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
#include "Constant.h"
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
typedef enum
{
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

    FMKCPU_ERRSTATE_STATE_NB, // Nombre total d'erreurs (peut être utilisé pour des vérifications de plage)
} t_eFMKCPU_ErrorState;
//-----------------------------TYPEDEF TYPES---------------------------//
//-----------------------------STRUCT TYPES---------------------------//
/* CAUTION : Automatic generated code section for Structure: Start */

/* CAUTION : Automatic generated code section for Structure: End */

/**< Structure of information on a timer-channel*/
typedef struct
{
    t_eFMKCPU_HwChannelCfg HwCfg_e;
    t_eFMKCPU_ChnlState State_e;
    t_eFMKCPU_ChnlPolarity Polarity_e;
    t_eFMKCPU_ChnlRunMode RunMode_e;
    t_eFMKCPU_ErrorState ErrState_e;
    t_cbFMKCPU_InterruptChnl *chnl_cb;
    t_bool IsChnlConfigure_b;
} t_sFMKCPU_CHnlInfo;

/**< Structure of information on a timer*/
typedef struct
{
    TIM_HandleTypeDef BspTimer_ps; /* The Timer structure for HAL STM32*/
    t_sFMKCPU_CHnlInfo Channel_as[FMKCPU_CHANNEL_NB];
    const t_eFMKCPU_IRQNType IRQNType_e;
    const t_eFMKCPU_ClockPort clock_e;
    t_bool IsTimerRunning_b;
    t_bool IsTimerConfigured_b;
    t_bool IsNVICTimerEnable_b;

} t_sFMKCPU_TimerInfo;

// ********************************************************************
// *                      Prototypes
// ********************************************************************

// ********************************************************************
// *                      Variables
// ********************************************************************
static t_eCyclicFuncState g_state_e = STATE_CYCLIC_PREOPE;

WWDG_HandleTypeDef g_wwdgInfos_s = {0};
// Flag automatic generate code
t_sFMKCPU_TimerInfo g_TimerInfo_as[FMKCPU_TIMER_NB] = {
    {
        // Timer_1
        .BspTimer_ps.Instance = TIM1,
        .clock_e = FMKCPU_RCC_CLK_TIM1,
        .IRQNType_e = TIM1_CC_IRQn,
    },
    {
        // TImer 3
        .BspTimer_ps.Instance = TIM3,
        .clock_e = FMKCPU_RCC_CLK_TIM3,
        .IRQNType_e = TIM3_IRQn,
    },
    {
        // TImer 14
        .BspTimer_ps.Instance = TIM14,
        .clock_e = FMKCPU_RCC_CLK_TIM14,
        .IRQNType_e = TIM14_IRQn,
    },
    {
        // TImer 15
        .BspTimer_ps.Instance = TIM15,
        .clock_e = FMKCPU_RCC_CLK_TIM15,
        .IRQNType_e = TIM15_IRQn,
    },
    {
        // TImer 16
        .BspTimer_ps.Instance = TIM16,
        .clock_e = FMKCPU_RCC_CLK_TIM16,
        .IRQNType_e = TIM16_IRQn,
    },
    {
        // TImer 17
        .BspTimer_ps.Instance = TIM17,
        .clock_e = FMKCPU_RCC_CLK_TIM17,
        .IRQNType_e = TIM17_IRQn,
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
static t_eReturnState s_FMKCPU_Set_BspTimerInit(t_sFMKCPU_TimerInfo * f_timer_ps,
                                                t_eFMKCPU_HwChannelCfg f_hwChnlCfg_e,
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
static t_eReturnState s_FMKCPU_Get_BspNVICPriority(t_eFMKCPU_NVICPriority f_priority_e, t_uint32 *BspNVICPriority_pu32);
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
static void s_FMKCPU_BspRqst_InterruptMngmt(TIM_HandleTypeDef *f_timerIstce_ps, t_eFMKCPU_HwChannelCfg f_HwChnlCfg_e);
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
t_eReturnState FMKCPU_Set_SysClockCfg(void);
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
static t_eReturnState s_FMKCPU_Operational(void);

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
static t_eReturnState s_FMKCPU_PreOperational(void);

//****************************************************************************
//                      Public functions - Implementation
//********************************************************************************
t_eReturnState FMKCPU_Init(void)
{
    t_uint8 LLI_u8;
    t_uint8 LLI2_u8;
    for (LLI_u8 = (t_uint8)0 ; LLI_u8 < (t_eFMKCPU_Timer)FMKCPU_TIMER_NB ; LLI_u8++)
    {
        g_TimerInfo_as[LLI_u8].IsNVICTimerEnable_b = (t_bool)False;
        g_TimerInfo_as[LLI_u8].IsTimerConfigured_b = (t_bool)False;
        g_TimerInfo_as[LLI_u8].IsTimerRunning_b    = (t_bool)False;
        for (LLI2_u8 = (t_uint8)0 ; LLI2_u8 < (t_eFMKCPU_InterruptChnl)FMKCPU_CHANNEL_NB ; LLI2_u8++)
        {
            g_TimerInfo_as[LLI_u8].Channel_as[LLI2_u8].chnl_cb = NULL_FONCTION;
            g_TimerInfo_as[LLI_u8].Channel_as[LLI2_u8].ErrState_e = FMKCPU_ERRSTATE_NONE;
            g_TimerInfo_as[LLI_u8].Channel_as[LLI2_u8].HwCfg_e = FMKCPU_HWCHNL_CFG_EVNT;
            g_TimerInfo_as[LLI_u8].Channel_as[LLI2_u8].IsChnlConfigure_b =  (t_bool)False;
            g_TimerInfo_as[LLI_u8].Channel_as[LLI2_u8].Polarity_e = FMKCPU_CHNLPOLARITY_LOW;
            g_TimerInfo_as[LLI_u8].Channel_as[LLI2_u8].RunMode_e = FMKCPU_CNHL_RUNMODE_POLLING;
            g_TimerInfo_as[LLI_u8].Channel_as[LLI2_u8].State_e = FMKCPU_CHNLST_DISACTIVATED;
        }
    }
    return RC_OK;
}
/*********************************
 * FMKCPU_Set_Delay
 *********************************/
t_eReturnState FMKCPU_Cyclic(void)
{
    t_eReturnState Ret_e = RC_OK;

    switch (g_state_e)
    {
    case STATE_CYCLIC_PREOPE:
    {

        Ret_e = s_FMKCPU_PreOperational();
        if(Ret_e == RC_OK)
        {
            g_state_e = STATE_CYCLIC_WAITING;
        }
        break;
    }
    case STATE_CYCLIC_WAITING:
    {
        // nothing to do, just wait all module are Ope
        break;
    }
    case STATE_CYCLIC_OPE:
    {
        Ret_e = s_FMKCPU_Operational();
        break;
    }
    case STATE_CYCLIC_ERROR:
    {
        break;
    }
    case STATE_CYCLIC_BUSY:
    default:
        Ret_e = RC_OK;
        break;
    }
    return Ret_e;
}

/*********************************
 * FMKCPU_GetState
 *********************************/
t_eReturnState FMKCPU_GetState(t_eCyclicFuncState *f_State_pe)
{
    t_eReturnState Ret_e = RC_OK;

    if(f_State_pe == (t_eCyclicFuncState *)NULL)
    {
        Ret_e = RC_ERROR_PTR_NULL;
    }
    if(Ret_e == RC_OK)
    {
        *f_State_pe = g_state_e;
    }

    return Ret_e;
}

/*********************************
 * FMKCPU_SetState
 *********************************/
t_eReturnState FMKCPU_SetState(t_eCyclicFuncState f_State_e)
{

    g_state_e = f_State_e;

    return RC_OK;
}

/*********************************
 * FMKCPU_Set_Delay
 *********************************/
void FMKCPU_Set_Delay(t_uint32 f_delayms_u32)
{
    return HAL_Delay(f_delayms_u32);
}

/*********************************
 * FMKCPU_Get_Tick
 *********************************/
t_eReturnState FMKCPU_Get_Tick(t_uint32 * f_tickms_pu32)
{
    t_eReturnState Ret_e = RC_OK;

    if( f_tickms_pu32 == (t_uint32 *)NULL)
    {
        Ret_e = RC_ERROR_PTR_NULL;
    }
    if(Ret_e == RC_OK)
    {
        *f_tickms_pu32 = HAL_GetTick();
    }
    return Ret_e;
}
/*********************************
 * FMKCPU_Set_NVICState
 *********************************/
t_eReturnState FMKCPU_Set_NVICState(t_eFMKCPU_IRQNType f_IRQN_e,
                                    t_eFMKCPU_NVICPriority f_priority_e,
                                    t_eFMKCPU_NVIC_Ope f_OpeState_e)
{
    t_eReturnState Ret_e = RC_OK;
    t_uint32 BspPriority_u32 = 0;
    if (f_IRQN_e > (t_eFMKCPU_IRQNType)FMKCPU_IRQN_TYPE_NB || f_priority_e > FMKCPU_NVIC_PRIORITY_NB || f_OpeState_e > FMKCPU_NVIC_OPE_NB)
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
    }
    if (Ret_e == RC_OK)
    {
        switch (f_OpeState_e)
        {
        case FMKCPU_NVIC_OPE_ENABLE:
        { // Get the bspPriority using t_eFMKCPU_NVICPriority
            Ret_e = s_FMKCPU_Get_BspNVICPriority(f_priority_e, &BspPriority_u32);
            if (Ret_e == RC_OK)
            {
                HAL_NVIC_SetPriority((IRQn_Type)f_IRQN_e, BspPriority_u32, 0);
                HAL_NVIC_EnableIRQ((IRQn_Type)f_IRQN_e);
            }
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

    return Ret_e;
}

/*********************************
 * FMKCPU_Set_HwClock
 *********************************/
t_eReturnState FMKCPU_Set_HwClock(t_eFMKCPU_ClockPort f_clkPort_e,
                                  t_eFMKCPU_ClockPortOpe f_OpeState_e)
{
    t_eReturnState Ret_e = RC_OK;

    if (f_clkPort_e > FMKCPU_RCC_CLK_NB || f_OpeState_e > FMKCPU_CLOCKPORT_OPE_NB)
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
    }
    if (Ret_e == RC_OK)
    {
        switch (f_OpeState_e)
        {
        case FMKCPU_CLOCKPORT_OPE_ENABLE:
        {
            if (c_FMKCPU_ClkFunctions_apcb[f_clkPort_e].EnableClk_pcb != (t_cbFMKCPU_ClockDisable *)NULL_FONCTION)
            {
                c_FMKCPU_ClkFunctions_apcb[f_clkPort_e].EnableClk_pcb();
            }
            else
            {
                Ret_e = RC_WARNING_NO_OPERATION;
            }
            break;
        }
        case FMKCPU_CLOCKPORT_OPE_DISABLE:
        {
            if (c_FMKCPU_ClkFunctions_apcb[f_clkPort_e].DisableClk_pcb != (t_cbFMKCPU_ClockDisable *)NULL_FONCTION)
            {
                c_FMKCPU_ClkFunctions_apcb[f_clkPort_e].DisableClk_pcb();
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
 * FMKCPU_Set_WwdgCfg
 *********************************/
t_eReturnState FMKCPU_Set_WwdgCfg(t_eFMKCPu_WwdgResetPeriod f_period_e)
{
    t_eReturnState Ret_e = RC_OK;
    HAL_StatusTypeDef bspRet_e = HAL_OK;

    Ret_e = FMKCPU_Set_HwClock(FMKCPU_RCC_CLK_WWDG, FMKCPU_CLOCKPORT_OPE_ENABLE);
    if(Ret_e == RC_OK)
    {
        Ret_e = FMKCPU_Set_NVICState(WWDG_IRQn,FMKCPU_NVIC_PRIORITY_HIGH ,FMKCPU_NVIC_OPE_ENABLE);
    }
    if(Ret_e == RC_OK)
    {
        g_wwdgInfos_s.Instance       = WWDG;
        g_wwdgInfos_s.Init.Prescaler = c_FMKCPU_WwdgPeriodcfg_ua16[f_period_e].psc_u16;
        g_wwdgInfos_s.Init.Counter   = c_FMKCPU_WwdgPeriodcfg_ua16[f_period_e].reload_u16;
        g_wwdgInfos_s.Init.Window    = (t_uint32)0x0FFF;
        g_wwdgInfos_s.Init.EWIMode   = WWDG_EWI_ENABLE;
        bspRet_e = HAL_WWDG_Init(&g_wwdgInfos_s);

        if(bspRet_e != HAL_OK)
        {
            Ret_e = RC_ERROR_WRONG_STATE;
        }
    }

    return Ret_e;
}

/*********************************
 * FMKCPU_ResetWwdg
 *********************************/
t_eReturnState FMKCPU_ResetWwdg(void)
{
    HAL_StatusTypeDef bspRet_e = HAL_OK;
    t_eReturnState Ret_e = RC_OK;
    bspRet_e = HAL_WWDG_Refresh(&g_wwdgInfos_s);

    if(bspRet_e != HAL_OK)
    {
        Ret_e = RC_ERROR_WRONG_RESULT;
    }
    return Ret_e;
}
/*********************************
 * FMKCPU_Set_PWMChannelCfg
 *********************************/
t_eReturnState FMKCPU_Set_PWMChannelCfg(t_sFMKCPU_BspTimerCfg f_bspCfg_s, t_uint32 f_pwmFreq_u32)
{
    /********************************
     *   Some useful information for PWM generation
     *   1 - ARR = Period in Init =  (((freq_timer)/ (freq_pwm * (PSC+1))) -1)
     *   For a dutycyle E [0 - 1000]
     *   2 - CCR1_2_3_4 depending on channel, set the Duty Cycle -> (DutyCyle/ 1000) * (ARR +1)
     ********************************/
    t_eReturnState Ret_e = RC_OK;
    HAL_StatusTypeDef BspRet_e = HAL_OK;
    TIM_MasterConfigTypeDef masterCfg_s = {0};
    TIM_OC_InitTypeDef BspOcInit_s;
    t_uint32 bspChannel_u32 = 0;
    t_uint32 bspPeriod_u32;

    if (f_bspCfg_s.timer_e > FMKCPU_TIMER_NB || f_bspCfg_s.channel_e > FMKCPU_CHANNEL_NB)
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
    }
    if (g_TimerInfo_as[f_bspCfg_s.timer_e].IsTimerConfigured_b == (t_bool)False)
    {
        bspPeriod_u32 = (t_uint32)(((FMKCPU_TIMER_CLOCK_OSC * CST_MHZ_TO_HZ) /
                                            (f_pwmFreq_u32 * (FMKCPU_PWM_PSC + 1))) - (t_uint32)1);
        Ret_e = s_FMKCPU_Set_BspTimerInit(&g_TimerInfo_as[f_bspCfg_s.timer_e],
                                                    FMKCPU_HWCHNL_CFG_PWM,
                                                    (t_uint32)FMKCPU_PWM_PSC,
                                                    (t_uint32)bspPeriod_u32,
                                                    (t_uint32)TIM_COUNTERMODE_UP,
                                                    (t_uint32)TIM_CLOCKDIVISION_DIV1,
                                                    (t_uint32)TIM_AUTORELOAD_PRELOAD_DISABLE); // Irreveleent in PWM                           
        masterCfg_s.MasterOutputTrigger = TIM_TRGO_RESET;
        masterCfg_s.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
        BspRet_e = HAL_TIMEx_MasterConfigSynchronization(&g_TimerInfo_as[f_bspCfg_s.timer_e].BspTimer_ps,
                                                            &masterCfg_s);
        if(BspRet_e != HAL_OK)
        {
            g_TimerInfo_as[f_bspCfg_s.timer_e].IsTimerConfigured_b = (t_bool)False;
            Ret_e = RC_ERROR_WRONG_RESULT;
        }
    }
    if (g_TimerInfo_as[f_bspCfg_s.timer_e].Channel_as[f_bspCfg_s.channel_e].IsChnlConfigure_b == (t_bool)True)
    {
        Ret_e = RC_WARNING_ALREADY_CONFIGURED;
    }
    if (Ret_e == RC_OK)
    { // Function get here only if Timer is initialized and channel not initialized yet
        // Now Configure the channel in PWM mode
        Ret_e = s_FMKCPU_Get_BspChannel(f_bspCfg_s.channel_e, &bspChannel_u32);
        if (Ret_e == RC_OK)
        {
            BspOcInit_s.OCMode = (t_uint32)TIM_OCMODE_PWM1; // Basic cfg impose Up when counter > counterCompare
            BspOcInit_s.Pulse = (t_uint32)0;                // set init DutyCycle to 0
            BspOcInit_s.OCNPolarity = (t_uint32)TIM_OCPOLARITY_HIGH;
            BspOcInit_s.OCFastMode = (t_uint32)TIM_OCFAST_DISABLE;
            BspRet_e = HAL_TIM_PWM_ConfigChannel(&g_TimerInfo_as[f_bspCfg_s.timer_e].BspTimer_ps,
                                                    &BspOcInit_s,
                                                    (uint32_t)bspChannel_u32);  
            if (BspRet_e != HAL_OK)
            {
                Ret_e = RC_ERROR_WRONG_STATE;
            }
        }
        if (Ret_e == RC_OK)
        { // Update INformation
            g_TimerInfo_as[f_bspCfg_s.timer_e].Channel_as[f_bspCfg_s.channel_e].HwCfg_e = FMKCPU_HWCHNL_CFG_PWM;
            g_TimerInfo_as[f_bspCfg_s.timer_e].Channel_as[f_bspCfg_s.channel_e].IsChnlConfigure_b = (t_bool)True;
        }
        
    }
    return Ret_e;
}

/*********************************
 * FMKCPU_Set_PWMChannelDuty
 *********************************/
t_eReturnState FMKCPU_Set_PWMChannelDuty(t_eFMKCPU_Timer f_timer_e,
                                         t_eFMKCPU_InterruptChnl f_channel_e,
                                         t_uint16 f_dutyCycle_u16)
/********************************
 *   Some useful information for PWM generation
 *   1 - ARR = Period in Init = (((freq_timer)/ (freq_pwm * (PSC+1))) -1)
 *   For a dutycyle E [0 - 1000]
 *   2 - CCR1_2_3_4 depending on channel, set the Duty Cycle -> CCR = (DutyCyle/ 1000) * (ARR +1)
 ********************************/
{
    t_eReturnState Ret_e = RC_OK;
    t_uint32 BspChannel_u32 = 0;
    t_uint32 CCRxValue_u32 = 0;

    if (f_timer_e > FMKCPU_TIMER_NB || f_channel_e > FMKCPU_CHANNEL_NB)
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
    }
    if (g_TimerInfo_as[f_timer_e].IsTimerConfigured_b == (t_bool)False 
    || g_TimerInfo_as[f_timer_e].Channel_as[f_channel_e].IsChnlConfigure_b == (t_bool)False)
    {
        Ret_e = RC_ERROR_WRONG_STATE;
    }
    if (Ret_e == RC_OK)
    {
        // Shutdown channel if dutycycle == 0 & channel is active
        //  else make dutycycle to channel, shut on channel if not on yet
        if (f_dutyCycle_u16 == (t_uint16)0 && g_TimerInfo_as[f_timer_e].Channel_as[f_channel_e].State_e == FMKCPU_CHNLST_ACTIVATED)
        {
            s_FMKCPU_Set_HwChannelState(f_timer_e, f_channel_e, FMKCPU_CHNLST_DISACTIVATED);
        }
        else if (f_dutyCycle_u16 > (t_uint16)FMKCPU_PWM_MIN_DUTY_CYLCE && f_dutyCycle_u16 <= (t_uint16)FMKCPU_PWM_MAX_DUTY_CYLCE)
        { // update dutycycle
            CCRxValue_u32 = (t_uint32)((t_float32)f_dutyCycle_u16 / (t_float32)FMKCPU_PWM_MAX_DUTY_CYLCE *
                           (t_float32)(g_TimerInfo_as[f_timer_e].BspTimer_ps.Init.Period + (t_uint32)1));
            if (g_TimerInfo_as[f_timer_e].Channel_as[f_channel_e].State_e == FMKCPU_CHNLST_DISACTIVATED)
            {

                Ret_e = s_FMKCPU_Set_HwChannelState(f_timer_e, f_channel_e, FMKCPU_CHNLST_ACTIVATED);
            }
            if (Ret_e == RC_OK)
            {
                Ret_e = s_FMKCPU_Get_BspChannel(f_channel_e, &BspChannel_u32);
            }
            if (Ret_e == RC_OK)
            {
                __HAL_TIM_SET_COMPARE(&g_TimerInfo_as[f_timer_e].BspTimer_ps, BspChannel_u32, (t_uint32)CCRxValue_u32);
            }
        }
        else
        {
            Ret_e = RC_WARNING_NO_OPERATION;
        }
    }
    return Ret_e;
}

/*********************************
 * FMKCPU_Get_PWMChannelDuty
 *********************************/
t_eReturnState FMKCPU_Get_PWMChannelDuty(t_eFMKCPU_Timer f_timer_e,
                                         t_eFMKCPU_InterruptChnl f_channel_e,
                                         t_uint16 *f_dutyCycle_u16)
{
    /********************************
     *   Some useful information for PWM generation
     *   1 - ARR = Period in Init =  (((freq_timer)/ (freq_pwm * (PSC+1))) -1)
     *   For a dutycyle E [0 - 1000]
     *   2 - CCR1_2_3_4 depending on channel, set the Duty Cycle -> CCR = (DutyCyle/ 1000) * (ARR +1)
     ********************************/
    t_eReturnState Ret_e = RC_OK;
    t_uint32 BspChannel_u32 = 0;
    t_uint32 comparedValue_u32 = 0;

    if (f_timer_e > FMKCPU_TIMER_NB || f_channel_e > FMKCPU_CHANNEL_NB)
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
    }
    if (g_TimerInfo_as[f_timer_e].IsTimerConfigured_b == (t_bool)False || g_TimerInfo_as[f_timer_e].Channel_as[f_channel_e].IsChnlConfigure_b == (t_bool)False)
    {
        Ret_e = RC_ERROR_WRONG_STATE;
    }
    if (f_dutyCycle_u16 == (t_uint16 *)NULL)
        if (Ret_e == RC_OK)
        {
            // update dutycycle onlyu if channel is active
            if (g_TimerInfo_as[f_timer_e].Channel_as[f_channel_e].State_e == FMKCPU_CHNLST_ACTIVATED)
            {
                Ret_e = s_FMKCPU_Get_BspChannel(f_channel_e, &BspChannel_u32);
                if (Ret_e == RC_OK)
                {
                    comparedValue_u32 = (t_uint32)HAL_TIM_ReadCapturedValue(&g_TimerInfo_as[f_timer_e].BspTimer_ps, BspChannel_u32);
                    *f_dutyCycle_u16 = (t_uint16)((comparedValue_u32 * 1000) /
                                                  (g_TimerInfo_as[f_timer_e].BspTimer_ps.Init.Period + 1));
                }
            }
            else
            {
                Ret_e = RC_ERROR_WRONG_STATE;
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
    if (f_bspCfg_s.timer_e > FMKCPU_TIMER_NB || f_bspCfg_s.channel_e > FMKCPU_CHANNEL_NB)
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
    }
    if (g_TimerInfo_as[f_bspCfg_s.timer_e].IsTimerConfigured_b == (t_bool)False)
    {
        s_FMKCPU_Set_BspTimerInit(&g_TimerInfo_as[f_bspCfg_s.timer_e],
                                    FMKCPU_HWCHNL_CFG_IC,
                                    (t_uint32)FMKCPU_IC_PSC,
                                    (t_uint32)FMKCPU_IC_ARR,
                                    (t_uint32)TIM_COUNTERMODE_UP,
                                    (t_uint32)TIM_CLOCKDIVISION_DIV1,
                                    (t_uint32)TIM_AUTORELOAD_PRELOAD_DISABLE);
    }
    if (g_TimerInfo_as[f_bspCfg_s.timer_e].Channel_as[f_bspCfg_s.channel_e].HwCfg_e != FMKCPU_HWCHNL_CFG_IC)
    { // this timer and channel is already configured for another purpose
        Ret_e = RC_ERROR_NOT_ALLOWED;
    }
    if (g_TimerInfo_as[f_bspCfg_s.timer_e].Channel_as[f_bspCfg_s.channel_e].IsChnlConfigure_b == (t_bool)True)
    {
        Ret_e = RC_WARNING_ALREADY_CONFIGURED;
    }
    { // this timer and channel is already configured for another purpose
        Ret_e = RC_ERROR_NOT_ALLOWED;
    }
    if (Ret_e == RC_OK)
    {
        Ret_e = s_FMKCPU_Get_BspChannel(f_bspCfg_s.channel_e, &bspChannel_u32);
        if (Ret_e == RC_OK)
        {
            BspICInit_s.ICPolarity = (t_uint32)TIM_ICPOLARITY_RISING;
            BspICInit_s.ICSelection = (t_uint32)TIM_ICSELECTION_DIRECTTI;
            BspICInit_s.ICPrescaler = (t_uint32)TIM_ICPSC_DIV1;
            BspICInit_s.ICFilter = (t_uint32)0;
            BspRet_e = HAL_TIM_IC_ConfigChannel(&g_TimerInfo_as[f_bspCfg_s.timer_e].BspTimer_ps,
                                                &BspICInit_s,
                                                bspChannel_u32);
            if (BspRet_e != HAL_OK)
            {
                Ret_e = RC_ERROR_WRONG_STATE;
            }
        }
        if (Ret_e == RC_OK)
        { // update information
            g_TimerInfo_as[f_bspCfg_s.timer_e].Channel_as[f_bspCfg_s.channel_e].HwCfg_e = FMKCPU_HWCHNL_CFG_IC;
            g_TimerInfo_as[f_bspCfg_s.timer_e].Channel_as[f_bspCfg_s.channel_e].IsChnlConfigure_b = (t_bool)True;
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
    /********************************
     *   Some useful information for Evnt generation
     *   In FMKCPU_ConfigPrivate, we set the prescaler so that
     *   the freqTimer counter is 1ms. In conclusion ARR = .period= (f_periodms -1) in ms
     ********************************/
    t_eReturnState Ret_e = RC_OK;
    t_eFMKCPU_Timer EvntTimer_e;
    t_eFMKCPU_InterruptChnl EvntChnl_e;

    if (f_evntChannel_e > FMKCPU_EVENT_CHANNEL_NB)
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
    }
    if (f_ITChannel_cb == (t_cbFMKCPU_InterruptChnl *)NULL_FONCTION)
    {
        Ret_e = RC_ERROR_PTR_NULL;
    }
    if(Ret_e == RC_OK)
    {
        EvntTimer_e = c_FMKCPU_EvntTimerCfg_as[f_evntChannel_e].timer_e;
        EvntChnl_e = c_FMKCPU_EvntTimerCfg_as[f_evntChannel_e].channel_e;
    
        if (g_TimerInfo_as[EvntTimer_e].IsTimerConfigured_b == (t_bool)False)
        {
            Ret_e = s_FMKCPU_Set_BspTimerInit(&g_TimerInfo_as[EvntTimer_e],
                                                FMKCPU_HWCHNL_CFG_EVNT,
                                                (t_uint32)FMKCPU_EVNT_PSC,
                                                (t_uint32)(f_periodms_u32 - 1),
                                                (t_uint32)TIM_COUNTERMODE_UP,
                                                (t_uint32)TIM_CLOCKDIVISION_DIV1,
                                                (t_uint32)TIM_AUTORELOAD_PRELOAD_DISABLE);
        }
        if (g_TimerInfo_as[EvntTimer_e].Channel_as[EvntTimer_e].IsChnlConfigure_b == (t_bool)True)
        {
            Ret_e = RC_WARNING_ALREADY_CONFIGURED;
        }
        if (Ret_e == RC_OK)
        {
            // Update Flag Configured
            g_TimerInfo_as[EvntTimer_e].IsTimerConfigured_b = (t_bool)True;
            g_TimerInfo_as[EvntTimer_e].Channel_as[EvntChnl_e].HwCfg_e = FMKCPU_HWCHNL_CFG_EVNT;
            g_TimerInfo_as[EvntTimer_e].Channel_as[EvntChnl_e].RunMode_e = FMKCPU_CNHL_RUNMODE_INTERRUPT;
            g_TimerInfo_as[EvntTimer_e].Channel_as[EvntChnl_e].chnl_cb = f_ITChannel_cb;
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

    if (f_timer_e > FMKCPU_TIMER_NB || f_channel_e > FMKCPU_CHANNEL_NB)
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
    }
    if (f_ITChannel_cb == (t_cbFMKCPU_InterruptChnl *)NULL_FONCTION)
    {
        Ret_e = RC_ERROR_PTR_NULL;
    }
    if (g_TimerInfo_as[f_timer_e].Channel_as[f_channel_e].IsChnlConfigure_b != (t_bool)True || g_TimerInfo_as[f_timer_e].IsTimerConfigured_b != (t_bool)True)
    {
        Ret_e = RC_ERROR_WRONG_STATE;
    }
    if (Ret_e == RC_OK)
    {
        // Update channel Run mode and Add Callback
        g_TimerInfo_as[f_timer_e].Channel_as[f_channel_e].RunMode_e = FMKCPU_CNHL_RUNMODE_INTERRUPT;
        g_TimerInfo_as[f_timer_e].Channel_as[f_channel_e].chnl_cb = f_ITChannel_cb;
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

    if (f_timer_e > FMKCPU_TIMER_NB || f_channel_e > FMKCPU_CHANNEL_NB || f_channelState_e > FMKCPU_CHNLST_NB)
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
    }
    if (Ret_e == RC_OK)
    {
        Ret_e = s_FMKCPU_Set_HwChannelState(f_timer_e, f_channel_e, f_channelState_e);
    }
    return Ret_e;
}
//********************************************************************************
//                      Local functions - Implementation
//********************************************************************************
/*********************************
 * s_FMKCPU_PreOperational
 *********************************/
static t_eReturnState s_FMKCPU_PreOperational(void)
{
    t_eReturnState Ret_e = RC_OK;

    // set sys confgiguration 
    Ret_e = FMKCPU_Set_SysClockCfg();
    if(Ret_e == RC_OK)
    {
        Ret_e = FMKCPU_Set_WwdgCfg((t_eFMKCPu_WwdgResetPeriod)FMKCPU_WWDG_RESET_CFG);
    }

    return Ret_e;
}
/*********************************
 * s_FMKCPU_Operational
 *********************************/
static t_eReturnState s_FMKCPU_Operational(void)
{
    return RC_OK;
}

/*********************************
 * FMKCPU_Set_SysClockCfg
 *********************************/
t_eReturnState FMKCPU_Set_SysClockCfg(void)
{
    t_eReturnState Ret_e = RC_OK;
    HAL_StatusTypeDef  bspRet_e = HAL_OK;
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
    RCC_OscInitStruct.HSIState = RCC_HSI_ON;
    RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;

    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                                    |RCC_CLOCKTYPE_PCLK1;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

    bspRet_e = HAL_RCC_OscConfig(&RCC_OscInitStruct);
    if(bspRet_e == HAL_OK)
    {
        bspRet_e = HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0);
    }
    if(bspRet_e != HAL_OK)
    {
        Ret_e = RC_ERROR_WRONG_RESULT;
    }
    return Ret_e;
}
/*********************************
 * s_FMKCPU_Get_BspTimer
 *********************************/
static t_eReturnState s_FMKCPU_Get_BspNVICPriority(t_eFMKCPU_NVICPriority f_priority_e, t_uint32 *f_BspNVICPriority_pu32)
{
    t_eReturnState Ret_e = RC_OK;

    if (f_BspNVICPriority_pu32 == (t_uint32 *)NULL)
    {
        Ret_e = RC_ERROR_PTR_NULL;
    }
    if (f_priority_e > FMKCPU_NVIC_PRIORITY_NB)
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
    }
    if (Ret_e == RC_OK)
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

    if (f_bspChnl_pu32 == (t_uint32 *)NULL)
    {
        Ret_e = RC_ERROR_PTR_NULL;
    }
    if (f_channel_e > FMKCPU_CHANNEL_NB)
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
    }
    if (Ret_e == RC_OK)
    {
        switch (f_channel_e)
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
    t_sFMKCPU_CHnlInfo *channelInfo;
    HAL_StatusTypeDef bspRet_e = HAL_OK;

    // Argument already verify
    channelInfo = &g_TimerInfo_as[f_timer_e].Channel_as[f_channel_e];
    if (channelInfo->State_e != f_chnlStateOpe_e)
    {
        Ret_e = s_FMKCPU_Get_BspChannel(f_channel_e, &bspChannel_u32);
        if (Ret_e == RC_OK)
        { // Depending on wehter we need to activate or deactivate function
            switch (f_chnlStateOpe_e)
            {
                case FMKCPU_CHNLST_ACTIVATED:
                { // We have to start HALfunction in Basic or Interrupt depending on f_chnlRunMode_e
                    // call the right HAL function Polling or Interrupt mode
                    if (g_TimerInfo_as[f_timer_e].IsNVICTimerEnable_b == (t_bool)False)
                    {
                        Ret_e = FMKCPU_Set_NVICState(g_TimerInfo_as[f_timer_e].IRQNType_e,
                                                    c_FMKCPU_IRQNPriority_ae[g_TimerInfo_as[f_timer_e].IRQNType_e],
                                                    FMKCPU_NVIC_OPE_ENABLE);
                    }
                    if (Ret_e == RC_OK)
                    {
                        switch (channelInfo->RunMode_e)
                        {
                        case FMKCPU_CNHL_RUNMODE_POLLING:
                            bspRet_e = c_FMKCPU_BspTimFunc_apf[channelInfo->HwCfg_e].StartFuncPoll_pcb(&g_TimerInfo_as[f_timer_e].BspTimer_ps,
                                                                                                            (t_uint32)bspChannel_u32);
                            break;
                        case FMKCPU_CNHL_RUNMODE_INTERRUPT:
                            bspRet_e = c_FMKCPU_BspTimFunc_apf[channelInfo->HwCfg_e].StartFuncInterrupt_pcb(&g_TimerInfo_as[f_timer_e].BspTimer_ps,
                                                                                                                (t_uint32)bspChannel_u32);
                            break;
                        case FMKCPU_CNHL_RUNMODE_NB:
                        default:
                            Ret_e = RC_ERROR_NOT_SUPPORTED;
                            break;
                        }
                    }

                    break;
                }

                case FMKCPU_CHNLST_DISACTIVATED:
                {
                    if (g_TimerInfo_as[f_timer_e].IsNVICTimerEnable_b == (t_bool)True)
                    {
                        Ret_e = FMKCPU_Set_NVICState(g_TimerInfo_as[f_timer_e].IRQNType_e,
                                                    c_FMKCPU_IRQNPriority_ae[g_TimerInfo_as[f_timer_e].IRQNType_e],
                                                    FMKCPU_NVIC_OPE_DISABLE);
                    }
                    if (Ret_e == RC_OK)
                    {
                        switch (channelInfo->RunMode_e)
                        {
                        case FMKCPU_CNHL_RUNMODE_POLLING:
                            bspRet_e = c_FMKCPU_BspTimFunc_apf[channelInfo->HwCfg_e].StopFuncPoll_pcb(&g_TimerInfo_as[f_timer_e].BspTimer_ps,
                                                                                                        (t_uint32)bspChannel_u32);
                            break;
                        case FMKCPU_CNHL_RUNMODE_INTERRUPT:
                            bspRet_e = c_FMKCPU_BspTimFunc_apf[channelInfo->HwCfg_e].StopFuncInterrupt_pcb(&g_TimerInfo_as[f_timer_e].BspTimer_ps,
                                                                                                                (t_uint32)bspChannel_u32);
                            break;
                        case FMKCPU_CNHL_RUNMODE_NB:
                        default:
                            Ret_e = RC_ERROR_NOT_SUPPORTED;
                            break;
                        }
                    }
                    break;
                }
                case FMKCPU_CHNLST_NB:
                default:
                    Ret_e = RC_ERROR_NOT_SUPPORTED;
                    break;
            }
            if (bspRet_e != HAL_OK)
            {
                Ret_e = RC_ERROR_WRONG_RESULT;
            }
            else
            {
                channelInfo->State_e = f_chnlStateOpe_e;
            }
        }
    }
    return Ret_e;
}

/*********************************
 * s_FMKCPU_Set_BspTimerInit
 *********************************/
static t_eReturnState s_FMKCPU_Set_BspTimerInit(t_sFMKCPU_TimerInfo * f_timer_ps,
                                                t_eFMKCPU_HwChannelCfg f_hwChnlCfg_e,
                                                  t_uint32 f_prescaler_u32,
                                                  t_uint32 f_period_u32,
                                                  t_uint32 f_counterMode_32,
                                                  t_uint32 f_clockDivision_u32,
                                                  t_uint32 f_autoRePreload_u32)
{
    t_eReturnState Ret_e = RC_OK;
    HAL_StatusTypeDef bspRet_e = HAL_OK;

    if (f_timer_ps == (t_sFMKCPU_TimerInfo *)NULL)
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
    }
    if(Ret_e == RC_OK)
    {
        Ret_e = FMKCPU_Set_HwClock(f_timer_ps->clock_e, FMKCPU_CLOCKPORT_OPE_ENABLE);
    }
    if (Ret_e == RC_OK)
    {
        f_timer_ps->BspTimer_ps.Init.Prescaler = f_prescaler_u32;
        f_timer_ps->BspTimer_ps.Init.Period = f_period_u32;
        f_timer_ps->BspTimer_ps.Init.CounterMode = f_counterMode_32;
        f_timer_ps->BspTimer_ps.Init.ClockDivision = f_clockDivision_u32;
        f_timer_ps->BspTimer_ps.Init.AutoReloadPreload = f_autoRePreload_u32;

        bspRet_e = c_FMKCPU_BspTimFunc_apf[f_hwChnlCfg_e].TimerInit_pcb(&f_timer_ps->BspTimer_ps);
        if(bspRet_e != HAL_OK)
        {
            Ret_e = RC_ERROR_WRONG_RESULT;
        }
        else 
        {
            f_timer_ps->IsTimerConfigured_b = (t_bool)True;
        }
    }

    return Ret_e;
}

/***********************************
 * s_FMKCPU_BspRqst_InterruptMngmt
 ***********************************/
static void s_FMKCPU_BspRqst_InterruptMngmt(TIM_HandleTypeDef *f_timerIstce_ps, t_eFMKCPU_HwChannelCfg f_HwChnlCfg_e)
{
    t_eFMKCPU_Timer Calltimer_e = FMKCPU_TIMER_NB;
    HAL_TIM_ActiveChannel BspITChnl_e = HAL_TIM_ACTIVE_CHANNEL_CLEARED;
    t_eFMKCPU_InterruptChnl ITChnl_e = FMKCPU_CHANNEL_NB;
    t_uint8 LLI_u8 = 0;

    // loop to know  which timer it is
    for (LLI_u8 = (t_uint8)0; LLI_u8 < (t_uint8)FMKCPU_TIMER_NB; LLI_u8++)
    {
        if (&g_TimerInfo_as[LLI_u8].BspTimer_ps == (TIM_HandleTypeDef *)f_timerIstce_ps)
        {
            Calltimer_e = (t_eFMKCPU_Timer)LLI_u8;
            break;
        }
    }
    if (Calltimer_e == FMKCPU_TIMER_NB)
    {
        return; // Call somoene to deal with this error
    }
    else
    {
    #warning "only channel callback take in charged"
        BspITChnl_e = HAL_TIM_GetActiveChannel(&g_TimerInfo_as[Calltimer_e].BspTimer_ps);
        switch (BspITChnl_e)
        {
        case HAL_TIM_ACTIVE_CHANNEL_1:
            ITChnl_e = FMKCPU_CHANNEL_1;
            break;

        case HAL_TIM_ACTIVE_CHANNEL_2:
            ITChnl_e = FMKCPU_CHANNEL_1;
            break;

        case HAL_TIM_ACTIVE_CHANNEL_3:
            ITChnl_e = FMKCPU_CHANNEL_1;
            break;

        case HAL_TIM_ACTIVE_CHANNEL_4:
            ITChnl_e = FMKCPU_CHANNEL_1;
            break;
        case HAL_TIM_ACTIVE_CHANNEL_CLEARED:
        default:
            break;
        }
        if (ITChnl_e != FMKCPU_CHANNEL_NB)
        {
            g_TimerInfo_as[Calltimer_e].Channel_as[ITChnl_e].chnl_cb(Calltimer_e, ITChnl_e);
        }
    }
    return;
}
//********************************************************************************
//                      HAL_Callback Implementation
//********************************************************************************
/*****************************************************************************
 *
 *	@brief      Every calllack function is now centralized in one function
 *	@details
 *
 *
 *	@param[in]
 *	@param[out]
 *
 *
 *
 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) { return s_FMKCPU_BspRqst_InterruptMngmt(htim, FMKCPU_HWCHNL_CFG_EVNT); }
void HAL_TIM_PeriodElapsedHalfCpltCallback(TIM_HandleTypeDef *htim) { return s_FMKCPU_BspRqst_InterruptMngmt(htim, FMKCPU_HWCHNL_CFG_EVNT); }
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim) { return s_FMKCPU_BspRqst_InterruptMngmt(htim, FMKCPU_HWCHNL_CFG_IC); }
void HAL_TIM_IC_CaptureHalfCpltCallback(TIM_HandleTypeDef *htim) { return s_FMKCPU_BspRqst_InterruptMngmt(htim, FMKCPU_HWCHNL_CFG_IC); }
void HAL_TIM_OC_DelayElapsedCallback(TIM_HandleTypeDef *htim) { return s_FMKCPU_BspRqst_InterruptMngmt(htim, FMKCPU_HWCHNL_CFG_OC); }
void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim) { return s_FMKCPU_BspRqst_InterruptMngmt(htim, FMKCPU_HWCHNL_CFG_PWM); }
void HAL_TIM_PWM_PulseFinishedHalfCpltCallback(TIM_HandleTypeDef *htim) { return s_FMKCPU_BspRqst_InterruptMngmt(htim, FMKCPU_HWCHNL_CFG_PWM); }
void HAL_TIM_TriggerCallback(TIM_HandleTypeDef *htim) { return s_FMKCPU_BspRqst_InterruptMngmt(htim, FMKCPU_HWCHNL_CFG_TRGR); }
void SysTick_Handler(void) { return HAL_IncTick(); }

/***********************************
 * WWDG_IRQHandler
 ***********************************/
void WWDG_IRQHandler(void)
{
    if (g_wwdgInfos_s.Instance->SR & WWDG_SR_EWIF)
    {
        // Effacer le drapeau d'interruption précoce
        g_wwdgInfos_s.Instance->SR &= ~WWDG_SR_EWIF;

        // deal with error
    }
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
