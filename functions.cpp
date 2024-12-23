#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <functional>
#include <stdexcept>

using namespace std;

typedef vector<double> Vec;

// Utility functions
double sum(const Vec &x) {
    return accumulate(x.begin(), x.end(), 0.0);
}

double prod(const Vec &x) {
    return accumulate(x.begin(), x.end(), 1.0, multiplies<double>());
}

double mean(const Vec &x) {
    return sum(x) / x.size();
}

// Function implementations
double ackley(const Vec &x, double a = 20, double b = 0.2, double c = 2 * M_PI) {
    double s1 = 0.0, s2 = 0.0;
    for (double xi : x) {
        s1 += xi * xi;
        s2 += cos(c * xi);
    }
    int n = x.size();
    return -a * exp(-b * sqrt(s1 / n)) - exp(s2 / n) + a + exp(1);
}

double dixonprice(const Vec &x) {
    int n = x.size();
    double result = (x[0] - 1) * (x[0] - 1);
    for (int i = 1; i < n; ++i) {
        result += (i + 1) * pow(2 * x[i] * x[i] - x[i - 1], 2);
    }
    return result;
}

double griewank(const Vec &x, double fr = 4000) {
    double s = 0.0;
    double p = 1.0;
    for (size_t i = 0; i < x.size(); ++i) {
        s += x[i] * x[i];
        p *= cos(x[i] / sqrt(i + 1));
    }
    return s / fr - p + 1;
}

double perm(const Vec &x, double b = 0.5) {
    int n = x.size();
    double result = 0.0;
    for (int k = 1; k <= n; ++k) {
        double inner = 0.0;
        for (int j = 1; j <= n; ++j) {
            double term = pow(j, k) + b;
            inner += term * (pow(fabs(x[j - 1]) / j, k) - 1);
        }
        result += inner * inner;
    }
    return result;
}

double rastrigin(const Vec &x) {
    int n = x.size();
    double result = 10 * n;
    for (double xi : x) {
        result += xi * xi - 10 * cos(2 * M_PI * xi);
    }
    return result;
}

double rosenbrock(const Vec &x) {
    double result = 0.0;
    for (size_t i = 0; i < x.size() - 1; ++i) {
        result += pow(1 - x[i], 2) + 100 * pow(x[i + 1] - x[i] * x[i], 2);
    }
    return result;
}

double schwefel(const Vec &x) {
    double result = 0.0;
    for (double xi : x) {
        result += xi * sin(sqrt(abs(xi)));
    }
    return 418.9829 * x.size() - result;
}

double sphere(const Vec &x) {
    double result = 0.0;
    for (double xi : x) {
        result += xi * xi;
    }
    return result;
}

double zakharov(const Vec &x) {
    double s1 = 0.0, s2 = 0.0;
    for (size_t i = 0; i < x.size(); ++i) {
        s1 += x[i] * x[i];
        s2 += 0.5 * (i + 1) * x[i];
    }
    return s1 + s2 * s2 + s2 * s2 * s2 * s2;
}

// Function selection
typedef function<double(const Vec &)> TestFunction;

TestFunction selectFunction(int cbIndex) {
    switch (cbIndex) {
        case 0: return [](const Vec &x) { return ackley(x); };
        case 1: return dixonprice;
        case 2: return [](const Vec &x) { return griewank(x); };
        case 3: return [](const Vec &x) { return perm(x); };
        case 4: return rastrigin;
        case 5: return rosenbrock;
        case 6: return schwefel;
        case 7: return sphere;
        case 8: return zakharov;
        default: throw invalid_argument("Invalid function index");
    }
}
