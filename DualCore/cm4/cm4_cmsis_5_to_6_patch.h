#ifndef CM4_CMSIS_5_to_6_PATCH
#define CM4_CMSIS_5_to_6_PATCH

#define CoreDebug_DEMCR_TRCENA_Msk  DCB_DEMCR_TRCENA_Msk
#define CoreDebug                   DCB

#define NVIC->IP                    NVIC->IPSR

#define SCB->SHP                    SCB->SHPR
#define SCB->PFR                    SCB->ID_PFR
#define SCB->DFR                    SCB->ID_DFR
#define SCB->ADR                    SCB->ID_AFR
#define SCB->MMFR                   SCB->ID_MMFR
#define SCB->ISAR                   SCB->ID_ISAR       

#endif