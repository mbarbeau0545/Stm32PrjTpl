/*********************************************************************
 * @file        FMKCPU_ConfigPublic.h
 * @brief       Template_BriefDescription.
 * @note        TemplateDetailsDescription.\n
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
    /**< Number max of cannel enable by timer */
    typedef enum 
    {
        FMKCPU_CHANNEL_1 = 0x0U,    /**< Reference to hal channel 1 */
        FMKCPU_CHANNEL_2,           /**< Reference to hal channel 2 */
        FMKCPU_CHANNEL_3,
        FMKCPU_CHANNEL_4,

        FMKCPU_CHANNEL_NB,
    } t_eFMKCPU_InterruptChnl;

    // Flag automatic generate code 
    /**< Number of timer enable in smt32f08 family */
    typedef enum 
    {
        FMKCPU_TIMER_1 = 0x0U,  /**< Reference to hal timer 1, this timer has 4 channels */
        FMKCPU_TIMER_3,         /**< Reference to hal timer 3, this timer has 4 channels */
        FMKCPU_TIMER_14,
        FMKCPU_TIMER_15,
        FMKCPU_TIMER_16,
        FMKCPU_TIMER_17,

        FMKCPU_TIMER_NB,
    } t_eFMKCPU_Timer;

    // Flag automatic generate code 
    /**< Number max of cannel enable by timer */
    typedef enum 
    {
        FMKCPU_EVENT_CHANNEL_1 = 0x0U,  /**< Event channel 1 */
        FMKCPU_EVENT_CHANNEL_2,         /**< Event channel 2 */

        FMKCPU_EVENT_CHANNEL_NB,
    } t_eFMKCPU_EventChannel;

    // Flag automatic generate code 
    /**< Number max of cannel enable by timer */
    typedef enum 
    {
        FMKCPU_RCC_CLK_SYSCFG = 0x0U,       /**< Reference to rcc clock syscfg  */
        FMKCPU_RCC_CLK_ADC1 ,               /**< Reference to rcc clock adc  */
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

    /**< typedef enum for channel mode */
    typedef enum 
    {
        FMKCPU_HWTIM_CFG_PWM = 0x0U,        /**< Timer configuration in PWM mode */
        FMKCPU_HWTIM_CFG_IC,                /**< Timer configuration in Input Capture mode */
        FMKCPU_HWTIM_CFG_OC,                /**< Timer configuration in Ouput Compare mode */
        FMKCPU_HWTIM_CFG_OP,                /**< Timer configuration in One Pulse mode */
        FMKCPU_HWTIM_CFG_EVNT,              /**< Timer configuration in Event mode */
        FMKCPU_HWTIM_CFG_ECDR,              /**< Timer configuration in j'saisplus mode */
        FMKCPU_HWTIM_CFG_TRGR,              /**< Timer configuration in trigger mode */

        FMKCPU_HWTIM_CFG_NB,                /**< Number of timer configuration mode*/
    } t_eFMKCPU_HwTimerCfg;

    /**< Enum for NVIC priority */
    typedef enum 
    {
        FMKCPU_NVIC_PRIORITY_LOW = 0x0U,    /**< Reference to bsp priority low value */
        FMKCPU_NVIC_PRIORITY_MEDIUM,        /**< Reference to bsp priority medium value */
        FMKCPU_NVIC_PRIORITY_HIGH,          /**< Reference to bsp priority high value */

        FMKCPU_NVIC_PRIORITY_NB             /**< Number of reference to bsp priority */
    } t_eFMKCPU_NVICPriority;

    /**< Enum for watchdog timer list */
    typedef enum
    {
        FMKCPU_WWDG_RESET_50MS = 0,     /**< Watchdogs reset parameter is 50 ms */
        FMKCPU_WWDG_RESET_100MS,        /**< Watchdogs reset parameter is 100 ms */
        FMKCPU_WWDG_RESET_200MS,        /**< Watchdogs reset parameter is 200 ms */
        FMKCPU_WWDG_RESET_500MS,        /**< Watchdogs reset parameter is 500 ms */

        FMKCPU_WWDG_RESET_NB,           /**< Number of watchdogs reset parameter  */
    } t_eFMKCPu_WwdgResetPeriod;
    //-----------------------------TYPEDEF TYPES---------------------------//
    /**< Abstraction for  IRQN type specfific for SMT32 card*/
    typedef IRQn_Type (t_eFMKCPU_IRQNType);
    
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
 *	@note   
 *
 *
 *	@param[in] 
 *	@param[out]
 *	 
 *
 *
 */
