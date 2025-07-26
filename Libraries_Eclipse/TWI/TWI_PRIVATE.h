#ifndef TWI_PRIVATE_H_
#define TWI_PRIVATE_H_
#define TWI_MASTER_MODE     1
#define TWI_SLAVE_MODE      2

typedef union {
    u8 ALL;
} TWBR_Reg;
#define TWBR (*(volatile TWBR_Reg*) 0x20)

typedef union {
    u8 ALL;
    struct {
        u8 TWPS0 :1;
        u8 TWPS1 :1;
        u8       :1;
        u8 TWS3  :1;
        u8 TWS4  :1;
        u8 TWS5  :1;
        u8 TWS6  :1;
        u8 TWS7  :1;
    } BITS;
} TWSR_Reg;
#define TWSR (*(volatile TWSR_Reg*) 0x21)

typedef union {
    u8 ALL;
    struct {
        u8 TWGCE :1;
        u8 TWA0  :1;
        u8 TWA1  :1;
        u8 TWA2  :1;
        u8 TWA3  :1;
        u8 TWA4  :1;
        u8 TWA5  :1;
        u8 TWA6  :1;
    } BITS;
} TWAR_Reg;
#define TWAR (*(volatile TWAR_Reg*) 0x22)

typedef union {
    u8 ALL;
} TWDR_Reg;
#define TWDR (*(volatile TWDR_Reg*) 0x23)

typedef union {
    u8 ALL;
    struct {
        u8 TWIE  :1;
        u8       :1;
        u8 TWEN  :1;
        u8 TWWC  :1;
        u8 TWSTO :1;
        u8 TWSTA :1;
        u8 TWEA  :1;
        u8 TWINT :1;
    } BITS;
} TWCR_Reg;
#define TWCR (*(volatile TWCR_Reg*) 0x56)

#endif /* TWI_PRIVATE_H_ */