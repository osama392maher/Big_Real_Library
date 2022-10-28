cmake_minimum_required(VERSION 3.22)
project(Big_Real)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Big_Real
        BigDecimalIntClass.cpp
        BigDecimalIntClass.h
        main.cpp
       BigRealClass.cpp
       BigRealClass.h)
