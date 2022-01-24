#include "queue.h"
#include "stack.h"
#include "deque.h"

int main() {

    Stack<int> d;
    Deque<int> s;
    Queue<int> q;
    s.insertfront(10);
    s.insertrear(20);
    d.push(10);
    d.push(20);
    std::cout << s.getRear();
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.dequeue();
    Queue<int> q1 = q;

    return 0;
}