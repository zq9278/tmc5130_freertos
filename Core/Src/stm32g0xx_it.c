/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32g0xx_it.c
  * @brief   Interrupt Service Routines.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32g0xx_it.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
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
extern DMA_HandleTypeDef hdma_adc1;
extern ADC_HandleTypeDef hadc1;
extern DMA_HandleTypeDef hdma_i2c1_rx;
extern DMA_HandleTypeDef hdma_i2c1_tx;
extern DMA_HandleTypeDef hdma_i2c2_rx;
extern DMA_HandleTypeDef hdma_i2c2_tx;
extern I2C_HandleTypeDef hi2c1;
extern I2C_HandleTypeDef hi2c2;
extern DMA_HandleTypeDef hdma_tim16_ch1;
extern DMA_HandleTypeDef hdma_usart1_tx;
extern UART_HandleTypeDef huart1;
extern TIM_HandleTypeDef htim6;

/* USER CODE BEGIN EV */

/* USER CODE END EV */

/******************************************************************************/
/*           Cortex-M0+ Processor Interruption and Exception Handlers          */
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{
  /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

  /* USER CODE END NonMaskableInt_IRQn 0 */
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

/******************************************************************************/
/* STM32G0xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32g0xx.s).                    */
/******************************************************************************/

/**
  * @brief This function handles EXTI line 2 and line 3 interrupts.
  */
void EXTI2_3_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI2_3_IRQn 0 */

  /* USER CODE END EXTI2_3_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(SW_CNT_Pin);
  /* USER CODE BEGIN EXTI2_3_IRQn 1 */

  /* USER CODE END EXTI2_3_IRQn 1 */
}

/**
  * @brief This function handles DMA1 channel 1 interrupt.
  */
void DMA1_Channel1_IRQHandler(void)
{
  /* USER CODE BEGIN DMA1_Channel1_IRQn 0 */

  /* USER CODE END DMA1_Channel1_IRQn 0 */
  HAL_DMA_IRQHandler(&hdma_i2c1_rx);
  /* USER CODE BEGIN DMA1_Channel1_IRQn 1 */

  /* USER CODE END DMA1_Channel1_IRQn 1 */
}

/**
  * @brief This function handles DMA1 channel 2 and channel 3 interrupts.
  */
void DMA1_Channel2_3_IRQHandler(void)
{
  /* USER CODE BEGIN DMA1_Channel2_3_IRQn 0 */

  /* USER CODE END DMA1_Channel2_3_IRQn 0 */
  HAL_DMA_IRQHandler(&hdma_i2c1_tx);
  HAL_DMA_IRQHandler(&hdma_i2c2_rx);
  /* USER CODE BEGIN DMA1_Channel2_3_IRQn 1 */

  /* USER CODE END DMA1_Channel2_3_IRQn 1 */
}

/**
  * @brief This function handles DMA1 channel 4, channel 5, channel 6, channel 7 and DMAMUX1 interrupts.
  */
void DMA1_Ch4_7_DMAMUX1_OVR_IRQHandler(void)
{
  /* USER CODE BEGIN DMA1_Ch4_7_DMAMUX1_OVR_IRQn 0 */

  /* USER CODE END DMA1_Ch4_7_DMAMUX1_OVR_IRQn 0 */
  HAL_DMA_IRQHandler(&hdma_i2c2_tx);
  HAL_DMA_IRQHandler(&hdma_adc1);
  HAL_DMA_IRQHandler(&hdma_usart1_tx);
  HAL_DMA_IRQHandler(&hdma_tim16_ch1);
  /* USER CODE BEGIN DMA1_Ch4_7_DMAMUX1_OVR_IRQn 1 */

  /* USER CODE END DMA1_Ch4_7_DMAMUX1_OVR_IRQn 1 */
}

/**
  * @brief This function handles ADC1 interrupt.
  */
void ADC1_IRQHandler(void)
{
  /* USER CODE BEGIN ADC1_IRQn 0 */

  /* USER CODE END ADC1_IRQn 0 */
  HAL_ADC_IRQHandler(&hadc1);
  /* USER CODE BEGIN ADC1_IRQn 1 */

  /* USER CODE END ADC1_IRQn 1 */
}

/**
  * @brief This function handles TIM6 global interrupt.
  */
void TIM6_IRQHandler(void)
{
  /* USER CODE BEGIN TIM6_IRQn 0 */

  /* USER CODE END TIM6_IRQn 0 */
  HAL_TIM_IRQHandler(&htim6);
  /* USER CODE BEGIN TIM6_IRQn 1 */

  /* USER CODE END TIM6_IRQn 1 */
}

/**
  * @brief This function handles I2C1 event global interrupt / I2C1 wake-up interrupt through EXTI line 23.
  */
void I2C1_IRQHandler(void)
{
  /* USER CODE BEGIN I2C1_IRQn 0 */

  /* USER CODE END I2C1_IRQn 0 */
  if (hi2c1.Instance->ISR & (I2C_FLAG_BERR | I2C_FLAG_ARLO | I2C_FLAG_OVR)) {
    HAL_I2C_ER_IRQHandler(&hi2c1);
  } else {
    HAL_I2C_EV_IRQHandler(&hi2c1);
  }
  /* USER CODE BEGIN I2C1_IRQn 1 */

  /* USER CODE END I2C1_IRQn 1 */
}

/**
  * @brief This function handles I2C2 global interrupt.
  */
void I2C2_IRQHandler(void)
{
  /* USER CODE BEGIN I2C2_IRQn 0 */

  /* USER CODE END I2C2_IRQn 0 */
  if (hi2c2.Instance->ISR & (I2C_FLAG_BERR | I2C_FLAG_ARLO | I2C_FLAG_OVR)) {
    HAL_I2C_ER_IRQHandler(&hi2c2);
  } else {
    HAL_I2C_EV_IRQHandler(&hi2c2);
  }
  /* USER CODE BEGIN I2C2_IRQn 1 */

  /* USER CODE END I2C2_IRQn 1 */
}

/**
  * @brief This function handles USART1 global interrupt / USART1 wake-up interrupt through EXTI line 25.
  */
void USART1_IRQHandler(void)
{
  /* USER CODE BEGIN USART1_IRQn 0 */

  /* USER CODE END USART1_IRQn 0 */
  HAL_UART_IRQHandler(&huart1);
  /* USER CODE BEGIN USART1_IRQn 1 */

  /* USER CODE END USART1_IRQn 1 */
}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
