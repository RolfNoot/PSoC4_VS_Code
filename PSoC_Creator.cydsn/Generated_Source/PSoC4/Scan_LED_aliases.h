/*******************************************************************************
* File Name: Scan_LED.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Scan_LED_ALIASES_H) /* Pins Scan_LED_ALIASES_H */
#define CY_PINS_Scan_LED_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define Scan_LED_0			(Scan_LED__0__PC)
#define Scan_LED_0_PS		(Scan_LED__0__PS)
#define Scan_LED_0_PC		(Scan_LED__0__PC)
#define Scan_LED_0_DR		(Scan_LED__0__DR)
#define Scan_LED_0_SHIFT	(Scan_LED__0__SHIFT)
#define Scan_LED_0_INTR	((uint16)((uint16)0x0003u << (Scan_LED__0__SHIFT*2u)))

#define Scan_LED_INTR_ALL	 ((uint16)(Scan_LED_0_INTR))


#endif /* End Pins Scan_LED_ALIASES_H */


/* [] END OF FILE */
