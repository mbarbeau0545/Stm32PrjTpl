/*********************************************************************
 * @file        FMKCIO_ConfigPrivate.h
 * @brief       Template_BriefDescription.
 * @details     TemplateDetailsDescription.\n
 *
 * @author      xxxxxx
 * @date        jj/mm/yyyy
 * @version     1.0
 */
  
#ifndef FMKIO_CONFIGPRIVATE_H_INCLUDED
#define FMKIO_CONFIGPRIVATE_H_INCLUDED





    // ********************************************************************
    // *                      Includes
    // ********************************************************************
    #include "TypeCommon.h"
    #include "./FMKIO_ConfigPublic.h"
    #include "./FMKCDA_ConfigPublic.h"
    // ********************************************************************
    // *                      Defines
    // ********************************************************************

    // ********************************************************************
    // *                      Types
    // ********************************************************************
    //-----------------------------ENUM TYPES-----------------------------//
    /* CAUTION : Automatic generated code section for Enum: Start */

    /* CAUTION : Automatic generated code section for Enum: End */
    // Flag automatic generate code

    //-----------------------------TYPEDEF TYPES---------------------------//
    //-----------------------------STRUCT TYPES---------------------------//
    /* CAUTION : Automatic generated code section for Structure: Start */

    /* CAUTION : Automatic generated code section for Structure: End */
    typedef struct 
    {
        t_eFMKCDA_Adc        adc_e;
        t_eFMKCDA_AdcChannel adcChannel_e;
    }t_sFMKIO_AnaAdcCfg;
    // ********************************************************************
    // *                      Prototypes
    // ********************************************************************
        
    // ********************************************************************
    // *                      Variables
    // ********************************************************************
    const t_uint32 c_BspPinMapping_ua32[FMKIO_GPIO_PIN_NB] = {
        GPIO_PIN_0, 
        GPIO_PIN_1, 
        GPIO_PIN_2, 
        GPIO_PIN_3, 
        GPIO_PIN_4, 
        GPIO_PIN_5, 
        GPIO_PIN_6, 
        GPIO_PIN_7, 
        GPIO_PIN_8, 
        GPIO_PIN_9, 
        GPIO_PIN_10,
        GPIO_PIN_11,
        GPIO_PIN_12,
        GPIO_PIN_13,
        GPIO_PIN_14,
        GPIO_PIN_15,
    };
    
    // Flag automatic generate code 
    const t_sFMKIO_BspSigCfg c_InAnaSigBspMap_as[FMKIO_INPUT_SIGANA_NB] = {
        {FMKIO_GPIO_PORT_A            , FMKIO_GPIO_PIN_0},
        {FMKIO_GPIO_PORT_A            , FMKIO_GPIO_PIN_0},
        {FMKIO_GPIO_PORT_A            , FMKIO_GPIO_PIN_0},
        {FMKIO_GPIO_PORT_A            , FMKIO_GPIO_PIN_0},
        {FMKIO_GPIO_PORT_A            , FMKIO_GPIO_PIN_0},
        {FMKIO_GPIO_PORT_A            , FMKIO_GPIO_PIN_0},
        {FMKIO_GPIO_PORT_A            , FMKIO_GPIO_PIN_0},
        {FMKIO_GPIO_PORT_A            , FMKIO_GPIO_PIN_0},
        {FMKIO_GPIO_PORT_A            , FMKIO_GPIO_PIN_0},
        {FMKIO_GPIO_PORT_A            , FMKIO_GPIO_PIN_0},
    };
    const t_sFMKIO_AnaAdcCfg c_InAnaSigAdcCfg_ae[FMKIO_INPUT_SIGANA_NB] = {
        {FMKCDA_ADC_1, FMKCDA_ADC_CHANNEL_0},//FMKIO_INPUT_SIGANA_1
        {FMKCDA_ADC_1, FMKCDA_ADC_CHANNEL_1},//FMKIO_INPUT_SIGANA_2
        {FMKCDA_ADC_1, FMKCDA_ADC_CHANNEL_2},//FMKIO_INPUT_SIGANA_3
        {FMKCDA_ADC_1, FMKCDA_ADC_CHANNEL_3},//FMKIO_INPUT_SIGANA_4
        {FMKCDA_ADC_1, FMKCDA_ADC_CHANNEL_4},//FMKIO_INPUT_SIGANA_5
        {FMKCDA_ADC_1, FMKCDA_ADC_CHANNEL_5},//FMKIO_INPUT_SIGANA_6
        {FMKCDA_ADC_1, FMKCDA_ADC_CHANNEL_6},//FMKIO_INPUT_SIGANA_7
        {FMKCDA_ADC_1, FMKCDA_ADC_CHANNEL_7},//FMKIO_INPUT_SIGANA_8
        {FMKCDA_ADC_1, FMKCDA_ADC_CHANNEL_8},//FMKIO_INPUT_SIGANA_9
        {FMKCDA_ADC_1, FMKCDA_ADC_CHANNEL_9},//FMKIO_INPUT_SIGANA_10
    };
    const t_sFMKIO_BspSigCfg c_InDigSigBspMap_as[FMKIO_INPUT_SIGDIG_NB] = {
        {FMKIO_GPIO_PORT_A            , FMKIO_GPIO_PIN_0},
        {FMKIO_GPIO_PORT_A            , FMKIO_GPIO_PIN_0},
        {FMKIO_GPIO_PORT_A            , FMKIO_GPIO_PIN_0},
        {FMKIO_GPIO_PORT_A            , FMKIO_GPIO_PIN_0},
        {FMKIO_GPIO_PORT_A            , FMKIO_GPIO_PIN_0},
        {FMKIO_GPIO_PORT_A            , FMKIO_GPIO_PIN_0},
        {FMKIO_GPIO_PORT_A            , FMKIO_GPIO_PIN_0},
        {FMKIO_GPIO_PORT_A            , FMKIO_GPIO_PIN_0},
        {FMKIO_GPIO_PORT_A            , FMKIO_GPIO_PIN_0},
        {FMKIO_GPIO_PORT_A            , FMKIO_GPIO_PIN_0},
        {FMKIO_GPIO_PORT_A            , FMKIO_GPIO_PIN_0},
        {FMKIO_GPIO_PORT_A            , FMKIO_GPIO_PIN_0},
    };
    const t_sFMKIO_BspSigCfg c_OutDigSigBspMap_as[FMKIO_OUTPUT_SIGDIG_NB] = {
        {FMKIO_GPIO_PORT_A            , FMKIO_GPIO_PIN_0},
        {FMKIO_GPIO_PORT_A            , FMKIO_GPIO_PIN_0},
        {FMKIO_GPIO_PORT_A            , FMKIO_GPIO_PIN_0},
        {FMKIO_GPIO_PORT_A            , FMKIO_GPIO_PIN_0},
        {FMKIO_GPIO_PORT_A            , FMKIO_GPIO_PIN_0},
        {FMKIO_GPIO_PORT_A            , FMKIO_GPIO_PIN_0},
        {FMKIO_GPIO_PORT_A            , FMKIO_GPIO_PIN_0},
        {FMKIO_GPIO_PORT_A            , FMKIO_GPIO_PIN_0},
        {FMKIO_GPIO_PORT_A            , FMKIO_GPIO_PIN_0},
        {FMKIO_GPIO_PORT_A            , FMKIO_GPIO_PIN_0},
        {FMKIO_GPIO_PORT_A            , FMKIO_GPIO_PIN_0},
        {FMKIO_GPIO_PORT_A            , FMKIO_GPIO_PIN_0},
    };
    const t_sFMKIO_BspTimerSigCfg c_InFreqSigBspMap_as[FMKIO_INPUT_SIGFREQ_NB] = {
        {{FMKIO_GPIO_PORT_A            , FMKIO_GPIO_PIN_0},     GPIO_AF0_TIM14    ,FMKCPU_TIMER_14,   FMKCPU_CHANNEL_1},
        {{FMKIO_GPIO_PORT_A            , FMKIO_GPIO_PIN_0},     GPIO_AF0_TIM15    ,FMKCPU_TIMER_14,   FMKCPU_CHANNEL_1},
        {{FMKIO_GPIO_PORT_A            , FMKIO_GPIO_PIN_0},     GPIO_AF0_TIM15    ,FMKCPU_TIMER_14,   FMKCPU_CHANNEL_2},
       
    };
    
    const t_sFMKIO_BspTimerSigCfg c_OutPwmSigBspMap_as[FMKIO_OUTPUT_SIGPWM_NB] = {
        {{FMKIO_GPIO_PORT_A            , FMKIO_GPIO_PIN_0},     GPIO_AF2_TIM1    ,FMKCPU_TIMER_1,   FMKCPU_CHANNEL_1},
        {{FMKIO_GPIO_PORT_A            , FMKIO_GPIO_PIN_0},     GPIO_AF2_TIM1    ,FMKCPU_TIMER_1,   FMKCPU_CHANNEL_2},
        {{FMKIO_GPIO_PORT_A            , FMKIO_GPIO_PIN_0},     GPIO_AF2_TIM1    ,FMKCPU_TIMER_1,   FMKCPU_CHANNEL_3},
        {{FMKIO_GPIO_PORT_A            , FMKIO_GPIO_PIN_0},     GPIO_AF1_TIM3    ,FMKCPU_TIMER_3,   FMKCPU_CHANNEL_1},
        {{FMKIO_GPIO_PORT_A            , FMKIO_GPIO_PIN_0},     GPIO_AF1_TIM3    ,FMKCPU_TIMER_3,   FMKCPU_CHANNEL_2},
        {{FMKIO_GPIO_PORT_A            , FMKIO_GPIO_PIN_0},     GPIO_AF1_TIM3    ,FMKCPU_TIMER_3,   FMKCPU_CHANNEL_3},
        {{FMKIO_GPIO_PORT_A            , FMKIO_GPIO_PIN_0},     GPIO_AF1_TIM3    ,FMKCPU_TIMER_3,   FMKCPU_CHANNEL_4},
       
    };

    const t_sFMKIO_BspEvntSigCfg c_InEvntSigBspMap_as[FMKIO_INPUT_SIGEVNT_NB] = {
        {{FMKIO_GPIO_PORT_A            , FMKIO_GPIO_PIN_0},     GPIO_AF2_TIM16, EXTI0_1_IRQn},
        {{FMKIO_GPIO_PORT_A            , FMKIO_GPIO_PIN_0},     GPIO_AF0_TIM17, EXTI2_3_IRQn},
       
    };

    

    //********************************************************************************
    //                      Public functions - Prototyupes
    //********************************************************************************

#endif // FMKIO_CONFIGPRIVATE_H_INCLUDED           
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
