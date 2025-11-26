<h1 align="center">In the name of GOD</h1>

# GAGHL_STM32_CLOCK_MANAGER

**A lightweight and minimal clock management library for STM32F1 series**

GAGHL_STM32_CLOCK_MANAGER is a header-only, C-based library for managing clocks on STM32F10x microcontrollers. It provides easy-to-use functions to configure system clocks, PLL, AHB/APB dividers, and peripheral clocks in a manner similar to ST’s Low-Layer (LL) drivers.

## 💡 Browse Online
You can explore this repository in a VS Code like interface using [this link](https://github1s.com/GAGHL/GAGHL_STM32_CLOCK_MANAGER).

## 📦 Features

- ✅ Configure system clock source (HSI, HSE, PLL)
- ✅ Configure PLL source and multiplier
- ✅ Set FLASH latency automatically based on system clock
- ✅ Configure AHB, APB1, and APB2 prescalers
- ✅ Enable/disable clocks for GPIO, USART, SPI, I2C, TIM, ADC, CRC, DMA, and more
- ✅ Inline functions for quick clock ready/disabling checks
- ✅ Optional timeout for clock ready waits


## 📚 API Overview

| Function                                      | Parameters                                   | Description                                               |
| --------------------------------------------- | -------------------------------------------- | --------------------------------------------------------- |
| `PLL_Enable_With_Config()`                    | `PLL_INPUT_SOURCE_T source, PLL_MULL_T mull` | Enable PLL with specified input and multiplication factor |
| `SystemClock_Config_To_72MHz()`               | *(void)*                                     | Configure system to 72 MHz using HSE + PLL                |
| `RCC_Set_System_Clock_To_HSI_Output()`        | *(void)*                                     | Switch system clock to HSI                                |
| `RCC_Set_System_Clock_To_HSE_Output()`        | *(void)*                                     | Switch system clock to HSE                                |
| `RCC_Set_System_Clock_To_PLL_Output()`        | *(void)*                                     | Switch system clock to PLL                                |
| `RCC_Set_AHB_Clock()`                         | `AHB_DIV_T div`                              | Set AHB prescaler                                         |
| `RCC_Set_APB1_Clock()`                        | `APB1_DIV_T div`                             | Set APB1 prescaler                                        |
| `RCC_Set_APB2_Clock()`                        | `APB2_DIV_T div`                             | Set APB2 prescaler                                        |
| `RCC_FLASH_Set_Latency()`                     | `FLASH_LATENCY_T latency`                    | Set flash latency                                         |
| `RCC_APB1_Enable_TIM2()`                      | *(void)*                                     | Enable TIM2 clock on APB1                                 |
| `RCC_APB2_Enable_GPIOA()`                     | *(void)*                                     | Enable GPIOA clock on APB2                                |
| *(and similar functions for all peripherals)* |                                              |                                                           |

Most functions are defined static inline for zero-overhead usage.

## 🚀 Getting Started

### 1. Add the files to your project

Copy these files into your STM32 project:

- `GAGHL_STM32_CLOCK_MANAGER.c`
- `GAGHL_STM32_CLOCK_MANAGER.h`

### 2. Include it in your code

```c
#include "GAGHL_STM32_CLOCK_MANAGER.h"
```

### 3. Configure system clock
```c
#include <stm32f10x.h>
#include "GAGHL_STM32_CLOCK_MANAGER.h"

int main(void) {
    // Configure STM32F103 to 72 MHz
    SystemClock_Config_To_72MHz();

    // Enable GPIOA and USART1
    RCC_APB2_Enable_GPIOA();
    RCC_APB2_Enable_USART1();

    while(1) {
        // Your main code
    }
}

```
---

## 🔧 Requirements

- STM32F1 series microcontrollers (e.g., STM32F103C8, STM32F103RCT6)
- ARM Cortex-M3 toolchain (STM32CubeIDE, Keil, GCC ARM, etc.)

## 🛠️ TODO

- [ ] Add more STM32F1 peripheral enable helpers
- [ ] Add interrupt-based clock failure detection (CSS)





## 🤝 Contributing

Contributions are welcome!  
Whether it's bug fixes, feature suggestions, or improvements — your help is appreciated.

- Fork the repository
- Create a new branch (`git checkout -b feature/my-feature`)
- Commit your changes (`git commit -am 'Add new feature'`)
- Push to the branch (`git push origin feature/my-feature`)
- Open a Pull Request

If you’re using this library in your project, feel free to let me know — I’d love to check it out!

## License

This project is licensed under the Creative Commons Attribution-NonCommercial 4.0 International (CC BY-NC 4.0).

You are free to:
- Share — copy and redistribute the material in any medium or format
- Adapt — remix, transform, and build upon the material

Under the following terms:
- **Attribution** — You must give appropriate credit to the author (GAGHL).
- **NonCommercial** — You may not use the material for commercial purposes without explicit permission.

For more information, see the full license: [https://creativecommons.org/licenses/by-nc/4.0/](https://creativecommons.org/licenses/by-nc/4.0/)

© 2025 GAGHL. All rights reserved.

## Author

Developed by [GAGHL](https://github.com/GAGHL)
