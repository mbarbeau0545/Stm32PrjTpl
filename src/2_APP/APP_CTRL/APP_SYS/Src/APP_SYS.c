/*********************************************************************
 * @file        APP_SYS.c
 * @brief       Template_BriefDescription.
 * @details     TemplateDetailsDescription.\n
 *
 * @author      xxxxxx
 * @date        jj/mm/yyyy
 * @version     1.0
 */






// ********************************************************************
// *                      Includes
// ********************************************************************
#include "./APP_CFG/ConfigFiles/APPSYS_ConfigPrivate.h"
#include "./APP_SYS.h"
#include "APP_LGC/Src/APP_LGC.h"
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
t_eCyclicFuncState g_ModuleState_ae[APPSYS_MODULE_NB];
//********************************************************************************
//                      Local functions - Prototypes
//********************************************************************************

//****************************************************************************
//                      Public functions - Implementation
//********************************************************************************
/*********************************
 * APPSYS_Init
 *********************************/
void APPSYS_Init(void)
{
    t_eReturnState Ret_e = RC_OK;
    t_uint8 LLI_u8 = 0;

    while(LLI_u8 < (t_uint8)(APPSYS_MODULE_NB))
    {
        g_ModuleState_ae[LLI_u8] = STATE_CYCLIC_WAITING;
        Ret_e = c_AppSys_ModuleFunc_apf[LLI_u8].funcInit_cb();
        if(Ret_e == RC_OK)
        {
            LLI_u8 += (t_uint8)1;
        }
    }
    return;
}
/*********************************
 * APPSYS_Init
 *********************************/
void APPSYS_Cyclic(void)
{
    t_eReturnState Ret_e = RC_OK;
    t_uint8 LLI_u8 = 0;
    t_uint8 ModuleInitCnt_u8 = 0;
    t_uint32 currentCnt_u32 = 0;
    static t_uint32 s_previousCnt_u32 = 0;
    t_uint32 elapsedTime_u32 =  0;
    static t_bool   s_IsAllModInitialized_b = False;
    
    Ret_e = FMKCPU_Get_Tick(&currentCnt_u32);
    if(Ret_e == RC_OK)
    {
        Ret_e = FMKCPU_ResetWwdg();
    }
    if(Ret_e == RC_OK)
    {
        elapsedTime_u32 = (t_uint32)(currentCnt_u32 - s_previousCnt_u32);
        if((elapsedTime_u32) > APPSYS_ELAPSED_TIME_CYCLIC)
        {
            // reset whatchdog for fmk/app cycle
           
            s_previousCnt_u32 = currentCnt_u32;
           // call every fmk/app function cyclic
            for(LLI_u8 = (t_uint8)0 ; (LLI_u8 < (t_uint8)APPSYS_MODULE_NB) && (Ret_e == RC_OK) ; LLI_u8++)
            {
                Ret_e = c_AppSys_ModuleFunc_apf[LLI_u8].funcCyclic_cb();
                if((s_IsAllModInitialized_b == (t_bool)False) && (Ret_e == RC_OK))
                {
                    Ret_e = c_AppSys_ModuleFunc_apf[LLI_u8].funcGetState_cb(&g_ModuleState_ae[LLI_u8]);
                    if(g_ModuleState_ae[LLI_u8] == STATE_CYCLIC_OPE
                    || g_ModuleState_ae[LLI_u8] == STATE_CYCLIC_WAITING)
                    {
                        ModuleInitCnt_u8 += 1;
                    }
                }
            }
        // manage error
        }
        if(Ret_e == RC_OK)
        {
            // reset watchdog for logic cycle
            Ret_e = FMKCPU_ResetWwdg();
        }
        if(Ret_e == RC_OK)
        {
            switch (s_IsAllModInitialized_b)
            {
                case False:
                {// see if all module are in WaitingMode means ready for logic
                    if(ModuleInitCnt_u8 == (t_uint8)APPSYS_MODULE_NB)
                    {
                        // Update state for module which are waiting to be in Logic Mode
                        for(LLI_u8 = (t_uint8)0 ; (LLI_u8 <  (t_uint8)APPSYS_MODULE_NB) && (Ret_e == RC_OK) ; LLI_u8++)
                        {
                            if(g_ModuleState_ae[LLI_u8] == STATE_CYCLIC_WAITING)
                            {
                                Ret_e = c_AppSys_ModuleFunc_apf[LLI_u8].funcSetState_cb(STATE_CYCLIC_OPE);
                            }
                        }
                        s_IsAllModInitialized_b = True;
                    }
                    break;
                }
                case True:
                {
                    Ret_e = APPLGC_Cyclic();
                    if(Ret_e != RC_OK)
                    {
                        // deal error 
                    }
                    break;
                }
            }
        }
    }

    return;
}
//********************************************************************************
//                      Local functions - Implementation
//********************************************************************************

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
