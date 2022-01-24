template <typename T>
Stack<T>::Stack()
{
    m_top = -1;
    m_max_size = 100;
    m_vec.reserve(m_max_size);
}

template <typename T>
Stack<T>::Stack(const Stack<T> & rhs)
{
    m_top = rhs.m_top;
    m_max_size = rhs.m_max_size;
    m_vec.reserve(m_max_size);

    for(int i = 0; i < m_max_size; ++i)
    {
        m_vec[i] = rhs.m_vec[i];
    }
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack<T> & rhs)
{
    if(this == &rhs) return *this;
    
    m_top = rhs.m_top;
    m_max_size = rhs.m_max_size;
    m_vec.reserve(m_max_size);

    for(int i = 0; i < m_max_size; ++i)
    {
        m_vec[i] = rhs.m_vec[i];
    }
    return *this;
}

template <typename T>
Stack<T>& Stack<T>::operator=(Stack<T> && rhs) noexcept
{
    if (this == &rhs)  return *this;

    m_top = rhs.m_top;
    m_max_size = rhs.m_max_size;
    m_vec = std::move(rhs.m_vec);

    rhs.top = 0;
    rhs.m_max_size = 0;
    rhs.vec.clear();
}
template <typename T>
Stack<T>::Stack(Stack && rhs) noexcept
{
    m_top = rhs.m_top;
    m_max_size = rhs.m_max_size;
    m_vec = std::move(rhs.m_vec);

    rhs.top = 0;
    rhs.m_max_size = 0;
    rhs.vec.clear();
}

template <typename T>
Stack<T>::~Stack()
{
    m_top = 0;
    m_max_size = 0;
    m_vec.clear();
}

template <typename T>
bool Stack<T>::push(const T value)
{
    if (m_top >= (m_max_size - 1)) 
    {
        std::cout << "Stack Overflow";
        std::exit(0);
    }
    else 
    {
        m_vec[++m_top] = value;
        std::cout << value << " pushed into stack\n";
        return true;
    }
}

template <typename T>
int Stack<T>::pop()
{
    return m_top < 0 ? 0 : m_vec[--m_top];
}

template <typename T>
bool Stack<T>::isEmpty() 
{
    return (m_top < 0);
}

template <typename T>
int Stack<T>::peek() 
{
    return m_top < 0 ? 0 : m_vec[m_top];
}
