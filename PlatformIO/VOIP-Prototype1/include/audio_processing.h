#ifndef AUDIO_PROCESSING_H
#define AUDIO_PROCESSING_H
#include <stdint.h>

void setupAudioProcessing();
int processAudioData(int16_t *samples, int count);
void printPlotLimits(int limit);



#endif