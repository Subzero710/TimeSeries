#ifndef TP2CPP_GAUSSIANGENERATOR_H
#define TP2CPP_GAUSSIANGENERATOR_H

#include "TimeSeriesGenerator.h"
using namespace std;

class GaussianGenerator : public TimeSeriesGenerator {
private:
    double mean;
    double stddev;

    double boxMuller() const;

public:
    GaussianGenerator();
    GaussianGenerator(int seed, double mean, double stddev);

    vector<double> generateTimeSeries(int size) override;
};

#endif // TP2CPP_GAUSSIANGENERATOR_H
