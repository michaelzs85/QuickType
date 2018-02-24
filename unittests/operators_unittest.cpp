#include "quick_type.hpp"
#include <gtest/gtest.h>

namespace
{

TEST(Operator, ArithmeticOperationsOnQuickTypesShouldBeTheSameAsTheOperationsOnTheUnderlyingTypes) // NOLINT
{
    int a            = 3857;
    int b            = 10348;
    using UnaryPlusT = quick_type<int, struct UPT, UnaryPlus>;
    ASSERT_EQ(+a, +UnaryPlusT{a}.val);
    using UnaryMinusT = quick_type<int, struct UPT, UnaryMinus>;
    ASSERT_EQ(-b, -UnaryMinusT{b}.val);
    using AdditionT = quick_type<int, struct UPT, Addition>;
    ASSERT_EQ(a + b, (AdditionT{a} + AdditionT{b}).val);
    using SubtractionT = quick_type<int, struct UPT, Subtraction>;
    ASSERT_EQ(a - b, (SubtractionT{a} - SubtractionT{b}).val);
    using MultiplicationT = quick_type<int, struct UPT, Multiplication>;
    ASSERT_EQ(a * b, (MultiplicationT{a} * MultiplicationT{b}).val);
    using DivisionT = quick_type<int, struct UPT, Division>;
    ASSERT_EQ(a / b, (DivisionT{a} / DivisionT{b}).val);
    using ModuloT = quick_type<int, struct UPT, Modulo>;
    ASSERT_EQ(a % b, (ModuloT{a} % ModuloT{b}).val);
    using BitwiseNotT = quick_type<int, struct UPT, BitwiseNot>;
    ASSERT_EQ(~b, ~BitwiseNotT{b}.val);
    using BitwiseAndT = quick_type<int, struct UPT, BitwiseAnd>;
    ASSERT_EQ(a & b, (BitwiseAndT{a} & BitwiseAndT{b}).val);
    using BitwiseOrT = quick_type<int, struct UPT, BitwiseOr>;
    ASSERT_EQ(a | b, (BitwiseOrT{a} | BitwiseOrT{b}).val);
    using BitwiseXorT = quick_type<int, struct UPT, BitwiseXor>;
    ASSERT_EQ(a ^ b, (BitwiseXorT{a} ^ BitwiseXorT{b}).val);
    using BitwiseLeftShiftT = quick_type<int, struct UPT, BitwiseLeftShift>;
    ASSERT_EQ(a << 3, (BitwiseLeftShiftT{a} << BitwiseLeftShiftT{3}).val);
    using BitwiseRightShiftT = quick_type<int, struct UPT, BitwiseRightShift>;
    ASSERT_EQ(a >> 3, (BitwiseRightShiftT{a} >> BitwiseRightShiftT{3}).val);
}

TEST(Operator, LogicalOperatorsOnQuickTypesShouldResultInTheSameValuesAsLogicalOperatorsOnTheUnterlyingValues)
{
    bool a          = true;
    bool b          = false;
    using NegationT = quick_type<bool, struct Tag, Negation>;
    ASSERT_EQ(!b, !NegationT{b});
    using AndT = quick_type<bool, struct Tag, And>;
    ASSERT_EQ(a && b, AndT{a} && AndT{b});
    using InclusiveOrT = quick_type<bool, struct Tag, InclusiveOr>;
    ASSERT_EQ(a || b, InclusiveOrT{a} || InclusiveOrT{b});
}

TEST(Operator, ComparisonOperatorsOnQuickTypesShouldResultinTheSameValuesasLogicalOperatorsOnTheUnderlyingValues)
{
    int a          = 23850;
    int b          = 14592;
    using EqualToT = quick_type<int, struct FDH, EqualTo>;
    ASSERT_EQ(a == b, EqualToT{a} == EqualToT{b});
    ASSERT_EQ(a == a, EqualToT{a} == EqualToT{a});
    using NotEqualToT = quick_type<int, struct FDH, NotEqualTo>;
    ASSERT_EQ(a != b, NotEqualToT{a} != NotEqualToT{b});
    ASSERT_EQ(a != a, NotEqualToT{a} != NotEqualToT{a});
    using LessThanT = quick_type<int, struct FDH, LessThan>;
    ASSERT_EQ(a < b, LessThanT{a} < LessThanT{b});
    ASSERT_EQ(b < a, LessThanT{b} < LessThanT{a});
    using GreaterThanT = quick_type<int, struct FDH, GreaterThan>;
    ASSERT_EQ(a > b, GreaterThanT{a} > GreaterThanT{b});
    ASSERT_EQ(b > a, GreaterThanT{b} > GreaterThanT{a});
    using LessThanOrEqualToT = quick_type<int, struct FDH, LessThanOrEqualTo>;
    ASSERT_EQ(a <= b, LessThanOrEqualToT{a} <= LessThanOrEqualToT{b});
    ASSERT_EQ(b <= a, LessThanOrEqualToT{b} <= LessThanOrEqualToT{a});
    using GreaterThanOrEqualToT = quick_type<int, struct FDH, GreaterThanOrEqualTo>;
    ASSERT_EQ(a >= b, GreaterThanOrEqualToT{a} >= GreaterThanOrEqualToT{b});
    ASSERT_EQ(b >= a, GreaterThanOrEqualToT{b} >= GreaterThanOrEqualToT{a});
}

TEST(Operator, IncrementAndDecrementOperatorsOnQuickTypesShouldHaveTheSameEffectAsTheSameOpeatorsOnTheUnderlyingValues)
{
    using Type = quick_type<int, struct TypeTag, PreIncrement, PreDecrement, PostIncrement, PostDecrement>;
    int  v     = 35743943;
    Type k{v};
    ++v;
    ++k;
    ASSERT_EQ(v, k.val);
    --v;
    --k;
    ASSERT_EQ(v, k.val);
    v++;
    k++;
    ASSERT_EQ(v, k.val);
    v--;
    k--;
    ASSERT_EQ(v, k.val);
}

TEST(Operator, AssignmentsOnQuickTypesShouldHaveTheSameEffectAsAssignmentsOnTheUnderlyingValues)
{
    using Type =
        quick_type<int, struct TypeTag, AdditionAssignment, SubtractionAssignment, MultiplicationAssignment, DivisionAssignment, ModuloAssignment,
                   BitwiseAndAssignment, BitwiseOrAssignment, BitwiseXorAssignment, BitwiseLeftShiftAssignment, BitwiseRightShiftAssignment>;
    int k = 848;
    int l = 1234;

    Type a{k};
    Type b{l};

    k = l;
    a = b;
    ASSERT_EQ(k, a.val);

    k += l;
    a += b;
    ASSERT_EQ(k, a.val);

    k -= l;
    a -= b;
    ASSERT_EQ(k, a.val);

    k *= l;
    a *= b;
    ASSERT_EQ(k, a.val);

    k /= l;
    a /= b;
    ASSERT_EQ(k, a.val);

    k %= l;
    a %= b;
    ASSERT_EQ(k, a.val);

    k &= l;
    a &= b;
    ASSERT_EQ(k, a.val);

    k |= l;
    a |= b;
    ASSERT_EQ(k, a.val);

    k ^= l;
    a ^= b;
    ASSERT_EQ(k, a.val);

    k <<= l;
    a <<= b;
    ASSERT_EQ(k, a.val);

    k >>= l;
    a >>= b;
    ASSERT_EQ(k, a.val);
}

} // namespace

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
