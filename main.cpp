#include <iostream>
#include <vector>
using namespace std;

#include "headers/GaussianGenerator.h"
#include "headers/SinWaweGenerator.h"
#include "headers/StepGenerator.h"
#include "headers/TimeSeriesDataset.h"
#include "headers/KNN.h"

int main() {
    TimeSeriesDataset trainData(false, true);
    TimeSeriesDataset testData(false, false);

    int length = 11;

    GaussianGenerator gaussGen(0, 0.0, 1.0);
    SinWaweGenerator sinGen(1, 1.0, 0.2, 0.0);
    StepGenerator stepGen(2);

    trainData.addTimeSeries(gaussGen.generateTimeSeries(length), 0);
    trainData.addTimeSeries(gaussGen.generateTimeSeries(length), 0);

    trainData.addTimeSeries(sinGen.generateTimeSeries(length), 1);
    trainData.addTimeSeries(sinGen.generateTimeSeries(length), 1);

    trainData.addTimeSeries(stepGen.generateTimeSeries(length), 2);
    trainData.addTimeSeries(stepGen.generateTimeSeries(length), 2);

    vector<int> ground_truth;

    testData.addTimeSeries(gaussGen.generateTimeSeries(length));
    ground_truth.push_back(0);

    testData.addTimeSeries(sinGen.generateTimeSeries(length));
    ground_truth.push_back(1);

    testData.addTimeSeries(stepGen.generateTimeSeries(length));
    ground_truth.push_back(2);

    KNN knn1(1, "dtw");
    cout << "k=1, DTW: " << knn1.evaluate(trainData, testData, ground_truth) << endl;

    KNN knn2(1, "euclidean_distance");
    cout << "k=1, euclidean: " << knn2.evaluate(trainData, testData, ground_truth) << endl;

    KNN knn3(3, "euclidean_distance");
    cout << "k=3, euclidean: " << knn3.evaluate(trainData, testData, ground_truth) << endl;

    KNN knn4(1, "edr");
    cout << "k=1, EDR: " << knn4.evaluate(trainData, testData, ground_truth) << endl;

    return 0;
}
