//
// Created by Cebulka on 13.01.2024.
//
#include <random>
#include "alg.h"


double WheelGF(double x){
    return x;
}
double OneGF(double x){
    return x;
}
double WheelLengthGF(double x){
    return x;
}
double WagonLengthGF(double x){
    return x;
}
double HeadGF(double x){
    return x;
}
double BellyGF(double x){
    return x;
}
double NumberOfPassengersGF(double x){
    return x;
}
double TrainLengthGF(double x){
    return x;
}

bool generateBernoulli(double x){
    std::random_device rd;
    std::mt19937 engine(rd());
    std::bernoulli_distribution dist(x);

    return dist(engine);
}

unsigned int generateUniqueSeed(){
    return static_cast<unsigned int>(std::time(nullptr)) + lastSeed++;
}

int generateCycle(double x){
    RandomNumberGenerator rng(generateUniqueSeed());

    double U = rng.next();
    double p_k = -x / log(1 - x);
    double S = p_k;
    int k = 1;

    while(U > S){
        k++;
        p_k = p_k * x * k / (k -1);
        S += p_k;
    }
    return k;
}

int generateSet(double x){
    RandomNumberGenerator rng(generateUniqueSeed());

    double U = rng.next();
    double p_k = exp(-x);
    double S = p_k;
    int k = 0;

    while (U > S) {
        k++;
        p_k =  x* p_k/k;
        S += p_k;
    }

    return k;

}

int generateSequence(double x, int minLen){

    RandomNumberGenerator rng(generateUniqueSeed());

    double U = rng.next();
    double p_k = 1-x;
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