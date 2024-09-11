/*********************************************************************
 * @file        APPACT_ConfigPrivate.h
 * @brief       Template_BriefDescription.
 * @note        TemplateDetailsDescription.\n
 *
 * @author      xxxxxx
 * @date        jj/mm/yyyy
 * @version     1.0
 */
  
#ifndef APPACT_CONFIGPRIVATE_H_INCLUDED
#define APPACT_CONFIGPRIVATE_H_INCLUDED





    // ********************************************************************
    // *                      Includes
    // ********************************************************************
    #include "./APPACT_ConfigPublic.h"

    #include "../ConfigSpecific/APP_ACT_CFGSPEC/APPACT_SPEC_ValveSome.h"
    // ********************************************************************
    // *                      Defines
    // ********************************************************************
    #define APPACT_CFG_NB_PER_CYCLE ((t_uint8)5)
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
    typedef t_eReturnState (t_cbAppAct_SetActCfg)(void);
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
    typedef t_eReturnState (t_cbAppAct_GetActValue)(t_sAPPACT_ValueInfo *f_Value_ps);
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
    typedef t_eReturnState (t_cbAppAct_SetActValue)(t_sint16 f_value);
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
    typedef t_eReturnState (t_cbAppAct_DrvInit)(void);
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
    typedef t_eReturnState (t_cbAppAct_DrvCyclic)(void);

	
	/* CAUTION : Automatic generated code section : Start */

	/* CAUTION : Automatic generated code section : End */
	
    typedef struct 
    {
        t_cbAppAct_SetActCfg      * SetCfg_pcb;
        t_cbAppAct_SetActValue    * SetValue_pcb;
        t_cbAppAct_GetActValue    * GetValue_pcb;
    } t_sAPPACT_SysActFunc;

    typedef struct 
    {
        t_cbAppAct_DrvInit   * Init_pcb;
        t_cbAppAct_DrvCyclic * Cyclic_pcb;
    } t_sAPPACT_SysDrvFunc;
    // ********************************************************************
    // *                      Prototypes
    // ********************************************************************
        
    // ********************************************************************
    // *                      Variables
    // ********************************************************************
    const t_sAPPACT_SysActFunc c_AppAct_SysAct_apf[APPACT_ACT_NB] = {
        {APPACT_SPEC_ValveSome_SetCfg, APPACT_SPEC_ValveSome_SetValue, APPACT_SPEC_ValveSome_GetValue},
        {APPACT_SPEC_ValveSome_SetCfg, APPACT_SPEC_ValveSome_SetValue, APPACT_SPEC_ValveSome_GetValue},
    };

    const t_sAPPACT_SysDrvFunc c_AppAct_SysDrv_apf[APPACT_DRV_NB] = {
        {(t_cbAppAct_DrvInit *)NULL_FONCTION , (t_cbAppAct_DrvCyclic *)NULL_FONCTION},
        {(t_cbAppAct_DrvInit *)NULL_FONCTION , (t_cbAppAct_DrvCyclic *)NULL_FONCTION},
    };
    // Flag automatic generate code
    const t_eAPPACT_DrvState c_AppAct_DrvState_ae[APPACT_DRV_NB] = {
        APPACT_DRIVER_ENABLE, // APPSNS_DRV_JOY_1
        APPACT_DRIVER_ENABLE, // APPSNS_DRV_JOY_2
    };

    // Flag automatic generate code
    const t_eAPPACT_ActuatorState c_AppAct_ActState_ae[APPACT_ACT_NB] = {
        APPACT_ACTUATOR_ENABLE, // APPSNS_SNS_1
        APPACT_ACTUATOR_ENABLE, // APPSNS_SNS_2
    };


    //********************************************************************************
    //                      Public functions - Prototyupes
    //********************************************************************************

#endif // APPACT_CONFIGPRIVATE_H_INCLUDED           
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
