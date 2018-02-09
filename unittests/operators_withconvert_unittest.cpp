#include "quick_type.h"
#include <gtest/gtest.h>
#include <ratio>

TEST(ConvertOperatorTest, TheOneAndAllEncompassingTest)
{
    using T = NamedType<int, struct Tag, Addition, Subtraction, Multiplication, Division, Modulo, BitwiseAnd, BitwiseOr, BitwiseXor, BitwiseLeftShift,
                        BitwiseRightShift, AdditionAssignment, SubtractionAssignment, MultiplicationAssignment, DivisionAssignment, ModuloAssignment,
                        BitwiseAndAssignment, BitwiseOrAssignment, BitwiseXorAssignment, BitwiseLeftShiftAssignment, BitwiseRightShiftAssignment>;
    using M = MultipleOf2<T, int, std::kilo>;
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
    ASSERT_EQ(int(i << (j * std::kilo::num)), (o << p).val);
    ASSERT_EQ(int(i >> (j * std::kilo::num)), (o >> p).val);
    ASSERT_EQ(int(i += (j * std::kilo::num)), (o += p).val);
    ASSERT_EQ(int(i -= (j * std::kilo::num)), (o -= p).val);
    ASSERT_EQ(int(i *= (j * std::kilo::num)), (o *= p).val);
    ASSERT_EQ(int(i /= (j * std::kilo::num)), (o /= p).val);
    ASSERT_EQ(int(i %= (j * std::kilo::num)), (o %= p).val);
    ASSERT_EQ(int(i &= (j * std::kilo::num)), (o &= p).val);
    ASSERT_EQ(int(i |= (j * std::kilo::num)), (o |= p).val);
    ASSERT_EQ(int(i ^= (j * std::kilo::num)), (o ^= p).val);
    ASSERT_EQ(int(i <<= (j * std::kilo::num)), (o <<= p).val);
    ASSERT_EQ(int(i >>= (j * std::kilo::num)), (o >>= p).val);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
