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
#include "FMK_HAL/FKM_IO/Src/FMK_IO.h"
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

//********************************************************************************
//                      Local functions - Prototypes
//********************************************************************************
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
    Ret_e =FMKIO_Set_InDigSigCfg(FMKIO_INPUT_SIGDIG_3, FMKIO_PULL_MODE_UNABLE);
    return Ret_e;
}



/******************************************
* APPSNS_SPEC_AirTemperature_GetValue
******************************************/
t_eReturnState APPSNS_SPEC_AirTemperature_GetValue(t_sAPPSNS_ValueInfo *f_SnsValue_ps)
{
    t_eReturnState Ret_e = RC_OK;
    t_eFMKIO_DigValue value_e;
    //    Your code for AirTemperature_GetSnsValue here
    Ret_e = FMKIO_Get_InDigSigValue(FMKIO_INPUT_SIGDIG_3, &value_e);
    if(Ret_e == RC_OK)
    {
        f_SnsValue_ps->IsValueOK_b = True;
        f_SnsValue_ps->rawValue_s16 = value_e;
    }
    else
    {
        f_SnsValue_ps->IsValueOK_b = False;
        f_SnsValue_ps->rawValue_s16 = value_e;
    }


    return Ret_e;
}

/* CAUTION : Automatic generated code section for Specific Function Implementation: End */
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
