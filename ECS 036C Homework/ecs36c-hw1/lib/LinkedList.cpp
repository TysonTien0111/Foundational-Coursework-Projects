#ifndef LINKED_LIST_CPP
#define LINKED_LIST_CPP

#include "LinkedList.hpp"

template <typename T>
LinkedList<T>::LinkedList() : _size(0),
                              _head(nullptr),
                              _tail(nullptr) 
{
}

template <typename T>
LinkedList<T>::LinkedList(LinkedList<T> &&other) : _size(other._size),
                                                   _head(other._head),
                                                   _tail(other._tail)
{
    other._size = 0;
    other._head = nullptr;
    other._tail = nullptr;
}

template <typename T>
LinkedList<T>::LinkedList(const std::vector<T> &items) : _size(0),
                                                        _head(nullptr), 
                                                        _tail(nullptr)
{
    for (const T& single_item : items) 
    {
        append(single_item);
    }
}

template <typename T>
size_t LinkedList<T>::size() const 
{
    return _size;
}

template <typename T>
LinkedListNode<T> *LinkedList<T>::head() const 
{
    if (_size == 0)
    {
        return nullptr;
    }

    return _head;
}

template <typename T>
LinkedListNode<T> *LinkedList<T>::tail() const 
{
    if (_size == 0)
    {
        return nullptr;
    }
    
    return _tail;
}

template <typename T>
LinkedListNode<T> *LinkedList<T>::find(T value) const 
{
    if (_size == 0)
    {
        return nullptr;
    }

    LinkedListNode<T> *current_node = _head;

    while (current_node != nullptr) 
    {
        if (current_node->value == value) 
        {
            return current_node;
        }
        current_node = current_node->_next;
    }

    return nullptr;
}

template <typename T>
LinkedListNode<T> *LinkedList<T>::prepend(T value) 
{
    LinkedListNode<T> *new_list_node = new LinkedListNode<T>(value);
    new_list_node->_next = _head;

    if (_size == 0) 
    {
        _tail = new_list_node;
    }

    _head = new_list_node;

    _size++;

    return new_list_node;
}

template <typename T>
LinkedListNode<T> *LinkedList<T>::append(T value) 
{
    LinkedListNode<T> *new_list_node = new LinkedListNode<T>(value);

    if (_size == 0) 
    {
        _head = _tail = new_list_node;
    } else 
    {
        _tail->_next = new_list_node;
        _tail = new_list_node;
    }

    _size++;

    return new_list_node;
}

template <typename T>
LinkedListNode<T> *LinkedList<T>::insertAfter(LinkedListNode<T> *node, T value) {
    if (node == nullptr) 
    {
        return prepend(value);
    }

    LinkedListNode<T> *new_list_node = new LinkedListNode<T>(value);
    new_list_node->_next = node->_next;
    node->_next = new_list_node;

    if (node == _tail) 
    {
        _tail = new_list_node;
    }

    _size++;

    return new_list_node;
}

template <typename T>
std::optional<T> LinkedList<T>::removeHead() 
{
    if (_size == 0) 
    {
        return std::nullopt;
    }

    LinkedListNode<T> *old_list_head = _head;
    T value = old_list_head->value;
    _head = _head->_next;

    delete old_list_head;

    if (_size == 1) 
    {
        _tail = nullptr;
    }

    _size--;

    return value;
}

template <typename T>
bool LinkedList<T>::remove(T value) 
{
    if (_size == 0) 
    {
        return false;
    }

    if (_head->value == value) 
    {
        removeHead();

        if (_size == 0) 
        {
            _tail = nullptr;
        }

        return true;
    }

    LinkedListNode<T> *current_list_node = _head;

    while (current_list_node->_next != nullptr) 
    {
        if (current_list_node->_next->value == value) 
        {
            LinkedListNode<T> *remove_list_node = current_list_node->_next;
            current_list_node->_next = remove_list_node->_next;

            delete remove_list_node;

            if (current_list_node->_next == nullptr) 
            {
                _tail = current_list_node;
            }

            _size--;

            return true;
        }
        
        current_list_node = current_list_node->_next;
    }

    return false;
}

template <typename T>
void LinkedList<T>::clear() 
{
    while (_head != nullptr) 
    {
        LinkedListNode<T> *remove_list_node = _head;
        _head = _head->_next;
        
        delete remove_list_node;
    }

    _size = 0;
    _tail = nullptr;
}

template <typename T>
LinkedList<T>::~LinkedList() 
{
    clear();
}

#endif
