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
#include "stm32f0xx_hal.h"
#include "stm32f0xx_hal_def.h"
#include "stm32f0xx_hal_gpio.h"
#include "stm32f0xx_hal_tim.h"
#include "stm32f030x8.h"
#include "TypeCommon.h"
#include "stm32f0xx_hal_rcc.h"
#include "stm32f0xx_hal_adc.h"
#include "FMK_HAL/FMK_CPU/Src/FMK_CPU.h"

// ********************************************************************
// *                      Defines
// ********************************************************************
/*void EXTI0_IRQHandler(void)
{
    HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_0);  // Gérer l'interruption pour le pin 0
}*/

int main()
{   
    
    return 0;
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



