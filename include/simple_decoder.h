//
// Created by bytedance on 2021/11/20.
//

#ifndef HOW_TO_TEST_PACKAGE_SIZE_SIMPLE_DECODER_H
#define HOW_TO_TEST_PACKAGE_SIZE_SIMPLE_DECODER_H

#include <stdlib.h>
typedef struct SimpleDecoder SimpleDecoder;

enum FileType
{
    kWav = 0,
    kMp3,
    kFlac
};

SimpleDecoder* createFromFile(const char* file_path, enum FileType type);
int getNumChannels(SimpleDecoder* decoder);
int getSampleRate(SimpleDecoder* decoder);
size_t read(SimpleDecoder* decoder, float* out_interleave_data, int num_samples_per_channel);
int destroy(SimpleDecoder* decoder);

#endif //HOW_TO_TEST_PACKAGE_SIZE_SIMPLE_DECODER_H
