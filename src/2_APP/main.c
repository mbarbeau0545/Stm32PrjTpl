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


int main(void)
{
    // Initialiser le système
    HAL_Init();
    SystemClock_Config();

    FMKIO_Set_OutDigSigCfg(FMKIO_OUTPUT_SIGDIG_13, FMKIO_PULL_MODE_UNABLE, FMKIO_SPD_MODE_LOW);
    //MX_GPIO_Init();
    // Boucle principale
    while (1)
    {
    // Allumer la LED
    FMKIO_Set_OutDigSigValue(FMKIO_OUTPUT_SIGDIG_13, FMKIO_DIG_VALUE_HIGH);
    //HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);

    // Attendre un moment
    HAL_Delay(1000); // Délai de 1 seconde

    // Éteindre la LED
    //HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET);
    FMKIO_Set_OutDigSigValue(FMKIO_OUTPUT_SIGDIG_13, FMKIO_DIG_VALUE_LOW);

    // Attendre un moment
    HAL_Delay(1000); // Délai de 1 seconde
    }
}

void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  // 1. Configurer l'oscillateur HSI
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL12; // Multiplie le HSI (8 MHz) par 12 pour obtenir 48 MHz
  RCC_OscInitStruct.PLL.PREDIV = RCC_PREDIV_DIV1; // Pas de prédivision
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    // Gestion d'erreur
    while(1);
  }

  // 2. Configurer les horloges AHB et APB
  RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1);
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI; // Utiliser PLL comme horloge système
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1; // Pas de division pour AHB
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1; // Pas de division pour APB1
  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    // Gestion d'erreur
    while(1);
  }

}

static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  // Activer le port GPIOC
  __HAL_RCC_GPIOC_CLK_ENABLE();

  // Configurer la broche GPIOC Pin 13 en mode sortie push-pull
  GPIO_InitStruct.Pin = GPIO_PIN_13;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
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



