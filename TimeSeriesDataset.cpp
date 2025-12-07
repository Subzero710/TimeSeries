#include "headers/TimeSeriesDataset.h"

#include <cmath>
#include <limits>
using namespace std;

TimeSeriesDataset::TimeSeriesDataset(bool znormalise, bool isTrain)
    : znormalise(znormalise),
      isTrain(isTrain),
      data(),
      maxLength(0),
      numberOfSamples(0) {
}

vector<double> TimeSeriesDataset::zNormalize(const vector<double>& s) {
    int n = (int)s.size();
    if (n == 0) {
        return s;
    }

    double mean = 0.0;
    for (int i = 0; i < n; ++i) {
        mean += s[i];
    }
    mean /= n;

    double var = 0.0;
    for (int i = 0; i < n; ++i) {
        double d = s[i] - mean;
        var += d * d;
    }
    var /= n;
    double stddev = sqrt(var);

    vector<double> result(n);
    if (stddev == 0.0) {
        for (int i = 0; i < n; ++i) {
            result[i] = 0.0;
        }
    } else {
        for (int i = 0; i < n; ++i) {
            result[i] = (s[i] - mean) / stddev;
        }
    }
    return result;
}

void TimeSeriesDataset::addTimeSeries(const vector<double>& s, int label) {
    vector<double> tmp = s;
    if (znormalise) {
        tmp = zNormalize(s);
    }

    series.push_back(tmp);
    labels.push_back(label);
    numberOfSamples++;

    if ((int)tmp.size() > maxLength) {
        maxLength = (int)tmp.size();
    }
}

void TimeSeriesDataset::addTimeSeries(const vector<double>& s) {
    vector<double> tmp = s;
    if (znormalise) {
        tmp = zNormalize(s);
    }

    series.push_back(tmp);
    numberOfSamples++;

    if ((int)tmp.size() > maxLength) {
        maxLength = (int)tmp.size();
    }
}

const vector<double>& TimeSeriesDataset::getTimeSeries(int index) const {
    return series[index];
}

int TimeSeriesDataset::getLabel(int index) const {
    return labels[index];
}

int TimeSeriesDataset::getNumberOfSamples() const {
    return numberOfSamples;
}

double TimeSeriesDataset::euclidian_distance(const vector<double>& a,
                                             const vector<double>& b) const {
    int n = (int)a.size();
    int m = (int)b.size();
    int len = n < m ? n : m;

    double sum = 0.0;
    for (int i = 0; i < len; ++i) {
        double d = a[i] - b[i];
        sum += d * d;
    }

    return sqrt(sum);
}

double TimeSeriesDataset::dtw_distance(const vector<double>& a,
                                       const vector<double>& b) const {
    int n = (int)a.size();
    int m = (int)b.size();

    const double INF = numeric_limits<double>::infinity();
    vector< vector<double> > D(n + 1, vector<double>(m + 1, INF));

    D[0][0] = 0.0;
    for (int i = 1; i <= n; ++i) {
        D[i][0] = INF;
    }
    for (int j = 1; j <= m; ++j) {
        D[0][j] = INF;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            double diff = a[i - 1] - b[j - 1];
            double cost = diff * diff;

            double best = D[i - 1][j];
            if (D[i][j - 1] < best) {
                best = D[i][j - 1];
            }
            if (D[i - 1][j - 1] < best) {
                best = D[i - 1][j - 1];
            }

            D[i][j] = cost + best;
        }
    }

    return sqrt(D[n][m]);
}
