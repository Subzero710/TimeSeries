#ifndef TP2CPP_TIMESERIESGENERATOR_H
#define TP2CPP_TIMESERIESGENERATOR_H

#include <vector>
using namespace std;

class TimeSeriesGenerator {
protected:
    int seed;

public:
    TimeSeriesGenerator();
    TimeSeriesGenerator(int seed);

    virtual vector<double> generateTimeSeries(int size) = 0;

    static void printTimeSeries(const vector<double> ts);
};

#endif // TP2CPP_TIMESERIESGENERATOR_H
