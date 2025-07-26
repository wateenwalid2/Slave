#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"
#include "TWI_INTERFACE.h"
#include "TWI_CONFIG.h"
#include "TWI_PRIVATE.h"

void TWI_MasterInit(){
 TWSR.BITS.TWPS0=0;
 TWSR.BITS.TWPS1=0;
//set the prescaler to 1
 TWBR.ALL = (u8)((CPU_FREQ/SCL_FREQ)-16)/2;
 //set the value of TWBR Register
 TWCR.BITS.TWEN = 1;
 //Enable the TWI
}
void TWI_StartCondition(){
    TWCR.BITS.TWSTA = 1;  
     // Start Condition
    TWCR.BITS.TWEN  = 1;  
     // Enable TWI
    TWCR.BITS.TWINT = 1;
    // Clear interrupt flag to start the operation
     while (TWCR.BITS.TWINT == 0);
     //wait until the end of operation 
}
void TWI_Stop(){
    TWCR.BITS.TWSTO = 1;  
     // Stop Condition
    TWCR.BITS.TWEN  = 1;  
     // Enable TWI
    TWCR.BITS.TWINT = 1;
    // Clear interrupt flag to start the operation

}
void TWI_SendAddress(u8 address, u8 select){
    TWDR.ALL = (address << 1) | (select & 0x01);
    //send the slave address and choose whether read or write
    TWCR.BITS.TWEN  = 1;
    // Enable TWI
    TWCR.BITS.TWINT = 1;
    // Clear interrupt flag to start the operation
    while (TWCR.BITS.TWINT == 0);
    //wait until the end of operation 

}
void TWI_WriteData(u8 data){
    TWDR.ALL = data;
    //send data to slave 
    TWCR.BITS.TWEN  = 1;
    // Enable TWI
    TWCR.BITS.TWINT = 1;
    // Clear interrupt flag to start the operation
    while (TWCR.BITS.TWINT == 0);
    //wait until the end of operation
}
u8 TWI_ReadData_ACK(){
    TWCR.BITS.TWEA  = 1; 
    // Enable ACK
    TWCR.BITS.TWEN  = 1;
    // Enable TWI
    TWCR.BITS.TWINT = 1;
     // Clear interrupt flag to start the operation
    while (TWCR.BITS.TWINT == 0);
    //wait until the end of operation
    return TWDR.ALL;
    //return the data that master read from slave
}
u8 TWI_ReadData_NACK(){
    TWCR.BITS.TWEA  = 0; 
    // Enable NACK
    TWCR.BITS.TWEN  = 1;
    // Enable TWI
    TWCR.BITS.TWINT = 1;
     // Clear interrupt flag to start the operation
    while (TWCR.BITS.TWINT == 0);
    //wait until the end of operation
    return TWDR.ALL;
    //return the data that master read from slave
}

void TWI_SlaveInit(u8 slave_address){
    TWAR.ALL = (slave_address << 1);
    //send slave address
    TWCR.BITS.TWEA = 1;
    // Enable ACK
    TWCR.BITS.TWEN = 1;
    // Enable TWI
    TWCR.BITS.TWINT = 1;
    // Clear interrupt flag to start the operation
}
void TWI_SlaveWaitMaster(){
    while (TWCR.BITS.TWINT == 0);
     //wait until the end of operation
}
u8 TWI_SlaveRead(){
    TWCR.BITS.TWEA  = 1;
    // Enable ACK
    TWCR.BITS.TWEN  = 1;
    // Enable TWI
    TWCR.BITS.TWINT = 1;
    // Clear interrupt flag to start the operation
    while (TWCR.BITS.TWINT == 0);
    //wait until the end of operation
    return TWDR.ALL;
    //return the recieved data from slave
}
void TWI_SlaveWrite(u8 data){
    TWDR.ALL = data;
    //send data to master
    TWCR.BITS.TWEA  = 1;
    // Enable ACK
    TWCR.BITS.TWEN  = 1;
    // Enable TWI
    TWCR.BITS.TWINT = 1; 
    // Clear interrupt flag to start the operation
    while (TWCR.BITS.TWINT == 0);
    //wait until the end of operation
}
void TWI_EnableGeneralCall(){
    TWAR.BITS.TWGCE = 1;
    //enable the general call
}






