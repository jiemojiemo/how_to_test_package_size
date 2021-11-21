//
// Created by bytedance on 2021/11/20.
//

#ifndef HOW_TO_TEST_PACKAGE_SIZE_SIMPLE_DECODER_H
#define HOW_TO_TEST_PACKAGE_SIZE_SIMPLE_DECODER_H

#include <stdlib.h>

#if defined(__cplusplus)
extern "C"{
#endif
typedef struct SimpleWavDecoder SimpleWavDecoder;

SimpleWavDecoder *createFromFile(const char *file_path);

int getNumChannels(SimpleWavDecoder *decoder);

int getSampleRate(SimpleWavDecoder *decoder);

size_t read(SimpleWavDecoder *decoder, float *out_interleave_data, int num_samples_per_channel);

int destroy(SimpleWavDecoder *decoder);

#if defined(__cplusplus)
}
#endif
#endif //HOW_TO_TEST_PACKAGE_SIZE_SIMPLE_DECODER_H
