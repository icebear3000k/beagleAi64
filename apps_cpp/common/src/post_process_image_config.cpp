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

/* Standard headers. */
#include <stdint.h>
#include <vector>
#include <map>
#include <filesystem>

/* Third-party headers. */
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>

/* Module headers. */
#include <utils/include/ti_logger.h>
#include <common/include/post_process_image.h>
#include <common/include/post_process_image_classify.h>
#include <common/include/post_process_image_object_detect.h>
#include <common/include/post_process_image_segmentation.h>

namespace ti::edgeai::common
{
using namespace cv;

void PostprocessImageConfig::getPostProcString(std::string &s) const
{
    s = " ! tiovxdlcolorconvert ! video/x-raw,format=NV12";
}

void PostprocessImageConfig::dumpInfo() const
{
    LOG_INFO_RAW("\n");
    LOG_INFO("PostprocessImageConfig::modelName      = %s\n", modelName.c_str());
    LOG_INFO("PostprocessImageConfig::rtType         = %s\n", rtType.c_str());
    LOG_INFO("PostprocessImageConfig::taskType       = %s\n", taskType.c_str());
    LOG_INFO("PostprocessImageConfig::dataLayout     = %s\n", dataLayout.c_str());
    LOG_INFO("PostprocessImageConfig::inDataWidth    = %d\n", inDataWidth);
    LOG_INFO("PostprocessImageConfig::inDataHeight   = %d\n", inDataHeight);
    LOG_INFO("PostprocessImageConfig::outDataWidth   = %d\n", outDataWidth);
    LOG_INFO("PostprocessImageConfig::outDataHeight  = %d\n", outDataHeight);
    LOG_INFO("PostprocessImageConfig::dispWidth      = %d\n", dispWidth);
    LOG_INFO("PostprocessImageConfig::dispHeight     = %d\n", dispHeight);
    LOG_INFO("PostprocessImageConfig::vizThreshold   = %f\n", vizThreshold);
    LOG_INFO("PostprocessImageConfig::alpha          = %f\n", alpha);
    LOG_INFO("PostprocessImageConfig::normDetect     = %d\n", normDetect);
    LOG_INFO("PostprocessImageConfig::labelOffsetMap = [ ");

    for (const auto& [key, value] : labelOffsetMap)
    {
        LOG_INFO_RAW("(%d, %d) ", key, value);
    }

    LOG_INFO_RAW("]\n\n");

    LOG_INFO("PostprocessImageConfig::formatter = [ ");

    for (uint32_t i = 0; i < formatter.size(); i++)
    {
        LOG_INFO_RAW(" %d", formatter[i]);
    }

    LOG_INFO_RAW("]\n\n");

    LOG_INFO("PostprocessImageConfig::resultIndices = [ ");

    for (uint32_t i = 0; i < resultIndices.size(); i++)
    {
        LOG_INFO_RAW(" %d", resultIndices[i]);
    }

    LOG_INFO_RAW("]\n\n");
}

} // namespace ti::edgeai::common

