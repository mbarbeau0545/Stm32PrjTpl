/*********************************************************************
 * @file        CAN.h
 * @brief       Template_BriefDescription.
 * @note        TemplateDetailsDescription.\n
 *
 * @author      xxxxxx
 * @date        jj/mm/yyyy
 * @version     1.0
 */
  
#ifndef APPSYS_CONFIGPRIVATE_H_INCLUDED
#define APPSYS_CONFIGPRIVATE_H_INCLUDED





    // ********************************************************************
    // *                      Includes
    // ********************************************************************
    #include "./APPSYS_ConfigPublic.h"
    #include "1_FMK/FMK_HAL/FKM_IO/Src/FMK_IO.h"
    #include "1_FMK/FMK_HAL/FMK_CDA/Src/FMK_CDA.h"
    #include "1_FMK/FMK_HAL/FMK_CPU/Src/FMK_CPU.h"
    #include "2_APP/APP_CTRL/APP_ACT/Src/APP_ACT.h"
    #include "2_APP/APP_CTRL/APP_SNS/Src/APP_SNS.h"
    // ********************************************************************
    // *                      Defines
    // ********************************************************************

    #define APPSYS_ELAPSED_TIME_CYCLIC ((t_uint8)20) /* elapsed time between all cyclic function are called*/
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
    /*****************************************************************************
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
    typedef t_eReturnState (t_cbAppSys_FuncInit)(void);
    /*****************************************************************************
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
    typedef t_eReturnState (t_cbAppSys_FuncCyclic)(void);
    /*****************************************************************************
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
    typedef t_eReturnState (t_cbAppSys_GetState)(t_eCyclicFuncState *f_state_pe);
    /*****************************************************************************
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
    typedef t_eReturnState (t_cbAppSys_SetState)(t_eCyclicFuncState f_state_pe);

    /* Structure to store Init and Cyclic Func*/

    typedef struct 
    {
        t_cbAppSys_FuncInit   * funcInit_cb;
        t_cbAppSys_FuncCyclic * funcCyclic_cb;
        t_cbAppSys_GetState   * funcGetState_cb;
        t_cbAppSys_SetState   * funcSetState_cb;
    } t_sAppSys_SysFunc;
    // ********************************************************************
    // *                      Prototypes
    // ********************************************************************
        
    // ********************************************************************
    // *                      Variables
    // ********************************************************************
    
    // Flag automatic generate code
    t_sAppSys_SysFunc c_AppSys_ModuleFunc_apf[APPSYS_MODULE_NB] = {
        // FrameWork module 
        {FMKCPU_Init,    FMKCPU_Cyclic,     FMKCPU_GetState, FMKCPU_SetState},
        {FMKCDA_Init,    FMKCDA_Cyclic,     FMKCDA_GetState, FMKCDA_SetState},
        {FMKIO_Init,     FMKIO_Cyclic,      FMKIO_GetState,  FMKIO_SetState},

        // Application module
        {APPSNS_Init,    APPSNS_Cyclic,     APPSNS_GetState, APPSNS_SetState},
        {APPACT_Init,    APPACT_Cyclic,     APPACT_GetState, APPACT_SetState},
    };

    //********************************************************************************
    //                      Public functions - Prototyupes
    //********************************************************************************

#endif // APPSYS_CONFIGPRIVATE_H_INCLUDED           
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
