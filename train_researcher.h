//
// Created by Cebulka on 16.01.2024.
//

#ifndef BOLTZMANSAMPLERS_V2_TRAIN_RESEARCHER_H
#define BOLTZMANSAMPLERS_V2_TRAIN_RESEARCHER_H

#include "combinatorial_train.h"
#include <fstream>
#include <vector>
#include <thread>

struct ElementCounts {
    int noPlanks = 0;
    int noWagons = 0;
    int noWheels = 0;
    int noPassengers = 0;
};
ElementCounts countElements(Train* t);
void elements_counter(double min_x, double max_x, double step, int repeat, const std::string& filepath, int train_min_len);



#endif //BOLTZMANSAMPLERS_V2_TRAIN_RESEARCHER_H
