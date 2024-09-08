/*********************************************************************
 * @file        APPSYS_ConfigPublic.h
 * @brief       Template_BriefDescription.
 * @details     TemplateDetailsDescription.\n
 *
 * @author      xxxxxx
 * @date        jj/mm/yyyy
 * @version     1.0
 */
  
#ifndef APPSYS_CONFIGPUBLIC_H_INCLUDED
#define APPSYS_CONFIGPUBLIC_H_INCLUDED





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
	/* CAUTION : Automatic generated code section for Enum: Start */

	/* CAUTION : Automatic generated code section for Enum: End */
	//-----------------------------ENUM TYPES-----------------------------//
    // Flag automatic generate code
    typedef enum
    {
        APPSYS_MODULE_FMK_CPU = 0,
        APPSYS_MODULE_FMK_CDA,
        APPSYS_MODULE_FMK_IO,

        APPSYS_MODULE_APP_ACT,
        APPSYS_MODULE_APP_SNS,

        APPSYS_MODULE_NB
    } t_eAppSys_ModuleList;

	/* CAUTION : Automatic generated code section for Structure: Start */

	/* CAUTION : Automatic generated code section for Structure: End */
	//-----------------------------STRUCT TYPES---------------------------//
	/* CAUTION : Automatic generated code section : Start */

	/* CAUTION : Automatic generated code section : End */
	//-----------------------------TYPEDEF TYPES---------------------------//
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
    typedef t_eReturnState (t_cbAppSys_FuncInit)(void);
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
    typedef t_eReturnState (t_cbAppSys_FuncCyclic)(void);
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
    typedef t_eReturnState (t_cbAppSys_GetState)(t_eCyclicFuncState *f_state_pe);
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
    


    //********************************************************************************
    //                      Public functions - Prototyupes
    //********************************************************************************

#endif // APPSYS_CONFIGPUBLIC_H_INCLUDED           
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
