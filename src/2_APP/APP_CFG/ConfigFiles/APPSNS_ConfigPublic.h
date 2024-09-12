/*********************************************************************
 * @file        APPSNS_ConfigPublic.h
 * @brief       Template_BriefDescription.
 * @note        TemplateDetailsDescription.\n
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
    /**< Enum for Sensors list */
    typedef enum
    {
        APPSNS_SNS_1 = 0,        /**< Description */
        APPSNS_SNS_2,            /**< Description */

        APPSNS_SNS_NB
    }t_eAPPSNS_Sensors;

    /**< Enum for Sensors drivers list */
    typedef enum
    {
        APPSNS_DRV_JOY_1 = 0,    /**< Description */
        APPSNS_DRV_JOY_2,        /**< Description */
        APPSNS_DRV_NB
    } t_eAPPSNS_Drivers;

    /**< Enum for sensor conversion list */
    typedef enum
    {
        APPSNS_MEASTYPE_RAW = 0,            /**< Raw value is not changed */
        APPSNS_MEASTYPE_ANGLE_RAD,          /**< Sensor value converted to angle in radians */
        APPSNS_MEASTYPE_ANGLE_DEGREE,       /**< Sensor value converted to angle in degrees */
        APPSNS_MEASTYPE_DISTANCE_M,         /**< Sensor value converted to distance in meters */
        APPSNS_MEASTYPE_DISTANCE_MM,        /**< Sensor value converted to distance in millimeters */
        APPSNS_MEASTYPE_TEMPERATURE_C,      /**< Sensor value converted to temperature in Celsius */
        APPSNS_MEASTYPE_TEMPERATURE_F,      /**< Sensor value converted to temperature in Fahrenheit */
        APPSNS_MEASTYPE_PRESSURE_PA,        /**< Sensor value converted to pressure in pascals */
        APPSNS_MEASTYPE_PRESSURE_BAR,       /**< Sensor value converted to pressure in bars */
        APPSNS_MEASTYPE_HUMIDITY,           /**< Sensor value converted to relative humidity percentage */
        APPSNS_MEASTYPE_ACCELERATION_M_S2,  /**< Sensor value converted to acceleration in meters per second squared */
        APPSNS_MEASTYPE_VELOCITY_M_S,       /**< Sensor value converted to velocity in meters per second */
        APPSNS_MEASTYPE_POWER_W,            /**< Sensor value converted to power in watts */
        APPSNS_MEASTYPE_ENERGY_J,           /**< Sensor value converted to energy in joules */
        APPSNS_MEASTYPE_VOLUME,             /**< Sensor value converted to volume */

        APPSNS_MEASTYPE_NB,
    } t_eAPPSNS_SnsMeasType;

    typedef enum 
    {
        APPSNS_SENSOR_DISABLE = 0,          /**< The sensor is unused in a system configuration */
        APPSNS_SENSOR_ENABLE                /**< The sensor is used in a system configuration */
    } t_eAPPSNS_SensorState;

    typedef enum 
    {
        APPSNS_DRIVER_DISABLE = 0,          /**< The driver is unused in a system configuration */
        APPSNS_DRIVER_ENABLE                /**< The driver is used in a system configuration */
    } t_eAPPSNS_DrvState;
	/* CAUTION : Automatic generated code section for Structure: Start */

	/* CAUTION : Automatic generated code section for Structure: End */
	//-----------------------------STRUCT TYPES---------------------------//
    typedef struct
    {
        t_sint16 rawValue_s16;      /**< Store the sensor rawValue */
        t_sint16 SnsValue_s16;      /**< Store the sensor after conversion */
        t_bool   IsValueOK_b;       /**< Store flag value validity */
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
 *	@note   
 *
 *
 *	@params[in] 
 *	@params[out]
 *	 
 *
 *
 */
