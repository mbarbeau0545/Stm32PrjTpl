/*********************************************************************
 * @file        FMK_MAC.h
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
#include "./FMK_MAC.h"
#include "stm32f0xx_hal.h"
// ********************************************************************
// *                      Defines
// ********************************************************************

// ********************************************************************
// *                      Types
// ********************************************************************
/* CAUTION : Automatic generated code section for Enum: Start */

/* CAUTION : Automatic generated code section for Enum: End */
//-----------------------------ENUM TYPES-----------------------------//


/* CAUTION : Automatic generated code section for Structure: Start */

/* CAUTION : Automatic generated code section for Structure: End */
//-----------------------------STRUCT TYPES---------------------------//
/* CAUTION : Automatic generated code section : Start */

/* CAUTION : Automatic generated code section : End */
//-----------------------------TYPEDEF TYPES---------------------------//
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
t_eReturnState FMKMAC_RqstDmaInit(t_eFMKMAC_DmaRqstType f_DmaType_e, void *f_ModuleHandle_s)
{
    t_eReturnState Ret_e = RC_OK;

    if(f_DmaType_e > FMKMAC_DMA_RQSTYPE_NB)
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
    }
    if(f_ModuleHandle_s == (void *)NULL)
    {
        Ret_e = RC_OK;
    }
    if(Ret_e == RC_OK)
    {

    }
    
    return Ret_e;
}
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
