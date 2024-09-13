/*********************************************************************
 * @file        FMKCPU_ConfigSpecific.h
 * @brief       Template_BriefDescription.
 * @note        TemplateDetailsDescription.\n
 *
 * @author      xxxxxx
 * @date        jj/mm/yyyy
 * @version     1.0
 */
  
#ifndef FMKPU_CONFIGSPECIFIC_H_INCLUDED
#define FMKPU_CONFIGSPECIFIC_H_INCLUDED





    // ********************************************************************
    // *                      Includes
    // ********************************************************************
    
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
    //                      Public functions - Prototyupes
    //********************************************************************************
    /* CAUTION : Automatic generated code section for Enable Clk Declaration: Start */
    void FMKCPU_Enable_SYSCFG_Clock(void);
    void FMKCPU_Enable_ADC1_Clock(void);
    void FMKCPU_Enable_TIM1_Clock(void);
    void FMKCPU_Enable_TIM3_Clock(void);
    void FMKCPU_Enable_TIM14_Clock(void);
    void FMKCPU_Enable_TIM15_Clock(void);
    void FMKCPU_Enable_TIM16_Clock(void);
    void FMKCPU_Enable_TIM17_Clock(void);
    void FMKCPU_Enable_SPI1_Clock(void);
    void FMKCPU_Enable_SPI2_Clock(void);
    void FMKCPU_Enable_USART1_Clock(void);
    void FMKCPU_Enable_USART2_Clock(void);
    void FMKCPU_Enable_I2C1_Clock(void);
    void FMKCPU_Enable_GPIOA_Clock(void);
    void FMKCPU_Enable_GPIOB_Clock(void);
    void FMKCPU_Enable_GPIOC_Clock(void);
    void FMKCPU_Enable_GPIOF_Clock(void);
    void FMKCPU_Enable_CRC_Clock(void);
    void FMKCPU_Enable_DMA1_Clock(void);
    void FMKCPU_Enable_SRAM_Clock(void);
    void FMKCPU_Enable_FLITF_Clock(void);
    void FMKCPU_Enable_WWDG_Clock(void);
    void FMKCPU_Enable_PWR_Clock(void);
    /* CAUTION : Automatic generated code section for Enable Clk Declaration: End */
    


    /* CAUTION : Automatic generated code section for Disable Clk Declaration: Start */
    void FMKCPU_Disable_SYSCFG_Clock(void);
    void FMKCPU_Disable_ADC1_Clock(void);
    void FMKCPU_Disable_TIM1_Clock(void);
    void FMKCPU_Disable_TIM3_Clock(void);
    void FMKCPU_Disable_TIM14_Clock(void);
    void FMKCPU_Disable_TIM15_Clock(void);
    void FMKCPU_Disable_TIM16_Clock(void);
    void FMKCPU_Disable_TIM17_Clock(void);
    void FMKCPU_Disable_SPI1_Clock(void);
    void FMKCPU_Disable_SPI2_Clock(void);
    void FMKCPU_Disable_USART1_Clock(void);
    void FMKCPU_Disable_USART2_Clock(void);
    void FMKCPU_Disable_I2C1_Clock(void);
    void FMKCPU_Disable_GPIOA_Clock(void);
    void FMKCPU_Disable_GPIOB_Clock(void);
    void FMKCPU_Disable_GPIOC_Clock(void);
    void FMKCPU_Disable_GPIOF_Clock(void);
    void FMKCPU_Disable_CRC_Clock(void);
    void FMKCPU_Disable_DMA1_Clock(void);
    void FMKCPU_Disable_SRAM_Clock(void);
    void FMKCPU_Disable_FLITF_Clock(void);
    void FMKCPU_Disable_WWDG_Clock(void);
    void FMKCPU_Disable_PWR_Clock(void);
    /* CAUTION : Automatic generated code section for Disable Clk Declaration: End */

/**< This function has been made to filled in c_FMKCPU_BspTimFunc_apf */
HAL_StatusTypeDef FMKCPU_HAL_TIM_Base_Start(TIM_HandleTypeDef *htim, uint32_t Channel);
HAL_StatusTypeDef FMKCPU_HAL_TIM_Base_Stop(TIM_HandleTypeDef *htim, uint32_t Channel);
HAL_StatusTypeDef FMKCPU_HAL_TIM_Base_Start_IT(TIM_HandleTypeDef *htim, uint32_t Channel);
HAL_StatusTypeDef FMKCPU_HAL_TIM_Base_Stop_IT(TIM_HandleTypeDef *htim, uint32_t Channel);
#endif // FMKPU_CONFIGSPECIFIC_H_INCLUDED           
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
