/*********************************************************************
 * @file        item.h
 * @brief       Template_BriefDescription.
 * @details     TemplateDetailsDescription.\n
 *
 * @author      xxxxxx
 * @date        jj/mm/yyyy
 * @version     1.0
 */

// ********************************************************************
// *                      Includes
// ********************************************************************
#include "FMK_HAL/FKM_IO/Src/FMK_IO.h"
TIM_HandleTypeDef htim3;
// ********************************************************************
// *                      Defines
// ********************************************************************
/*void EXTI0_IRQHandler(void)
{
    HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_0);  // Gérer l'interruption pour le pin 0
}*/

void Error_Handler(void);
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM3_Init(void);

int main(void)
{
  // Initialiser le système
  HAL_Init();
  SystemClock_Config();
  FMKCPU_Init();
  // MX_GPIO_Init();
  // MX_TIM3_Init();
  // HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
  FMKIO_Set_OutPwmSigCfg(FMKIO_OUTPUT_SIGPWM_5, FMKIO_PULL_MODE_UNABLE, 10, 500, False);
  while (1)
  {
    FMKIO_Set_OutPwmSigValue(FMKIO_OUTPUT_SIGPWM_5, 1000);
    // TIM3->CCR1 = (t_uint32)392;

    HAL_Delay(1000);

    // TIM3->CCR1 = (t_uint32)700;
    // FMKIO_Set_OutPwmSigValue(FMKIO_OUTPUT_SIGPWM_1, 1000);

    // HAL_Delay(1000);
  }
}

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
    while(1);
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
   while(1);
  }
}

static void MX_TIM3_Init(void)
{

  /* USER CODE BEGIN TIM3_Init 0 */

  /* USER CODE END TIM3_Init 0 */
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM3_Init 1 */

  /* USER CODE END TIM3_Init 1 */
  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 50;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 783;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_PWM_Init(&htim3) != HAL_OK)
  {
    while (1)
      ;
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    while (1)
      ;
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 100;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    while (1)
      ;
  }
  /* USER CODE BEGIN TIM3_Init 2 */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  /**TIM3 GPIO Configuration
  PC6     ------> TIM3_CH1
  */
  GPIO_InitStruct.Pin = GPIO_PIN_6;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF0_MCO;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
  /* USER CODE END TIM3_Init 2 */
}
static void MX_GPIO_Init(void)
{

  /* USER CODE BEGIN MX_GPIO_Init_1 */
  /* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_TIM3_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  /* USER CODE BEGIN MX_GPIO_Init_2 */
  /* USER CODE END MX_GPIO_Init_2 */
}

/*t_eReturnState FMKCPU_ReqstInterruptMngmt(TIM_HandleTypeDef *htim)
{
    for(int i = 0; i < TIM_NB; i++)
    {
        if (g_TimInfo_as[i].TIMx.Instance == htim->Instance)
        {
            // Récupérer le canal actif
            HAL_TIM_ActiveChannel activeChannel = HAL_TIM_GetActiveChannel(htim);

            // Appeler le callback en fonction du canal actif
            switch(activeChannel)
            {
                case HAL_TIM_ACTIVE_CHANNEL_1:
                    g_TimInfo_as[i].HwCallback_cb(FMKCPU_CHANNEL_1);  // Canal 1
                    break;
                case HAL_TIM_ACTIVE_CHANNEL_2:
                    g_TimInfo_as[i].HwCallback_cb(FMKCPU_CHANNEL_2);  // Canal 2
                    break;
                case HAL_TIM_ACTIVE_CHANNEL_3:
                    g_TimInfo_as[i].HwCallback_cb(FMKCPU_CHANNEL_3);  // Canal 3
                    break;
                case HAL_TIM_ACTIVE_CHANNEL_4:
                    g_TimInfo_as[i].HwCallback_cb(FMKCPU_CHANNEL_4);  // Canal 4
                    break;
                case HAL_TIM_ACTIVE_CHANNEL_CLEARED:
                    // Aucune interruption détectée, vous pouvez gérer cela si nécessaire
                    break;
                default:
                    // Gérer les autres cas si nécessaire
                    break;
            }
        }
    }
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){ return FMKCPU_ReqstInterruptMngmt(htim);}
void HAL_TIM_PeriodElapsedHalfCpltCallback(TIM_HandleTypeDef *htim){ return FMKCPU_ReqstInterruptMngmt(htim);}
void HAL_TIM_OC_DelayElapsedCallback(TIM_HandleTypeDef *htim){ return FMKCPU_ReqstInterruptMngmt(htim);}
void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim){ return FMKCPU_ReqstInterruptMngmt(htim);}
void HAL_TIM_PWM_PulseFinishedHalfCpltCallback(TIM_HandleTypeDef *htim){ return FMKCPU_ReqstInterruptMngmt(htim);}
void HAL_TIM_TriggerCallback(TIM_HandleTypeDef *htim){ return FMKCPU_ReqstInterruptMngmt(htim);}*/
//************************************************************************************
// End of File
//************************************************************************************

/**
 *
 *	@brief
 *	@details
 *
 *
 *	@params[in]
 *	@params[out]
 *
 *
 *
 */
