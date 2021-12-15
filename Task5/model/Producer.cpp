#include "Producer.h"
#include "../utilities/Constants.h"

void Producer::run() {
    for (int i = 0; i < NUM_OF_STOLEN_ITEMS; i++) {
        //создать элемент для буфера
        int data = rand() % 11 + 1;

        {
            std::unique_lock<std::mutex> unique_lock(mutex1);

            //заснуть, если заполненно
            buffer_->getNotFullCond().wait(unique_lock, [this] { return !buffer_->isFull(); });

            //запись в общий буфер
            buffer_->writeValue(data);
        }

        buffer_->getNotEmptyCond().notify_all();


        printf("Ivanov: stole value = %d\n\n", data);
        std::this_thread::sleep_for(std::chrono::milliseconds(2));
    }
}

std::thread Producer::start() {
    std::thread new_thread(&Producer::run, this);
    return new_thread;
}
