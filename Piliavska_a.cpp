#include "shared_types.h"
#include <iostream>
#include <vector>
#include <cmath> 

using namespace std;


OutPtr calculateA(InPtr data) {
    cout << "[LOG] Executing: calculateA (Lagrange Interpolation)\n";

    auto result = make_unique<Result>();

    double x0 = data->x0;
    const auto& pts = data->points;
    size_t n = pts.size();

    double sum = 0.0;

    for (size_t i = 0; i < n; ++i) {
        double term = pts[i].y;
        for (size_t j = 0; j < n; ++j) {
            if (i != j) {
                term *= (x0 - pts[j].x) / (pts[i].x - pts[j].x);
            }
        }
        sum += term;
    }

    result->value = sum;


    if (n > 1) {
        double total_h = 0.0;
        for (size_t i = 0; i < n - 1; ++i) {
            total_h += (pts[i + 1].x - pts[i].x);
        }
        double avg_h = total_h / (n - 1);

        result->estimatedError = pow(avg_h, n);
    }
    else {
        result->estimatedError = 0.0;
    }

    return result;
}
