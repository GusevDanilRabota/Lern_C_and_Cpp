#ifndef MAIN_H
#define MAIN_H

#include "stdio.h"
#include <stdarg.h>

typedef struct {
    float x;
    float y;
    float z;
} vector_components;

typedef struct {
    __int64 id;
    vector_components components_start;
    vector_components components_end;
} vector;


__int8 sum_vectors(vector* result_vector, ...);
__int8 mul_vectors_vector(vector* composition, vector* multiplier_1, vector* multiplier_2);
__int8 mul_vectors_skolar(float composition, vector* multiplier_1, vector* multiplier_2);
__int8 show_vector(vector* displayed_vector);

#endif
