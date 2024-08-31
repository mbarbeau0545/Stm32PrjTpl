/*********************************************************************
 * @file        FMK_CPU.c
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
#include "./FMK_CPU.h"
#include "FMK_CFG/FMKCFG_ConfigFiles/FMKCPU_ConfigPrivate.h"

// ********************************************************************
// *                      Defines
// ********************************************************************

// ********************************************************************
// *                      Types
// ********************************************************************
// ********************************************************************
// *                      Types
// ********************************************************************
//-----------------------------ENUM TYPES-----------------------------//
/* CAUTION : Automatic generated code section for Enum: Start */

/* CAUTION : Automatic generated code section for Enum: End */
typedef enum {
    FMKCPU_ERRSTATE_NONE = 0,        // Pas d'erreur
    FMKCPU_ERRSTATE_INVALID_CHANNEL, // Canaux invalides
    FMKCPU_ERRSTATE_TIMEOUT,         // Délai d'attente expiré
    FMKCPU_ERRSTATE_OVERFLOW,        // Dépassement de capacité
    FMKCPU_ERRSTATE_UNDERFLOW,       // Sous-flux ou valeur invalide
    FMKCPU_ERRSTATE_NOT_CONFIGURED,  // Timer ou canal non configuré
    FMKCPU_ERRSTATE_BUSY,            // Le canal est occupé
    FMKCPU_ERRSTATE_INIT_FAILED,     // Échec de l'initialisation
    FMKCPU_ERRSTATE_PARAM,           // Paramètres invalides
    FMKCPU_ERRSTATE_UNKNOWN,         // Erreur inconnue ou non spécifiée

    FMKCPU_ERRSTATE_STATE_NB,        // Nombre total d'erreurs (peut être utilisé pour des vérifications de plage)
} t_eFMKCPU_ErrorState;
//-----------------------------TYPEDEF TYPES---------------------------//
//-----------------------------STRUCT TYPES---------------------------//
/* CAUTION : Automatic generated code section for Structure: Start */

/* CAUTION : Automatic generated code section for Structure: End */
/* Structure of information on a timer-channel */
typedef struct
{
    t_eFMKCPU_HwChannelCfg        HwCfg_e;
    t_eFMKCPU_ChnlState           State_e;
    t_eFMKCPU_ChnlPolarity        Polarity_e;
    t_eFMKCPU_ChnlRunMode         RunMode_e;
    t_eFMKCPU_ErrorState          ErrState_e;
    t_cbFMKCPU_InterruptChnl *    chnl_cb;
    t_bool                        IsChnlConfigure_b;
} t_sFMKCPU_CHnlInfo;

/* Structure of information on a timer */
typedef struct 
{   
    TIM_HandleTypeDef   BspTimer_ps;
    t_sFMKCPU_CHnlInfo  Channel_as[FMKCPU_CHANNEL_NB];
    t_eFMKCPU_IRQNType  IRQNType_e;
    t_bool              IsTimerRunning_b;
    t_bool              IsTimerConfigured_b;
    t_bool              IsNVICTimerEnable_b;

} t_sFMKCPU_TimerInfo;


// ********************************************************************
// *                      Prototypes
// ********************************************************************
	
// ********************************************************************
// *                      Variables
// ********************************************************************
t_sFMKCPU_TimerInfo g_TimerInfo[FMKCPU_TIMER_NB] = {
    {// Timer_1
        .BspTimer_ps.Instance = TIM1,
        .IRQNType_e = TIM1_CC_IRQn,
        .IsNVICTimerEnable_b = False,
        .IsTimerConfigured_b = False,
        .IsTimerRunning_b    = False
    },
    {// TImer 3
        .BspTimer_ps.Instance = TIM3,
        .IRQNType_e = TIM3_IRQn,
        .IsNVICTimerEnable_b = False,
        .IsTimerConfigured_b = False,
        .IsTimerRunning_b    = False
    },
    {// TImer 14
        .BspTimer_ps.Instance = TIM14,
        .IRQNType_e = TIM14_IRQn,
        .IsNVICTimerEnable_b = False,
        .IsTimerConfigured_b = False,
        .IsTimerRunning_b    = False
    },
    {// TImer 15
        .BspTimer_ps.Instance = TIM15,
        .IRQNType_e = TIM15_IRQn,
        .IsNVICTimerEnable_b = False,
        .IsTimerConfigured_b = False,
        .IsTimerRunning_b    = False
    },
    {// TImer 16
        .BspTimer_ps.Instance = TIM16,
        .IRQNType_e = TIM16_IRQn,
        .IsNVICTimerEnable_b = False,
        .IsTimerConfigured_b = False,
        .IsTimerRunning_b    = False
    },
    {// TImer 17
        .BspTimer_ps.Instance = TIM17,
        .IRQNType_e = TIM17_IRQn,
        .IsNVICTimerEnable_b = False,
        .IsTimerConfigured_b = False,
        .IsTimerRunning_b    = False
    },
    
};
//********************************************************************************
//                      Local functions - Prototypes
//********************************************************************************
/*****************************************************************************
*
*	@brief
*	@details
*
*
*	@param[in] 
*	@param[out]
*	 
*
*
*/
static t_eReturnState s_FMKCPU_FilledBspTimerInit(t_sFMKCPU_TimerInfo *f_timer_ps,
                                                t_uint32 f_prescaler_u32,
                                                t_uint32 f_period_u32,
                                                t_uint32 f_counterMode_32,
                                                t_uint32 f_clockDivision_u32,
                                                t_uint32 f_autoRePreload_u32);
/*****************************************************************************
*
*	@brief
*	@details
*
*
*	@param[in] 
*	@param[out]
*	 
*
*
*/
static t_eReturnState s_FMKCPU_Get_BspNVICPrioirity(t_eFMKCPU_NVICPriority f_priority_e, t_uint32 *BspNVICPriority_pu32);
/*****************************************************************************
*
*
*	@brief
*	@details
*
*
*	@param[in] 
*	@param[out]
*	 
*
*
*/
static t_eReturnState s_FMKCPU_Get_BspChannel(t_eFMKCPU_InterruptChnl f_channel_e, t_uint32 *f_bspChnl_pu32);
/*****************************************************************************
*
*
*
*	@brief
*	@details
*
*
*	@param[in] 
*	@param[out]
*	 
*
*
*/
static t_eReturnState s_FMKCPU_Set_HwChannelState(t_eFMKCPU_Timer f_timer_e, 
                                                  t_eFMKCPU_InterruptChnl f_channel_e,
                                                  t_eFMKCPU_ChnlState f_chnlState_e);

/*****************************************************************************
*
*
*
*	@brief
*	@details
*
*
*	@param[in] 
*	@param[out]
*	 
*
*
*/
static t_eReturnState s_FMKCPU_BspRqst_InterruptMngmt(TIM_HandleTypeDef * f_timerIstce_ps, t_eFMKCPU_HwChannelCfg f_HwChnlCfg_e);

                                         
//****************************************************************************
//                      Public functions - Implementation
//********************************************************************************
/*********************************
* FMKCPU_Set_NVICState
*********************************/
t_eReturnState FMKCPU_Set_NVICState(t_eFMKCPU_IRQNType f_IRQN_e, 
                                       t_eFMKCPU_NVICPriority f_priority_e, 
                                       t_eFMKCPU_NVIC_Ope f_OpeState_e)
{
    t_eReturnState  Ret_e = RC_OK;
    t_uint32 BspPriority_u32 = 0;
    if(f_IRQN_e > (t_eFMKCPU_IRQNType)IRQN_TYPE_NB
    || f_priority_e > FMKCPU_NVIC_PRIORITY_NB
    || f_OpeState_e > FMKCPU_NVIC_OPE_NB)
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
    }
    if(Ret_e == RC_OK)
    {
        switch(f_OpeState_e)
        {
            case FMKCPU_NVIC_OPE_ENABLE:
            {// Get the bspPriority using t_eFMKCPU_NVICPriority
                Ret_e = s_FMKCPU_Get_BspNVICPrioirity(f_priority_e, &BspPriority_u32);
                HAL_NVIC_SetPriority((IRQn_Type)f_IRQN_e, BspPriority_u32, 0);
                HAL_NVIC_EnableIRQ((IRQn_Type)f_IRQN_e);
                break;
            }

            case FMKCPU_NVIC_OPE_DISABLE:
            {
                HAL_NVIC_DisableIRQ((IRQn_Type)f_IRQN_e);
                break;
            }
            case FMKCPU_NVIC_OPE_NB:
            default:
                Ret_e = RC_ERROR_NOT_SUPPORTED;
                break;
        }
    }

    return Ret_e ;
}

/*********************************
* FMKCPU_Set_NVICState
*********************************/
t_eReturnState FMKCPU_Set_HwClock(t_eFMKCPU_ClockPort f_clkPort_e, 
                                       t_eFMKCPU_ClockPortOPe f_OpeState_e)
{
    t_eReturnState Ret_e = RC_OK;
    
    if(f_clkPort_e  > FMKCPU_RCC_CLK_NB
    || f_OpeState_e > FMKCPU_CLOCKPORT_OPE_NB)
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
    }
    if(Ret_e == RC_OK)
    {
        switch (f_OpeState_e)
        {
            case FMKCPU_NVIC_OPE_ENABLE:
            {
                if (c_FMKCPU_ClkFunctions_apcb[f_clkPort_e].EnableClk_cb != NULL_FONCTION)
                {
                    c_FMKCPU_ClkFunctions_apcb[f_clkPort_e].EnableClk_cb();
                }
                else 
                {
                    Ret_e = RC_WARNING_NO_OPERATION;
                }
                break;
            }
            case FMKCPU_NVIC_OPE_DISABLE:
            {
                if (c_FMKCPU_ClkFunctions_apcb[f_clkPort_e].DisableClk_cb != NULL_FONCTION)
                {
                    c_FMKCPU_ClkFunctions_apcb[f_clkPort_e].DisableClk_cb();
                }
                else 
                {
                    Ret_e = RC_WARNING_NO_OPERATION;
                }
                break;
            }
            case FMKCPU_CLOCKPORT_OPE_NB:
            default:
                Ret_e = RC_ERROR_PARAM_NOT_SUPPORTED;
                break;
        }
    }
    return Ret_e;
}

/*********************************
* FMKCPU_Set_PWMChannelCfg
*********************************/
t_eReturnState FMKCPU_Set_PWMChannelCfg(t_sFMKCPU_BspTimerCfg f_bspCfg_s)
{
    t_eReturnState Ret_e = RC_OK;
    HAL_StatusTypeDef BspRet_e = HAL_OK;
    TIM_OC_InitTypeDef BspOcInit_s;
    t_uint32 bspChannel_u32 = 0;
    t_uint32 bspPrescaler_u32 = 0;
    if(f_bspCfg_s.timer_e > FMKCPU_TIMER_NB
    || f_bspCfg_s.channel_e > FMKCPU_CHANNEL_NB)
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
    }
    if(g_TimerInfo[f_bspCfg_s.timer_e].Channel_as[f_bspCfg_s.channel_e].RunMode_e != FMKCPU_HWCHNL_CFG_PWM)
    {// this timer is already configured for another purpose 
        Ret_e = RC_ERROR_NOT_ALLOWED;
    }
    if(g_TimerInfo[f_bspCfg_s.timer_e].Channel_as[f_bspCfg_s.channel_e].IsChnlConfigure_b == (t_bool)True)
    {
        Ret_e = RC_WARNING_ALREADY_CONFIGURED;
    }
    if(Ret_e == RC_OK)
    {// if the timer_e is not initialized make it else pass directly to chanell cfg
        if(g_TimerInfo[f_bspCfg_s.timer_e].IsTimerConfigured_b == (t_bool)False)
        {
            bspPrescaler_u32 = (t_uint32)(HAL_RCC_GetPCLK1Freq() / f_bspCfg_s.timerFreq_u32);
            Ret_e = s_FMKCPU_FilledBspTimerInit(&g_TimerInfo[f_bspCfg_s.timer_e].BspTimer_ps,
                                                (t_uint32)bspPrescaler_u32,
                                                (t_uint32)f_bspCfg_s.timerPeriod_u32,
                                                (t_uint32)TIM_COUNTERMODE_UP,
                                                (t_uint32)TIM_CLOCKDIVISION_DIV1,
                                                (t_uint32)0 ); // Irreveleent in PWM
            if(Ret_e == RC_OK)
            {
                BspRet_e = HAL_TIM_PWM_Init(&g_TimerInfo[f_bspCfg_s.timer_e].BspTimer_ps);
                if(BspRet_e != HAL_OK)
                {
                    Ret_e = RC_ERROR_WRONG_STATE;
                }
            }
        }
        if(Ret_e == RC_OK)
        {// Now Configure the channel in OS
            Ret_e = s_FMKCPU_Get_BspChannel(f_bspCfg_s.channel_e, &bspChannel_u32);
            if(Ret_e == RC_OK)
            {
                BspOcInit_s.OCMode      = (t_uint32)TIM_OCMODE_PWM1; // Basic cfg impose Up when counter > counterCompare
                BspOcInit_s.Pulse       = (t_uint32)0;              // set init DutyCycle to 0
                BspOcInit_s.OCNPolarity = (t_uint32)TIM_OCPOLARITY_HIGH;
                BspOcInit_s.OCFastMode  = (t_uint32)TIM_OCFAST_DISABLE;
                BspRet_e = HAL_TIM_PWM_ConfigChannel(&g_TimerInfo[f_bspCfg_s.timer_e].BspTimer_ps,
                                                     &BspOcInit_s, 
                                                    (uint32_t)bspChannel_u32);
                if(BspRet_e != HAL_OK)
                {
                    Ret_e = RC_ERROR_WRONG_STATE;
                }
            }
            if(Ret_e == RC_OK)
            {// Update INformation 
                g_TimerInfo[f_bspCfg_s.timer_e].Channel_as[f_bspCfg_s.channel_e].HwCfg_e   = FMKCPU_HWCHNL_CFG_PWM;
                g_TimerInfo[f_bspCfg_s.timer_e].Channel_as[f_bspCfg_s.channel_e].IsChnlConfigure_b = (t_bool)True;
            }
        }
    }
    return Ret_e;
}

/*********************************
* FMKCPU_Set_ICChannelCfg
*********************************/
t_eReturnState FMKCPU_Set_ICChannelCfg(t_sFMKCPU_BspTimerCfg f_bspCfg_s, t_eFMKCPU_ChnlMeasTrigger f_MeasTrigger_e)
{
    t_eReturnState Ret_e = RC_OK;
    HAL_StatusTypeDef BspRet_e = HAL_OK;
    TIM_IC_InitTypeDef BspICInit_s;
    t_uint32 bspChannel_u32 = 0;
    if(f_bspCfg_s.timer_e > FMKCPU_TIMER_NB
    || f_bspCfg_s.channel_e > FMKCPU_CHANNEL_NB)
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
    }
    if(g_TimerInfo[f_bspCfg_s.timer_e].Channel_as[f_bspCfg_s.channel_e].RunMode_e != FMKCPU_HWCHNL_CFG_IC)
    {// this timer and channel is already configured for another purpose 
        Ret_e = RC_ERROR_NOT_ALLOWED;
    }
    if(g_TimerInfo[f_bspCfg_s.timer_e].Channel_as[f_bspCfg_s.channel_e].IsChnlConfigure_b == (t_bool)True)
    {
        Ret_e = RC_WARNING_ALREADY_CONFIGURED;
    }
    {// this timer and channel is already configured for another purpose 
        Ret_e = RC_ERROR_NOT_ALLOWED;
    }
    if(Ret_e == RC_OK)
    {
        if(g_TimerInfo[f_bspCfg_s.timer_e].IsTimerConfigured_b == (t_bool)False)
        {
            Ret_e = s_FMKCPU_FilledBspTimerInit(&g_TimerInfo[f_bspCfg_s.timer_e].BspTimer_ps,
                                                (t_uint32)0,
                                                (t_uint32)f_bspCfg_s.timerPeriod_u32,
                                                (t_uint32)TIM_COUNTERMODE_UP,
                                                (t_uint32)TIM_CLOCKDIVISION_DIV1,
                                                (t_uint32)0); // Irreveleent in PWM
            if(Ret_e == RC_OK)
            {
                BspRet_e = HAL_TIM_IC_Init(&g_TimerInfo[f_bspCfg_s.timer_e].BspTimer_ps);
                if(BspRet_e != HAL_OK)
                {
                    Ret_e = RC_ERROR_WRONG_STATE;
                }
            }
        }
        if(Ret_e == RC_OK)
        {
            Ret_e = s_FMKCPU_Get_BspChannel(f_bspCfg_s.channel_e, &bspChannel_u32);
            if(Ret_e == RC_OK)
            {
                BspICInit_s.ICPolarity  = (t_uint32)TIM_ICPOLARITY_RISING;
                BspICInit_s.ICSelection = (t_uint32)TIM_ICSELECTION_DIRECTTI;
                BspICInit_s.ICPrescaler = (t_uint32)TIM_ICPSC_DIV1;
                BspICInit_s.ICFilter    = (t_uint32)0;
                BspRet_e = HAL_TIM_IC_ConfigChannel(&g_TimerInfo[f_bspCfg_s.timer_e].BspTimer_ps,
                                                    &BspICInit_s,
                                                    bspChannel_u32);
                if(BspRet_e != HAL_OK)
                {
                    Ret_e = RC_ERROR_WRONG_STATE;
                }
            }
            if(Ret_e == RC_OK)
            {// update information
                g_TimerInfo[f_bspCfg_s.timer_e].Channel_as[f_bspCfg_s.channel_e].HwCfg_e   = FMKCPU_HWCHNL_CFG_IC;
                g_TimerInfo[f_bspCfg_s.timer_e].Channel_as[f_bspCfg_s.channel_e].IsChnlConfigure_b = (t_bool)True;
            }
        }
    }
    return Ret_e;
}

/*********************************
* FMKCPU_Set_EvntChannelCfg
*********************************/
t_eReturnState FMKCPU_Set_EvntChannelCfg(t_eFMKCPU_EventChannel f_evntChannel_e, 
                                             t_uint32 f_periodms_u32,
                                             t_cbFMKCPU_InterruptChnl f_ITChannel_cb)
{
    t_eReturnState Ret_e = RC_OK;
    HAL_StatusTypeDef BspRet_e = HAL_OK;
    t_eFMKCPU_Timer EvntTimer_e;
    t_eFMKCPU_InterruptChnl EvntChnl_e;
    t_uint32 bspPrescaler_u32 = 0;
    if(f_evntChannel_e > FMKCPU_EVENT_CHANNEL_NB)
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
    }
    if(f_ITChannel_cb == (t_cbFMKCPU_InterruptChnl *)NULL_FONCTION)
    {
        Ret_e = RC_ERROR_PTR_NULL;
    }
    if(Ret_e == RC_OK)
    {
        EvntTimer_e = c_EvntTimerCfg_as[f_evntChannel_e].timer_e;
        if(g_TimerInfo[EvntTimer_e].IsTimerConfigured_b == (t_bool)False)
        {
            bspPrescaler_u32 = (t_uint32)(HAL_RCC_GetPCLK1Freq()); // CHANGE TO ADAPT
            Ret_e = s_FMKCPU_FilledBspTimerInit(&g_TimerInfo[EvntTimer_e].BspTimer_ps,
                                                (t_uint32)bspPrescaler_u32,
                                                (t_uint32)f_periodms_u32,
                                                (t_uint32)TIM_COUNTERMODE_UP,
                                                (t_uint32)TIM_CLOCKDIVISION_DIV1,
                                                (t_uint32)TIM_AUTORELOAD_PRELOAD_DISABLE);
            if(Ret_e == RC_OK)
            {
                BspRet_e = HAL_TIM_Base_Init(&g_TimerInfo[EvntTimer_e].BspTimer_ps);
                if(BspRet_e != HAL_OK)
                {
                    Ret_e = RC_ERROR_WRONG_STATE;
                }
            }
        }
    }
    return Ret_e;
}
/*********************************
* FMKCPU_AddTimerChnlCallback
*********************************/
t_eReturnState FMKCPU_AddTimerChnlCallback(t_eFMKCPU_Timer f_timer_e, 
                                             t_eFMKCPU_InterruptChnl f_channel_e,
                                             t_cbFMKCPU_InterruptChnl *f_ITChannel_cb)
{
    t_eReturnState Ret_e = RC_OK;

    if(f_timer_e > FMKCPU_TIMER_NB
    || f_channel_e > FMKCPU_CHANNEL_NB)
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
    }
    if(f_ITChannel_cb == (t_cbFMKCPU_InterruptChnl *)NULL_FONCTION)
    {
        Ret_e = RC_ERROR_PTR_NULL;
    }
    if(g_TimerInfo[f_timer_e].Channel_as[f_channel_e].IsChnlConfigure_b != (t_bool)True 
    || g_TimerInfo[f_timer_e].IsTimerConfigured_b != (t_bool)True)
    {
        Ret_e = RC_ERROR_WRONG_STATE;
    }
    if(Ret_e == RC_OK)
    {
        // Update channel Run mode and Add Callback
        g_TimerInfo[f_timer_e].Channel_as[f_channel_e].RunMode_e = FMKCPU_CNHL_RUNMODE_INTERRUPT;
        g_TimerInfo[f_timer_e].Channel_as[f_channel_e].chnl_cb = f_ITChannel_cb;
    }
    return Ret_e;
}

/*********************************
* FMKCPU_Set_ChannelState
*********************************/
t_eReturnState FMKCPU_Set_ChannelState(t_eFMKCPU_Timer f_timer_e, 
                                           t_eFMKCPU_InterruptChnl f_channel_e,
                                           t_eFMKCPU_ChnlState f_channelState_e)
{
    t_eReturnState Ret_e = RC_OK;

    if(f_timer_e > FMKCPU_TIMER_NB
    || f_channel_e > FMKCPU_CHANNEL_NB
    || f_channelState_e > FMKCPU_CHNLST_NB)
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
    }
    if(Ret_e == RC_OK)
    {
        Ret_e = s_FMKCPU_Set_HwChannelState(f_timer_e, f_channel_e, f_channelState_e);
    }
    return Ret_e;
}
//********************************************************************************
//                      Local functions - Implementation
//********************************************************************************
/*********************************
* s_FMKCPU_Get_BspTimer
*********************************/
static t_eReturnState s_FMKCPU_Get_BspNVICPrioirity(t_eFMKCPU_NVICPriority f_priority_e, t_uint32 *f_BspNVICPriority_pu32)
{
    t_eReturnState Ret_e = RC_OK;

    if(f_BspNVICPriority_pu32 == (t_uint32 *)NULL)
    {
        Ret_e = RC_ERROR_PTR_NULL;
    }
    if(f_priority_e > FMKCPU_NVIC_PRIORITY_NB)
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
    }
    if(Ret_e == RC_OK)
    {
        switch (f_priority_e)
        {
            case FMKCPU_NVIC_PRIORITY_LOW:
                *f_BspNVICPriority_pu32 = 1;
                break;
            case FMKCPU_NVIC_PRIORITY_MEDIUM:
                *f_BspNVICPriority_pu32 = 3;
                break;
            case FMKCPU_NVIC_PRIORITY_HIGH:
                *f_BspNVICPriority_pu32 = 5;
                break;
         
            case FMKCPU_NVIC_PRIORITY_NB:
            default:
                Ret_e = RC_ERROR_PARAM_NOT_SUPPORTED;
                break;
        }
    }
    return Ret_e;
}

/*********************************
* s_FMKCPU_Get_BspChannel
*********************************/
static t_eReturnState s_FMKCPU_Get_BspChannel(t_eFMKCPU_InterruptChnl f_channel_e, t_uint32 *f_bspChnl_pu32)
{
    t_eReturnState Ret_e = RC_OK;

    if(f_bspChnl_pu32 == (t_uint32 *)NULL)
    {
        Ret_e = RC_ERROR_PTR_NULL;
    }
    if(f_channel_e > FMKCPU_CHANNEL_NB)
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
    }
    if(Ret_e == RC_OK)
    {
        switch(f_channel_e)
        {
            case FMKCPU_CHANNEL_1:
                *f_bspChnl_pu32 = (t_uint32)TIM_CHANNEL_1;
                break;
            case FMKCPU_CHANNEL_2:
                *f_bspChnl_pu32 = (t_uint32)TIM_CHANNEL_2;
                break;
            case FMKCPU_CHANNEL_3:
                *f_bspChnl_pu32 = (t_uint32)TIM_CHANNEL_3;
                break;
            case FMKCPU_CHANNEL_4:
                *f_bspChnl_pu32 = (t_uint32)TIM_CHANNEL_4;
                break;
            case FMKCPU_CHANNEL_NB:
            default:
                Ret_e = RC_ERROR_PARAM_NOT_SUPPORTED;
                break;
        }
    }
    return Ret_e;
}
/*********************************
* s_FMKCPU_Set_HwChannelState
*********************************/
static t_eReturnState s_FMKCPU_Set_HwChannelState(t_eFMKCPU_Timer f_timer_e, 
                                                  t_eFMKCPU_InterruptChnl f_channel_e,
                                                  t_eFMKCPU_ChnlState f_chnlStateOpe_e)
{
    t_eReturnState Ret_e = RC_OK;
    t_uint32 bspChannel_u32 = 0;
    t_eFMKCPU_NVIC_Ope NVIC_ope_e = FMKCPU_NVIC_OPE_NB;
    t_sFMKCPU_CHnlInfo *channelInfo;

    // Argument already verify
    channelInfo = &g_TimerInfo[f_timer_e].Channel_as[f_channel_e];
    Ret_e = s_FMKCPU_Get_BspChannel(f_channel_e, &bspChannel_u32);
    if(Ret_e == RC_OK)
    {// Depending on wehter we need to activate or deactivate function 
        switch (f_chnlStateOpe_e)
        {
            case FMKCPU_CHNLST_ACTIVATED:
            {// We have to start HALfunction in Basic or Interrupt depending on f_chnlRunMode_e
                // call the right HAL function Polling or Interrupt mode
                switch (channelInfo->RunMode_e)
                {
                    case FMKCPU_CNHL_RUNMODE_POLLING:
                        c_FMKCPU_BspTimChannelFunc_as[channelInfo->HwCfg_e].StartFuncPoll_cb(&g_TimerInfo[f_timer_e].BspTimer_ps,
                                                                                            (t_uint32)bspChannel_u32);
                        break;
                    case FMKCPU_CNHL_RUNMODE_INTERRUPT:
                        c_FMKCPU_BspTimChannelFunc_as[channelInfo->HwCfg_e].StartFuncInterrupt_cb(&g_TimerInfo[f_timer_e].BspTimer_ps,
                                                                                                (t_uint32)bspChannel_u32);
                        break;
                    case FMKCPU_CNHL_RUNMODE_NB:
                    default:
                        Ret_e = RC_ERROR_NOT_SUPPORTED;
                        break;
                }
                if(g_TimerInfo[f_timer_e].IsNVICTimerEnable_b == (t_bool)False)
                {
                    NVIC_ope_e = FMKCPU_NVIC_OPE_ENABLE;
                }
                break;
            }
            
            case FMKCPU_CHNLST_DISACTIVATED:
            {
                switch (channelInfo->RunMode_e)
                {
                    case FMKCPU_CNHL_RUNMODE_POLLING:
                        c_FMKCPU_BspTimChannelFunc_as[channelInfo->HwCfg_e].StopFuncPoll_cb(&g_TimerInfo[f_timer_e].BspTimer_ps,
                                                                                    (t_uint32)bspChannel_u32);
                        break;
                    case FMKCPU_CNHL_RUNMODE_INTERRUPT:
                        c_FMKCPU_BspTimChannelFunc_as[channelInfo->HwCfg_e].StopFuncInterrupt_cb(&g_TimerInfo[f_timer_e].BspTimer_ps,
                                                                                    (t_uint32)bspChannel_u32);
                        break;
                    case FMKCPU_CNHL_RUNMODE_NB:
                    default:
                        Ret_e = RC_ERROR_NOT_SUPPORTED;
                        break;
                }
                if(g_TimerInfo[f_timer_e].IsNVICTimerEnable_b == (t_bool)True)
                {
                    NVIC_ope_e = FMKCPU_NVIC_OPE_DISABLE;
                }
                break;
            }
            case FMKCPU_CHNLST_NB:
            default:
                Ret_e = RC_ERROR_NOT_SUPPORTED;
                        break;
        }
        if(NVIC_ope_e != FMKCPU_NVIC_OPE_NB)
        {
            Ret_e = FMKCPU_Set_NVICState(g_TimerInfo[f_timer_e].IRQNType_e,
                                        c_FMKCPU_IRQNPriority_ae[g_TimerInfo[f_timer_e].IRQNType_e],
                                        NVIC_ope_e);
        }
        if(Ret_e == RC_OK)
        {
            channelInfo->State_e = f_chnlStateOpe_e;
        }
    }
    return Ret_e;
}

/*********************************
* s_FMKCPU_FilledBspTimerInit
*********************************/
static t_eReturnState s_FMKCPU_FilledBspTimerInit(t_sFMKCPU_TimerInfo *f_timer_ps,
                                                t_uint32 f_prescaler_u32,
                                                t_uint32 f_period_u32,
                                                t_uint32 f_counterMode_32,
                                                t_uint32 f_clockDivision_u32,
                                                t_uint32 f_autoRePreload_u32)
{
    t_eReturnState Ret_e = RC_OK;

    if(f_timer_ps > (t_sFMKCPU_TimerInfo *)NULL)
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
    }
    if(Ret_e == RC_OK)
    {
        f_timer_ps->BspTimer_ps.Init.Prescaler         = f_prescaler_u32;
        f_timer_ps->BspTimer_ps.Init.Period            = f_period_u32;
        f_timer_ps->BspTimer_ps.Init.CounterMode       = f_counterMode_32;
        f_timer_ps->BspTimer_ps.Init.ClockDivision     = f_clockDivision_u32;
        f_timer_ps->BspTimer_ps.Init.AutoReloadPreload = f_autoRePreload_u32;
        // Update Flag Configured
        f_timer_ps->IsTimerConfigured_b = (t_bool)True;
    }

    return Ret_e;
}
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
