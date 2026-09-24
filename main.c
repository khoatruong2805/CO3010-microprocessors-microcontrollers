/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
//uint16_t clock_pins[12] = {LED_1_Pin, LED_2_Pin, LED_3_Pin, LED_4_Pin, LED_5_Pin, LED_6_Pin, LED_7_Pin, LED_8_Pin, LED_9_Pin, LED_10_Pin, LED_11_Pin, LED_12_Pin};
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */


// Ex 4
void display7SEG(int num) {
  uint8_t seg7[10] = {0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02, 0x78, 0x00, 0x10};
  if (num < 0 || num > 9) return;
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, (seg7[num] >> 0) & 0x01); // a
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, (seg7[num] >> 1) & 0x01); // b
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, (seg7[num] >> 2) & 0x01); // c
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, (seg7[num] >> 3) & 0x01); // d
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, (seg7[num] >> 4) & 0x01); // e
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, (seg7[num] >> 5) & 0x01); // f
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, (seg7[num] >> 6) & 0x01); // g
}

//// Ex 7
//void clearAllClock(){
//	for (int i = 0; i<12;i++){
//		HAL_GPIO_WritePin(GPIOA, clock_pins[i], GPIO_PIN_SET);
//	}
//}
//
//// Ex 8
//void setNumberOnClock(int num){
//	if (num < 0 || num > 11) return;
//	HAL_GPIO_WritePin(GPIOA, clock_pins[num],GPIO_PIN_RESET);
//}
//
//// Ex 9
//void clearNumberOnClock(int num){
//	if (num < 0 || num > 11) return;
//	HAL_GPIO_WritePin(GPIOA, clock_pins[num],GPIO_PIN_SET);
//}



void Run_Exercise_1(void) {
  while (1) {
	  HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_SET);
	  HAL_Delay(2000);
	  HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_RESET);
	  HAL_Delay(2000);
  }
}

void Run_Exercise_2(void) {
  while (1) {
	  HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET);
	  HAL_Delay(5000);

	  HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET);
	  HAL_Delay(2000);

	  HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_RESET);
	  HAL_Delay(3000);
  }
}

//void Run_Exercise_3(void) {
//  while (1) {
//    HAL_GPIO_WritePin(GPIOA, LED_RED_Pin|LED_YELLOW_Pin, GPIO_PIN_SET);
//    HAL_GPIO_WritePin(GPIOA, LED_GREEN_Pin, GPIO_PIN_RESET);
//    HAL_GPIO_WritePin(GPIOA, LED_RED_2_Pin, GPIO_PIN_RESET);
//    HAL_GPIO_WritePin(GPIOA, LED_YELLOW_2_Pin|LED_GREEN_2_Pin, GPIO_PIN_SET);
//    HAL_Delay(5000);
//
//    HAL_GPIO_WritePin(GPIOA, LED_GREEN_Pin, GPIO_PIN_SET);
//    HAL_GPIO_WritePin(GPIOA, LED_YELLOW_Pin, GPIO_PIN_RESET);
//    HAL_Delay(2000);
//
//    HAL_GPIO_WritePin(GPIOA, LED_YELLOW_Pin, GPIO_PIN_SET);
//    HAL_GPIO_WritePin(GPIOA, LED_RED_Pin, GPIO_PIN_RESET);
//    HAL_GPIO_WritePin(GPIOA, LED_RED_2_Pin, GPIO_PIN_SET);
//    HAL_GPIO_WritePin(GPIOA, LED_GREEN_2_Pin, GPIO_PIN_RESET);
//    HAL_Delay(5000);
//
//    HAL_GPIO_WritePin(GPIOA, LED_GREEN_2_Pin, GPIO_PIN_SET);
//    HAL_GPIO_WritePin(GPIOA, LED_YELLOW_2_Pin, GPIO_PIN_RESET);
//    HAL_Delay(2000);
//  }
//}

void Run_Exercise_4(void) {
  while (1) {
    for (int i = 0; i <= 9; i++) {
      display7SEG(i);
      HAL_Delay(1000);
    }
  }
}

//void Run_Exercise_5(void) {
//  while (1) {
//	  HAL_GPIO_WritePin(GPIOA, LED_RED_Pin|LED_YELLOW_Pin, GPIO_PIN_SET);
//	  HAL_GPIO_WritePin(GPIOA, LED_GREEN_Pin, GPIO_PIN_RESET);
//	  HAL_GPIO_WritePin(GPIOA, LED_RED_2_Pin, GPIO_PIN_RESET);
//	  HAL_GPIO_WritePin(GPIOA, LED_YELLOW_2_Pin|LED_GREEN_2_Pin, GPIO_PIN_SET);
//	  for (int i = 5; i>=0; i -= 1){
//		  display7SEG(i);
//		  HAL_Delay(1000);
//	  }
//
//	  HAL_GPIO_WritePin(GPIOA, LED_GREEN_Pin, GPIO_PIN_SET);
//	  HAL_GPIO_WritePin(GPIOA, LED_YELLOW_Pin, GPIO_PIN_RESET);
//	  for (int i = 2; i>=0; i -= 1){
//		  display7SEG(i);
//		  HAL_Delay(1000);
//	  }
//
//	  HAL_GPIO_WritePin(GPIOA, LED_YELLOW_Pin, GPIO_PIN_SET);
//	  HAL_GPIO_WritePin(GPIOA, LED_RED_Pin, GPIO_PIN_RESET);
//	  HAL_GPIO_WritePin(GPIOA, LED_RED_2_Pin, GPIO_PIN_SET);
//	  HAL_GPIO_WritePin(GPIOA, LED_GREEN_2_Pin, GPIO_PIN_RESET);
//	  for (int i = 5; i>=0; i -= 1){
//		  display7SEG(i);
//		  HAL_Delay(1000);
//	  }
//
//	  HAL_GPIO_WritePin(GPIOA, LED_GREEN_2_Pin, GPIO_PIN_SET);
//	  HAL_GPIO_WritePin(GPIOA, LED_YELLOW_2_Pin, GPIO_PIN_RESET);
//	  for (int i = 2; i>=0; i -= 1){
//		  display7SEG(i);
//		  HAL_Delay(1000);
//	  }
//  }
//}

//void Run_Exercise_6(void) {
//  while (1) {
//	  for (int i = 0; i<12;i++){
//		  for(int j = 0;j<12;j++){
//			  HAL_GPIO_WritePin(GPIOA,clock_pins[j],GPIO_PIN_SET);
//		  }
//		  HAL_GPIO_WritePin(GPIOA,clock_pins[i],GPIO_PIN_RESET);
//		  HAL_Delay(1000);
//	  }
//  }
//}
//
//void Run_Exercise_7(void) {
//  while (1) {
//    for (int i = 0; i < 12; i++) {
//      HAL_GPIO_WritePin(GPIOA, clock_pins[i], GPIO_PIN_RESET);
//    }
//    HAL_Delay(1000);
//    clearAllClock();
//    HAL_Delay(1000);
//  }
//}
//
//void Run_Exercise_8(void) {
//  while (1) {
//    clearAllClock();
//    for (int i = 0; i < 12; i++) {
//      setNumberOnClock(i);
//      HAL_Delay(500);
//    }
//    HAL_Delay(1000);
//  }
//}
//
//void Run_Exercise_9(void) {
//  while (1) {
//    for (int i = 0; i < 12; i++) {
//      setNumberOnClock(i);
//    }
//    HAL_Delay(500);
//    for (int i = 0; i < 12; i++) {
//      clearNumberOnClock(i);
//      HAL_Delay(1000);
//    }
//  }
//}
//
//void Run_Exercise_10(void) {
//  int hour = 0, minute = 0, second = 0;
//  while (1) {
//    clearAllClock();
//    setNumberOnClock(hour);
//    setNumberOnClock(minute / 5);
//    setNumberOnClock(second / 5);
//    second++;
//    if (second >= 60) {
//      second = 0;
//      minute++;
//    }
//    if (minute >= 60) {
//      minute = 0;
//      hour++;
//    }
//    if (hour >= 12) {
//      hour = 0;
//    }
//    HAL_Delay(50);
//  }
//}

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
  /* USER CODE BEGIN 2 */
  //Run_Exercise_1();
  //Run_Exercise_2();
  //Run_Exercise_3();
  //Run_Exercise_4();
  //Run_Exercise_5();
  //Run_Exercise_6();
  //Run_Exercise_7();
  //Run_Exercise_8();
  //Run_Exercise_9();
  //Run_Exercise_10();

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	while (1)
	{
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
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LED_RED_Pin|LED_YELLOW_Pin|LED_GREEN_Pin|LED_YELLOW_2_Pin
                          |LED_GREEN_2_Pin|LED_7_Pin|LED_8_Pin|LED_9_Pin
                          |LED_10_Pin|LED_11_Pin|LED_12_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6, GPIO_PIN_RESET);

  /*Configure GPIO pins : LED_RED_Pin LED_YELLOW_Pin LED_GREEN_Pin LED_YELLOW_2_Pin
                           LED_GREEN_2_Pin LED_7_Pin LED_8_Pin LED_9_Pin
                           LED_10_Pin LED_11_Pin LED_12_Pin */
  GPIO_InitStruct.Pin = LED_RED_Pin|LED_YELLOW_Pin|LED_GREEN_Pin|LED_YELLOW_2_Pin
                          |LED_GREEN_2_Pin|LED_7_Pin|LED_8_Pin|LED_9_Pin
                          |LED_10_Pin|LED_11_Pin|LED_12_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PB0 PB1 PB2 PB3
                           PB4 PB5 PB6 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

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

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
