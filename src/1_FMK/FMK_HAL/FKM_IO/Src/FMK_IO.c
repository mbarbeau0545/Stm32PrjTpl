/*********************************************************************
 * @file        FMKIO.c
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
#include "./FMK_IO.h"
#include "FMK_CFG/FMKCFG_ConfigFiles/FMKIO_ConfigPrivate.h"
#include "FMK_HAL/FMK_CDA/Src/FMK_CDA.h"

// ********************************************************************
// *                      Defines
// ********************************************************************

// ********************************************************************
// *                      Types
// ********************************************************************
//-----------------------------ENUM TYPES-----------------------------//
/* CAUTION : Automatic generated code section for Enum: Start */

/* CAUTION : Automatic generated code section for Enum: End */

//-----------------------------TYPEDEF TYPES---------------------------//
//-----------------------------STRUCT TYPES---------------------------//
/* CAUTION : Automatic generated code section for Structure: Start */

/* CAUTION : Automatic generated code section for Structure: End */
typedef struct
{
    t_eFMKIO_PullMode       pull_e;
    t_eFMKIO_SpdMode        spd_e;
    t_eFMKIO_AlternateFunc  altFunc_e;
    t_bool                  IsSigConfigured_b;
    t_bool                  IsInterruptEnable_b;
    t_cbFMKIO_EventFunc *   EvntFunc_cb;
    
} t_sFMKIO_SigInfo;
// ********************************************************************
// *                      Prototypes
// ********************************************************************
	
// ********************************************************************
// *                      Variables
// ********************************************************************
t_sFMKIO_SigInfo g_InFreqSigInfo_as[FMKIO_INPUT_SIGFREQ_NB];
t_sFMKIO_SigInfo g_InAnaSigInfo_as[FMKIO_INPUT_SIGANA_NB];
t_sFMKIO_SigInfo g_InDigSigInfo_as[FMKIO_INPUT_SIGDIG_NB];
t_sFMKIO_SigInfo g_InEvntSigInfo_as[FMKIO_INPUT_SIGEVNT_NB];
t_sFMKIO_SigInfo g_OutPwmSigInfo_as[FMKIO_OUTPUT_SIGPWM_NB];
t_sFMKIO_SigInfo g_OutDigSigInfo_as[FMKIO_OUTPUT_SIGDIG_NB];

t_eFMKCPU_ClockPortOpe g_IsGpioClockEnable_ab[FMKIO_GPIO_PORT_NB];

t_uint32 g_InFreqSigRawValue_ua32[FMKIO_INPUT_SIGFREQ_NB];

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
static t_eReturnState s_FMKIO_Get_BspPullMode(t_eFMKIO_PullMode f_pull_e, t_uint32 *f_bspPull_pu32);
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
static t_eReturnState s_FMKIO_Get_BspSpdMode(t_eFMKIO_SpdMode f_spd_e, t_uint32 *f_bspSpd_pu32);
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
static t_eReturnState s_FMKIO_Get_BspGpioPort(t_eFMKIO_GpioPort f_GpioPort_e, GPIO_TypeDef * f_BspGpio_ps);
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
static t_eReturnState s_FMKIO_Get_BspTriggerMode(t_eFMKIO_SigTrigCptr f_trigger_e, t_uint32 * f_bspTrigger_pu32);
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
static t_eReturnState s_FMKIO_Set_BspSigCfg(t_eFMKIO_GpioPort   f_gpioPort_e,
                                            t_eFMKIO_BspGpioPin f_pin_e,
                                            t_uint32            f_mode_u32,
                                            t_eFMKIO_PullMode   f_pull_e,
                                            t_eFMKIO_SpdMode    f_spd_e,
                                            t_uint8             f_AltFunc_u8);
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
static t_eReturnState s_FMKIO_MngSigFrequency(t_eFMKCPU_Timer f_timer_e, t_eFMKCPU_InterruptChnl f_channel_e);
/**************************************************************************************
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
static t_eReturnState s_FMKIO_Set_GpioClkState(t_eFMKIO_GpioPort f_gpioPort_e, t_eFMKCPU_ClockPortOpe f_ope_e);
//****************************************************************************
//                      Public functions - Implementation
//********************************************************************************
/*********************************
* s_FMKIO_Get_BspPullMode
*********************************/
t_eReturnState FMKIO_Set_InDigSigCfg(t_eFMKIO_InDigSig f_signal_e, t_eFMKIO_PullMode f_pull_e)
{
    t_eReturnState Ret_e = RC_OK;
    t_eFMKIO_GpioPort gpioPort_e;
    if(f_signal_e > FMKIO_INPUT_SIGDIG_NB
    || f_pull_e   > FMKIO_PULL_MODE_NB)
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
    }
    if(Ret_e == RC_OK)
    {
        gpioPort_e = c_InDigSigBspMap_as[f_signal_e].HwGpio_e;
        Ret_e = s_FMKIO_Set_BspSigCfg(gpioPort_e,
                                     c_InDigSigBspMap_as[f_signal_e].HwPin_e,
                                     (t_uint32)MODE_INPUT,
                                     f_pull_e,
                                     FMKIO_SPD_MODE_LOW, // irrevelent for a input sig dig
                                     GPIO_AF0_EVENTOUT);
        if(Ret_e == RC_OK)
        {
            if(g_IsGpioClockEnable_ab[gpioPort_e] == (t_bool)False)
            {
                Ret_e = s_FMKIO_Set_GpioClkState(gpioPort_e, FMKCPU_CLOCKPORT_OPE_ENABLE);
            }
            if(Ret_e == RC_OK)
            {// update info
                g_InDigSigInfo_as[f_signal_e].IsSigConfigured_b = (t_bool)True;
                g_InDigSigInfo_as[f_signal_e].pull_e = f_pull_e;
                g_InDigSigInfo_as[f_signal_e].spd_e  = FMKIO_SPD_MODE_LOW;
            }
        }
    }
    return Ret_e;
}

/*********************************
* FMKIO_Set_InAnaSigCfg
*********************************/
t_eReturnState FMKIO_Set_InAnaSigCfg(t_eFMKIO_InAnaSig f_signal_e, t_eFMKIO_PullMode f_pull_e)
{
    t_eReturnState Ret_e = RC_OK;
    t_eFMKIO_GpioPort gpioPort_e;
    if(f_signal_e > FMKIO_INPUT_SIGANA_NB
    || f_pull_e   > FMKIO_PULL_MODE_NB)
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
    }
    if(Ret_e == RC_OK)
    {
        gpioPort_e = c_InAnaSigBspMap_as[f_signal_e].HwGpio_e;
        Ret_e = s_FMKIO_Set_BspSigCfg(gpioPort_e,
                                     c_InAnaSigBspMap_as[f_signal_e].HwPin_e,
                                     (t_uint32)MODE_ANALOG,
                                     f_pull_e,
                                     FMKIO_SPD_MODE_LOW, // irrevelent for a input sig dig
                                     GPIO_AF0_EVENTOUT);
        if(Ret_e == RC_OK)
        {
            if(g_IsGpioClockEnable_ab[gpioPort_e] == (t_bool)False)
            {
                Ret_e = s_FMKIO_Set_GpioClkState(gpioPort_e, FMKCPU_CLOCKPORT_OPE_ENABLE);
            }
            if(Ret_e == RC_OK)
            {// configure the adc 
                FMKCDA_AddAdcChannelCfg(c_InAnaSigAdcCfg_ae[f_signal_e].adc_e, 
                                        c_InAnaSigAdcCfg_ae[f_signal_e].adcChannel_e,
                                        FMKCDA_ADC_CFG_SCAN_DMA);
            }
            if(Ret_e == RC_OK)
            {// update info
                g_InAnaSigInfo_as[f_signal_e].IsSigConfigured_b = (t_bool)True;
                g_InAnaSigInfo_as[f_signal_e].pull_e = f_pull_e;
                g_InAnaSigInfo_as[f_signal_e].spd_e  = FMKIO_SPD_MODE_LOW;
            }
        }
    }
    return Ret_e;
}

/*********************************
* FMKIO_Set_InFreqSigCfg
*********************************/
t_eReturnState FMKIO_Set_InFreqSigCfg(t_eFMKIO_InFreqSig f_signal_e)
{
    t_eReturnState Ret_e = RC_OK;
    t_eFMKIO_GpioPort gpioPort_e;
    t_sFMKCPU_BspTimerCfg timerCfg_s;

    if(f_signal_e  > FMKIO_INPUT_SIGFREQ_NB)
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
    }
    if(Ret_e == RC_OK)
    {
        gpioPort_e = c_InFreqSigBspMap_as[f_signal_e].BasicCfg.HwGpio_e;
        Ret_e = s_FMKIO_Set_BspSigCfg(gpioPort_e,
                                    c_InFreqSigBspMap_as[f_signal_e].BasicCfg.HwPin_e,
                                    (t_uint32)GPIO_MODE_AF_PP,
                                    FMKIO_PULL_MODE_UNABLE,
                                    FMKIO_SPD_MODE_HIGH, // irrevelent for a input sig dig
                                    c_InFreqSigBspMap_as[f_signal_e].BspAlternateFunc_u8);
        if(Ret_e == RC_OK)
        {
            timerCfg_s.timer_e         = c_InFreqSigBspMap_as[f_signal_e].timer_e;
            timerCfg_s.channel_e       = c_InFreqSigBspMap_as[f_signal_e].channel_e;
            timerCfg_s.timerFreq_u32   = 0; // prescaler set to 0 in this cfg anyway
            timerCfg_s.timerPeriod_u32 = 0xFFFF;
            Ret_e = FMKCPU_Set_ICChannelCfg(timerCfg_s, FMKCPU_CHNL_MEAS_RISING_EDGE);
            if(Ret_e == RC_OK)
            {
                Ret_e = FMKCPU_AddTimerChnlCallback(timerCfg_s.timer_e,
                                                    timerCfg_s.channel_e,
                                                    (t_cbFMKCPU_InterruptChnl *)&s_FMKIO_MngSigFrequency );
            }
            if(Ret_e == RC_OK)
            {
                if(g_IsGpioClockEnable_ab[gpioPort_e] == (t_bool)False)
                {
                    Ret_e = s_FMKIO_Set_GpioClkState(gpioPort_e, FMKCPU_CLOCKPORT_OPE_ENABLE);
                }
                if(Ret_e == RC_OK)
                {// update info
                    g_InFreqSigInfo_as[f_signal_e].IsSigConfigured_b = (t_bool)True;
                    g_InFreqSigInfo_as[f_signal_e].pull_e = FMKIO_PULL_MODE_UNABLE;
                    g_InFreqSigInfo_as[f_signal_e].spd_e  = FMKIO_SPD_MODE_HIGH;
                }
            }
        }            
                
    }
    return Ret_e;
}
/*********************************
* FMKIO_Set_InEvntSigCfg
*********************************/
t_eReturnState FMKIO_Set_InEvntSigCfg(t_eFMKIO_InEvntSig f_signal_e, 
                                          t_eFMKIO_PullMode f_pull_e,
                                          t_eFMKIO_SigTrigCptr f_trigger_e,
                                          t_cbFMKIO_EventFunc * f_Evnt_cb)
{
    t_eReturnState Ret_e = RC_OK;
    t_eFMKIO_GpioPort gpioPort_e;
    t_uint32 bspTrigger_u32;

    if(f_signal_e  > FMKIO_INPUT_SIGEVNT_NB
    || f_pull_e    > FMKIO_PULL_MODE_NB
    || f_trigger_e > FMKIO_STC_NB)
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
    }
    if(f_Evnt_cb == (t_cbFMKIO_EventFunc *)NULL)
    {
        Ret_e = RC_ERROR_PTR_NULL;
    }
    if(Ret_e == RC_OK)
    {
        gpioPort_e = c_InEvntSigBspMap_as[f_signal_e].BasicCfg.HwGpio_e;
        Ret_e = s_FMKIO_Get_BspTriggerMode(f_trigger_e, &bspTrigger_u32);
        if(Ret_e == RC_OK)
        {
            Ret_e = s_FMKIO_Set_BspSigCfg(gpioPort_e,
                                        c_InEvntSigBspMap_as[f_signal_e].BasicCfg.HwPin_e,
                                        (t_uint32)bspTrigger_u32,
                                        FMKIO_PULL_MODE_UNABLE,
                                        FMKIO_SPD_MODE_LOW, // irrevelent for a input sig dig
                                        c_InFreqSigBspMap_as[f_signal_e].BspAlternateFunc_u8);
            if(Ret_e == RC_OK)
            {
                
                Ret_e = FMKCPU_Set_NVICState(c_InEvntSigBspMap_as[f_signal_e].ExtiIRQN_e,
                                             FMKCPU_NVIC_PRIORITY_MEDIUM,
                                             FMKCPU_NVIC_OPE_ENABLE);
                if(Ret_e == RC_OK)
                {
                    if(g_IsGpioClockEnable_ab[gpioPort_e] == (t_bool)False)
                    {
                        Ret_e = s_FMKIO_Set_GpioClkState(gpioPort_e, FMKCPU_CLOCKPORT_OPE_ENABLE);
                    }
                    if(Ret_e == RC_OK)
                    {// update info
                        g_InEvntSigInfo_as[f_signal_e].IsSigConfigured_b = (t_bool)True;
                        g_InEvntSigInfo_as[f_signal_e].pull_e = FMKIO_PULL_MODE_UNABLE;
                        g_InEvntSigInfo_as[f_signal_e].spd_e  = FMKIO_SPD_MODE_LOW;
                        g_InEvntSigInfo_as[f_signal_e].EvntFunc_cb = f_Evnt_cb;
                    }
                }
            }            
        }        
    }
    return Ret_e;
}
/*********************************
* FMKIO_Set_OutPwmSigCfg
*********************************/
t_eReturnState FMKIO_Set_OutPwmSigCfg(t_eFMKIO_OutPwmSig f_signal_e, 
                                      t_eFMKIO_PullMode  f_pull_e,
                                      t_uint32           f_frequency_u32,
                                      t_uint16           f_dutyCycle_u16,
                                      t_bool             f_startNow_b)
{
    t_eReturnState Ret_e = RC_OK;
    t_eFMKIO_GpioPort gpioPort_e;
    t_sFMKCPU_BspTimerCfg timerCfg_s;

    if(f_signal_e > FMKIO_OUTPUT_SIGPWM_NB
    || f_pull_e   > FMKIO_PULL_MODE_NB)
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
    }
    if(Ret_e == RC_OK)
    {
        gpioPort_e = c_OutPwmSigBspMap_as[f_signal_e].BasicCfg.HwGpio_e;
        Ret_e = s_FMKIO_Set_BspSigCfg(gpioPort_e,
                                     c_OutPwmSigBspMap_as[f_signal_e].BasicCfg.HwPin_e,
                                     (t_uint32)GPIO_MODE_AF_PP,
                                     f_pull_e,
                                     FMKIO_SPD_MODE_LOW, // irrevelent for a input sig dig
                                     c_OutPwmSigBspMap_as[f_signal_e].BspAlternateFunc_u8);
        if(Ret_e == RC_OK)
        {
            timerCfg_s.timer_e         = c_OutPwmSigBspMap_as[f_signal_e].timer_e;
            timerCfg_s.channel_e       = c_OutPwmSigBspMap_as[f_signal_e].channel_e;
            timerCfg_s.timerFreq_u32   = f_frequency_u32;
            timerCfg_s.timerPeriod_u32 = (t_uint32)(1000-1); // 1ms
            Ret_e = FMKCPU_Set_PWMChannelCfg(timerCfg_s);
        
            if(Ret_e == RC_OK)
            {
                if(g_IsGpioClockEnable_ab[gpioPort_e] == (t_bool)False)
                {
                    Ret_e = s_FMKIO_Set_GpioClkState(gpioPort_e, FMKCPU_CLOCKPORT_OPE_ENABLE);
                }
                if(Ret_e == RC_OK && f_startNow_b == (t_bool)True)
                {
                    Ret_e = FMKCPU_Set_ChannelState(timerCfg_s.timer_e, 
                                                    timerCfg_s.channel_e,
                                                    FMKCPU_CHNLST_ACTIVATED);
                }
                if(Ret_e == RC_OK)
                {// update info
                    g_OutPwmSigInfo_as[f_signal_e].IsSigConfigured_b = (t_bool)True;
                    g_OutPwmSigInfo_as[f_signal_e].pull_e = f_pull_e;
                    g_OutPwmSigInfo_as[f_signal_e].spd_e  = FMKIO_SPD_MODE_LOW;
                }
            }
        }
    }
    return Ret_e;
}

/*********************************
* s_FMKIO_Get_BspPullMode
*********************************/
t_eReturnState FMKIO_Set_OutDigSigCfg(t_eFMKIO_OutDigSig f_signal_e, 
                                          t_eFMKIO_PullMode  f_pull_e,
                                          t_eFMKIO_SpdMode   f_spd_e)
{
    t_eReturnState Ret_e = RC_OK;
    t_eFMKIO_GpioPort gpioPort_e;

    if(f_signal_e > FMKIO_OUTPUT_SIGDIG_NB
    || f_pull_e   > FMKIO_PULL_MODE_NB
    || f_spd_e    > FMKIO_SPD_MODE_NB)
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
    }
    if(Ret_e == RC_OK)
    {
        gpioPort_e = c_OutDigSigBspMap_as[f_signal_e].HwGpio_e;
        Ret_e = s_FMKIO_Set_BspSigCfg(gpioPort_e,
                                     c_OutDigSigBspMap_as[f_signal_e].HwPin_e,
                                     (t_uint32)GPIO_MODE_OUTPUT_PP,
                                     f_pull_e,
                                     f_spd_e, // irrevelent for a input sig dig
                                     GPIO_AF0_EVENTOUT);
        if(Ret_e == RC_OK)
        {
            if(g_IsGpioClockEnable_ab[gpioPort_e] == (t_bool)False)
            {
                Ret_e = s_FMKIO_Set_GpioClkState(gpioPort_e, FMKCPU_CLOCKPORT_OPE_ENABLE);
            }
            if(Ret_e == RC_OK)
            {// update info
                g_OutDigSigInfo_as[f_signal_e].IsSigConfigured_b = (t_bool)True;
                g_OutDigSigInfo_as[f_signal_e].pull_e = f_pull_e;
                g_OutDigSigInfo_as[f_signal_e].spd_e  = f_spd_e;
            }
        }
    }
    return Ret_e;
}

t_eReturnState FMKIO_Set_OutDigSigValue(t_eFMKIO_OutDigSig f_signal_e, t_eFMKIO_DigValue f_value_e)
{
    t_eReturnState Ret_e = RC_OK;
    GPIO_TypeDef bspGpio_u32;
    GPIO_PinState bspSigValue_e;

    if(f_signal_e > FMKIO_OUTPUT_SIGDIG_NB
    || f_value_e  > FMKIO_DIG_VALUE_NB)
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
    }
    if(Ret_e == RC_OK)
    {
        Ret_e = s_FMKIO_Get_BspGpioPort(c_InDigSigBspMap_as[f_signal_e].HwGpio_e, &bspGpio_u32);
        if(Ret_e == RC_OK)
        {
            switch (f_value_e)
            {
                case FMKIO_DIG_VALUE_LOW:
                    bspSigValue_e = GPIO_PIN_RESET;
                    break;
                case FMKIO_DIG_VALUE_HIGH:
                    bspSigValue_e = GPIO_PIN_SET;
                    break;
                case FMKIO_DIG_VALUE_NB:
                default:
                   Ret_e = RC_WARNING_WRONG_RESULT;
                   break;
            }
            if(Ret_e == RC_OK)
            {
                HAL_GPIO_WritePin(&bspGpio_u32, 
                                  c_BspPinMapping_ua32[c_InDigSigBspMap_as[f_signal_e].HwPin_e],
                                  bspSigValue_e);
            }
        }
    }
    return Ret_e;
}
/*********************************
* FMKIO_Set_OutPwmSigValue
*********************************/
t_eReturnState FMKIO_Set_OutPwmSigValue(t_eFMKIO_OutPwmSig f_signal_e, t_uint16 f_dutyCycle_u16)
{
    t_eReturnState Ret_e = RC_OK;

    if(f_signal_e > FMKIO_OUTPUT_SIGPWM_NB)
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
    }
    if(Ret_e == RC_OK)
    {
        Ret_e = FMKCPU_Set_PWMChannelDuty(c_OutPwmSigBspMap_as[f_signal_e].timer_e,
                                          c_OutPwmSigBspMap_as[f_signal_e].channel_e,
                                          f_dutyCycle_u16);
    }
    return Ret_e;
}

/*********************************
* FMKIO_Set_OutPwmSigValue
*********************************/
t_eReturnState FMKIO_Get_InDigSigValue(t_eFMKIO_InDigSig f_signal_e, t_eFMKIO_DigValue *f_value_pe)
{
    t_eReturnState Ret_e = RC_OK;
    GPIO_TypeDef bspGpio_u32;
    GPIO_PinState bspSigValue_e;

    if(f_signal_e > FMKIO_INPUT_SIGDIG_NB)
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
    }
    if(f_value_pe == (t_eFMKIO_DigValue *)NULL)
    {
        Ret_e = RC_ERROR_PTR_NULL;
    }
    if(Ret_e == RC_OK)
    {
        Ret_e = s_FMKIO_Get_BspGpioPort(c_InDigSigBspMap_as[f_signal_e].HwGpio_e, &bspGpio_u32);
        if(Ret_e == RC_OK)
        {
            bspSigValue_e = HAL_GPIO_ReadPin(&bspGpio_u32, c_BspPinMapping_ua32[c_InDigSigBspMap_as[f_signal_e].HwPin_e]);
            switch (bspSigValue_e)
            {
                case GPIO_PIN_RESET:
                    *f_value_pe = FMKIO_DIG_VALUE_LOW;
                    break;
                case GPIO_PIN_SET:
                    *f_value_pe = FMKIO_DIG_VALUE_HIGH;
                    break;
                default:
                   *f_value_pe = FMKIO_DIG_VALUE_LOW;
                   Ret_e = RC_WARNING_WRONG_RESULT;
                   break;
            }
        }
    }
    return Ret_e;
}

/*********************************
* s_FMKIO_Get_BspPullMode
*********************************/
t_eReturnState FMKIO_Get_InAnaSigValue(t_eFMKIO_InAnaSig f_signal_e, t_uint16 *f_value_pu16)
{
    t_eReturnState Ret_e = RC_OK;
    if(f_signal_e > FMKIO_INPUT_SIGANA_NB)
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
    }
    if(f_value_pu16 == (t_uint16 *)NULL)
    {
        Ret_e = RC_ERROR_PTR_NULL;
    }
    if(Ret_e == RC_OK)
    {
        Ret_e = FMKCDA_Get_AnaChannelMeasure(c_InAnaSigAdcCfg_ae[f_signal_e].adc_e,
                                             c_InAnaSigAdcCfg_ae[f_signal_e].adcChannel_e,
                                             f_value_pu16);
    }
    return Ret_e;

}

/*********************************
* FMKIO_Get_InFreqSigValue
*********************************/
t_eReturnState FMKIO_Get_InFreqSigValue(t_eFMKIO_InFreqSig f_signal_e, t_uint32 *f_value_pu32)
{
     t_eReturnState Ret_e = RC_OK;
    if(f_signal_e > FMKIO_INPUT_SIGFREQ_NB)
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
    }
    if(f_value_pu32 == (t_uint32 *)NULL)
    {
        Ret_e = RC_ERROR_PTR_NULL;
    }
    if(Ret_e == RC_OK)
    {
        *f_value_pu32 = g_InFreqSigRawValue_ua32[f_signal_e];
    }
    return Ret_e;
}

/*********************************
* FMKIO_Get_OutPwmSigValue
*********************************/
t_eReturnState FMKIO_Get_OutPwmSigValue(t_eFMKIO_OutPwmSig f_signal_e, t_uint16 *f_value_pu16)
{
    t_eReturnState Ret_e = RC_OK;

    if(f_signal_e > FMKIO_OUTPUT_SIGPWM_NB)
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
    }
    if(f_value_pu16 == (t_uint16 *)NULL)
    {
        Ret_e = RC_ERROR_PTR_NULL;
    }
    if(Ret_e == RC_OK)
    {
        Ret_e = FMKCPU_Get_PWMChannelDuty(c_OutPwmSigBspMap_as[f_signal_e].timer_e,
                                          c_OutPwmSigBspMap_as[f_signal_e].channel_e,
                                          f_value_pu16);
    }
    return Ret_e;
}

/*********************************
* FMKIO_Get_OutDigSigValue
*********************************/
t_eReturnState FMKIO_Get_OutDigSigValue(t_eFMKIO_OutDigSig f_signal_e, t_eFMKIO_DigValue *f_value_pe)
{
    t_eReturnState Ret_e = RC_OK;
    GPIO_TypeDef bspGpio_u32;
    GPIO_PinState bspSigValue_e;

    if(f_signal_e > FMKIO_OUTPUT_SIGDIG_NB)
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
    }
    if(f_value_pe == (t_eFMKIO_DigValue *)NULL)
    {
        Ret_e = RC_ERROR_PTR_NULL;
    }
    if(Ret_e == RC_OK)
    {
        Ret_e = s_FMKIO_Get_BspGpioPort(c_InDigSigBspMap_as[f_signal_e].HwGpio_e, &bspGpio_u32);
        if(Ret_e == RC_OK)
        {
            bspSigValue_e = HAL_GPIO_ReadPin(&bspGpio_u32, c_BspPinMapping_ua32[c_InDigSigBspMap_as[f_signal_e].HwPin_e]);
            switch (bspSigValue_e)
            {
                case GPIO_PIN_RESET:
                    *f_value_pe = FMKIO_DIG_VALUE_LOW;
                    break;
                case GPIO_PIN_SET:
                    *f_value_pe = FMKIO_DIG_VALUE_HIGH;
                    break;
                default:
                   *f_value_pe = FMKIO_DIG_VALUE_LOW;
                   Ret_e = RC_WARNING_WRONG_RESULT;
                   break;
            }
        }
    }
    return Ret_e;
}
//********************************************************************************
//                      Local functions - Implementation
//********************************************************************************
/*********************************
* s_FMKIO_Get_BspPullMode
*********************************/
static t_eReturnState s_FMKIO_Get_BspPullMode(t_eFMKIO_PullMode f_pull_e, t_uint32 *f_bspPull_pu32)
{
    t_eReturnState Ret_e = RC_OK;

    if(f_pull_e > FMKIO_PULL_MODE_NB)
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
    }
    if(f_bspPull_pu32 == (t_uint32 *)NULL)
    {
        Ret_e = RC_ERROR_PTR_NULL;
    }
    if(Ret_e == RC_OK)
    {
        switch (f_pull_e)
        {
            case FMKIO_PULL_MODE_UNABLE:
                *f_bspPull_pu32 = GPIO_NOPULL;
                break;
            case FMKIO_PULL_MODE_DOWN:
                *f_bspPull_pu32 = GPIO_PULLDOWN;
                break;
            case FMKIO_PULL_MODE_UP:
                *f_bspPull_pu32 = GPIO_PULLUP;
                break;
            case FMKIO_PULL_MODE_NB:
            default:
                Ret_e = RC_WARNING_NO_OPERATION;
                break;
        }
    }
    return Ret_e;
}

/*********************************
* s_FMKIO_Get_BspPullMode
*********************************/
static t_eReturnState s_FMKIO_Get_BspSpdMode(t_eFMKIO_SpdMode f_spd_e, t_uint32 *f_bspSpd_pu32)
{
    t_eReturnState Ret_e = RC_OK;

    if(f_spd_e > FMKIO_SPD_MODE_NB)
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
    }
    if(f_bspSpd_pu32 == (t_uint32 *)NULL)
    {
        Ret_e = RC_ERROR_PTR_NULL;
    }
    if(Ret_e == RC_OK)
    {
        switch (f_spd_e)
        {
            case FMKIO_SPD_MODE_LOW:
                *f_bspSpd_pu32 = GPIO_SPEED_FREQ_LOW;
                break;
            case FMKIO_SPD_MODE_MEDIUM:
                *f_bspSpd_pu32 = GPIO_SPEED_FREQ_MEDIUM;
                break;
            case FMKIO_SPD_MODE_HIGH:
                *f_bspSpd_pu32 = GPIO_SPEED_FREQ_HIGH;
                break;
            case FMKIO_SPD_MODE_NB:
            default:
                Ret_e = RC_WARNING_NO_OPERATION;
                break;
        }
    }
    return Ret_e;
}

/*********************************
* s_FMKIO_Get_BspTriggerMode
*********************************/
static t_eReturnState s_FMKIO_Get_BspTriggerMode(t_eFMKIO_SigTrigCptr f_trigger_e, t_uint32 * f_bspTrigger_pu32)
{
    t_eReturnState Ret_e = RC_OK;

    if(f_trigger_e > FMKIO_STC_NB)
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
    }
    if(f_bspTrigger_pu32 == (t_uint32 *)NULL)
    {
        Ret_e = RC_ERROR_PTR_NULL;
    }
    if(Ret_e == RC_OK)
    {
        switch (f_trigger_e)
        {
            case FMKIO_STC_RISING_EDGE:
                *f_bspTrigger_pu32 = GPIO_MODE_IT_RISING;
                break;
            case FMKIO_STC_FALLING_EDGE:
                *f_bspTrigger_pu32 = GPIO_MODE_IT_FALLING;
                break;
            case FMKIO_STC_BOTH_EDGE:
                *f_bspTrigger_pu32 = GPIO_MODE_IT_RISING_FALLING;
                break;
            case FMKIO_STC_NB:
            default:
                Ret_e = RC_WARNING_NO_OPERATION;
                break;
        }
    }
    return Ret_e;
}

/*********************************
* s_FMKIO_Get_BspGpioPort
*********************************/
static t_eReturnState s_FMKIO_Get_BspGpioPort(t_eFMKIO_GpioPort f_GpioPort_e, GPIO_TypeDef * f_BspGpio_ps)
{
    t_eReturnState Ret_e = RC_OK;

    if(f_GpioPort_e > FMKIO_GPIO_PORT_NB)
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
    }
    if(f_BspGpio_ps == (GPIO_TypeDef *)NULL)
    {
        Ret_e = RC_ERROR_PTR_NULL;
    }
    if(Ret_e == RC_OK)
    {
        switch (f_GpioPort_e)
        {
            case FMKIO_GPIO_PORT_A:
                f_BspGpio_ps = GPIOA;
                break;
            case FMKIO_GPIO_PORT_B:
                f_BspGpio_ps = GPIOB;
                break;
            case FMKIO_GPIO_PORT_C:
                f_BspGpio_ps = GPIOC;
                break;
            case FMKIO_GPIO_PORT_D:
                f_BspGpio_ps = GPIOD;
                break;
            case FMKIO_GPIO_PORT_F:
                f_BspGpio_ps = GPIOF;
                break;
            case FMKIO_GPIO_PORT_NB:
            default:
                Ret_e = RC_WARNING_NO_OPERATION;
                break;
        }
    }
    return Ret_e;
}

/*********************************
* s_FMKIO_Set_BspSigCfg
*********************************/
static t_eReturnState s_FMKIO_Set_BspSigCfg(t_eFMKIO_GpioPort   f_gpioPort_e,
                                            t_eFMKIO_BspGpioPin f_pin_e,
                                            t_uint32            f_mode_u32,
                                            t_eFMKIO_PullMode   f_pull_e,
                                            t_eFMKIO_SpdMode    f_spd_e,
                                            t_uint8             f_AltFunc_u8)
{
    t_eReturnState Ret_e = RC_OK;
    GPIO_TypeDef bspGpio_s;
    GPIO_InitTypeDef bspInit_s;
    t_uint32 bspPull_32;
    t_uint32 bspSpd_u32;

    if(f_gpioPort_e > FMKIO_GPIO_PORT_NB
    || f_pin_e      > FMKIO_GPIO_PIN_NB
    || f_pull_e     > FMKIO_PULL_MODE_NB
    || f_spd_e      > FMKIO_SPD_MODE_NB)
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
    }
    if(Ret_e == RC_OK)
    {
        Ret_e = s_FMKIO_Get_BspGpioPort(f_gpioPort_e, &bspGpio_s);
        if(Ret_e == RC_OK)
        {
            Ret_e = s_FMKIO_Get_BspPullMode(f_pull_e, &bspPull_32);
        }
        if(Ret_e == RC_OK)
        {
            Ret_e = s_FMKIO_Get_BspSpdMode(f_spd_e, &bspSpd_u32);
        }
        if(Ret_e == RC_OK)
        {
            bspInit_s.Alternate = (t_uint32)f_AltFunc_u8;
            bspInit_s.Mode      = (t_uint32)f_mode_u32;
            bspInit_s.Pin       = (t_uint32)c_BspPinMapping_ua32[f_pin_e];
            bspInit_s.Pull      = (t_uint32)bspPull_32;
            bspInit_s.Speed     = (t_uint32)bspSpd_u32;
            HAL_GPIO_Init(&bspGpio_s, &bspInit_s);
        }
    }
    return Ret_e;
}

/*********************************
* s_FMKIO_Set_GpioClkState
*********************************/
static t_eReturnState s_FMKIO_Set_GpioClkState(t_eFMKIO_GpioPort f_gpioPort_e, t_eFMKCPU_ClockPortOpe f_ope_e)
{
    t_eReturnState Ret_e = RC_OK;
    t_eFMKCPU_ClockPort gpioClkPort_e ;

    if(f_gpioPort_e > FMKIO_GPIO_PORT_NB)
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
    }
    if(Ret_e == RC_OK)
    {
        // get the GPIO CLOCK ENUM
        switch (f_gpioPort_e)
        {
            case FMKIO_GPIO_PORT_A:
                gpioClkPort_e = FMKCPU_RCC_CLK_GPIOA;
                break;
            case FMKIO_GPIO_PORT_B:
                gpioClkPort_e = FMKCPU_RCC_CLK_GPIOB;
                break;
            case FMKIO_GPIO_PORT_C:
                gpioClkPort_e = FMKCPU_RCC_CLK_GPIOC;
                break;
            case FMKIO_GPIO_PORT_F:
                gpioClkPort_e = FMKCPU_RCC_CLK_GPIOF;
                break;
            case FMKIO_GPIO_PORT_D:
            case FMKIO_GPIO_PORT_NB:
            default:
                Ret_e = RC_WARNING_NO_OPERATION;
                break;
        }
        if(Ret_e == RC_OK)
        {
            Ret_e = FMKCPU_Set_HwClock(gpioClkPort_e, f_ope_e);
        }
        if(Ret_e == RC_OK)
        {
            g_IsGpioClockEnable_ab[f_gpioPort_e] = f_ope_e;
        }
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
