#include "combinatorial_train.h"

Plank:: ~Plank(){};
Passenger:: ~Passenger(){};

Wagon:: ~Wagon(){
    for (int i = 0; i < this->planks.size(); i++){
        delete this->planks[i];
    }
}
WagonWithPassengers::~WagonWithPassengers(){
    delete wagon;

    for (int i = 0; i < this->Passengers.size() ; i++){
        delete this->Passengers[i];
    }
}

Train::~Train(){
    delete locomotive;

    for (int i = 0; i < this->wagonswithpassengers.size(); i++){
        delete this->wagonswithpassengers[i];
    }
}