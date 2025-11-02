
#include "GAGHL_STM32_CLOCK_MANAGER.h"

volatile CLOCK_SOURCE_T current_clock_source;
volatile PLL_CLOCK_SOURCE_T current_pll_clock_source;

void Check_Clock_Source(void) {
	uint32_t clock_source = (RCC->CFGR >> 2) & 0x3;

	switch (clock_source) {
		case 0x00:
			current_clock_source = Clock_Source_is_HSI;
			break;

		case 0x01:
			current_clock_source = Clock_Source_is_HSE;
			break;

		case 0x02:
			current_clock_source = Clock_Source_is_PLL;
			break;
	}
}

void PLL_check_Clock_Source(void) {
	uint32_t pll_source = (RCC->CFGR >> 16) & 0x1;

	if (((RCC->CFGR >> 2) & 0x3) == (0x02)) {
		if (pll_source == 0x01) {
			current_pll_clock_source = PLL_Source_is_HSE;
		} else {
			current_pll_clock_source = PLL_Source_is_HSI_div2;
		}
	} else {
		current_pll_clock_source = PLL_is_Disable;
	}
}


