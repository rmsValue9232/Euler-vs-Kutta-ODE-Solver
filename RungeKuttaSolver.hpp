#ifndef RUNGEKUTTASOLVERDEF
#define RUNGEKUTTASOLVERDEF
#include "AbstractOdeSolver.hpp"

class RungeKuttaSolver: public AbstractOdeSolver {
    private:
        // Need a function pointer to hold onto the
        // external function that is to be utilised
        // as the RightHandSide
        // The solver is defined by this function
        double (*f)(double, double);

        // Putting copy constructor in private
        // so as to not allow to duplicate this
        // object, keeping solver unique to a
        // particular function only
        // Helping in securing the solver from
        // unannounced/unnoticeable changes
        RungeKuttaSolver(const RungeKuttaSolver& S);
    public:
        RungeKuttaSolver(double (*f)(double, double));

        double RightHandSide(double y, double t) override;
        double* SolveEquation() override;
};

#endif