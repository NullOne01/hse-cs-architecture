#ifndef TASK5_RINGBUFFER_H
#define TASK5_RINGBUFFER_H

#include <condition_variable>

class RingBuffer {
public:
    explicit RingBuffer(int buf_size) : buf_size_(buf_size) {
        buff_arr = new int[buf_size_];
    }

    int readValue();

    void writeValue(int value);

    bool isEmpty() const;

    bool isFull() const;

    int getCount() const;

    virtual ~RingBuffer();

    std::condition_variable &getNotFullCond();

    std::condition_variable &getNotEmptyCond();

private:
    int *buff_arr;

    int count_ = 0;
    int buf_size_ = 10;

    int reader_index_ = 0;
    int writer_index_ = 0;

    std::condition_variable not_full_cond_;

    std::condition_variable not_empty_cond_;
};


#endif //TASK5_RINGBUFFER_H
