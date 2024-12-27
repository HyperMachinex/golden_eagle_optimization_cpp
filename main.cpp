#include <iostream>
#include <vector>
#include <numeric>
#include "GEO.cpp"
#include <chrono>
#include <windows.h>
#include <malloc.h>    
#include <stdio.h>
#include <tchar.h>
using namespace std;
typedef vector<double> Vec;

#define SELECT_ACKLEY 1
#define SELECT_DIXONPRICE 0
#define SELECT_GRIEWANK 0
#define SELECT_PERM 0
#define SELECT_RASTRIGIN 0
#define SELECT_ROSENBROCK 0
#define SELECT_SCHWEFEL 0
#define SELECT_SPHERE 0
#define SELECT_ZAKHAROV 0

int populationsize = 1000;
int Iteration[] = {500,1000,5000};
int dim = 30;
//const auto processor_count = thread::hardware_concurrency();
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;

#if SELECT_ACKLEY
int main() {
    printf("Running on %d cores.\n", atoi(getenv("NUMBER_OF_PROCESSORS")));
    Vec lb(dim, -32768.0);
    Vec ub(dim, 32768.0);
    TestFunction fun = selectFunction(0);
    cout << "Selected function is Ackley" << endl; 
    for(int i=0; i< sizeof(Iteration)/sizeof(int); i++){
        cout <<"Iteration Number:" << Iteration[i] << endl;
        auto t1 = high_resolution_clock::now();
        GEO(fun, dim, lb, ub, populationsize, Iteration[i]);
        auto t2 = high_resolution_clock::now();
        duration<double> ms_double = t2 - t1;
        cout << "Runtime:" << ms_double.count() << "s\n";
    }
    return 0;
}
#endif

#if SELECT_DIXONPRICE
int main() {
    printf("Running on %d cores.\n", atoi(getenv("NUMBER_OF_PROCESSORS")));
    int dim = 5;
    Vec lb(dim, -10.0);
    Vec ub(dim, 10.0);
    TestFunction fun = selectFunction(1);
    cout << "Selected function is Dixonprice" << endl;
    for(int i=0; i< sizeof(Iteration)/sizeof(int); i++){
        cout <<"Iteration Number:" << Iteration[i] << endl;
        auto t1 = high_resolution_clock::now();
        GEO(fun, dim, lb, ub, populationsize, Iteration[i]);
        auto t2 = high_resolution_clock::now();
        duration<double> ms_double = t2 - t1;
        cout << "Runtime:" << ms_double.count() << "s\n";
    }
    return 0;
}
#endif

#if SELECT_GRIEWANK
int main() {
    printf("Running on %d cores.\n", atoi(getenv("NUMBER_OF_PROCESSORS")));
    Vec lb(dim, -600.0);
    Vec ub(dim, 600.0);
    TestFunction fun = selectFunction(2);
    cout << "Selected function is Griewank" << endl;
    for(int i=0; i< sizeof(Iteration)/sizeof(int); i++){
        cout <<"Iteration Number:" << Iteration[i] << endl;
        auto t1 = high_resolution_clock::now();
        GEO(fun, dim, lb, ub, populationsize, Iteration[i]);
        auto t2 = high_resolution_clock::now();
        duration<double> ms_double = t2 - t1;
        cout << "Runtime:" << ms_double.count() << "s\n";
    }
    return 0;
}
#endif

#if SELECT_PERM
int main() {
    printf("Running on %d cores.\n", atoi(getenv("NUMBER_OF_PROCESSORS")));
    Vec lb(dim, -5.0);
    Vec ub(dim, 5.0);
    TestFunction fun = selectFunction(3);
    cout << "Selected function is Perm" << endl;
    for(int i=0; i< sizeof(Iteration)/sizeof(int); i++){
        cout <<"Iteration Number:" << Iteration[i] << endl;
        auto t1 = high_resolution_clock::now();
        GEO(fun, dim, lb, ub, populationsize, Iteration[i]);
        auto t2 = high_resolution_clock::now();
        duration<double> ms_double = t2 - t1;
        cout << "Runtime:" << ms_double.count() << "s\n";
    }
    return 0;
}
#endif

#if SELECT_RASTRIGIN
int main() {
    printf("Running on %d cores.\n", atoi(getenv("NUMBER_OF_PROCESSORS")));
    Vec lb(dim, -5.12);
    Vec ub(dim, 5.12);
    TestFunction fun = selectFunction(4);
    cout << "Selected function is Rastrigin" << endl;
    for(int i=0; i< sizeof(Iteration)/sizeof(int); i++){
        cout <<"Iteration Number:" << Iteration[i] << endl;
        auto t1 = high_resolution_clock::now();
        GEO(fun, dim, lb, ub, populationsize, Iteration[i]);
        auto t2 = high_resolution_clock::now();
        duration<double> ms_double = t2 - t1;
        cout << "Runtime:" << ms_double.count() << "s\n";
    }
    return 0;
}
#endif

#if SELECT_ROSENBROCK
int main() {
    printf("Running on %d cores.\n", atoi(getenv("NUMBER_OF_PROCESSORS")));
    Vec lb(dim, -2048.0);
    Vec ub(dim, 2048.0);
    TestFunction fun = selectFunction(5);
    cout << "Selected function is Rosenbrock" << endl;
    for(int i=0; i< sizeof(Iteration)/sizeof(int); i++){
        cout <<"Iteration Number:" << Iteration[i] << endl;
        auto t1 = high_resolution_clock::now();
        GEO(fun, dim, lb, ub, populationsize, Iteration[i]);
        auto t2 = high_resolution_clock::now();
        duration<double> ms_double = t2 - t1;
        cout << "Runtime:" << ms_double.count() << "s\n";
    }
    return 0;
}
#endif

#if SELECT_SCHWEFEL
int main() {
    printf("Running on %d cores.\n", atoi(getenv("NUMBER_OF_PROCESSORS")));
    Vec lb(dim, -500.0);
    Vec ub(dim, 500.0);
    TestFunction fun = selectFunction(6);
    cout << "Selected function is Schwefel" << endl;
    for(int i=0; i< sizeof(Iteration)/sizeof(int); i++){
        cout <<"Iteration Number:" << Iteration[i] << endl;
        auto t1 = high_resolution_clock::now();
        GEO(fun, dim, lb, ub, populationsize, Iteration[i]);
        auto t2 = high_resolution_clock::now();
        duration<double> ms_double = t2 - t1;
        cout << "Runtime:" << ms_double.count() << "s\n";
    }
    return 0;
}
#endif

#if SELECT_SPHERE
int main() {
    printf("Running on %d cores.\n", atoi(getenv("NUMBER_OF_PROCESSORS")));
    Vec lb(dim, -5.12);
    Vec ub(dim, 5.12);
    TestFunction fun = selectFunction(7);
    cout << "Selected function is Sphere" << endl;
    for(int i=0; i< sizeof(Iteration)/sizeof(int); i++){
        cout <<"Iteration Number:" << Iteration[i] << endl;
        auto t1 = high_resolution_clock::now();
        GEO(fun, dim, lb, ub, populationsize, Iteration[i]);
        auto t2 = high_resolution_clock::now();
        duration<double> ms_double = t2 - t1;
        cout << "Runtime:" << ms_double.count() << "s\n";
    }
    return 0;
}
#endif

#if SELECT_ZAKHAROV
int main() {
    printf("Running on %d cores.\n", atoi(getenv("NUMBER_OF_PROCESSORS")));
    int dim = 5;
    Vec lb(dim, -5.0);
    Vec ub(dim, 10.0);
    TestFunction fun = selectFunction(8);
    cout << "Selected function is Zakhraov" << endl;
    for(int i=0; i< sizeof(Iteration)/sizeof(int); i++){
        cout <<"Iteration Number:" << Iteration[i] << endl;
        auto t1 = high_resolution_clock::now();
        GEO(fun, dim, lb, ub, populationsize, Iteration[i]);
        auto t2 = high_resolution_clock::now();
        duration<double> ms_double = t2 - t1;
        cout << "Runtime:" << ms_double.count() << "s\n";
    }
    return 0;
}
#endif
