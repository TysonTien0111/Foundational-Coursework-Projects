#ifndef STACK_CPP
#define STACK_CPP

#include "Stack.hpp"

template <typename T>
Stack<T>::Stack()
{
}

template <typename T>
Stack<T>::Stack(const std::vector<T> &items)
{
    for (const T& single_item : items)
    {
        _llist.prepend(single_item);
    }
}

template <typename T>
size_t Stack<T>::size() const
{
    return _llist.size();
}

template <typename T>
std::optional<T> Stack<T>::top() const
{
    if (_llist.size() == 0) 
    {
        return std::nullopt;
    }

    return _llist.head()->value;
}

template <typename T>
void Stack<T>::push(T value)
{
    _llist.prepend(value);
}

template <typename T>
std::optional<T> Stack<T>::pop()
{
    return _llist.removeHead();
}

#endif