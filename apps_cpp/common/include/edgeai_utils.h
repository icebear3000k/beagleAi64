/*
 *  Copyright (C) 2021 Texas Instruments Incorporated - http://www.ti.com/
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _TI_EDGEAI_UTILS_H_
#define _TI_EDGEAI_UTILS_H_

/* Standard headers. */
#include <string>
#include <thread>

/* Third-party headers. */
#include <yaml-cpp/yaml.h>

/* Module headers. */
#include <common/include/post_process_image.h>
#include <common/include/pre_process_image.h>

using namespace std;

namespace ti::edgeai::common
{
    /* Forward declaration. */
    struct StatEntry;

    using MapStatEntry   = map<uint32_t, StatEntry>;

    /** Statistics database. */
    /**
     * \brief Class for holding the performance information during the DL
     *        model inference runs.
     *
     * \ingroup group_edgeai_common
     */
    class Statistics
    {
        public:
            /** Vector of ststistics objects. */
            static MapStatEntry m_stats;

            /** Flag to control curses report thread */
            static bool m_printCurses;

            /** Flag to control STDOUT prints if curses is disabled*/
            static bool m_printStdout;

            /** Reporting thread identifier. */
            static thread m_reportingThread;

            /** Function for registering the model to track statistics specific
             * to this model.
             *
             * @param key Identifier for retrieving the appropriate record.
             * @param inputName Name String representation of the input
             * @param modelType Type of the model
             * @param modelName Name of the model to start tracking statistics
             *                  for.
             */
            static int32_t addEntry(uint32_t        key,
                                    const string   &inputName,
                                    const string   &modelType,
                                    const string   &modelName);

            /**
             * Utility Function for reporting processing time measurements
             * It will update the last average with the new sample value
             *
             * @param key Idetfier for retrieving the appropriate record.
             * @param tag unique string to represent the processing time of certain operation
             * @param value processing time measured in milliseconds
             */
            static int32_t reportProcTime(uint32_t      key,
                                          const string &tag,
                                          float         value);

            /**
             * Utility Function for reporting performence metrics
             * It will update the last average with the new sample value
             *
             * @param key Idetfier for retrieving the appropriate record.
             * @param tag unique string to represent each metric
             * @param unit unit of measurment
             * @param value measured value
             */
            static int32_t reportMetric(uint32_t        key,
                                        const string   &tag,
                                        const string   &unit,
                                        float           value);
            /**
             * Thread callback function which prints a table of reported processing times
             * using ncurses library.
             *
             * The number of columns displayed is dynamically computed based on the length
             * of the modelpath.
             */
             static void reportingLoop(const string &demoName);
            /**
             * Control if the processing time should be printed to the console or shown
             * in a nice looking, table using ncurses library. If you use the curses method,
             * only the processing time is shown and other debug prints will not be visible.
             * If you do not use the curses library, all the processing time are simply
             * printed to the console. It's a choice between debug prints v/s demo appearance.
             *
             * @param state passing true will start the curses thread
             * @param verbose Verbose flag for controlling the output prints to the screen
             * @param demoName Demo name to display
             */
            static void enableCursesReport(bool            state,
                                           bool            verbose,
                                           const string   &demoName);

            /**
             * Disables the curses process printing to the output, if enabled.
             */
            static void disableCursesReport();
    };


    /**
     * Extract the infererer specific configuration from the parsed YAML object.
     *
     * @param appConfig Parsed YAML configuration context.
     * @param modelBasePath Directory path where the model and artifacts are located
     * @param infConfig Inferer configuration context which will be populated with
     *                  the information contained in the yaml configuration
     *                  object.
     */
    int32_t getInfererConfig(const YAML::Node  &appConfig,
                             const string      &modelBasePath,
                             InfererConfig     &infConfig);

    /**
     * Extract the post-processing specific configuration from the parsed YAML
     * object.
     *
     * @param yaml Parsed YAML configuration context.
     * @param config Post-processing configuration context which will be
     *                  populated with the information contained in the yaml
     *                  configuration object.
     */
    int32_t getPostprocessImageConfig(const YAML::Node         &yaml,
                                      PostprocessImageConfig   &config);

    /**
     * Extract the pre-processing specific configuration from the parsed YAML
     * object.
     *
     * @param yaml Parsed YAML configuration context.
     * @param config Pre-processing configuration context which will be
     *                  populated with the information contained in the yaml
     *                  configuration object.
     */
    int32_t getPreprocessImageConfig(const YAML::Node      &yaml,
                                     PreprocessImageConfig &config);

} // namespace ti::edgeai::common

#endif /* _TI_EDGEAI_UTILS_H_ */

