#include <iostream>
#include "model/Producer.h"
#include "model/Consumer.h"
#include "model/ProducerConsumer.h"
#include "model/Constants.h"

int main() {
    auto *ring_buffer1 = new RingBuffer(NUM_OF_STOLEN_ITEMS);
    auto *ring_buffer2 = new RingBuffer(NUM_OF_STOLEN_ITEMS);

    Producer *producer = new Producer(ring_buffer1);
    auto thread1 = producer->start();

    ProducerConsumer *producerConsumer = new ProducerConsumer(ring_buffer1, ring_buffer2);
    auto thread2 = producerConsumer->start();

    Consumer *consumer = new Consumer(ring_buffer2);
    auto thread3 = consumer->start();

    thread1.join();
    thread2.join();
    thread3.join();

    std::cout << "Program is finished!" << std::endl;
    std::cout << "Total balance: " << consumer->getSumCounter() << std::endl;
    return 0;
}
