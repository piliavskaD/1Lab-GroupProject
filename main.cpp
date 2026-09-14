#include "shared_types.h"
#include <iostream>

using namespace std;

int main()
{
    auto data = make_shared<const InputData>(
        InputData{
            {
                { 1.0, 2.0 },
                { 2.0, 4.0 },
                { 3.0, 6.0 },
                { 4.0, 8.0 }
            },
            2.5
        }
    );

    auto resultA = calculateA(data);
    auto resultB = calculateB(data);

    auto [valueA, errorA] = *resultA;
    auto [valueB, errorB] = *resultB;

    cout << "Student A: value = " << valueA
        << ", error = " << errorA << endl;

    cout << "Student B: value = " << valueB
        << ", error = " << errorB << endl;

    return 0;
}