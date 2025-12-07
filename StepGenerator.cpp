#include "headers/StepGenerator.h"
#include <cstdlib>
using namespace std;

StepGenerator::StepGenerator(int _seed)
    : TimeSeriesGenerator(_seed) {
}

vector<double> StepGenerator::generateTimeSeries(int taille) {
    vector<double> timeSerie;
    double bufferValue = 0.0;

    for (int i = 0; i < taille; i++) {
        if (rand() % 2 == 1) {
            bufferValue = rand() % 101;
        }
        timeSerie.push_back(bufferValue);
    }

    return timeSerie;
}
