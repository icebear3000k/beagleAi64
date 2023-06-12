==============================
Release notes version 08.02.00
==============================

.. _pub_edgeai_new_in_this_release:

New in this Release
===================
 - Support for Sony's IMX390 FPD link based sensors and Fusion1 board
 - Support for 8 channel capture of Sony's IMX390 FPD link based sensors at 2MP @ 30fps using virtual channels
 - Support for Sony's IMX219 Rpi camera with 10-bit capture support
 - Multi-instance Human pose estimation demo in edge_ai_apps :ref:`pub_edgeai_human_pose_estimation_data_flow`
 - Updated edgeai-gst-plugins with multi-channel support
 - Updated `tiovxisp <https://github.com/TexasInstruments/edgeai-gst-plugins/wiki/tiovxisp>` Gstreamer element with IMX390 support
 - Improved `tiovxdlpreproc <https://github.com/TexasInstruments/edgeai-gst-plugins/wiki/tiovxdlpreproc>` Gstreamer element with DMA optimizations to provide 2x performance lift
 - New tiovxdlcolorconvert Gstreamer element with DMA optimizations to provide 4x performance lift
 - Updated performance visualization tool with realtime junction temperature readings of CPU, GPU, C7x DSP and R5F cores
 - Validation of `Intel-9260 WiFi card <https://www.amazon.in/Intel-Wireless-Ac-9260-2230-Gigabit/dp/B079QJQF4Y>` in Access Point and Station mode
 - Enablement of Pulse Width Modulation (PWM) hardware accelerator

.. _pub_fixed_in_this_release:

Fixed in this Release
=====================
 - ADASVISION-5149 - Hostname incorrect in SK shows j7-evm instead of tda4vm-sk
 - ADASVISION-5117 - USB 3.0 device is recognized as USB 2.1 sometimes
 - ADASVISION-4953 - Video looping does not work with v4l2 HW decoder plugin
 - ADASVISION-4943 - IMX219 based Rpi camera cannot capture data correctly for 10 bit format
 - ADASVISION-4809 - Python and C++ apps cannot measure pre and post processing time accurately

  .. _pub_edgeai_known_issues:

Known Issues
============
 - ADASVISION-5463 - ONR-OD-8000 model fails with IMX390  in CPP app due to 1200x1200 resolution
 - ADASVISION-5113 - GST Pipeline error: Error pulling tensor from GST Pipeline
 - ADASVISION-5070 - Edge AI demo output not resizing properly on 4K monitor
 - ADASVISION-4997 - Multi-input multi-inference demo freezes after long duration run
 - ADASVISION-4794 - Application takes 10-15 seconds to come up in some cases
 - ADASVISION-5454 - tiovxdlcolorcovert does not support UYVY
 - ADASVISION-5447 - Models failing due to tiovxdlcolorconvert limitation
 - ADASVISION-5421 - No metadata file was found for CPP apps with TVM models
 - ADASVISION-5420 - No valid frames found before end of stream

.. _pub_edgeai_model_zoo_status:

Model Zoo
=========
About 83 models from 8.2 model zoo are regressed with multiple input sources such as
camera and video files. A list of unsupported models are as below,

 - Height/2 is odd, tiovxdlpreproc block fetch logic fails
    - TFL-CL-0100-efficientNet-edgeTPU-m
    - TFL-CL-0140-efficientNet-lite4
    - TFL-CL-0170-efficientNet-lite1
    - TFL-CL-0190-efficientNet-edgeTPU-l

 - High latency causes DSS underflow
    - ONR-SS-8730-deeplabv3-mobv3-lite-large-cocoseg21-512x512

 - Odd resolution, tiovxdlcolorconvert fails
    - TVM-CL-3430-gluoncv-mxnet-xception
    - TFL-CL-0040-InceptionNetV3

 - Human pose model with unsupported post processing
    - ONR-KD-7000-human-pose-ae-mobv2-fpn-spp-udp-512x512
    - ONR-KD-7010-human-pose-ae-res50v2-fpn-spp-udp-512x512
    - ONR-KD-7020-human-pose-ae-mobv2-pan-spp-udp-512x512
    - ONR-KD-7030-human-pose-ae-res50v2-pan-spp-udp-512x512

.. note::
    Please also refer to `edgeai-gst-plugins issues <https://github.com/TexasInstruments/edgeai-gst-plugins/issues>`_
    for more details on bugs filed on custom GStreamer plugins

.. _pub_edgeai_software_components:

Software components
===================

List of software components used in this version

+------------------------------+---------------------+
| Componenet                   | Version             |
+==============================+=====================+
| PSDKLA (filesystem, uboot)   | 08.02.00.04         |
+------------------------------+---------------------+
| PSDKRA (firmware)            | 08.02.00.06         |
+------------------------------+---------------------+
| Docker                       | 19.03.8-ce          |
+------------------------------+---------------------+
| Ubuntu (Docker)              | 20.04.LTS           |
+------------------------------+---------------------+
| Python                       | 3.8                 |
+------------------------------+---------------------+
| OpenCV                       | 4.5.1               |
+------------------------------+---------------------+
| GStreamer                    | 1.16.2              |
+------------------------------+---------------------+
| Cmake                        | 3.16.3              |
+------------------------------+---------------------+
| Ninja                        | 1.10.0              |
+------------------------------+---------------------+
| Meson                        | 0.57.2              |
+------------------------------+---------------------+
| Jupyterlab                   | 3.0.14              |
+------------------------------+---------------------+
| NeoAI - DLR                  | 1.8.0               |
+------------------------------+---------------------+
| Tensorflow                   | TIDL_PSDK_8.2       |
+------------------------------+---------------------+
| TFLite-runtime               | TIDL_PSDK_8.2       |
+------------------------------+---------------------+
| ONNX-runtime                 | TIDL_PSDK_8.2       |
+------------------------------+---------------------+
| PyYAML                       | 5.4.1               |
+------------------------------+---------------------+
| TI Model Zoo                 | 8.2.0               |
+------------------------------+---------------------+
| edgeai-gst-plugins           | 0.6.0               |
+------------------------------+---------------------+
| edgeai-tiovx-modules         | 8.2.0               |
+------------------------------+---------------------+
| edgeai-tidl-tools            | 8.2.0.5             |
+------------------------------+---------------------+
