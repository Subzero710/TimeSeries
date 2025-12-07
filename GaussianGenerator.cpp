#include "headers/GaussianGenerator.h"

#include <cmath>
#include <cstdlib>
using namespace std;

GaussianGenerator::GaussianGenerator()
    : TimeSeriesGenerator(), mean(0.0), stddev(0.0) {
}

GaussianGenerator::GaussianGenerator(int seed, double mean, double stddev)
    : TimeSeriesGenerator(seed), mean(mean), stddev(stddev) {
}

double GaussianGenerator::boxMuller() const {
    double u1 = (rand() + 1.0) / (RAND_MAX + 2.0);
    double u2 = (rand() + 1.0) / (RAND_MAX + 2.0);

    double z = sqrt(-2.0 * log(u1)) * cos(2.0 * acos(0.0) * u2);

    return mean + stddev * z;
}

vector<double> GaussianGenerator::generateTimeSeries(int size) {
    vector<double> ts;
    ts.reserve(size);

    for (int i = 0; i < size; ++i) {
        ts.push_back(boxMuller());
    }

    return ts;
}
