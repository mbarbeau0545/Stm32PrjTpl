/*********************************************************************
 * @file        FMKCPU_ConfigPublic.h
 * @brief       Template_BriefDescription.
 * @details     TemplateDetailsDescription.\n
 *
 * @author      AUDMBA
 * @date        31/08/2024
 * @version     1.0
 */
  
#ifndef FMKCPU_CONFIGPUBLIC_H_INCLUDED
#define FMKCPU_CONFIGPUBLIC_H_INCLUDED





    // ********************************************************************
    // *                      Includes
    // ********************************************************************
    #include "stm32f030x8.h"
    #include "stm32f0xx_hal.h"
    #include "TypeCommon.h"
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
    /* Number max of cannel enable by timer */
    typedef enum 
    {
        FMKCPU_CHANNEL_1 = 0x0U,
        FMKCPU_CHANNEL_2,
        FMKCPU_CHANNEL_3,
        FMKCPU_CHANNEL_4,

        FMKCPU_CHANNEL_NB,
    } t_eFMKCPU_InterruptChnl;

    // Flag automatic generate code 
    /* Number of timer enable in smt32f08 family */
    typedef enum 
    {
        FMKCPU_TIMER_1 = 0x0U,
        FMKCPU_TIMER_3,
        FMKCPU_TIMER_14,
        FMKCPU_TIMER_15,
        FMKCPU_TIMER_16,
        FMKCPU_TIMER_17,

        FMKCPU_TIMER_NB,
    } t_eFMKCPU_Timer;

    // Flag automatic generate code 
    /* Number max of cannel enable by timer */
    typedef enum 
    {
        FMKCPU_EVENT_CHANNEL_1 = 0x0U,
        FMKCPU_EVENT_CHANNEL_2,

        FMKCPU_EVENT_CHANNEL_NB,
    } t_eFMKCPU_EventChannel;

    // Flag automatic generate code 
    /* Number max of cannel enable by timer */
    typedef enum 
    {
        FMKCPU_RCC_CLK_SYSCFG = 0x0U,
        FMKCPU_RCC_CLK_ADC1 ,
        FMKCPU_RCC_CLK_TIM1,
        FMKCPU_RCC_CLK_TIM3,
        FMKCPU_RCC_CLK_TIM14,
        FMKCPU_RCC_CLK_TIM15,
        FMKCPU_RCC_CLK_TIM16 ,
        FMKCPU_RCC_CLK_TIM17,
        FMKCPU_RCC_CLK_SPI1,
        FMKCPU_RCC_CLK_SPI2,
        FMKCPU_RCC_CLK_USART1,
        FMKCPU_RCC_CLK_USART2,
        FMKCPU_RCC_CLK_I2C1,
        FMKCPU_RCC_CLK_GPIOA,
        FMKCPU_RCC_CLK_GPIOB,
        FMKCPU_RCC_CLK_GPIOC,
        FMKCPU_RCC_CLK_GPIOF,
        FMKCPU_RCC_CLK_CRC,
        FMKCPU_RCC_CLK_DMA1,
        FMKCPU_RCC_CLK_SRAM,
        FMKCPU_RCC_CLK_FLITF,
        FMKCPU_RCC_CLK_WWDG,
        FMKCPU_RCC_CLK_PWR,

        FMKCPU_RCC_CLK_NB,
    } t_eFMKCPU_ClockPort;

    /* typedef enum for channel mode */
    typedef enum 
    {
        FMKCPU_HWCHNL_CFG_PWM = 0x0U,
        FMKCPU_HWCHNL_CFG_IC,
        FMKCPU_HWCHNL_CFG_OC,
        FMKCPU_HWCHNL_CFG_OP,
        FMKCPU_HWCHNL_CFG_EVNT,
        FMKCPU_HWCHNL_CFG_ECDR,
        FMKCPU_HWCHNL_CFG_TRGR,

        FMKCPU_HWCHNL_CFG_NB,
    } t_eFMKCPU_HwChannelCfg;

    typedef enum 
    {
        FMKCPU_NVIC_PRIORITY_LOW = 0x0U,
        FMKCPU_NVIC_PRIORITY_MEDIUM,
        FMKCPU_NVIC_PRIORITY_HIGH,

        FMKCPU_NVIC_PRIORITY_NB
    } t_eFMKCPU_NVICPriority;

    typedef enum
    {
        FMKCPU_WWDG_RESET_50MS = 0,
        FMKCPU_WWDG_RESET_100MS,
        FMKCPU_WWDG_RESET_200MS,
        FMKCPU_WWDG_RESET_500MS,

        FMKCPU_WWDG_RESET_NB,
    } t_eFMKCPu_WwdgResetPeriod;
    //-----------------------------TYPEDEF TYPES---------------------------//
    /*IRQNType available in stm32f030x8*/
    typedef IRQn_Type (t_eFMKCPU_IRQNType);
    

    typedef struct
    {
        t_eFMKCPU_Timer               timer_e;
        t_eFMKCPU_InterruptChnl       channel_e;
    } t_sFMKCPU_BspTimerCfg;
    // ********************************************************************
    // *                      Prototypes
    // ********************************************************************
        
    // ********************************************************************
    // *                      Variables
    // ********************************************************************
    


    //********************************************************************************
    //                      Public functions - Prototyupes
    //********************************************************************************

#endif // FMKCPU_CONFIGPUBLIC_H_INCLUDED           
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
