#include "shared_types.h"
#include <memory>
using namespace std;

struct SplineCoefficients
{
    vector<double> a, b, c, d, x;
};

static SplineCoefficients buildNaturalSpline(const vector<Point>& points)
{
    const size_t n = points.size();

    vector<double> x(n), a(n);
    for (size_t i = 0; i < n; ++i)
    {
        x[i] = points[i].x;
        a[i] = points[i].y;
    }

    vector<double> h(n - 1);
    for (size_t i = 0; i < n - 1; ++i)
        h[i] = x[i + 1] - x[i];

    vector<double> alpha(n, 0.0);
    for (size_t i = 1; i < n - 1; ++i)
        alpha[i] = (3.0 / h[i]) * (a[i + 1] - a[i]) - (3.0 / h[i - 1]) * (a[i] - a[i - 1]);

    vector<double> l(n, 1.0), mu(n, 0.0), z(n, 0.0);
    for (size_t i = 1; i < n - 1; ++i)
    {
        l[i] = 2.0 * (x[i + 1] - x[i - 1]) - h[i - 1] * mu[i - 1];
        mu[i] = h[i] / l[i];
        z[i] = (alpha[i] - h[i - 1] * z[i - 1]) / l[i];
    }

    vector<double> c(n, 0.0), b(n - 1, 0.0), d(n - 1, 0.0);
    for (size_t idx = 0; idx < n - 1; ++idx)
    {
        size_t j = n - 2 - idx;
        c[j] = z[j] - mu[j] * c[j + 1];
        b[j] = (a[j + 1] - a[j]) / h[j] - h[j] * (c[j + 1] + 2.0 * c[j]) / 3.0;
        d[j] = (c[j + 1] - c[j]) / (3.0 * h[j]);
    }

    return SplineCoefficients{ move(a), move(b), move(c), move(d), move(x) };
}

static double evaluateSpline(const SplineCoefficients& s, double x0)
{
    const size_t n = s.x.size();
    size_t seg = 0;

    if (x0 <= s.x.front())
        seg = 0;
    else if (x0 >= s.x.back())
        seg = n - 2;
    else
    {
        for (size_t i = 0; i < n - 1; ++i)
        {
            if (x0 >= s.x[i] && x0 <= s.x[i + 1])
            {
                seg = i;
                break;
            }
        }
    }

    double dx = x0 - s.x[seg];
    return s.a[seg] + s.b[seg] * dx + s.c[seg] * dx * dx + s.d[seg] * dx * dx * dx;
}

static double estimateError(const vector<Point>& points, double x0, double fullValue)
{
    if (points.size() < 4)
        return 0.0;

    vector<Point> reduced(points.begin(), points.end() - 1);
    auto reducedSpline = buildNaturalSpline(reduced);
    double reducedValue = evaluateSpline(reducedSpline, x0);
    return abs(fullValue - reducedValue);
}

unique_ptr<Result> calculateB(shared_ptr<const InputData> data)
{
    auto spline = buildNaturalSpline(data->points);
    double value = evaluateSpline(spline, data->x0);
    double error = estimateError(data->points, data->x0, value);

    auto result = make_unique<Result>();
    result->value = value;
    result->estimatedError = error;

    return result;
}