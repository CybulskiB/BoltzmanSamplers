#ifndef BOLTZMANSAMPLERS_V2_GENERATING_FUNCTIONS_H
#define BOLTZMANSAMPLERS_V2_GENERATING_FUNCTIONS_H


#include <ctime>
#include <cstdlib>
#include <cmath>
#include <random>
#include <iostream>

double EndpointGF(double x);
double CycleGF(double x);
double SequenceGF(double x);
double SetGF(double x);
double PassengerGF(double x);
double PlankGF(double x);
double WagonGF(double x);
double SetPassengerGF(double x);
double WagonWithPassengersGF(double x);
double TrainGF(double x);

#endif //BOLTZMANSAMPLERS_V2_GENERATING_FUNCTIONS_H
