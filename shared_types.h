#ifndef SHARED_TYPES_H
#define SHARED_TYPES_H

#include <iostream>
#include <vector>

// Структура вхідних даних
struct InputData {
    std::vector<double> values;
    int parameter = 0;
};

// Структура результату
struct Result {
    double calculatedValue = 0.0;
    bool isSuccess = false;
};

// Заглушки функцій для двох студентів
Result processStudentA(const InputData& data);
Result processStudentB(const InputData& data);

#endif // SHARED_TYPES_H