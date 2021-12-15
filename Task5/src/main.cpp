#include <iostream>
#include "model/Producer.h"
#include "model/Consumer.h"
#include "model/ProducerConsumer.h"
#include "utilities/Constants.h"

int main() {
    srand(time(nullptr));

    clock_t start, end;
    double cpu_time_used;
    start = clock();

    // Буфер для места перед грузовиком. Сюда Иванов несёт вещи, а потом Петров их заносит в грузовик
    auto *ring_buffer1 = new RingBuffer(5);
    // Буфер для грузовика. Сюда Петров поднимает вещи, а Нечепорчук подсчитывает их стоимость
    auto *ring_buffer2 = new RingBuffer(5);

    // Иванов
    Producer *producer = new Producer(ring_buffer1);
    auto thread1 = producer->start();

    // Петров
    ProducerConsumer *producerConsumer = new ProducerConsumer(ring_buffer1, ring_buffer2);
    auto thread2 = producerConsumer->start();

    // Нечепорчук
    Consumer *consumer = new Consumer(ring_buffer2);
    auto thread3 = consumer->start();

    thread1.join();
    thread2.join();
    thread3.join();

    std::cout << "Program is finished!" << std::endl;
    std::cout << "Total balance: " << consumer->getSumCounter() << std::endl;

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time elapsed (seconds): %f\n", cpu_time_used);

    return 0;
}
