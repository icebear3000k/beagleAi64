/* Standard headers. */
#include <filesystem>
#include <thread>
#include <unistd.h>

/* Module headers. */
#include <utils/include/edgeai_perfstats.h>

/*
 * Outputs log files containing real-time performance metrics.
 * Log files generated with performance metrics averaged over some fixed time interval.
 */

// bool ti::edgeai::utils::printstats = false;
namespace ti::utils
{
    static bool                printstats;
    static app_perf_point_t    perf;
    static thread              perfThreadId;
    static const char         *sub_dir_name{nullptr};

    static void perfThread()
    {
        app_perf_point_t   *perf_arr[1];
        int32_t             logNumber = 0;
        const int32_t       save_history = 16;      // Defines how many log files to keep at a time
        std::string         base_dir = "../perf_logs";

        /* open sysfs files for reading temperature data*/
        FILE *cpuTempFd  = fopen("/sys/class/thermal/thermal_zone1/temp", "rb");
        FILE *wkupTempFd = fopen("/sys/class/thermal/thermal_zone0/temp", "rb");
        FILE *c7xTempFd  = fopen("/sys/class/thermal/thermal_zone2/temp", "rb");
        FILE *gpuTempFd  = fopen("/sys/class/thermal/thermal_zone3/temp", "rb");
        FILE *r5fTempFd  = fopen("/sys/class/thermal/thermal_zone4/temp", "rb");
        uint32_t cpuTemp, wkupTemp, c7xTemp, gpuTemp, r5fTemp;

        if (sub_dir_name)
        {
            base_dir += string("/") + sub_dir_name;
        }

        std::filesystem::remove_all(base_dir);
        std::filesystem::create_directories(base_dir);

        while (printstats)
        {
            perf_arr[0] = &perf;

            std::string file_name = "Log" + std::to_string(logNumber);

            FILE *fp = appPerfStatsExportOpenFile(base_dir.c_str(), file_name.c_str());

            if (NULL != fp)
            {
                ::appPerfStatsExportAll(fp, perf_arr, 1);

                /* Read temperature data*/
                fscanf(cpuTempFd, "%u", &cpuTemp);
                rewind(cpuTempFd);
                fflush(cpuTempFd);
                fscanf(wkupTempFd, "%u", &wkupTemp);
                rewind(wkupTempFd);
                fflush(wkupTempFd);
                fscanf(c7xTempFd, "%u", &c7xTemp);
                rewind(c7xTempFd);
                fflush(c7xTempFd);
                fscanf(gpuTempFd, "%u", &gpuTemp);
                rewind(gpuTempFd);
                fflush(gpuTempFd);
                fscanf(r5fTempFd, "%u", &r5fTemp);
                rewind(r5fTempFd);
                fflush(r5fTempFd);

                /* print temperature stats*/
                fprintf(fp,"\n");
                fprintf(fp,"# Temperature statistics\n");
                fprintf(fp,"\n");
                fprintf(fp,"ZONE      | TEMPERATURE\n");
                fprintf(fp,"----------|--------------\n");
                fprintf(fp,"CPU   |   %0.2f Celsius\n",float(cpuTemp)/1000);
                fprintf(fp,"WKUP  |   %0.2f Celsius\n",float(wkupTemp)/1000);
                fprintf(fp,"C7X   |   %0.2f Celsius\n",float(c7xTemp)/1000);
                fprintf(fp,"GPU   |   %0.2f Celsius\n",float(gpuTemp)/1000);
                fprintf(fp,"R5F   |   %0.2f Celsius\n",float(r5fTemp)/1000);

                ::appPerfStatsExportCloseFile(fp);
                ::appPerfStatsResetAll();
            }
            else
            {
                printf("fp is null\n");
            }

            /* Increment the log file number. */
            logNumber = (logNumber + 1) % save_history;

            /* Log files generated every 2s */
            this_thread::sleep_for(chrono::milliseconds(2000));
        }

        /* close fds*/
        fclose(cpuTempFd);
        fclose(wkupTempFd);
        fclose(c7xTempFd);
        fclose(gpuTempFd);
        fclose(r5fTempFd);

    }

    // Starts thread to log performance files
    void enableReport(bool state, const char *dir_name)
    {
        printstats = state;
        sub_dir_name = dir_name;
        if (state)
        {
            perfThreadId = thread(perfThread);
        }
    }

    // When called, start recording and averaging performance metrics
    void startRec()
    {
        appPerfPointBegin(&perf);
    }

    // When called, pause recording and averaging performance metrics
    void endRec()
    {
        appPerfPointEnd(&perf);
    }

    void waitForPerfThreadExit()
    {
        if (perfThreadId.joinable())
        {
            perfThreadId.join();
        }
    }

    // Stop performance logs
    void disableReport()
    {
        printstats = false;
        sleep(1);
    }
}
