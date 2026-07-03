#ifndef FILTER_H_
#define FILTER_H_

#include <stdint.h>

// Fator de suavização alfa (quanto menor, mais filtra o ruído, mas responde mais lento)
#define ALPHA 0.2f

// Estrutura para armazenar o estado do filtro de cada sensor
typedef struct {
    float filtered_value;
    uint8_t is_initialized;
} EMA_Filter;

// Aplica a filtragem a uma nova amostra lida
float Filter_Update(EMA_Filter *filter, uint16_t new_sample);

#endif /* FILTER_H_ */
