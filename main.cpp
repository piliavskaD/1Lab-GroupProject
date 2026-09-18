#include "shared_types.h"
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

int main()
{
    InputData rawData{
        vector<Point>{
        {0.0, 0.0},
        {1.0, 1.0},
        {2.0, 4.0},
        {3.0, 9.0},
        {4.0, 16.0}
        },
        2.5
    };

    auto data = make_shared<const InputData>(rawData);

    auto resultA = calculateA(data);
    auto resultB = calculateB(data);

    auto [valueA, errorA] = *resultA;
    auto [valueB, errorB] = *resultB;

    cout << "Student A result: " << valueA << ", deviation: " << errorA << "\n";
    cout << "Student B result: " << valueB << ", error: " << errorB << "\n";


    return 0;
}