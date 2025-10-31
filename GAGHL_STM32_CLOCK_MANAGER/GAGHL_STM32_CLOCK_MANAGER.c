
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
				current_clock_source = PLL_Source_HSI_div_2;
			}
			break;
	}
}

static inline void CSS_TURN_ON(void) { RCC->CR |= RCC_CR_CSSON; }

static inline void HSI_TURN_ON(void) { RCC->CR |= RCC_CR_HSION; }

static inline void HSE_TURN_ON(void) { RCC->CR |= RCC_CR_HSEON; }

static inline void PLL_TURN_ON(void) { RCC->CR |= RCC_CR_PLLON; }

static inline void SET_PLL_MULTIPLIER_mull_2(void)  { RCC->CFGR = (RCC->CFGR & ~RCC_CFGR_PLLMULL) | RCC_CFGR_PLLMULL2;  }
static inline void SET_PLL_MULTIPLIER_mull_3(void)  { RCC->CFGR = (RCC->CFGR & ~RCC_CFGR_PLLMULL) | RCC_CFGR_PLLMULL3;  }
static inline void SET_PLL_MULTIPLIER_mull_4(void)  { RCC->CFGR = (RCC->CFGR & ~RCC_CFGR_PLLMULL) | RCC_CFGR_PLLMULL4;  }
static inline void SET_PLL_MULTIPLIER_mull_5(void)  { RCC->CFGR = (RCC->CFGR & ~RCC_CFGR_PLLMULL) | RCC_CFGR_PLLMULL5;  }
static inline void SET_PLL_MULTIPLIER_mull_6(void)  { RCC->CFGR = (RCC->CFGR & ~RCC_CFGR_PLLMULL) | RCC_CFGR_PLLMULL6;  }
static inline void SET_PLL_MULTIPLIER_mull_7(void)  { RCC->CFGR = (RCC->CFGR & ~RCC_CFGR_PLLMULL) | RCC_CFGR_PLLMULL7;  }
static inline void SET_PLL_MULTIPLIER_mull_8(void)  { RCC->CFGR = (RCC->CFGR & ~RCC_CFGR_PLLMULL) | RCC_CFGR_PLLMULL8;  }
static inline void SET_PLL_MULTIPLIER_mull_9(void)  { RCC->CFGR = (RCC->CFGR & ~RCC_CFGR_PLLMULL) | RCC_CFGR_PLLMULL9;  }
static inline void SET_PLL_MULTIPLIER_mull_10(void) { RCC->CFGR = (RCC->CFGR & ~RCC_CFGR_PLLMULL) | RCC_CFGR_PLLMULL10; }
static inline void SET_PLL_MULTIPLIER_mull_11(void) { RCC->CFGR = (RCC->CFGR & ~RCC_CFGR_PLLMULL) | RCC_CFGR_PLLMULL11; }
static inline void SET_PLL_MULTIPLIER_mull_12(void) { RCC->CFGR = (RCC->CFGR & ~RCC_CFGR_PLLMULL) | RCC_CFGR_PLLMULL12; }
static inline void SET_PLL_MULTIPLIER_mull_13(void) { RCC->CFGR = (RCC->CFGR & ~RCC_CFGR_PLLMULL) | RCC_CFGR_PLLMULL13; }
static inline void SET_PLL_MULTIPLIER_mull_14(void) { RCC->CFGR = (RCC->CFGR & ~RCC_CFGR_PLLMULL) | RCC_CFGR_PLLMULL14; }
static inline void SET_PLL_MULTIPLIER_mull_15(void) { RCC->CFGR = (RCC->CFGR & ~RCC_CFGR_PLLMULL) | RCC_CFGR_PLLMULL15; }
static inline void SET_PLL_MULTIPLIER_mull_16(void) { RCC->CFGR = (RCC->CFGR & ~RCC_CFGR_PLLMULL) | RCC_CFGR_PLLMULL16; }

static inline void SET_PLL_HSE_PRESCALER_div_1(void) { RCC->CFGR &= ~RCC_CFGR_PLLXTPRE; }
static inline void SET_PLL_HSE_PRESCALER_div_2(void) { RCC->CFGR |=  RCC_CFGR_PLLXTPRE; }

static inline void SET_PLL_SOURCE_HSI(void) { RCC->CFGR &= ~RCC_CFGR_PLLSRC; }
static inline void SET_PLL_SOURCE_HSE(void) { RCC->CFGR |= RCC_CFGR_PLLSRC; }

static inline void SET_SYSTEM_CLOCK_SOURCE_HSI(void) { RCC->CFGR |= RCC_CFGR_SW_HSI; }
static inline void SET_SYSTEM_CLOCK_SOURCE_HSE(void) { RCC->CFGR |= RCC_CFGR_SW_HSE; }
static inline void SET_SYSTEM_CLOCK_SOURCE_PLL(void) { RCC->CFGR |= RCC_CFGR_SW_PLL; }
//-------------------------------------------------
static inline void HSI_ON_AND_STABLAZITION(void) {
	HSI_TURN_ON();
	while (!(RCC->CR & RCC_CR_HSIRDY));
}

static inline void HSE_ON_AND_STABLAZITION(void) {
	HSE_TURN_ON();
	while (!(RCC->CR & RCC_CR_HSERDY));
}

static inline void PLL_ON_AND_STABLAZITION(void) {
	PLL_TURN_ON();
	while (!(RCC->CR & RCC_CR_PLLRDY));
}