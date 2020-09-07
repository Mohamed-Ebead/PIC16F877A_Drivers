/*
 * File:   DIO_Prog.c
 * Author: Mohamed  Ebead
 *
 * Created on June 29, 2020, 9:02 PM
 */
#include "std_types.h"
#include "Bit_Logic.h"

#include "DIO_Interface.h"
#include "DIO_Reg.h"



/* IO Pins */

void DIO_SetPinDirection (u8 u8PortIdCopy, u8 u8PinIdCopy, u8 u8PinDirCopy)
{
	/* Make sure that the Port ID and Pin ID are in the valid range */
	if ((u8PortIdCopy <= PORTD_DIO) && (u8PinIdCopy <= PIN7))
	{
		if ( u8PinDirCopy == OUTPUT )
		{
			/* Check on the Required PORT Number */
			switch (u8PortIdCopy)
			{
				case PORTA_DIO: CLR_BIT(TRISA_Register,u8PinIdCopy); break;
				case PORTB_DIO: CLR_BIT(TRISB_Register,u8PinIdCopy); break;
				case PORTC_DIO: CLR_BIT(TRISC_Register,u8PinIdCopy); break;
				case PORTD_DIO: CLR_BIT(TRISD_Register,u8PinIdCopy); break;
			}
		}
		
		else if ( u8PinDirCopy == INPUT )
		{
			/* Check on the Required PORT Number */
			switch (u8PortIdCopy)
			{
				case PORTA_DIO: SET_BIT(TRISA_Register,u8PinIdCopy); break;
				case PORTB_DIO: SET_BIT(TRISB_Register,u8PinIdCopy); break;
				case PORTC_DIO: SET_BIT(TRISC_Register,u8PinIdCopy); break;
				case PORTD_DIO: SET_BIT(TRISD_Register,u8PinIdCopy); break;
			}
		}
		
		else
		{
			/* Do nothing, Wrong Direction Required */
		}
	}
	
	else
	{
		/* Do nothing, Error in the Pin ID or PORT ID */
	}
}


/*----------------------------------------------------------------------------*/

void DIO_SetPinValue(u8 u8PortIdCopy , u8 u8PinIdCopy, u8 u8PinValCopy)
{
	/* Make sure that the Port ID and Pin ID are in the valid range */
	if ((u8PortIdCopy <= PORTD_DIO) && (u8PinIdCopy <= PIN7))
	{
		if (u8PinValCopy == HIGH)
		{
			/* Check on the Required PORT Number */
			switch (u8PortIdCopy)
			{
				case PORTA_DIO: SET_BIT(PORTA_Register,u8PinIdCopy); break;
				case PORTB_DIO: SET_BIT(PORTB_Register,u8PinIdCopy); break;
				case PORTC_DIO: SET_BIT(PORTC_Register,u8PinIdCopy); break;
				case PORTD_DIO: SET_BIT(PORTD_Register,u8PinIdCopy); break;
			}
		
		}
		
		else if (u8PinValCopy == LOW)
		{
			/* Check on the Required PORT Number */
			switch (u8PortIdCopy)
			{
				case PORTA_DIO: CLR_BIT(PORTA_Register,u8PinIdCopy); break;
				case PORTB_DIO: CLR_BIT(PORTB_Register,u8PinIdCopy); break;
				case PORTC_DIO: CLR_BIT(PORTC_Register,u8PinIdCopy); break;
				case PORTD_DIO: CLR_BIT(PORTD_Register,u8PinIdCopy); break;
			}
		}
	
		else
		{
			/* Do nothing, Wrong value to set */
		}
	}
	
	else
	{
		/* Do nothing, Error in the Pin ID or PORT ID */
	}
}

/*----------------------------------------------------------------------------*/

u8 DIO_GetPinValue(u8 u8PortIdCopy, u8 u8PinIdCopy)
{
	/* Define Local Variable to get the BIT Value */
	u8 u8ResultLocal;
	/* Make sure that the Port ID and Pin ID are in the valid range */
	if ((u8PortIdCopy <= PORTD_DIO) && (u8PinIdCopy <= PIN7))
	{
		/* Check on the Required PORT Number */
		switch (u8PortIdCopy)
		{
			case PORTA_DIO: u8ResultLocal= GET_BIT(PORTA_Register,u8PinIdCopy); break;
			case PORTB_DIO: u8ResultLocal= GET_BIT(PORTB_Register,u8PinIdCopy); break;
			case PORTC_DIO: u8ResultLocal= GET_BIT(PORTC_Register,u8PinIdCopy); break;
			case PORTD_DIO: u8ResultLocal= GET_BIT(PORTD_Register,u8PinIdCopy); break;
		}
	}
	
	else
	{
		/* return 0xff in case of error in the Pin ID or PORT ID */
		u8ResultLocal = 0xFF;
	}
	
	return u8ResultLocal;
}
/*----------------------------------------------------------------------------*/

/* IO Ports */
void DIO_SetPortDirection (u8 u8PortId, u8 u8PortDir)
{
	/* Check on the Required PORT Number */
	switch (u8PortId)
	{
			case PORTA_DIO: TRISA_Register = u8PortDir; break;
			case PORTB_DIO: TRISB_Register = u8PortDir; break;
			case PORTC_DIO: TRISC_Register = u8PortDir; break;
			case PORTD_DIO: TRISD_Register = u8PortDir; break;
		default: /* Wrong Port ID */       break;
	}
}

/*----------------------------------------------------------------------------*/

void DIO_SetPortValue (u8 u8PortId, u8 u8PortVal)
{
	/* Check on the Required PORT Number */
	switch (u8PortId)
	{
			case PORTA_DIO: PORTA_Register = u8PortVal; break;
			case PORTB_DIO: PORTB_Register = u8PortVal; break;
			case PORTC_DIO: PORTC_Register = u8PortVal; break;
			case PORTD_DIO: PORTD_Register = u8PortVal; break;
		default: /* Wrong Port ID */        break;
	}
}
