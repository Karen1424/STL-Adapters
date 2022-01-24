template <typename T>
Queue<T>::Queue()
{
    m_max_size = 100;
    m_vec.reserve(m_max_size);
    m_front = 0;
    m_rear = -1;
    m_count = 0;
}

template <typename T>
Queue<T>& Queue<T>::operator=(Queue<T> && rhs) noexcept
{
    if (this == &rhs)  return *this;

    m_max_size = rhs.m_max_size;
    m_front = rhs.m_front;
    m_rear = rhs.m_rear;
    m_count = rhs.m_count;
    m_vec = std::move(rhs.m_vec);

    rhs.m_front = 0;
    rhs.m_max_size = 0;
    rhs.m_count = 0;
    rhs.rear = 0;
    rhs.vec.clear();
}

template <typename T>
Queue<T>::Queue(const Queue<T> & rhs)
{
    m_max_size = rhs.m_max_size;
    m_front = rhs.m_front;
    m_rear = rhs.m_rear;
    m_count = rhs.m_count;
    m_vec.reserve(m_max_size);

    for(int i = 0; i < m_max_size; ++i)
    {
        m_vec[i] = rhs.m_vec[i];
    }
}

template <typename T>
Queue<T>::Queue(Queue<T> && rhs) noexcept
{

    m_max_size = rhs.m_max_size;
    m_front = rhs.m_front;
    m_rear = rhs.m_rear;
    m_count = rhs.m_count;
    m_vec = std::move(rhs.m_vec);

    rhs.m_front = 0;
    rhs.m_max_size = 0;
    rhs.m_count = 0;
    rhs.rear = 0;
    rhs.vec.clear();
}

template <typename T>
Queue<T>::~Queue() 
{
    m_max_size = 0;
    m_front = 0;
    m_rear = 0;
    m_count = 0;
    m_vec.clear();
}

template <typename T>
int Queue<T>::dequeue()
{
    if (isEmpty())
    {
        std::cout << "Underflow\nProgram Terminated\n";
        std::exit(0);
    }
    int value = m_vec[m_front];
    std::cout << "Removing " << value << std::endl;
 
    m_front = (m_front + 1) % m_max_size;
    m_count--;
 
    return value;
}

template <typename T>
void Queue<T>::enqueue(T item)
{
    if (isFull())
    {
        std::cout << "Overflow\nProgram Terminated\n";
        exit(0);
    }
    std::cout << "Inserting " << item << std::endl;
 
    m_rear = (m_rear + 1) % m_max_size;
    m_vec[m_rear] = item;
    m_count++;
}

template <typename T>
int Queue<T>::peek()
{
    if (isEmpty())
    {
        std::cout << "Underflow\nProgram Terminated\n";
        std::exit(0);
    }
    return m_vec[m_front];
}
 
template <typename T>
int Queue<T>::size() 
{
    return m_count;
}
 
template <typename T>
bool Queue<T>::isEmpty() 
{
    return (size() == 0);
}
 
template <typename T>
bool Queue<T>::isFull() 
{
    return (size() == m_max_size);
}