/*********************************************************************
 * @file        FMKCPU_ConfigSpecific.c
 * @brief       Template_BriefDescription.
 * @note        TemplateDetailsDescription.\n
 *
 * @author      xxxxxx
 * @date        jj/mm/yyyy
 * @version     1.0
 */






// ********************************************************************
// *                      Includes
// ********************************************************************

#include "stm32f0xx_hal.h"

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
// ********************************************************************
// *                      Prototypes
// ********************************************************************
	
// ********************************************************************
// *                      Variables
// ********************************************************************

//********************************************************************************
//                      Local functions - Prototypes
//********************************************************************************

//****************************************************************************
//                      Public functions - Implementation
//********************************************************************************
void FMKCPU_Enable_SYSCFG_Clock(void) { __HAL_RCC_SYSCFG_CLK_ENABLE(); }
void FMKCPU_Enable_ADC1_Clock(void)   { __HAL_RCC_ADC1_CLK_ENABLE(); }
void FMKCPU_Enable_TIM1_Clock(void)   { __HAL_RCC_TIM1_CLK_ENABLE(); }
void FMKCPU_Enable_TIM3_Clock(void)   { __HAL_RCC_TIM3_CLK_ENABLE(); }
void FMKCPU_Enable_TIM14_Clock(void)  { __HAL_RCC_TIM14_CLK_ENABLE(); }
void FMKCPU_Enable_TIM15_Clock(void)  { __HAL_RCC_TIM15_CLK_ENABLE(); }
void FMKCPU_Enable_TIM16_Clock(void)  { __HAL_RCC_TIM16_CLK_ENABLE(); }
void FMKCPU_Enable_TIM17_Clock(void)  { __HAL_RCC_TIM17_CLK_ENABLE(); }
void FMKCPU_Enable_SPI1_Clock(void)   { __HAL_RCC_SPI1_CLK_ENABLE(); }
void FMKCPU_Enable_SPI2_Clock(void)   { __HAL_RCC_SPI2_CLK_ENABLE(); }
void FMKCPU_Enable_USART1_Clock(void) { __HAL_RCC_USART1_CLK_ENABLE(); }
void FMKCPU_Enable_USART2_Clock(void) { __HAL_RCC_USART2_CLK_ENABLE(); }
void FMKCPU_Enable_I2C1_Clock(void)   { __HAL_RCC_I2C1_CLK_ENABLE(); }
void FMKCPU_Enable_GPIOA_Clock(void)  { __HAL_RCC_GPIOA_CLK_ENABLE(); }
void FMKCPU_Enable_GPIOB_Clock(void)  { __HAL_RCC_GPIOB_CLK_ENABLE(); }
void FMKCPU_Enable_GPIOC_Clock(void)  { __HAL_RCC_GPIOC_CLK_ENABLE(); }
void FMKCPU_Enable_GPIOF_Clock(void)  { __HAL_RCC_GPIOF_CLK_ENABLE(); }
void FMKCPU_Enable_CRC_Clock(void)    { __HAL_RCC_CRC_CLK_ENABLE(); }
void FMKCPU_Enable_DMA1_Clock(void)   { __HAL_RCC_DMA1_CLK_ENABLE(); }
void FMKCPU_Enable_SRAM_Clock(void)   { __HAL_RCC_SRAM_CLK_ENABLE(); }
void FMKCPU_Enable_FLITF_Clock(void)  { __HAL_RCC_FLITF_CLK_ENABLE(); }
void FMKCPU_Enable_WWDG_Clock(void)   { __HAL_RCC_WWDG_CLK_ENABLE(); }
void FMKCPU_Enable_PWR_Clock(void)    { __HAL_RCC_PWR_CLK_ENABLE(); }

// Fonctions pour désactiver les horloges
void FMKCPU_Disable_SYSCFG_Clock(void) { __HAL_RCC_SYSCFG_CLK_DISABLE(); }
void FMKCPU_Disable_ADC1_Clock(void)   { __HAL_RCC_ADC1_CLK_DISABLE(); }
void FMKCPU_Disable_TIM1_Clock(void)   { __HAL_RCC_TIM1_CLK_DISABLE(); }
void FMKCPU_Disable_TIM3_Clock(void)   { __HAL_RCC_TIM3_CLK_DISABLE(); }
void FMKCPU_Disable_TIM14_Clock(void)  { __HAL_RCC_TIM14_CLK_DISABLE(); }
void FMKCPU_Disable_TIM15_Clock(void)  { __HAL_RCC_TIM15_CLK_DISABLE(); }
void FMKCPU_Disable_TIM16_Clock(void)  { __HAL_RCC_TIM16_CLK_DISABLE(); }
void FMKCPU_Disable_TIM17_Clock(void)  { __HAL_RCC_TIM17_CLK_DISABLE(); }
void FMKCPU_Disable_SPI1_Clock(void)   { __HAL_RCC_SPI1_CLK_DISABLE(); }
void FMKCPU_Disable_SPI2_Clock(void)   { __HAL_RCC_SPI2_CLK_DISABLE(); }
void FMKCPU_Disable_USART1_Clock(void) { __HAL_RCC_USART1_CLK_DISABLE(); }
void FMKCPU_Disable_USART2_Clock(void) { __HAL_RCC_USART2_CLK_DISABLE(); }
void FMKCPU_Disable_I2C1_Clock(void)   { __HAL_RCC_I2C1_CLK_DISABLE(); }
void FMKCPU_Disable_GPIOA_Clock(void)  { __HAL_RCC_GPIOA_CLK_DISABLE(); }
void FMKCPU_Disable_GPIOB_Clock(void)  { __HAL_RCC_GPIOB_CLK_DISABLE(); }
void FMKCPU_Disable_GPIOC_Clock(void)  { __HAL_RCC_GPIOC_CLK_DISABLE(); }
void FMKCPU_Disable_GPIOF_Clock(void)  { __HAL_RCC_GPIOF_CLK_DISABLE(); }
void FMKCPU_Disable_CRC_Clock(void)    { __HAL_RCC_CRC_CLK_DISABLE(); }
void FMKCPU_Disable_DMA1_Clock(void)   { __HAL_RCC_DMA1_CLK_DISABLE(); }
void FMKCPU_Disable_SRAM_Clock(void)   { __HAL_RCC_SRAM_CLK_DISABLE(); }
void FMKCPU_Disable_FLITF_Clock(void)  { __HAL_RCC_FLITF_CLK_DISABLE(); }
void FMKCPU_Disable_WWDG_Clock(void)   { __HAL_RCC_WWDG_CLK_DISABLE(); }
void FMKCPU_Disable_PWR_Clock(void)    { __HAL_RCC_PWR_CLK_DISABLE(); }

HAL_StatusTypeDef FMKCPU_HAL_TIM_Base_Start(TIM_HandleTypeDef *htim, uint32_t Channel){UNUSED(Channel); return HAL_TIM_Base_Start(htim);}
HAL_StatusTypeDef FMKCPU_HAL_TIM_Base_Stop(TIM_HandleTypeDef *htim, uint32_t Channel){UNUSED(Channel); return HAL_TIM_Base_Stop(htim);}
HAL_StatusTypeDef FMKCPU_HAL_TIM_Base_Start_IT(TIM_HandleTypeDef *htim, uint32_t Channel){UNUSED(Channel); return HAL_TIM_Base_Start_IT(htim);}
HAL_StatusTypeDef FMKCPU_HAL_TIM_Base_Stop_IT(TIM_HandleTypeDef *htim, uint32_t Channel){UNUSED(Channel); return HAL_TIM_Base_Stop_IT(htim);}
//********************************************************************************
//                      Local functions - Implementation
//********************************************************************************
           
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
