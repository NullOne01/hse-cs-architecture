#include "RingBuffer.h"

template<class T>
RingBuffer<T>::RingBuffer(int buf_size):buf_size_(buf_size) {
    buff_arr = new T[buf_size_];
}

template<class T>
T RingBuffer<T>::readValue() {
    T result = buff_arr[reader_index_];
    reader_index_ = (reader_index_ + 1) % buf_size_;
    count_--;

    return nullptr;
}

template<class T>
void RingBuffer<T>::writeValue(T value) {
    buff_arr[writer_index_] = value;
    writer_index_ = (writer_index_ + 1) % buf_size_;
    count_++;
}

template<class T>
int RingBuffer<T>::getCount() const {
    return count_;
}

template<class T>
bool RingBuffer<T>::isEmpty() const {
    return getCount() == 0;
}

template<class T>
bool RingBuffer<T>::isFull() const {
    return getCount() == buf_size_;
}

template<class T>
RingBuffer<T>::~RingBuffer() {
    delete[] buff_arr;
}
