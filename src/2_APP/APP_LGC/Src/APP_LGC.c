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

//********************************************************************************
//                      Local functions - Prototypes
//********************************************************************************
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
    Ret_e = FMKCPU_Set_EvntChannelCfg(FMKCPU_EVENT_CHANNEL_1, 3000, s_APPLGC_callback);
    Ret_e = FMKCPU_Set_ChannelState(FMKCPU_TIMER_16, FMKCPU_CHANNEL_1, FMKCPU_CHNLST_ACTIVATED);
    return Ret_e;
}

/*********************************
 * APPLGC_Init
 *********************************/
t_eReturnState APPLGC_Cyclic(void)
{
    t_eReturnState Ret_e = RC_OK;
    // code to run every x milliseconds, config in APPSYS_ConfigPrivate.h
    //Ret_e = FMKIO_Set_InDigSigCfg(FMKIO_INPUT_SIGDIG_10, FMKIO_PULL_MODE_UNABLE);
    //Ret_e = FMKIO_Set_InDigSigCfg(FMKIO_INPUT_SIGDIG_11, FMKIO_PULL_MODE_UNABLE);
    //Ret_e = FMKIO_Set_InDigSigCfg(FMKIO_INPUT_SIGDIG_12, FMKIO_PULL_MODE_UNABLE);
    //Ret_e = FMKIO_Set_InDigSigCfg(FMKIO_INPUT_SIGDIG_9, FMKIO_PULL_MODE_UNABLE);
    //Ret_e = FMKIO_Set_InDigSigCfg(FMKIO_INPUT_SIGDIG_10, FMKIO_PULL_MODE_UNABLE);
    return Ret_e;
}
//********************************************************************************
//                      Local functions - Implementation
//********************************************************************************
static t_eReturnState s_APPLGC_callback(t_eFMKCPU_Timer f_timer_e, t_eFMKCPU_InterruptChnl f_channel_e)
{
    t_eReturnState Ret_e = RC_OK;
    
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

