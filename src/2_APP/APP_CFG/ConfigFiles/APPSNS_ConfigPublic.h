/*********************************************************************
 * @file        APPSNS_ConfigPublic.h
 * @brief       Template_BriefDescription.
 * @details     TemplateDetailsDescription.\n
 *
 * @author      xxxxxx
 * @date        jj/mm/yyyy
 * @version     1.0
 */
  
#ifndef APPSNS_CONFIGPUBLIC_H_INCLUDED
#define APPSNS_CONFIGPUBLIC_H_INCLUDED





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
    typedef enum
    {
        APPSNS_SNS_1 = 0,
        APPSNS_SNS_2,

        APPSNS_SNS_NB
    }t_eAPPSNS_Sensors;

    typedef enum
    {
        APPSNS_DRV_JOY_1 = 0,
        APPSNS_DRV_JOY_2,
        APPSNS_DRV_NB
    } t_eAPPSNS_Drivers;
    typedef enum
    {
        APPSNS_MEASTYPE_RAW = 0,
        APPSNS_MEASTYPE_ANGLE_RAD,
        APPSNS_MEASTYPE_ANGLE_DEGREE,
        APPSNS_MEASTYPE_DISTANCE_M,
        APPSNS_MEASTYPE_DISTANCE_MM,
        APPSNS_MEASTYPE_TEMPERATURE_C,
        APPSNS_MEASTYPE_TEMPERATURE_F,
        APPSNS_MEASTYPE_PRESSURE_PA,
        APPSNS_MEASTYPE_PRESSURE_BAR,
        APPSNS_MEASTYPE_HUMIDITY, 
        APPSNS_MEASTYPE_ACCELERATION_M_S2,
        APPSNS_MEASTYPE_VELOCITY_M_S,
        APPSNS_MEASTYPE_POWER_W, 
        APPSNS_MEASTYPE_ENERGY_J,
        APPSNS_MEASTYPE_VOLUME,

        APPSNS_MEASTYPE_NB,
    } t_eAPPSNS_SnsMeasType;

    typedef enum 
    {
        APPSNS_SENSOR_DISABLE = 0,
        APPSNS_SENSOR_ENABLE
    } t_eAPPSNS_SensorState;

    typedef enum 
    {
        APPSNS_DRIVER_DISABLE = 0,
        APPSNS_DRIVER_ENABLE
    } t_eAPPSNS_DrvState;
	/* CAUTION : Automatic generated code section for Structure: Start */

	/* CAUTION : Automatic generated code section for Structure: End */
	//-----------------------------STRUCT TYPES---------------------------//
    typedef struct
    {
        t_sint16 rawValue_s16;
        t_sint16 SnsValue_s16;
        t_bool   IsValueOK_b;
    } t_sAPPSNS_ValueInfo;
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

#endif // APPSNS_CONFIGPUBLIC_H_INCLUDED           
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
