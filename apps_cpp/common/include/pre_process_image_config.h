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

#ifndef _PRE_PROCESS_IMAGE_CONFIG_H_
#define _PRE_PROCESS_IMAGE_CONFIG_H_

/* Module headers. */
#include <common/include/edgeai_debug.h>
#include <dl_inferer/include/ti_dl_inferer.h>

/**
 * \defgroup group_edgeai_cpp_apps_pre_proc Image Pre-processing
 *
 * \brief Class providing interface for generic pre-processing logic.
 *
 * \ingroup group_edgeai_cpp_apps
 */

namespace ti::edgeai::common
{
// Default values to avoid exceptions resulting from using uninitialized values
#define TI_PREPROC_DEFAULT_WIDTH   320
#define TI_PREPROC_DEFAULT_HEIGHT  240
#define MAX_SCALE_FACTOR           4

    using namespace ti::dl;

    /**
     * \brief Configuration for the DL inferer.
     *
     * \ingroup group_edgeai_cpp_apps_post_proc
     */
    struct PreprocessImageConfig
    {
        /** Name of the model. */
        std::string         modelName{};

        /** Type of the runtime API to invoke. The valid values are:
         * - DL_INFER_RTTYPE_DLR
         * - DL_INFER_RTTYPE_TFLITE
         * - DL_INFER_RTTYPE_ONNX
         */
        std::string         rtType{};

        /** Task type.
         *  - detection
         *  - segmentation
         *  - classification
         */
        std::string         taskType{};

        /** Width of the input data. */
        int32_t             inDataWidth{TI_PREPROC_DEFAULT_WIDTH};

        /** Height of the input data. */
        int32_t             inDataHeight{TI_PREPROC_DEFAULT_HEIGHT};

        /** Out width. */
        int32_t             outDataWidth{TI_PREPROC_DEFAULT_WIDTH};

        /** Out height. */
        int32_t             outDataHeight{TI_PREPROC_DEFAULT_HEIGHT};

        /** Mean values to apply during normalization. */
        std::vector<float>  mean;

        /** Scale values to apply during normalization. */
        std::vector<float>  scale;

        /** Resize width. */
        int32_t             resizeWidth{TI_PREPROC_DEFAULT_WIDTH};

        /** Resize height. */
        int32_t             resizeHeight{TI_PREPROC_DEFAULT_HEIGHT};

        /** Layout of the data. Allowed values. */
        std::string         dataLayout{"NCHW"};

        /** Data type of Input tensor. */
        DlInferType         inputTensorType{DlInferType_Invalid};

        /** Optional debugging control configuration. */
        DebugDumpConfig     debugConfig;

        /**
         * Updates the string 's' with the gst videoscale and videobox command strings
         * based on the pre-processor configuration 'config'. The video scale string is
         * always generated but the videobox string will be conditionally generated
         * only if any of the crop (top/bottom, left/right) are non-zero.
         *
         * @param s             String with the gst commands
         */
        void getPreProcString(std::string  &s) const;

        /**
         * Helper function to dump the configuration information.
         */
        void dumpInfo() const;

        /** target for dlpreproc. */
        static uint32_t            target;
    };

} // namespace ti::edgeai::common

#endif /* _PRE_PROCESS_IMAGE_CONFIG_H_ */
