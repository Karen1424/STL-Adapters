template <typename T>
Deque<T>::Deque()
{
    m_max_size = 100;
    m_front = -1;
    m_rear = 0;
    m_vec.reserve(m_max_size);
}

template <typename T>
Deque<T>::~Deque()
{
    m_rear = 0;
    m_max_size = 0;
    m_front = 0;
    m_vec.clear();
}

template <typename T>
bool Deque<T>::isFull()
{
    return ((m_front == 0 && m_rear == m_max_size - 1) || m_front == m_rear + 1);
}

template <typename T>
bool Deque<T>::isEmpty()
{
    return (m_front == -1);
}

template <typename T>
void Deque<T>::insertfront(T key)
{
    if (isFull())
    {
        std::cout << "Overflow\n" << std::endl;
        return;
    }
    if (m_front == -1)
    {
        m_front = 0;
        m_rear = 0;
    }
    else if (m_front == 0)
    {
        m_front = m_max_size - 1 ;
    }
    else
    {
        m_front = m_front - 1;
    }
    m_vec[m_front] = key;
}

template <typename T>
void Deque<T>::insertrear(T key)
{
    if (isFull())
    {
        std::cout << " Overflow\n " << std::endl;
        return;
    }
    if (m_front == -1)
    {
        m_front = 0;
        m_rear = 0;
    }
    else if (m_rear == m_max_size - 1)
    {
        m_rear = 0;
    }
    else
    {
        m_rear = m_rear + 1;
    }
    m_vec[m_rear] = key ;
}

template <typename T>
void Deque<T>::deletefront()
{
    if(isEmpty())
    {
        std::cout << "Queue Underflow\n" << std::endl;
        return ;
    }
    if(m_front == m_rear)
    {
        m_front = -1;
        m_rear = -1;
    }
    else
    {
        if(m_front == m_max_size - 1)
        {
            m_front = 0;
        }
        else
        {
            m_front = m_front + 1;
        }             
    }
}

template <typename T>
void Deque<T>::deleterear()
{
    if (isEmpty())
    {
        std::cout << " Underflow\n" << std::endl;
        return ;
    }
    if (m_front == m_rear)
    {
        m_front = -1;
        m_rear = -1;
    }
    else if (m_rear == 0)
    {
       m_rear = m_max_size - 1;
    }
    else
    {
        m_rear = m_rear - 1;
    }        
}

template <typename T>
int Deque<T>::getFront()
{
    if (isEmpty())
    {
        std::cout << " Underflow\n" << std::endl;
        return -1 ;
    }
    return m_vec[m_front];
}  

template <typename T>
int Deque<T>::getRear()
{
    if(isEmpty() || m_rear < 0)
    {
        std::cout << " Underflow\n" << std::endl;
        return -1 ;
    }
    return m_vec[m_rear];
}