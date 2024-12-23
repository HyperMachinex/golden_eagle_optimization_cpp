#include <iostream>
#include <vector>
#include <functional>
#include <cmath>
#include <limits>
#include <random>
#include "functions.cpp"

using namespace std;

typedef vector<double> Vec;

double VecNorm(const Vec &x, double p) {
    double norm = 0.0;
    for (double xi : x) {
        norm += pow(fabs(xi), p);
    }
    return pow(norm, 1.0 / p);
}

void GEO(TestFunction fun, int nvars, const Vec &lb, const Vec &ub, int populationSize, int maxIterations, 
         double attackStart, double attackEnd, double cruiseStart, double cruiseEnd) {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0.0, 1.0);

    vector<Vec> population(populationSize, Vec(nvars));
    Vec fitnessScores(populationSize);
    Vec flockMemoryF(populationSize, numeric_limits<double>::max());
    vector<Vec> flockMemoryX(populationSize, Vec(nvars));

    for (int i = 0; i < populationSize; ++i) {
        for (int j = 0; j < nvars; ++j) {
            population[i][j] = lb[j] + dis(gen) * (ub[j] - lb[j]);
        }
        fitnessScores[i] = fun(population[i]);
        flockMemoryF[i] = fitnessScores[i];
        flockMemoryX[i] = population[i];
    }

    Vec attackPropensity(maxIterations);
    Vec cruisePropensity(maxIterations);
    for (int t = 0; t < maxIterations; ++t) {
        attackPropensity[t] = attackStart + t * (attackEnd - attackStart) / (maxIterations - 1);
        cruisePropensity[t] = cruiseStart + t * (cruiseEnd - cruiseStart) / (maxIterations - 1);
    }

    double globalBestF = numeric_limits<double>::max();
    Vec globalBestX(nvars);

    for (int iter = 0; iter < maxIterations; ++iter) {
        vector<Vec> newPopulation(populationSize, Vec(nvars));

        for (int i = 0; i < populationSize; ++i) {
            int j = dis(gen) * populationSize;
            while (j == i) j = dis(gen) * populationSize;

            Vec attackVector(nvars);
            Vec cruiseVector(nvars);
            Vec stepVector(nvars);

            for (int k = 0; k < nvars; ++k) {
                attackVector[k] = flockMemoryX[j][k] - population[i][k];
                cruiseVector[k] = dis(gen) * 2.0 - 1.0;
            }

            double radius = VecNorm(attackVector, 2);

            for (int k = 0; k < nvars; ++k) {
                attackVector[k] *= attackPropensity[iter] * radius / VecNorm(attackVector, 2);
                cruiseVector[k] *= cruisePropensity[iter] * radius / VecNorm(cruiseVector, 2);
                stepVector[k] = attackVector[k] + cruiseVector[k];

                newPopulation[i][k] = population[i][k] + stepVector[k];

                if (newPopulation[i][k] < lb[k]) newPopulation[i][k] = lb[k];
                if (newPopulation[i][k] > ub[k]) newPopulation[i][k] = ub[k];
            }

            double newFitness = fun(newPopulation[i]);
            if (newFitness < flockMemoryF[i]) {
                flockMemoryF[i] = newFitness;
                flockMemoryX[i] = newPopulation[i];
            }

            if (newFitness < globalBestF) {
                globalBestF = newFitness;
                globalBestX = newPopulation[i];
            }
        }

        population = newPopulation;
        cout << "Iteration " << iter + 1 << " Best Fitness: " << globalBestF << endl;
    }

    cout << "Best solution: ";
    for (double xi : globalBestX) {
        cout << xi << " ";
    }
    cout << endl;
    cout << "Best fitness: " << globalBestF << endl;
}
