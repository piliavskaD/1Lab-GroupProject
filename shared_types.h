#ifndef SHARED_TYPES_H
#define SHARED_TYPES_H

#include <vector>
#include <memory>

struct Point {
    double x;
    double y;
};

struct InputData {
    std::vector<Point> points;
    double x0;
};

// Результат роботи алгоритмів
struct Result {
    double y0; // Знайдене значення
    int operations_count; // Обчислювальна складність (кількість кроків/операцій)
};

using InPtr = std::shared_ptr<const InputData>;
using OutPtr = std::unique_ptr<Result>;

#endif // SHARED_TYPES_H
