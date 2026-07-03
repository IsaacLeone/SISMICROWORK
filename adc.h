#ifndef ADC_H_
#define ADC_H_

#include <avr/io.h>

// Inicializa o periférico ADC
void ADC_Init(void);

// Lê o valor bruto (0 a 1023) de um canal específico (0 a 7)
uint16_t ADC_Read(uint8_t channel);

#endif /* ADC_H_ */
