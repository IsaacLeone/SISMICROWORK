#include "rtc.h"
#include "config.h"

#define RTC_ADDRESS 0xD0 // Endereço padrão I2C para a maioria dos RTCs (DS1307/DS3231)

void I2C_Init(void) {
    // Configura a taxa de amostragem SCL para ~100kHz com F_CPU = 16MHz
    TWSR = 0x00; // Prescaler = 1
    TWBR = 72;   // SCL freq = F_CPU / (16 + 2*TWBR*Prescaler)
}

void I2C_Start(void) {
    TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
}

void I2C_Stop(void) {
    TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);
    while (TWCR & (1 << TWSTO)); // Aguarda conclusão
}

void I2C_Write(uint8_t data) {
    TWDR = data;
    TWCR = (1 << TWINT) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
}

uint8_t I2C_Read_ACK(void) {
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);
    while (!(TWCR & (1 << TWINT)));
    return TWDR;
}

uint8_t I2C_Read_NACK(void) {
    TWCR = (1 << TWINT) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
    return TWDR;
}

// Funções auxiliares de conversão BCD para Decimal
static uint8_t bcd_to_dec(uint8_t val) {
    return ((val / 16) * 10) + (val % 16);
}

void RTC_GetTime(DateTime *dt) {
    I2C_Start();
    I2C_Write(RTC_ADDRESS);      // Envia endereço em modo escrita
    I2C_Write(0x00);             // Aponta para o registrador 0x00 (Segundos)
    
    I2C_Start();                 // Repetidas condições de Start (Restart)
    I2C_Write(RTC_ADDRESS | 1);  // Altera para modo leitura
    
    dt->second = bcd_to_dec(I2C_Read_ACK() & 0x7F);
    dt->minute = bcd_to_dec(I2C_Read_ACK());
    dt->hour   = bcd_to_dec(I2C_Read_ACK() & 0x3F); // Modo 24h
    I2C_Read_ACK();                                 // Pula o dia da semana
    dt->day    = bcd_to_dec(I2C_Read_ACK());
    dt->month  = bcd_to_dec(I2C_Read_ACK());
    dt->year   = bcd_to_dec(I2C_Read_NACK()) + 2000; // Converte ano offset
    I2C_Stop();
}
