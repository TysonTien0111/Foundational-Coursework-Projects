#ifndef TREE_MAP_CPP
#define TREE_MAP_CPP

#include "TreeMap.hpp"
#include "TreeSet.cpp"

template <typename TKey, typename TValue>
TreeMap<TKey, TValue>::TreeMap() : _tree()
{
}

template <typename TKey, typename TValue>
TreeMap<TKey, TValue>::TreeMap(const std::vector<std::pair<TKey, TValue>>& items) : _tree(items)
{
}

template <typename TKey, typename TValue>
size_t TreeMap<TKey, TValue>::size() const
{
    return _tree.size();
}

template <typename TKey, typename TValue>
void TreeMap<TKey, TValue>::insert(TKey key, TValue value)
{
    _tree.add(std::make_pair(key, value));
}

template <typename TKey, typename TValue>
std::optional<TValue> TreeMap<TKey, TValue>::get(TKey key) const
{
    std::vector<std::pair<TKey, TValue>> sorted_list = _tree.to_vector();

    for (const auto& key_value : sorted_list) {
        if (key_value.first == key) {
            return std::optional<TValue>(key_value.second);
        }
    }

    return std::nullopt;
}

template <typename TKey, typename TValue>
bool TreeMap<TKey, TValue>::contains(TKey key) const
{
    std::vector<std::pair<TKey, TValue>> sorted_list = _tree.to_vector();

    for (const auto& key_value : sorted_list) {
        if (key_value.first == key) {
            return true;
        }
    }

    return false;
}

template <typename TKey, typename TValue>
std::vector<std::pair<TKey, TValue>> TreeMap<TKey, TValue>::to_vector() const
{
    return _tree.to_vector();
}

template <typename TKey, typename TValue>
bool TreeMap<TKey, TValue>::is_empty() const
{
    return _tree.is_empty();
}

template<typename TKey, typename TValue>
void TreeMap<TKey, TValue>::clear()
{
    _tree.clear();
}

template <typename TKey, typename TValue>
TreeMap<TKey, TValue>::~TreeMap()
{
}

#endif
