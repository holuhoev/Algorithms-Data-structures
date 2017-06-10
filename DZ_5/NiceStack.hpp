
template<class T>
NiceStack<T>::NiceStack(size_t capacity)
{
    m_capacity = capacity;
    iHead = 0;
}

template<class T>
size_t NiceStack<T>::size() const
{
    return iHead;
}


template<class T>
void NiceStack<T>::push(T newelement) throw(out_of_range)
{
    if (iHead == m_capacity)
        throw std::out_of_range("Stack is full!");

    TypeElementStack elementStack;
    T min;

    if (iHead == 0)
        min = newelement;
    else
        min = newelement < getMinimum() ? newelement : getMinimum();

    elementStack = make_pair(newelement, min);

    ++iHead;
    storage.push_back(elementStack);
}

template<class T>
T NiceStack<T>::pop(void) throw(out_of_range)
{
    if (iHead == 0)
        throw std::out_of_range("Stack is empty!");

    --iHead;//reduce number of elements

    //get element value and pop it from vector
    TypeElementStack elem = storage.at(iHead);
    storage.pop_back();
    T value = elem.first;

    return value;
}

template<class T>
NiceStack<T>::~NiceStack(void)
{
    // nothing should be deleted
}
template<class T>
T NiceStack<T>::getMinimum(void) throw(out_of_range)
{
    if (iHead == 0)
        throw std::out_of_range("Stack is empty!");

    TypeElementStack elem = storage.at(iHead - 1);
    T value = elem.second;

    return value;
}