#include <iostream>
#include "combinatorial_train.h"
#include "train_saver.h"
#include "alg.h"
#include "train_researcher.h"

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
void single_train_test(){
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    Train *t = new Train(0.9,2);
    printTrain(t);
    std::string filename_1 = "Trains/Train_one.json";
    std::string filename_2 = "Trains/Train_two.json";
    std::string filename_3 = "Trains/Train_three.json";
    saveTrainToJson(t, filename_3);

    delete t;
}


int main() {
    double min_x =0.01;
    double max_x = 1.0;
    double step = 0.01;
    int repeat = 1000;
    int train_min_len = 2;
    std::string filepath = "Results/Test_v1/X=";

    elements_counter(min_x, max_x, step, repeat, filepath, train_min_len);
    return 0;
}
