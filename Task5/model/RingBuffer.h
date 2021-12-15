#ifndef TASK5_RINGBUFFER_H
#define TASK5_RINGBUFFER_H

template<class T>
class RingBuffer {
public:
    explicit RingBuffer(int buf_size);

    T readValue();

    void writeValue(T value);

    bool isEmpty() const;

    bool isFull() const;

    int getCount() const;

    virtual ~RingBuffer();

private:
    T *buff_arr;

    int count_ = 0;
    int buf_size_ = 10;

    int reader_index_ = 0;
    int writer_index_ = 0;
};


#endif //TASK5_RINGBUFFER_H
