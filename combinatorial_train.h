#ifndef BOLTZMANSAMPLERS_V2_COMBINATORIAL_TRAIN_H
#define BOLTZMANSAMPLERS_V2_COMBINATORIAL_TRAIN_H

#include <vector>
#include <utility>

struct Plank {
    int wheel;
    ~Plank();
};

struct Wagon{
    std::vector<Plank*> planks;
    ~Wagon();
};

struct Passenger{
    int head;
    int belly;
    ~Passenger();
};

struct WagonWithPassengers{
    Wagon *wagon;
    std::vector<Passenger*> Passengers;
    ~WagonWithPassengers();
};

struct Train{
    Wagon* locomotive;
    std::vector<WagonWithPassengers*> wagonswithpassengers;
    ~Train();
};
#endif //BOLTZMANSAMPLERS_V2_COMBINATORIAL_TRAIN_H
