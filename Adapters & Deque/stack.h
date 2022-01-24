#ifndef _STACK_H_
#define _STACK_H_

#include <iostream>
#include <vector>

template <typename T>
class Stack {
public:
    Stack();
    Stack(const Stack &);
    Stack(Stack &&) noexcept;
    ~Stack();
public:
    Stack& operator=(const Stack &);
    Stack& operator=(Stack &&) noexcept;
public:
    bool push(const T);
    int pop();
    int peek();
    bool isEmpty();    
private:
    int m_top;
    int m_max_size;
    std::vector<T> m_vec;
};

#include "stack.hpp"
#endif // _STACK_H_ 