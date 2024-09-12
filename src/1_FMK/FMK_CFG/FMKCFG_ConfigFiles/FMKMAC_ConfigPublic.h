/*********************************************************************
 * @file        FMKCDA_ConfigPrivate.h
 * @brief       Template_BriefDescription.
 * @note        TemplateDetailsDescription.\n
 *
 * @author      xxxxxx
 * @date        jj/mm/yyyy
 * @version     1.0
 */
  
#ifndef FMKMAC_CONFIGPUBLIC_H_INCLUDED
#define FMKMAC_CONFIGPUBLIC_H_INCLUDED





    // ********************************************************************
    // *                      Includes
    // ********************************************************************
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
    // Flag automatic generate code 
    /**< Enum for the different request available for DMA service */
    typedef enum 
    {
        FMKMAC_DMA_RQSTYPE_ADC1 = 0,    /**< Reference to bsp dma request for ADC1 */
        FMKMAC_DMA_RQSTYPE_SPI1,        /**< Reference to bsp dma request for SPI1 */
        FMKMAC_DMA_RQSTYPE_SPI2,
        FMKMAC_DMA_RQSTYPE_UART1,

        FMKMAC_DMA_RQSTYPE_NB,

    } t_eFMKMAC_DmaRqstType;


    //********************************************************************************
    //                      Public functions - Prototyupes
    //********************************************************************************

#endif // FMKMAC_CONFIGPUBLIC_H_INCLUDED           
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
