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

int main()
{   
    t_eReturnState Ret_e = RC_OK;
    t_uint8 LLI_u8;
    t_eFMKIO_DigValue vl;
    t_uint16 value_u16;
    for (LLI_u8 = 0 ; LLI_u8 < FMKIO_INPUT_SIGANA_NB ; LLI_u8++)
    {
        Ret_e = FMKIO_Set_InAnaSigCfg((t_eFMKIO_InAnaSig)LLI_u8,
                                FMKIO_PULL_MODE_UNABLE);
        Ret_e = FMKIO_Set_InAnaSigCfg((t_eFMKIO_InDigSig)LLI_u8,
                                FMKIO_PULL_MODE_UNABLE);
        
        Ret_e = FMKIO_Set_OutPwmSigCfg((t_eFMKIO_OutPwmSig)LLI_u8,
                                FMKIO_PULL_MODE_UNABLE, 35,45,False);
    }
    while(1)
    {
        for (LLI_u8 = 0 ; LLI_u8 < FMKIO_INPUT_SIGANA_NB ; LLI_u8++)
        {
            Ret_e = FMKIO_Get_InAnaSigValue((t_eFMKIO_InAnaSig)LLI_u8, &value_u16);
            Ret_e = FMKIO_Get_OutDigSigValue((t_eFMKIO_OutDigSig)LLI_u8, &vl);
            Ret_e = FMKIO_Get_InDigSigValue((t_eFMKIO_InDigSig)LLI_u8, &vl);
            Ret_e = FMKIO_Get_OutPwmSigValue((t_eFMKIO_OutPwmSig)LLI_u8, &value_u16);
        }
    }
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



