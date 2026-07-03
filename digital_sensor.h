#ifndef DIGITAL_SENSOR_H_
#define DIGITAL_SENSOR_H_

#include <avr/io.h>

// Definição de pinos no ATmega328 (Ex: Pinos digitais PD3 e PD4)
#define RAIN_PIN        PD3
#define HUMIDITY_PIN    PD4
#define SENSOR_PINX     PIND
#define SENSOR_DDR      DDRD
#define SENSOR_PORT     PORTD

void DigitalSensors_Init(void);
uint8_t Read_RainSensor(void);
uint8_t Read_HumiditySensor(void);

#endif /* DIGITAL_SENSOR_H_ */
