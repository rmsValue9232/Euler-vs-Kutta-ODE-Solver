#ifndef DATADEF
#define DATADEF
#include <iostream>

// A class to implement data handling
// customised to this problem of ODE
// solvers more efficiently.
class Data {
    private:
        // Since this class object does not
        // retain any data before saving or
        // loading it, its copy constructor
        // needs to unusable, hence it is
        // private.
        Data(const Data& sd);
    public:
        Data();
        void save(double* t, double* y, std::string path, unsigned int N);
        double** load(std::string path);
};

#endif