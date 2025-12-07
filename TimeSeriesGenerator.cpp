#include "headers/TimeSeriesGenerator.h"

#include <cstdlib>
#include <iostream>
using namespace std;

TimeSeriesGenerator::TimeSeriesGenerator() : seed(0) {
    srand(seed);
}

TimeSeriesGenerator::TimeSeriesGenerator(int seed) : seed(seed) {
    srand(seed);
}

void TimeSeriesGenerator::printTimeSeries(const vector<double> ts) {
    for (size_t i = 0; i < ts.size(); ++i) {
        cout << ts[i] << " ";
    }
    cout << endl;
}
