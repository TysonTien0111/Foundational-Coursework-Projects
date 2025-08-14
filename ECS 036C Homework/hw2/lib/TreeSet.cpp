#ifndef TREE_SET_CPP
#define TREE_SET_CPP

#include "TreeSet.hpp"

template <typename T>
TreeSet<T>::TreeSet() : _root(nullptr), _size(0) 
{
    _comparator = [](T left, T right) 
    {
        if (left < right)
        {
            return -1;
        }
        else if (left > right)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    };
}

template <typename T>
void TreeSet<T>::fix_violation(BinaryTreeNode<T> *the_current_node) 
{
    while ((the_current_node != nullptr) && (the_current_node->_parent != nullptr) && (the_current_node->_parent->_color == Red)) 
    {
        BinaryTreeNode<T> *the_uncle_node = nullptr;

        if ((the_current_node->_parent) == (the_current_node->_parent->_parent->_left)) 
        {
            the_uncle_node = the_current_node->_parent->_parent->_right;

            if ((the_uncle_node != nullptr) && (the_uncle_node->_color == Red)) {
                the_current_node->_parent->_color = Black;
                the_uncle_node->_color = Black;
                the_current_node->_parent->_parent->_color = Red;
                the_current_node = the_current_node->_parent->_parent;
            } else {
                if (the_current_node == (the_current_node->_parent->_right)) 
                {
                    the_current_node = the_current_node->_parent;

                    rotate_left(the_current_node);
                }

                the_current_node->_parent->_color = Black;
                the_current_node->_parent->_parent->_color = Red;

                rotate_right(the_current_node->_parent->_parent);
            }
        } 
        else 
        {
            the_uncle_node = the_current_node->_parent->_parent->_left;

            if ((the_uncle_node != nullptr) && (the_uncle_node->_color == Red)) {
                the_current_node->_parent->_color = Black;
                the_uncle_node->_color = Black;
                the_current_node->_parent->_parent->_color = Red;
                the_current_node = the_current_node->_parent->_parent;
            } 
            else 
            {
                if (the_current_node == (the_current_node->_parent->_left)) 
                {
                    the_current_node = the_current_node->_parent;

                    rotate_right(the_current_node);
                }

                the_current_node->_parent->_color = Black;
                the_current_node->_parent->_parent->_color = Red;

                rotate_left(the_current_node->_parent->_parent);
            }
        }
    }

    _root->_color = Black;
}


template <typename T>
void TreeSet<T>::rotate_left(BinaryTreeNode<T> *the_current_node) 
{
    BinaryTreeNode<T> *the_right_child = the_current_node->_right;
    the_current_node->_right = the_right_child->_left;

    if ((the_right_child->_left) != nullptr) 
    {
        the_right_child->_left->_parent = the_current_node;
    }

    the_right_child->_parent = the_current_node->_parent;

    if ((the_current_node->_parent) == nullptr) 
    {
        _root = the_right_child;
    } 
    else if (the_current_node == (the_current_node->_parent->_left)) 
    {
        the_current_node->_parent->_left = the_right_child;
    } 
    else 
    {
        the_current_node->_parent->_right = the_right_child;
    }

    the_right_child->_left = the_current_node;
    the_current_node->_parent = the_right_child;
}

template <typename T>
void TreeSet<T>::rotate_right(BinaryTreeNode<T> *the_current_node) {
    BinaryTreeNode<T> *the_left_child = the_current_node->_left;
    the_current_node->_left = the_left_child->_right;

    if ((the_left_child->_right) != nullptr) 
    {
        the_left_child->_right->_parent = the_current_node;
    }

    the_left_child->_parent = the_current_node->_parent;

    if ((the_current_node->_parent) == nullptr) 
    {
        _root = the_left_child;
    } 
    else if (the_current_node == (the_current_node->_parent->_left)) 
    {
        the_current_node->_parent->_left = the_left_child;
    } else {
        the_current_node->_parent->_right = the_left_child;
    }

    the_left_child->_right = the_current_node;
    the_current_node->_parent = the_left_child;
}

template <typename T>
TreeSet<T>::TreeSet(const std::vector<T> &items) : _root(nullptr), _size(0)
{
    _comparator = [](T left, T right) 
    {
        if (left < right)
        {
            return -1;
        }
        else if (left > right)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    };

    for (const T& value : items)
    {
        add(value);
    }
}

template <typename T>
TreeSet<T>::TreeSet(std::function<int(T, T)> comparator) : _root(nullptr), _size(0), _comparator(comparator)
{
}

template <typename T>
TreeSet<T>::TreeSet(const std::vector<T> &items, std::function<int(T, T)> comparator) : _root(nullptr), _size(0), _comparator(comparator)
{
    for (const T& value : items)
    {
        add(value);
    }
}

template <typename T>
size_t TreeSet<T>::size() const
{
    return _size;
}

template <typename T>
void TreeSet<T>::add(T value)
{
    BinaryTreeNode<T>* the_new_node = new BinaryTreeNode<T>(value, Red);
    BinaryTreeNode<T>* the_parent_node = nullptr;
    BinaryTreeNode<T>* the_current_node = _root;

    while (the_current_node != nullptr)
    {
        the_parent_node = the_current_node;

        if (_comparator(value, the_current_node->value) < 0)
        {
            the_current_node = the_current_node->_left;
        }
        else if (_comparator(value, the_current_node->value) > 0)
        {
            the_current_node = the_current_node->_right;
        }
        else
        {
            the_current_node->value = value;

            delete the_new_node;

            return;
        }
    }

    the_new_node->_parent = the_parent_node;

    if (the_parent_node == nullptr)
    {
        _root = the_new_node;
    } 
    else if (_comparator(value, the_parent_node->value) < 0)
    {
        the_parent_node->_left = the_new_node;
    }
    else
    {
        the_parent_node->_right = the_new_node;
    }

    fix_violation(the_new_node);
    
    _size++;
}

template <typename T>
bool TreeSet<T>::contains(T value) const
{
    BinaryTreeNode<T> *the_current_node = _root;

    while (the_current_node != nullptr)
    {
        if (value == (the_current_node->value))
        {
            return true;
        }
        else if (value < (the_current_node->value))
        {
            the_current_node = the_current_node->_left;
        }
        else
        {
            the_current_node = the_current_node->_right;
        }
    }

    return false;
}

template <typename T>
bool TreeSet<T>::is_empty() const
{
    if (_size == 0)
    {
        return true;
    }

    return false;
}

template <typename T>
std::optional<T> TreeSet<T>::min() const
{
    BinaryTreeNode<T>* the_current_node = _root;

    while ((the_current_node->_left) != nullptr)
    {
        the_current_node = the_current_node->_left;
    }

    if (the_current_node != nullptr)
    {
        return std::optional<T>(the_current_node->value);
    }

    return std::nullopt;
}

template <typename T>
std::optional<T> TreeSet<T>::max() const
{
    BinaryTreeNode<T>* the_current_node = _root;

    while ((the_current_node->_right) != nullptr)
    {
        the_current_node = the_current_node->_right;
    }

    if (the_current_node != nullptr)
    {
        return std::optional<T>(the_current_node->value);
    }

    return std::nullopt;
}

template <typename T>
std::vector<T> TreeSet<T>::to_vector() const
{
    std::vector<T> sorted_list;
    BinaryTreeNode<T>* the_current_node = _root;
    BinaryTreeNode<T>* the_previous_node = nullptr;

    while (the_current_node != nullptr)
    {
        if ((the_current_node->_left) == nullptr)
        {
            sorted_list.push_back(the_current_node->value);

            the_current_node = the_current_node->_right;
        }
        else
        {
            the_previous_node = the_current_node->_left;

            while ((the_previous_node->_right != nullptr) && (the_previous_node->_right != the_current_node))
            {
                the_previous_node = the_previous_node->_right;
            }

            if ((the_previous_node->_right) == nullptr)
            {
                the_previous_node->_right = the_current_node;
                the_current_node = the_current_node->_left;
            }
            else
            {
                the_previous_node->_right = nullptr;

                sorted_list.push_back(the_current_node->value);

                the_current_node = the_current_node->_right;
            }
        }
    }

    return sorted_list;
}

template <typename T>
std::optional<T> TreeSet<T>::get(T value) const
{
    BinaryTreeNode<T>* the_current_node = _root;

    while (the_current_node != nullptr)
    {
        if (value == (the_current_node->value))
        {
            return std::optional<T>(the_current_node->value);
        }
        else if (value < (the_current_node->value))
        {   
            the_current_node = the_current_node->_left;
        }
        else
        {
            the_current_node = the_current_node->_right;
        }
    } 

    return std::nullopt;
}

template <typename T>
TreeSet<T> TreeSet<T>::operator+(const TreeSet &other)
{
    TreeSet<T> new_set;

    for (const T& value : to_vector())
    {
        new_set.add(value);
    }

    for (const T& value : other.to_vector())
    {
        new_set.add(value);
    }

    return new_set;
}

template <typename T>
TreeSet<T>& TreeSet<T>::operator+=(const TreeSet &other) 
{
    for (const T& value : other.to_vector()) 
    {
        if (contains(value) == false)
        {
            add(value);
        }
    }

    return *this;
}

template <typename T>
TreeSet<T> TreeSet<T>::operator&(const TreeSet &other)
{
    TreeSet<T> new_set;

    for (const T& value : this->to_vector())
    {
        if (other.contains(value))
        {
            new_set.add(value);
        }
    }

    return new_set;
}

template <typename T>
bool TreeSet<T>::operator==(const TreeSet<T> &other) const
{
    if (_size != other._size)
    {
        return false;
    }

    for (const T& value : other.to_vector()) 
    {
        if (contains(value) == false)
        {
            return false;
        }
    }

    for (const T& value : to_vector())
    {
        if (other.contains(value) == false)
        {
            return false;
        }
    }

    return true;
}

template <typename T>
bool TreeSet<T>::operator!=(const TreeSet<T> &other) const
{
    if (*this == other)
    {
        return false;
    }

    return true;
}

template <typename T>
void TreeSet<T>::clear()
{
    BinaryTreeNode<T>* the_current_node = _root;

    while ((_root != nullptr) && (_size != 0))
    {
        while ((the_current_node->_left) != nullptr)
        {
            the_current_node = the_current_node->_left;
        }

        if ((the_current_node->_right) == nullptr)
        {
            if ((the_current_node->_parent) != nullptr)
            {
                if ((the_current_node->_parent->_left) == the_current_node)
                {
                    the_current_node->_parent->_left = nullptr;
                }
                else
                {
                    the_current_node->_parent->_right = nullptr;
                }
            }

            delete the_current_node;

            _size--;

            if (_size != 0)
            {
                the_current_node = _root;
            }
        }
        else
        {
            the_current_node = the_current_node->_right;
        }
    }

    _root = nullptr;
}

template <typename T>
TreeSet<T>::~TreeSet()
{
    clear();
}

#endif
