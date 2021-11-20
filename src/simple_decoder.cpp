//
// Created by bytedance on 2021/11/20.
//
#include <memory>
#include "simple_decoder.h"

#define DR_WAV_IMPLEMENTATION
#include "dr_wav.h"

typedef struct SimpleDecoder{
    drwav wav;
}SimpleDecoder;

SimpleDecoder* createFromFile(const char* file_path, FileType type)
{
    std::unique_ptr<SimpleDecoder> decoder = std::make_unique<SimpleDecoder>();
    if(!drwav_init_file(&decoder->wav, file_path, NULL)){
        decoder = nullptr;
    }

    return decoder.release();
}
int getNumChannels(SimpleDecoder* decoder)
{
    assert(decoder != NULL);
    return decoder->wav.channels;
}
int getSampleRate(SimpleDecoder* decoder)
{
    assert(decoder != NULL);
    return decoder->wav.sampleRate;
}
size_t read(SimpleDecoder* decoder, float* out_interleave_data, int num_samples_per_channel)
{
    assert(decoder != NULL);
    assert(out_interleave_data != NULL);
    assert(num_samples_per_channel >= 0);

    size_t framesRead = drwav_read_pcm_frames_f32(&decoder->wav, num_samples_per_channel, out_interleave_data);

    return framesRead;
}
int destroy(SimpleDecoder* decoder)
{
    delete decoder;
    return 0;
}
