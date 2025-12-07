#include "headers/KNN.h"

#include <algorithm>
#include <map>
using namespace std;

KNN::KNN(int k, string similarity_measure)
    : k(k), similarity_measure(similarity_measure) {
}

int KNN::predict(const TimeSeriesDataset& trainData,
                 const vector<double>& query) const {
    int nTrain = trainData.getNumberOfSamples();
    vector< pair<double, int> > distances;

    for (int i = 0; i < nTrain; ++i) {
        const vector<double>& s = trainData.getTimeSeries(i);
        double d;

        if (similarity_measure == "euclidean_distance") {
            d = trainData.euclidian_distance(s, query);
        } else if (similarity_measure == "dtw") {
            d = trainData.dtw_distance(s, query);
        } else if (similarity_measure == "edr") {
            d = trainData.edr_distance(s, query);
        } else {
            d = trainData.euclidian_distance(s, query);
        }

        distances.push_back(make_pair(d, trainData.getLabel(i)));
    }

    sort(distances.begin(), distances.end(),
         [](const pair<double,int>& a, const pair<double,int>& b) {
             return a.first < b.first;
         });

    map<int,int> counts;
    int limit = k;
    if (limit > (int)distances.size()) {
        limit = (int)distances.size();
    }

    for (int i = 0; i < limit; ++i) {
        int lbl = distances[i].second;
        counts[lbl]++;
    }

    int bestLabel = -1;
    int bestCount = -1;
    for (map<int,int>::iterator it = counts.begin(); it != counts.end(); ++it) {
        if (it->second > bestCount) {
            bestCount = it->second;
            bestLabel = it->first;
        }
    }

    return bestLabel;
}

double KNN::evaluate(const TimeSeriesDataset& trainData,
                     const TimeSeriesDataset& testData,
                     const vector<int>& ground_truth) const {
    int nTest = testData.getNumberOfSamples();
    int correct = 0;

    int limit = nTest;
    if (limit > (int)ground_truth.size()) {
        limit = (int)ground_truth.size();
    }

    for (int i = 0; i < limit; ++i) {
        const vector<double>& query = testData.getTimeSeries(i);
        int pred = predict(trainData, query);
        if (pred == ground_truth[i]) {
            correct++;
        }
    }

    if (limit == 0) {
        return 0.0;
    }

    return (double)correct / (double)limit;
}
