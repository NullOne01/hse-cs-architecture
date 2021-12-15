#include "RingBuffer.h"


int RingBuffer::readValue() {
    int result = buff_arr[reader_index_];
    reader_index_ = (reader_index_ + 1) % buf_size_;
    count_--;

    return result;
}

void RingBuffer::writeValue(int value) {
    buff_arr[writer_index_] = value;
    writer_index_ = (writer_index_ + 1) % buf_size_;
    count_++;
}

int RingBuffer::getCount() const {
    return count_;
}

bool RingBuffer::isEmpty() const {
    return getCount() == 0;
}

bool RingBuffer::isFull() const {
    return getCount() == buf_size_;
}

RingBuffer::~RingBuffer() {
    delete[] buff_arr;
}

std::condition_variable &RingBuffer::getNotFullCond() {
    return not_full_cond_;
}

std::condition_variable &RingBuffer::getNotEmptyCond() {
    return not_empty_cond_;
}
