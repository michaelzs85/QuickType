#ifndef OPERATORS_H
#define OPERATORS_H

#include "skills.h"
#include <type_traits>
#include <iostream>

// Arithmetic operators

template<class NamedType>
typename std::enable_if<std::is_base_of<UnaryPlus, NamedType>::value, NamedType>::type
operator+ (const NamedType& rhs)
{
  return NamedType{+rhs.val};
}

template<class NamedType>
typename std::enable_if<std::is_base_of<UnaryMinus, NamedType>::value, NamedType>::type
operator- (const NamedType& rhs)
{
  return NamedType{-rhs.val};
}

template<class NamedType>
typename std::enable_if<std::is_base_of<Addition, NamedType>::value, NamedType>::type
operator+ (const NamedType& lhs, const NamedType& rhs)
{
  return NamedType{lhs.val + rhs.val};
}

template<class NamedType>
typename std::enable_if<std::is_base_of<Subtraction, NamedType>::value, NamedType>::type
operator- (const NamedType& lhs, const NamedType& rhs)
{
  return NamedType{lhs.val - rhs.val};
}

template<class NamedType>
typename std::enable_if<std::is_base_of<Multiplication, NamedType>::value, NamedType>::type
operator* (const NamedType& lhs, const NamedType& rhs)
{
  return NamedType{lhs.val * rhs.val};
}

template<class NamedType>
typename std::enable_if<std::is_base_of<Division, NamedType>::value, NamedType>::type
operator/ (const NamedType& lhs, const NamedType& rhs)
{
  return NamedType{lhs.val / rhs.val};
}

template<class NamedType>
typename std::enable_if<std::is_base_of<Modulo, NamedType>::value, NamedType>::type
operator% (const NamedType& lhs, const NamedType& rhs)
{
  return NamedType{lhs.val % rhs.val};
}

template<class NamedType>
typename std::enable_if<std::is_base_of<BitwiseNot, NamedType>::value, NamedType>::type
operator~ (const NamedType& rhs)
{
  return NamedType{~rhs.val};
}

template<class NamedType>
typename std::enable_if<std::is_base_of<BitwiseAnd, NamedType>::value, NamedType>::type
operator& (const NamedType& lhs, const NamedType& rhs)
{
  return NamedType{lhs.val & rhs.val};
}

template<class NamedType>
typename std::enable_if<std::is_base_of<BitwiseOr, NamedType>::value, NamedType>::type
operator| (const NamedType& lhs, const NamedType& rhs)
{
  return NamedType{lhs.val | rhs.val};
}

template<class NamedType>
typename std::enable_if<std::is_base_of<BitwiseXor, NamedType>::value, NamedType>::type
operator^ (const NamedType& lhs, const NamedType& rhs)
{
  return NamedType{lhs.val ^ rhs.val};
}

template<class NamedType>
typename std::enable_if<std::is_base_of<BitwiseLeftShift, NamedType>::value, NamedType>::type
operator<< (const NamedType& lhs, const NamedType& rhs)
{
  return NamedType{lhs.val << rhs.val};
}

template<class NamedType>
typename std::enable_if<std::is_base_of<BitwiseRightShift, NamedType>::value, NamedType>::type
operator>> (const NamedType& lhs, const NamedType& rhs)
{
    return NamedType{lhs.val >> rhs.val};
}

// Assignment operators

template<class NamedType>
typename std::enable_if<std::is_base_of<AdditionAssignment, NamedType>::value, NamedType&>::type
operator+= (NamedType& lhs, const NamedType& rhs)
{
    lhs.val += rhs.val;
    return lhs;
}

template<class NamedType>
typename std::enable_if<std::is_base_of<SubtractionAssignment, NamedType>::value, NamedType&>::type
operator-= (NamedType& lhs, const NamedType& rhs)
{
    lhs.val -= rhs.val;
    return lhs;
}

template<class NamedType>
typename std::enable_if<std::is_base_of<MultiplicationAssignment, NamedType>::value, NamedType&>::type
operator*= (NamedType& lhs, const NamedType& rhs)
{
    lhs.val *= rhs.val;
    return lhs;
}

template<class NamedType>
typename std::enable_if<std::is_base_of<DivisionAssignment, NamedType>::value, NamedType&>::type
operator/= (NamedType& lhs, const NamedType& rhs)
{
    lhs.val /= rhs.val;
    return lhs;
}

template<class NamedType>
typename std::enable_if<std::is_base_of<ModuloAssignment, NamedType>::value, NamedType&>::type
operator%= (NamedType& lhs, const NamedType& rhs)
{
    lhs.val %= rhs.val;
    return lhs;
}

template<class NamedType>
typename std::enable_if<std::is_base_of<BitwiseAndAssignment, NamedType>::value, NamedType&>::type
operator&= (NamedType& lhs, const NamedType& rhs)
{
    lhs.val &= rhs.val;
    return lhs;
}

template<class NamedType>
typename std::enable_if<std::is_base_of<BitwiseOrAssignment, NamedType>::value, NamedType&>::type
operator|= (NamedType& lhs, const NamedType& rhs)
{
    lhs.val |= rhs.val;
    return lhs;
}

template<class NamedType>
typename std::enable_if<std::is_base_of<BitwiseXorAssignment, NamedType>::value, NamedType&>::type
operator^= (NamedType& lhs, const NamedType& rhs)
{
    lhs.val ^= rhs.val;
    return lhs;
}

template<class NamedType>
typename std::enable_if<std::is_base_of<BitwiseLeftShiftAssignment, NamedType>::value, NamedType&>::type
operator<<= (NamedType& lhs, const NamedType& rhs)
{
    lhs.val <<= rhs.val;
    return lhs;
}

template<class NamedType>
typename std::enable_if<std::is_base_of<BitwiseRightShiftAssignment, NamedType>::value, NamedType&>::type
operator>>= (NamedType& lhs, const NamedType& rhs)
{
    lhs.val >>= rhs.val;
    return lhs;
}

// Increment/Decrement operators

template<class NamedType>
typename std::enable_if<std::is_base_of<PreIncrement, NamedType>::value, NamedType&>::type
operator++ (NamedType& rhs)
{
    ++rhs.val;
    return rhs;
}

template<class NamedType>
typename std::enable_if<std::is_base_of<PreDecrement, NamedType>::value, NamedType&>::type
operator-- (NamedType& rhs)
{
    --rhs.val;
    return rhs;
}

template<class NamedType>
typename std::enable_if<std::is_base_of<PostIncrement, NamedType>::value, NamedType>::type
operator++ (NamedType& lhs, int)
{
    lhs.val++;
    return lhs;
}

template<class NamedType>
typename std::enable_if<std::is_base_of<PostDecrement, NamedType>::value, NamedType>::type
operator-- (NamedType& lhs, int)
{
    lhs.val--;
    return lhs;
}

// Logical operators

template<class NamedType>
typename std::enable_if<std::is_base_of<Negation, NamedType>::value, bool>::type
operator! (const NamedType& a)
{
    return !a.val;
}

template<class NamedType>
typename std::enable_if<std::is_base_of<And, NamedType>::value, bool>::type
operator&& (const NamedType& lhs, const NamedType& rhs)
{
    return (lhs.val && rhs.val);
}

template<class NamedType>
typename std::enable_if<std::is_base_of<InclusiveOr, NamedType>::value, bool>::type
operator|| (const NamedType& lhs, const NamedType& rhs)
{
    return (lhs.val || rhs.val);
}

// Comparison operators

template<class NamedType>
typename std::enable_if<std::is_base_of<EqualTo, NamedType>::value, bool>::type
operator== (const NamedType& lhs, const NamedType& rhs)
{
    return (lhs.val == rhs.val);
}

template<class NamedType>
typename std::enable_if<std::is_base_of<NotEqualTo, NamedType>::value, bool>::type
operator!= (const NamedType& lhs, const NamedType& rhs)
{
    return (lhs.val != rhs.val);
}

template<class NamedType>
typename std::enable_if<std::is_base_of<LessThan, NamedType>::value, bool>::type
operator< (const NamedType& lhs, const NamedType& rhs)
{
    return (lhs.val < rhs.val);
}

template<class NamedType>
typename std::enable_if<std::is_base_of<GreaterThan, NamedType>::value, bool>::type
operator> (const NamedType& lhs, const NamedType& rhs)
{
    return (lhs.val > rhs.val);
}

template<class NamedType>
typename std::enable_if<std::is_base_of<LessThanOrEqualTo, NamedType>::value, bool>::type
operator<= (const NamedType& lhs, const NamedType& rhs)
{
    return (lhs.val <= rhs.val);
}

template<class NamedType>
typename std::enable_if<std::is_base_of<GreaterThanOrEqualTo, NamedType>::value, bool>::type
operator>= (const NamedType& lhs, const NamedType& rhs)
{
    return (lhs.val >= rhs.val);
}

// Other operators

template<class NamedType>
typename std::enable_if<std::is_base_of<Printable, NamedType>::value, std::ostream&>::type
operator<< (std::ostream& os, const NamedType& a)
{
    return os << a.val;
}

#endif // OPERATORS_H
