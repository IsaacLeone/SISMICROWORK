#ifndef CONFIG_H_
#define CONFIG_H_

// Definição do clock do sistema (Ex: 16MHz do Arduino Uno/ATmega328)
#ifndef F_CPU
#define F_CPU 16000000UL
#endif

// Macros para facilitar a manipulação de bits
#define set_bit(y, bit)   (y |= (1 << bit))
#define clr_bit(y, bit)   (y &= ~(1 << bit))
#define cgl_bit(y, bit)   (y ^= (1 << bit))
#define tst_bit(y, bit)   (y & (1 << bit))

// Definição dos pinos para as versões de comunicação (Exemplo)
#define COM_MODE_PIN      PD2 // Pino para ler a escolha do usuário (Serial vs Wireless)
#define COM_MODE_PORT     PORTD
#define COM_MODE_DDR      DDRD
#define COM_MODE_PINX     PIND

#endif /* CONFIG_H_ */
