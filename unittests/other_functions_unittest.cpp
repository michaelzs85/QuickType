#include "quick_type.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <ratio>
#include <set>
#include <unordered_set>

TEST(OtherFunctionsTest, hashTest)
{
    using H = quick_type<int, struct HashableTypeTag, Hashable>;

    std::unordered_set<H> the_set;
    the_set.insert(H{87});
    the_set.emplace(6);
    ASSERT_EQ(the_set.size(), 2);
    the_set.insert(H{87});
    ASSERT_EQ(the_set.size(), 2);
    the_set.emplace(45);
    ASSERT_EQ(the_set.count(H{45}), 1);
    ASSERT_EQ(the_set.count(H{0}), 0);

    std::set<H> ordered_set;
    std::pair<std::set<H>::iterator, bool> ret;
    ret = ordered_set.emplace(45);
    ASSERT_EQ(true, ret.second);
    ret = ordered_set.emplace(34);
    ASSERT_EQ(true, ret.second);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
