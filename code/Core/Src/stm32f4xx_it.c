/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32f4xx_it.c
  * @brief   Interrupt Service Routines.
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
/*
 * Format for IP address
 * IP1...;
 * IP2...;
 * IP3...;
 * IP4...;
 *
 * For gateway
 * GW1...;
 * GW2...;
 * GW3...;
 * GW4...;
 */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f4xx_it.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
extern char str_rx2[25];
extern char flag_ok;
extern uint8_t flag_usb;
extern char ip1;
extern char ip2;
extern char ip3;
extern char ip4;
extern char gw1;
extern char gw2;
extern char gw3;
extern char gw4;
extern char flag_get_ip;

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/
extern PCD_HandleTypeDef hpcd_USB_OTG_FS;
extern SPI_HandleTypeDef hspi1;
extern TIM_HandleTypeDef htim1;

/* USER CODE BEGIN EV */

/* USER CODE END EV */

/******************************************************************************/
/*           Cortex-M4 Processor Interruption and Exception Handlers          */
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{
  /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

  /* USER CODE END NonMaskableInt_IRQn 0 */
  HAL_RCC_NMI_IRQHandler();
  /* USER CODE BEGIN NonMaskableInt_IRQn 1 */
  while (1)
  {
  }
  /* USER CODE END NonMaskableInt_IRQn 1 */
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{
  /* USER CODE BEGIN HardFault_IRQn 0 */

  /* USER CODE END HardFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_HardFault_IRQn 0 */
    /* USER CODE END W1_HardFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Memory management fault.
  */
void MemManage_Handler(void)
{
  /* USER CODE BEGIN MemoryManagement_IRQn 0 */

  /* USER CODE END MemoryManagement_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_MemoryManagement_IRQn 0 */
    /* USER CODE END W1_MemoryManagement_IRQn 0 */
  }
}

/**
  * @brief This function handles Pre-fetch fault, memory access fault.
  */
void BusFault_Handler(void)
{
  /* USER CODE BEGIN BusFault_IRQn 0 */

  /* USER CODE END BusFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_BusFault_IRQn 0 */
    /* USER CODE END W1_BusFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Undefined instruction or illegal state.
  */
void UsageFault_Handler(void)
{
  /* USER CODE BEGIN UsageFault_IRQn 0 */

  /* USER CODE END UsageFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_UsageFault_IRQn 0 */
    /* USER CODE END W1_UsageFault_IRQn 0 */
  }
}

/**
  * @brief This function handles System service call via SWI instruction.
  */
void SVC_Handler(void)
{
  /* USER CODE BEGIN SVCall_IRQn 0 */

  /* USER CODE END SVCall_IRQn 0 */
  /* USER CODE BEGIN SVCall_IRQn 1 */

  /* USER CODE END SVCall_IRQn 1 */
}

/**
  * @brief This function handles Debug monitor.
  */
void DebugMon_Handler(void)
{
  /* USER CODE BEGIN DebugMonitor_IRQn 0 */

  /* USER CODE END DebugMonitor_IRQn 0 */
  /* USER CODE BEGIN DebugMonitor_IRQn 1 */

  /* USER CODE END DebugMonitor_IRQn 1 */
}

/**
  * @brief This function handles Pendable request for system service.
  */
void PendSV_Handler(void)
{
  /* USER CODE BEGIN PendSV_IRQn 0 */

  /* USER CODE END PendSV_IRQn 0 */
  /* USER CODE BEGIN PendSV_IRQn 1 */

  /* USER CODE END PendSV_IRQn 1 */
}

/**
  * @brief This function handles System tick timer.
  */
void SysTick_Handler(void)
{
  /* USER CODE BEGIN SysTick_IRQn 0 */

  /* USER CODE END SysTick_IRQn 0 */

  /* USER CODE BEGIN SysTick_IRQn 1 */

  /* USER CODE END SysTick_IRQn 1 */
}

/******************************************************************************/
/* STM32F4xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f4xx.s).                    */
/******************************************************************************/

/**
  * @brief This function handles TIM1 update interrupt and TIM10 global interrupt.
  */
void TIM1_UP_TIM10_IRQHandler(void)
{
  /* USER CODE BEGIN TIM1_UP_TIM10_IRQn 0 */
	if (LL_TIM_IsActiveFlag_UPDATE(TIM10)) {
			LL_TIM_ClearFlag_UPDATE(TIM10);
			LL_GPIO_TogglePin(GPIOC, LED_Pin);
	}

  /* USER CODE END TIM1_UP_TIM10_IRQn 0 */
  HAL_TIM_IRQHandler(&htim1);
  /* USER CODE BEGIN TIM1_UP_TIM10_IRQn 1 */

  /* USER CODE END TIM1_UP_TIM10_IRQn 1 */
}

/**
  * @brief This function handles SPI1 global interrupt.
  */
void SPI1_IRQHandler(void)
{
  /* USER CODE BEGIN SPI1_IRQn 0 */

  /* USER CODE END SPI1_IRQn 0 */
  HAL_SPI_IRQHandler(&hspi1);
  /* USER CODE BEGIN SPI1_IRQn 1 */

  /* USER CODE END SPI1_IRQn 1 */
}

/**
  * @brief This function handles USART1 global interrupt.
  */
void USART1_IRQHandler(void) {
	/* USER CODE BEGIN USART1_IRQn 0 */
	char letter;
	static uint8_t i = 0;
	letter = USART1->DR;
	if (letter != '\r') {
		str_rx2[i] = letter;
		i++;
		if (i == 24)
			i = 0;
	} else {
		str_rx2[i] = '\r';
		i = 0;
		flag_ok = 1;
		if ((str_rx2[0]=='G')&&(str_rx2[1]=='E')&&(str_rx2[2]=='T')){
			flag_get_ip = 1;
		}

		if ((str_rx2[0]=='A')&&(str_rx2[1]=='M')&&(str_rx2[2]=='1')){
			flag_usb = 1;
				}

		if ((str_rx2[0] == 'I') && (str_rx2[1] == 'P')) {
			if (str_rx2[2] == '1') {
				if (str_rx2[3] != ';') {
					ip1 = (str_rx2[3] - 48) * 100;
				}
				if (str_rx2[4] != ';') {
					ip1 = ip1 + (str_rx2[4] - 48) * 10;
				}
				if (str_rx2[5] != ';') {
					ip1 = ip1 + (str_rx2[5] - 48);
				}
			}
			if (str_rx2[2] == '2') {
				if (str_rx2[3] != ';') {
					ip2 = (str_rx2[3] - 48) * 100;
				}
				if (str_rx2[4] != ';') {
					ip2 = ip2 + (str_rx2[4] - 48) * 10;
				}
				if (str_rx2[5] != ';') {
					ip2 = ip2 + (str_rx2[5] - 48);
				}
			}
			if (str_rx2[2] == '3') {
				if (str_rx2[3] != ';') {
					ip3 = (str_rx2[3] - 48) * 100;
				}
				if (str_rx2[4] != ';') {
					ip3 = ip3 + (str_rx2[4] - 48) * 10;
				}
				if (str_rx2[5] != ';') {
					ip3 = ip3 + (str_rx2[5] - 48);
				}
			}
			if (str_rx2[2] == '4') {
				if (str_rx2[3] != ';') {
					ip4 = (str_rx2[3] - 48) * 100;
				}
				if (str_rx2[4] != ';') {
					ip4 = ip4 + (str_rx2[4] - 48) * 10;
				}
				if (str_rx2[5] != ';') {
					ip4 = ip4 + (str_rx2[5] - 48);
				}
			}
		}
		if ((str_rx2[0] == 'G') && (str_rx2[1] == 'W')) {
			if (str_rx2[2] == '1') {
				if (str_rx2[3] != ';') {
					gw1 = (str_rx2[3] - 48) * 100;
				}
				if (str_rx2[4] != ';') {
					gw1 = gw1 + (str_rx2[4] - 48) * 10;
				}
				if (str_rx2[5] != ';') {
					gw1 = gw1 + (str_rx2[5] - 48);
				}
			}
			if (str_rx2[2] == '2') {
				if (str_rx2[3] != ';') {
					gw2 = (str_rx2[3] - 48) * 100;
				}
				if (str_rx2[4] != ';') {
					gw2 = gw2 + (str_rx2[4] - 48) * 10;
				}
				if (str_rx2[5] != ';') {
					gw2 = gw2 + (str_rx2[5] - 48);
				}
			}
			if (str_rx2[2] == '3') {
				if (str_rx2[3] != ';') {
					gw3 = (str_rx2[3] - 48) * 100;
				}
				if (str_rx2[4] != ';') {
					gw3 = gw3 + (str_rx2[4] - 48) * 10;
				}
				if (str_rx2[5] != ';') {
					gw3 = gw3 + (str_rx2[5] - 48);
				}
			}
			if (str_rx2[2] == '4') {
				if (str_rx2[3] != ';') {
					gw4 = (str_rx2[3] - 48) * 100;
				}
				if (str_rx2[4] != ';') {
					gw4 = gw4 + (str_rx2[4] - 48) * 10;
				}
				if (str_rx2[5] != ';') {
					gw4 = gw4 + (str_rx2[5] - 48);
				}
			}
		}
	}

	/* USER CODE END USART1_IRQn 0 */
	/* USER CODE BEGIN USART1_IRQn 1 */

	/* USER CODE END USART1_IRQn 1 */
}

/**
  * @brief This function handles USB On The Go FS global interrupt.
  */
void OTG_FS_IRQHandler(void)
{
  /* USER CODE BEGIN OTG_FS_IRQn 0 */

  /* USER CODE END OTG_FS_IRQn 0 */
  HAL_PCD_IRQHandler(&hpcd_USB_OTG_FS);
  /* USER CODE BEGIN OTG_FS_IRQn 1 */

  /* USER CODE END OTG_FS_IRQn 1 */
}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
