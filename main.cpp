#include <iostream>
#include <vector>
#include <numeric>
#include "GEO.cpp"
using namespace std;
typedef vector<double> Vec;

#define SELECT_ACKLEY 0
#define SELECT_DIXONPRICE 0 
#define SELECT_GRIEWANK 0
#define SELECT_PERM 0
#define SELECT_RASTRIGIN 0
#define SELECT_ROSENBROCK 0
#define SELECT_SCHWEFEL 0
#define SELECT_SPHERE 0
#define SELECT_ZAKHAROV 1

int populationsize = 100;
int Iteration = 1000;
int dim = 30;

#if SELECT_ACKLEY
int main() {
    Vec lb(dim, -32768.0);
    Vec ub(dim, 32768.0);
    TestFunction fun = selectFunction(0);
    cout << "Selected function is Ackley" << endl;
    GEO(fun, dim, lb, ub, populationsize, Iteration, 0.5, 0.1, 1.0, 0.5);

    return 0;
}
#endif

#if SELECT_DIXONPRICE
int main() {
    int dim = 5;
    Vec lb(dim, -10.0);
    Vec ub(dim, 10.0);
    TestFunction fun = selectFunction(1);
    cout << "Selected function is Dixonprice" << endl;
    GEO(fun, dim, lb, ub, populationsize, Iteration, 0.5, 0.1, 1.0, 0.5);

    return 0;
}
#endif

#if SELECT_GRIEWANK
int main() {
    Vec lb(dim, -600.0);
    Vec ub(dim, 600.0);
    TestFunction fun = selectFunction(2);
    cout << "Selected function is Griewank" << endl;
    GEO(fun, dim, lb, ub, populationsize, Iteration, 0.5, 0.1, 1.0, 0.5);

    return 0;
}
#endif

#if SELECT_PERM
int main() {
    Vec lb(dim, -5.0);
    Vec ub(dim, 5.0);
    TestFunction fun = selectFunction(3);
    cout << "Selected function is Perm" << endl;
   GEO(fun, dim, lb, ub, populationsize, Iteration, 0.5, 0.1, 1.0, 0.5);

    return 0;
}
#endif

#if SELECT_RASTRIGIN
int main() {
    Vec lb(dim, -5.12);
    Vec ub(dim, 5.12);
    TestFunction fun = selectFunction(4);
    cout << "Selected function is Rastrigin" << endl;
    GEO(fun, dim, lb, ub, populationsize, Iteration, 0.5, 0.1, 1.0, 0.5);

    return 0;
}
#endif

#if SELECT_ROSENBROCK
int main() {
    Vec lb(dim, -2048.0);
    Vec ub(dim, 2048.0);
    TestFunction fun = selectFunction(5);
    cout << "Selected function is Rosenbrock" << endl;
    GEO(fun, dim, lb, ub, populationsize, Iteration, 0.5, 0.1, 1.0, 0.5);

    return 0;
}
#endif

#if SELECT_SCHWEFEL
int main() {
    Vec lb(dim, -500.0);
    Vec ub(dim, 500.0);
    TestFunction fun = selectFunction(6);
    cout << "Selected function is Schwefel" << endl;
    GEO(fun, dim, lb, ub, populationsize, Iteration, 0.5, 0.1, 1.0, 0.5);

    return 0;
}
#endif

#if SELECT_SPHERE
int main() {
    Vec lb(dim, -5.12);
    Vec ub(dim, 5.12);
    TestFunction fun = selectFunction(7);
    cout << "Selected function is Sphere" << endl;
    GEO(fun, dim, lb, ub, populationsize, Iteration, 0.5, 0.1, 1.0, 0.5);

    return 0;
}
#endif

#if SELECT_ZAKHAROV
int main() {
    int dim = 5;
    Vec lb(dim, -5.0);
    Vec ub(dim, 10.0);
    TestFunction fun = selectFunction(8);
    cout << "Selected function is Zakhraov" << endl;
    GEO(fun, dim, lb, ub, populationsize, Iteration, 0.5, 0.1, 1.0, 0.5);

    return 0;
}
#endif
