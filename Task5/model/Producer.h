#ifndef TASK5_PRODUCER_H
#define TASK5_PRODUCER_H

#include <mutex>
#include <thread>
#include "../utilities/RingBuffer.h"

class Producer {
public:
    explicit Producer(RingBuffer *buffer) : buffer_(buffer) {}

    void run();

    std::thread start();

private:
    RingBuffer *buffer_;
};

#endif //TASK5_PRODUCER_H
