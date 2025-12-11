#include "main.h"

int main(void) {
    // Инициализация векторов с начальной и конечной точками
    vector vector_1 = {
        .id = 0x00,
        .components_end={.x=1.12f, .y=-2.0f, .z=3.0f},
        .components_start={.x=0.023f, .y=11.0f, .z=0.0f}
    };
    vector vector_2 = {
        .id = 0x01,
        .components_end={.x=0.0f, .y=-1.0f, .z=0.0f},
        .components_start={.x=3.0f, .y=25.0f, .z=-1.0f}
    };
    vector vector_result = {0}; // Вектор для хранения результата

    float composition_skolar = 0.0f;

    sum_vectors(&vector_result, 1, &vector_1, NULL);
    sum_vectors(&vector_result, 1, &vector_2, NULL);
    sum_vectors(&vector_result, 2, &vector_1, &vector_2, NULL);

    mul_vectors_skolar(&composition_skolar, &vector_1, &vector_1);

    return 0;
}

__int8 sum_vectors(vector* sum_vector, int count, ...) {
    if (sum_vector == NULL) {
        printf("PASSING NULL POINTERS TO THE VECTOR OF THE RESULT");
        return -1;
    }

    sum_vector->components_start.x = sum_vector->components_start.y = sum_vector->components_start.z = 0.0f;
    sum_vector->components_end.x = sum_vector->components_end.y = sum_vector->components_end.z = 0.0f;

    va_list args;
    va_start(args, count);

    // Выводим заголовок с ID векторов
    printf("THE RESULT OF SUMMING VECTORS WITH ID --> ");

    // Читаем векторы пока не встретим NULL как указатель-терминатор
    vector* current_vector = NULL;
    for (int i = 0; i < count; i++) {
        current_vector = va_arg(args, vector*);

        if (current_vector == NULL) {
            break;
        }

        // Выводим ID текущего вектора
        if (i == 0) {
            printf("%d", current_vector->id);
        } else {
            printf(", %d", current_vector->id);
        }

        // Суммируем компоненты
        sum_vector->components_end.x += (current_vector->components_end.x - current_vector->components_start.x);
        sum_vector->components_end.y += (current_vector->components_end.y - current_vector->components_start.y);
        sum_vector->components_end.z += (current_vector->components_end.z - current_vector->components_start.z);
    }

    printf("\n");

    va_end(args);

    show_vector(sum_vector);

    return 0;
}

__int8 mul_vectors_vector(vector* composition_vector, const vector* multiplier_1, const vector* multiplier_2) {
    if (composition_vector == NULL) {
        printf("PASSING NULL POINTERS TO THE VECTOR OF THE RESULT");
        return -1;
    }

    if (multiplier_1 == NULL || multiplier_2 == NULL) {
        printf("PASSING ONE OR MORE NULL POINTERS");
        return -1;
    }

    // ОПРЕДЕЛЕНИЕ ОРТОНОРМИРОВАННОГО БАЗИСА
    __int8 orthonormal_basis = 0;

    if (orthonormal_basis == 1) { // ПРАВЫЙ
        pass;
    } else if (orthonormal_basis == -1) { // ЛЕВЫЙ
        pass;
    }

    return 0;
}

__int8 mul_vectors_skolar(float* composition_skolar, const vector* multiplier_1, const vector* multiplier_2) {
    if (composition_skolar == NULL) {
        printf("PASSING A NULL POINTER TO THE SCALAR OF THE RESULT");
        return -1;
    }

    if (multiplier_1 == NULL || multiplier_2 == NULL) {
        printf("PASSING ONE OR MORE NULL POINTERS TO MULTIPLICATION VECTORS");
        return -1;
    }

    // Вычисляем компоненты векторов
    float vec1_x = multiplier_1->components_end.x - multiplier_1->components_start.x;
    float vec1_y = multiplier_1->components_end.y - multiplier_1->components_start.y;
    float vec1_z = multiplier_1->components_end.z - multiplier_1->components_start.z;

    float vec2_x = multiplier_2->components_end.x - multiplier_2->components_start.x;
    float vec2_y = multiplier_2->components_end.y - multiplier_2->components_start.y;
    float vec2_z = multiplier_2->components_end.z - multiplier_2->components_start.z;

    // Вычисляем скалярное произведение
    *composition_skolar = 0.0f;
    *composition_skolar += vec1_x * vec2_x;
    *composition_skolar += vec1_y * vec2_y;
    *composition_skolar += vec1_z * vec2_z;

    printf("THE RESULT OF SCALAR MULTIPLICATION VECTOR ID --> %d, %d\n", multiplier_1->id, multiplier_2->id);
    printf("%e\n", *composition_skolar);

    return 0;
}

__int8 show_vector(vector* displayed_vector) {
    if (displayed_vector == NULL) {
        printf("PASSING A NULL POINTER ON DISPLAYED VECTOR");
        return -1;
    }

    printf("ID VECTOR --> %d\n", displayed_vector->id);
    printf("COMPONENT -- X --> %e\n", displayed_vector->components_end.x);
    printf("COMPONENT -- Y --> %e\n", displayed_vector->components_end.y);
    printf("COMPONENT -- Z --> %e\n", displayed_vector->components_end.z);
    printf("\n");

    return 0;
}
