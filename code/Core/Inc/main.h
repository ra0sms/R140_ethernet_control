/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

#include "stm32f4xx_ll_tim.h"
#include "stm32f4xx_ll_usart.h"
#include "stm32f4xx_ll_rcc.h"
#include "stm32f4xx_ll_system.h"
#include "stm32f4xx_ll_gpio.h"
#include "stm32f4xx_ll_exti.h"
#include "stm32f4xx_ll_bus.h"
#include "stm32f4xx_ll_cortex.h"
#include "stm32f4xx_ll_utils.h"
#include "stm32f4xx_ll_pwr.h"
#include "stm32f4xx_ll_dma.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LED_Pin LL_GPIO_PIN_13
#define LED_GPIO_Port GPIOC
#define BTN_Pin LL_GPIO_PIN_0
#define BTN_GPIO_Port GPIOA
#define SPI_RST_Pin LL_GPIO_PIN_3
#define SPI_RST_GPIO_Port GPIOA
#define SPI1_CS_Pin LL_GPIO_PIN_4
#define SPI1_CS_GPIO_Port GPIOA
#define OUT1_Pin LL_GPIO_PIN_0
#define OUT1_GPIO_Port GPIOB
#define OUT2_Pin LL_GPIO_PIN_1
#define OUT2_GPIO_Port GPIOB
#define OUT3_Pin LL_GPIO_PIN_2
#define OUT3_GPIO_Port GPIOB
#define OUT11_Pin LL_GPIO_PIN_10
#define OUT11_GPIO_Port GPIOB
#define OUT12_Pin LL_GPIO_PIN_12
#define OUT12_GPIO_Port GPIOB
#define OUT13_Pin LL_GPIO_PIN_13
#define OUT13_GPIO_Port GPIOB
#define OUT14_Pin LL_GPIO_PIN_14
#define OUT14_GPIO_Port GPIOB
#define OUT15_Pin LL_GPIO_PIN_15
#define OUT15_GPIO_Port GPIOB
#define OUT16_Pin LL_GPIO_PIN_15
#define OUT16_GPIO_Port GPIOA
#define OUT4_Pin LL_GPIO_PIN_3
#define OUT4_GPIO_Port GPIOB
#define OUT5_Pin LL_GPIO_PIN_4
#define OUT5_GPIO_Port GPIOB
#define OUT6_Pin LL_GPIO_PIN_5
#define OUT6_GPIO_Port GPIOB
#define OUT7_Pin LL_GPIO_PIN_6
#define OUT7_GPIO_Port GPIOB
#define OUT8_Pin LL_GPIO_PIN_7
#define OUT8_GPIO_Port GPIOB
#define OUT9_Pin LL_GPIO_PIN_8
#define OUT9_GPIO_Port GPIOB
#define OUT10_Pin LL_GPIO_PIN_9
#define OUT10_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
