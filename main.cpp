#include <iostream>
#include "shared_types.h"
using namespace std;

int main() {
    cout << "--- Lab 1 Group Project ---\n";

    InputData input;
    input.parameter = 10;

    Result resA = processStudentA(input);
    Result resB = processStudentB(input);

    cout << "Student A(Piliavska) execution success: " << std::boolalpha << resA.isSuccess << "\n";
    cout << "Student B(Vorona) execution success: " << std::boolalpha << resB.isSuccess << "\n";

    return 0;
}