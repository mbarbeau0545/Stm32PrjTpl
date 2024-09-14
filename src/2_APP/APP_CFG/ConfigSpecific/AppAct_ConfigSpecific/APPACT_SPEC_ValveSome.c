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
#include "./APPACT_SPEC_ValveSome.h"
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
t_eReturnState APPACT_SPEC_ValveSome_SetCfg(void)
{
    FMKIO_Set_OutPwmSigCfg(FMKIO_OUTPUT_SIGPWM_2,FMKIO_PULL_MODE_UNABLE, 200, 500, False,NULL_FONCTION);
    return RC_OK;
}

t_eReturnState APPACT_SPEC_ValveSome_SetValue(t_sint16 f_value_s16)
{
    FMKIO_Set_OutPwmSigValue(FMKIO_OUTPUT_SIGPWM_2, f_value_s16);
    return RC_OK;
}

t_eReturnState APPACT_SPEC_ValveSome_GetValue(t_sAPPACT_ValueInfo *f_SnsValue_ps)
{
    FMKIO_Get_OutPwmSigValue(FMKIO_OUTPUT_SIGPWM_2, (t_uint16 *)&f_SnsValue_ps->rawValue_s16);
    return RC_OK;
}

t_eReturnState APPSNS_SPEC_APPACT_SPEC_ValveSome_DiagHdlrHumidity_DiagHdlr(t_uint8 f_InSigProblem_u8)
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
