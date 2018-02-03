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

#endif // SKILLS_H
