/*********************************************************************
 * @file        FMK_CPU.h
 * @brief       Template_BriefDescription.
 * @details     TemplateDetailsDescription.\n
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
    #define FMKCPU_PWM_MAX_DUTY_CYLCE ((t_uint16)1000)
    #define FMKCPU_PWM_MIN_DUTY_CYLCE ((t_uint16)0)
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
    *	@details
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
    t_eReturnState FMKCPU_Set_NVICState(t_eFMKCPU_IRQNType f_IRQN_e, 
                                       t_eFMKCPU_NVICPriority f_priority_e, 
                                       t_eFMKCPU_NVIC_Ope f_OpeState_e);
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
    t_eReturnState FMKCPU_Set_HwClock(t_eFMKCPU_ClockPort f_clkPort_e, 
                                       t_eFMKCPU_ClockPortOpe f_OpeState_e);
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
    t_eReturnState FMKCPU_Set_WWDGChannelCfg(void);
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
    t_eReturnState FMKCPU_Set_PWMChannelCfg(t_sFMKCPU_BspTimerCfg f_bspCfg_s);
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
    t_eReturnState FMKCPU_Set_PWMChannelDuty(t_eFMKCPU_Timer f_timer_e, 
                                             t_eFMKCPU_InterruptChnl f_channel_e,
                                             t_uint16 f_dutyCycle_u16);
    /*****************************************************************************
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
    t_eReturnState FMKCPU_Get_PWMChannelDuty(t_eFMKCPU_Timer f_timer_e, 
                                             t_eFMKCPU_InterruptChnl f_channel_e,
                                             t_uint16 *f_dutyCycle_u16);
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
    t_eReturnState FMKCPU_Set_ICChannelCfg(t_sFMKCPU_BspTimerCfg f_bspCfg_s, t_eFMKCPU_ChnlMeasTrigger f_MeasTrigger_e);
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
    t_eReturnState FMKCPU_Set_EvntChannelCfg(t_eFMKCPU_EventChannel f_evntChannel_e, 
                                             t_uint32 f_periodms_u32,
                                             t_cbFMKCPU_InterruptChnl f_ITChannel_cb);
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
    t_eReturnState FMKCPU_AddTimerChnlCallback(t_eFMKCPU_Timer f_timer_e, 
                                             t_eFMKCPU_InterruptChnl f_channel_e,
                                             t_cbFMKCPU_InterruptChnl *f_ITChannel_cb);
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
 *	@details
 *
 *
 *	@param[in] 
 *	@param[out]
 *	 
 *
 *
 */
