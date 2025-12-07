#ifndef TD2_KNN_H
#define TD2_KNN_H

#include <vector>
#include <string>
#include "TimeSeriesDataset.h"
using namespace std;

class KNN {
private:
    int k;
    string similarity_measure; // "euclidean_distance" or "dtw"

public:
    KNN(int k, string similarity_measure);

    int predict(const TimeSeriesDataset& trainData,
                const vector<double>& query) const;

    double evaluate(const TimeSeriesDataset& trainData,
                    const TimeSeriesDataset& testData,
                    const vector<int>& ground_truth) const;
};

#endif // TD2_KNN_H
