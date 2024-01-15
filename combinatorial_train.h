//
// Created by Cebulka on 13.01.2024.
//

#ifndef BOLTZMANSAMPLERS_V2_COMBINATORIAL_TRAIN_H
#define BOLTZMANSAMPLERS_V2_COMBINATORIAL_TRAIN_H

#include <vector>
#include <utility>

struct Plank {
    //Długosc cyklu /rozmiar kola
    //wheel == 0 => brak kola
    int wheel;
    Plank(double x);
};

struct Wagon{
    std::vector<Plank*> planks;
    Wagon(double x);
    ~Wagon();
};

struct Passenger{
    int head; // Cyc(Z)
    int belly; // Cyc(Z)
    Passenger(double x);
};

struct WagonWithPassengers{
    Wagon *wagon;
    std::vector<Passenger*> Passengers;
    WagonWithPassengers(double x);
    ~WagonWithPassengers();
};

struct Train{
    Wagon* locomotive;
    std::vector<WagonWithPassengers*> wagons;
    Train(double x);
    ~Train();
};

#endif //BOLTZMANSAMPLERS_V2_COMBINATORIAL_TRAIN_H
