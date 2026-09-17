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


struct Result {
    double value;          // інтерпольоване значення функції
    double estimatedError; // характеристика похибки
};

using InPtr = std::shared_ptr<const InputData>;
using OutPtr = std::unique_ptr<Result>;

OutPtr calculateA(InPtr data);
OutPtr calculateB(InPtr data);

#endif 