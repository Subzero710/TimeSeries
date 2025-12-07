cmake_minimum_required(VERSION 4.0)
project(TP2cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(TP2cpp main.cpp
        TimeSeriesGenerator.cpp
        headers/TimeSeriesGenerator.h
        GaussianGenerator.cpp
        headers/GaussianGenerator.h
        StepGenerator.cpp
        headers/StepGenerator.h
        SinWaweGenerator.cpp
        TimeSeriesDataset.cpp
        headers/TimeSeriesDataset.h)
