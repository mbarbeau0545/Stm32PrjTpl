/*********************************************************************
 * @file        APP_ACT.c
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

#include "./APP_ACT.h"
#include "APP_CFG/ConfigFiles/APPACT_ConfigPrivate.h"
// ********************************************************************
// *                      Defines
// ********************************************************************

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
static t_eCyclicFuncState g_state_e = STATE_CYCLIC_PREOPE;
//********************************************************************************
//                      Local functions - Prototypes
//********************************************************************************
/**
 *
 *	@brief      Perform preOperationnal action.\n
 *  @note       Set the actuator configuration.\n
 *              Call driver init function.\n
 *              If one of the configuration is not set the Module Cyclic 
 *              retry indefinitely.\n
 *              
 * 
 *  @retval RC_OK                             @ref RC_OK
 *  @retval RC_ERROR_PARAM_INVALID            @ref RC_ERROR_PARAM_INVALID
 *  @retval RC_ERROR_WRONG_STATE              @ref RC_ERROR_WRONG_STATE

 */
static t_eReturnState s_APPACT_PreOperational(void);
/**
*
*	@brief  Call driver cyclic function
*
*/
static t_eReturnState s_APPACT_Operational(void);
//****************************************************************************
//                      Public functions - Implementation
//********************************************************************************
/*********************************
 * APPACT_Init
 *********************************/
t_eReturnState APPACT_Init(void)
{
    return RC_OK;
}

/*********************************
 * APPACT_Cyclic
 *********************************/
t_eReturnState APPACT_Cyclic(void)
{
    t_eReturnState Ret_e = RC_OK;

    switch (g_state_e)
    {
    case STATE_CYCLIC_PREOPE:
    {
        Ret_e = s_APPACT_PreOperational();
        break;
    }
    case STATE_CYCLIC_WAITING:
    {
        // nothing to do, just wait all module are Ope
        break;
    }
    case STATE_CYCLIC_OPE:
    {
        Ret_e = s_APPACT_Operational();
        break;
    }
    case STATE_CYCLIC_ERROR:
    {
        break;
    }
    case STATE_CYCLIC_BUSY:
    default:
        Ret_e = RC_OK;
        break;
    }
    return Ret_e;
}

/*********************************
 * APPACT_GetState
 *********************************/
t_eReturnState APPACT_GetState(t_eCyclicFuncState *f_State_pe)
{
    t_eReturnState Ret_e = RC_OK;

    if(f_State_pe == (t_eCyclicFuncState *)NULL)
    {
        Ret_e = RC_ERROR_PTR_NULL;
    }
    if(Ret_e == RC_OK)
    {
        *f_State_pe = g_state_e;
    }
    return Ret_e;
}

/*********************************
 * APPACT_SetState
 *********************************/
t_eReturnState APPACT_SetState(t_eCyclicFuncState f_State_e)
{
    g_state_e = f_State_e;
    return RC_OK;
}

/*********************************
 * APPACT_Get_ActValue
 *********************************/
t_eReturnState APPACT_Get_ActValue(t_eAPPACT_Actuators f_actuator_e, t_sint16 * f_value_ps16)
{
    t_eReturnState Ret_e = RC_OK;
    t_sAPPACT_ValueInfo actValInfo_s = {0};

    if(f_actuator_e > APPACT_ACT_NB)
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
    }
    if(f_value_ps16 == (t_sint16 *)NULL)
    {
        Ret_e = RC_ERROR_PTR_NULL;
    }
    if(g_state_e != STATE_CYCLIC_OPE)
    {
        Ret_e = RC_ERROR_MODULE_NOT_INITIALIZED;
    }
    if(Ret_e == RC_OK)
    {
        // call specFunc 
        Ret_e = (c_AppAct_SysAct_apf[f_actuator_e].GetValue_pcb)(&actValInfo_s);
        if(actValInfo_s.IsValueOK_b == True)
        {
            *f_value_ps16 = (t_sint16)actValInfo_s.rawValue_s16;
        }
        else
        {
            *f_value_ps16 = (t_sint16)0;
        }
    }
    
    return Ret_e;
}

/*********************************
 * APPACT_Set_ActValue
 *********************************/
t_eReturnState APPACT_Set_ActValue(t_eAPPACT_Actuators f_actuator_e, t_sint16 f_value_s16)
{
    t_eReturnState Ret_e = RC_OK;

    if(f_actuator_e > APPACT_ACT_NB)
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
    }
    if(g_state_e != STATE_CYCLIC_OPE)
    {
        Ret_e = RC_ERROR_MODULE_NOT_INITIALIZED;
    }
    if(Ret_e == RC_OK)
    {
        // call specFunc 
        Ret_e = (c_AppAct_SysAct_apf[f_actuator_e].SetValue_pcb)(f_value_s16);
    }

    return Ret_e;    
}
//********************************************************************************
//                      Local functions - Implementation
//********************************************************************************
/*********************************
 * s_APPACT_PreOperational
 *********************************/
static t_eReturnState s_APPACT_PreOperational(void)
{
    t_eReturnState Ret_e = RC_OK;
    t_uint8 LLI_u8;
    static t_uint8 LLActCfg_u8 = 0;
    static t_uint8 ActCfgCnt_u8 = 0;
    static t_bool s_IsDrvInitDone_b = False;
    // first call drv init function 
    switch (s_IsDrvInitDone_b)
    {
        case False:
        {
            for(LLI_u8 = (t_uint8)0 ; (LLI_u8 < APPACT_DRV_NB) && (Ret_e == RC_OK) ; LLI_u8++)
            {
                if(c_AppAct_DrvState_ae[LLI_u8] == APPACT_DRIVER_ENABLE)
                {
                    if(c_AppAct_SysDrv_apf[LLI_u8].Init_pcb != (t_cbAppAct_DrvInit *)NULL_FONCTION)
                    {
                        Ret_e = (c_AppAct_SysDrv_apf[LLI_u8].Init_pcb)();
                    }
                }
            }
            if((LLI_u8 >= APPACT_DRV_NB) && (Ret_e == RC_OK))
            {
                s_IsDrvInitDone_b = (t_bool)True;
            }
            break;
        }
        case True:
        {// then config the sensors only if the Sensors is used which means in "enable"
            while((ActCfgCnt_u8 < (t_uint8)APPACT_CFG_NB_PER_CYCLE) && (Ret_e == RC_OK))
            {
                if(c_AppAct_ActState_ae[LLActCfg_u8] == APPACT_ACTUATOR_ENABLE)
                {
                    if(c_AppAct_SysAct_apf[LLActCfg_u8].SetCfg_pcb != (t_cbAppAct_SetActCfg *)NULL_FONCTION)
                    {
                        Ret_e = (c_AppAct_SysAct_apf[LLActCfg_u8].SetCfg_pcb)();
                        if(Ret_e == RC_OK)
                        {
                            ActCfgCnt_u8 += (t_uint8)1;
                        }
                    }                    
                }
                if(Ret_e == RC_OK)
                {
                    LLI_u8 += (t_uint8)1;
                    if(LLI_u8 >= APPACT_ACT_NB)
                    {
                        g_state_e = STATE_CYCLIC_WAITING;
                        break;
                    }
                }
            }
            break;
        }
    }
    return Ret_e;
}
/*********************************
 * s_APPACT_Operational
 *********************************/
static t_eReturnState s_APPACT_Operational(void)
{
    t_eReturnState Ret_e = RC_OK;
    static t_bool s_IsDrvCylic_b = True;
    t_bool DrvCyclicCnt_u8 = 0;
    t_uint8 LLI_u8; 

    if(s_IsDrvCylic_b == (t_bool)True)
    {
        for(LLI_u8 = (t_uint8)0 ; (LLI_u8 < APPACT_DRV_NB) && (Ret_e == RC_OK); LLI_u8++)
        {
            if(c_AppAct_DrvState_ae[LLI_u8] == APPACT_DRIVER_ENABLE)
            {
                if(c_AppAct_SysDrv_apf[LLI_u8].Cyclic_pcb != (t_cbAppAct_DrvCyclic *)NULL_FONCTION)
                {
                    Ret_e = (c_AppAct_SysDrv_apf[LLI_u8].Cyclic_pcb)();
                }
            }
            else
            {
                DrvCyclicCnt_u8 += (t_uint8)1;
            }
        }
        if(DrvCyclicCnt_u8 == (t_uint8)0)
        {
            s_IsDrvCylic_b = (t_bool)False;
        }
    }

    return Ret_e;
}
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

