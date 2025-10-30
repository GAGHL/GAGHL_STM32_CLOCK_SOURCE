#ifndef GAGHL_STM32_CLOCK_MANAGER_H
#define GAGHL_STM32_CLOCK_MANAGER_H

typedef enum {
	Clock_Source_HSI = 0,
	Clock_Source_HSE,
	Clock_Source_PLL,
	PLL_Source_HSE,
	PLL_Source_HSI_div_2
} CLOCK_SOURCE_T;

void Check_Clock_Source(void);

static inline void HSI_ON(void);
static inline void HSE_ON(void);
static inline void PLL_ON(void);

static inline void HSI_ON_AND_STABLAZITION(void);
static inline void HSE_ON_AND_STABLAZITION(void);
static inline void PLL_ON_AND_STABLAZITION(void);

static inline void SET_HSI_CLOCK_SOURCE(void);


static inline void SET_HSE_PREDIV(void);


static inline void SET_PLL_CLOCK_SOURCE(void);
static inline void SET_PLL_MULTIPLIER(void);

#endif
