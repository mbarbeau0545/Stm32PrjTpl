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

    #include "../ConfigSpecific/AppAct_ConfigSpecific/APPACT_SPEC_ValveSome.h"
    // ********************************************************************
    // *                      Defines
    // ********************************************************************
    #define APPACT_CFG_NB_PER_CYCLE ((t_uint8)5) /**< Number of actuators configuration per cycle */
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
    /**
    *
    *	@brief      Set a actuator configuration 

    */
    typedef t_eReturnState (t_cbAppAct_SetActCfg)(void);
    /**
    *
    *	@brief  Get actuator value 
    *
    *	@param[in]  f_value_ps : structure to store value and validity
    *
    */
    typedef t_eReturnState (t_cbAppAct_GetActValue)(t_sAPPACT_ValueInfo *f_value_ps);
    /**
    *
    *	@brief      Set value for an actuator
    *
    *	@param[in] f_value_s16 : value to set
    *
    */
    typedef t_eReturnState (t_cbAppAct_SetActValue)(t_sint16 f_value_s16);
    /**
    *
    *	@brief      Set the driver init function
    */
    typedef t_eReturnState (t_cbAppAct_DrvInit)(void);
    /**
    *
    *	@brief      Set the driver cyclic function
    *
    */
    typedef t_eReturnState (t_cbAppAct_DrvCyclic)(void);

	
	/* CAUTION : Automatic generated code section : Start */

	/* CAUTION : Automatic generated code section : End */
	
    /**< Structure to store needed functions for an actuators */
    typedef struct 
    {
        t_cbAppAct_SetActCfg      * SetCfg_pcb;         /**< Reference to "set config" function */
        t_cbAppAct_SetActValue    * SetValue_pcb;       /**< Reference to "set value" function */
        t_cbAppAct_GetActValue    * GetValue_pcb;       /**< Reference to "get value" function */
    } t_sAPPACT_SysActFunc;

    /**< Structure to store needed functions for a driver */
    typedef struct 
    {
        t_cbAppAct_DrvInit   * Init_pcb;        /**< Reference for init driver function */
        t_cbAppAct_DrvCyclic * Cyclic_pcb;      /**< Reference for cyclic driver function */
    } t_sAPPACT_SysDrvFunc;
    // ********************************************************************
    // *                      Prototypes
    // ********************************************************************
        
    // ********************************************************************
    // *                      Variables
    // ********************************************************************
    // Flag automatic generate code
    /**< Variable for System Actuators functions*/
    const t_sAPPACT_SysActFunc c_AppAct_SysAct_apf[APPACT_ACT_NB] = {
        // Actuator Cfg function           Actuator SetValue function   Actuator GetValue function 
        {APPACT_SPEC_ValveSome_SetCfg, APPACT_SPEC_ValveSome_SetValue, APPACT_SPEC_ValveSome_GetValue}, // ACTUATOR 1
        {APPACT_SPEC_ValveSome_SetCfg, APPACT_SPEC_ValveSome_SetValue, APPACT_SPEC_ValveSome_GetValue}, // ACTUATOR 2
    };
    // Flag automatic generate code
    /**< Variable for System Actuators Drivers functions*/
    const t_sAPPACT_SysDrvFunc c_AppAct_SysDrv_apf[APPACT_DRV_NB] = {
        {(t_cbAppAct_DrvInit *)NULL_FONCTION , (t_cbAppAct_DrvCyclic *)NULL_FONCTION}, // DRV_1 
        {(t_cbAppAct_DrvInit *)NULL_FONCTION , (t_cbAppAct_DrvCyclic *)NULL_FONCTION}, // DRV_2
    };
    // Flag automatic generate code
    /**< Variable for Actuators Drivers State*/
    const t_eAPPACT_DrvState c_AppAct_DrvState_ae[APPACT_DRV_NB] = {
        APPACT_DRIVER_ENABLE, // APPSNS_DRV_JOY_1
        APPACT_DRIVER_ENABLE, // APPSNS_DRV_JOY_2
    };

    // Flag automatic generate code
    /**< Variable for Actuators State*/
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
