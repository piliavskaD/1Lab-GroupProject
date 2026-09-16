#include "shared_types.h"
#include <memory>
#include <iostream>
using namespace std;

// Проста заглушка: повертає порожній результат із нулями
OutPtr calculateB(shared_ptr<const InputData> data) {
    cout << "[LOG] Stub call: calculateB (Cubic Spline Interpolation)\n";

    auto result = make_unique<Result>();
    result->y0 = 0.0;
    result->operations_count = 0;

    return result;
}