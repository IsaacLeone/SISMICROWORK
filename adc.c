#include "adc.h"

void ADC_Init(void) {
    // Configura a referência de tensão para AVCC com capacitor externo no pino AREF
    ADMUX = (1 << REFS0);
    
    // Habilita o ADC e define o prescaler para 128 
    // (16MHz / 128 = 125kHz, que está dentro da faixa ideal de 50kHz a 200kHz)
    ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
}

uint16_t ADC_Read(uint8_t channel) {
    // Limpa os bits de canal anteriores e seleciona o novo canal (0-7)
    ADMUX = (ADMUX & 0xF0) | (channel & 0x0F);
    
    // Inicia a conversão (bit ADSC)
    ADCSRA |= (1 << ADSC);
    
    // Aguarda a conversão terminar (ADSC volta a ser 0)
    while (ADCSRA & (1 << ADSC));
    
    // Retorna o valor de 10 bits combinado (ADCL + ADCH)
    return ADCW;
}
