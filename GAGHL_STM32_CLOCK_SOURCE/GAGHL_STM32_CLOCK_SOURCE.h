#ifndef GAGHL_STM32_CLOCK_SOURCE_H
#define GAGHL_STM32_CLOCK_SOURCE_H

typedef enum {
	Clock_Source_HSI = 0, Clock_Source_HSE, Clock_Source_PLL, PLL_Source_HSE, PLL_Source_HSI_div2
} CLOCK_SOURCE_T;

void Check_Clock_Source(void);

#endif
