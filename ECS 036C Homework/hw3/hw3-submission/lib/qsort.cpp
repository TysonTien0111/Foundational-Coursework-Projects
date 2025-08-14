#ifndef QSORT_CPP
#define QSORT_CPP

#include "qsort.hpp"
#include <cstdlib>
#include <ctime>

void initialize_srand()
{
    srand(time(0));
}

template <typename RandomAccessIter, typename Comparator>
RandomAccessIter partition(RandomAccessIter first, RandomAccessIter last, Comparator comparator)
{
    RandomAccessIter the_pivot = first + (rand() % std::distance(first, last));

    std::iter_swap(the_pivot, last - 1);

    RandomAccessIter the_low_side = first - 1;

    for (RandomAccessIter the_current_element = first; the_current_element < last - 1; ++the_current_element)
    {
        if (comparator(*the_current_element, *(last - 1)))
        {
            the_low_side++;

            std::iter_swap(the_low_side, the_current_element);
        }
    }

    std::iter_swap(the_low_side + 1, last - 1);

    return the_low_side + 1;
}

template <typename RandomAccessIter, typename Comparator>
void quick_sort(RandomAccessIter first, RandomAccessIter last, Comparator comparator)
{
    if (std::distance(first, last) <= 1) 
    {
        return;
    }

    RandomAccessIter the_pivot = ::partition(first, last, comparator);

    quick_sort(first, the_pivot, comparator);

    quick_sort(the_pivot + 1, last, comparator);
}

#endif
