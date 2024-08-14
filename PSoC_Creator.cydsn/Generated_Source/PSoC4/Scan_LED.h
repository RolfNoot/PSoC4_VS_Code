/*******************************************************************************
* File Name: Scan_LED.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Scan_LED_H) /* Pins Scan_LED_H */
#define CY_PINS_Scan_LED_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Scan_LED_aliases.h"


/***************************************
*     Data Struct Definitions
***************************************/

/**
* \addtogroup group_structures
* @{
*/
    
/* Structure for sleep mode support */
typedef struct
{
    uint32 pcState; /**< State of the port control register */
    uint32 sioState; /**< State of the SIO configuration */
    uint32 usbState; /**< State of the USBIO regulator */
} Scan_LED_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   Scan_LED_Read(void);
void    Scan_LED_Write(uint8 value);
uint8   Scan_LED_ReadDataReg(void);
#if defined(Scan_LED__PC) || (CY_PSOC4_4200L) 
    void    Scan_LED_SetDriveMode(uint8 mode);
#endif
void    Scan_LED_SetInterruptMode(uint16 position, uint16 mode);
uint8   Scan_LED_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void Scan_LED_Sleep(void); 
void Scan_LED_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(Scan_LED__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define Scan_LED_DRIVE_MODE_BITS        (3)
    #define Scan_LED_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Scan_LED_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the Scan_LED_SetDriveMode() function.
         *  @{
         */
        #define Scan_LED_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define Scan_LED_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define Scan_LED_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define Scan_LED_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define Scan_LED_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define Scan_LED_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define Scan_LED_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define Scan_LED_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define Scan_LED_MASK               Scan_LED__MASK
#define Scan_LED_SHIFT              Scan_LED__SHIFT
#define Scan_LED_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Scan_LED_SetInterruptMode() function.
     *  @{
     */
        #define Scan_LED_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define Scan_LED_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define Scan_LED_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define Scan_LED_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(Scan_LED__SIO)
    #define Scan_LED_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(Scan_LED__PC) && (CY_PSOC4_4200L)
    #define Scan_LED_USBIO_ENABLE               ((uint32)0x80000000u)
    #define Scan_LED_USBIO_DISABLE              ((uint32)(~Scan_LED_USBIO_ENABLE))
    #define Scan_LED_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define Scan_LED_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define Scan_LED_USBIO_ENTER_SLEEP          ((uint32)((1u << Scan_LED_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << Scan_LED_USBIO_SUSPEND_DEL_SHIFT)))
    #define Scan_LED_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << Scan_LED_USBIO_SUSPEND_SHIFT)))
    #define Scan_LED_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << Scan_LED_USBIO_SUSPEND_DEL_SHIFT)))
    #define Scan_LED_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(Scan_LED__PC)
    /* Port Configuration */
    #define Scan_LED_PC                 (* (reg32 *) Scan_LED__PC)
#endif
/* Pin State */
#define Scan_LED_PS                     (* (reg32 *) Scan_LED__PS)
/* Data Register */
#define Scan_LED_DR                     (* (reg32 *) Scan_LED__DR)
/* Input Buffer Disable Override */
#define Scan_LED_INP_DIS                (* (reg32 *) Scan_LED__PC2)

/* Interrupt configuration Registers */
#define Scan_LED_INTCFG                 (* (reg32 *) Scan_LED__INTCFG)
#define Scan_LED_INTSTAT                (* (reg32 *) Scan_LED__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define Scan_LED_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(Scan_LED__SIO)
    #define Scan_LED_SIO_REG            (* (reg32 *) Scan_LED__SIO)
#endif /* (Scan_LED__SIO_CFG) */

/* USBIO registers */
#if !defined(Scan_LED__PC) && (CY_PSOC4_4200L)
    #define Scan_LED_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define Scan_LED_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define Scan_LED_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define Scan_LED_DRIVE_MODE_SHIFT       (0x00u)
#define Scan_LED_DRIVE_MODE_MASK        (0x07u << Scan_LED_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins Scan_LED_H */


/* [] END OF FILE */
