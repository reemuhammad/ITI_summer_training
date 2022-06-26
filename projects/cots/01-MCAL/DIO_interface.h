#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/* set pin */
void DIO_VidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Value, u8 Copy_u8PinNumber);
void DIO_VidSetPinDirection(u8 Copy_u8Port, u8 Copy_u8PinNumber, u8 Copy_u8PinDirection);
void DIO_VidGetPinValue(u8 Copy_u8Port, u8 Copy_u8PinNumber, u8 * Copy_Pu8PinValue);

/* set port */
void DIO_VidSetPortValue(u8 Copy_u8Port, u8 Copy_u8Value);
void DIO_VidSetPortDirection(u8 Copy_u8Port, u8 Copy_u8PortDirection);
void DIO_VidGetPortValue(u8 Copy_u8Port,  u8 * Copy_Pu8PortValue);

/* Others: toggle */
#endif