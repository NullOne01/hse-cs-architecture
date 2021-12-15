#include "Producer.h"
#include "../utilities/Constants.h"

void Producer::run() {
    for (int i = 0; i < NUM_OF_STOLEN_ITEMS; i++) {
        //создать случайную стоимость товара
        int data = rand() % 11 + 1;

        {
            std::unique_lock<std::mutex> unique_lock(mutex1);

            // заснуть, если место перед грузовиком заполнено
            buffer_->getNotFullCond().wait(unique_lock, [this] { return !buffer_->isFull(); });

            // запись предмета в место перед грузовиком
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
