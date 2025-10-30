
#include <stdint.h>
#include "GAGHL_STM32_CLOCK_MANAGER.h"
#include <main.h>

volatile CLOCK_SOURCE_T current_clock_source;

void Check_Clock_Source(void) {
	uint32_t clock_source = (RCC->CFGR >> 2) & 0x3;
	uint32_t pll_source = (RCC->CFGR >> 16) & 0x1;

	switch (clock_source) {
		case 0x00:
			current_clock_source = Clock_Source_HSI;
			break;

		case 0x01:
			current_clock_source = Clock_Source_HSE;
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

static inline void HSI_ON(void) {
	RCC->CR |= RCC_CR_HSION;
}

static inline void HSE_ON(void) {
	RCC->CR |= RCC_CR_HSEON;
}

static inline void PLL_ON(void) {
	RCC->CR |= RCC_CR_PLLON;
}

//-------------------------------------------------
static inline void HSI_ON_AND_STABLAZITION(void) {
	
}

static inline void HSE_ON_AND_STABLAZITION(void) {
	RCC->CR |= RCC_CR_HSEON;
	while (!(RCC->CR & RCC_CR_HSERDY));
}

static inline void PLL_ON_AND_STABLAZITION(void) {
	RCC->CR |= RCC_CR_PLLON;
	while (!(RCC->CR & RCC_CR_PLLRDY));
}