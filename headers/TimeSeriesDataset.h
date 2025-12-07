#ifndef TP2CPP_TIMESERIESDATASET_H
#define TP2CPP_TIMESERIESDATASET_H

#include <vector>
using namespace std;

class TimeSeriesDataset {
private:
    bool znormalise;
    bool isTrain;
    vector<double> data;
    vector< vector<double> > series;
    vector<int> labels;
    int maxLength;
    int numberOfSamples;

    vector<double> zNormalize(const vector<double>& s);

public:
    TimeSeriesDataset(bool znormalise, bool isTrain);

    void addTimeSeries(const vector<double>& s, int label);
    void addTimeSeries(const vector<double>& s);

    const vector<double>& getTimeSeries(int index) const;
    int getLabel(int index) const;
    int getNumberOfSamples() const;

    double euclidian_distance(const vector<double>& a, const vector<double>& b) const;

    double dtw_distance(const vector<double>& a, const vector<double>& b) const;
};

#endif // TP2CPP_TIMESERIESDATASET_H
