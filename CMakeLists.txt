cmake_minimum_required(VERSION 3.27)
project(BoltzmanSamplers_v2)

set(CMAKE_CXX_STANDARD 17)

add_executable(BoltzmanSamplers_v2 main.cpp
        alg.cpp
        alg.h
        combinatorial_train.cpp
        combinatorial_train.h
        train_saver.cpp
        train_saver.h)
