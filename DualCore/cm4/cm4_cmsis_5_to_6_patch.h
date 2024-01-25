#ifndef CM4_CMSIS_5_to_6_PATCH
#define CM4_CMSIS_5_to_6_PATCH

#if defined (__CM_CMSIS_VERSION_MAIN) && (__CM_CMSIS_VERSION_MAIN >= 6)

#define CoreDebug_DEMCR_TRCENA_Msk      DCB_DEMCR_TRCENA_Msk
#define CoreDebug                       DCB
       

#define ITM_TCR_TraceBusID_Pos          ITM_TCR_TRACEBUSID_Pos
#define ITM_TCR_TraceBusID_Msk          ITM_TCR_TRACEBUSID_Msk
#define ITM_TCR_TSPrescale_Pos          ITM_TCR_TSPRESCALE_Pos
#define ITM_TCR_TSPrescale_Msk          ITM_TCR_TSPRESCALE_Msk

#define ITM_LSR_ByteAcc_Pos             ITM_LSR_BYTEACC_Pos
#define ITM_LSR_ByteAcc_Msk             ITM_LSR_BYTEACC_Msk
#define ITM_LSR_Access_Pos              ITM_LSR_ACCESS_Pos
#define ITM_LSR_Access_Msk              ITM_LSR_ACCESS_Msk
#define ITM_LSR_Present_Pos             ITM_LSR_PRESENT_Pos
#define ITM_LSR_Present_Msk             ITM_LSR_PRESENT_Msk

#define TPI                             TPIU
#define TPI_ACPR_PRESCALER_Pos 	        TPIU_ACPR_PRESCALER_Pos  
#define TPI_ACPR_PRESCALER_Msk 	        TPIU_ACPR_PRESCALER_Msk  
#define TPI_SPPR_TXMODE_Pos    	        TPIU_SPPR_TXMODE_Pos     
#define TPI_SPPR_TXMODE_Msk    	        TPIU_SPPR_TXMODE_Msk     
    
    
#define TPI_FFSR_FtNonStop_Pos 	        TPIU_FFSR_FtNonStop_Pos  
#define TPI_FFSR_FtNonStop_Msk 	        TPIU_FFSR_FtNonStop_Msk  
    
#define TPI_FFSR_TCPresent_Pos 	        TPIU_FFSR_TCPresent_Pos  
#define TPI_FFSR_TCPresent_Msk 	        TPIU_FFSR_TCPresent_Msk  
    
#define TPI_FFSR_FtStopped_Pos 	        TPIU_FFSR_FtStopped_Pos  
#define TPI_FFSR_FtStopped_Msk 	        TPIU_FFSR_FtStopped_Msk  
    
#define TPI_FFSR_FlInProg_Pos  	        TPIU_FFSR_FlInProg_Pos   
#define TPI_FFSR_FlInProg_Msk  	        TPIU_FFSR_FlInProg_Msk              

#define TPI_FFCR_TrigIn_Pos        	    TPIU_FFCR_TrigIn_Pos         
#define TPI_FFCR_TrigIn_Msk        	    TPIU_FFCR_TrigIn_Msk         
    
#define TPI_FFCR_EnFCont_Pos       	    TPIU_FFCR_EnFCont_Pos        
#define TPI_FFCR_EnFCont_Msk       	    TPIU_FFCR_EnFCont_Msk        
    
#define TPI_TRIGGER_TRIGGER_Pos    	    TPIU_TRIGGER_TRIGGER_Pos     
#define TPI_TRIGGER_TRIGGER_Msk    	    TPIU_TRIGGER_TRIGGER_Msk     
    
#define TPI_FIFO0_ITM_ATVALID_Pos  	    TPIU_FIFO0_ITM_ATVALID_Pos   
#define TPI_FIFO0_ITM_ATVALID_Msk  	    TPIU_FIFO0_ITM_ATVALID_Msk   
    
#define TPI_FIFO0_ITM_bytecount_Pos	    TPIU_FIFO0_ITM_bytecount_Pos 
#define TPI_FIFO0_ITM_bytecount_Msk	    TPIU_FIFO0_ITM_bytecount_Msk 
    
#define TPI_FIFO0_ETM_ATVALID_Pos  	    TPIU_FIFO0_ETM_ATVALID_Pos   
#define TPI_FIFO0_ETM_ATVALID_Msk  	    TPIU_FIFO0_ETM_ATVALID_Msk   
    
#define TPI_FIFO0_ETM_bytecount_Pos	    TPIU_FIFO0_ETM_bytecount_Pos 
#define TPI_FIFO0_ETM_bytecount_Msk	    TPIU_FIFO0_ETM_bytecount_Msk 
    
#define TPI_FIFO0_ETM2_Pos         	    TPIU_FIFO0_ETM2_Pos          
#define TPI_FIFO0_ETM2_Msk         	    TPIU_FIFO0_ETM2_Msk          
    
#define TPI_FIFO0_ETM1_Pos         	    TPIU_FIFO0_ETM1_Pos          
#define TPI_FIFO0_ETM1_Msk         	    TPIU_FIFO0_ETM1_Msk          
    
#define TPI_FIFO0_ETM0_Pos         	    TPIU_FIFO0_ETM0_Pos          
#define TPI_FIFO0_ETM0_Msk         	    TPIU_FIFO0_ETM0_Msk          
    
#define TPI_ITATBCTR2_ATREADY2_Pos 	    TPIU_ITATBCTR2_ATREADY2_Pos  
#define TPI_ITATBCTR2_ATREADY2_Msk 	    TPIU_ITATBCTR2_ATREADY2_Msk  
    
#define TPI_ITATBCTR2_ATREADY1_Pos 	    TPIU_ITATBCTR2_ATREADY1_Pos  
#define TPI_ITATBCTR2_ATREADY1_Msk 	    TPIU_ITATBCTR2_ATREADY1_Msk  
    
#define TPI_FIFO1_ITM_ATVALID_Pos  	    TPIU_FIFO1_ITM_ATVALID_Pos   
#define TPI_FIFO1_ITM_ATVALID_Msk  	    TPIU_FIFO1_ITM_ATVALID_Msk   
    
#define TPI_FIFO1_ITM_bytecount_Pos	    TPIU_FIFO1_ITM_bytecount_Pos 
#define TPI_FIFO1_ITM_bytecount_Msk	    TPIU_FIFO1_ITM_bytecount_Msk 
    
#define TPI_FIFO1_ETM_ATVALID_Pos  	    TPIU_FIFO1_ETM_ATVALID_Pos    
#define TPI_FIFO1_ETM_ATVALID_Msk  	    TPIU_FIFO1_ETM_ATVALID_Msk    
    
#define TPI_FIFO1_ETM_bytecount_Pos	    TPIU_FIFO1_ETM_bytecount_Pos  
#define TPI_FIFO1_ETM_bytecount_Msk	    TPIU_FIFO1_ETM_bytecount_Msk 

#define TPI_FIFO1_ITM2_Pos             	TPIU_FIFO1_ITM2_Pos          
#define TPI_FIFO1_ITM2_Msk             	TPIU_FIFO1_ITM2_Msk          
	
#define TPI_FIFO1_ITM1_Pos             	TPIU_FIFO1_ITM1_Pos          
#define TPI_FIFO1_ITM1_Msk             	TPIU_FIFO1_ITM1_Msk          
	
#define TPI_FIFO1_ITM0_Pos             	TPIU_FIFO1_ITM0_Pos          
#define TPI_FIFO1_ITM0_Msk             	TPIU_FIFO1_ITM0_Msk          
	
	
#define TPI_ITATBCTR0_ATREADY2_Pos     	TPIU_ITATBCTR0_ATREADY2_Pos  
#define TPI_ITATBCTR0_ATREADY2_Msk     	TPIU_ITATBCTR0_ATREADY2_Msk  
	
#define TPI_ITATBCTR0_ATREADY1_Pos     	TPIU_ITATBCTR0_ATREADY1_Pos  
#define TPI_ITATBCTR0_ATREADY1_Msk     	TPIU_ITATBCTR0_ATREADY1_Msk  
	
	
#define TPI_ITCTRL_Mode_Pos            	TPIU_ITCTRL_Mode_Pos         
#define TPI_ITCTRL_Mode_Msk            	TPIU_ITCTRL_Mode_Msk         
	
	
#define TPI_DEVID_NRZVALID_Pos         	TPIU_DEVID_NRZVALID_Pos      
#define TPI_DEVID_NRZVALID_Msk         	TPIU_DEVID_NRZVALID_Msk      
	
#define TPI_DEVID_MANCVALID_Pos        	TPIU_DEVID_MANCVALID_Pos     
#define TPI_DEVID_MANCVALID_Msk        	TPIU_DEVID_MANCVALID_Msk     
	
#define TPI_DEVID_PTINVALID_Pos        	TPIU_DEVID_PTINVALID_Pos     
#define TPI_DEVID_PTINVALID_Msk        	TPIU_DEVID_PTINVALID_Msk     
	
#define TPI_DEVID_MinBufSz_Pos         	TPIU_DEVID_MinBufSz_Pos      
#define TPI_DEVID_MinBufSz_Msk         	TPIU_DEVID_MinBufSz_Msk      
	
#define TPI_DEVID_AsynClkIn_Pos        	TPIU_DEVID_AsynClkIn_Pos     
#define TPI_DEVID_AsynClkIn_Msk        	TPIU_DEVID_AsynClkIn_Msk     
	
#define TPI_DEVID_NrTraceInput_Pos     	TPIU_DEVID_NrTraceInput_Pos  
#define TPI_DEVID_NrTraceInput_Msk     	TPIU_DEVID_NrTraceInput_Msk  
	
#define TPI_DEVTYPE_SubType_Pos   	    TPIU_DEVTYPE_SubType_Pos   
#define TPI_DEVTYPE_SubType_Msk   	    TPIU_DEVTYPE_SubType_Msk   
    
#define TPI_DEVTYPE_MajorType_Pos 	    TPIU_DEVTYPE_MajorType_Pos 
#define TPI_DEVTYPE_MajorType_Msk 	    TPIU_DEVTYPE_MajorType_Msk 	
	
	
#endif
#endif
