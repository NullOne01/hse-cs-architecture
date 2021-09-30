# set minimum cmake version
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name and language
project(Task1 LANGUAGES C)
set(C_STANDARD C99)

set(BUILD_DIR "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/../bin")

set(BINARY_DIR "${CMAKE_BINARY_DIR}")

# Source files list
set(SOURCE_FILES
        # Headers
        rnd.h
        bird.h
        fish.h
        animal.h
        container.h
        mammal.h

        # Sources
        bird.c
        fish.c
        animal.c
        container.c
        main.c
        mammal.c)

add_executable(Task1 ${SOURCE_FILES})
