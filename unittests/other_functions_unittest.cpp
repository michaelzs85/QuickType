#include "quick_type.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include <ratio>
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
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
