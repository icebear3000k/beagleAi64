# Datasheet {#group_apps_Log12_datasheet}

# Summary of CPU load

CPU      | TOTAL LOAD
----------|--------------
mpu1_0    |  69. 9 
mcu2_0    |   8. 0 
mcu2_1    |   1. 0 
 c6x_1    |  85. 0 
 c6x_2    |  11. 0 
 c7x_1    |  75. 0 

# HWA performance statistics

HWA      | LOAD
----------|--------------
  MSC0    |  24.19 % ( 157 MP/s )

# DDR performance statistics

DDR BW   | AVG          | PEAK
----------|--------------|-------
READ BW |   2504 MB/s  |  12495 MB/s
WRITE BW |    926 MB/s  |   7456 MB/s
TOTAL BW |   3430 MB/s  |  19951 MB/s

# Detailed CPU performance/memory statistics


##CPU: mcu2_0

###Task Table

TASK          | TASK LOAD
--------------|-------
          IPC_RX   |   0.58 %
      REMOTE_SRV   |   0.14 %
       LOAD_TEST   |   0. 0 %
      TIVX_CPU_0   |   0. 0 %
         TIVX_NF   |   0. 0 %
       TIVX_LDC1   |   0. 0 %
       TIVX_MSC1   |   2.14 %
       TIVX_MSC2   |   4.33 %
      TIVX_VISS1   |   0. 0 %
      TIVX_CAPT1   |   0. 0 %
      TIVX_CAPT2   |   0. 0 %
      TIVX_DISP1   |   0. 0 %
      TIVX_DISP2   |   0. 0 %
      TIVX_CSITX   |   0. 0 %
      TIVX_CAPT3   |   0. 0 %
      TIVX_CAPT4   |   0. 0 %
      TIVX_CAPT5   |   0. 0 %
      TIVX_CAPT6   |   0. 0 %
      TIVX_CAPT7   |   0. 0 %
      TIVX_CAPT8   |   0. 0 %
     TIVX_DISP_M   |   0. 0 %
     TIVX_DISP_M   |   0. 0 %
     TIVX_DISP_M   |   0. 0 %
     TIVX_DISP_M   |   0. 0 %

###CPU Heap Table

HEAP   | Size  | Free | Unused
--------|-------|------|---------
  DDR_SHARED_MEM |   16777216 B |   16768256 B |  99 %
          L3_MEM |     262144 B |     261888 B |  99 %

##CPU: mcu2_1

###Task Table

TASK          | TASK LOAD
--------------|-------
          IPC_RX   |   0. 0 %
      REMOTE_SRV   |   0. 8 %
       LOAD_TEST   |   0. 0 %
        TIVX_SDE   |   0. 0 %
        TIVX_DOF   |   0. 0 %
      TIVX_CPU_1   |   0. 0 %
     IPC_TEST_RX   |   0. 0 %
     IPC_TEST_TX   |   0. 0 %
     IPC_TEST_TX   |   0. 0 %
     IPC_TEST_TX   |   0. 0 %
     IPC_TEST_TX   |   0. 0 %
     IPC_TEST_TX   |   0. 0 %

###CPU Heap Table

HEAP   | Size  | Free | Unused
--------|-------|------|---------
  DDR_SHARED_MEM |   16777216 B |   16773376 B |  99 %
          L3_MEM |     262144 B |     262144 B | 100 %

##CPU: c6x_1

###Task Table

TASK          | TASK LOAD
--------------|-------
          IPC_RX   |   0.40 %
      REMOTE_SRV   |   0. 0 %
       LOAD_TEST   |   0. 0 %
        TIVX_CPU   |  84.11 %
     IPC_TEST_RX   |   0. 0 %
     IPC_TEST_TX   |   0. 0 %
     IPC_TEST_TX   |   0. 0 %
     IPC_TEST_TX   |   0. 0 %
     IPC_TEST_TX   |   0. 0 %
     IPC_TEST_TX   |   0. 0 %

###CPU Heap Table

HEAP   | Size  | Free | Unused
--------|-------|------|---------
  DDR_SHARED_MEM |   16777216 B |   16748544 B |  99 %
          L2_MEM |     229376 B |          0 B |   0 %
 DDR_SCRATCH_MEM |   50331648 B |   50331648 B | 100 %

##CPU: c6x_2

###Task Table

TASK          | TASK LOAD
--------------|-------
          IPC_RX   |   0.12 %
      REMOTE_SRV   |   0. 0 %
       LOAD_TEST   |   0. 0 %
        TIVX_CPU   |  10. 0 %
     IPC_TEST_RX   |   0. 0 %
     IPC_TEST_TX   |   0. 0 %
     IPC_TEST_TX   |   0. 0 %
     IPC_TEST_TX   |   0. 0 %
     IPC_TEST_TX   |   0. 0 %
     IPC_TEST_TX   |   0. 0 %

###CPU Heap Table

HEAP   | Size  | Free | Unused
--------|-------|------|---------
  DDR_SHARED_MEM |   16777216 B |   16760320 B |  99 %
          L2_MEM |     229376 B |          0 B |   0 %
 DDR_SCRATCH_MEM |   50331648 B |   50331648 B | 100 %

##CPU: c7x_1

###Task Table

TASK          | TASK LOAD
--------------|-------
          IPC_RX   |   0. 4 %
      REMOTE_SRV   |   0. 1 %
       LOAD_TEST   |   0. 0 %
     TIVX_CPU_PR   |  74.73 %
     TIVX_CPU_PR   |   0. 0 %
     TIVX_CPU_PR   |   0. 0 %
     TIVX_CPU_PR   |   0. 0 %
     TIVX_CPU_PR   |   0. 0 %
     TIVX_CPU_PR   |   0. 0 %
     TIVX_CPU_PR   |   0. 0 %
     TIVX_CPU_PR   |   0. 0 %
     IPC_TEST_RX   |   0. 0 %
     IPC_TEST_TX   |   0. 0 %
     IPC_TEST_TX   |   0. 0 %
     IPC_TEST_TX   |   0. 0 %
     IPC_TEST_TX   |   0. 0 %
     IPC_TEST_TX   |   0. 0 %

###CPU Heap Table

HEAP   | Size  | Free | Unused
--------|-------|------|---------
  DDR_SHARED_MEM |  268435456 B |  166027008 B |  61 %
          L3_MEM |    8159232 B |          0 B |   0 %
          L2_MEM |     458752 B |     458752 B | 100 %
          L1_MEM |      16384 B |          0 B |   0 %
 DDR_SCRATCH_MEM |  385875968 B |  359912881 B |  93 %

# Performance point statistics


## Performance

PERF      | avg (usecs)  | min/max (usecs)  | number of executions
----------|----------|----------|----------
                 |  32983 |      0 / 444183 |        730

## FPS

PERF      | Frames per sec (FPS)
----------|----------
                 |   30.31


# Temperature statistics

ZONE      | TEMPERATURE
----------|--------------
CPU   |   63.74 Celsius
WKUP  |   63.53 Celsius
C7X   |   64.99 Celsius
GPU   |   63.95 Celsius
R5F   |   64.37 Celsius
