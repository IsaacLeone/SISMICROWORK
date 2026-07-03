#include "filter.h"

float Filter_Update(EMA_Filter *filter, uint16_t new_sample) {
    // Se for a primeira leitura, inicializa o filtro com o valor atual para evitar rampa inicial
    if (!filter->is_initialized) {
        filter->filtered_value = (float)new_sample;
        filter->is_initialized = 1;
    } else {
        // Equação de diferenças: Y[n] = alpha * X[n] + (1 - alpha) * Y[n-1]
        filter->filtered_value = (ALPHA * (float)new_sample) + ((1.0f - ALPHA) * filter->filtered_value);
    }
    return filter->filtered_value;
}
