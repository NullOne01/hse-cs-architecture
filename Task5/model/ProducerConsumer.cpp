#include "ProducerConsumer.h"
#include "Constants.h"

void ProducerConsumer::run() {
    for (int i = 0; i < NUM_OF_STOLEN_ITEMS; i++) {
        int data;
        {
            std::unique_lock<std::mutex> unique_lock1(mutex1);

            //заснуть, если пусто
            buffer_in_->getNotEmptyCond().wait(unique_lock1, [this] { return !buffer_in_->isEmpty(); });
            data = buffer_in_->readValue();
        }

        buffer_in_->getNotFullCond().notify_all();

        printf("Petrov: received value = %d\n", data);

        {
            std::unique_lock<std::mutex> unique_lock2(mutex2);

            //заснуть, если заполненно
            buffer_out_->getNotFullCond().wait(unique_lock2, [this] { return !buffer_out_->isFull(); });
            //запись в общий буфер
            buffer_out_->writeValue(data);
        }

        buffer_out_->getNotEmptyCond().notify_all();

        printf("Petrov: threw value = %d\n\n", data);
        std::this_thread::sleep_for(std::chrono::milliseconds(2));
    }
}

std::thread ProducerConsumer::start() {
    std::thread new_thread(&ProducerConsumer::run, this);
    return new_thread;
}