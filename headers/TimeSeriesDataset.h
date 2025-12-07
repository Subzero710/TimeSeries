#ifndef TP2CPP_TIMESERIESDATASET_H
#define TP2CPP_TIMESERIESDATASET_H

#include <vector>
using namespace std;

class TimeSeriesDataset {
private:
    bool znormalise;
    bool isTrain;
    vector<double> data;
    int maxLength;
    int numberOfSamples;

public:
    TimeSeriesDataset(bool znormalise, bool isTrain,
                      vector<double> data, int maxLength,
                      int numberOfSamples);

    double euclidian_distance(const vector<double> a, const vector<double> b);
};

#endif // TP2CPP_TIMESERIESDATASET_H
