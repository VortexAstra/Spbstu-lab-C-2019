cmake_minimum_required(VERSION 3.15)
project(B3)

set(CMAKE_CXX_STANDARD 14)

add_executable(B3 main.cpp
        factorialContainer.cpp
        factorialContainer.hpp
        factorials.cpp
        factorials.hpp
        phonebookInterface.cpp
        phonebookInterface.hpp
        phonebook.cpp
        phonebook.hpp
        )
