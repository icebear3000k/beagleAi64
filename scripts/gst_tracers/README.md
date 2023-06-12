Steps to get latency for gstreamer elements
===========================================

1. Run any gstreamer application with below string prepended
```
    GST_DEBUG_FILE=trace.log GST_DEBUG_NO_COLOR=1 GST_DEBUG="GST_TRACER:7" GST_TRACERS="latency(flags=element)"

    Ex:
        GST_DEBUG_FILE=trace.log GST_DEBUG_NO_COLOR=1 GST_DEBUG="GST_TRACER:7" GST_TRACERS="latency(flags=element)" gst-launch-1.0 videotestsrc num-buffers=1000 ! videoconvert ! videoscale ! videoconvert ! kmssink driver-name=tidss
        GST_DEBUG_FILE=trace.log GST_DEBUG_NO_COLOR=1 GST_DEBUG="GST_TRACER:7" GST_TRACERS="latency(flags=element)" ./app_edgeai.py ../config/image_classification.yaml
```

2. In another terminal run parse gst python script with trace.log path as input
```
    root@tda4vm-sk:/opt/edge_ai_apps/scripts/gst_tracers# ./parse_gst_tracers.py ../../apps_python/trace.log
```
