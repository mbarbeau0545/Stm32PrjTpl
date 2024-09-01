/*********************************************************************
 * @file        FMK_IO.h
 * @brief       Template_BriefDescription.
 * @details     TemplateDetailsDescription.\n
 *
 * @author      xxxxxx
 * @date        jj/mm/yyyy
 * @version     1.0
 */
  
#ifndef FMKIO_H_INCLUDED
#define FMKIO_H_INCLUDED





    // ********************************************************************
    // *                      Includes
    // ********************************************************************
    #include "TypeCommon.h"
    #include "FMK_CFG/FMKCFG_ConfigFiles/FMKIO_ConfigPublic.h"
    // ********************************************************************
    // *                      Defines
    // ********************************************************************

    // ********************************************************************
    // *                      Types
    // ********************************************************************
        //-----------------------------ENUM TYPES-----------------------------//
    /* CAUTION : Automatic generated code section for Enum: Start */

    /* CAUTION : Automatic generated code section for Enum: End */
    typedef enum 
    {
        FMKIO_PULL_MODE_UNABLE = 0,
        FMKIO_PULL_MODE_DOWN,
        FMKIO_PULL_MODE_UP,

        FMKIO_PULL_MODE_NB
    } t_eFMKIO_PullMode;

    typedef enum
    {
        FMKIO_SPD_MODE_LOW = 0,
        FMKIO_SPD_MODE_MEDIUM,
        FMKIO_SPD_MODE_HIGH,

        FMKIO_SPD_MODE_NB,
    } t_eFMKIO_SpdMode; 

    typedef enum
    {
        FMKIO_STC_RISING_EDGE = 0,
        FMKIO_STC_FALLING_EDGE,
        FMKIO_STC_BOTH_EDGE,

        FMKIO_STC_NB,
    } t_eFMKIO_SigTrigCptr;

    typedef enum 
    {
        FMKIO_SIGTYPE_INPUT_DIG = 0,
        FMKIO_SIGTYPE_INPUT_FREQ,
        FMKIO_SIGTYPE_INPUT_ANA,
        FMKIO_SIGTYPE_INPUT_EVNT,
        FMKIO_SIGTYPE_OUTPUT_DIG,
        FMKIO_SIGTYPE_OUTPUT_PWM,

        FMKIO_SIGTYPE_OUTPUT_NB,
    } t_eFMKIO_SigType;
    typedef enum 
    {
        FMKIO_DIG_VALUE_LOW = 0,
        FMKIO_DIG_VALUE_HIGH,

        FMKIO_DIG_VALUE_NB
    } t_eFMKIO_DigValue;
    //-----------------------------TYPEDEF TYPES---------------------------//
    typedef t_eReturnState (t_cbFMKIO_EventFunc)(void);
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
    t_eReturnState FMKIO_Init(void);
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
    t_eReturnState FMKIO_Cyclic(void);
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
    t_eReturnState FMKIO_Set_InDigSigCfg(t_eFMKIO_InDigSig f_signal_e, t_eFMKIO_PullMode f_pull_e);
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
    t_eReturnState FMKIO_Set_InAnaSigCfg(t_eFMKIO_InAnaSig f_signal_e, t_eFMKIO_PullMode f_pull_e);
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
    t_eReturnState FMKIO_Set_InFreqSigCfg(t_eFMKIO_InFreqSig f_signal_e);
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
    t_eReturnState FMKIO_Set_OutPwmSigCfg(t_eFMKIO_OutPwmSig f_signal_e, 
                                          t_eFMKIO_PullMode  f_pull_e,
                                          t_uint32           f_frequency_u32,
                                          t_uint16           f_dutyCycle_u16,
                                          t_bool             f_startNow_b);
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
    t_eReturnState FMKIO_Set_OutDigSigCfg(t_eFMKIO_OutDigSig f_signal_e, 
                                          t_eFMKIO_PullMode  f_pull_e,
                                          t_eFMKIO_SpdMode   f_spd_e);
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
    t_eReturnState FMKIO_Set_InEvntSigCfg(t_eFMKIO_InEvntSig f_signal_e, 
                                          t_eFMKIO_PullMode f_pull_e,
                                          t_eFMKIO_SigTrigCptr f_trigger_e,
                                          t_cbFMKIO_EventFunc * f_Evnt_cb);
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
    t_eReturnState FMKIO_Set_OutPwmSigValue(t_eFMKIO_OutPwmSig f_signal_e, t_uint16 f_dutyCycle_u16);
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
    t_eReturnState FMKIO_Set_OutDigSigValue(t_eFMKIO_OutDigSig f_signal_e, t_eFMKIO_DigValue f_value_e);
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
    t_eReturnState FMKIO_Get_InDigSigValue(t_eFMKIO_InDigSig f_signal_e, t_eFMKIO_DigValue *f_value_pe);
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
    t_eReturnState FMKIO_Get_InAnaSigValue(t_eFMKIO_InAnaSig f_signal_e, t_uint16 *f_value_pu16);
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
    t_eReturnState FMKIO_Get_InFreqSigValue(t_eFMKIO_InFreqSig f_signal_e, t_uint32 *f_value_pu32);
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
    t_eReturnState FMKIO_Get_OutPwmSigValue(t_eFMKIO_OutPwmSig f_signal_e, t_uint16 *f_value_pu16);
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
    t_eReturnState FMKIO_Get_OutDigSigValue(t_eFMKIO_OutDigSig f_signal_e, t_eFMKIO_DigValue *f_value_pe);
#endif // FMKIO_H_INCLUDED           
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
