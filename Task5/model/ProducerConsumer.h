#ifndef TASK5_PRODUCERCONSUMER_H
#define TASK5_PRODUCERCONSUMER_H


#include <thread>
#include "../utilities/RingBuffer.h"

class ProducerConsumer {
public:
    explicit ProducerConsumer(RingBuffer *buffer_in, RingBuffer *buffer_out) : buffer_in_(buffer_in),
                                                                               buffer_out_(buffer_out) {}

    void run();

    std::thread start();

private:
    RingBuffer *buffer_in_;

    RingBuffer *buffer_out_;
};


#endif //TASK5_PRODUCERCONSUMER_H
