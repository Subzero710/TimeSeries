#include "headers/SinWaweGenerator.h"
using namespace std;

SinWaweGenerator::SinWaweGenerator(int _seed, double _a, double _omega, double _phi)
    : TimeSeriesGenerator(_seed), a(_a), omega(_omega), phi(_phi) {
}

vector<double> SinWaweGenerator::generateTimeSeries(int taille) {
    vector<double> timeSerie;

    for (int i = 0; i < taille; i++) {
        timeSerie.push_back(a * sin(omega * i + phi));
    }

    return timeSerie;
}
