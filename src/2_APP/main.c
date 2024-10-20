/*********************************************************************
 * @file        item.h
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
#include "APP_CTRL/APP_SYS/Src/APP_SYS.h"

#include "FMK_HAL/FMK_CPU/Src/FMK_CPU.h"
#include "APP_LGC/Src/APP_LGC.h"
// ********************************************************************
// *                      Defines
// ********************************************************************
/* If define only logic Init & Cyclic are called
*  else all framework & application function are called
*/
//#define STANDALONE_MODE 

// ********************************************************************
// *                      Prototypes
// ********************************************************************
    
// ********************************************************************
// *                      Variables
// ********************************************************************

//********************************************************************************
//                      main
//********************************************************************************
int main(void)
{
    #ifdef STANDALONE_MODE
        t_eReturnState Ret_e = RC_OK;
        Ret_e = FMKCPU_Set_HardwareInit();
        if(Ret_e == RC_OK)
        {
            Ret_e = FMKCPU_Set_SysClockCfg();
        }
        if(Ret_e == RC_OK)
        {
            APPLGC_Init();
        }
        if(Ret_e != RC_OK)
        {
            while(1){}
        }
    #else
        APPSYS_Init();
    #endif
    while (1)
    {
        #ifdef STANDALONE_MODE
            APPLGC_Cyclic();
        #else
            APPSYS_Cyclic();
        #endif
    }
    return 0;
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
 *	@param[in]
 *	@param[out]
 *
 *
 *
 */
