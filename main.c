#include "main.h"

int main(void) {
    // Инициализация векторов с начальной и конечной точками
    vector vector_1 = {
        .id = 0x00,
        .components_end={.x=1.0f, .y=2.0f, .z=3.0f},
        .components_start={.x=0.0f, .y=0.0f, .z=0.0f}
    };
    vector vector_2 = {
        .id = 0x01,
        .components_end={.x=0.0f, .y=0.0f, .z=0.0f},
        .components_start={.x=3.0f, .y=2.0f, .z=1.0f}
    };
    vector vector_result = {0}; // Вектор для хранения результата

    sum_vectors(&vector_result, &vector_1, NULL);
    show_vector(&vector_result);

    sum_vectors(&vector_result, &vector_2, NULL);
    show_vector(&vector_result);

    sum_vectors(&vector_result, &vector_1, &vector_2, NULL);
    show_vector(&vector_result);

    return 0;
}

__int8 sum_vectors(vector* result_vector, ...) {
    if (result_vector == NULL) {
        return -1; // Ошибка: result_vector не может быть NULL
    }

    result_vector->id = 0xFF;
    result_vector->components_start.x = result_vector->components_start.y = result_vector->components_start.z = 0.0f;
    result_vector->components_end.x = result_vector->components_end.y = result_vector->components_end.z = 0.0f;

    va_list args;
    va_start(args, result_vector);

    // Читаем векторы пока не встретим NULL как указатель-терминатор
    vector* current_vector = NULL;
    current_vector = va_arg(args, vector*);
    while (current_vector != NULL) {
        result_vector->components_end.x += (current_vector->components_end.x - current_vector->components_start.x);
        result_vector->components_end.y += (current_vector->components_end.y - current_vector->components_start.y);
        result_vector->components_end.z += (current_vector->components_end.z - current_vector->components_start.z);

        current_vector = va_arg(args, vector*);
    }

    va_end(args);

    return 0;
}

__int8 mul_vectors_vector(vector* composition, vector* multiplier_1, vector* multiplier_2) {
    if (composition == NULL || multiplier_1 == NULL || multiplier_2 == NULL) {
        return -1;
    }

    // ОПРЕДЕЛЕНИЕ ОРТОНОРМИРОВАННОГО БАЗИСА
    __int8 orthonormal_basis = 0;

    if (orthonormal_basis == 1) { // ПРАВЫЙ

    } else if (orthonormal_basis == -1) { // ЛЕВЫЙ

    }
}

__int8 mul_vectors_skolar(float composition, vector* multiplier_1, vector* multiplier_2) {

}

__int8 show_vector(vector* displayed_vector) {
    printf("ID vector -> %d\n", displayed_vector->id);
    printf("Component x -> %e\n", displayed_vector->components_end.x);
    printf("Component y -> %e\n", displayed_vector->components_end.y);
    printf("Component z -> %e\n", displayed_vector->components_end.z);
    printf("\n");

    return 0;
}
