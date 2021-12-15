#include <thread>
#include "Consumer.h"
#include "Constants.h"

void Consumer::run() {
    for (int i = 0; i < NUM_OF_STOLEN_ITEMS; i++) {
        int data;
        {
            std::unique_lock<std::mutex> unique_lock(mutex2);

            //заснуть, если пусто
            buffer_->getNotEmptyCond().wait(unique_lock, [this] { return !buffer_->isEmpty(); });

            //запись в общий буфер
            data = buffer_->readValue();
            sum_counter_ += data;
        }

        buffer_->getNotFullCond().notify_all();

        printf("Ne4epor4uk: received value = %d\nTotal balance: %d\n\n", data, sum_counter_);
        std::this_thread::sleep_for(std::chrono::milliseconds(2));
    }
}

std::thread Consumer::start() {
    std::thread new_thread(&Consumer::run, this);
    return new_thread;
}

int Consumer::getSumCounter() const {
    return sum_counter_;
}
