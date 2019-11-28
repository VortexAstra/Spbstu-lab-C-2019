cmake_minimum_required(VERSION 3.15)
project(7)

set(CMAKE_CXX_STANDARD 14)

add_executable(7 main.cpp
        functions.cpp
        functions.hpp
        Circle.cpp
        Circle.hpp
        Shape.cpp
        Shape.hpp
        Square.cpp
        Square.hpp
        Triangle.cpp
        Triangle.hpp
        )