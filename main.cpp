#include <iostream>
#include <memory>
#include <vector>
#include "shared_types.h"
using namespace std;


unique_ptr<Result> calculateA(shared_ptr<const InputData> data);
unique_ptr<Result> calculateB(shared_ptr<const InputData> data);

int main() {

    // Створюємо порожнi вхiднi данi через shared_ptr
    auto input = make_shared<InputData>();
    input->x0 = 2.5;

    // Викликаємо обидвi заглушки
    auto resultA = calculateA(input);
    auto resultB = calculateB(input);

    // Розпаковка через Structured Bindings (наразi тут будуть просто нулi)
    auto [yA, opsA] = *resultA;
    auto [yB, opsB] = *resultB;

    cout << "Result A: Y = " << yA << ", operations = " << opsA << "\n";
    cout << "Result B: Y = " << yB << ", operations = " << opsB << "\n";

    return 0;
}
