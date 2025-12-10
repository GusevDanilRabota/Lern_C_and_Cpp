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
    vector_components comnents;
} vector;


__int8 sum_vectors(vector* result_vector, ...);

#endif
