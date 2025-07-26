#ifndef TWI_INTERFACE_H_
#define TWI_INTERFACE_H_
void TWI_MasterInit();
void TWI_StartCondition(void);
void TWI_Stop(void);
void TWI_SendAddress(u8 address, u8 select);
void TWI_WriteData(u8 data);
u8 TWI_ReadData_ACK(void);
u8 TWI_ReadData_NACK(void);
void TWI_SlaveInit(u8 slave_address);
void TWI_SlaveWaitMaster(void);
u8 TWI_SlaveRead(void);
void TWI_SlaveWrite(u8 data);
void TWI_EnableGeneralCall(void);
#endif /* TWI_INTERFACE_H_ */