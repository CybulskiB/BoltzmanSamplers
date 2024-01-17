
#include "combinatorial_train.h"
#include "alg.h"

Plank::Plank(double x){
    if(generateBernoulli(WheelGF(x) / (WheelGF((x)) + EndpointGF(x)) )){
        this->wheel = generateCycle(x, WheelGF(x));
    }
    else{
        this->wheel = 0;
    }
}

Wagon::Wagon(double x) {
    int len = generateSequence(x,WagonLengthGF(x),2);

    for(int i = 0 ; i < len; i++){
        this->planks.push_back((new Plank(x)));
    }
}

Wagon:: ~Wagon(){

}

Passenger::Passenger(double x) {
    this->head = generateCycle(x, HeadGF(x));
    this->belly = generateCycle(x, BellyGF(x));
}

WagonWithPassengers::WagonWithPassengers(double x)  {
    this->wagon = new Wagon(x);

    int len = generateSet(x,NumberOfPassengersGF(x));

    for (int i = 0; i < len; i++){
        this->Passengers.push_back(new Passenger(x));
    }
}

WagonWithPassengers::~WagonWithPassengers(){
    delete wagon;

    for (int i = 0; i < this->Passengers.size() ; i++){
        delete this->Passengers[i];
    }
}

Train::Train(double x, int minLen) {
    this->locomotive = new Wagon(x);

    int len = generateSequence(x,TrainLengthGF(x),minLen);

    for (int i = 0; i < len ; i ++){
        this->wagons.push_back(new WagonWithPassengers(x));
    }

}

Train::~Train(){
    delete locomotive;

    for (int i = 0; i < this->wagons.size(); i++)
        delete this->wagons[i];
}