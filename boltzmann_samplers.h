//
// Created by Cebulka on 13.01.2024.
//

#ifndef BOLTZMANSAMPLERS_V2_BOLTZMANN_SAMPLERS_H
#define BOLTZMANSAMPLERS_V2_BOLTZMANN_SAMPLERS_H

#include <vector>
#include <utility>

#include "combinatorial_train.h"
#include "generating_functions.h"
#include "generators.h"

Plank* plankBS(double x);
Wagon* wagonBs(double x);
Passenger* passengerBS(double x);
WagonWithPassengers* wagonWithPassengersBS(double x);
Train* trainBS(double x, int minLen);


#endif //BOLTZMANSAMPLERS_V2_BOLTZMANN_SAMPLERS_H
