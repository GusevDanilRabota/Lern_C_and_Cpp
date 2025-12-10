#include "main.h"

int main() {
    vector v1 = {{1.0f, 2.0f, 3.0f}};
    vector v2 = {{4.0f, 5.0f, 6.0f}};
    vector v3 = {{7.0f, 8.0f, 9.0f}};
    vector result = {0};

    // Сложение двух векторов
    sum_vectors(&result, &v1, &v2, NULL);
    printf("v1 + v2 = (%.2f, %.2f, %.2f)\n",
           result.comnents.x, result.comnents.y, result.comnents.z);

    // Сложение трех векторов
    sum_vectors(&result, &v1, &v2, &v3, NULL);
    printf("v1 + v2 + v3 = (%.2f, %.2f, %.2f)\n",
           result.comnents.x, result.comnents.y, result.comnents.z);

    // Сложение четырех векторов (включая сам результат)
    sum_vectors(&result, &v1, &v2, &v3, &result, NULL);
    printf("Сумма с предыдущим результатом = (%.2f, %.2f, %.2f)\n", result.comnents.x, result.comnents.y, result.comnents.z);

    return 0;
}

__int8 sum_vectors(vector* result_vector, ...) {
    if (result_vector == NULL) {
        return -1; // Ошибка: result_vector не может быть NULL
    }

    result_vector->comnents.x = 0.0f;
    result_vector->comnents.y = 0.0f;
    result_vector->comnents.z = 0.0f;

    va_list args;
    va_start(args, result_vector);

    // Читаем векторы пока не встретим NULL как указатель-терминатор
    vector* current_vector;

    while (1) {
        // Явно получаем указатель
        current_vector = va_arg(args, vector*);

        // Проверяем на NULL (завершающий маркер)
        if (current_vector == NULL) {
            break;
        }

        result_vector->comnents.x += current_vector->comnents.x;
        result_vector->comnents.y += current_vector->comnents.y;
        result_vector->comnents.z += current_vector->comnents.z;
    }

    va_end(args);
    return 0; // Успех
}
