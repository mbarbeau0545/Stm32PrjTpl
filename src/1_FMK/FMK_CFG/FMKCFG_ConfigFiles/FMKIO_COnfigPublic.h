/*********************************************************************
 * @file        FMKIO_ConfigPublic.h
 * @brief       Template_BriefDescription.
 * @details     TemplateDetailsDescription.\n
 *
 * @author      xxxxxx
 * @date        jj/mm/yyyy
 * @version     1.0
 */
  
#ifndef FMKIO_CONFIGPUBLIC_H_INCLUDED
#define FMKIO_CONFIGPUBLIC_H_INCLUDED





    // ********************************************************************
    // *                      Includes
    // ********************************************************************
    #include "TypeCommon.h"
    #include "FMK_HAL/FMK_CPU/Src/FMK_CPU.h"
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
    /* List of input digital pin available on this board*/
    typedef enum 
{
    FMKIO_INPUT_SIGDIG_1 = 0x00U,
    FMKIO_INPUT_SIGDIG_2,
    FMKIO_INPUT_SIGDIG_3,
    FMKIO_INPUT_SIGDIG_4,
    FMKIO_INPUT_SIGDIG_5,
    FMKIO_INPUT_SIGDIG_6,
    FMKIO_INPUT_SIGDIG_7,
    FMKIO_INPUT_SIGDIG_8,
    FMKIO_INPUT_SIGDIG_9,
    FMKIO_INPUT_SIGDIG_10,
    FMKIO_INPUT_SIGDIG_11,
    FMKIO_INPUT_SIGDIG_12,

    FMKIO_INPUT_SIGDIG_NB,
} t_eFMKIO_InDigSig;

    // Flag automatic generate code
    /* List of input Analog pin available on this board*/
   typedef enum 
    {
        FMKIO_INPUT_SIGANA_1 = 0x00U,
        FMKIO_INPUT_SIGANA_2,
        FMKIO_INPUT_SIGANA_3,
        FMKIO_INPUT_SIGANA_4,
        FMKIO_INPUT_SIGANA_5,
        FMKIO_INPUT_SIGANA_6,
        FMKIO_INPUT_SIGANA_7,
        FMKIO_INPUT_SIGANA_8,
        FMKIO_INPUT_SIGANA_9,
        FMKIO_INPUT_SIGANA_10,

        FMKIO_INPUT_SIGANA_NB,
    } t_eFMKIO_InAnaSig;

    // Flag automatic generate code
    /* List of input frequency pin available on this board*/
    typedef enum 
    {
        FMKIO_INPUT_SIGFREQ_1 = 0x00U,
        FMKIO_INPUT_SIGFREQ_2,
        FMKIO_INPUT_SIGFREQ_3,

        FMKIO_INPUT_SIGFREQ_NB,
    } t_eFMKIO_InFreqSig;

    // Flag automatic generate code
    /* List of input frequency pin available on this board*/
    typedef enum 
    {
        FMKIO_INPUT_SIGEVNT_1 = 0x00U,
        FMKIO_INPUT_SIGEVNT_2,

        FMKIO_INPUT_SIGEVNT_NB,
    } t_eFMKIO_InEvntSig;

    // Flag automatic generate code
    /* List of output pwm pin available on this board*/
    typedef enum 
    {
        FMKIO_OUTPUT_SIGPWM_1 = 0x00U,
        FMKIO_OUTPUT_SIGPWM_2,
        FMKIO_OUTPUT_SIGPWM_3,
        FMKIO_OUTPUT_SIGPWM_4,
        FMKIO_OUTPUT_SIGPWM_5,
        FMKIO_OUTPUT_SIGPWM_6,
        FMKIO_OUTPUT_SIGPWM_7,

        FMKIO_OUTPUT_SIGPWM_NB,
    } t_eFMKIO_OutPwmSig;

    // Flag automatic generate code
    /* List of output digital pin available on this board*/
    typedef enum 
    {
        FMKIO_OUTPUT_SIGDIG_1 = 0x00U,
        FMKIO_OUTPUT_SIGDIG_2,
        FMKIO_OUTPUT_SIGDIG_3,
        FMKIO_OUTPUT_SIGDIG_4,
        FMKIO_OUTPUT_SIGDIG_5,
        FMKIO_OUTPUT_SIGDIG_6,
        FMKIO_OUTPUT_SIGDIG_7,
        FMKIO_OUTPUT_SIGDIG_8,
        FMKIO_OUTPUT_SIGDIG_9,
        FMKIO_OUTPUT_SIGDIG_10,
        FMKIO_OUTPUT_SIGDIG_11,
        FMKIO_OUTPUT_SIGDIG_12,

        FMKIO_OUTPUT_SIGDIG_NB,
    } t_eFMKIO_OutDigSig;

    // Flag automatic generate code
    /* List of gpio port available on this board*/
    typedef enum
    {
        FMKIO_GPIO_PORT_A = 0x00U,
        FMKIO_GPIO_PORT_B,
        FMKIO_GPIO_PORT_C,
        FMKIO_GPIO_PORT_D,
        FMKIO_GPIO_PORT_F,

        FMKIO_GPIO_PORT_NB,
    } t_eFMKIO_GpioPort;

    // Flag automatic generate code
    /* List of Pin available for each GPIO on this board*/
    typedef enum
    {
        FMKIO_GPIO_PIN_0 = 0,
        FMKIO_GPIO_PIN_1,
        FMKIO_GPIO_PIN_2,
        FMKIO_GPIO_PIN_3,
        FMKIO_GPIO_PIN_4,
        FMKIO_GPIO_PIN_5,
        FMKIO_GPIO_PIN_6,
        FMKIO_GPIO_PIN_7,
        FMKIO_GPIO_PIN_8,
        FMKIO_GPIO_PIN_9,
        FMKIO_GPIO_PIN_10,
        FMKIO_GPIO_PIN_11,
        FMKIO_GPIO_PIN_12,
        FMKIO_GPIO_PIN_13,
        FMKIO_GPIO_PIN_14,
        FMKIO_GPIO_PIN_15,

        FMKIO_GPIO_PIN_NB, // Nombre total de broches, non inclus dans les broches valides
    } t_eFMKIO_BspGpioPin;

    // Flag automatic generate code
    /* List of Pin available for each GPIO on this board*/
    typedef enum
    {
        FMKIO_AF0_EVENTOUT = 0,  /*!< AF0: EVENTOUT Alternate Function mapping */
        FMKIO_AF0_MCO,           /*!< AF0: MCO Alternate Function mapping */
        FMKIO_AF0_SPI1,          /*!< AF0: SPI1 Alternate Function mapping */
        FMKIO_AF0_SPI2,          /*!< AF0: SPI2 Alternate Function mapping */
        FMKIO_AF0_TIM15,         /*!< AF0: TIM15 Alternate Function mapping */
        FMKIO_AF0_TIM17,         /*!< AF0: TIM17 Alternate Function mapping */
        FMKIO_AF0_SWDIO,         /*!< AF0: SWDIO Alternate Function mapping */
        FMKIO_AF0_SWCLK,         /*!< AF0: SWCLK Alternate Function mapping */
        FMKIO_AF0_TIM14,         /*!< AF0: TIM14 Alternate Function mapping */
        FMKIO_AF0_USART1,        /*!< AF0: USART1 Alternate Function mapping */
        FMKIO_AF0_IR,            /*!< AF0: IR Alternate Function mapping */
        FMKIO_AF0_TIM3,          /*!< AF0: TIM3 Alternate Function mapping */

        FMKIO_AF1_TIM3,          /*!< AF1: TIM3 Alternate Function mapping */
        FMKIO_AF1_TIM15,         /*!< AF1: TIM15 Alternate Function mapping */
        FMKIO_AF1_USART1,        /*!< AF1: USART1 Alternate Function mapping */
        FMKIO_AF1_USART2,        /*!< AF1: USART2 Alternate Function mapping */
        FMKIO_AF1_EVENTOUT,      /*!< AF1: EVENTOUT Alternate Function mapping */
        FMKIO_AF1_I2C1,          /*!< AF1: I2C1 Alternate Function mapping */
        FMKIO_AF1_I2C2,          /*!< AF1: I2C2 Alternate Function mapping */
        FMKIO_AF1_IR,            /*!< AF1: IR Alternate Function mapping */

        FMKIO_AF2_TIM1,          /*!< AF2: TIM1 Alternate Function mapping */
        FMKIO_AF2_TIM16,         /*!< AF2: TIM16 Alternate Function mapping */
        FMKIO_AF2_TIM17,         /*!< AF2: TIM17 Alternate Function mapping */
        FMKIO_AF2_EVENTOUT,      /*!< AF2: EVENTOUT Alternate Function mapping */

        FMKIO_AF3_EVENTOUT,      /*!< AF3: EVENTOUT Alternate Function mapping */
        FMKIO_AF3_I2C1,          /*!< AF3: I2C1 Alternate Function mapping */
        FMKIO_AF3_TIM15,         /*!< AF3: TIM15 Alternate Function mapping */

        FMKIO_AF4_TIM14,         /*!< AF4: TIM14 Alternate Function mapping */

        FMKIO_AF5_TIM16,         /*!< AF5: TIM16 Alternate Function mapping */
        FMKIO_AF5_TIM17,         /*!< AF5: TIM17 Alternate Function mapping */

        FMKIO_AF6_EVENTOUT,      /*!< AF6: EVENTOUT Alternate Function mapping */

        FMKIO_AF_NB              /*!< Total number of alternate functions */
    } t_eFMKIO_AlternateFunc;



    //-----------------------------TYPEDEF TYPES---------------------------//
    //-----------------------------STRUCT TYPES---------------------------//
    /* CAUTION : Automatic generated code section for Structure: Start */

    /* CAUTION : Automatic generated code section for Structure: End */

    /* Basic configuration needed in all Signal configuration*/
    typedef struct 
    {
        t_eFMKIO_GpioPort HwGpio_e;
        t_eFMKIO_BspGpioPin  HwPin_e;
    } t_sFMKIO_BspSigCfg;

    /* Structure configuration for Pwm and Signal needed timer*/
    typedef struct 
    {
        t_sFMKIO_BspSigCfg      BasicCfg;
        t_uint8                 BspAlternateFunc_u8;
        t_eFMKCPU_Timer         timer_e;
        t_eFMKCPU_InterruptChnl channel_e;
    } t_sFMKIO_BspTimerSigCfg;

    typedef struct 
    {
        t_sFMKIO_BspSigCfg      BasicCfg;
        t_uint8                 BspAlternateFunc_u8;
        t_eFMKCPU_IRQNType      ExtiIRQN_e;
    } t_sFMKIO_BspEvntSigCfg;

    // ********************************************************************
    // *                      Prototypes
    // ********************************************************************
        
    // ********************************************************************
    // *                      Variables
    // ********************************************************************
    // Flag automatic generate code 


    //********************************************************************************
    //                      Public functions - Prototyupes
    //********************************************************************************

#endif // FMKIO_CONFIGPUBLIC_H_INCLUDED           
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
