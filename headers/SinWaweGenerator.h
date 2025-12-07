#ifndef TD2_SINWAWEGENERATOR_H
#define TD2_SINWAWEGENERATOR_H

#include <cmath>
#include "TimeSeriesGenerator.h"
using namespace std;

class SinWaweGenerator : public TimeSeriesGenerator {
private:
    double a;
    double omega;
    double phi;

public:
    SinWaweGenerator(int _seed, double _a, double _omega, double _phi);

    vector<double> generateTimeSeries(int taille) override;
};

#endif // TD2_SINWAWEGENERATOR_H
