/*********************************************************************
 * @file        APPACT_ConfigPublic.h
 * @brief       Template_BriefDescription.
 * @note        TemplateDetailsDescription.\n
 *
 * @author      xxxxxx
 * @date        jj/mm/yyyy
 * @version     1.0
 */
  
#ifndef APPACT_CONFIGPUBLIC_H_INCLUDED
#define APPACT_CONFIGPUBLIC_H_INCLUDED





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
    /**< Enum for actuators list */
    typedef enum 
    {
        APPACT_ACT_1 = 0,       /**< Description */
        APPACT_ACT_2,           /**< Description */

        APPACT_ACT_NB,
    } t_eAPPACT_Actuators;

    /**< Enum for actuators drivers list */
    typedef enum
    {
        APPACT_DRV_JOY_1 = 0,   /**< Description */
        APPACT_DRV_JOY_2,       /**< Description */
        APPACT_DRV_NB
    } t_eAPPACT_Drivers;

    typedef enum 
    {
        APPACT_ACTUATOR_DISABLE = 0,    /**< The actuator is unused in a system configuration */
        APPACT_ACTUATOR_ENABLE          /**< The actuator is used in a system configuration */
    } t_eAPPACT_ActuatorState;

    typedef enum 
    {
        APPACT_DRIVER_DISABLE = 0,      /**< The driver is used in a system configuration */
        APPACT_DRIVER_ENABLE            /**< The driver is used in a system configuration */
    } t_eAPPACT_DrvState;
	/* CAUTION : Automatic generated code section for Structure: Start */

	/* CAUTION : Automatic generated code section for Structure: End */
	//-----------------------------STRUCT TYPES---------------------------//
    typedef struct
    {
        t_sint16 rawValue_s16;      /**< Store the actuators rawValue */
        t_bool   IsValueOK_b;       /**< Flag value is OK */
    } t_sAPPACT_ValueInfo;
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
    //                      Public functions - Prototyupes
    //********************************************************************************

#endif // APPACT_CONFIGPUBLIC_H_INCLUDED           
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
