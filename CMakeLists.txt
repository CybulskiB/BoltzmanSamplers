cmake_minimum_required(VERSION 3.27)
project(BoltzmanSamplers_v2)

set(CMAKE_CXX_STANDARD 17)

add_executable(BoltzmanSamplers_v2 main.cpp
        boltzmann_samplers.cpp
        boltzmann_samplers.h
        train_saver.cpp
        train_saver.h
        train_researcher.cpp
        train_researcher.h
        generating_functions.cpp
        generating_functions.h
        generators.cpp
        generators.h
        combinatorial_train.cpp
        combinatorial_train.h
        tests.cpp
        tests.h)
