#ifndef SKILLS_H
#define SKILLS_H


// arithmetic

template<class NamedType>
struct UnaryPlus {};

template<class NamedType>
struct UnaryMinus {};

template<class NamedType>
struct Addition {};

template<class NamedType>
struct Subtraction {};

template<class NamedType>
struct Multiplication {};

template<class NamedType>
struct Division {};

template<class NamedType>
struct Modulo {};

template<class NamedType>
struct BitwiseNot {};

template<class NamedType>
struct BitwiseAnd {};

template<class NamedType>
struct BitwiseOr {};

template<class NamedType>
struct  BitwiseXor {};

template<class NamedType>
struct BitwiseLeftShift {};

template<class NamedType>
struct BitwiseRightShift {};

// assignment

template<class NamedType>
struct AdditionAssignment {};

template<class NamedType>
struct SubtractionAssignment {};

template<class NamedType>
struct MultiplicationAssignment {};

template<class NamedType>
struct DivisionAssignment {};

template<class NamedType>
struct ModuloAssignment {};

template<class NamedType>
struct BitwiseAndAssignment {};

template<class NamedType>
struct BitwiseOrAssignment {};

template<class NamedType>
struct BitwiseXorAssignment {};

template<class NamedType>
struct BitwiseLeftShiftAssignment {};

template<class NamedType>
struct BitwiseRightShiftAssignment {};

// increment/decrement

template<class NamedType>
struct PreIncrement {};

template<class NamedType>
struct PreDecrement {};

template<class NamedType>
struct PostIncrement {};

template<class NamedType>
struct PostDecrement {};

// logical

template<class NamedType>
struct Negation {};

template<class NamedType>
struct And {};

template<class NamedType>
struct InclusiveOr {};

// comparison

template<class NamedType>
struct EqualTo {};

template<class NamedType>
struct NotEqualTo {};

template<class NamedType>
struct LessThan {};

template<class NamedType>
struct GreaterThan {};

template<class NamedType>
struct LessThanOrEqualTo {};

template<class NamedType>
struct GreaterThanOrEqualTo {};

// other

template<class NamedType>
struct Printable {};

// Functions with aritmetic types

template<class NamedType>
struct AdditionWithArith {};

template<class NamedType>
struct SubtractionWithArith {};

template<class NamedType>
struct MultiplicationWithArith {};

template<class NamedType>
struct DivisionWithArith {};

template<class NamedType>
struct ModuloWithArith {};

template<class NamedType>
struct BitwiseAndWithArith {};

template<class NamedType>
struct BitwiseOrWithArith {};

template<class NamedType>
struct BitwiseXorWithArith {};

template<class NamedType>
struct BitwiseLeftShiftWithArith {};

template<class NamedType>
struct BitwiseRightShiftWithArith {};

template<class NamedType>
struct AdditionAssignmentWithArith {};

template<class NamedType>
struct SubtractionAssignmentWithArith {};

template<class NamedType>
struct MultiplicationAssignmentWithArith {};

template<class NamedType>
struct DivisionAssignmentWithArith {};

template<class NamedType>
struct ModuloAssignmentWithArith {};

template<class NamedType>
struct BitwiseAndAssignmentWithArith {};

template<class NamedType>
struct BitwiseOrAssignmentWithArith {};

template<class NamedType>
struct BitwiseXorAssignmentWithArith {};

template<class NamedType>
struct BitwiseLeftShiftAssignmentWithArith {};

template<class NamedType>
struct BitwiseRightShiftAssignmentWithArith {};

template<class NamedType>
struct AndWithArith {};

template<class NamedType>
struct InclusiveOrWithArith {};

template<class NamedType>
struct EqualToWithArith {};

template<class NamedType>
struct NotEqualToWithArith {};

template<class NamedType>
struct LessThanWithArith {};

template<class NamedType>
struct GreaterThanWithArith {};

template<class NamedType>
struct LessThanOrEqualToWithArith {};

template<class NamedType>
struct GreaterThanOrEqualToWithArith {};

// hash


#endif // SKILLS_H
