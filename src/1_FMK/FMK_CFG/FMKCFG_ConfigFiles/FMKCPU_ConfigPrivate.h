/*********************************************************************
 * @file        FMKCPU_ConfigPrivate.h
 * @brief       Template_BriefDescription.
 * @details     TemplateDetailsDescription.\n
 *
 * @author      xxxxxx
 * @date        jj/mm/yyyy
 * @version     1.0
 */
  
#ifndef FMKCPU_CONFIGPRIVATE_H_INCLUDED
#define FMKCPU_CONFIGPRIVATE_H_INCLUDED





    // ********************************************************************
    // *                      Includes
    // ********************************************************************
    #include "./FMKCPU_ConfigPublic.h"
    #include "../FMKCFG_ConfigSpecific/FMKCPU_ConfigSpecific.h"
    #include "TypeCommon.h"
    // ********************************************************************
    // *                      Defines
    // ********************************************************************
    #define FMKCPU_IRQN_TYPE_NB    ((t_uint8)28)       // The number of IRQN Type, this number should be the same as IRQn_Type_NB
    #define FMKCPU_HSI_CLOCK_OSC   ((t_uint8)8)        // HSI oscillatator equals to 8 MHz
    #define FMKCPU_TIMER_CLOCK_OSC ((t_uint8)8)        // Frequency of the timer are 8 MHz
    #define FMKCPU_PWM_PSC         ((t_uint8)50)       // for every PWM the Prescaler is a constant 
    #define FMKCPU_IC_PSC          ((t_uint8)0)       // for every InputCOmpare the Prescaler is a constant 
    #define FMKCPU_IC_ARR          ((t_uint16)0xFFFF)       // for every InputCOmpare the Prescaler is a constant 
    #define FMKCPU_EVNT_PSC        ((t_uint16)(FMKCPU_TIMER_CLOCK_OSC * 1000)- (t_uint16)1) // The prescaler use for evnt timer, having 1000Hz (1ms)
    // ********************************************************************
    // *                      Types
    // ********************************************************************
    /* CAUTION : Automatic generated code section for Enum: Start */

    /* CAUTION : Automatic generated code section for Enum: End */

    /* CAUTION : Automatic generated code section for Structure: Start */

    /* CAUTION : Automatic generated code section for Structure: End */
    // ********************************************************************
    // *                      Prototypes
    // ********************************************************************
        
    // ********************************************************************
    // *                      Variables
    // ********************************************************************
    // Flag automatic generate code 
    const t_sFMKCPU_TimChannelFunc c_FMKCPU_BspTimFunc_apf[FMKCPU_HWCHNL_CFG_NB] = 
    {// Init Timer                         DeInitTimer                    StartPolling Func                 StopPolling Funnc             Start Interrupt Func          Stop Interrupt Func
        {HAL_TIM_PWM_Init,                HAL_TIM_PWM_DeInit,           HAL_TIM_PWM_Start,               HAL_TIM_PWM_Stop,             HAL_TIM_PWM_Start_IT,           HAL_TIM_PWM_Stop_IT},         // FMKCPU_CHANNEL_CFG_PWM 
        {HAL_TIM_IC_Init,                 HAL_TIM_IC_DeInit,            HAL_TIM_IC_Start,                HAL_TIM_IC_Stop,              HAL_TIM_IC_Start_IT,            HAL_TIM_IC_Stop_IT},          // FMKCPU_CHANNEL_CFG_IC
        {HAL_TIM_OC_Init,                 HAL_TIM_OC_DeInit,            HAL_TIM_OC_Start,                HAL_TIM_OC_Stop,              HAL_TIM_OC_Start_IT,            HAL_TIM_OC_Stop_IT},          // FMKCPU_CHANNEL_CFG_OC
        {NULL_FONCTION,                   HAL_TIM_OnePulse_DeInit,      HAL_TIM_OnePulse_Start,          HAL_TIM_OnePulse_Stop,        HAL_TIM_OnePulse_Start_IT,      HAL_TIM_OnePulse_Stop_IT},    // FMKCPU_CHANNEL_CFG_OP
        {HAL_TIM_Base_Init,               HAL_TIM_Base_DeInit,          FMKCPU_HAL_TIM_Base_Start,       FMKCPU_HAL_TIM_Base_Stop,     FMKCPU_HAL_TIM_Base_Start_IT,   FMKCPU_HAL_TIM_Base_Stop_IT}, // FMKCPU_CHANNEL_CFG_EVNT
        {NULL_FONCTION,                   HAL_TIM_Encoder_DeInit,       HAL_TIM_Encoder_Start,           HAL_TIM_Encoder_Stop,         HAL_TIM_Encoder_Start_IT,       HAL_TIM_Encoder_Stop_IT},     // FMKCPU_CHANNEL_CFG_ECDR
        {HAL_TIM_PWM_Init,                HAL_TIM_PWM_DeInit,           HAL_TIM_IC_Start,                HAL_TIM_IC_Stop,              HAL_TIM_Encoder_Start_IT,       HAL_TIM_Encoder_Stop_IT},     // FMKCPU_CHANNEL_CFG_TRGR
    };
    // Flag automatic generate code 
    const t_eFMKCPU_NVICPriority c_FMKCPU_IRQNPriority_ae[FMKCPU_IRQN_TYPE_NB] = {
        FMKCPU_NVIC_PRIORITY_MEDIUM,//WWDG_IRQn               
        FMKCPU_NVIC_PRIORITY_MEDIUM,//RTC_IRQn                
        FMKCPU_NVIC_PRIORITY_MEDIUM,//FLASH_IRQn              
        FMKCPU_NVIC_PRIORITY_MEDIUM,//RCC_IRQn                
        FMKCPU_NVIC_PRIORITY_MEDIUM,//EXTI0_1_IRQn            
        FMKCPU_NVIC_PRIORITY_MEDIUM,//EXTI2_3_IRQn            
        FMKCPU_NVIC_PRIORITY_MEDIUM,//EXTI4_15_IRQn           
        FMKCPU_NVIC_PRIORITY_MEDIUM,//DMA1_Channel1_IRQn      
        FMKCPU_NVIC_PRIORITY_MEDIUM,//DMA1_Channel2_3_IRQn    
        FMKCPU_NVIC_PRIORITY_MEDIUM,//DMA1_Channel4_5_IRQn    
        FMKCPU_NVIC_PRIORITY_MEDIUM,//ADC1_IRQn               
        FMKCPU_NVIC_PRIORITY_MEDIUM,//TIM1_BRK_UP_TRG_COM_IRQn
        FMKCPU_NVIC_PRIORITY_MEDIUM,//TIM1_CC_IRQn            
        FMKCPU_NVIC_PRIORITY_MEDIUM,//TIM3_IRQn               
        FMKCPU_NVIC_PRIORITY_MEDIUM,//TIM6_IRQn               
        FMKCPU_NVIC_PRIORITY_MEDIUM,//TIM14_IRQn              
        FMKCPU_NVIC_PRIORITY_MEDIUM,//TIM15_IRQn              
        FMKCPU_NVIC_PRIORITY_MEDIUM,//TIM16_IRQn              
        FMKCPU_NVIC_PRIORITY_MEDIUM,//TIM17_IRQn              
        FMKCPU_NVIC_PRIORITY_MEDIUM,//I2C1_IRQn               
        FMKCPU_NVIC_PRIORITY_MEDIUM,//I2C2_IRQn               
        FMKCPU_NVIC_PRIORITY_MEDIUM,//SPI1_IRQn               
        FMKCPU_NVIC_PRIORITY_MEDIUM,//SPI2_IRQn               
        FMKCPU_NVIC_PRIORITY_MEDIUM,//USART1_IRQn             
        FMKCPU_NVIC_PRIORITY_MEDIUM,//USART2_IRQn
    };

    // Flag automatic generate code 
    const t_sFMKCPU_ClkFunc c_FMKCPU_ClkFunctions_apcb[FMKCPU_RCC_CLK_NB] = {
    {FMKCPU_Enable_SYSCFG_Clock , FMKCPU_Disable_SYSCFG_Clock},   // FMKCPU_RCC_CLK_SYSCFG
    {FMKCPU_Enable_ADC1_Clock   , FMKCPU_Disable_ADC1_Clock},     // FMKCPU_RCC_CLK_ADC1
    {FMKCPU_Enable_TIM1_Clock   , FMKCPU_Disable_TIM1_Clock},     // FMKCPU_RCC_CLK_TIM1
    {FMKCPU_Enable_TIM3_Clock   , FMKCPU_Disable_TIM3_Clock},     // FMKCPU_RCC_CLK_TIM3
    {FMKCPU_Enable_TIM14_Clock  , FMKCPU_Disable_TIM14_Clock},    // FMKCPU_RCC_CLK_TIM14
    {FMKCPU_Enable_TIM15_Clock  , FMKCPU_Disable_TIM15_Clock},    // FMKCPU_RCC_CLK_TIM15
    {FMKCPU_Enable_TIM16_Clock  , FMKCPU_Disable_TIM16_Clock},    // FMKCPU_RCC_CLK_TIM16
    {FMKCPU_Enable_TIM17_Clock  , FMKCPU_Disable_TIM17_Clock},    // FMKCPU_RCC_CLK_TIM17
    {FMKCPU_Enable_SPI1_Clock   , FMKCPU_Disable_SPI1_Clock},     // FMKCPU_RCC_CLK_SPI1
    {FMKCPU_Enable_SPI2_Clock   , FMKCPU_Disable_SPI2_Clock},     // FMKCPU_RCC_CLK_SPI2
    {FMKCPU_Enable_USART1_Clock , FMKCPU_Disable_USART1_Clock},   // FMKCPU_RCC_CLK_USART1
    {FMKCPU_Enable_USART2_Clock , FMKCPU_Disable_USART2_Clock},   // FMKCPU_RCC_CLK_USART2
    {FMKCPU_Enable_I2C1_Clock   , FMKCPU_Disable_I2C1_Clock},     // FMKCPU_RCC_CLK_I2C1
    {FMKCPU_Enable_GPIOA_Clock  , FMKCPU_Disable_GPIOA_Clock},    // FMKCPU_RCC_CLK_GPIOA
    {FMKCPU_Enable_GPIOB_Clock  , FMKCPU_Disable_GPIOB_Clock},    // FMKCPU_RCC_CLK_GPIOB
    {FMKCPU_Enable_GPIOC_Clock  , FMKCPU_Disable_GPIOC_Clock},    // FMKCPU_RCC_CLK_GPIOC
    {FMKCPU_Enable_GPIOF_Clock  , FMKCPU_Disable_GPIOF_Clock},    // FMKCPU_RCC_CLK_GPIOF
    {FMKCPU_Enable_CRC_Clock    , FMKCPU_Disable_CRC_Clock},      // FMKCPU_RCC_CLK_CRC
    {FMKCPU_Enable_DMA1_Clock   , FMKCPU_Disable_DMA1_Clock},     // FMKCPU_RCC_CLK_DMA1
    {FMKCPU_Enable_SRAM_Clock   , FMKCPU_Disable_SRAM_Clock},     // FMKCPU_RCC_CLK_SRAM
    {FMKCPU_Enable_FLITF_Clock  , FMKCPU_Disable_FLITF_Clock},    // FMKCPU_RCC_CLK_FLITF
    {FMKCPU_Enable_WWDG_Clock   , FMKCPU_Disable_WWDG_Clock},     // FMKCPU_RCC_CLK_WWDG
    {FMKCPU_Enable_PWR_Clock    , FMKCPU_Disable_PWR_Clock},      // FMKCPU_RCC_CLK_PWR
    };

    // Flag automatic generate code 
    const t_sFMKCPU_BspTimerCfg c_EvntTimerCfg_as[FMKCPU_EVENT_CHANNEL_NB] = {
        {FMKCPU_TIMER_16, FMKCPU_CHANNEL_1}, // FMKCPU_EVENT_CHANNEL_1
        {FMKCPU_TIMER_17, FMKCPU_CHANNEL_1}, // FMKCPU_EVENT_CHANNEL_2
    };
    //********************************************************************************
    //                      Public functions - Prototyupes
    //********************************************************************************

#endif // FMKCPU_CONFIGPRIVATE_H_INCLUDED           
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
