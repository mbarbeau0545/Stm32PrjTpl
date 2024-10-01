/*********************************************************************
 * @file        APP_LGC.c
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

#include "./APP_LGC.h"
#include "FMK_HAL/FMK_CPU/Src/FMK_CPU.h"
#include "FMK_HAL/FMK_IO/Src/FMK_IO.h"
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
static t_eReturnState s_APPLGC_Operational(void);
static t_eReturnState s_APPLGC_PreOperational(void);

static t_eReturnState s_APPLGC_callback(t_eFMKCPU_Timer f_timer_e, t_eFMKCPU_InterruptChnl f_channel_e);
//****************************************************************************
//                      Public functions - Implementation
//********************************************************************************
/*********************************
 * APPLGC_Init
 *********************************/
t_eReturnState APPLGC_Init(void)
{
    t_eReturnState Ret_e = RC_OK;
    
    
    return Ret_e;
}

/*********************************
 * APPLGC_Init
 *********************************/
t_eReturnState APPLGC_Cyclic(void)
{
    t_eReturnState Ret_e = RC_OK;
    // code to run every x milliseconds, config in APPSYS_ConfigPrivate.h

    switch (g_state_e)
    {
    case STATE_CYCLIC_PREOPE:
    {
        Ret_e = s_APPLGC_PreOperational();
        if(Ret_e == RC_OK)
        {
            g_state_e = STATE_CYCLIC_WAITING;
        }
        break;
    }

    case STATE_CYCLIC_WAITING:
    {
        // nothing to do, just wait all module are Ope
        break;
    }
    case STATE_CYCLIC_OPE:
    {
        Ret_e = s_APPLGC_Operational();
        if(Ret_e < RC_OK)
        {
            g_state_e = STATE_CYCLIC_ERROR;
        }
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
 * APPLGC_GetState
 *********************************/
t_eReturnState APPLGC_GetState(t_eCyclicFuncState *f_State_pe)
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
 * APPLGC_SetState
 *********************************/
t_eReturnState APPLGC_SetState(t_eCyclicFuncState f_State_e)
{

    g_state_e = f_State_e;

    return RC_OK;
}
//********************************************************************************
//                      Local functions - Implementation
//********************************************************************************
static t_eReturnState s_APPLGC_callback(t_eFMKCPU_Timer f_timer_e, t_eFMKCPU_InterruptChnl f_channel_e)
{
    t_eReturnState Ret_e = RC_OK;
    static t_uint32 last_tick_u32;
    t_uint32 current_tick_u23;
    t_uint32 elasped_time_u32;
    static t_eFMKIO_DigValue s_digval_e = FMKIO_DIG_VALUE_HIGH;

    if(s_digval_e == FMKIO_DIG_VALUE_HIGH)
    {
        s_digval_e = FMKIO_DIG_VALUE_LOW;
    }
    else
    {
        s_digval_e = FMKIO_DIG_VALUE_HIGH;
    }

    Ret_e = FMKCPU_Get_Tick(&current_tick_u23);
    if(Ret_e == RC_OK)
    {
        Ret_e = FMKIO_Set_OutDigSigValue(FMKIO_OUTPUT_SIGDIG_1, s_digval_e);
    }
    if(Ret_e == RC_OK)
    {
        elasped_time_u32 = (current_tick_u23 - last_tick_u32);
        if(elasped_time_u32 > (t_uint32)0)
        {
            last_tick_u32 = current_tick_u23;
            elasped_time_u32 += 1;
            Ret_e = RC_WARNING_BUSY;
        }
    }
    return Ret_e;
}

/*********************************
 * s_APPLGC_PreOperational
 *********************************/
static t_eReturnState s_APPLGC_PreOperational(void)
{
    t_eReturnState Ret_e = RC_OK;
    //Ret_e = FMKIO_Set_InDigSigCfg(FMKIO_INPUT_SIGDIG_10, FMKIO_PULL_MODE_UNABLE);
    //Ret_e = FMKIO_Set_InDigSigCfg(FMKIO_INPUT_SIGDIG_11, FMKIO_PULL_MODE_UNABLE);
    //Ret_e = FMKIO_Set_InDigSigCfg(FMKIO_INPUT_SIGDIG_12, FMKIO_PULL_MODE_UNABLE);
    //Ret_e = FMKIO_Set_InDigSigCfg(FMKIO_INPUT_SIGDIG_9, FMKIO_PULL_MODE_UNABLE);
    //Ret_e = FMKIO_Set_InDigSigCfg(FMKIO_INPUT_SIGDIG_10, FMKIO_PULL_MODE_UNABLE);
    Ret_e = FMKIO_Set_OutDigSigCfg(FMKIO_OUTPUT_SIGDIG_1, FMKIO_PULL_MODE_UNABLE, FMKIO_SPD_MODE_LOW);
    if(Ret_e == RC_OK)
    {
        Ret_e = FMKCP_Set_EvntTimerCfg(FMKCPU_TIMER_16, 62000, s_APPLGC_callback);
    }
    if(Ret_e == RC_OK)
    {
        Ret_e = FMKCPU_Set_EventTimerState(FMKCPU_TIMER_16, FMKCPU_TIMST_ACTIVATED);
    }
    return Ret_e;
}

/*********************************
 * s_APPLGC_Operational
 *********************************/
static t_eReturnState s_APPLGC_Operational(void)
{
    t_eReturnState Ret_e = RC_OK;
    //Ret_e = FMKIO_Set_OutDigSigValue(FMKIO_OUTPUT_SIGDIG_1, FMKIO_DIG_VALUE_HIGH);
    //HAL_Delay(1000);
    //Ret_e = FMKIO_Set_OutDigSigValue(FMKIO_OUTPUT_SIGDIG_1, FMKIO_DIG_VALUE_LOW);
    //HAL_Delay(1000);
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

