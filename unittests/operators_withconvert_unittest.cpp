#include "quick_type.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include <ratio>

TEST(ConvertOperatorTest, TheOneAndAllEncompassingTest)
{
    using T = quick_type<int, struct Tag, Addition, Subtraction, Multiplication, Division, Modulo, BitwiseAnd, BitwiseOr, BitwiseXor,
                         AdditionAssignment, SubtractionAssignment, MultiplicationAssignment, DivisionAssignment, ModuloAssignment,
                         BitwiseAndAssignment, BitwiseOrAssignment, BitwiseXorAssignment, Printable>;
    using M = multiple_of2<T, int, std::kilo>;
    int i   = 345232;
    int j   = 124345;

    T o{i};
    M p{j};
    ASSERT_EQ(int(i + j * std::kilo::num), (o + p).val);
    ASSERT_EQ(int(i - j * std::kilo::num), (o - p).val);
    ASSERT_EQ(int(i * (j * std::kilo::num)), (o * p).val);
    ASSERT_EQ(int(i / (j * std::kilo::num)), (o / p).val);
    ASSERT_EQ(int(i % (j * std::kilo::num)), (o % p).val);
    ASSERT_EQ(int(i & (j * std::kilo::num)), (o & p).val);
    ASSERT_EQ(int(i | (j * std::kilo::num)), (o | p).val);
    ASSERT_EQ(int(i ^ (j * std::kilo::num)), (o ^ p).val);
    ASSERT_EQ(int(i += (j * std::kilo::num)), (o += p).val);
    ASSERT_EQ(int(i -= (j * std::kilo::num)), (o -= p).val);
    ASSERT_EQ(int(i *= (j * std::kilo::num)), (o *= p).val);
    ASSERT_EQ(int(i /= (j * std::kilo::num)), (o /= p).val);
    ASSERT_EQ(int(i %= (j * std::kilo::num)), (o %= p).val);
    ASSERT_EQ(int(i &= (j * std::kilo::num)), (o &= p).val);
    ASSERT_EQ(int(i |= (j * std::kilo::num)), (o |= p).val);
    ASSERT_EQ(int(i ^= (j * std::kilo::num)), (o ^= p).val);

    // The value of the result of left or right shift is undefined if the right
    // operrand is larger than the number of bits in the promoted left
    // operant.
    using T2 = quick_type<int, struct T2Tag, BitwiseLeftShift, BitwiseRightShift, BitwiseLeftShiftAssignment, BitwiseRightShiftAssignment, Printable>;
    using M2 = multiple_of2<T2, int, std::ratio<1, 1>>;
    int a    = 346482;
    int b    = 15;
    T2  g{a};
    M2  h(b);
    ASSERT_EQ(int(a << (b * 1)), (g << h).val);
    ASSERT_EQ(int(a >> (b * 1)), (g >> h).val);
    ASSERT_EQ(int(a <<= (b * 1)), (g <<= h).val);
    ASSERT_EQ(int(a >>= (b * 1)), (g >>= h).val);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
