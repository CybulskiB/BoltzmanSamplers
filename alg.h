#ifndef BOLTZMANSAMPLERS_V2_ALG_H
#define BOLTZMANSAMPLERS_V2_ALG_H

#include <ctime>
#include <cstdlib>
#include <cmath>
#include <random>
#include <iostream>

#include "combinatorial_train.h"

class RandomNumberGenerator {
public:
    RandomNumberGenerator(unsigned int seed) : seed(seed) {
    }

    double next() {
        return static_cast<double>(rand()) / RAND_MAX;
    }

private:
    unsigned int seed;
};

static unsigned int lastSeed = 0;

unsigned int generateUniqueSeed();


double WheelGF(double x);
double EndpointGF(double x);
double WheelLengthGF(double x);
double WagonLengthGF(double x);
double HeadGF(double x);
double BellyGF(double x);
double NumberOfPassengersGF(double x);
double TrainLengthGF(double x);


int generateSequence(double x,double Ax, int minLen);
int generateSet(double x, double Ax);
int generateCycle(double x, double Ax);


bool generateBernoulli(double x);

#endif //BOLTZMANSAMPLERS_V2_ALG_H
