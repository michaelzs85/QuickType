#include "strong_type.h"
#include <gtest/gtest.h>

TEST(ArithmeticOperatorsTest,ThatOneTestCase)
{
    using T = NamedType<int, struct TheTag, AdditionWithArith,
                                            SubtractionWithArith,
                                            MultiplicationWithArith,
                                            DivisionWithArith,
                                            ModuloWithArith,
                                            BitwiseAndWithArith,
                                            BitwiseOrWithArith,
                                            BitwiseXorWithArith,
                                            BitwiseLeftShiftWithArith,
                                            BitwiseRightShiftWithArith,
                                            AdditionAssignmentWithArith,
                                            SubtractionAssignmentWithArith,
                                            MultiplicationAssignmentWithArith,
                                            DivisionAssignmentWithArith,
                                            ModuloAssignmentWithArith,
                                            BitwiseAndAssignmentWithArith,
                                            BitwiseOrAssignmentWithArith,
                                            BitwiseXorAssignmentWithArith,
                                            BitwiseLeftShiftAssignmentWithArith,
                                            BitwiseRightShiftAssignmentWithArith,
                                            AndWithArith,
                                            InclusiveOrWithArith,
                                            EqualToWithArith,
                                            NotEqualToWithArith,
                                            LessThanWithArith,
                                            GreaterThanWithArith,
                                            LessThanOrEqualToWithArith,
                                            GreaterThanOrEqualToWithArith>;
    int i = 2344;
    int j = 5692;
    T k{i};

    ASSERT_EQ(i+j, (k+j).val);
    ASSERT_EQ(i-j, (k-j).val);
    ASSERT_EQ(i*j, (k*j).val);
    ASSERT_EQ(i/j, (k/j).val);
    ASSERT_EQ(i%j, (k%j).val);
    ASSERT_EQ(i&j, (k&j).val);
    ASSERT_EQ(i|j, (k|j).val);
    ASSERT_EQ(i^j, (k^j).val);
    ASSERT_EQ(i<<4, (k<<4).val);
    ASSERT_EQ(i>>4, (k>>4).val);
    ASSERT_EQ(i+=j, (k+=j).val);
    ASSERT_EQ(i-=j, (k-=j).val);
    ASSERT_EQ(i*=j, (k*=j).val);
    ASSERT_EQ(i/=j, (k/=j).val);
    ASSERT_EQ(i%=j, (k%=j).val);
    ASSERT_EQ(i&=j, (k&=j).val);
    ASSERT_EQ(i|=j, (k|=j).val);
    ASSERT_EQ(i^=j, (k^=j).val);
    ASSERT_EQ(i<<=4, (k<<=4).val);
    ASSERT_EQ(i>>=4, (k>>=4).val);
    ASSERT_EQ(i&&j, (k&&j));
    ASSERT_EQ(i||j, (k||j));
    ASSERT_EQ(i==j, (k==j));
    ASSERT_EQ(i!=j, (k!=j));
    ASSERT_EQ(i<j, (k<j));
    ASSERT_EQ(i>j, (k>j));
    ASSERT_EQ(i<=j, (k<=j));
    ASSERT_EQ(i>=j, (k>=j));
}



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
