#ifndef __HAL_H_
#define __HAL_H_

#include <stdint.h>

void HalSystemDelay(uint32_t ms, uint32_t cpu_freq_mhz);
unsigned int* HalMalloc(unsigned int size);
void HalClearInt();
void HalStartInt();
void HalIdle();

#endif
