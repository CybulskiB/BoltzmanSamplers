#include <iostream>
#include "combinatorial_train.h"
#include "train_saver.h"

void printWagon(Wagon* w){
    for (Plank* p: w->planks){
        std::cout << p->wheel << " ";
    }
}

void printTrain(Train* t){
    std::cout << "Lokomotywa :" ;
    printWagon(t->locomotive);
    std::cout << "\n";

    for (WagonWithPassengers* w : t->wagons){
        std::cout << w->Passengers.size() << ";;";

        printWagon(w->wagon);
        std::cout << "\n";
    }
}

int main() {
    Train* t = new Train(0.1);
    printTrain(t);
    saveTrainToJson(t, "Trains/Train_one.json");

    delete t;
    return 0;
}
