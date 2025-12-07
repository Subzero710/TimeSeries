#include "headers/TimeSeriesDataset.h"
#include <cmath>
using namespace std;

TimeSeriesDataset::TimeSeriesDataset(bool znormalise, bool isTrain, vector<double> data, int maxLength, int numberOfSamples)
    : znormalise(znormalise),
      isTrain(isTrain),
      data(data),
      maxLength(maxLength),
      numberOfSamples(numberOfSamples) {
}

double TimeSeriesDataset::euclidian_distance(const vector<double> a,
                                             const vector<double> b) {
    double sum = 0.0;
    int n = (int)a.size();

    for (int i = 0; i < n; ++i) {
        double d = a[i] - b[i];
        sum += d * d;
    }

    return sqrt(sum);
}
