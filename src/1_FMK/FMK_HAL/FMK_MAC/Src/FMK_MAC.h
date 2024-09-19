/**
 * @file        FMK_MAC.h
 * @brief       Memomry access control for DMA & user access\n.
 * @note        TemplateDetailsDescription.\n
 *
 * @author      xxxxxx
 * @date        jj/mm/yyyy
 * @version     1.0
 */
  
#ifndef FMKMAC_H_INCLUDED
#define FMKMAC_H_INCLUDED





    // ********************************************************************
    // *                      Includes
    // ********************************************************************
    #include "TypeCommon.h"
    #include "FMK_CFG/FMKCFG_ConfigFiles/FMKMAC_ConfigPublic.h"
    // ********************************************************************
    // *                      Defines
    // ********************************************************************

    // ********************************************************************
    // *                      Types
    // ********************************************************************
    //-----------------------------ENUM TYPES-----------------------------//
    /* CAUTION : Automatic generated code section for Enum: Start */

    /* CAUTION : Automatic generated code section for Enum: End */
    /**< Enum for Dma channel state */
    typedef enum
    {
        FMKMAC_DMA_CHNLSTATE_START = 0x0, /**< The dma channel is running */
        FMKMAC_DMA_CHNLSTATE_STOP,        /**< The dma channel is not running */
        FMKMAC_DMA_CHNLSTATE_NB,          /**< Number of channel state*/
    } t_eFMKMAC_DmaChnlState;
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
    /**************************************************************************
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
t_eReturnState FMKMAC_RqstDmaInit(t_eFMKMAC_DmaRqstType f_DmaType, void *f_ModuleHandle_pv);
#endif // FMKMAC_H_INCLUDED           
//************************************************************************************
// End of File
//************************************************************************************

/**************************************************************************
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
