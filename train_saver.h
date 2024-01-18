#ifndef TRAIN_SAVER_H
#define TRAIN_SAVER_H

#include <string>
#include "boltzmann_samplers.h"

std::string wagonToJson(Wagon* wagon);
std::string wagonWithPassengersToJson(WagonWithPassengers* wagonWithPassengers);
std::string trainToJson(Train* train);
void saveTrainToJson(Train* train, const std::string& filename);

#endif // TRAIN_SAVER_H