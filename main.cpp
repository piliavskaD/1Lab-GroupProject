#include <iostream>
#include "shared_types.h"

int main() {
    std::cout << "--- Lab 1 Group Project ---\n";

    InputData input;
    input.parameter = 10;

    Result resA = processStudentA(input);
    Result resB = processStudentB(input);

    std::cout << "Student A execution success: " << std::boolalpha << resA.isSuccess << "\n";
    std::cout << "Student B execution success: " << std::boolalpha << resB.isSuccess << "\n";

    return 0;
}