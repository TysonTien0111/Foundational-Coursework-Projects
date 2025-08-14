#include <gtest/gtest.h>
#include "qsort.cpp"

TEST(QuickSortTest, SortEmpty)
{
    std::vector<int> v;
    quick_sort(v.begin(), v.end(), std::less<int>());
    std::vector<int> expected;
    ASSERT_EQ(v, expected);
}

TEST(QuickSortTest, SortVectorWithOneElement)
{
    std::vector<int> v{1};
    quick_sort(v.begin(), v.end(), std::less<int>());
    std::vector<int> expected{1};
    ASSERT_EQ(v, expected);
}

TEST(QuickSortTest, Ascending)
{
    std::vector<int> v{2, 4, 3, 1, 5};
    quick_sort(v.begin(), v.end(), std::less<int>());
    std::vector<int> expected{1, 2, 3, 4, 5};
    ASSERT_EQ(v, expected);
}

TEST(QuickSortTest, Descending)
{
    std::vector<int> v{2, 4, 3, 1, 5};
    quick_sort(v.begin(), v.end(), std::greater<int>());
    std::vector<int> expected{5, 4, 3, 2, 1};
    ASSERT_EQ(v, expected);
}