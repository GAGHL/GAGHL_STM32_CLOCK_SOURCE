#ifndef GAGHL_STM32_CLOCK_MANAGER_H
#define GAGHL_STM32_CLOCK_MANAGER_H

#include <stm32f10x.h>
#include <stdint.h>

#define HSI_TIMEOUT_VALUE  				0x5000
#define HSE_TIMEOUT_VALUE 			 	0x5000
#define PLL_TIMEOUT_VALUE  				0x5000
#define SYS_To_HSI_TIMEOUT_VALUE  0x5000
#define SYS_To_HSE_TIMEOUT_VALUE  0x5000
#define SYS_To_PLL_TIMEOUT_VALUE  0x5000

#define SET_BIT(REG, BIT)      ((REG) |= (BIT))
#define CLEAR_BIT(REG, BIT)    ((REG) &= ~(BIT))
#define READ_BIT(REG, BIT)     ((REG) & (BIT))

#define CLEAR_REG(REG)         ((REG) = (0x0))
#define WRITE_REG(REG, VAL)    ((REG) = (VAL))
#define READ_REG(REG)          ((REG))
#define MODIFY_REG(REG, CLEARMASK, SETMASK)  WRITE_REG((REG), (((READ_REG(REG)) & (~(CLEARMASK))) | (SETMASK)))

typedef enum {
	System_Clock_is_HSI = 0,
	System_Clock_is_HSE,
	System_Clock_is_PLL
} CLOCK_SOURCE_T;

typedef enum {
	PLL_is_Disable = 0,
	PLL_Source_is_HSE,
	PLL_Source_is_HSI_div_2
} PLL_CLOCK_SOURCE_T;

typedef enum {
	APB1_DIV_1   = RCC_CFGR_PPRE1_DIV1,
	APB1_DIV_2   = RCC_CFGR_PPRE1_DIV2,
	APB1_DIV_4   = RCC_CFGR_PPRE1_DIV4,
	APB1_DIV_8   = RCC_CFGR_PPRE1_DIV8,
	APB1_DIV_16  = RCC_CFGR_PPRE1_DIV16
} APB1_DIV_T;

typedef enum {
	APB2_DIV_1   = RCC_CFGR_PPRE2_DIV1,
	APB2_DIV_2   = RCC_CFGR_PPRE2_DIV2,
	APB2_DIV_4   = RCC_CFGR_PPRE2_DIV4,
	APB2_DIV_8   = RCC_CFGR_PPRE2_DIV8,
	APB2_DIV_16  = RCC_CFGR_PPRE2_DIV16
} APB2_DIV_T;

typedef enum {
	AHB_DIV_1    = RCC_CFGR_HPRE_DIV1,
	AHB_DIV_2    = RCC_CFGR_HPRE_DIV2,
	AHB_DIV_4    = RCC_CFGR_HPRE_DIV4,
	AHB_DIV_8    = RCC_CFGR_HPRE_DIV8,
	AHB_DIV_16   = RCC_CFGR_HPRE_DIV16,
	AHB_DIV_64   = RCC_CFGR_HPRE_DIV64,
	AHB_DIV_128  = RCC_CFGR_HPRE_DIV128,
	AHB_DIV_256  = RCC_CFGR_HPRE_DIV256,
	AHB_DIV_512  = RCC_CFGR_HPRE_DIV512
} AHB_DIV_T;


void System_Check_Clock_Source(void);
void PLL_Check_Clock_Source(void);

typedef enum {
	HSI_Div_2 = 0x0U,
	HSE_DIV_1 = RCC_CFGR_PLLSRC,
	HSE_DIV_2 = (RCC_CFGR_PLLSRC | RCC_CFGR_PLLXTPRE)
} PLL_INPUT_SOURCE_T;

typedef enum {
	MULL_2  = RCC_CFGR_PLLMULL2,
	MULL_3  = RCC_CFGR_PLLMULL3,
	MULL_4  = RCC_CFGR_PLLMULL4,
	MULL_5  = RCC_CFGR_PLLMULL5,
	MULL_6  = RCC_CFGR_PLLMULL6,
	MULL_7  = RCC_CFGR_PLLMULL7,
	MULL_8  = RCC_CFGR_PLLMULL8,
	MULL_9  = RCC_CFGR_PLLMULL9,
	MULL_10 = RCC_CFGR_PLLMULL10,
	MULL_11 = RCC_CFGR_PLLMULL11,
	MULL_12 = RCC_CFGR_PLLMULL12,
	MULL_13 = RCC_CFGR_PLLMULL13,
	MULL_14 = RCC_CFGR_PLLMULL14,
	MULL_15 = RCC_CFGR_PLLMULL15,
	MULL_16 = RCC_CFGR_PLLMULL16
} PLL_MULL_T;

typedef enum {
	ADC_DIV_2 = RCC_CFGR_ADCPRE_DIV2,
	ADC_DIV_4 = RCC_CFGR_ADCPRE_DIV4,
	ADC_DIV_6 = RCC_CFGR_ADCPRE_DIV6,
	ADC_DIV_8 = RCC_CFGR_ADCPRE_DIV8
} ADC_DIV_T;

typedef enum {
	FLASH_LATENCY_0 = 0x0U,
	FLASH_LATENCY_1 = FLASH_ACR_LATENCY_0,
	FLASH_LATENCY_2 = FLASH_ACR_LATENCY_1
} FLASH_LATENCY_T;


/* =========================================================
 * 							Clock Control (Enable/Disable)
 * ========================================================= */
static inline void RCC_CSS_Enable(void)    { SET_BIT(RCC->CR, RCC_CR_CSSON);   }
static inline void RCC_CSS_Disable(void)   { CLEAR_BIT(RCC->CR, RCC_CR_CSSON); }
static inline void RCC_CSS_Clear_IT(void)  { SET_BIT(RCC->CIR, RCC_CIR_CSSC);  }

static inline void RCC_LSI_Enable(void)    { SET_BIT(RCC->CSR,   RCC_CSR_LSION);     }
static inline void RCC_LSI_Disable(void)   { CLEAR_BIT(RCC->CSR, RCC_CSR_LSION);     }
static inline void RCC_LSI_Enable_IT(void) { SET_BIT(RCC->CIR,   RCC_CIR_LSIRDYIE);  }
static inline void RCC_LSI_Clear_IT(void)  { SET_BIT(RCC->CIR,   RCC_CIR_LSIRDYC);   }

static inline void RCC_LSE_Enable(void)    { SET_BIT(RCC->BDCR,   RCC_BDCR_LSEON);    }
static inline void RCC_LSE_Disable(void)   { CLEAR_BIT(RCC->BDCR, RCC_BDCR_LSEON);    }
static inline void RCC_LSE_Enable_IT(void) { SET_BIT(RCC->CIR,    RCC_CIR_HSERDYIE);  }
static inline void RCC_LSE_Clear_IT(void)  { SET_BIT(RCC->CIR,    RCC_CIR_HSERDYC);   }

static inline void RCC_HSI_Enable(void)    { SET_BIT(RCC->CR, RCC_CR_HSION);      }
static inline void RCC_HSI_Disable(void)   { CLEAR_BIT(RCC->CR, RCC_CR_HSION);    }
static inline void RCC_HSI_Enable_IT(void) { SET_BIT(RCC->CIR, RCC_CIR_HSIRDYIE); }
static inline void RCC_HSI_Clear_IT(void)  { SET_BIT(RCC->CIR, RCC_CIR_HSIRDYC);  }

static inline void RCC_HSE_Enable(void)    { SET_BIT(RCC->CR,   RCC_CR_HSEON);     }
static inline void RCC_HSE_Disable(void)   { CLEAR_BIT(RCC->CR, RCC_CR_HSEON);     }
static inline void RCC_HSE_Enable_IT(void) { SET_BIT(RCC->CIR,  RCC_CIR_HSERDYIE); }
static inline void RCC_HSE_Clear_IT(void)  { SET_BIT(RCC->CIR,  RCC_CIR_HSERDYC);  }

static inline void RCC_PLL_Enable(void)    { SET_BIT(RCC->CR,   RCC_CR_PLLON);     }
static inline void RCC_PLL_Disable(void)   { CLEAR_BIT(RCC->CR, RCC_CR_PLLON);     }
static inline void RCC_PLL_Enable_IT(void) { SET_BIT(RCC->CIR,  RCC_CIR_PLLRDYIE); }
static inline void RCC_PLL_Clear_IT(void)  { SET_BIT(RCC->CIR,  RCC_CIR_PLLRDYC);  }

static inline uint8_t RCC_HSI_Is_Ready(void) { return READ_BIT(RCC->CR, RCC_CR_HSIRDY) != 0; }
static inline uint8_t RCC_HSE_Is_Ready(void) { return READ_BIT(RCC->CR, RCC_CR_HSERDY) != 0; }
static inline uint8_t RCC_PLL_Is_Ready(void) { return READ_BIT(RCC->CR, RCC_CR_PLLRDY) != 0; }

static inline uint8_t RCC_HSI_Is_Disable(void) { return READ_BIT(RCC->CR, RCC_CR_HSIRDY) == 0; }
static inline uint8_t RCC_HSE_Is_Disable(void) { return READ_BIT(RCC->CR, RCC_CR_HSERDY) == 0; }
static inline uint8_t RCC_PLL_Is_Disable(void) { return READ_BIT(RCC->CR, RCC_CR_PLLRDY) == 0; }

static inline void RCC_Set_System_Clock_To_HSI_Output(void) {
	MODIFY_REG(RCC->CFGR, RCC_CFGR_SW, RCC_CFGR_SW_HSI);
}
static inline void RCC_Set_System_Clock_To_HSE_Output(void) {
	MODIFY_REG(RCC->CFGR, RCC_CFGR_SW, RCC_CFGR_SW_HSE);
}
static inline void RCC_Set_System_Clock_To_PLL_Output(void) {
	MODIFY_REG(RCC->CFGR, RCC_CFGR_SW, RCC_CFGR_SW_PLL);
}
//------------------------------Wait for HSI/HSE/PLL clocks getting ready
static inline void RCC_Wait_HSI_Ready(void)    { while(!RCC_HSI_Is_Ready()); }
static inline void RCC_Wait_HSE_Ready(void)    { while(!RCC_HSE_Is_Ready()); }
static inline void RCC_Wait_PLL_Ready(void)    { while(!RCC_PLL_Is_Ready()); }
//------------------------------Wait for HSI/HSE/PLL clocks getting disable
static inline void RCC_Wait_HSI_Disable(void)  { while(!RCC_HSI_Is_Disable()); }
static inline void RCC_Wait_HSE_Disable(void)  { while(!RCC_HSE_Is_Disable()); }
static inline void RCC_Wait_PLL_Disable(void)  { while(!RCC_PLL_Is_Disable()); }
//------------------------------Wait for HSI/HSE/PLL clocks getting ready with timeout
static inline int8_t RCC_Wait_HSI_Ready_With_Timeout(void) { 
	uint32_t timeout = 0;
	while(!RCC_HSI_Is_Ready()) {
		timeout++;
		if (timeout > HSI_TIMEOUT_VALUE) {
				return -1; 
		}
	}
	return 0;
}

static inline int8_t RCC_Wait_HSE_Ready_With_Timeout(void) { 
	uint32_t timeout = 0;
	while(!RCC_HSE_Is_Ready()) {
		timeout++;
		if (timeout > HSE_TIMEOUT_VALUE) {
				return -1; 
		}
	}
	return 0;
}

static inline int8_t RCC_Wait_PLL_Ready_With_Timeout(void) { 
	uint32_t timeout = 0;
	while(!RCC_PLL_Is_Ready()) {
		timeout++;
		if (timeout > PLL_TIMEOUT_VALUE) {
				return -1; 
		}
	}
	return 0;
}
//------------------------------System Clock Select checks getting ready
static inline uint8_t RCC_System_Clock_To_HSI_Is_Ready(void) { return READ_BIT(RCC->CFGR, RCC_CFGR_SWS) == RCC_CFGR_SWS_HSI; }
static inline uint8_t RCC_System_Clock_To_HSE_Is_Ready(void) { return READ_BIT(RCC->CFGR, RCC_CFGR_SWS) == RCC_CFGR_SWS_HSE; }
static inline uint8_t RCC_System_Clock_To_PLL_Is_Ready(void) { return READ_BIT(RCC->CFGR, RCC_CFGR_SWS) == RCC_CFGR_SWS_PLL; }
//------------------------------Wait for system clock source changed to HSI/HSE/PLL output ready
static inline void RCC_Wait_System_Clock_To_HSI_Ready(void) { while(!RCC_System_Clock_To_HSI_Is_Ready()); }
static inline void RCC_Wait_System_Clock_To_HSE_Ready(void) { while(!RCC_System_Clock_To_HSE_Is_Ready()); }
static inline void RCC_Wait_System_Clock_To_PLL_Ready(void) { while(!RCC_System_Clock_To_PLL_Is_Ready()); }
//------------------------------Wait for system clock source changed to HSI/HSE/PLL output ready with timeout
static inline int8_t RCC_Wait_System_Clock_To_HSI_Ready_With_Timeout(void) { 
	uint32_t timeout = 0;
	while(!RCC_System_Clock_To_HSI_Is_Ready()) {
		timeout++;
		if (timeout > SYS_To_HSI_TIMEOUT_VALUE) {
				return -1; 
		}
	}
	return 0;
}

static inline int8_t RCC_Wait_System_Clock_To_HSE_Ready_With_Timeout(void) { 
	uint32_t timeout = 0;
	while(!RCC_System_Clock_To_HSE_Is_Ready()) {
		timeout++;
		if (timeout > SYS_To_HSE_TIMEOUT_VALUE) {
				return -1; 
		}
	}
	return 0;
}

static inline int8_t RCC_Wait_System_Clock_To_PLL_Ready_With_Timeout(void) { 
	uint32_t timeout = 0;
	while(!RCC_System_Clock_To_PLL_Is_Ready()) {
		timeout++;
		if (timeout > SYS_To_PLL_TIMEOUT_VALUE) {
				return -1; 
		}
	}
	return 0;
}

static inline void RCC_FLASH_Set_Latency(FLASH_LATENCY_T latency) {
	MODIFY_REG(FLASH->ACR, FLASH_ACR_LATENCY, latency);
}

/* =========================================================
 * 			Clock Division Configuration (AHB, APB1, APB2)
 * ========================================================= */


static inline void RCC_Set_AHB_Clock(AHB_DIV_T div)   { MODIFY_REG(RCC->CFGR, RCC_CFGR_HPRE, div); }
static inline void RCC_Set_APB1_Clock(APB1_DIV_T div) { MODIFY_REG(RCC->CFGR, RCC_CFGR_PPRE1, div); }
static inline void RCC_Set_APB2_Clock(APB2_DIV_T div) { MODIFY_REG(RCC->CFGR, RCC_CFGR_PPRE2, div); }

// AHB
static inline void RCC_AHB_Enable_CRC(void)   { SET_BIT(RCC->AHBENR, RCC_AHBENR_CRCEN); }
static inline void RCC_AHB_Disable_CRC(void)  { CLEAR_BIT(RCC->AHBENR, RCC_AHBENR_CRCEN); }

static inline void RCC_AHB_Enable_DMA1(void)   { SET_BIT(RCC->AHBENR, RCC_AHBENR_DMA1EN); }
static inline void RCC_AHB_Disable_DMA1(void)  { CLEAR_BIT(RCC->AHBENR, RCC_AHBENR_DMA1EN); }

static inline void RCC_AHB_Enable_FLIT(void)   { SET_BIT(RCC->AHBENR, RCC_AHBENR_FLITFEN); }
static inline void RCC_AHB_Disable_FLIT(void)  { CLEAR_BIT(RCC->AHBENR, RCC_AHBENR_FLITFEN); }

static inline void RCC_AHB_Enable_SRAM(void)   { SET_BIT(RCC->AHBENR, RCC_AHBENR_SRAMEN); }
static inline void RCC_AHB_Disable_SRAM(void)  { CLEAR_BIT(RCC->AHBENR, RCC_AHBENR_SRAMEN); }


// APB1
static inline void RCC_APB1_Enable_TIM2(void)   { SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM2EN); }
static inline void RCC_APB1_Disable_TIM2(void)  { CLEAR_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM2EN); }

static inline void RCC_APB1_Enable_TIM3(void)   { SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM3EN); }
static inline void RCC_APB1_Disable_TIM3(void)  { CLEAR_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM3EN); }

static inline void RCC_APB1_Enable_TIM4(void)   { SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM4EN); }
static inline void RCC_APB1_Disable_TIM4(void)  { CLEAR_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM4EN); }

static inline void RCC_APB1_Enable_USART2(void) { SET_BIT(RCC->APB1ENR, RCC_APB1ENR_USART2EN); }
static inline void RCC_APB1_Disable_USART2(void){ CLEAR_BIT(RCC->APB1ENR, RCC_APB1ENR_USART2EN); }

static inline void RCC_APB1_Enable_USART3(void) { SET_BIT(RCC->APB1ENR, RCC_APB1ENR_USART3EN); }
static inline void RCC_APB1_Disable_USART3(void){ CLEAR_BIT(RCC->APB1ENR, RCC_APB1ENR_USART3EN); }

static inline void RCC_APB1_Enable_SPI2(void)   { SET_BIT(RCC->APB1ENR, RCC_APB1ENR_SPI2EN); }
static inline void RCC_APB1_Disable_SPI2(void)  { CLEAR_BIT(RCC->APB1ENR, RCC_APB1ENR_SPI2EN); }

static inline void RCC_APB1_Enable_I2C1(void)   { SET_BIT(RCC->APB1ENR, RCC_APB1ENR_I2C1EN); }
static inline void RCC_APB1_Disable_I2C1(void)  { CLEAR_BIT(RCC->APB1ENR, RCC_APB1ENR_I2C1EN); }

static inline void RCC_APB1_Enable_I2C2(void)   { SET_BIT(RCC->APB1ENR, RCC_APB1ENR_I2C2EN); }
static inline void RCC_APB1_Disable_I2C2(void)  { CLEAR_BIT(RCC->APB1ENR, RCC_APB1ENR_I2C2EN); }

static inline void RCC_APB1_Enable_CAN1(void)   { SET_BIT(RCC->APB1ENR, RCC_APB1ENR_CAN1EN); }
static inline void RCC_APB1_Disable_CAN1(void)  { CLEAR_BIT(RCC->APB1ENR, RCC_APB1ENR_CAN1EN); }

static inline void RCC_APB1_Enable_USB(void)    { SET_BIT(RCC->APB1ENR, RCC_APB1ENR_USBEN); }
static inline void RCC_APB1_Disable_USB(void)   { CLEAR_BIT(RCC->APB1ENR, RCC_APB1ENR_USBEN); }

static inline void RCC_APB1_Enable_WWDG(void)   { SET_BIT(RCC->APB1ENR, RCC_APB1ENR_WWDGEN); }
static inline void RCC_APB1_Disable_WWDG(void)  { CLEAR_BIT(RCC->APB1ENR, RCC_APB1ENR_WWDGEN); }

static inline void RCC_APB1_Enable_BKP(void)    { SET_BIT(RCC->APB1ENR, RCC_APB1ENR_BKPEN); }
static inline void RCC_APB1_Disable_BKP(void)   { CLEAR_BIT(RCC->APB1ENR, RCC_APB1ENR_BKPEN); }

static inline void RCC_APB1_Enable_PWR(void)    { SET_BIT(RCC->APB1ENR, RCC_APB1ENR_PWREN); }
static inline void RCC_APB1_Disable_PWR(void)   { CLEAR_BIT(RCC->APB1ENR, RCC_APB1ENR_PWREN); }

// APB2
static inline void RCC_APB2_Enable_TIM1(void)   { SET_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM1EN); }
static inline void RCC_APB2_Disable_TIM1(void)  { CLEAR_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM1EN); }

static inline void RCC_APB2_Enable_SPI1(void)   { SET_BIT(RCC->APB2ENR, RCC_APB2ENR_SPI1EN); }
static inline void RCC_APB2_Disable_SPI1(void)  { CLEAR_BIT(RCC->APB2ENR, RCC_APB2ENR_SPI1EN); }

static inline void RCC_APB2_Enable_USART1(void) { SET_BIT(RCC->APB2ENR, RCC_APB2ENR_USART1EN); }
static inline void RCC_APB2_Disable_USART1(void){ CLEAR_BIT(RCC->APB2ENR, RCC_APB2ENR_USART1EN); }

static inline void RCC_APB2_Enable_ADC1(void)   { SET_BIT(RCC->APB2ENR, RCC_APB2ENR_ADC1EN); }
static inline void RCC_APB2_Disable_ADC1(void)  { CLEAR_BIT(RCC->APB2ENR, RCC_APB2ENR_ADC1EN); }

static inline void RCC_APB2_Enable_ADC2(void)   { SET_BIT(RCC->APB2ENR, RCC_APB2ENR_ADC2EN); }
static inline void RCC_APB2_Disable_ADC2(void)  { CLEAR_BIT(RCC->APB2ENR, RCC_APB2ENR_ADC2EN); }

static inline void RCC_APB2_Enable_GPIOA(void)  { SET_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPAEN); }
static inline void RCC_APB2_Disable_GPIOA(void) { CLEAR_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPAEN); }

static inline void RCC_APB2_Enable_GPIOB(void)  { SET_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPBEN); }
static inline void RCC_APB2_Disable_GPIOB(void) { CLEAR_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPBEN); }

static inline void RCC_APB2_Enable_GPIOC(void)  { SET_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPCEN); }
static inline void RCC_APB2_Disable_GPIOC(void) { CLEAR_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPCEN); }

static inline void RCC_APB2_Enable_GPIOD(void)  { SET_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPDEN); }
static inline void RCC_APB2_Disable_GPIOD(void) { CLEAR_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPDEN); }

static inline void RCC_APB2_Enable_GPIOE(void)  { SET_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPEEN); }
static inline void RCC_APB2_Disable_GPIOE(void) { CLEAR_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPEEN); }

static inline void RCC_APB2_Enable_AFIO(void)   { SET_BIT(RCC->APB2ENR, RCC_APB2ENR_AFIOEN); }
static inline void RCC_APB2_Disable_AFIO(void)  { CLEAR_BIT(RCC->APB2ENR, RCC_APB2ENR_AFIOEN); }

/* ==============================================
 *							High level functions
 * ============================================== */


static inline void PLL_Enable_With_Config(PLL_INPUT_SOURCE_T source, PLL_MULL_T mull) {
	
	if(RCC_System_Clock_To_PLL_Is_Ready()) { // If system clock is from PLL
		RCC_Set_System_Clock_To_HSI_Output();
		RCC_Wait_System_Clock_To_HSI_Ready();
	}
	
	RCC_PLL_Disable();
	RCC_Wait_PLL_Disable();
	
	if((source == HSE_DIV_1) || (source == HSE_DIV_2)) {
		RCC_HSE_Enable();
		RCC_Wait_HSE_Ready();
	}
	
	MODIFY_REG(RCC->CFGR, RCC_CFGR_PLLSRC | RCC_CFGR_PLLXTPRE, source);
	
	MODIFY_REG(RCC->CFGR, RCC_CFGR_PLLMULL, mull);
	
	if (mull >= MULL_6) {
		RCC_FLASH_Set_Latency(FLASH_LATENCY_2);
	} else if (mull >= 3) {
		RCC_FLASH_Set_Latency(FLASH_LATENCY_1);
	} else {
		RCC_FLASH_Set_Latency(FLASH_LATENCY_0);
	}
	
	RCC_Set_AHB_Clock(AHB_DIV_1);
	RCC_Set_APB1_Clock(APB1_DIV_2);
	RCC_Set_APB2_Clock(APB2_DIV_1);
	
	RCC_PLL_Enable();
	RCC_Wait_PLL_Ready();
	
	RCC_Set_System_Clock_To_PLL_Output();
	RCC_Wait_System_Clock_To_PLL_Ready();
}

static inline void SystemClock_Config_To_72MHz(void) {
    PLL_Enable_With_Config(HSE_DIV_1, MULL_9);
    RCC_Set_AHB_Clock(AHB_DIV_1);
    RCC_Set_APB1_Clock(APB1_DIV_2);
    RCC_Set_APB2_Clock(APB2_DIV_1);
}

#endif
