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
        triangle.h
        rectangle.h
        shape.h
        container.h

        # Sources
        triangle.c
        rectangle.c
        shape.c
        container.c
        main.c
        )

add_executable(Task1 ${SOURCE_FILES})
