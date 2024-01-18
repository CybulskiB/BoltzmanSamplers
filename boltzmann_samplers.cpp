#include "boltzmann_samplers.h"


// BS (C(x)) = (ProbabilityGen(A(x)) -> BS (Ax))

// Cycle -> logaGen
// Set -> poissGen
// Sequence -> geomGen

Plank* plankBS(double x){
    auto* plank = new Plank();
    if(generateBernoulli(CycleGF(x) / (CycleGF((x)) + EndpointGF(x)) )){
        plank->wheel = logaGenerator(CycleGF(x),1, false);
    }
    else{
        plank->wheel = 0;
    }
    return plank;
}

Wagon* wagonBs(double x){
    int len = 0;
    auto* wagon = new Wagon();
    while (len < 1){
        len = geomGenerator(WagonGF(x),1, false);
    }
    //std::cout << "Wagon length " << len << "\n";
    for(int i = 0 ; i < len; i++){
        wagon->planks.push_back((plankBS(x)));
    }
    return wagon;
}


Passenger* passengerBS(double x){
    auto* passenger = new Passenger();
    passenger->head = logaGenerator(CycleGF(x), 1, false);
    passenger->belly = logaGenerator(CycleGF(x), 1, false);
    return passenger;
}

WagonWithPassengers* wagonWithPassengersBS(double x){
    auto* wagonWithPassengers = new WagonWithPassengers();
    wagonWithPassengers->wagon = wagonBs(x);

    int len = poissGenerator(WagonWithPassengersGF(x),1,false);
    //std::cout << "Passengers number " << len << "\n";
    for (int i = 0; i < len; i++){
        wagonWithPassengers->Passengers.push_back(passengerBS(x));
      //  std::cout << "Passenger " << i << "\n";
    }
    return wagonWithPassengers;
}



Train* trainBS(double x, int minLen){
    auto* train = new Train();
    train->locomotive = wagonBs(x);
    //std::cout<< "Locomotive done\n";
    int len = geomGenerator(TrainGF(x),minLen, true);
    //std::cout<< "Train length " << len  <<"\n";
    for (int i = 0; i < len ; i ++){
        train->wagonswithpassengers.push_back(wagonWithPassengersBS(x));
      //  std::cout<< "Wagon " << i  <<"\n";
    }
    return train;
}
