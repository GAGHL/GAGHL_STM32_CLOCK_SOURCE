#ifndef GAGHL_STM32_CLOCK_MANAGER_H
#define GAGHL_STM32_CLOCK_MANAGER_H

#include <stdint.h>
#include <main.h>

typedef enum {
	Clock_Source_is_HSI = 0,
	Clock_Source_is_HSE,
	Clock_Source_is_PLL
} CLOCK_SOURCE_T;

typedef enum {
	PLL_is_Disable = 0,
	PLL_Source_is_HSE,
	PLL_Source_is_HSI_div2
} PLL_CLOCK_SOURCE_T;

void Check_Clock_Source(void);

static inline void RCC_Enable_CSS(void) { RCC->CR |= RCC_CR_CSSON; }
static inline void RCC_Enable_HSI(void) { RCC->CR |= RCC_CR_HSION; }
static inline void RCC_Enable_HSE(void) { RCC->CR |= RCC_CR_HSEON; }
static inline void RCC_Enable_PLL(void) { RCC->CR |= RCC_CR_PLLON; }

static inline void RCC_Set_PLL_Multiplier_To_2(void)  { RCC->CFGR |= RCC_CFGR_PLLMUL2;  }
static inline void RCC_Set_PLL_Multiplier_To_3(void)  { RCC->CFGR |= RCC_CFGR_PLLMUL3;  }
static inline void RCC_Set_PLL_Multiplier_To_4(void)  { RCC->CFGR |= RCC_CFGR_PLLMUL4;  }
static inline void RCC_Set_PLL_Multiplier_To_5(void)  { RCC->CFGR |= RCC_CFGR_PLLMUL5;  }
static inline void RCC_Set_PLL_Multiplier_To_6(void)  { RCC->CFGR |= RCC_CFGR_PLLMUL6;  }
static inline void RCC_Set_PLL_Multiplier_To_7(void)  { RCC->CFGR |= RCC_CFGR_PLLMUL7;  }
static inline void RCC_Set_PLL_Multiplier_To_8(void)  { RCC->CFGR |= RCC_CFGR_PLLMUL8;  }
static inline void RCC_Set_PLL_Multiplier_To_9(void)  { RCC->CFGR |= RCC_CFGR_PLLMUL9;  }
static inline void RCC_Set_PLL_Multiplier_To_10(void) { RCC->CFGR |= RCC_CFGR_PLLMUL10; }
static inline void RCC_Set_PLL_Multiplier_To_11(void) { RCC->CFGR |= RCC_CFGR_PLLMUL11; }
static inline void RCC_Set_PLL_Multiplier_To_12(void) { RCC->CFGR |= RCC_CFGR_PLLMUL12; }
static inline void RCC_Set_PLL_Multiplier_To_13(void) { RCC->CFGR |= RCC_CFGR_PLLMUL13; }
static inline void RCC_Set_PLL_Multiplier_To_14(void) { RCC->CFGR |= RCC_CFGR_PLLMUL14; }
static inline void RCC_Set_PLL_Multiplier_To_15(void) { RCC->CFGR |= RCC_CFGR_PLLMUL15; }
static inline void RCC_Set_PLL_Multiplier_To_16(void) { RCC->CFGR |= RCC_CFGR_PLLMUL16; }

static inline void RCC_Set_PLL_Clock_Source_To_HSI_Div2(void) {
	RCC->CFGR &= ~RCC_CFGR_PLLSRC;
}
static inline void RCC_Set_PLL_Clock_Source_To_HSE_Div1(void) {
	RCC->CFGR |= RCC_CFGR_PLLSRC;
	RCC->CFGR &= ~RCC_CFGR_PLLXTPRE;
}
static inline void RCC_Set_PLL_Clock_Source_To_HSE_Div2(void) {
	RCC->CFGR |= RCC_CFGR_PLLSRC;
	RCC->CFGR |=  RCC_CFGR_PLLXTPRE;
}

static inline void RCC_Set_System_Clock_Source_To_HSI_Output(void) { RCC->CFGR |= RCC_CFGR_SW_HSI; }
static inline void RCC_Set_System_Clock_Source_To_HSE_Output(void) { RCC->CFGR |= RCC_CFGR_SW_HSE; }
static inline void RCC_Set_System_Clock_Source_To_PLL_Output(void) { RCC->CFGR |= RCC_CFGR_SW_PLL; }

static inline void RCC_Enable_HSI_And_Stabilization(void) {
	RCC->CR |= RCC_CR_HSION;
	while (!(RCC->CR & RCC_CR_HSIRDY));
}
static inline void RCC_Enable_HSE_And_Stabilization(void) {
	RCC->CR |= RCC_CR_HSEON;
	while (!(RCC->CR & RCC_CR_HSERDY));
}
static inline void RCC_Enable_PLL_And_Stabilization(void) {
	RCC->CR |= RCC_CR_PLLON;
	while (!(RCC->CR & RCC_CR_PLLRDY));
}



#endif
