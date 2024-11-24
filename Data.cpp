#include <fstream>
#include <iostream>
#include <cassert>
#include "Data.hpp"

Data::Data() {}

// Saves the given time array: t, solution array: y
// into the specified path, given the number of
// sub intervals: N
void Data::save(double* t, double* y, std::string path, unsigned int N) {
    std::ofstream write_output(path);
    assert(("File could not be opened", write_output.is_open()));
    write_output.precision(10);

    // make first row of the data file to be
    // for retaining size of the data to
    // expect when reading
    write_output << N << ' ' << N << '\n';

    // format of data file is simple:
    // t[i] y[i]
    // for all i = 0 upto N
    for (int i = 0; i <= N; i++) {
        write_output << t[i] << ' ' << y[i] << '\n';
    }

    write_output.close();
}

// Loads the given time array: t, solution array: y
// from the specified path, noting the number of
// sub intervals: N
double** Data::load(std::string path) {
    std::ifstream read_file(path);
    assert(("File could not be opened", read_file.is_open()));

    unsigned int N;
    read_file >> N >> N;

    double** data = new double*[2];
    for (int i = 0; i < 2; i++) {
        data[i] = new double[N+1];
    }

    // As the first row only informs
    // the size of datapoints to
    // expect.
    data[0][0] = N;
    data[1][0] = N;

    int i = 1;
    while(!read_file.eof()) {
        read_file >> data[0][i] >> data[1][i];
        i++;
    }

    read_file.close();

    // *data[0][i] holds the information of t[i]
    // *data[1][i] holds the information of y[i]
    // valid for all i from 1 upto N
    return data;
}