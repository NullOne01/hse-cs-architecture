cmake_minimum_required(VERSION 3.20)
project(Task2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Task2 main.cpp
        # HEADERS
        data/Container.h
        data/Animal.h
        data/Fish.h
        data/Bird.h
        data/Mammal.h
        utilities/Random.cpp

        # SOURCES
        data/Container.cpp
        data/Animal.cpp
        data/Fish.cpp
        data/Bird.cpp
        data/Mammal.cpp)
