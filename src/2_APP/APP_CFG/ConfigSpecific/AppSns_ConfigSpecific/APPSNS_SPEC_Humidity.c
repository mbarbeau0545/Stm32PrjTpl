/*********************************************************************
 * @file        APPSNS_SPEC_Humidity.h
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
#include "./APPSNS_SPEC_Humidity.h"
#include "FMK_HAL/FKM_IO/Src/FMK_IO.h"
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
t_eReturnState APPSNS_SPEC_Humidity_SetCfg(void)
{
    FMKIO_Set_InAnaSigCfg(FMKIO_INPUT_SIGANA_1, FMKIO_PULL_MODE_UNABLE, NULL_FONCTION);
    return RC_OK;
}
t_eReturnState APPSNS_SPEC_Humidity_GetValue(t_sAPPSNS_ValueInfo *f_SnsValue_ps)
{
    t_uint16 value;
    FMKIO_Get_InAnaSigValue(FMKIO_INPUT_SIGANA_1, &value);

    return RC_OK;
}
t_eReturnState APPSNS_SPEC_Humidity_DiagHdlr(t_uint8 f_InSigProblem_u8)
{
    return RC_OK;
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
