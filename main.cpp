#include <iostream>
#include "AbstractOdeSolver.hpp"
#include "ForwardEulerSolver.hpp"
#include "RungeKuttaSolver.hpp"
#include "Data.hpp"
#include <math.h>

using namespace std;

double f(double y, double t) {
    return sin(5*y)*cos(t+2);
}

void Q1_usingForwardEuler(double initialTime, double finalTime, double initialValue, unsigned int intervalCount) {
    double stepSize = (finalTime - initialTime)/intervalCount;

    double* t = new double[intervalCount+1];
    t[0] = initialTime;

    for (int i = 1; i <= intervalCount; i++) {
        t[i] = t[i-1] + stepSize;
    }
    ForwardEulerSolver fEuler(f);

    fEuler.SetInitialValue(initialValue);
    fEuler.SetTimeInterval(initialTime, finalTime);
    fEuler.SetStepSize(stepSize);

    double* y = fEuler.SolveEquation();

    Data dataHandler;
    dataHandler.save(t, y, "./data/euler_with_"+ to_string(intervalCount+1) + "_points.txt", intervalCount);
}

void Q2_usingRungeKutta(double initialTime, double finalTime, double initialValue, unsigned int intervalCount) {
    double stepSize = (finalTime - initialTime)/intervalCount;

    double* t = new double[intervalCount+1];
    t[0] = initialTime;

    for (int i = 1; i <= intervalCount; i++) {
        t[i] = t[i-1] + stepSize;
    }

    RungeKuttaSolver rKutta(f);

    rKutta.SetInitialValue(initialValue);
    rKutta.SetTimeInterval(initialTime, finalTime);
    rKutta.SetStepSize(stepSize);

    double* y = rKutta.SolveEquation();

    Data dataHandler;
    dataHandler.save(t, y, "./data/kutta_with_"+ to_string(intervalCount+1) + "_points.txt", intervalCount);
}

int main() {
    unsigned int intervalCount = 1;
    double initialTime = -M_PI*10;
    double finalTime = M_PI*10;
    double initialValue = -1;
    double stepSize;

    // Find step size corresponding to
    // each power of 10 that can
    // be used
    for (int i = 1; i <=3; i++) {
        intervalCount *= 10;
        Q1_usingForwardEuler(initialTime, finalTime, initialValue, intervalCount);
        Q2_usingRungeKutta(initialTime, finalTime, initialValue, intervalCount);
    }

    return 0;
}