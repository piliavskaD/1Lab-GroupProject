#ifndef SHARED_TYPES_H
#define SHARED_TYPES_H

#include <vector>
#include <memory>

using namespace std;

struct Point
{
    double x;
    double y;
};

struct InputData
{
    vector<Point> points;
    double x0;
};

struct Result
{
    double value;
    double estimatedError;
};

unique_ptr<Result> calculateA(
    shared_ptr<const InputData> data);

unique_ptr<Result> calculateB(
    shared_ptr<const InputData> data);

#endif // SHARED_TYPES_H