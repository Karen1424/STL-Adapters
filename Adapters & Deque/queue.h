#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <vector>

template <typename T>
class Queue {
public:
    Queue();
    Queue(Queue<T> &&) noexcept;
    Queue(const Queue<T> &);     
    ~Queue();
    public:
    Queue& operator=(const Queue &);
    Queue& operator=(Queue &&) noexcept;
public:                   
    int dequeue();
    void enqueue(T);
    int peek();
    int size();
    bool isEmpty();
    bool isFull();
private:
    int m_max_size;
    int m_front;
    int m_rear;
    int m_count;
    std::vector<T> m_vec;
};

#include "queue.hpp"
#endif /* QUEUE_H */