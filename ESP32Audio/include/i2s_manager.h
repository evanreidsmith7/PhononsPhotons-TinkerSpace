#pragma once
#include <driver/i2s.h>
extern bool isMuted;
void i2s_install();
void i2s_setpin();
void micTask(void *parameter);
void toggleMute();
void checkVoiceMute();
