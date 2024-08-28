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
t_uint32 a = ADC1;

// ********************************************************************
// *                      Defines
// ********************************************************************
#define NB_DIG_PIN 8
enum 
{
    FLKIO_ANA_PIN_1 = 0,
    FLKIO_ANA_PIN_2,
    FLKIO_ANA_PIN_3,
    FLKIO_ANA_PIN_4,
    FLKIO_ANA_PIN_NB,


};
typedef enum 
{
    ACQUISITION_MODE_SINGLE = 0,
    ACQUISITION_MODE_CONTINUOUS,
    ACQUISITION_MODE_SCAN,
    ACQUISITION_MODE_TRIGGERED,
}t_eAcquisitionMode;
typedef enum 
{
    RESULT_REGISTER = 0,
    RESULT_INTERRUPT,
    RESULT_DMA,
}t_eResultMode;
typedef struct 
{
    t_uint32* BspGPIOPort_32;
    t_uint32* BspPin_u32;
    t_bool    IsSigCOnfigured_b;
}t_eFMKIO_SigInfo;


typedef struct 
{
    t_eChannelMode Mode_e;
    t_eIsChannelRunning channelState_e;
    t_ePolarity polarity_e;
    t_bool isInterruptEnabled_b;   // Indicateur d'activation de l'interruption
    void (*channelCallback_fn)(void);  // Pointeur vers une fonction de callback spécifique
    t_eErrorState errorState_e;    // État d'erreur pour ce canal

}t_sMain_ChannelInfo;

typedef void (t_cbFMKCDA_Channel)(void);
t_uint32 c_SigChannelMapping[NB_FREQ_] = {
    ADC_CHANNEL_0, // Pin_1
    ADC_CHANNEL_1, // Pin_2
    ADC_CHANNEL_4, // Pin_3
    ADC_CHANNEL_12, // Pin_4
};

int main()
{   
    HAL_NVIC_EnableIRQ()
    __HAL_RCC_GPIOA_CLK_ENABLE();
    g_TimInfo_s[0].timCfg_s.Instance = TIM1
    return 0;
}
typedef enum
{
    FMKCPU_CHANNEL_1 = 0,
    FMKCPU_CHANNEL_2,
    FMKCPU_CHANNEL_3,
    FMKCPU_CHANNEL_4,
}t_eChannel;
enum{
    TIM_1 = 0,
    TIM_2,
    TIM_NB
};
#define MAX_CHANNEL 9

typedef t_eReturnState (t_cbHardwareInterrupt)(t_eChannel f_channel);
typedef struct 
{
    TIM_HandleTypeDef TIMx;
    t_cbHardwareInterrupt *HwCallback_cb;
    t_bool IsTimerRunning_b;
    t_bool IsTimerConfigured_b;
    t_bool IsTimerClockEnable_b;
    t_sFMKCPU_ChannelInfo[MAX_CHANNEL]

}t_sFMKCPU_TimInfo;

t_sFMKCPU_TimInfo g_TimInfo_as[TIM_NB];

t_eReturnState FMKCPU_ReqstInterruptMngmt(TIM_HandleTypeDef *htim)
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
void HAL_TIM_TriggerCallback(TIM_HandleTypeDef *htim){ return FMKCPU_ReqstInterruptMngmt(htim);}

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



