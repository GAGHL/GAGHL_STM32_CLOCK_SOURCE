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

static inline void CSS_TURN_ON(void);
static inline void HSI_TURN_ON(void);
static inline void HSE_TURN_ON(void);
static inline void PLL_TURN_ON(void);

static inline void SET_PLL_MULTIPLIER_mull_2(void);
static inline void SET_PLL_MULTIPLIER_mull_3(void);
static inline void SET_PLL_MULTIPLIER_mull_4(void);
static inline void SET_PLL_MULTIPLIER_mull_5(void);
static inline void SET_PLL_MULTIPLIER_mull_6(void);
static inline void SET_PLL_MULTIPLIER_mull_7(void);
static inline void SET_PLL_MULTIPLIER_mull_8(void);
static inline void SET_PLL_MULTIPLIER_mull_9(void);
static inline void SET_PLL_MULTIPLIER_mull_10(void);
static inline void SET_PLL_MULTIPLIER_mull_11(void);
static inline void SET_PLL_MULTIPLIER_mull_12(void);
static inline void SET_PLL_MULTIPLIER_mull_13(void);
static inline void SET_PLL_MULTIPLIER_mull_14(void);
static inline void SET_PLL_MULTIPLIER_mull_15(void);
static inline void SET_PLL_MULTIPLIER_mull_16(void);

static inline void SET_PLL_HSE_PRESCALER_div_1(void);
static inline void SET_PLL_HSE_PRESCALER_div_2(void);

static inline void SET_PLL_SOURCE_HSI(void);
static inline void SET_PLL_SOURCE_HSE(void);

static inline void SET_SYSTEM_CLOCK_SOURCE_HSI(void);
static inline void SET_SYSTEM_CLOCK_SOURCE_HSE(void);
static inline void SET_SYSTEM_CLOCK_SOURCE_PLL(void);

static inline void HSI_ON_AND_STABLAZITION(void);
static inline void HSE_ON_AND_STABLAZITION(void);
static inline void PLL_ON_AND_STABLAZITION(void);

static inline void SET_HSI_CLOCK_SOURCE(void);


static inline void SET_HSE_PREDIV(void);


static inline void SET_PLL_CLOCK_SOURCE(void);
static inline void SET_PLL_MULTIPLIER(void);

#endif
