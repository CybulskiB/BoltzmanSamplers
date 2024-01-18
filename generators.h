//
// Created by Cebulka on 18.01.2024.
//

#ifndef BOLTZMANSAMPLERS_V2_GENERATORS_H
#define BOLTZMANSAMPLERS_V2_GENERATORS_H

#include <ctime>
#include <cstdlib>
#include <cmath>
#include <random>
#include <iostream>

bool generateBernoulli(double x);
int geomGenerator(double lambda, int minLen, bool usingminSize);
int poissGenerator(double lambda, int minLen, bool usingminSize);
int logaGenerator(double lambda, int minLen, bool usingminSize);

#endif //BOLTZMANSAMPLERS_V2_GENERATORS_H
