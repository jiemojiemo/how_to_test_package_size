//
// Created by bytedance on 2021/11/20.
//

#include "simple_decoder.h"
#include <vector>

#include <cassert>
int main()
{
    {
        // can create wav file from path
        const char* path = "/Users/bytedance/Downloads/2_114_下雨天_bip_1.wav";
        SimpleWavDecoder* decoder = SD_createFromFile(path);
        assert(decoder != NULL);

        // can get number channels from wav
        int num_channels = SD_getNumChannels(decoder);
        assert(num_channels == 2);

        // can get sample rate from wav
        int sample_rate = SD_getSampleRate(decoder);
        assert(sample_rate == 44100);

        // can read samples
        const int num_samples_to_read = 1024;
        std::vector<float> interleave_buffer(num_samples_to_read * num_channels);
        int ret = SD_read(decoder, interleave_buffer.data(), num_samples_to_read);
        assert(ret == num_samples_to_read);

        // can destroy
        ret = SD_destroy(decoder);
        assert(ret == 0);
    }
    return 0;
}