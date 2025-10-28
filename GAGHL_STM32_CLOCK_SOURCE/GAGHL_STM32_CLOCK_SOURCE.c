#include <stdint.h>
#include "GAGHL_STM32_CLOCK_SOURCE.h"
#include <main.h>

volatile CLOCK_SOURCE_T current_clock_source;

void Check_Clock_Source(void) {
	uint8_t clock_source = (RCC->CFGR >> 2) & 0x3;
	uint8_t pll_source = (RCC->CFGR >> 16) & 0x1;

	switch (clock_source) {
		case 0x00:
			current_clock_source = Clcok_Source_HSI;
			break;

		case 0x01:
			current_clock_source = Clcok_Source_HSE;
			break;

		case 0x02:
			if (pll_source == 0x01) {
				current_clock_source = PLL_Source_HSE;
			} else {
				current_clock_source = PLL_Source_HSI_div2;
			}
			break;
	}
}
