#include <iostream>
#include "combinatorial_train.h"
#include "train_saver.h"
#include "alg.h"

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
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    Train *t = new Train(0.9);
    printTrain(t);
    std::string filename_1 = "Trains/Train_one.json";
    std::string filename_2 = "Trains/Train_two.json";
    saveTrainToJson(t, filename_2);

    delete t;
    return 0;
}
