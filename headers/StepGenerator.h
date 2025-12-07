#ifndef TD2_STEPGENERATOR_H
#define TD2_STEPGENERATOR_H

#include "TimeSeriesGenerator.h"
using namespace std;

class StepGenerator : public TimeSeriesGenerator {
public:
    StepGenerator(int _seed);

    vector<double> generateTimeSeries(int taille) override;
};

#endif // TD2_STEPGENERATOR_H
