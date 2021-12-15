#ifndef TASK5_CONSUMER_H
#define TASK5_CONSUMER_H


#include "../utilities/RingBuffer.h"

class Consumer {
public:
    explicit Consumer(RingBuffer *buffer) : buffer_(buffer) {}

    void run();

    std::thread start();

    int getSumCounter() const;

private:
    RingBuffer *buffer_;

    int sum_counter_ = 0;
};


#endif //TASK5_CONSUMER_H
