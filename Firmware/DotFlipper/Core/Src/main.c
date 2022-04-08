/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2021 STMicroelectronics.
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
#include "spi.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "TLE94112ES.h"
#include "DISPLAY.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define NO_OF_CHIPS	1
#define PULSELENGTH 1000
#define BUFFERLENGHT 12
#define DAISYCHAINLENGHT 5
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
int pause = 2000 - PULSELENGTH;
	//uint8_t TXBuf[NO_OF_CHIPS * 2];
	//uint8_t RXBuf[NO_OF_CHIPS * 2];
	//Message Messages[NO_OF_CHIPS];

	//uint8_t controllerData = 0;


///////////////////////////////////
	Display 	display;
	Matrix 		matrix;
	uint32_t 	framebuf1[BUFFERLENGHT];
	uint32_t 	framebuf2[BUFFERLENGHT];
	uint32_t 	difbuf[BUFFERLENGHT];
	Message		messages[DAISYCHAINLENGHT];

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_SPI2_Init();
  /* USER CODE BEGIN 2 */
  HAL_GPIO_WritePin(HB_EN_GPIO_Port, HB_EN_Pin, 1);

  matrix.width = 3;
  matrix.height = 2;
  matrix.DaisyChainLength = DAISYCHAINLENGHT;
  matrix.Messages = messages;

  display.width = 30;
  display.height = 12;
  display.Frontbuffer = framebuf1;
  display.Backbuffer = framebuf2;
  display.Differencebuffer = difbuf;
  display.Matrix = matrix;

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  /*
	  	  Messages[0].RegisterAdress 	= HB_ACT_3_CTRL;
	  	  Messages[0].Data 				= HB10_HS_EN | HB11_LS_EN;
	  	  Messages[0].WriteClear 		= WRITE;

	  	  TLE94112ES_ConstructTXBuffer(TXBuf, NO_OF_CHIPS, Messages);
	  	  HAL_GPIO_WritePin(SPI2_CS_GPIO_Port, SPI2_CS_Pin, 0);
	  	  HAL_SPI_TransmitReceive(&hspi2, TXBuf, RXBuf, NO_OF_CHIPS * 2, HAL_MAX_DELAY);
	  	  HAL_GPIO_WritePin(SPI2_CS_GPIO_Port, SPI2_CS_Pin, 1);
	  	  TLE94112ES_DeconstructRXBuffer(RXBuf, NO_OF_CHIPS, Messages);

	  	  HAL_Delay(PULSELENGTH);

	  	  Messages[0].RegisterAdress 	= HB_ACT_3_CTRL;
	  	  Messages[0].Data 				= 0x00;
	  	  Messages[0].WriteClear 		= WRITE;

	  	  TLE94112ES_ConstructTXBuffer(TXBuf, NO_OF_CHIPS, Messages);
	  	  HAL_GPIO_WritePin(SPI2_CS_GPIO_Port, SPI2_CS_Pin, 0);
	  	  HAL_SPI_TransmitReceive(&hspi2, TXBuf, RXBuf, NO_OF_CHIPS * 2, HAL_MAX_DELAY);
	  	  HAL_GPIO_WritePin(SPI2_CS_GPIO_Port, SPI2_CS_Pin, 1);
	  	  TLE94112ES_DeconstructRXBuffer(RXBuf, NO_OF_CHIPS, Messages);

	  	  HAL_Delay(pause);

	  	  Messages[0].RegisterAdress 	= HB_ACT_3_CTRL;
	  	  Messages[0].Data 				= HB10_LS_EN | HB12_HS_EN;
	  	  Messages[0].WriteClear 		= WRITE;

	  	  TLE94112ES_ConstructTXBuffer(TXBuf, NO_OF_CHIPS, Messages);
	  	  HAL_GPIO_WritePin(SPI2_CS_GPIO_Port, SPI2_CS_Pin, 0);
	  	  HAL_SPI_TransmitReceive(&hspi2, TXBuf, RXBuf, NO_OF_CHIPS * 2, HAL_MAX_DELAY);
	  	  HAL_GPIO_WritePin(SPI2_CS_GPIO_Port, SPI2_CS_Pin, 1);
	  	  TLE94112ES_DeconstructRXBuffer(RXBuf, NO_OF_CHIPS, Messages);

	  	  HAL_Delay(PULSELENGTH);

	  	  Messages[0].RegisterAdress 	= HB_ACT_3_CTRL;
	  	  Messages[0].Data 				= 0x00;
	  	  Messages[0].WriteClear 		= WRITE;

	  	  TLE94112ES_ConstructTXBuffer(TXBuf, NO_OF_CHIPS, Messages);
	  	  HAL_GPIO_WritePin(SPI2_CS_GPIO_Port, SPI2_CS_Pin, 0);
	  	  HAL_SPI_TransmitReceive(&hspi2, TXBuf, RXBuf, NO_OF_CHIPS * 2, HAL_MAX_DELAY);
	  	  HAL_GPIO_WritePin(SPI2_CS_GPIO_Port, SPI2_CS_Pin, 1);
	  	  TLE94112ES_DeconstructRXBuffer(RXBuf, NO_OF_CHIPS, Messages);

	  	  HAL_Delay(pause);
	  	  */
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  RCC_OscInitStruct.PLL.PREDIV = RCC_PREDIV_DIV1;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV2;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
