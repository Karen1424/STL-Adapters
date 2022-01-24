#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>
#include <vector>

template <typename T>
class Deque {
public:
    Deque();
    ~Deque();
public:
    void insertfront(T);
    void insertrear(T);
    void deletefront();
    void deleterear();
    int  getFront();
    int  getRear();
    bool isFull();
    bool isEmpty();
private:
    int m_front;
    int m_rear;
    int m_max_size;
    std::vector<T> m_vec;
};

#include "deque.hpp"
#endif /* STACK_H */