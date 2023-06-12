# Datasheet {#group_apps_Log5_datasheet}

# Summary of CPU load

CPU      | TOTAL LOAD
----------|--------------
mpu1_0    |  69.38 
mcu2_0    |   8. 0 
mcu2_1    |   1. 0 
 c6x_1    |  85. 0 
 c6x_2    |  11. 0 
 c7x_1    |  76. 0 

# HWA performance statistics

HWA      | LOAD
----------|--------------
  MSC0    |  24.54 % ( 159 MP/s )

# DDR performance statistics

DDR BW   | AVG          | PEAK
----------|--------------|-------
READ BW |   2506 MB/s  |   6821 MB/s
WRITE BW |    925 MB/s  |   5568 MB/s
TOTAL BW |   3431 MB/s  |  12389 MB/s

# Detailed CPU performance/memory statistics


##CPU: mcu2_0

###Task Table

TASK          | TASK LOAD
--------------|-------
          IPC_RX   |   0.91 %
      REMOTE_SRV   |   0. 4 %
       LOAD_TEST   |   0. 0 %
      TIVX_CPU_0   |   0. 0 %
         TIVX_NF   |   0. 0 %
       TIVX_LDC1   |   0. 0 %
       TIVX_MSC1   |   1.99 %
       TIVX_MSC2   |   4.50 %
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
          IPC_RX   |   0.70 %
      REMOTE_SRV   |   0. 0 %
       LOAD_TEST   |   0. 0 %
        TIVX_CPU   |  84.17 %
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
          IPC_RX   |   0. 3 %
      REMOTE_SRV   |   0. 0 %
       LOAD_TEST   |   0. 0 %
        TIVX_CPU   |  10.11 %
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
     TIVX_CPU_PR   |  75.35 %
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
                 |  34537 |      0 / 444183 |        290

## FPS

PERF      | Frames per sec (FPS)
----------|----------
                 |   28.95


# Temperature statistics

ZONE      | TEMPERATURE
----------|--------------
CPU   |   63.32 Celsius
WKUP  |   63.11 Celsius
C7X   |   64.58 Celsius
GPU   |   63.32 Celsius
R5F   |   63.74 Celsius
