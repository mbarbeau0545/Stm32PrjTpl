/**
 * @file        FMK_MAC.c
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
#include "./FMK_MAC.h"
#include "FMK_CFG/FMKCFG_ConfigFiles/FMKMAC_ConfigPrivate.h"
#include "FMK_HAL/FMK_CPU/Src/FMK_CPU.h"
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
    FMKMAC_ERRSTATE_OK = 0x000U,                     /**< No error detected */
    FMKMAC_ERRSTATE_TRANSFER_COMPLETE = 0x001,       /**< THe transfer is completed with an error */
    FMKMAC_ERRSTATE_TRANSFER_ERROR = 0x002,          /**< THe transfer is incomplete with an error */
    FMKMAC_ERRSTATE_FIFO = 0x004,                    /**< FIFO error, over/under debit from FIFO to DMA */
    FMKMAC_ERRSTATE_DIRECT_MODE = 0x008,             /**< An error with direct mode DMA has been detected*/
    FMKMAC_ERRSTATE_INVALID_CHANNEL = 0x010,         /**< DMA cannal invalid */
    FMKMAC_ERRSTATE_CONFIGURATION = 0x020,           /**< A configuration error has been detected */
    FMKMAC_ERRSTATE_PRIORITY = 0x040,                /**< Priority DMA has not been respected */
    FMKMAC_ERRSTATE_MEM_ALLOCATION = 0x080,          /**< Error allocation memory (FIFO not allowed) */
    FMKMAC_ERRSTATE_TIMEOUT = 0x100                  /**< Timeout delay (transfer has take too many time)*/
} t_eFMKMAC_DmaChnlErr;

/* CAUTION : Automatic generated code section for Structure: Start */

/* CAUTION : Automatic generated code section for Structure: End */
//-----------------------------STRUCT TYPES---------------------------//

typedef struct
{
    DMA_HandleTypeDef bspDma_ps;            /**< @ref  DMA_HandleTypeDef*/
    IRQn_Type NVICType_e;                   /**< NVIC channel interruption config*/
    t_eFMKMAC_DmaChnlErr chnlErr_e;         /**< @ref t_eFMKMAC_DmaChnlErr*/
} t_sFMKMAC_DmaChnlInfo;

typedef struct 
{
    t_sFMKMAC_DmaChnlInfo channel_as[FMKMAC_DMA_CHANNEL_NB];        /**< @ref  t_sFMKMAC_DmaChnlInfo*/
    const t_eFMKCPU_ClockPort clock_e;                              /**< constant to store the clock for each ADC */   
    t_bool isConfigured_b;                                          /**< Flag channel is configured */
} t_sFMKMAC_DmaInfo;
/* CAUTION : Automatic generated code section : Start */

/* CAUTION : Automatic generated code section : End */
//-----------------------------TYPEDEF TYPES---------------------------//
// ********************************************************************
// *                      Prototypes
// ********************************************************************
	
// ********************************************************************
// *                      Variables
// ********************************************************************
t_sFMKMAC_DmaInfo g_DmaInfo_as[FMKMAC_DMA_CTRL_NB] = {
    { // DMA1_CONTROLLER
        .clock_e = FMKCPU_RCC_CLK_DMA1,
        .isConfigured_b = False,
        .channel_as = {
            [FMKMAC_DMA_CHANNEL_1] = {
                .bspDma_ps = { .Instance = DMA1_Channel1 },  
                .NVICType_e = DMA1_Channel1_IRQn,
                .chnlErr_e = FMKMAC_ERRSTATE_OK,
            },
            [FMKMAC_DMA_CHANNEL_2] = {
                .bspDma_ps = { .Instance = DMA1_Channel2 }, 
                .NVICType_e = DMA1_Channel2_3_IRQn,
                .chnlErr_e = FMKMAC_ERRSTATE_OK,
            },
            [FMKMAC_DMA_CHANNEL_3] = {
                .bspDma_ps = { .Instance = DMA1_Channel3 }, 
                .NVICType_e = DMA1_Channel2_3_IRQn,
                .chnlErr_e = FMKMAC_ERRSTATE_OK,
            },
            [FMKMAC_DMA_CHANNEL_4] = {
                .bspDma_ps = { .Instance = DMA1_Channel4 },  
                .NVICType_e = DMA1_Channel4_5_IRQn,
                .chnlErr_e = FMKMAC_ERRSTATE_OK,
            },
            [FMKMAC_DMA_CHANNEL_5] = {
                .bspDma_ps = { .Instance = DMA1_Channel5 },  
                .NVICType_e = DMA1_Channel4_5_IRQn,
                .chnlErr_e = FMKMAC_ERRSTATE_OK,
            }
        }
    }
};
//********************************************************************************
//                      Local functions - Prototypes
//********************************************************************************
/**
*
*	@brief      Function to get the bsp dma channel
*
*	@param[in]  f_channel_e              : enum value for the channel, value from @ref t_eFMKCPU_InterruptChnl
*	@param[in]  f_bspChnl_pu32           : storage for bsp channel.\n
*
*  @retval RC_OK                             @ref RC_OK
*  @retval RC_ERROR_PARAM_INVALID            @ref RC_ERROR_PARAM_INVALID
*  @retval RC_ERROR_PTR_NULL                 @ref RC_ERROR_PTR_NULL
*  @retval RC_ERROR_PARAM_NOT_SUPPORTED      @ref RC_ERROR_PARAM_NOT_SUPPORTED
*
*/
static t_eReturnState s_FMKMAC_Set_DmaBspCfg(t_eFMKMAC_DmaRqstType f_RqstType_e,
                                                DMA_HandleTypeDef * f_bspDma_ps,
                                                t_eFMKMAC_DmaTransferPriority f_dmaPrio_e);
/**
*
*	@brief      Function to get the bsp dma priority
*
*	@param[in]  f_channel_e              : enum value for the channel, value from @ref t_eFMKCPU_InterruptChnl
*	@param[in]  f_bspPriority_pu32       : storage for bsp prioirty.\n
*
*  @retval RC_OK                             @ref RC_OK
*  @retval RC_ERROR_PARAM_INVALID            @ref RC_ERROR_PARAM_INVALID
*  @retval RC_ERROR_PTR_NULL                 @ref RC_ERROR_PTR_NULL
*  @retval RC_ERROR_PARAM_NOT_SUPPORTED      @ref RC_ERROR_PARAM_NOT_SUPPORTED
*
*/
static t_eReturnState s_FMKMAC_Get_DmaBspPriority(t_eFMKMAC_DmaTransferPriority f_priority_e, t_uint32 * f_bspPriority_pu32);
//********************************************************************************
//                      Public functions - Implementation
//********************************************************************************
t_eReturnState FMKMAC_RqstDmaInit(t_eFMKMAC_DmaRqstType f_DmaType, 
                                    void *f_ModuleHandle_pv)
{
    t_eReturnState Ret_e = RC_OK;
    HAL_StatusTypeDef bspRet_e = HAL_OK;
    t_eFMKMAC_DmaChnl channel_e;
    t_eFMKMAC_DmaController dmaCtrl_e;
    t_sFMKMAC_DmaChnlInfo * DmaChnl_ps;

    if (f_DmaType > FMKMAC_DMA_RQSTYPE_NB)
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
    } 
    if(f_ModuleHandle_pv == (void *)NULL)
    {
        Ret_e = RC_ERROR_PTR_NULL;
    }
    if(g_DmaInfo_as[f_DmaType].isConfigured_b == (t_bool)True)
    {
        Ret_e = RC_ERROR_ALREADY_CONFIGURED;
    }
    if(Ret_e == RC_OK)
    {
        dmaCtrl_e = c_FmkMac_DmaRqstCfg_as[f_DmaType].Ctrl_e;
        channel_e = c_FmkMac_DmaRqstCfg_as[f_DmaType].Chnl_e;
        DmaChnl_ps = &g_DmaInfo_as[dmaCtrl_e].channel_as[channel_e];
        // configure hardware clock to access register
        Ret_e = FMKCPU_Set_HwClock(g_DmaInfo_as[dmaCtrl_e].clock_e, FMKCPU_CLOCKPORT_OPE_ENABLE);
        if(Ret_e == RC_OK)
        {// Configure Dma channel NVIC priority if not done yet
            Ret_e = FMKCPU_Set_NVICState(DmaChnl_ps->NVICType_e, FMKCPU_NVIC_OPE_ENABLE);
        }
        if(Ret_e == RC_OK)
        {   
            Ret_e = s_FMKMAC_Set_DmaBspCfg(f_DmaType, 
                                            &DmaChnl_ps->bspDma_ps,
                                            c_FmkMac_DmaRqstCfg_as[f_DmaType].transfPrio_e);
        }
        if(Ret_e == RC_OK)
        {
            bspRet_e = HAL_DMA_Init(&DmaChnl_ps->bspDma_ps);
            if(bspRet_e == HAL_OK)
            {
                g_DmaInfo_as[dmaCtrl_e].isConfigured_b = (t_bool)True;
                //__HAL_LINKDMA((ADC_HandleTypeDef *)f_moduleHandle_pv,
                //                (DMA_HandleTypeDef *)DMA_Handle,
                //                f_bspDma_ps);
            }
            else
            {   
                Ret_e = RC_ERROR_WRONG_RESULT;
            }
        }
    }

    return Ret_e;
}
//********************************************************************************
//                      Local functions - Implementation
//********************************************************************************
/***********************************
 * s_FMKMAC_SetDmaBspCfg
 ***********************************/
static t_eReturnState s_FMKMAC_Set_DmaBspCfg(t_eFMKMAC_DmaRqstType f_RqstType_e,
                                                DMA_HandleTypeDef * f_bspDma_ps,
                                                t_eFMKMAC_DmaTransferPriority f_dmaPrio_e)
{
    t_eReturnState Ret_e = RC_OK;
    t_uint32 bspPriority_u32 = 0;

    if(f_RqstType_e > FMKMAC_DMA_RQSTYPE_NB)
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
    }
    if(f_bspDma_ps == (DMA_HandleTypeDef *)NULL)
    {
        Ret_e = RC_ERROR_PTR_NULL;
    }
    if(Ret_e == RC_OK)
    {
        Ret_e = s_FMKMAC_Get_DmaBspPriority(f_dmaPrio_e, &bspPriority_u32);
    }
    if(Ret_e == RC_OK)
    {
        f_bspDma_ps->Init.Priority = bspPriority_u32;
        switch (f_RqstType_e)
        {
            case FMKMAC_DMA_RQSTYPE_ADC1:
            {
                f_bspDma_ps->Init.Direction = DMA_PERIPH_TO_MEMORY;
                f_bspDma_ps->Init.Mode = DMA_CIRCULAR;
                f_bspDma_ps->Init.PeriphInc = DMA_PINC_DISABLE;
                f_bspDma_ps->Init.MemInc = DMA_MINC_ENABLE;
                f_bspDma_ps->Init.MemDataAlignment = DMA_MDATAALIGN_WORD;
                f_bspDma_ps->Init.PeriphDataAlignment = DMA_PDATAALIGN_WORD;
                
                break;
            }
            case FMKMAC_DMA_RQSTYPE_SPI1:
            case FMKMAC_DMA_RQSTYPE_SPI2:
            case FMKMAC_DMA_RQSTYPE_UART1:
            default:
                Ret_e = RC_ERROR_NOT_SUPPORTED;
                break;
        }
    }
    return Ret_e;
}

/***********************************
 * s_FMKMAC_Get_DmaBspPriority
 ***********************************/
static t_eReturnState s_FMKMAC_Get_DmaBspPriority(t_eFMKMAC_DmaTransferPriority f_priority_e, t_uint32 * f_bspPriority_pu32)
{
    t_eReturnState Ret_e = RC_OK;

    if(f_priority_e > FMKMAC_DMA_TRANSPRIO_NB)
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
    }
    if(f_bspPriority_pu32 == (t_uint32 *)0)
    {
        Ret_e = RC_ERROR_PTR_NULL;
    }
    if(Ret_e == RC_OK)
    {
        switch(f_priority_e)
        {
            case FMKMAC_DMA_TRANSPRIO_LOW:
                *f_bspPriority_pu32 = DMA_PRIORITY_LOW;
                break;
            case FMKMAC_DMA_TRANSPRIO_MEDIUM:
                *f_bspPriority_pu32 = DMA_PRIORITY_MEDIUM;
                break;
            case FMKMAC_DMA_TRANSPRIO_HIGH:
                *f_bspPriority_pu32 = DMA_PRIORITY_HIGH;
                break;
            case FMKMAC_DMA_TRANSPRIO_VERY_HIGH:
                *f_bspPriority_pu32 = DMA_PRIORITY_VERY_HIGH;
                break;
            case FMKMAC_DMA_TRANSPRIO_NB:
            default:
                Ret_e = RC_ERROR_NOT_SUPPORTED;
                break;
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
