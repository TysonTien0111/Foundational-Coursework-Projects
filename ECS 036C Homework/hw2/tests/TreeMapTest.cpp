#include <gtest/gtest.h>
#include "TreeMap.cpp"

TEST(TreeMapTest, InsertAndSize) {
    TreeMap<int, std::string> map;

    map.insert(9, "Nine");
    map.insert(5, "Five");
    map.insert(7, "Seven");

    ASSERT_EQ(map.size(), 3);
}

TEST(TreeMapTest, Get) {
    TreeMap<int, std::string> map;

    map.insert(9, "Nine"); 
    map.insert(5, "Five");
    map.insert(7, "Seven");

    auto the_value = map.get(5);
    ASSERT_TRUE(the_value.has_value());
    ASSERT_EQ(the_value.value(), "Five");
}

TEST(TreeMapTest, Contains) {
    TreeMap<int, std::string> map;

    map.insert(9, "Nine");
    map.insert(5, "Five");
    map.insert(7, "Seven");

    ASSERT_TRUE(map.contains(5));
    ASSERT_FALSE(map.contains(8));
}

TEST(TreeMapTest, ToVector) {
    TreeMap<int, std::string> map;

    map.insert(9, "Nine");
    map.insert(5, "Five");
    map.insert(7, "Seven");

    auto vector = map.to_vector();

    ASSERT_EQ(vector.size(), 3);
}

TEST(TreeMapTest, IsEmpty) {
    TreeMap<int, std::string> map;

    ASSERT_TRUE(map.is_empty());

    map.insert(9, "Nine");

    ASSERT_FALSE(map.is_empty());
}

TEST(TreeMapTest, Clear) {
    TreeMap<int, std::string> map;

    map.insert(9, "Nine");
    map.insert(5, "Five");
    map.insert(7, "Seven");

    map.clear();

    ASSERT_TRUE(map.is_empty());
}