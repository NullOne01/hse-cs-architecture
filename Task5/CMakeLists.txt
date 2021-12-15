cmake_minimum_required(VERSION 3.20)
project(Task5)

set(CMAKE_CXX_STANDARD 14)

add_executable(Task5 main.cpp utilities/RingBuffer.cpp utilities/RingBuffer.h model/Producer.cpp model/Producer.h model/Consumer.cpp model/Consumer.h utilities/Constants.h model/ProducerConsumer.cpp model/ProducerConsumer.h)
