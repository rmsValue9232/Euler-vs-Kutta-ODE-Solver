#include <cassert>
#include "AbstractOdeSolver.hpp"

void AbstractOdeSolver::SetStepSize(double h){
    assert(("Step size should be strictly greater than 0", h>0));
    stepSize = h;
}

void AbstractOdeSolver::SetTimeInterval(double t0, double t1) {
    assert(("Final time should be greater than or equal to initial time", t1>=t0));
    initialTime = t0;
    finalTime = t1;
}

void AbstractOdeSolver::SetInitialValue (double y0) {
    initialValue = y0;
}