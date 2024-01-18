#include "generators.h"

// PROBABILITIES:

bool generateBernoulli(double x){
    std::random_device rd;
    std::mt19937 engine(rd());
    std::bernoulli_distribution dist(x);
    return dist(engine);
}

// Generators for Boltzmann Samplers
// BS (C(x)) = (ProbabilityGen(A(x)) -> BS (Ax))

// Geometric generator
int geomGenerator(double lambda, int minLen, bool usingminSize){

    double U = static_cast<double>(rand()) / RAND_MAX;
    double p_k = 1.0-lambda;
    double S = 0.0;
    double k = 0.0;

    if ( p_k <= 0 || p_k >= 1){
        throw std::runtime_error("Error: Wrong value of probability in geomGenerator : p_k = " + std::to_string(p_k));
    }
    if (lambda<= 0){
        throw std::runtime_error("Error: Wrong value of lambda in geomGenerator : lambda = " + std::to_string(lambda));
    }

    if (usingminSize){
        while (k < minLen){
            S += p_k;
            p_k =  lambda* p_k;
            k++;
        }
    }

    while (U > S){
        S += p_k;
        p_k = lambda * p_k;
        k++;
    }

    return k;
}
// Poisson generator
int poissGenerator(double lambda, int minLen, bool usingminSize){

    double U = static_cast<double>(rand()) / RAND_MAX;
    double p_k = exp(-lambda);
    double S = 0.0;
    double k = 0.0;

    if ( p_k <= 0 || p_k >= 1){
        throw std::runtime_error("Error: Wrong value of probability in poissGenerator : p_k = " + std::to_string(p_k));
    }
    if (lambda <= 0){
        throw std::runtime_error("Error: Wrong value of lambda in geomGenerator : lambda = " + std::to_string(lambda));
    }

    if (usingminSize){
        while (k < minLen){
            S += p_k;
            p_k =  lambda* p_k /(k+1);
            k++;
        }
    }
    while (U > S){
        S += p_k;
        p_k = lambda * p_k / (k+1);
        k++;
    }
    return k;
}
// Logarithmic generator
int logaGenerator(double lambda, int minLen, bool usingminSize){

    double U = static_cast<double>(rand()) / RAND_MAX;
    double p_k = -1.0/ (1.0/ log(1.0 - lambda)); //Error in Book
    double S = 0.0;
    double k = 1.0;

    if ( p_k <= 0 || p_k >= 1){
        throw std::runtime_error("Error: Wrong value of probability in logaGenerator : p_k = " + std::to_string(p_k));
    }
    if (lambda <= 0){
        throw std::runtime_error("Error: Wrong value of lambda in geomGenerator : lambda = " + std::to_string(lambda));
    }

    if (usingminSize){
        while (k < minLen){
            S += p_k;
            p_k =  lambda* p_k * k/(k-1); //Error in Book
            k++;
        }
    }
    while (U > S){
        S += p_k;
        p_k = lambda * p_k * k/ (k-1);
        k++;
    }
    return k;
}
