#ifndef USART_H_
#define USART_H_

#include <avr/io.h>

// Função para inicializar a USART com o Baud Rate desejado
void USART_Init(unsigned long baud);

// Transmite um único caractere
void USART_Transmit(char data);

// Transmite uma string completa
void USART_SendString(const char* str);

#endif /* USART_H_ */
