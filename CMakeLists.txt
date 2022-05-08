cmake_minimum_required(VERSION 3.21)
project(SDA_Multidictionar_Ordonat)

set(CMAKE_CXX_STANDARD 14)

add_executable(SDA_Multidictionar_Ordonat App.cpp MDO.cpp MDO.h IteratorMDO.cpp
        IteratorMDO.h TestExtins.cpp TestExtins.h TestScurt.cpp TestScurt.h)
