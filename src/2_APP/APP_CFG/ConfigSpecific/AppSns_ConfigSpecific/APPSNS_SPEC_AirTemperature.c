/*********************************************************************
 * @file        TemplateName.c
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
/* CAUTION : Automatic generated code section for Include: Start */
#include "./APPSNS_SPEC_AirTemperature.h"
/* CAUTION : Automatic generated code section for Include: End */
#include "FMK_HAL/FMK_IO/Src/FMK_IO.h"
// ********************************************************************
// *                      Defines
// ********************************************************************
/* CAUTION : Automatic generated code section for Include: Start */

/* CAUTION : Automatic generated code section for Include: End */
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
static const t_eFMKIO_InAnaSig c_InputSig_e = FMKIO_INPUT_SIGANA_9;
//********************************************************************************
//                      Local functions - Prototypes
//********************************************************************************
static t_eReturnState s_APPSNS_SPEC_AirTemperature_DiagMngmt(t_uint8 f_debugInfo1_u8, t_uint8 f_debugInfo2_u8);
//****************************************************************************
//                      Public functions - Implementation
//********************************************************************************
/* CAUTION : Automatic generated code section for Specific Function Implementation: Start */


/******************************************
* APPSNS_SPEC_AirTemperature_SetCfg
******************************************/
t_eReturnState APPSNS_SPEC_AirTemperature_SetCfg(void)
{
    t_eReturnState Ret_e = RC_OK;
    //    Your code for AirTemperature_SetSnsCfg here
    //Ret_e = FMKIO_Set_InAnaSigCfg(c_InputSig_e, 
    //                                FMKIO_PULL_MODE_DISABLE,
    //                                s_APPSNS_SPEC_AirTemperature_DiagMngmt);
    return Ret_e;
}



/******************************************
* APPSNS_SPEC_AirTemperature_GetValue
******************************************/
t_eReturnState APPSNS_SPEC_AirTemperature_GetValue(t_sAPPSNS_ValueInfo *f_SnsValue_ps)
{
    t_eReturnState Ret_e = RC_OK;
    t_uint16 value_u16;
    //    Your code for AirTemperature_GetSnsValue here
    Ret_e = FMKIO_Get_InAnaSigValue(c_InputSig_e, &value_u16);
    if(Ret_e == RC_OK)
    {
        f_SnsValue_ps->IsValueOK_b = True;
    }
    else 
    {
        f_SnsValue_ps->IsValueOK_b = False;
    }
    f_SnsValue_ps->rawValue_s16 = (t_sint16)value_u16;

    return Ret_e;
}

/* CAUTION : Automatic generated code section for Specific Function Implementation: End */
static t_eReturnState s_APPSNS_SPEC_AirTemperature_DiagMngmt(t_uint8 f_debugInfo1_u8, t_uint8 f_debugInfo2_u8)
{
    t_eReturnState Ret_e = RC_OK;

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
 *	@param[in] 
 *	@param[out]
 *	 
 *
 *
 */
