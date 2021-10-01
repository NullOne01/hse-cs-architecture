# set minimum cmake version
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name and language
project(Task1 LANGUAGES C)
set(C_STANDARD C99)

set(BUILD_DIR "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/../bin")

# Source files list
set(SOURCE_FILES
        # Headers
        utilities/rnd.h
        data/bird.h
        data/fish.h
        data/animal.h
        data/container.h
        data/mammal.h

        # Sources
        utilities/rnd.c
        data/bird.c
        data/fish.c
        data/animal.c
        data/container.c
        data/mammal.c
        main.c)

add_executable(Task1 ${SOURCE_FILES})
