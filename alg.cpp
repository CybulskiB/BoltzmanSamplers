#include "alg.h"

// PROBABILITIES:

bool generateBernoulli(double x){
    std::random_device rd;
    std::mt19937 engine(rd());
    std::bernoulli_distribution dist(x);

    return dist(engine);
}

unsigned int generateUniqueSeed(){
    return static_cast<unsigned int>(std::time(nullptr)) + lastSeed;
}


//GENERATING FUNCTIONS:

// + : Disjoint union: C(z) = A(z) + B(z),  BS C(x) = (Bern (A(x)/ A(x) +B(x) ) -> BS A(x) | BS B(x)
// * : Cartesian product: C(z) = A(z) * B(z),  BS C(x) = (BS A(x) ; BS B(x))

// ENDPOINT: x
double EndpointGF(double x){
    return x;
}
// PASSENGER: Head * Belly

// Belly -> Cycle(Endpoint)
double BellyGF(double x){
    return log(1 / (1 - EndpointGF(x)));
}
// Head -> Cycle(Endpoint)
double HeadGF(double x){
    return log(1 / (1 - EndpointGF(x)));
}

// PLANK: (Wheel + One) * Endpoint * Endpoint

// Wheel -> Cycle(Endpoint)
double WheelGF(double x){
    return log(1 / (1 - EndpointGF(x)));
}

// WAGON: Sequence(Plank)

double WagonLengthGF(double x){
    double Ax = EndpointGF(x) * EndpointGF(x) * (1 + WheelGF(x));
    return 1.0 / (1.0 - Ax);
}

// TRAIN: Wagon * Sequence( Wagon * Set(Passenger))

// Set(Passenger) -> Set(Cycle(Head) * Cycle(Belly))
double NumberOfPassengersGF(double x){
    double Ax = HeadGF(x) * BellyGF(x);
    return exp(Ax);
}

// Sequence(Wagon * Set(Passenger))
double TrainLengthGF(double x){
    double Wx = WagonLengthGF(x);
    double Px = NumberOfPassengersGF(x);
    double Ax = Wx * Px;
    return 1.0 / (1.0 - Ax);
}

// Boltzmann Sampler for cycles
// BS (C(x)) = (Loga(A(x)) => BS (Ax))
int generateCycle(double x, double Ax){
    RandomNumberGenerator rng(generateUniqueSeed());
    x = x/ Ax;
    if( x>= 1){
        std::cout << "x = " << x << " Ax = " << Ax << "unexpected behaviour in generateCycle ""\n";
    }
    double U = rng.next();
    double p_k = -x / log(1 - x);

    if ( p_k <= 0 || p_k >= 1){
        std::cout << "p_k = " << p_k << "unexpected behaviour in generateCycle ""\n";
    }

    double S = p_k;
    int k = 1;

    while(U > S){
        k++;
        p_k = p_k * x * k / (k -1);
        S += p_k;
    }
    return k;
}

// Boltzmann Sampler for sets
// BS C(x) =  (Pois(A(x)) => BS (Ax))
int generateSet(double x, double Ax){
    RandomNumberGenerator rng(generateUniqueSeed());
    x = x/ Ax;
    if( x>= 1){
        std::cout << "x = " << x << " Ax = " << Ax << "unexpected behaviour in generateSet ""\n";
    }

    double U = rng.next();
    double p_k = exp(-x);

    if ( p_k <= 0 || p_k >= 1){
        std::cout << "p_k = " << p_k << "unexpected behaviour in generateSet ""\n";
    }

    double S = p_k;
    int k = 0;

    while (U > S) {
        k++;
        p_k =  x* p_k/k;
        S += p_k;
    }
    //std::cout << U << " " << k << " " << S << " " << p_k << "\n";

    return k;

}
// Boltzmann Sampler for sequences
// BS C(x) =  (Geom(A(x)) => BS (Ax))
int generateSequence(double x,double Ax, int minLen){

    RandomNumberGenerator rng(generateUniqueSeed());
    if (x >= 1){
        std::cout << "x = " << x << " Ax = " << Ax << "unexpected behaviour in generateSet ""\n";
    }

    double U = rng.next();
    double p_k = 1-x;

    if ( p_k <= 0 || p_k >= 1){
        std::cout << "p_k = " << p_k << "unexpected behaviour in generateSequence ""\n";
    }

    double S = p_k;
    int k = 0;

    while (k < minLen){
        k++;
        p_k = x * p_k;
        S += p_k;
    }

    while (U > S){
        k++;
        p_k = x * p_k;
        S += p_k;
    }

    return k;
}