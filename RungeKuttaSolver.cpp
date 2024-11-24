#include <cassert>
#include <cfloat>
#include "RungeKuttaSolver.hpp"

RungeKuttaSolver::RungeKuttaSolver(double (*f)(double, double)): f(f) {
    // Assign unrealisable values to the parameters
    // so that assertion breaks down unless they are set
    // by the user, stopping the program.
    stepSize = DBL_MAX;
    initialTime = DBL_MAX;
    finalTime = DBL_MIN;
    initialValue = DBL_MAX;
}

double RungeKuttaSolver::RightHandSide(double y, double t) {
    return f(y,t);
}

double* RungeKuttaSolver::SolveEquation() {
    assert(("Step size has not be initialized yet", stepSize!=DBL_MAX));
    assert(("Time interval has not been defined yet", initialTime!=DBL_MAX));
    assert(("Initial boundary not specified yet", initialValue!=DBL_MAX));
    
    // Number of intervals in between initialTime and finalTime
    // double to int truncation error rounds down, need to add 1
    int N = 1 + int((finalTime - initialTime)/stepSize);
    // t array
    double *t = new double[N+1];
    // y array
    double *y = new double[N+1];

    // RK-4 coefficients
    double k[4];

    t[0] = initialTime;
    y[0] = initialValue;

    for (int i = 1; i <= N; i++) {
        t[i] = t[i-1] + stepSize;

        k[0] = stepSize*RightHandSide(y[i-1], t[i-1]);

        k[1] = stepSize*RightHandSide(y[i-1]+0.5*k[0], t[i-1]+0.5*stepSize);

        k[2] = stepSize*RightHandSide(y[i-1]+0.5*k[1], t[i-1]+0.5*stepSize);

        k[3] = stepSize*RightHandSide(y[i-1]+k[2], t[i-1]+stepSize);

        y[i] = y[i-1] + (k[0]+2*k[1]+2*k[2]+k[3])/6;
    }

    return y;
}

