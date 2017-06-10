
template<class T>
NiceQueue<T>::NiceQueue(size_t capacity) : inStack(capacity), outStack(capacity)
{
    m_capacity = capacity;
}

template<class T>
size_t NiceQueue<T>::size(void) const
{
    return inStack.size() + outStack.size();
}

template<class T>
T NiceQueue<T>::getMinimum(void) throw(out_of_range)
{
    if (inStack.size() == 0 && outStack.size() == 0)
        throw std::out_of_range("Queue is empty");

    T min;

    //find minimum of two stacks
    if (inStack.size() > 0 && outStack.size() > 0)
        min = inStack.getMinimum() < outStack.getMinimum() ?
              inStack.getMinimum() :
              outStack.getMinimum();
    else
    {
        if (inStack.size() > 0)
            min = inStack.getMinimum();
        else
            min = outStack.getMinimum();
    }

    return min;
}


template<class T>
T NiceQueue<T>::deq(void) throw(out_of_range)
{
    if (size() == 0)
        throw std::out_of_range("Queue is empty!");

    T value;

    if (outStack.size() == 0)
    {
        //перекладываем элементы из входного стека в выходной
        while (inStack.size() != 0)
        {
            value = inStack.pop();
            outStack.push(value);
        }
    }

    value = outStack.pop();

    return value;
}

template<class T>
void NiceQueue<T>::enq(T newelement) throw(out_of_range)
{
    if (size() == m_capacity)
        throw std::out_of_range("Queue is full");

    inStack.push(newelement);
}