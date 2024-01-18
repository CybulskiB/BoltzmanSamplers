#include "generating_functions.h"

//GENERATING FUNCTIONS:

// + : Disjoint union: C(z) = A(z) + B(z),  BS C(x) = (Bern (A(x)/ A(x) +B(x) ) -> BS A(x) | BS B(x)
// * : Cartesian product: C(z) = A(z) * B(z),  BS C(x) = (BS A(x) ; BS B(x))

// MATHS GENERATING FUNCTIONS:

// ENDPOINT: x
double EndpointGF(double x){
    double Ax = x;
    return Ax;
}
// Cycle : log(1 / (1 - x))
double CycleGF(double x){
    double Ax = std::log(1.0 / (1.0 - EndpointGF(x)));
    return Ax;
}
// Sequence: 1 / (1 - x)
double SequenceGF(double x){
    double Ax = 1.0 / (1.0 - EndpointGF(x));
    return Ax;
}
// Set: exp(x)
double SetGF(double x){
    double Ax = exp(x);
    return Ax;
}

// COMBINATORIAL TRAIN GENERATING FUNCTIONS

// Passenger: Cycle(Z) * Cycle(Z)
double PassengerGF(double x){
    double Ax = CycleGF(x) * CycleGF(x);
    return Ax;
}

// PLANK: Endpoint * Endpoint * (One + Wheel)
double PlankGF(double x){
    double Ax = EndpointGF(x) * EndpointGF(x) * ( 1.0 + CycleGF(x));
    return Ax;
}

// WAGON: |Sequence(Plank)| >= 1

double WagonGF(double x){
    // Plank
    double Plx = PlankGF(x);
    double SeqPlx = SequenceGF(Plx);
    double Ax = Plx * SeqPlx; // Greater or equal than 1
    return Ax;
}

// TRAIN: Wagon * Sequence( Wagon * Set(Passenger))

// Set(Passenger) -> Set(Cycle(Head) * Cycle(Belly))
double SetPassengerGF(double x){
    double Ax = SetGF(PassengerGF(x));
    return Ax;
}
// Sequence( Wagon * Set(Passenger))
double WagonWithPassengersGF(double x){
    double Wx = WagonGF(x);
    double Px = SetPassengerGF(x);
    double Ax = SequenceGF(Wx * Px);
    return Ax;
}
// Wagon * Sequence( Wagon * Set(Passenger))
double TrainGF(double x){
    double Wx = WagonGF(x);
    double WxPx = WagonWithPassengersGF(x);
    double Ax = Wx * WxPx;
    return Ax;
}
