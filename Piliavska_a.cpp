#include "shared_types.h"
#include <memory>
#include <iostream>
using namespace std;

// Рядок читається як: Функція calculateA приймає вхідні дані (InPtr) 
// і повертає результат (OutPtr). Все!
OutPtr calculateA(InPtr data) {
    cout << "[LOG] Stub call: calculateA\n";

    auto result = make_unique<Result>();
    result->y0 = 0.0;
    result->operations_count = 0;

    return result;
}