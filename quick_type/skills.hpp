#ifndef SKILLS_H
#define SKILLS_H

// clang-format off

// arithmetic

struct UnaryPlus {};
struct UnaryMinus {};
struct Addition {};
struct Subtraction {};
struct Multiplication {};
struct Division {};
struct Modulo {};
struct BitwiseNot {};
struct BitwiseAnd {};
struct BitwiseOr {};
struct BitwiseXor {};
struct BitwiseLeftShift {};
struct BitwiseRightShift {};

// assignment

struct AdditionAssignment {};
struct SubtractionAssignment {};
struct MultiplicationAssignment {};
struct DivisionAssignment {};
struct ModuloAssignment {};
struct BitwiseAndAssignment {};
struct BitwiseOrAssignment {};
struct BitwiseXorAssignment {};
struct BitwiseLeftShiftAssignment {};
struct BitwiseRightShiftAssignment {};

// increment/decrement

struct PreIncrement {};
struct PreDecrement {};
struct PostIncrement {};
struct PostDecrement {};

// logical

struct Negation {};
struct And {};
struct InclusiveOr {};

// comparison

struct EqualTo {};
struct NotEqualTo {};
struct LessThan {};
struct GreaterThan {};
struct LessThanOrEqualTo {};
struct GreaterThanOrEqualTo {};

struct Comparable : EqualTo, NotEqualTo, LessThan, GreaterThan, LessThanOrEqualTo, GreaterThanOrEqualTo {};

// other

struct Printable {};

// Functions with aritmetic types

struct AdditionWithArith {};
struct SubtractionWithArith {};
struct MultiplicationWithArith {};
struct DivisionWithArith {};
struct ModuloWithArith {};
struct BitwiseAndWithArith {};
struct BitwiseOrWithArith {};
struct BitwiseXorWithArith {};
struct BitwiseLeftShiftWithArith {};
struct BitwiseRightShiftWithArith {};
struct AdditionAssignmentWithArith {};
struct SubtractionAssignmentWithArith {};
struct MultiplicationAssignmentWithArith {};
struct DivisionAssignmentWithArith {};
struct ModuloAssignmentWithArith {};
struct BitwiseAndAssignmentWithArith {};
struct BitwiseOrAssignmentWithArith {};
struct BitwiseXorAssignmentWithArith {};
struct BitwiseLeftShiftAssignmentWithArith {};
struct BitwiseRightShiftAssignmentWithArith {};
struct AndWithArith {};
struct InclusiveOrWithArith {};
struct EqualToWithArith {};
struct NotEqualToWithArith {};
struct LessThanWithArith {};
struct GreaterThanWithArith {};
struct LessThanOrEqualToWithArith {};
struct GreaterThanOrEqualToWithArith {};

// hash

// std::hash requires operater== to work
struct Hashable : Comparable {};

// clang-format on

#endif // SKILLS_H
