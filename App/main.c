#define F_CPU 8000000UL
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "avr/delay.h"
#include "../LCD/LCD_CONFIG.h"
#include "../LCD/LCD_INTERFACE.h"
#include "../TWI/TWI_CONFIG.h"
#include "../TWI/TWI_INTERFACE.h"

int main(void)
{
	u8 data_From_Master[3];
    LCD_voidInit();
    TWI_SlaveInit(0x20);
    while (1)
    {
        TWI_SlaveWaitMaster();
        for(u8 i=0;i<3;i++){
        	data_From_Master[i]=TWI_SlaveRead();
        }
        LCD_voidClear();
        LCD_voidWriteString((u8*)data_From_Master);
    }
}


