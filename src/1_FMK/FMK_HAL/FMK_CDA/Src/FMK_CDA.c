/*********************************************************************
 * @file        FMK_IO.c
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
#include "./FMK_CDA.h"
#include "FMK_HAL/FMK_MAC/Src/FMK_MAC.h"
#include "FMK_HAL/FMK_CPU/Src/FMK_CPU.h"
#include "FMK_CFG/FMKCFG_ConfigFiles/FMKCDA_ConfigPrivate.h"
#include "stm32f0xx_hal.h"

// ********************************************************************
// *                      Defines
// ********************************************************************
#define FMKCDA_CHNLCFG_PER_CYCLE ((t_uint8)5) /* Number of channel configuration per Cycle*/
// ********************************************************************
// *                      Types
// ********************************************************************
//-----------------------------ENUM TYPES-----------------------------//
/* CAUTION : Automatic generated code section for Enum: Start */

/* CAUTION : Automatic generated code section for Enum: End */
/* Channel error status*/
typedef enum
{
    FMKCDA_CHANNEL_STATE_OK = 0,
    FMKCDA_CHANNEL_STATE_ERR_INTERNAL,
    FMKCDA_CHANNEL_STATE_ERR_OVR,
    FMKCDA_CHANNEL_STATE_ERR_DMA,
    FMKCDA_CHANNEL_STATE_CB,
    FMKCDA_CHANNEL_STATE_JQOVF,

    FMKCDA_CHANNEL_STATE_NB
} t_eFMKCDA_ChnlErrState;

//-----------------------------TYPEDEF TYPES---------------------------//
//-----------------------------STRUCT TYPES---------------------------//
/* CAUTION : Automatic generated code section for Structure: Start */

/* CAUTION : Automatic generated code section for Structure: End */

typedef struct
{
    t_uint16 rawValue_au16[FMKCDA_ADC_CHANNEL_NB];
    t_uint8 BspChnlmapp[FMKCDA_ADC_CHANNEL_NB];
    t_bool FlagValueUpdated_b;
} t_sFMKCDA_AdcBuffer;

/* Structure for adc channel info*/
typedef struct
{
    t_uint16 rawValue_u16;
    t_bool FlagValueUpdated_b;
    t_bool IsChnlUsed_b;
    t_bool IsChnlConfigured_b;
    t_eFMKCDA_ChnlErrState Error_e;
} t_sFMKCDA_ChnlInfo;

/* Structure for adc info*/
typedef struct
{
    ADC_HandleTypeDef BspInit_s;
    t_eFMKCDA_HwAdcCfg HwCfg_e;
    t_sFMKCDA_ChnlInfo Channel_as[FMKCDA_ADC_CHANNEL_NB];
    const t_eFMKCPU_ClockPort clock_e;
    const t_eFMKCPU_IRQNType IRQNType_e;
    t_bool IsAdcConfigured_b;
    t_bool IsAdcRunning_b;
} t_sFMKCDA_AdcInfo;
// ********************************************************************
// *                      Prototypes
// ********************************************************************

// ********************************************************************
// *                      Variables
// ********************************************************************
/*store the raw value for each channel of each adc converter*/
t_sFMKCDA_AdcBuffer g_AdcBuffer_as[FMKCDA_ADC_NB];
// Flag automatic generate code
/* Store the Adc Info variable*/
t_sFMKCDA_AdcInfo g_AdcInfo_as[FMKCDA_ADC_NB] = {
    {
        // ADC_1
        .BspInit_s.Instance = ADC1,
        .clock_e = FMKCPU_RCC_CLK_ADC1,
        .IRQNType_e = ADC1_IRQn,
    }};

t_eCyclicFuncState g_state_e = STATE_CYCLIC_WAITING;

//********************************************************************************
//                      Local functions - Prototypes
//********************************************************************************
/*****************************************************************************
 *
 *	@brief
 *	@details
 *
 *
 *	@param[in]
 *	@param[out]
 *
 *
 *
 */
static t_eReturnState s_FMKCDA_Get_BspChannel(t_eFMKCDA_AdcChannel f_channel_e, t_uint32 *f_bspChannel_32);
/*****************************************************************************
 *
 *	@brief
 *	@details
 *
 *
 *	@param[in]
 *	@param[out]
 *
 *
 *
 */
static t_eReturnState s_FMKCDA_Set_BspAdcCfg(t_eFMKCDA_Adc f_Adc_e,
                                             t_eFMKCDA_HwAdcCfg f_HwAdcCfg_e);
/*****************************************************************************
 *
 *	@brief
 *	@details
 *
 *
 *	@param[in]
 *	@param[out]
 *
 *
 *
 */
static t_eReturnState s_FMKCDA_Set_BspChannelCfg(t_eFMKCDA_Adc f_Adc_e, t_eFMKCDA_AdcChannel f_channel_e);
/*****************************************************************************
 *
 *	@brief
 *	@details
 *
 *
 *	@param[in]
 *	@param[out]
 *
 *
 *
 */
static t_eReturnState s_FMKCDA_PreOperational(void);
/*****************************************************************************
 *
 *	@brief
 *	@details
 *
 *
 *	@param[in]
 *	@param[out]
 *
 *
 *
 */
static t_eReturnState s_FMKCDA_Operational(void);
//****************************************************************************
//                      Public functions - Implementation
//********************************************************************************
/*********************************
 * FMKCDA_Init
 *********************************/
t_eReturnState FMKCDA_Init(void)
{
    t_uint8 LLI1_u8 = 0;
    t_uint8 LLI2_u8 = 0;
    // initiate to default value variable structure
    for (LLI1_u8 = (t_uint8)0; LLI1_u8 < (t_uint8)FMKCDA_ADC_NB; LLI1_u8++)
    { // all timer
        g_AdcInfo_as[LLI1_u8].IsAdcConfigured_b = (t_bool)False;
        g_AdcInfo_as[LLI1_u8].IsAdcRunning_b = (t_bool)False;

        for (LLI2_u8 = (t_uint8)0; LLI2_u8 < (t_uint8)FMKCDA_ADC_CHANNEL_NB; LLI2_u8++)
        { // all channel for a timer
            g_AdcInfo_as[LLI1_u8].Channel_as[LLI2_u8].IsChnlConfigured_b = (t_bool)False;
            g_AdcInfo_as[LLI1_u8].Channel_as[LLI2_u8].Error_e = FMKCDA_CHANNEL_STATE_OK;
            g_AdcInfo_as[LLI1_u8].Channel_as[LLI2_u8].IsChnlUsed_b = (t_bool)False;
            g_AdcInfo_as[LLI1_u8].Channel_as[LLI2_u8].rawValue_u16 = (t_uint16)0;
        }
    }
    return RC_OK;
}

/*********************************
 * FMKCDA_Init
 *********************************/
t_eReturnState FMKCDA_Cyclic(void)
{
    t_eReturnState Ret_e = RC_OK;

    switch (g_state_e)
    {
    case STATE_CYCLIC_PREOPE:
    {
        Ret_e = s_FMKCDA_PreOperational();
        break;
    }
    case STATE_CYCLIC_OPE:
    {
        Ret_e = s_FMKCDA_Operational();
        break;
    }
    case STATE_CYCLIC_WAITING:
    {
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
 * FMKCDA_Set_AdcChannelCfg
 *********************************/
t_eReturnState FMKCDA_Set_AdcChannelCfg(t_eFMKCDA_Adc f_Adc_e,
                                        t_eFMKCDA_AdcChannel f_channel_e,
                                        t_eFMKCDA_HwAdcCfg f_hwAdcCfg_e)
{
    t_eReturnState Ret_e = RC_OK;

    if (f_Adc_e > FMKCDA_ADC_NB || f_channel_e > FMKCDA_ADC_CHANNEL_NB)
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
    }
    if (Ret_e == RC_OK)
    {
        if (g_AdcInfo_as[f_Adc_e].IsAdcConfigured_b == (t_bool)False)
        { // configure adc timer
            Ret_e = s_FMKCDA_Set_BspAdcCfg((t_eFMKCDA_Adc)f_Adc_e,
                                           f_hwAdcCfg_e);
            if (Ret_e == RC_OK)
            {
#warning "Only Scan/DMA mode is trreated for AdcChannel Configuration"
                Ret_e = FMKMAC_RqstDmaInit(FMKMAC_DMA_RQSTYPE_ADC1, (void *)&g_AdcInfo_as[f_Adc_e].BspInit_s);
                if (Ret_e == RC_OK)
                {
                    g_AdcInfo_as[f_Adc_e].IsAdcConfigured_b = True;
                    g_AdcInfo_as[f_Adc_e].HwCfg_e = f_hwAdcCfg_e;
                }
            }
        }
        if (Ret_e == RC_OK)
        { // Configure Channel
            Ret_e = s_FMKCDA_Set_BspChannelCfg(f_Adc_e, f_channel_e);
        }
    }
    return Ret_e;
}

/*********************************
 * FMKCDA_Get_AnaChannelMeasure
 *********************************/
t_eReturnState FMKCDA_Get_AnaChannelMeasure(t_eFMKCDA_Adc f_Adc_e, t_eFMKCDA_AdcChannel f_channel_e, t_uint16 *f_AnaMeasure_u16)
{
    t_eReturnState Ret_e = RC_OK;

    if (f_Adc_e > FMKCDA_ADC_NB || f_channel_e > FMKCDA_ADC_CHANNEL_NB)
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
    }
    if (f_AnaMeasure_u16 == (t_uint16 *)NULL)
    {
        Ret_e = RC_ERROR_PTR_NULL;
    }
    if (Ret_e == RC_OK)
    {
        // give the last raw analog value if value is updated
        if (g_AdcInfo_as[f_Adc_e].Channel_as[f_channel_e].FlagValueUpdated_b == (t_bool)True)
        {
            *f_AnaMeasure_u16 = g_AdcInfo_as[f_Adc_e].Channel_as[f_channel_e].rawValue_u16;
        }
        else
        {
            *f_AnaMeasure_u16 = (t_uint16)0;
            Ret_e = RC_ERROR_BUSY;
        }
    }
    return Ret_e;
}
//********************************************************************************
//                      Local functions - Implementation
//********************************************************************************
/*********************************
 * s_FMKCDA_Operational
 *********************************/
static t_eReturnState s_FMKCDA_Operational(void)
{
    t_eReturnState Ret_e = RC_OK;
    t_uint8 timerCnt_u8 = 0;
    t_uint8 chnlCnt_u8 = 0;
    t_uint8 rankInBuffer_u8 = 0;

    for (timerCnt_u8 = (t_uint8)0; timerCnt_u8 < (t_uint8)FMKCDA_ADC_NB; timerCnt_u8++)
    {
        if (g_AdcBuffer_as[timerCnt_u8].FlagValueUpdated_b == (t_bool)True)
        {
            for (chnlCnt_u8 = (t_uint8)0; chnlCnt_u8 < (t_uint8)FMKCDA_ADC_CHANNEL_NB; chnlCnt_u8++)
            {
                if (g_AdcInfo_as[timerCnt_u8].Channel_as[chnlCnt_u8].IsChnlUsed_b == (t_bool)True)
                {
                    rankInBuffer_u8 = g_AdcBuffer_as[timerCnt_u8].BspChnlmapp[chnlCnt_u8];
                    g_AdcInfo_as[timerCnt_u8].Channel_as[chnlCnt_u8].rawValue_u16 =
                        g_AdcBuffer_as[timerCnt_u8].rawValue_au16[rankInBuffer_u8];
                }
            }
        }
    }
#warning "ADC SCAN not set"
    return Ret_e;
}

/*********************************
 * s_FMKCDA_Get_BspChannel
 *********************************/
static t_eReturnState s_FMKCDA_Get_BspChannel(t_eFMKCDA_AdcChannel f_channel_e, t_uint32 *f_bspChannel_32)
{
    t_eReturnState Ret_e = RC_OK;
    if (f_channel_e > FMKCDA_ADC_CHANNEL_NB)
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
    }
    if (f_bspChannel_32 == (t_uint32 *)NULL)
    {
        Ret_e = RC_ERROR_PTR_NULL;
    }
    if (Ret_e == RC_OK)
    {
        switch (f_channel_e)
        {
        case FMKCDA_ADC_CHANNEL_0:
            *f_bspChannel_32 = ADC_CHANNEL_0;
            break;
        case FMKCDA_ADC_CHANNEL_1:
            *f_bspChannel_32 = ADC_CHANNEL_1;
            break;
        case FMKCDA_ADC_CHANNEL_2:
            *f_bspChannel_32 = ADC_CHANNEL_2;
            break;
        case FMKCDA_ADC_CHANNEL_3:
            *f_bspChannel_32 = ADC_CHANNEL_3;
            break;
        case FMKCDA_ADC_CHANNEL_4:
            *f_bspChannel_32 = ADC_CHANNEL_4;
            break;
        case FMKCDA_ADC_CHANNEL_5:
            *f_bspChannel_32 = ADC_CHANNEL_5;
            break;
        case FMKCDA_ADC_CHANNEL_6:
            *f_bspChannel_32 = ADC_CHANNEL_6;
            break;
        case FMKCDA_ADC_CHANNEL_7:
            *f_bspChannel_32 = ADC_CHANNEL_7;
            break;
        case FMKCDA_ADC_CHANNEL_8:
            *f_bspChannel_32 = ADC_CHANNEL_8;
            break;
        case FMKCDA_ADC_CHANNEL_9:
            *f_bspChannel_32 = ADC_CHANNEL_9;
            break;
        case FMKCDA_ADC_CHANNEL_10:
            *f_bspChannel_32 = ADC_CHANNEL_10;
            break;
        case FMKCDA_ADC_CHANNEL_11:
            *f_bspChannel_32 = ADC_CHANNEL_11;
            break;
        case FMKCDA_ADC_CHANNEL_12:
            *f_bspChannel_32 = ADC_CHANNEL_12;
            break;
        case FMKCDA_ADC_CHANNEL_13:
            *f_bspChannel_32 = ADC_CHANNEL_13;
            break;
        case FMKCDA_ADC_CHANNEL_14:
            *f_bspChannel_32 = ADC_CHANNEL_14;
            break;
        case FMKCDA_ADC_CHANNEL_15:
            *f_bspChannel_32 = ADC_CHANNEL_15;
            break;
        case FMKCDA_ADC_CHANNEL_16:
            *f_bspChannel_32 = ADC_CHANNEL_16;
            break;
        case FMKCDA_ADC_CHANNEL_17:
            *f_bspChannel_32 = ADC_CHANNEL_17;
            break;
        case FMKCDA_ADC_CHANNEL_NB:
        default:
            Ret_e = RC_WARNING_NO_OPERATION;
        }
    }
    return Ret_e;
}

/*********************************
 * s_FMKCDA_Set_BspAdcCfg
 *********************************/
static t_eReturnState s_FMKCDA_Set_BspAdcCfg(t_eFMKCDA_Adc f_Adc_e,
                                             t_eFMKCDA_HwAdcCfg f_HwAdcCfg_e)
{
    t_eReturnState Ret_e = RC_OK;
    HAL_StatusTypeDef BspRet_e = HAL_OK;
    ADC_InitTypeDef *bspAdcInit_s;

    if (f_Adc_e > FMKCDA_ADC_NB || f_HwAdcCfg_e > FMKCDA_ADC_CFG_NB)
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
    }
    if (Ret_e == RC_OK)
    {
        bspAdcInit_s = &g_AdcInfo_as[f_Adc_e].BspInit_s.Init;
        // Set shared Init varaible
        bspAdcInit_s->ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV4;
        bspAdcInit_s->Resolution = ADC_RESOLUTION_12B;
        bspAdcInit_s->DataAlign = ADC_DATAALIGN_RIGHT;
        bspAdcInit_s->SamplingTimeCommon = ADC_SAMPLETIME_13CYCLES_5; // Assuming a default value
        bspAdcInit_s->EOCSelection = ADC_EOC_SEQ_CONV;
        bspAdcInit_s->LowPowerAutoPowerOff = ENABLE;
        switch (f_HwAdcCfg_e)
        {
        case FMKCDA_ADC_CFG_BASIC_REGISTER:
        {
            bspAdcInit_s->ScanConvMode = DISABLE;
            bspAdcInit_s->ContinuousConvMode = DISABLE;
            bspAdcInit_s->DiscontinuousConvMode = DISABLE;
            bspAdcInit_s->DMAContinuousRequests = DISABLE;
            bspAdcInit_s->ExternalTrigConv = ADC_SOFTWARE_START;
            bspAdcInit_s->ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
            break;
        }
        case FMKCDA_ADC_CFG_PERIODIC_INTERRUPT:
        {
            bspAdcInit_s->ScanConvMode = DISABLE;
            bspAdcInit_s->ContinuousConvMode = ENABLE;
            bspAdcInit_s->DiscontinuousConvMode = DISABLE;
            bspAdcInit_s->DMAContinuousRequests = DISABLE;
            bspAdcInit_s->ExternalTrigConv = ADC_SOFTWARE_START;
            bspAdcInit_s->ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
            break;
        }
        case FMKCDA_ADC_CFG_PERIODIC_DMA:
        {
            bspAdcInit_s->ScanConvMode = DISABLE;
            bspAdcInit_s->ContinuousConvMode = ENABLE;
            bspAdcInit_s->DiscontinuousConvMode = DISABLE;
            bspAdcInit_s->DMAContinuousRequests = ENABLE;
            bspAdcInit_s->ExternalTrigConv = ADC_SOFTWARE_START;
            bspAdcInit_s->ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
            break;
        }
        case FMKCDA_ADC_CFG_SCAN_INTERRUPT:
        {
            bspAdcInit_s->ScanConvMode = ENABLE;
            bspAdcInit_s->ContinuousConvMode = DISABLE;
            bspAdcInit_s->DiscontinuousConvMode = DISABLE;
            bspAdcInit_s->DMAContinuousRequests = DISABLE;
            bspAdcInit_s->ExternalTrigConv = ADC_SOFTWARE_START;
            bspAdcInit_s->ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
            break;
        }
        case FMKCDA_ADC_CFG_SCAN_DMA:
        {
            bspAdcInit_s->ScanConvMode = ADC_SCAN_ENABLE;
            bspAdcInit_s->ContinuousConvMode = DISABLE;
            bspAdcInit_s->DiscontinuousConvMode = DISABLE;
            bspAdcInit_s->DMAContinuousRequests = ENABLE;
            bspAdcInit_s->ExternalTrigConv = ADC_SOFTWARE_START;
            bspAdcInit_s->ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
            break;
        }
        case FMKCDA_ADC_CFG_TRIGGERED_REGISTER:
        {
            bspAdcInit_s->ScanConvMode = DISABLE;
            bspAdcInit_s->ContinuousConvMode = DISABLE;
            bspAdcInit_s->DiscontinuousConvMode = DISABLE;
            bspAdcInit_s->DMAContinuousRequests = DISABLE;
            bspAdcInit_s->ExternalTrigConv = ADC_EXTERNALTRIGCONV_T1_CC4; // Example trigger source
            bspAdcInit_s->ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_RISING;
            break;
        }
        case FMKCDA_ADC_CFG_TRIGGERED_INTERRUPT:
        {
            bspAdcInit_s->ScanConvMode = DISABLE;
            bspAdcInit_s->ContinuousConvMode = DISABLE;
            bspAdcInit_s->DiscontinuousConvMode = DISABLE;
            bspAdcInit_s->DMAContinuousRequests = DISABLE;
            bspAdcInit_s->ExternalTrigConv = ADC_EXTERNALTRIGCONV_T1_CC4; // Example trigger source
            bspAdcInit_s->ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_RISING;
            break;
        }
        case FMKCDA_ADC_CFG_TRIGGERED_DMA:
        {
            bspAdcInit_s->ScanConvMode = DISABLE;
            bspAdcInit_s->ContinuousConvMode = DISABLE;
            bspAdcInit_s->DiscontinuousConvMode = DISABLE;
            bspAdcInit_s->DMAContinuousRequests = ENABLE;
            bspAdcInit_s->ExternalTrigConv = ADC_EXTERNALTRIGCONV_T1_CC4; // Example trigger source
            bspAdcInit_s->ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_RISING;
            break;
        }
        case FMKCDA_ADC_CFG_NB:
        default:
            Ret_e = RC_WARNING_NO_OPERATION;
        }
        // CAllBsp Func
        Ret_e = FMKCPU_Set_HwClock(g_AdcInfo_as[f_Adc_e].clock_e, FMKCPU_CLOCKPORT_OPE_ENABLE);
        if (Ret_e == RC_OK)
        {
            BspRet_e = HAL_ADC_Init(&g_AdcInfo_as[f_Adc_e].BspInit_s);

            if (BspRet_e == HAL_OK)
            {
                g_AdcInfo_as[f_Adc_e].IsAdcConfigured_b = (t_bool)True;
            }
        }
        else
        {
            Ret_e = RC_ERROR_WRONG_STATE;
        }
    }
    return Ret_e;
}

/*********************************
 * s_FMKCDA_Set_BspChannelCfg
 *********************************/
static t_eReturnState s_FMKCDA_Set_BspChannelCfg(t_eFMKCDA_Adc f_Adc_e, t_eFMKCDA_AdcChannel f_channel_e)
{
    t_eReturnState Ret_e = RC_OK;
    HAL_StatusTypeDef BspRet_e = HAL_OK;
    t_uint32 bspChannel_u32 = 0;
    static t_uint8 s_counterRank_u8 = 1;

    ADC_ChannelConfTypeDef BspChannelInit_s = {.SamplingTime = ADC_SAMPLETIME_13CYCLES_5}; // all channel ave this cfg

    if (f_Adc_e > FMKCDA_ADC_NB)
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
    }
    if (Ret_e == RC_OK)
    {
        // configure channel
        Ret_e = s_FMKCDA_Get_BspChannel(f_channel_e, &bspChannel_u32);

        if (Ret_e == RC_OK)
        {
            BspChannelInit_s.Channel = bspChannel_u32;
            BspChannelInit_s.Rank = s_counterRank_u8;
            BspRet_e = HAL_ADC_ConfigChannel(&g_AdcInfo_as[f_Adc_e].BspInit_s,
                                             &BspChannelInit_s);

            if (BspRet_e == HAL_OK)
            {
                // update mapping
                g_AdcBuffer_as[f_Adc_e].BspChnlmapp[f_channel_e] = s_counterRank_u8;
                g_AdcInfo_as[f_Adc_e].Channel_as[f_channel_e].IsChnlConfigured_b = (t_bool)True;
                s_counterRank_u8 += (t_uint8)1;
            }
            else
            {
                Ret_e = RC_ERROR_WRONG_STATE;
            }
        }
    }
    return Ret_e;
}

//********************************************************************************
//                      HAL_Callback Implementation
//********************************************************************************
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc)
{
    t_uint8 LLI_u8 = 8;
    t_eFMKCDA_Adc IT_Adc_e = FMKCDA_ADC_NB;
    for (LLI_u8 = (t_uint8)0; LLI_u8 < (t_uint8)FMKCDA_ADC_NB; LLI_u8++)
    {
        if (&g_AdcInfo_as[LLI_u8].BspInit_s == (ADC_HandleTypeDef *)hadc)
        {
            IT_Adc_e = (t_eFMKCDA_Adc)LLI_u8;
            break;
        }
    }
    if (IT_Adc_e < FMKCDA_ADC_NB)
    {
        g_AdcBuffer_as[LLI_u8].FlagValueUpdated_b = (t_bool)True;
    }
    return;
}
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
