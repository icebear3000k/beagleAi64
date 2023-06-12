#!/bin/bash

#  Copyright (C) 2021 Texas Instruments Incorporated - http://www.ti.com/
#
#  Redistribution and use in source and binary forms, with or without
#  modification, are permitted provided that the following conditions
#  are met:
#
#    Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
#
#    Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the
#    distribution.
#
#    Neither the name of Texas Instruments Incorporated nor the names of
#    its contributors may be used to endorse or promote products derived
#    from this software without specific prior written permission.
#
#  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
#  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
#  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
#  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
#  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
#  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
#  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
#  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
#  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
#  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
#  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

cd $(dirname $0)

if ! id | grep -q root; then
	echo "./init_script.sh must be run as root:"
	echo "sudo ./init_script.sh"
	exit
fi

# Putting display on standby
killall weston 2>/dev/null
sleep 1

BG_IMAGE=/usr/share/demo/
if grep -q sk /proc/device-tree/compatible
then
    BG_IMAGE+=j7-sk-p0-wallpaper.jpg
else
    BG_IMAGE+=j7-evm-oob-wallpaper.jpg
fi

#get ip addr to overlay
arr=(`ifconfig eth0 2>&1 | grep inet | grep -v inet6`)
ip_eth0=${arr[1]}
arr=(`ifconfig wlp1s0 2>&1 | grep inet | grep -v inet6`)
ip_wlp1s0=${arr[1]}

TEXTOVERLAY="textoverlay font-desc=\"Arial 8\" color=0xFF000000 \
            valignment=3 halignment=right draw-shadow=false \
            draw-outline=false"

GST_OVERLAY_STR=""
YPOS=0.03
STEP=0.03
if [ "$ip_eth0" == "" -a "$ip_wlp1s0" == "" ]
then
    GST_OVERLAY_STR+="$TEXTOVERLAY text=\"Ethernet and WiFi Not connected, \
                          use UART for accessing the board\" \
                          ypos=$YPOS ! "
    YPOS=`bc <<< $YPOS+$STEP`
fi

if [ "$ip_eth0" != "" ]
then
    GST_OVERLAY_STR+="$TEXTOVERLAY text=\"ip_eth0=$ip_eth0\" ypos=$YPOS !"
    YPOS=`bc <<< $YPOS+$STEP`
    GST_OVERLAY_STR+="$TEXTOVERLAY text=\"user:pwd=root:root\" ypos=$YPOS !"
    YPOS=`bc <<< $YPOS+2*$STEP`
fi

if [ "$ip_wlp1s0" != "" ]
then
    GST_OVERLAY_STR+="$TEXTOVERLAY text=\"ip_wlp1s0=$ip_wlp1s0\" ypos=$YPOS !"
    YPOS=`bc <<< $YPOS+$STEP`
    GST_OVERLAY_STR+="$TEXTOVERLAY text=\"`cat /usr/share/intel9260/hostapd.conf | grep ssid `\" ypos=$YPOS !"
    YPOS=`bc <<< $YPOS+$STEP`
    GST_OVERLAY_STR+="$TEXTOVERLAY text=\"user:pwd=root:root\" ypos=$YPOS !"
    YPOS=`bc <<< $YPOS+2*$STEP`
fi

gcc scripts/get_fb_resolution.c -o get_fb_resolution
gst-launch-1.0 filesrc location=$BG_IMAGE ! jpegdec ! videoconvert ! \
video/x-raw, format=BGRA ! videoscale ! `./get_fb_resolution` ! \
$GST_OVERLAY_STR \
filesink location=/dev/fb > /dev/null 2>&1
rm -rf get_fb_resolution

# Logic here tries to ping an internal server and sets the proxy if it succeeds
# Modify the server and proxy URLs as requied
ping bitbucket.itg.ti.com -c 1 > /dev/null 2>&1
if [ "$?" -eq "0" ]; then
    export HTTPS_PROXY=http://webproxy.ext.ti.com:80
    export https_proxy=http://webproxy.ext.ti.com:80
    export HTTP_PROXY=http://webproxy.ext.ti.com:80
    export http_proxy=http://webproxy.ext.ti.com:80
    export ftp_proxy=http://webproxy.ext.ti.com:80
    export FTP_PROXY=http://webproxy.ext.ti.com:80
    export no_proxy=ti.com,localhost
    # configure local ntpd servers
    cat << EOF > /etc/systemd/timesyncd.conf
#  This file is part of systemd.
#
#  systemd is free software; you can redistribute it and/or modify it
#  under the terms of the GNU Lesser General Public License as published by
#  the Free Software Foundation; either version 2.1 of the License, or
#  (at your option) any later version.
#
# Entries in this file show the compile time defaults.
# You can change settings by editing this file.
# Defaults can be restored by simply deleting this file.
#
# See timesyncd.conf(5) for details.

[Time]
#NTP=
FallbackNTP=0.bdtime.itg.ti.com 1.fltime.itg.ti.com 2.sbtime.itg.ti.com 3.letime.itg.ti.com
#RootDistanceMaxSec=5
#PollIntervalMinSec=32
#PollIntervalMaxSec=2048
EOF

systemctl restart systemd-timesyncd.service || true
fi

# Disable Neo-DLR phone-home feature
#echo '{"enable_phone_home": false}' > /usr/lib/python3.9/dist-packages/dlr/counter/ccm_config.json

# Link headers and libraries for DLR
mkdir -p /usr/dlr/
ln -snf /usr/lib/python3.9/dist-packages/dlr/libdlr.so /usr/dlr/libdlr.so
ln -snf /usr/dlr/libdlr.so /usr/lib/libdlr.so

# Link libraries and python packages for ONNXRT
ln -snf /usr/lib/libonnxruntime.so.1.7.0 /usr/lib/libonnxruntime.so

rm -rf /usr/lib/libvx_tidl_rt.so.map
rm -rf /usr/lib/libtidl_onnxrt_EP.so.map
rm -rf /usr/lib/libtidl_tfl_delegate.so.map

ldconfig

bash /opt/edge_ai_apps/scripts/setup_cameras.sh
