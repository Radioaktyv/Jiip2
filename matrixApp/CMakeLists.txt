cmake_minimum_required(VERSION 3.20)
project(MatrixCalc)

set(CMAKE_CXX_STANDARD 14)

add_executable(MatrixCalc main.cpp MatrixLib/MatrixCalc.cpp MatrixLib/MatrixLib.h)
