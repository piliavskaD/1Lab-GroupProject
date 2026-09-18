#include "shared_types.h"
#include <iostream>
#include <memory>
#include <vector>
#include <chrono>
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

    using clock = std::chrono::steady_clock;

    auto startA = clock::now();
    auto resultA = calculateA(data);
    double timeA = std::chrono::duration<double, std::micro>(clock::now() - startA).count();

    auto startB = clock::now();
    auto resultB = calculateB(data);
    double timeB = std::chrono::duration<double, std::micro>(clock::now() - startB).count();

    auto [valueA, errorA] = *resultA;
    auto [valueB, errorB] = *resultB;

    cout << "Student A result: " << valueA << ", deviation: " << errorA << "\n";
    cout << "Student B result: " << valueB << ", error: " << errorB << "\n";

    cout << "\nComparison:\n";
    cout << "  Value difference: " << abs(valueA - valueB) << "\n";
    cout << "  More accurate:    " << (errorA < errorB ? "Lagrange (A)" : "Spline (B)") << "\n";
    cout << "  Faster: "
        << (timeA < timeB ? "Lagrange (A)" : "Spline (B)")
        << " (A: " << timeA << " us, B: " << timeB << " us)\n";

    return 0;
}