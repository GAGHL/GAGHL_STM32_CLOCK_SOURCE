#ifndef GAGHL_STM32_CLOCK_MANAGER_H
#define GAGHL_STM32_CLOCK_MANAGER_H

#include <stdint.h>
#include <stm32f10x.h>

#define SBI(REG, BIT) ((REG) |= (BIT))
#define CBI(REG, BIT) ((REG) &= ~(BIT))

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

typedef enum {
	APB1_DIV1   = RCC_CFGR_PPRE1_DIV1,
	APB1_DIV2   = RCC_CFGR_PPRE1_DIV2,
	APB1_DIV4   = RCC_CFGR_PPRE1_DIV4,
	APB1_DIV8   = RCC_CFGR_PPRE1_DIV8,
	APB1_DIV16  = RCC_CFGR_PPRE1_DIV16
} APB1_DIV_T;

typedef enum {
	APB2_DIV1   = RCC_CFGR_PPRE2_DIV1,
	APB2_DIV2   = RCC_CFGR_PPRE2_DIV2,
	APB2_DIV4   = RCC_CFGR_PPRE2_DIV4,
	APB2_DIV8   = RCC_CFGR_PPRE2_DIV8,
	APB2_DIV16  = RCC_CFGR_PPRE2_DIV16
} APB2_DIV_T;

typedef enum {
	AHB_DIV1    = RCC_CFGR_HPRE_DIV1,
	AHB_DIV2    = RCC_CFGR_HPRE_DIV2,
	AHB_DIV4    = RCC_CFGR_HPRE_DIV4,
	AHB_DIV8    = RCC_CFGR_HPRE_DIV8,
	AHB_DIV16   = RCC_CFGR_HPRE_DIV16,
	AHB_DIV64   = RCC_CFGR_HPRE_DIV64,
	AHB_DIV128  = RCC_CFGR_HPRE_DIV128,
	AHB_DIV256  = RCC_CFGR_HPRE_DIV256,
	AHB_DIV512  = RCC_CFGR_HPRE_DIV512
} AHB_DIV_T;


void Check_Clock_Source(void);

/* =========================================================
 * 							Clock Control (Enable/Disable)
 * ========================================================= */
static inline void RCC_Enable_CSS(void) { SBI(RCC->CR, RCC_CR_CSSON); }
static inline void RCC_Enable_HSI(void) { SBI(RCC->CR, RCC_CR_HSION); }
static inline void RCC_Enable_HSE(void) { SBI(RCC->CR, RCC_CR_HSEON); }
static inline void RCC_Enable_PLL(void) { SBI(RCC->CR, RCC_CR_PLLON); }
/* =========================================================
 * 			Clock Division Configuration (AHB, APB1, APB2)
 * ========================================================= */
static inline void RCC_Set_APB1_Clock_To(APB1_DIV_T div) {
	RCC->CFGR &= ~RCC_CFGR_PPRE1;
	RCC->CFGR |= div;
}

static inline void RCC_Set_APB2_Clock_To(APB2_DIV_T div) {
	RCC->CFGR &= ~RCC_CFGR_PPRE2;
	RCC->CFGR |= div;
}

static inline void RCC_Set_AHB_Clock_To(AHB_DIV_T div) {
	RCC->CFGR &= ~RCC_CFGR_HPRE;
	RCC->CFGR |= div;
}

static inline void RCC_Set_PLL_Multiplier_To(uint32_t div) {
	RCC->CFGR &= ~RCC_CFGR_PLLMULL;
	RCC->CFGR |= div;
}

static inline void RCC_Set_PLL_Clock_Source_To_HSI_Div2(void) {
	CBI(RCC->CFGR, RCC_CFGR_PLLSRC);
}
static inline void RCC_Set_PLL_Clock_Source_To_HSE_Div1(void) {
	SBI(RCC->CFGR, RCC_CFGR_PLLSRC);
	CBI(RCC->CFGR, RCC_CFGR_PLLXTPRE);
}
static inline void RCC_Set_PLL_Clock_Source_To_HSE_Div2(void) {
	SBI(RCC->CFGR, RCC_CFGR_PLLSRC);
	SBI(RCC->CFGR, RCC_CFGR_PLLXTPRE);
}

static inline void RCC_Set_System_Clock_Source_To_HSI_Output(void) { RCC->CFGR |= RCC_CFGR_SW_HSI; }
static inline void RCC_Set_System_Clock_Source_To_HSE_Output(void) { RCC->CFGR |= RCC_CFGR_SW_HSE; }
static inline void RCC_Set_System_Clock_Source_To_PLL_Output(void) { RCC->CFGR |= RCC_CFGR_SW_PLL; }

static inline void RCC_Wait_HSI_Ready(void) { while (!(RCC->CR & RCC_CR_HSIRDY)); }
static inline void RCC_Wait_HSE_Ready(void) { while (!(RCC->CR & RCC_CR_HSERDY)); }
static inline void RCC_Wait_PLL_Ready(void) { while (!(RCC->CR & RCC_CR_PLLRDY)); }

static inline void RCC_Wait_System_Clock_HSI_Ready(void) {
	while((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_HSI);
}
static inline void RCC_Wait_System_Clock_HSE_Ready(void) {
	while((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_HSE);
}
static inline void RCC_Wait_System_Clock_PLL_Ready(void) {
	while((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL);
}

static inline void RCC_AHB_Enable_CRC(void)     { SBI(RCC->AHBENR ,RCC_AHBENR_CRCEN);      }
static inline void RCC_AHB_Enable_DMA1(void)    { SBI(RCC->AHBENR ,RCC_AHBENR_DMA1EN);     }
static inline void RCC_AHB_Enable_FLIT(void)    { SBI(RCC->AHBENR ,RCC_AHBENR_FLITFEN);    }
static inline void RCC_AHB_Enable_SRAM(void)    { SBI(RCC->AHBENR ,RCC_AHBENR_SRAMEN);     }

static inline void RCC_APB1_Enable_TIM2(void)   { SBI(RCC->APB1ENR ,RCC_APB1ENR_TIM2EN);   }
static inline void RCC_APB1_Enable_TIM3(void)   { SBI(RCC->APB1ENR ,RCC_APB1ENR_TIM3EN);   }
static inline void RCC_APB1_Enable_TIM4(void)   { SBI(RCC->APB1ENR ,RCC_APB1ENR_TIM4EN);   }
static inline void RCC_APB1_Enable_USART2(void) { SBI(RCC->APB1ENR ,RCC_APB1ENR_USART2EN); }
static inline void RCC_APB1_Enable_USART3(void) { SBI(RCC->APB1ENR ,RCC_APB1ENR_USART3EN); }
static inline void RCC_APB1_Enable_SPI2(void)   { SBI(RCC->APB1ENR ,RCC_APB1ENR_SPI2EN);   }
static inline void RCC_APB1_Enable_I2C1(void)   { SBI(RCC->APB1ENR ,RCC_APB1ENR_I2C1EN);   }
static inline void RCC_APB1_Enable_I2C2(void)   { SBI(RCC->APB1ENR ,RCC_APB1ENR_I2C2EN);   }
static inline void RCC_APB1_Enable_CAN1(void)   { SBI(RCC->APB1ENR ,RCC_APB1ENR_CAN1EN);   }
static inline void RCC_APB1_Enable_USB(void)    { SBI(RCC->APB1ENR ,RCC_APB1ENR_USBEN);    }
static inline void RCC_APB1_Enable_WWDG(void)   { SBI(RCC->APB1ENR ,RCC_APB1ENR_WWDGEN);   }
static inline void RCC_APB1_Enable_BKP(void)    { SBI(RCC->APB1ENR ,RCC_APB1ENR_BKPEN);    }
static inline void RCC_APB1_Enable_PWR(void)    { SBI(RCC->APB1ENR ,RCC_APB1ENR_PWREN);    }

static inline void RCC_APB2_Enable_TIM1(void)   { SBI(RCC->APB2ENR ,RCC_APB2ENR_TIM1EN);   }
static inline void RCC_APB2_Enable_SPI1(void)   { SBI(RCC->APB2ENR ,RCC_APB2ENR_SPI1EN);   }
static inline void RCC_APB2_Enable_USART1(void) { SBI(RCC->APB2ENR ,RCC_APB2ENR_USART1EN); }
static inline void RCC_APB2_Enable_ADC1(void)   { SBI(RCC->APB2ENR ,RCC_APB2ENR_ADC1EN);   }
static inline void RCC_APB2_Enable_ADC2(void)   { SBI(RCC->APB2ENR ,RCC_APB2ENR_ADC2EN);   }
static inline void RCC_APB2_Enable_GPIOA(void)  { SBI(RCC->APB2ENR ,RCC_APB2ENR_IOPAEN);   }
static inline void RCC_APB2_Enable_GPIOB(void)  { SBI(RCC->APB2ENR ,RCC_APB2ENR_IOPBEN);   }
static inline void RCC_APB2_Enable_GPIOC(void)  { SBI(RCC->APB2ENR ,RCC_APB2ENR_IOPCEN);   }
static inline void RCC_APB2_Enable_GPIOD(void)  { SBI(RCC->APB2ENR ,RCC_APB2ENR_IOPDEN);   }
static inline void RCC_APB2_Enable_GPIOE(void)  { SBI(RCC->APB2ENR ,RCC_APB2ENR_IOPEEN);   }
static inline void RCC_APB2_Enable_AFIO(void)   { SBI(RCC->APB2ENR ,RCC_APB2ENR_AFIOEN);   }



#endif
