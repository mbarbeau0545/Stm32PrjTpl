/*********************************************************************
 * @file        FMKCIO_ConfigPrivate.h
 * @brief       Template_BriefDescription.
 * @note        TemplateDetailsDescription.\n
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

    /**< Structure for Analog signal adc configuration */
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
    // Flag automatic generate code 
    /**< Variable for bsp/ enum pin mapping */
    const t_uint32 c_BspPinMapping_ua32[FMKIO_GPIO_PIN_NB] = {
        GPIO_PIN_0,         // FMKIO_GPIO_PIN_0
        GPIO_PIN_1,         // FMKIO_GPIO_PIN_1
        GPIO_PIN_2,         // FMKIO_GPIO_PIN_2
        GPIO_PIN_3,         // FMKIO_GPIO_PIN_3
        GPIO_PIN_4,         // FMKIO_GPIO_PIN_4
        GPIO_PIN_5,         // FMKIO_GPIO_PIN_5
        GPIO_PIN_6,         // FMKIO_GPIO_PIN_6
        GPIO_PIN_7,         // FMKIO_GPIO_PIN_7
        GPIO_PIN_8,         // FMKIO_GPIO_PIN_8
        GPIO_PIN_9,         // FMKIO_GPIO_PIN_9
        GPIO_PIN_10,        // FMKIO_GPIO_PIN_10
        GPIO_PIN_11,        // FMKIO_GPIO_PIN_11
        GPIO_PIN_12,        // FMKIO_GPIO_PIN_12
        GPIO_PIN_13,        // FMKIO_GPIO_PIN_13
        GPIO_PIN_14,        // FMKIO_GPIO_PIN_14
        GPIO_PIN_15,        // FMKIO_GPIO_PIN_15
    };
    
    // Flag automatic generate code 
    /**< Variable for bsp_Gpio_Pin Analog input signal mapping */
    const t_sFMKIO_BspSigCfg c_InAnaSigBspMap_as[FMKIO_INPUT_SIGANA_NB] = {
        {FMKIO_GPIO_PORT_C            , FMKIO_GPIO_PIN_0},      // FMKIO_INPUT_SIGANA_1
        {FMKIO_GPIO_PORT_C            , FMKIO_GPIO_PIN_1},      // FMKIO_INPUT_SIGANA_2
        {FMKIO_GPIO_PORT_C            , FMKIO_GPIO_PIN_2},      // FMKIO_INPUT_SIGANA_3
        {FMKIO_GPIO_PORT_C            , FMKIO_GPIO_PIN_3},      // FMKIO_INPUT_SIGANA_4
        {FMKIO_GPIO_PORT_C            , FMKIO_GPIO_PIN_4},      // FMKIO_INPUT_SIGANA_5
        {FMKIO_GPIO_PORT_C            , FMKIO_GPIO_PIN_5},      // FMKIO_INPUT_SIGANA_6
        {FMKIO_GPIO_PORT_A            , FMKIO_GPIO_PIN_0},      // FMKIO_INPUT_SIGANA_7
        {FMKIO_GPIO_PORT_A            , FMKIO_GPIO_PIN_4},      // FMKIO_INPUT_SIGANA_8
        {FMKIO_GPIO_PORT_B            , FMKIO_GPIO_PIN_0},      // FMKIO_INPUT_SIGANA_9
        {FMKIO_GPIO_PORT_B            , FMKIO_GPIO_PIN_1},      // FMKIO_INPUT_SIGANA_10
    };
    // Flag automatic generate code 
    /**< Variable for adc_channel Analog signal mapping */
    const t_sFMKIO_AnaAdcCfg c_InAnaSigAdcCfg_ae[FMKIO_INPUT_SIGANA_NB] = {
        {FMKCDA_ADC_1, FMKCDA_ADC_CHANNEL_10},      //FMKIO_INPUT_SIGANA_1
        {FMKCDA_ADC_1, FMKCDA_ADC_CHANNEL_11},      //FMKIO_INPUT_SIGANA_2
        {FMKCDA_ADC_1, FMKCDA_ADC_CHANNEL_12},      //FMKIO_INPUT_SIGANA_3
        {FMKCDA_ADC_1, FMKCDA_ADC_CHANNEL_13},      //FMKIO_INPUT_SIGANA_4
        {FMKCDA_ADC_1, FMKCDA_ADC_CHANNEL_14},      //FMKIO_INPUT_SIGANA_5
        {FMKCDA_ADC_1, FMKCDA_ADC_CHANNEL_15},      //FMKIO_INPUT_SIGANA_6
        {FMKCDA_ADC_1, FMKCDA_ADC_CHANNEL_0},       //FMKIO_INPUT_SIGANA_7
        {FMKCDA_ADC_1, FMKCDA_ADC_CHANNEL_4},       //FMKIO_INPUT_SIGANA_8
        {FMKCDA_ADC_1, FMKCDA_ADC_CHANNEL_8},       //FMKIO_INPUT_SIGANA_9
        {FMKCDA_ADC_1, FMKCDA_ADC_CHANNEL_9},       //FMKIO_INPUT_SIGANA_10
    };
    // Flag automatic generate code 
    /**< Variable for bsp_Gpio_Pin Digital input signal mapping */
    const t_sFMKIO_BspSigCfg c_InDigSigBspMap_as[FMKIO_INPUT_SIGDIG_NB] = {
        {FMKIO_GPIO_PORT_C            , FMKIO_GPIO_PIN_13},     // FMKIO_INPUT_SIGDIG_1
        {FMKIO_GPIO_PORT_A            , FMKIO_GPIO_PIN_0},      // FMKIO_INPUT_SIGDIG_2
        {FMKIO_GPIO_PORT_A            , FMKIO_GPIO_PIN_0},      // FMKIO_INPUT_SIGDIG_3
        {FMKIO_GPIO_PORT_A            , FMKIO_GPIO_PIN_0},      // FMKIO_INPUT_SIGDIG_4
        {FMKIO_GPIO_PORT_A            , FMKIO_GPIO_PIN_0},      // FMKIO_INPUT_SIGDIG_5
        {FMKIO_GPIO_PORT_A            , FMKIO_GPIO_PIN_0},      // FMKIO_INPUT_SIGDIG_6
        {FMKIO_GPIO_PORT_A            , FMKIO_GPIO_PIN_0},      // FMKIO_INPUT_SIGDIG_7
        {FMKIO_GPIO_PORT_A            , FMKIO_GPIO_PIN_0},      // FMKIO_INPUT_SIGDIG_8
        {FMKIO_GPIO_PORT_A            , FMKIO_GPIO_PIN_0},      // FMKIO_INPUT_SIGDIG_9
        {FMKIO_GPIO_PORT_A            , FMKIO_GPIO_PIN_0},      // FMKIO_INPUT_SIGDIG_10
        {FMKIO_GPIO_PORT_A            , FMKIO_GPIO_PIN_0},      // FMKIO_INPUT_SIGDIG_11
        {FMKIO_GPIO_PORT_A            , FMKIO_GPIO_PIN_0},      // FMKIO_INPUT_SIGDIG_12
    };
    // Flag automatic generate code 
    /**< Variable for bsp_Gpio_Pin Digital ouput signal mapping */
    const t_sFMKIO_BspSigCfg c_OutDigSigBspMap_as[FMKIO_OUTPUT_SIGDIG_NB] = {
        {FMKIO_GPIO_PORT_A            , FMKIO_GPIO_PIN_12},     // FMKIO_OUTPUT_SIGDIG_1
        {FMKIO_GPIO_PORT_A            , FMKIO_GPIO_PIN_13},     // FMKIO_OUTPUT_SIGDIG_2
        {FMKIO_GPIO_PORT_A            , FMKIO_GPIO_PIN_14},     // FMKIO_OUTPUT_SIGDIG_3
        {FMKIO_GPIO_PORT_A            , FMKIO_GPIO_PIN_15},     // FMKIO_OUTPUT_SIGDIG_4
        {FMKIO_GPIO_PORT_B            , FMKIO_GPIO_PIN_2},      // FMKIO_OUTPUT_SIGDIG_5
        {FMKIO_GPIO_PORT_B            , FMKIO_GPIO_PIN_3},      // FMKIO_OUTPUT_SIGDIG_6
        {FMKIO_GPIO_PORT_B            , FMKIO_GPIO_PIN_4},      // FMKIO_OUTPUT_SIGDIG_7
        {FMKIO_GPIO_PORT_B            , FMKIO_GPIO_PIN_5},      // FMKIO_OUTPUT_SIGDIG_8
        {FMKIO_GPIO_PORT_B            , FMKIO_GPIO_PIN_10},     // FMKIO_OUTPUT_SIGDIG_9
        {FMKIO_GPIO_PORT_B            , FMKIO_GPIO_PIN_11},     // FMKIO_OUTPUT_SIGDIG_10
        {FMKIO_GPIO_PORT_B            , FMKIO_GPIO_PIN_12},     // FMKIO_OUTPUT_SIGDIG_11
        {FMKIO_GPIO_PORT_B            , FMKIO_GPIO_PIN_13},     // FMKIO_OUTPUT_SIGDIG_12
        {FMKIO_GPIO_PORT_C            , FMKIO_GPIO_PIN_13},     // FMKIO_OUTPUT_SIGDIG_13
    };
    // Flag automatic generate code 
    /**< Variable for bsp_Gpio_Pin frequency input signal mapping */
    const t_sFMKIO_BspTimerSigCfg c_InFreqSigBspMap_as[FMKIO_INPUT_SIGFREQ_NB] = {
        {{FMKIO_GPIO_PORT_A            , FMKIO_GPIO_PIN_0},     GPIO_AF0_TIM14    ,FMKCPU_TIMER_14,   FMKCPU_CHANNEL_1}, // FMKIO_INPUT_SIGFREQ_1
        {{FMKIO_GPIO_PORT_A            , FMKIO_GPIO_PIN_0},     GPIO_AF0_TIM15    ,FMKCPU_TIMER_14,   FMKCPU_CHANNEL_1}, // FMKIO_INPUT_SIGFREQ_2
        {{FMKIO_GPIO_PORT_A            , FMKIO_GPIO_PIN_0},     GPIO_AF0_TIM15    ,FMKCPU_TIMER_14,   FMKCPU_CHANNEL_2}, // FMKIO_INPUT_SIGFREQ_3
       
    };
    // Flag automatic generate code 
    /**< Variable for bsp_Gpio_Pin PWM output signal mapping */
    const t_sFMKIO_BspTimerSigCfg c_OutPwmSigBspMap_as[FMKIO_OUTPUT_SIGPWM_NB] = {
        {{FMKIO_GPIO_PORT_A            , FMKIO_GPIO_PIN_8},     GPIO_AF0_MCO    ,FMKCPU_TIMER_1,   FMKCPU_CHANNEL_1}, // FMKIO_OUTPUT_SIGPWM_1
        {{FMKIO_GPIO_PORT_A            , FMKIO_GPIO_PIN_9},     GPIO_AF0_MCO    ,FMKCPU_TIMER_1,   FMKCPU_CHANNEL_2}, // FMKIO_OUTPUT_SIGPWM_2
        {{FMKIO_GPIO_PORT_A            , FMKIO_GPIO_PIN_10},    GPIO_AF0_MCO    ,FMKCPU_TIMER_1,   FMKCPU_CHANNEL_3}, // FMKIO_OUTPUT_SIGPWM_3
        {{FMKIO_GPIO_PORT_C            , FMKIO_GPIO_PIN_11},    GPIO_AF0_MCO    ,FMKCPU_TIMER_1,   FMKCPU_CHANNEL_4}, // FMKIO_OUTPUT_SIGPWM_4
        {{FMKIO_GPIO_PORT_C            , FMKIO_GPIO_PIN_6},     GPIO_AF0_MCO    ,FMKCPU_TIMER_3,   FMKCPU_CHANNEL_1}, // FMKIO_OUTPUT_SIGPWM_5
        {{FMKIO_GPIO_PORT_C            , FMKIO_GPIO_PIN_7},     GPIO_AF0_MCO    ,FMKCPU_TIMER_3,   FMKCPU_CHANNEL_2}, // FMKIO_OUTPUT_SIGPWM_6
        {{FMKIO_GPIO_PORT_C            , FMKIO_GPIO_PIN_8},     GPIO_AF0_MCO    ,FMKCPU_TIMER_3,   FMKCPU_CHANNEL_3}, // FMKIO_OUTPUT_SIGPWM_7
       
    };

    /**< Variable for bsp_Gpio_Pin event input signal mapping */
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
 *	@note   
 *
 *
 *	@params[in] 
 *	@params[out]
 *	 
 *
 *
 */
