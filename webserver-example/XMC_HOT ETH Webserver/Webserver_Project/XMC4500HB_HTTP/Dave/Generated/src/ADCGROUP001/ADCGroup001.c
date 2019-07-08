
/*CODE_BLOCK_BEGIN[ADCGROUP001.c]*/

/*******************************************************************************
 Copyright (c) 2011, Infineon Technologies AG                                 **
 All rights reserved.                                                         **
                                                                              **
 Redistribution and use in source and binary forms, with or without           **
 modification,are permitted provided that the following conditions are met:   **
                                                                              **
 *Redistributions of source code must retain the above copyright notice,      **
 this list of conditions and the following disclaimer.                        **
 *Redistributions in binary form must reproduce the above copyright notice,   **
 this list of conditions and the following disclaimer in the documentation    **
 and/or other materials provided with the distribution.                       **
 *Neither the name of the copyright holders nor the names of its contributors **
 may be used to endorse or promote products derived from this software without**
 specific prior written permission.                                           **
                                                                              **
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  **
 AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    **
 IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   **
 ARE  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE   **
 LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR         **
 CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF         **
 SUBSTITUTE GOODS OR  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    **
 INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN      **
 CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)       **
 ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   **
 POSSIBILITY OF SUCH DAMAGE.                                                  **
                                                                              **
 To improve the quality of the software, users are encouraged to share        **
 modifications, enhancements or bug fixes with Infineon Technologies AG       **
 dave@infineon.com).                                                          **
                                                                              **
********************************************************************************
**                                                                            **
**                                                                            **
** PLATFORM : Infineon XMC4000 Series                                         **
**                                                                            **
** COMPILER : Compiler Independent                                            **
**                                                                            **
** AUTHOR   : DAVE App Developer                                              **
**                                                                            **
** MAY BE CHANGED BY USER [yes/no]: Yes                                       **
**                                                                            **
** MODIFICATION DATE : July 31, 2012                                          **
**                                                                            **
*******************************************************************************/

/******************************************************************************
**                      Author(s) Identity                                   **
*******************************************************************************
**                                                                           **
** Initials     Name                                                         **
** CM           DAVE App Developer                                           **
** --------------------------------------------------------------------------**

*******************************************************************************/


/**
 * @file ADCGROUP001.c
 *
 * @brief This file contains ADCGROUP001 App API definitions
 *
 */

/*******************************************************************************
 ** INCLUDE FILES                                                             **
 ******************************************************************************/
#include <DAVE3.h>

/**
 * @cond INTERNAL_DOCS
 */

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                 Private Function Declarations:
*******************************************************************************/
/**
 * @brief This function initializes the app.
 *
 * @param [in] HandlePtr pointer to the Instance variable<BR>
 *
 * @return  NOne <BR>
 *
 * <b>Reentrancy:  Yes</b><BR>
 * <b>Sync/Async:  Synchronous</b><BR>
 */

void ADCGROUP001_lInit(const ADCGROUP001_HandleType *HandlePtr );

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                 Function like macro definitions                            **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Public Function Definitions                           **
*******************************************************************************/



/** This function initializes the app */
void ADCGROUP001_Init(void)
{
/*Initialize the global app */
  ADCGLOB001_Init();    
  ADCGROUP001_lInit(&ADCGROUP001_Handle0);   
}

/* 
 * This Function initializes the adcgroup App. Local function is used to 
 * initialize all the instances of the app.
 */
void ADCGROUP001_lInit(const ADCGROUP001_HandleType *HandlePtr )
{
  /*Pointer to the VADC Structure */
  VADC_G_TypeDef *VADCGroupPtr;     
  /* Pointer to the VADC Kernel Structure */   
  VADC_GLOBAL_TypeDef *VADCGlobalPtr; 
  
  VADCGlobalPtr = HandlePtr->VADCGlobalPtr;
  VADCGroupPtr = HandlePtr->VADCGroupPtr;
  
  FUNCTION_ENTRY(GID_ADCGROUP001, ADCGROUP001_FUNCTION_ENTRY);
  
  if((HandlePtr->DynamicHandlePtr->State == ADCGROUP001_UNINITIALIZED))
  {
    
    /* Set the Post calibration enable\disable */
    WR_REG(VADCGlobalPtr->GLOBCFG, VADC_GLOBCFG_DPCAL0_Msk, 
          ((uint32_t)VADC_GLOBCFG_DPCAL0_Pos + HandlePtr->kGroupNo),
            HandlePtr->kPostCalibration);

    /*  Converter is permanently on */
    WR_REG(VADCGroupPtr->ARBCFG, VADC_G_ARBCFG_ANONC_Msk, 
           VADC_G_ARBCFG_ANONC_Pos, (uint32_t)HandlePtr->kAnalogConverterCtrl);

    /* Set the Arbitration mode */
    WR_REG(VADCGroupPtr->ARBCFG, VADC_G_ARBCFG_ARBM_Msk, VADC_G_ARBCFG_ARBM_Pos,
                                         (uint32_t)HandlePtr->kArbitrationMode);

    /* Set the Group specific boundary 0 */
    WR_REG(VADCGroupPtr->BOUND, VADC_G_BOUND_BOUNDARY0_Msk,
               VADC_G_BOUND_BOUNDARY0_Pos, (uint32_t)HandlePtr->kGrpBoundary0);
    
    /* Set the Group specific boundary 1 */
    WR_REG(VADCGroupPtr->BOUND, VADC_G_BOUND_BOUNDARY1_Msk,
               VADC_G_BOUND_BOUNDARY1_Pos, (uint32_t)HandlePtr->kGrpBoundary1);
                                                
    /*
     * Enable write control for EMUX configuration.
     * Set the EMUX coding scheme, EMUX mode, EMUX start select.
     */
    VADCGroupPtr->EMUXCTR |= (uint32_t)((((uint32_t)1 << VADC_G_EMUXCTR_EMXWC_Pos) & VADC_G_EMUXCTR_EMXWC_Msk) | \
                                        (((uint32_t)HandlePtr->kEMUXCodeScheme \
                                                << VADC_G_EMUXCTR_EMXCOD_Pos) & VADC_G_EMUXCTR_EMXCOD_Msk) | \
                                        (((uint32_t)HandlePtr->kEMUXStartSelect  \
                                              << VADC_G_EMUXCTR_EMUXSET_Pos) & VADC_G_EMUXCTR_EMUXSET_Msk) | \
                                        (((uint32_t)HandlePtr->kEMUXMode \
                                              << VADC_G_EMUXCTR_EMUXMODE_Pos) & VADC_G_EMUXCTR_EMUXMODE_Msk));
  
    /*
     * Set conversion mode, EMUX conversion mode, sample time control,
     * Set EMUX sample time control for class 0. 
     */
    VADCGroupPtr->ICLASS[0] |= (uint32_t)((((uint32_t)HandlePtr->kConversionModeClass0 \
                                                << VADC_G_ICLASS_CMS_Pos) & VADC_G_ICLASS_CMS_Msk) | \
                                          (((uint32_t)HandlePtr->kEMUXConversionModeClass0 \
                                                << VADC_G_ICLASS_CME_Pos) & VADC_G_ICLASS_CME_Msk) | \
                                          (((uint32_t)HandlePtr->kSampleTimeControlClass0 \
                                                << VADC_G_ICLASS_STCS_Pos) & VADC_G_ICLASS_STCS_Msk) | \
                                          (((uint32_t)HandlePtr->kEMUXSampleTimeControlClass0 \
                                                << VADC_G_ICLASS_STCE_Pos) & VADC_G_ICLASS_STCE_Msk));
                                                
    /*
     * Set conversion mode, EMUX conversion mode, sample time control,  
     * EMUX sample time control for class 1. 
     */
    VADCGroupPtr->ICLASS[1] |= (uint32_t)((((uint32_t)HandlePtr->kConversionModeClass1 \
                                                << VADC_G_ICLASS_CMS_Pos) & VADC_G_ICLASS_CMS_Msk) | \
                                          (((uint32_t)HandlePtr->kEMUXConversionModeClass1 \
                                                << VADC_G_ICLASS_CME_Pos) & VADC_G_ICLASS_CME_Msk) | \
                                          (((uint32_t)HandlePtr->kSampleTimeControlClass1 \
                                                << VADC_G_ICLASS_STCS_Pos) & VADC_G_ICLASS_STCS_Msk)  | \
                                          (((uint32_t)HandlePtr->kEMUXSampleTimeControlClass1 \
                                                    << VADC_G_ICLASS_STCE_Pos) & VADC_G_ICLASS_STCE_Msk));
     /* Enable/Disable Startup Calibration */     
    if(ADCGLOB001_StartUpCalibrationInit() == (uint32_t)DAVEApp_SUCCESS)
    {
      /* Set the App State to Initialized */
      HandlePtr->DynamicHandlePtr->State = ADCGROUP001_INITIALIZED;
    }
    else
    {
      ERROR(GID_ADCGROUP001, (uint8_t)Status, 0, (uint8_t*)NULL);  
    }
  }
  else
  {
    ERROR(GID_ADCGROUP001, (uint8_t)Status, 0, (uint8_t*)NULL);
  }

  FUNCTION_EXIT(GID_ADCGROUP001, ADCGROUP001_FUNCTION_EXIT);
}

/* This Function resets the adcgroup001 app */
status_t ADCGROUP001_Deinit(const ADCGROUP001_HandleType *HandlePtr )
{
  status_t Status = (uint32_t)ADCGROUP001_OPER_NOT_ALLOWED_ERROR;

  /*Pointer to the VADC Structure */
  VADC_G_TypeDef *VADCGroupPtr;            
  /* Pointer to the VADC Kernel Structure */
  VADC_GLOBAL_TypeDef *VADCGlobalPtr;     
  
  VADCGlobalPtr = HandlePtr->VADCGlobalPtr;
  VADCGroupPtr = HandlePtr->VADCGroupPtr;
  
  FUNCTION_ENTRY(GID_ADCGROUP001, ADCGROUP001_FUNCTION_ENTRY);

  if((HandlePtr->DynamicHandlePtr->State == ADCGROUP001_INITIALIZED))
  {
    /* Reset the Post calibration enable\disable */
    CLR_BIT(VADCGlobalPtr->GLOBCFG, VADC_GLOBCFG_DPCAL0_Pos);
  
    /* Reset the Arbitration mode */
    VADCGroupPtr->ARBCFG = (uint32_t)0x00;
  
    /* Reset the Group specific boundary */
    VADCGroupPtr->BOUND = (uint32_t)0x00;
  
    /* ReSet the EMUX control register */
    VADCGroupPtr->EMUXCTR = (uint32_t)(0X80000000);
  
    /* Reset class 0 input register*/
    VADCGroupPtr->ICLASS[0] = (uint32_t)0x00;
    /* Reset class 1 input register*/
    VADCGroupPtr->ICLASS[1] = (uint32_t)0x00;
  
    /* Set the App State to Initialized */
    HandlePtr->DynamicHandlePtr->State = ADCGROUP001_UNINITIALIZED;
  
    Status = (uint32_t)DAVEApp_SUCCESS;
  }
  else
  {
    ERROR(GID_ADCGROUP001, (uint8_t)Status, 0, (uint8_t*)NULL);
  }

  FUNCTION_EXIT(GID_ADCGROUP001, ADCGROUP001_FUNCTION_EXIT);
  return Status;
}


/* This Function sets the group specific boundary 0 */
status_t ADCGROUP001_SetGroupBound0(const ADCGROUP001_HandleType *HandlePtr,
                                                         uint16_t BoundaryValue)
{
  status_t Status = (uint32_t)ADCGROUP001_OPER_NOT_ALLOWED_ERROR;
  /*Pointer to the VADC Structure */
  VADC_G_TypeDef *VADCGroupPtr;              
  VADCGroupPtr = HandlePtr->VADCGroupPtr;
  
  FUNCTION_ENTRY(GID_ADCGROUP001, ADCGROUP001_FUNCTION_ENTRY);

  if(HandlePtr->DynamicHandlePtr->State == ADCGROUP001_INITIALIZED)
  {
    if(BoundaryValue <= (uint16_t)ADCGROUP001_MAX_BOUNDARY_VALUE)
    {
      /* Set the Group specific boundary 0 */
      WR_REG(VADCGroupPtr->BOUND, VADC_G_BOUND_BOUNDARY0_Msk, 
                           VADC_G_BOUND_BOUNDARY0_Pos, (uint32_t)BoundaryValue);  
      Status = (uint32_t)DAVEApp_SUCCESS;
    }
    else
    {
      Status = (uint32_t)ADCGROUP001_INVALID_PARAM_ERROR;
    }
  }
  else
  {
    ERROR(GID_ADCGROUP001, (uint8_t)Status, 0, (uint8_t*)NULL);
  }  

  FUNCTION_EXIT(GID_ADCGROUP001, ADCGROUP001_FUNCTION_EXIT);

  return Status;
}


/* This Function sets the group specific boundary 1 */
status_t ADCGROUP001_SetGroupBound1(const ADCGROUP001_HandleType *HandlePtr,
                                                         uint16_t BoundaryValue)
{
  status_t Status = (uint32_t)ADCGROUP001_OPER_NOT_ALLOWED_ERROR;
  /*Pointer to the VADC Structure */
  VADC_G_TypeDef *VADCGroupPtr;              
  VADCGroupPtr = HandlePtr->VADCGroupPtr;
  
  FUNCTION_ENTRY(GID_ADCGROUP001, ADCGROUP001_FUNCTION_ENTRY);
  
  if(HandlePtr->DynamicHandlePtr->State == ADCGROUP001_INITIALIZED)
  {
    if(BoundaryValue <= (uint16_t)ADCGROUP001_MAX_BOUNDARY_VALUE)
    {
      /* Set the Group specific boundary 0 */
      WR_REG(VADCGroupPtr->BOUND, VADC_G_BOUND_BOUNDARY1_Msk, 
                           VADC_G_BOUND_BOUNDARY1_Pos, (uint32_t)BoundaryValue);  
      Status = (uint32_t)DAVEApp_SUCCESS;
    }
    else
    {
      ERROR(GID_ADCGROUP001, (uint8_t)Status, 0, (uint8_t*)NULL);
      Status = (uint32_t)ADCGROUP001_INVALID_PARAM_ERROR;
    }
  }
  else
  {
    ERROR(GID_ADCGROUP001, (uint8_t)Status, 0, (uint8_t*)NULL);
  }  
  
  FUNCTION_EXIT(GID_ADCGROUP001, ADCGROUP001_FUNCTION_EXIT);
  
  return Status;
}


/* This function activates group specific service request node */
status_t ADCGROUP001_ActiveGroupServiceRequestNode(
                          const ADCGROUP001_HandleType *HandlePtr, uint8_t Node)
{
  status_t Status = (uint32_t)ADCGROUP001_OPER_NOT_ALLOWED_ERROR;
  /*Pointer to the VADC Structure */
  VADC_G_TypeDef *VADCGroupPtr;              
  VADCGroupPtr = HandlePtr->VADCGroupPtr;
  
  FUNCTION_ENTRY(GID_ADCGROUP001, ADCGROUP001_FUNCTION_ENTRY);

  if((HandlePtr->DynamicHandlePtr->State == ADCGROUP001_INITIALIZED))
  {
    if( Node <= (uint8_t)(ADCGROUP001_MAX_SERVICE_REQUEST_NODE - 1))
    {
      /* Activate the Group specific service request node */
      CLR_BIT(VADCGroupPtr->SRACT, ((uint32_t)VADC_G_SRACT_AGSR0_Pos + (uint32_t)Node));
      SET_BIT(VADCGroupPtr->SRACT, ((uint32_t)VADC_G_SRACT_AGSR0_Pos + (uint32_t)Node));
      Status = (uint32_t)DAVEApp_SUCCESS;
    }
    else 
    {
      Status = (uint32_t)ADCGROUP001_INVALID_PARAM_ERROR;
    }
  }
  else  
  {
   ERROR(GID_ADCGROUP001, (uint8_t)Status, 0, (uint8_t*)NULL);
  }
  
  FUNCTION_EXIT(GID_ADCGROUP001, ADCGROUP001_FUNCTION_EXIT);
  return Status;
}

/* This function deactivates group specific service request node */
status_t ADCGROUP001_DeActiveGroupServiceRequestNode(
                          const ADCGROUP001_HandleType *HandlePtr, uint8_t Node)
{
  status_t Status = (uint32_t)ADCGROUP001_OPER_NOT_ALLOWED_ERROR;
  /*Pointer to the VADC Structure */
  VADC_G_TypeDef *VADCGroupPtr;              
  VADCGroupPtr = HandlePtr->VADCGroupPtr;
  
  FUNCTION_ENTRY(GID_ADCGROUP001, ADCGROUP001_FUNCTION_ENTRY);

  if((HandlePtr->DynamicHandlePtr->State == ADCGROUP001_INITIALIZED))
  {
    if( Node <= (uint8_t)(ADCGROUP001_MAX_SERVICE_REQUEST_NODE - 1))
    {
      /* Deactivate the Group specific service request node */
      CLR_BIT(VADCGroupPtr->SRACT, ((uint32_t)VADC_G_SRACT_AGSR0_Pos + (uint32_t)Node));
      Status = (uint32_t)DAVEApp_SUCCESS;    
    }
    else 
    {
      Status = (uint32_t)ADCGROUP001_INVALID_PARAM_ERROR;
    }
  }
  else  
  {
    ERROR(GID_ADCGROUP001, (uint8_t)Status, 0, (uint8_t*)NULL); 
  }

  FUNCTION_EXIT(GID_ADCGROUP001, ADCGROUP001_FUNCTION_EXIT);
  return Status;
}

/* This function activates the shared service request node. */
status_t ADCGROUP001_ActiveSharedServiceRequestNode(
                          const ADCGROUP001_HandleType *HandlePtr, uint8_t Node)
{
  status_t Status = (uint32_t)ADCGROUP001_OPER_NOT_ALLOWED_ERROR;
  /*Pointer to the VADC Structure */
  VADC_G_TypeDef *VADCGroupPtr;              
  VADCGroupPtr = HandlePtr->VADCGroupPtr;
  
  FUNCTION_ENTRY(GID_ADCGROUP001, ADCGROUP001_FUNCTION_ENTRY);

  if((HandlePtr->DynamicHandlePtr->State == ADCGROUP001_INITIALIZED))
  {
    if( Node <= (uint8_t)(ADCGROUP001_MAX_SERVICE_REQUEST_NODE - 1))
    {
      /* Activates the shared service request node. */
      CLR_BIT(VADCGroupPtr->SRACT, ((uint32_t)VADC_G_SRACT_ASSR0_Pos + (uint32_t)Node));
      SET_BIT(VADCGroupPtr->SRACT, ((uint32_t)VADC_G_SRACT_ASSR0_Pos + (uint32_t)Node));    
  
      Status = (uint32_t)DAVEApp_SUCCESS;
    }
    else 
    {
      Status = (uint32_t)ADCGROUP001_INVALID_PARAM_ERROR;
    }
  }
  else  
  {
    ERROR(GID_ADCGROUP001, (uint8_t)Status, 0, (uint8_t*)NULL);    
  }
  
  FUNCTION_EXIT(GID_ADCGROUP001, ADCGROUP001_FUNCTION_EXIT);
  return Status;
}

/* This deactivates the shared service request node.*/
status_t ADCGROUP001_DeActiveSharedServiceRequestNode(
                          const ADCGROUP001_HandleType *HandlePtr, uint8_t Node)
{
  status_t Status = (uint32_t)ADCGROUP001_OPER_NOT_ALLOWED_ERROR;
  /*Pointer to the VADC Structure */
  VADC_G_TypeDef *VADCGroupPtr;              
  VADCGroupPtr = HandlePtr->VADCGroupPtr;
  
  FUNCTION_ENTRY(GID_ADCGROUP001, ADCGROUP001_FUNCTION_ENTRY);

  if((HandlePtr->DynamicHandlePtr->State == ADCGROUP001_INITIALIZED))
  {
    if( Node <= (uint8_t)(ADCGROUP001_MAX_SERVICE_REQUEST_NODE - 1))
    {
      /* Deactivate the shared service request node.*/
      CLR_BIT(VADCGroupPtr->SRACT, ((uint32_t)VADC_G_SRACT_ASSR0_Pos + (uint32_t)Node));                          
  
      Status = (uint32_t)DAVEApp_SUCCESS;
    }
    else 
    {
      Status = (uint32_t)ADCGROUP001_INVALID_PARAM_ERROR;
    }
  }
  else  
  {
    ERROR(GID_ADCGROUP001, (uint8_t)Status, 0, (uint8_t*)NULL);    
  }
  
  FUNCTION_EXIT(GID_ADCGROUP001, ADCGROUP001_FUNCTION_EXIT);
  return Status;
}


/* This Function sets the value of EMUX start selection. */
status_t ADCGROUP001_EMUXStartSelection(
          const ADCGROUP001_HandleType *HandlePtr, uint8_t StartSelectionValue)
{
  status_t Status = (uint32_t)ADCGROUP001_OPER_NOT_ALLOWED_ERROR;
  /*Pointer to the VADC Structure */
  VADC_G_TypeDef *VADCGroupPtr;              
  VADCGroupPtr = HandlePtr->VADCGroupPtr;

  FUNCTION_ENTRY(GID_ADCGROUP001, ADCGROUP001_FUNCTION_ENTRY);

  if((HandlePtr->DynamicHandlePtr->State == ADCGROUP001_INITIALIZED))
  {
    if( StartSelectionValue <= (uint8_t)ADCGROUP001_MAX_ADC_GROUP_CHANNEL)
    {
      /* Set the EMUX start selection */
      WR_REG(VADCGroupPtr->EMUXCTR, VADC_G_EMUXCTR_EMUXSET_Msk,
                     VADC_G_EMUXCTR_EMUXSET_Pos, (uint32_t)StartSelectionValue);
      Status = (uint32_t)DAVEApp_SUCCESS;
    }
    else 
    {
      Status = (uint32_t)ADCGROUP001_INVALID_PARAM_ERROR;
    }
  }
  else  
  {
    ERROR(GID_ADCGROUP001, (uint8_t)Status, 0, (uint8_t*)NULL);
  }
  
  FUNCTION_EXIT(GID_ADCGROUP001, ADCGROUP001_FUNCTION_EXIT);
  return Status;
}

/* This function gets the value of EMUX start selection. */
status_t ADCGROUP001_GetEMUXStartSelection(
       const ADCGROUP001_HandleType *HandlePtr, uint8_t *StartSelectionValuePtr)
{
  status_t Status = (uint32_t)ADCGROUP001_OPER_NOT_ALLOWED_ERROR;
  /*Pointer to the VADC Structure */
  VADC_G_TypeDef *VADCGroupPtr;              
  VADCGroupPtr = HandlePtr->VADCGroupPtr;
  
  FUNCTION_ENTRY(GID_ADCGROUP001, ADCGROUP001_FUNCTION_ENTRY);

  if((HandlePtr->DynamicHandlePtr->State == ADCGROUP001_INITIALIZED))
  {
    if(StartSelectionValuePtr != NULL)
    {
      /* Get the EMUX start selection*/
      *StartSelectionValuePtr = (uint8_t)RD_REG( VADCGroupPtr->EMUXCTR, 
                        VADC_G_EMUXCTR_EMUXSET_Msk, VADC_G_EMUXCTR_EMUXSET_Pos);
      Status = (uint32_t)DAVEApp_SUCCESS;
    }
    else 
    {
      Status = (uint32_t)ADCGROUP001_INVALID_PARAM_ERROR;
    }
  }
  else  
  {
    ERROR(GID_ADCGROUP001, (uint8_t)Status, 0, (uint8_t*)NULL);
  }
  FUNCTION_EXIT(GID_ADCGROUP001, ADCGROUP001_FUNCTION_EXIT);
  return Status;
}

/* This function sets the value of EMUX channel select. */
status_t ADCGROUP001_SetEMUXChannelSelect(
          const ADCGROUP001_HandleType *HandlePtr, uint8_t ChannelSelectValue)
{
  status_t Status = (uint32_t)ADCGROUP001_OPER_NOT_ALLOWED_ERROR;
  /*Pointer to the VADC Structure */
  VADC_G_TypeDef *VADCGroupPtr;                
  VADCGroupPtr = HandlePtr->VADCGroupPtr;

  FUNCTION_ENTRY(GID_ADCGROUP001, ADCGROUP001_FUNCTION_ENTRY);

  if((HandlePtr->DynamicHandlePtr->State == ADCGROUP001_INITIALIZED))
  {
    if( ChannelSelectValue <= (uint8_t)ADCGROUP001_TOTAL_ADC_CHANNEL )
    {
      /* Set the EMUX channel select*/
      WR_REG(VADCGroupPtr->EMUXCTR, VADC_G_EMUXCTR_EMUXCH_Msk,
                       VADC_G_EMUXCTR_EMUXCH_Pos, (uint32_t)ChannelSelectValue);
  
      Status = (uint32_t)DAVEApp_SUCCESS;
    }
    else
    {
      Status = (uint32_t)ADCGROUP001_INVALID_PARAM_ERROR;
    }
  }
  else  
  {
    ERROR(GID_ADCGROUP001, (uint8_t)Status, 0, (uint8_t*)NULL);
  }
  
  FUNCTION_EXIT(GID_ADCGROUP001, ADCGROUP001_FUNCTION_EXIT);
  return Status;
}

/* This function sets the value of EMUX mode. */
status_t ADCGROUP001_SetEMUXMode(const ADCGROUP001_HandleType *HandlePtr, 
                                                                  uint8_t Mode)
{
  status_t Status = (uint32_t)ADCGROUP001_OPER_NOT_ALLOWED_ERROR;
  uint32_t ModeTemp;
  /*Pointer to the VADC Structure */
  VADC_G_TypeDef *VADCGroupPtr;              
  VADCGroupPtr = HandlePtr->VADCGroupPtr;

  FUNCTION_ENTRY(GID_ADCGROUP001, ADCGROUP001_FUNCTION_ENTRY);

  if((HandlePtr->DynamicHandlePtr->State == ADCGROUP001_INITIALIZED))
  {
    if(Mode <= (uint8_t)ADCGROUP001_SEQUENCEMODE)
    {
      /* Set the EMUX mode*/
      ModeTemp = VADCGroupPtr->EMUXCTR;
      ModeTemp &= (uint32_t)~(VADC_G_EMUXCTR_EMUXMODE_Msk);
      ModeTemp |= (VADC_G_EMUXCTR_EMXWC_Msk) |
                      (((uint32_t)Mode << VADC_G_EMUXCTR_EMUXMODE_Pos) & VADC_G_EMUXCTR_EMUXMODE_Msk);
      VADCGroupPtr->EMUXCTR = ModeTemp;
  
      Status = (uint32_t)DAVEApp_SUCCESS;
    }
    else 
    {
      Status = (uint32_t)ADCGROUP001_INVALID_PARAM_ERROR;
    }
  }
  else  
  {
    ERROR(GID_ADCGROUP001, (uint8_t)Status, 0, (uint8_t*)NULL);
  }
  
  FUNCTION_EXIT(GID_ADCGROUP001, ADCGROUP001_FUNCTION_EXIT);
  return Status;
}


/* This function sets the value of EMUX coding scheme. */
status_t ADCGROUP001_SetEMUXCodeScheme(const ADCGROUP001_HandleType *HandlePtr, 
                                                            uint8_t CodeScheme)
{
  status_t Status = (uint32_t)ADCGROUP001_OPER_NOT_ALLOWED_ERROR;
  uint32_t CodeSchemeTemp = (uint32_t)0;
  /*Pointer to the VADC Structure */
  VADC_G_TypeDef *VADCGroupPtr;              
  VADCGroupPtr = HandlePtr->VADCGroupPtr;
  
  FUNCTION_ENTRY(GID_ADCGROUP001, ADCGROUP001_FUNCTION_ENTRY);

  if((HandlePtr->DynamicHandlePtr->State == ADCGROUP001_INITIALIZED))
  {
    if(CodeScheme <= (uint8_t)ADCGROUP001_GRAYCODE)
    {
      /* Set the EMUX code scheme*/
      CodeSchemeTemp = VADCGroupPtr->EMUXCTR;
      CodeSchemeTemp &= (uint32_t)~(VADC_G_EMUXCTR_EMXCOD_Msk);
      CodeSchemeTemp |= (VADC_G_EMUXCTR_EMXWC_Msk) |
                    (((uint32_t)CodeScheme << VADC_G_EMUXCTR_EMXCOD_Pos) & VADC_G_EMUXCTR_EMXCOD_Msk);
      VADCGroupPtr->EMUXCTR = CodeSchemeTemp;

      Status = (uint32_t)DAVEApp_SUCCESS;
    }
    else 
    {
      Status = (uint32_t)ADCGROUP001_INVALID_PARAM_ERROR;
    }
  }
  else  
  {
    ERROR(GID_ADCGROUP001, (uint8_t)Status, 0, (uint8_t*)NULL);
  }
  
  FUNCTION_EXIT(GID_ADCGROUP001, ADCGROUP001_FUNCTION_EXIT);
  return Status;
}

/* This function sets the sample time for standard conversion mode */
status_t ADCGROUP001_SetGroupClass0SampleTime(
                                        const ADCGROUP001_HandleType *HandlePtr, 
                                                             uint8_t SampleTime)
{
  status_t Status = (uint32_t)ADCGROUP001_OPER_NOT_ALLOWED_ERROR;
  /*Pointer to the VADC Structure */
  VADC_G_TypeDef *VADCGroupPtr;              
  VADCGroupPtr = HandlePtr->VADCGroupPtr;
  
  FUNCTION_ENTRY(GID_ADCGROUP001, ADCGROUP001_FUNCTION_ENTRY);

  if((HandlePtr->DynamicHandlePtr->State == ADCGROUP001_INITIALIZED))
  {
    if(SampleTime < (uint8_t)ADCGROUP001_MAX_SAMPLE_TIME_CONTROL_VAL)
    {
      /* Set standard sample time control for class 0 */
      WR_REG(VADCGroupPtr->ICLASS[0], VADC_G_ICLASS_STCS_Msk,
                                 VADC_G_ICLASS_STCS_Pos, (uint32_t)SampleTime);
  
      Status = (uint32_t)DAVEApp_SUCCESS;
    }
    else
    {
      Status = (uint32_t)ADCGROUP001_INVALID_PARAM_ERROR;
    }  
  }
  else  
  {
    ERROR(GID_ADCGROUP001, (uint8_t)Status, 0, (uint8_t*)NULL);
  }
 
  FUNCTION_EXIT(GID_ADCGROUP001, ADCGROUP001_FUNCTION_EXIT);
  return Status;
}


/* This function sets the sample time for standard conversion mode */
status_t ADCGROUP001_SetGroupClass1SampleTime(
                                        const ADCGROUP001_HandleType *HandlePtr, 
                                                             uint8_t SampleTime)
{
  status_t Status = (uint32_t)ADCGROUP001_OPER_NOT_ALLOWED_ERROR;
  /*Pointer to the VADC Structure */
  VADC_G_TypeDef *VADCGroupPtr;              
  VADCGroupPtr = HandlePtr->VADCGroupPtr;
  
  FUNCTION_ENTRY(GID_ADCGROUP001, ADCGROUP001_FUNCTION_ENTRY);

  if((HandlePtr->DynamicHandlePtr->State == ADCGROUP001_INITIALIZED))
  {
    if(SampleTime < (uint8_t)ADCGROUP001_MAX_SAMPLE_TIME_CONTROL_VAL)
    {
      /* Set standard sample time control for class 1 */
      WR_REG(VADCGroupPtr->ICLASS[1], VADC_G_ICLASS_STCS_Msk,
                                 VADC_G_ICLASS_STCS_Pos, (uint32_t)SampleTime);                              
  
      Status = (uint32_t)DAVEApp_SUCCESS;
    }
    else
    {
      Status = (uint32_t)ADCGROUP001_INVALID_PARAM_ERROR;
    }    
  }
  else  
  {
    ERROR(GID_ADCGROUP001, (uint8_t)Status, 0, (uint8_t*)NULL);
  }
  
  FUNCTION_EXIT(GID_ADCGROUP001, ADCGROUP001_FUNCTION_EXIT);
  return Status;
}


/* This function sets the sample time for EMUX conversion mode*/
status_t ADCGROUP001_SetGroupClass0EmuxSampleTime(
                                        const ADCGROUP001_HandleType *HandlePtr, 
                                        uint8_t SampleTime)
{
  status_t Status = (uint32_t)ADCGROUP001_OPER_NOT_ALLOWED_ERROR;
  /*Pointer to the VADC Structure */
  VADC_G_TypeDef *VADCGroupPtr;              
  VADCGroupPtr = HandlePtr->VADCGroupPtr;

  FUNCTION_ENTRY(GID_ADCGROUP001, ADCGROUP001_FUNCTION_ENTRY);

  if((HandlePtr->DynamicHandlePtr->State == ADCGROUP001_INITIALIZED))
  {
    if(SampleTime < (uint8_t)ADCGROUP001_MAX_SAMPLE_TIME_CONTROL_VAL)
    {
      /* Set EMUX sample time control for class 0 */
      WR_REG(VADCGroupPtr->ICLASS[0], VADC_G_ICLASS_STCE_Msk,
                                 VADC_G_ICLASS_STCE_Pos, (uint32_t)SampleTime);
  
      Status = (uint32_t)DAVEApp_SUCCESS;
    }
    else
    {
      Status = (uint32_t)ADCGROUP001_INVALID_PARAM_ERROR;
    }  
  }
  else  
  {
    ERROR(GID_ADCGROUP001, (uint8_t)Status, 0, (uint8_t*)NULL);  
  }
  
  FUNCTION_EXIT(GID_ADCGROUP001, ADCGROUP001_FUNCTION_EXIT);
  return Status;
}


/* This function sets the sample time for EMUX conversion mode*/
status_t ADCGROUP001_SetGroupClass1EmuxSampleTime(
                                        const ADCGROUP001_HandleType *HandlePtr, 
                                        uint8_t SampleTime)
{
  status_t Status = (uint32_t)ADCGROUP001_OPER_NOT_ALLOWED_ERROR;
  /*Pointer to the VADC Structure */
  VADC_G_TypeDef *VADCGroupPtr;              
  VADCGroupPtr = HandlePtr->VADCGroupPtr;

  FUNCTION_ENTRY(GID_ADCGROUP001, ADCGROUP001_FUNCTION_ENTRY);

  if((HandlePtr->DynamicHandlePtr->State == ADCGROUP001_INITIALIZED))
  {
    if(SampleTime < (uint8_t)ADCGROUP001_MAX_SAMPLE_TIME_CONTROL_VAL)
    {
      /* Set EMUX sample time control for class 1 */
      WR_REG(VADCGroupPtr->ICLASS[1], VADC_G_ICLASS_STCE_Msk,
                                  VADC_G_ICLASS_STCE_Pos, (uint32_t)SampleTime);
      Status = (uint32_t)DAVEApp_SUCCESS;
    }
    else
    {
      Status = (uint32_t)ADCGROUP001_INVALID_PARAM_ERROR;
    }    
  }
  else  
  {
    ERROR(GID_ADCGROUP001, (uint8_t)Status, 0, (uint8_t*)NULL);
  }
 
  FUNCTION_EXIT(GID_ADCGROUP001, ADCGROUP001_FUNCTION_EXIT);
  return Status;
}


/* This function sets the standard conversion mode in group class 0 */
status_t ADCGROUP001_SetGroupClass0ConvMode(
                                      const ADCGROUP001_HandleType *HandlePtr, 
                                      uint8_t ConversionModeVal)
{
  status_t Status = (uint32_t)ADCGROUP001_OPER_NOT_ALLOWED_ERROR;
  /*Pointer to the VADC Structure */
  VADC_G_TypeDef *VADCGroupPtr;              
  VADCGroupPtr = HandlePtr->VADCGroupPtr;

  FUNCTION_ENTRY(GID_ADCGROUP001, ADCGROUP001_FUNCTION_ENTRY);

  if((HandlePtr->DynamicHandlePtr->State == ADCGROUP001_INITIALIZED))
  {
    if((ConversionModeVal <= (uint8_t)ADCGROUP001_8BIT) ||
        (ConversionModeVal == (uint8_t)ADCGROUP001_10BITFAST))
    {
      /* Set conversion mode for class 0 */
      WR_REG(VADCGroupPtr->ICLASS[0], VADC_G_ICLASS_CMS_Msk,
                            VADC_G_ICLASS_CMS_Pos, (uint32_t)ConversionModeVal);
  
      Status = (uint32_t)DAVEApp_SUCCESS;
    }
    else
    {
      Status = (uint32_t)ADCGROUP001_INVALID_PARAM_ERROR;
    }  
  }
  else  
  {
    ERROR(GID_ADCGROUP001, (uint8_t)Status, 0, (uint8_t*)NULL);   
  }
  
  FUNCTION_EXIT(GID_ADCGROUP001, ADCGROUP001_FUNCTION_EXIT);
  return Status;
}


/* This function sets the standard conversion mode */
status_t ADCGROUP001_SetGroupClass1ConvMode(
                                      const ADCGROUP001_HandleType *HandlePtr, 
                                      uint8_t ConversionModeVal)
{
  status_t Status = (uint32_t)ADCGROUP001_OPER_NOT_ALLOWED_ERROR;
  /*Pointer to the VADC Structure */
  VADC_G_TypeDef *VADCGroupPtr;              
  VADCGroupPtr = HandlePtr->VADCGroupPtr;
  
  FUNCTION_ENTRY(GID_ADCGROUP001, ADCGROUP001_FUNCTION_ENTRY);

  if((HandlePtr->DynamicHandlePtr->State == ADCGROUP001_INITIALIZED))
  {
    if((ConversionModeVal <= (uint8_t)ADCGROUP001_8BIT) ||
        (ConversionModeVal == (uint8_t)ADCGROUP001_10BITFAST))
    {
      /* Set conversion mode for class 1 */
      WR_REG(VADCGroupPtr->ICLASS[1], VADC_G_ICLASS_CMS_Msk,
                            VADC_G_ICLASS_CMS_Pos, (uint32_t)ConversionModeVal);
      Status = (uint32_t)DAVEApp_SUCCESS;
    }
    else
    {
      Status = (uint32_t)ADCGROUP001_INVALID_PARAM_ERROR;
    }    
  }
  else  
  {
    ERROR(GID_ADCGROUP001, (uint8_t)Status, 0, (uint8_t*)NULL);    
  }

  FUNCTION_EXIT(GID_ADCGROUP001, ADCGROUP001_FUNCTION_EXIT);
  return Status;
}


/* This function sets the emux conversion mode */
status_t ADCGROUP001_SetGroupClass0EmuxConvMode(
                                        const ADCGROUP001_HandleType *HandlePtr, 
                                        uint8_t ConversionModeVal
                                          )
{
  status_t Status = (uint32_t)ADCGROUP001_OPER_NOT_ALLOWED_ERROR;
  /*Pointer to the VADC Structure */
  VADC_G_TypeDef *VADCGroupPtr;              
  VADCGroupPtr = HandlePtr->VADCGroupPtr;

  FUNCTION_ENTRY(GID_ADCGROUP001, ADCGROUP001_FUNCTION_ENTRY);

  if((HandlePtr->DynamicHandlePtr->State == ADCGROUP001_INITIALIZED))
  {
    if((ConversionModeVal <= (uint8_t)ADCGROUP001_8BIT) ||
        (ConversionModeVal == (uint8_t)ADCGROUP001_10BITFAST))
    {
      /* Set EMUX conversion mode for class 0 */
      WR_REG(VADCGroupPtr->ICLASS[0], VADC_G_ICLASS_CME_Msk,
                            VADC_G_ICLASS_CME_Pos, (uint32_t)ConversionModeVal);
  
      Status = (uint32_t)DAVEApp_SUCCESS;
    }
    else
    {
      Status = (uint32_t)ADCGROUP001_INVALID_PARAM_ERROR;
    }  
  }
  else  
  {
    ERROR(GID_ADCGROUP001, (uint8_t)Status, 0, (uint8_t*)NULL);    
  }

  FUNCTION_EXIT(GID_ADCGROUP001, ADCGROUP001_FUNCTION_EXIT);
  return Status;
}


/* This function sets the emux conversion mode */
status_t ADCGROUP001_SetGroupClass1EmuxConvMode(
                                        const ADCGROUP001_HandleType *HandlePtr, 
                                        uint8_t ConversionModeVal
                                          )
{
  status_t Status = (uint32_t)ADCGROUP001_OPER_NOT_ALLOWED_ERROR;
  /*Pointer to the VADC Structure */
  VADC_G_TypeDef *VADCGroupPtr;              
  VADCGroupPtr = HandlePtr->VADCGroupPtr;
 
  FUNCTION_ENTRY(GID_ADCGROUP001, ADCGROUP001_FUNCTION_ENTRY);

  if((HandlePtr->DynamicHandlePtr->State == ADCGROUP001_INITIALIZED))
  {
    if((ConversionModeVal <= (uint8_t)ADCGROUP001_8BIT) ||
        (ConversionModeVal == (uint8_t)ADCGROUP001_10BITFAST))
    {
      /* Set EMUX conversion mode for class 1 */
      WR_REG(VADCGroupPtr->ICLASS[1], VADC_G_ICLASS_CME_Msk,
                           VADC_G_ICLASS_CME_Pos, (uint32_t)ConversionModeVal);
  
      Status = (uint32_t)DAVEApp_SUCCESS;
    }
    else
    {
      Status = (uint32_t)ADCGROUP001_INVALID_PARAM_ERROR;
    }
  }
  else  
  {
    ERROR(GID_ADCGROUP001, (uint8_t)Status, 0, (uint8_t*)NULL); 
  }

  FUNCTION_EXIT(GID_ADCGROUP001, ADCGROUP001_FUNCTION_EXIT);
  return Status;
}


/* This function sets the value of EMUX sample time control. */
status_t ADCGROUP001_SetEMUXSampleTimeControl(
                  const ADCGROUP001_HandleType *HandlePtr, uint8_t ControlValue)
{
  status_t Status = (uint32_t)ADCGROUP001_OPER_NOT_ALLOWED_ERROR;
  uint32_t SampleTimeCtrl;
  /*Pointer to the VADC Structure */
  VADC_G_TypeDef *VADCGroupPtr;              
  VADCGroupPtr = HandlePtr->VADCGroupPtr;
  
  FUNCTION_ENTRY(GID_ADCGROUP001, ADCGROUP001_FUNCTION_ENTRY);

  if((HandlePtr->DynamicHandlePtr->State == ADCGROUP001_INITIALIZED))
  {
    if(ControlValue <= (uint8_t)SET)
    {
      /* Set the EMUX sample time control */
      SampleTimeCtrl = VADCGroupPtr->EMUXCTR;
      SampleTimeCtrl &= (uint32_t)~(VADC_G_EMUXCTR_EMXST_Msk);
      SampleTimeCtrl |= (VADC_G_EMUXCTR_EMXWC_Msk) | \
                    (((uint32_t)ControlValue << VADC_G_EMUXCTR_EMXST_Pos) & VADC_G_EMUXCTR_EMXST_Msk);
      VADCGroupPtr->EMUXCTR = SampleTimeCtrl;
  
      Status = (uint32_t)DAVEApp_SUCCESS;
    }
    else 
    {
      Status = (uint32_t)ADCGROUP001_INVALID_PARAM_ERROR;
    }
  }
  else  
  {
    ERROR(GID_ADCGROUP001, (uint8_t)Status, 0, (uint8_t*)NULL);
  }

  FUNCTION_EXIT(GID_ADCGROUP001, ADCGROUP001_FUNCTION_EXIT);
  return Status;
}


/**
 * @endcond
 */
/*CODE_BLOCK_END*/

