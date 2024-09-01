/*********************************************************************
 * @file        FMK_CDA.h
 * @brief       Template_BriefDescription.
 * @details     TemplateDetailsDescription.\n
 *
 * @author      xxxxxx
 * @date        jj/mm/yyyy
 * @version     1.0
 */
  
#ifndef FMKCDA_H_INCLUDED
#define FMKCDA_H_INCLUDED





    // ********************************************************************
    // *                      Includes
    // ********************************************************************
    #include "FMK_CFG/FMKCFG_ConfigFiles/FMKCDA_ConfigPublic.h"
    #include "TypeCommon.h"
    // ********************************************************************
    // *                      Defines
    // ********************************************************************

    // ********************************************************************
    // *                      Types
    // ********************************************************************
    //-----------------------------ENUM TYPES-----------------------------//
    /* Configuration Result mode for Adc Conversion*/
    typedef enum
    {
        FMKCDDA_RESULT_REGISTER = 0,
        FMKCDA_RESULT_INTERRUPT,
        FMKCDA_RESULT_DMA,

        FMKCDA_RESULT_NB
    } t_eFMKCDA_ResultMode;

    typedef enum
    {
        FMKCDA_ACQUISITION_SINGLE = 0,
        FMKCDA_ACQUISITION_CONTINUOUS,
        FMKCDA_ACQUISITION_SCAN,
        FMKCDA_ACQUISITION_TRIGGERED,

        FMKCDA_ACQUISITION_NB
    } t_eFMKCDA_AcquisitionMode;

    typedef enum 
    {
        FMKCDA_ADC_CFG_BASIC_REGISTER = 0,
        FMKCDA_ADC_CFG_PERIODIC_INTERRUPT,
        FMKCDA_ADC_CFG_PERIODIC_DMA,
        FMKCDA_ADC_CFG_SCAN_INTERRUPT,
        FMKCDA_ADC_CFG_SCAN_DMA,
        FMKCDA_ADC_CFG_TRIGGERED_REGISTER,
        FMKCDA_ADC_CFG_TRIGGERED_INTERRUPT,
        FMKCDA_ADC_CFG_TRIGGERED_DMA,

        FMKCDA_ADC_CFG_NB,
    } t_eFMKCDA_HwAdcCfg;
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
    t_eReturnState FMKCDA_Init(void);
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
    t_eReturnState FMKCDA_Cyclic(void);
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
    t_eReturnState FMKCDA_AddAdcChannelCfg(t_eFMKCDA_Adc f_Adc_e, 
                                       t_eFMKCDA_AdcChannel f_channel_e,
                                       t_eFMKCDA_HwAdcCfg   f_adcCfg_e);
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
    t_eReturnState FMKCDA_Get_AnaChannelMeasure(t_eFMKCDA_Adc f_Adc_e, t_eFMKCDA_AdcChannel f_channel_e, t_uint16 *f_AnaMeasure_u16);
    
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
 *	@params[in] 
 *	@params[out]
 *	 
 *
 *
 */
