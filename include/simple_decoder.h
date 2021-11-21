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

/**
 * Create wave decoder from file path, return NULL if read file failed
 */
SimpleWavDecoder *createFromFile(const char *file_path);

/**
 * Return the number of channels
 */
int getNumChannels(SimpleWavDecoder *decoder);

/**
 * Return the sample rate
 */
int getSampleRate(SimpleWavDecoder *decoder);

/**
 * Decode from wav file and fill the samples to `out_interleave_data`,
 * returns the number of frames actually decoded.
 */
size_t read(SimpleWavDecoder *decoder, float *out_interleave_data, int num_samples_per_channel);

/**
 * Destroy decoder and release resources
 */
int destroy(SimpleWavDecoder *decoder);

#if defined(__cplusplus)
}
#endif
#endif //HOW_TO_TEST_PACKAGE_SIZE_SIMPLE_DECODER_H
