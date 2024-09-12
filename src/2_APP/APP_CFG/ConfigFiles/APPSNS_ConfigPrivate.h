/*********************************************************************
 * @file        APPSNS_ConfigPrivate.h
 * @brief       Template_BriefDescription.
 * @note        TemplateDetailsDescription.\n
 *
 * @author      xxxxxx
 * @date        jj/mm/yyyy
 * @version     1.0
 */
  
#ifndef APPSNS_CONFIGPRIVATE_H_INCLUDED
#define APPSNS_CONFIGPRIVATE_H_INCLUDED





    // ********************************************************************
    // *                      Includes
    // ********************************************************************
    #include "./APPSNS_ConfigPublic.h"

    #include "../ConfigSpecific/AppSns_ConfigSpecific/APPSNS_SPEC_Humidity.h"
    // ********************************************************************
    // *                      Defines
    // ********************************************************************
    #define APPSNS_CFG_NB_PER_CYCLE ((t_uint8)5)
    // ********************************************************************
    // *                      Types
    // ********************************************************************
	/* CAUTION : Automatic generated code section for Enum: Start */

	/* CAUTION : Automatic generated code section for Enum: End */
    /* CAUTION : Automatic generated code section for Structure: Start */

	/* CAUTION : Automatic generated code section for Structure: End */
	//-----------------------------STRUCT TYPES---------------------------//
    
	//-----------------------------ENUM TYPES-----------------------------//

    //-----------------------------TYPEDEF TYPES---------------------------//
    /**
    *
    *	@brief      Set a sensor configuration 

    */
    typedef t_eReturnState (t_cbAppSns_SetSnsCfg)(void);
    /**
    *
    *	@brief      get value for a sensor
    *
    *	@param[in] f_SnsValue_ps : structure to store value and validity
    *
    */
    typedef t_eReturnState (t_cbAppSns_GetSnsValue)(t_sAPPSNS_ValueInfo *f_SnsValue_ps);
    /**
    *
    *	@brief      Set the driver init function
    */
    typedef t_eReturnState (t_cbAppSns_DrvInit)(void);
    /**
    *
    *	@brief      Set the driver cyclic function
    *
    */
    typedef t_eReturnState (t_cbAppSns_DrvCyclic)(void);

	
	/* CAUTION : Automatic generated code section : Start */

	/* CAUTION : Automatic generated code section : End */
	/**< Structure to store needed functions for a sensor */
    typedef struct 
    {
        t_cbAppSns_SetSnsCfg      * SetCfg_pcb;         /**< Reference to "set config" function */
        t_cbAppSns_GetSnsValue    * GetValue_pcb;       /**< Reference to "get value" function */
    } t_sAPPSNS_SysSnsFunc;

    /**< Structure to store needed functions for a driver */
    typedef struct 
    {
        t_cbAppSns_DrvInit   * Init_pcb;
        t_cbAppSns_DrvCyclic * Cyclic_pcb;
    } t_sAPPSNS_SysDrvFunc;
    // ********************************************************************
    // *                      Prototypes
    // ********************************************************************
        
    // ********************************************************************
    // *                      Variables
    // ********************************************************************
    // Flag automatic generate code
    /**< Variable for System Sensors functions*/
    const t_sAPPSNS_SysSnsFunc c_AppSns_SysSns_apf[APPSNS_SNS_NB] = {
        {APPSNS_SPEC_Humidity_SetCfg,    APPSNS_SPEC_Humidity_GetValue},
        {APPSNS_SPEC_Humidity_SetCfg,    APPSNS_SPEC_Humidity_GetValue},
    };

    // Flag automatic generate code
    const t_sAPPSNS_SysDrvFunc c_AppSns_SysDrv_apf[APPSNS_DRV_NB] = {
        {(t_cbAppSns_DrvInit *)NULL_FONCTION , (t_cbAppSns_DrvCyclic *)NULL_FONCTION},
        {(t_cbAppSns_DrvInit *)NULL_FONCTION , (t_cbAppSns_DrvCyclic *)NULL_FONCTION},
    };
    // Flag automatic generate code
    /**< Variable for System Sensors Drivers functions*/
    const t_eAPPSNS_SnsMeasType c_AppSns_SnsMeasType_ae[APPSNS_SNS_NB] = {
        APPSNS_MEASTYPE_RAW, // APPSNS_SNS_1
        APPSNS_MEASTYPE_RAW, // APPSNS_SNS_2
    };
    // Flag automatic generate code
    /**< Variable for Sensors Drivers State*/
    const t_eAPPSNS_DrvState c_AppSns_DrvState_ae[APPSNS_DRV_NB] = {
        APPSNS_DRIVER_ENABLE, // APPSNS_DRV_JOY_1
        APPSNS_DRIVER_ENABLE, // APPSNS_DRV_JOY_2
    };

    // Flag automatic generate code
    /**< Variable for Sensors State*/
    const t_eAPPSNS_SensorState c_AppSns_SnsState_ae[APPSNS_SNS_NB] = {
        APPSNS_SENSOR_ENABLE, // APPSNS_SNS_1
        APPSNS_SENSOR_ENABLE, // APPSNS_SNS_2
    };
    //********************************************************************************
    //                      Public functions - Prototyupes
    //********************************************************************************

#endif // APPSNS_CONFIGPRIVATE_H_INCLUDED           
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
