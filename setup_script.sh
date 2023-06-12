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

current_dir=$(pwd)
cd $(dirname $0)

if ! id | grep -q root; then
	echo "./setup_script.sh must be run as root:"
	echo "sudo ./setup_script.sh"
	exit
fi

exit_setup()
{
    echo "Setup FAILED! : Make sure you have active network connection"
    cd $current_dir
    exit 1
}

if [ `arch` == "aarch64" ]; then
    install_dir="/opt/"
else
    install_dir="../"
fi
while getopts ":i:" flag; do
    case "${flag}" in
        i)
            if [ -z $OPTARG ] || [ ! -d $OPTARG ]; then
                echo "Invalid installation directory "
                cd $current_dir
                exit 1
            fi
            install_dir="$OPTARG"
            ;;
        *)
            if [ $OPTARG == i ]; then
                  echo "Installation directory not provided"
                  cd $current_dir
                  exit 1
            fi
            ;;
    esac
done

# Install Tensorflow for CPP apps build
ls $install_dir | grep "tensorflow"
if [ "$?" -ne "0" ]; then
    bash scripts/install_tensorflow.sh $*
    if [ "$?" -ne "0" ]; then
        exit_setup
    fi
fi

# Install dlpack for CPP apps build
ls $install_dir | grep "dlpack"
if [ "$?" -ne "0" ]; then
    bash scripts/install_dlpack.sh $*
    if [ "$?" -ne "0" ]; then
        exit_setup
    fi
fi

# Install ONNX RT for CPP apps build
ls $install_dir | grep "onnxruntime"
if [ "$?" -ne "0" ]; then
    bash scripts/install_onnx_rt.sh $*
    if [ "$?" -ne "0" ]; then
        exit_setup
    fi
fi

# Install edgeai-tidl-tools
ls $install_dir | grep "edgeai-tidl-tools"
if [ "$?" -ne "0" ]; then
    bash scripts/install_tidl_tools.sh $*
    if [ "$?" -ne "0" ]; then
        exit_setup
    fi
fi

# Install TIOVX modules required for custom GST plugins
bash scripts/install_tiovx_modules.sh $*
if [ "$?" -ne "0" ]; then
    exit_setup
fi

# Install custom GST plugins which uses TIOVX modules
bash scripts/install_gst_plugins.sh $*
if [ "$?" -ne "0" ]; then
    exit_setup
fi

# Install TI GPIO Python and CPP libraries
bash scripts/install_ti_gpio_libs.sh $*
if [ "$?" -ne "0" ]; then
    exit_setup
fi

# Build C++ apps
bash scripts/compile_cpp_apps.sh $*
if [ "$?" -ne "0" ]; then
    exit_setup
fi

cd $current_dir

sync

echo "Setup Done!"
