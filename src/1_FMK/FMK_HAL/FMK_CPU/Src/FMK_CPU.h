/*********************************************************************
 * @file        FMK_CPU.h
 * @brief       Template_BriefDescription.
 * @note        TemplateDetailsDescription.\n
 *
 * @author      xxxxxx
 * @date        jj/mm/yyyy
 * @version     1.0
 */
  
#ifndef FMKCPU_H_INCLUDED
#define FMKCPU_H_INCLUDED





    // ********************************************************************
    // *                      Includes
    // ********************************************************************
    #include "FMK_CFG/FMKCFG_ConfigFiles/FMKCPU_ConfigPublic.h"
    #include "TypeCommon.h"
    // ********************************************************************
    // *                      Defines
    // ********************************************************************
    #define FMKCPU_PWM_MAX_DUTY_CYLCE ((t_uint16)1000) /**< Max duty cycle allowed */
    #define FMKCPU_PWM_MIN_DUTY_CYLCE ((t_uint16)0)    /**< Min dutyCycle allowed */
    // ********************************************************************
    // *                      Types
    // ********************************************************************
    //-----------------------------ENUM TYPES-----------------------------//
    /* CAUTION : Automatic generated code section for Enum: Start */

    /* CAUTION : Automatic generated code section for Enum: End */
    typedef enum
    {
        FMKCPU_CHNLPOLARITY_LOW = 0x0U,
        FMKCPU_CHNLPOLARITY_HIGH,

        FMKCPU_CHNLPOLARITY_NB
    } t_eFMKCPU_ChnlPolarity;

    typedef enum
    {
        FMKCPU_CHNLST_ACTIVATED= 0x0U,
        FMKCPU_CHNLST_DISACTIVATED,

        FMKCPU_CHNLST_NB
    } t_eFMKCPU_ChnlState;

    typedef enum 
    {
        FMKCPU_CNHL_RUNMODE_POLLING = 0x0U,
        FMKCPU_CNHL_RUNMODE_INTERRUPT,

        FMKCPU_CNHL_RUNMODE_NB
    } t_eFMKCPU_ChnlRunMode; 

    typedef enum 
    {
        FMKCPU_CLOCKPORT_OPE_ENABLE = 0x0U,
        FMKCPU_CLOCKPORT_OPE_DISABLE,

        FMKCPU_CLOCKPORT_OPE_NB
    } t_eFMKCPU_ClockPortOpe;

    typedef enum 
    {
        FMKCPU_NVIC_OPE_ENABLE = 0x0U,
        FMKCPU_NVIC_OPE_DISABLE,

        FMKCPU_NVIC_OPE_NB
    } t_eFMKCPU_NVIC_Ope;

    typedef enum 
    {
        FMKCPU_CHNL_MEAS_RISING_EDGE = 0x0U,
        FMKCPU_CHNL_MEAS_FALLING_EDGE,
        FMKCPU_CHNL_MEAS_BOTH_EDGE,

        FMKCPU_CHNL_MEAS_NB
    }t_eFMKCPU_ChnlMeasTrigger;

    //-----------------------------TYPEDEF TYPES---------------------------//
    /**
    *
    *	@brief
    *	@note   
    *
    *
    *	@param[in] 
    *	@param[out]
    *	 
    *
    *
    */
   typedef void (t_cbFMKCPU_InterruptChnl)(t_eFMKCPU_Timer f_timer_e, t_eFMKCPU_InterruptChnl f_channel_e);
    //-----------------------------STRUCT TYPES---------------------------//
    /* CAUTION : Automatic generated code section for Structure: Start */

    /* CAUTION : Automatic generated code section for Structure: End */
    
    // ********************************************************************
    // *                      Prototypes
    // ********************************************************************
        
    // ********************************************************************
    // *                      Variables
    // ********************************************************************
    


    //********************************************************************************
    //                      Public functions - Prototyupes
    //********************************************************************************
    /**
    *
    *	@brief      Perform all Init action for this module.\n
    *	@note       Set to default value all globals structure that
    *                store information for each signals.\n
    *
    */
    t_eReturnState FMKCPU_Init(void);
    /**
    *
    *	@brief      Perform all Cyclic action for this module.\n
    *	@note       In preOpe mode this module makes the configuration of the system clock and 
    *               watchdogs configuration.\n 
    *               In ope mode, this module makesdiag on timer channel currently used, and 
    *               called the appropriate callback if an error occured + call APPDEM
    *               to reference error.\n
    *
    */
    t_eReturnState FMKCPU_Cyclic(void);
    /**
    *
    *	@brief Function to know the module state.\n 
    *
    *	@param[in]  f_State_pe : store the value, value from @ref t_eCyclicFuncState
    *
    *   @retval RC_OK                             @ref RC_OK
    *   @retval RC_ERROR_PTR_NULL                 @ref RC_ERROR_PTR_NUL
    */
    t_eReturnState FMKCPU_GetState(t_eCyclicFuncState *f_State_pe);
    /**
    *
    *	@brief Function to update the module state.\n
    *
    *	@param[in]  f_State_e : the new value, value from @ref t_eCyclicFuncState
    *
    *   @retval RC_OK                             @ref RC_OK
    */
    t_eReturnState FMKCPU_SetState(t_eCyclicFuncState f_State_e);
    /**
    *
    *	@brief      Set the system clock configuration.\n
    *   @note       This function has to be first one to be call in the Software.\n
    *               Configure the Clocks used and the frequency for each clock.\n
    *
    *	@param[in]  f_State_pe : store the value, value from @ref t_eCyclicFuncState
    *
    *   @retval RC_OK                             @ref RC_OK
    *   @retval RC_ERROR_WRONG_STATE              @ref RC_ERROR_WRONG_STATE
    */
    t_eReturnState FMKCPU_Set_SysClockCfg(void);
    /**
    *
    *	@brief      Set a Delay.\n
    *
    *	@param[in]  f_delayms_u32 : period delay in millisecond.\n
    *
    */
    void FMKCPU_Set_Delay(t_uint32 f_delayms_u32);
    /**
    *
    *	@brief      Get a tick from clock freqency.\n
    *
    *	@param[in]  f_tickms_pu32 : store the tick value in millisecond.\n
    *
    *   @retval RC_OK                             @ref RC_OK
    *   @retval RC_ERROR_WRONG_STATE              @ref RC_ERROR_WRONG_STATE
    */
    t_eReturnState FMKCPU_Get_Tick(t_uint32 * f_tickms_pu32);
    /**
    *
    *	@brief      Set the priority for a NVIC and the state ON/OFF\n
    *   @note       This function is called to set the interruption priority
    *               for f_IRQN_e interruption.\n 
    *               If an interruption (2) occur while another Interruption (1) is running, 
    *               depending on the value of f_priority_e (2) will interruot or not
    *               the interruption (1).\n
    *               This function also disable the IRQN interruption if needed.\n
    *
    *	@param[in]  f_IRQN_e     : enum value for IRQN type, value from @ref t_eFMKCPU_IRQNType
    *	@param[in]  f_priority_e : enum value for priority, value from @ref t_eFMKCPU_NVICPriority
    *	@param[in]  f_OpeState_e : enum value for  pose state,value from @ref t_eFMKCPU_NVIC_Ope
    *
    *  @retval RC_OK                             @ref RC_OK
    *  @retval RC_ERROR_PARAM_INVALID            @ref RC_ERROR_PARAM_INVALID
    *  @retval RC_ERROR_PARAM_NOT_SUPPORTED      @ref RC_ERROR_PARAM_NOT_SUPPORTED
    */
    t_eReturnState FMKCPU_Set_NVICState(t_eFMKCPU_IRQNType f_IRQN_e, 
                                       t_eFMKCPU_NVICPriority f_priority_e, 
                                       t_eFMKCPU_NVIC_Ope f_OpeState_e);
    /**
    *
    *	@brief      Set the RCC clock state.\n
    *   @note       In order to write down bit in everry register (ADC,GPIO,TIM,etc),
    *               the RCC clock has to be enable first. This function enable or disable
    *               the RCC clock reference to f_clkPort_e.\n
    *              
    *
    *	@param[in]  f_clkPort_e     : enum value for RCC clock, value from @ref t_eFMKCPU_ClockPort
    *	@param[in]  f_OpeState_e    : enum value for priority, value from @ref t_eFMKCPU_NVICPriority
    *
    *  @retval RC_OK                             @ref RC_OK
    *  @retval RC_ERROR_PARAM_INVALID            @ref RC_ERROR_PARAM_INVALID
    *  @retval RC_ERROR_PARAM_NOT_SUPPORTED      @ref RC_ERROR_PARAM_NOT_SUPPORTED
    *  @retval RC_WARNING_NO_OPERATION           @ref RC_WARNING_NO_OPERATION
    */
    t_eReturnState FMKCPU_Set_HwClock(t_eFMKCPU_ClockPort f_clkPort_e, 
                                       t_eFMKCPU_ClockPortOpe f_OpeState_e);
    /**
    *
    *	@brief      Set the watchdog configuration.\n
    *   @note       Set the watchdogs configuration and active it imeddiately.\n              
    *
    *	@param[in]  f_period_e      : enum value for period before reset, value from @ref t_eFMKCPu_WwdgResetPeriod
    *
    *  @retval RC_OK                             @ref RC_OK
    *  @retval RC_ERROR_PARAM_INVALID            @ref RC_ERROR_PARAM_INVALID
    *  @retval RC_ERROR_WRONG_STATE              @ref RC_ERROR_WRONG_STATE
    */
    t_eReturnState FMKCPU_Set_WwdgCfg(t_eFMKCPu_WwdgResetPeriod f_period_e);
    /**
    *
    *	@brief      Reset the watchdogs coutner.\n
    *
    *  @retval RC_OK                             @ref RC_OK
    *  @retval RC_ERROR_WRONG_STATE              @ref RC_ERROR_WRONG_STATE
    */
    t_eReturnState FMKCPU_ResetWwdg(void);
    /**
    *
    *	@brief      Configure a timer channel in PWM configuration.\n
    *   @note       First, this configuration set the bsp timer cfg in PWM mode.\n
    *               Once it's done, this function configure the bsp channel in PWM mode too.\n
    *               IMPORTANT, the PWM generation is based on a timer configuration which share
    *               multiple channel, as so, frequency is shared by all PWM channel.\n
    *               In result, the modification of the timer configuration reverbate for all channels.\n          
    *
    *	@param[in]  f_timer_e              : enum value for the priority, value from @ref t_eFMKCPU_Timer
    *	@param[in]  f_channel_e            : enum value for the channel, value from @ref t_eFMKCPU_InterruptChnl
    *	@param[in]  f_pwmFreq_u32      : the frequency timer.
    *
    *  @retval RC_OK                             @ref RC_OK
    *  @retval RC_ERROR_PARAM_INVALID            @ref RC_ERROR_PARAM_INVALID
    *  @retval RC_ERROR_WRONG_STATE              @ref RC_ERROR_WRONG_STATE
    *  @retval RC_ERROR_WRONG_RESULT             @ref RC_ERROR_WRONG_RESULT
    */
    t_eReturnState FMKCPU_Set_PWMChannelCfg(t_eFMKCPU_Timer f_timer_e,
                                            t_eFMKCPU_InterruptChnl f_channel_e,
                                            t_uint32 f_pwmFreq_u32);
    /**
    *
    *	@brief    Set the DutyCycle to a timer channel
    *   @note     Modify the CCRx register to change the dutyCycle.\n
    *             If the timer channel is disable, and the value is diferrent from 0,
    *             this function will enable the channel and set dutycycle give by f_dutyCycle_u16.\n
    *             If the value equals 0 this function will stop the PWM pulse (channel).\n 
    *
    *	@param[in]  f_timer_e              : enum value for the priority, value from @ref t_eFMKCPU_Timer
    *	@param[in]  f_channel_e            : enum value for the channel, value from @ref t_eFMKCPU_InterruptChnl
    *	@param[in]  f_dutyCycle_u16        : the dutycyle, value from [0, 1000]
    *
    *  @retval RC_OK                             @ref RC_OK
    *  @retval RC_ERROR_PARAM_INVALID            @ref RC_ERROR_PARAM_INVALID
    *  @retval RC_ERROR_ALREADY_CONFIGURED           @ref RC_ERROR_ALREADY_CONFIGURED
    *  @retval RC_WARNING_NO_OPERATION           @ref RC_WARNING_NO_OPERATION
    */
    t_eReturnState FMKCPU_Set_PWMChannelDuty(t_eFMKCPU_Timer f_timer_e, 
                                             t_eFMKCPU_InterruptChnl f_channel_e,
                                             t_uint16 f_dutyCycle_u16);
    /**
    *
    *	@brief    Get the DutyCycle from a timer channel
    *   @note     Get the value from CCRx register and convert it in dutycycle
    *
    *	@param[in]  f_timer_e              : enum value for the priority, value from @ref t_eFMKCPU_Timer
    *	@param[in]  f_channel_e            : enum value for the channel, value from @ref t_eFMKCPU_InterruptChnl
    *	@param[in]  f_dutyCycle_u16        : the dutycyle, value from [0, 1000]
    *
    *  @retval RC_OK                             @ref RC_OK
    *  @retval RC_ERROR_PTR_NULL                 @ref RC_ERROR_PTR_NULL
    *  @retval RC_ERROR_PARAM_INVALID            @ref RC_ERROR_PARAM_INVALID
    *  @retval RC_ERROR_ALREADY_CONFIGURED           @ref RC_ERROR_ALREADY_CONFIGURED
    *  @retval RC_WARNING_NO_OPERATION           @ref RC_WARNING_NO_OPERATION
    */
    t_eReturnState FMKCPU_Get_PWMChannelDuty(t_eFMKCPU_Timer f_timer_e, 
                                             t_eFMKCPU_InterruptChnl f_channel_e,
                                             t_uint16 *f_dutyCycle_u16);
    /**
    *
    *	@brief    Set a timer channel in Input Compare configuration.\n
    *   @note     The IC Timer configuration is used to measure a signal frequency.\n
    *             This function initialize the timer in Input Compare confgiuration if the
    *             timer is not configured yet.\n
    *             Once the timer is init correctly, this function set f_channel_e configuration
    *             based on the interrupt mode gives by f_MeasTrigger_e.\n
    *             Finally, if the CPU detect the event, it will call the function f_ITChannel_cb.\n
    *
    *	@param[in]  f_timer_e              : enum value for the priority, value from @ref t_eFMKCPU_Timer
    *	@param[in]  f_channel_e            : enum value for the channel, value from @ref t_eFMKCPU_InterruptChnl
    *	@param[in]  f_MeasTrigger_e        : trigger for interruption, value from @ref t_eFMKCPU_ChnlMeasTrigger
    *	@param[in]  f_ITChannel_cb         : call back function to call
    *
    *  @retval RC_OK                             @ref RC_OK
    *  @retval RC_ERROR_PTR_NULL                 @ref RC_ERROR_PTR_NULL
    *  @retval RC_ERROR_PARAM_INVALID            @ref RC_ERROR_PARAM_INVALID
    *  @retval RC_ERROR_ALREADY_CONFIGURED       @ref RC_ERROR_ALREADY_CONFIGURED
    *  @retval RC_ERROR_NOT_ALLOWED              @ref RC_ERROR_NOT_ALLOWED
    */
    t_eReturnState FMKCPU_Set_ICChannelCfg(t_eFMKCPU_Timer f_timer_e,
                                         t_eFMKCPU_InterruptChnl f_channel_e, 
                                         t_eFMKCPU_ChnlMeasTrigger f_MeasTrigger_e,
                                         t_cbFMKCPU_InterruptChnl f_ITChannel_cb);
    /**
    *
    *	@brief    Set a timer channel on event configuration.\n
    *   @note     This function initialize the timer in event configuration if the
    *             timer is not configured yet.\n
    *             Once the timer configure is done, update the channel state using function 
    *             "FMKCPU_Set_ChannelState" and every f_periodms_u32 callback function is called.\n
    *             IMPORTANT, in event configuration, this the timer and not the channel who manage 
    *             the interruption, which means it is better to choose timer whith only one channel 
    *             to eventTimer configuration in FMKCPU_ConfigPrivate
    *
    *	@param[in]  f_evntChannel_e           : enum value for event channel, value from @ref t_eFMKCPU_EventChannel
    *	@param[in]  f_periodms_u32            : period before calling function, in millisecond
    *	@param[in]  f_ITChannel_cb            : callback function to call
    *
    *  @retval RC_OK                             @ref RC_OK
    *  @retval RC_ERROR_PTR_NULL                 @ref RC_ERROR_PTR_NULL
    *  @retval RC_ERROR_PARAM_INVALID            @ref RC_ERROR_PARAM_INVALID
    *  @retval RC_ERROR_ALREADY_CONFIGURED       @ref RC_ERROR_ALREADY_CONFIGURED
    *  @retval RC_ERROR_NOT_ALLOWED              @ref RC_ERROR_NOT_ALLOWED
    */
    t_eReturnState FMKCPU_Set_EvntChannelCfg(t_eFMKCPU_EventChannel f_evntChannel_e, 
                                             t_uint32 f_periodms_u32,
                                             t_cbFMKCPU_InterruptChnl f_ITChannel_cb);
    /**
    *
    *	@brief      Add a callback function to a timer channel.\n
    *   @note       For the configuration where the callback is optionnal (PWM, OP,etc)
    *               This function allow to add a callback. 
    *               On PWM -> callback will be call whenever the PWM pulse generation (not implemented yet) is done 
    *               On OnePulse -> Not implemented
    *           
    *
    *	@param[in]  f_timer_e              : enum value for the priority, value from @ref t_eFMKCPU_Timer
    *	@param[in]  f_channel_e            : enum value for the channel, value from @ref t_eFMKCPU_InterruptChnl
    *	@param[in]  f_pwmFreq_u32      : the frequency timer.
    *
    *  @retval RC_OK                             @ref RC_OK
    *  @retval RC_ERROR_PARAM_INVALID            @ref RC_ERROR_PARAM_INVALID
    *  @retval RC_ERROR_WRONG_STATE              @ref RC_ERROR_WRONG_STATE
    */
    t_eReturnState FMKCPU_AddTimerChnlCallback(t_eFMKCPU_Timer f_timer_e, 
                                             t_eFMKCPU_InterruptChnl f_channel_e,
                                             t_cbFMKCPU_InterruptChnl *f_ITChannel_cb);
    /**
    *
    *	@brief      Set a timer-channel state ON/OFF.\n
    *   @note       Using HAL_TIM function 
    *           
    *
    *	@param[in]  f_timer_e              : enum value for the timer, value from @ref t_eFMKCPU_Timer
    *	@param[in]  f_channel_e            : enum value for the channel, value from @ref t_eFMKCPU_InterruptChnl
    *	@param[in]  f_channelState_e       : enum value for the state operation, value from @ref t_eFMKCPU_ChnlState
    *
    *  @retval RC_OK                             @ref RC_OK
    *  @retval RC_ERROR_PARAM_INVALID            @ref RC_ERROR_PARAM_INVALID
    *  @retval RC_ERROR_WRONG_STATE              @ref RC_ERROR_WRONG_STATE
    */
    t_eReturnState FMKCPU_Set_ChannelState(t_eFMKCPU_Timer f_timer_e, 
                                           t_eFMKCPU_InterruptChnl f_channel_e,
                                           t_eFMKCPU_ChnlState f_channelState_e);

#endif // FMKCPU_H_INCLUDED           
//************************************************************************************
// End of File
//************************************************************************************

/**
 *
 *	@brief
 *	@note   
 *
 *
 *	@param[in] 
 *	@param[out]
 *	 
 *
 *
 */
