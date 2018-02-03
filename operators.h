#ifndef OPERATORS_H
#define OPERATORS_H

#include "skills.h"
#include "namedtype.h"

// Arithmetic operators

template<class NamedType>
typename std::enable_if<std::is_base_of<UnaryPlus<NamedType>, NamedType>::value, NamedType>::type
operator+ (const NamedType& rhs)
{
  return NamedType{+rhs.val};
}

template<class NamedType>
typename std::enable_if<std::is_base_of<UnaryMinus<NamedType>, NamedType>::value, NamedType>::type
operator+ (const NamedType& rhs)
{
  return NamedType{-rhs.val};
}

template<class NamedType>
typename std::enable_if<std::is_base_of<Addition<NamedType>, NamedType>::value, NamedType>::type
operator+ (const NamedType& lhs, const NamedType& rhs)
{
  return NamedType{lhs.val + rhs.val};
}

template<class NamedType>
typename std::enable_if<std::is_base_of<Subtraction<NamedType>, NamedType>::value, NamedType>::type
operator- (const NamedType& lhs, const NamedType& rhs)
{
  return NamedType{lhs.val - rhs.val};
}

template<class NamedType>
typename std::enable_if<std::is_base_of<Multiplication<NamedType>, NamedType>::value, NamedType>::type
operator* (const NamedType& lhs, const NamedType& rhs)
{
  return NamedType{lhs.val * rhs.val};
}

template<class NamedType>
typename std::enable_if<std::is_base_of<Division<NamedType>, NamedType>::value, NamedType>::type
operator/ (const NamedType& lhs, const NamedType& rhs)
{
  return NamedType{lhs.val / rhs.val};
}

template<class NamedType>
typename std::enable_if<std::is_base_of<Modulo<NamedType>, NamedType>::value, NamedType>::type
operator% (const NamedType& lhs, const NamedType& rhs)
{
  return NamedType{lhs.val % rhs.val};
}

template<class NamedType>
typename std::enable_if<std::is_base_of<BitwiseNot<NamedType>, NamedType>::value, NamedType>::type
operator~ (const NamedType& rhs)
{
  return NamedType{~rhs.val};
}

template<class NamedType>
typename std::enable_if<std::is_base_of<BitwiseAnd<NamedType>, NamedType>::value, NamedType>::type
operator& (const NamedType& lhs, const NamedType& rhs)
{
  return NamedType{lhs.val & rhs.val};
}

template<class NamedType>
typename std::enable_if<std::is_base_of<BitwiseOr<NamedType>, NamedType>::value, NamedType>::type
operator| (const NamedType& lhs, const NamedType& rhs)
{
  return NamedType{lhs.val | rhs.val};
}

template<class NamedType>
typename std::enable_if<std::is_base_of<BitwiseXor<NamedType>, NamedType>::value, NamedType>::type
operator^ (const NamedType& lhs, const NamedType& rhs)
{
  return NamedType{lhs.val ^ rhs.val};
}

template<class NamedType>
typename std::enable_if<std::is_base_of<BitwiseLeftShift<NamedType>, NamedType>::value, NamedType>::type
operator<< (const NamedType& lhs, const NamedType& rhs)
{
  return NamedType{lhs.val << rhs.val};
}

template<class NamedType>
typename std::enable_if<std::is_base_of<BitwiseRightShift<NamedType>, NamedType>::value, NamedType>::type
operator>> (const NamedType& lhs, const NamedType& rhs)
{
    return NamedType{lhs.val >> rhs.val};
}

// Assignment operators

template<class NamedType>
typename std::enable_if<std::is_base_of<AdditionAssignment<NamedType>, NamedType>::value, NamedType&>::type
operator+= (NamedType& lhs, const NamedType& rhs)
{
    lhs.val += rhs.val;
    return lhs;
}

template<class NamedType>
typename std::enable_if<std::is_base_of<SubtractionAssignment<NamedType>, NamedType>::value, NamedType&>::type
operator-= (NamedType& lhs, const NamedType& rhs)
{
    lhs.val -= rhs.val;
    return lhs;
}

template<class NamedType>
typename std::enable_if<std::is_base_of<MultiplicationAssignment<NamedType>, NamedType>::value, NamedType&>::type
operator*= (NamedType& lhs, const NamedType& rhs)
{
    lhs.val *= rhs.val;
    return lhs;
}

template<class NamedType>
typename std::enable_if<std::is_base_of<DivisionAssignment<NamedType>, NamedType>::value, NamedType&>::type
operator/= (NamedType& lhs, const NamedType& rhs)
{
    lhs.val /= rhs.val;
    return lhs;
}

template<class NamedType>
typename std::enable_if<std::is_base_of<ModuloAssignment<NamedType>, NamedType>::value, NamedType&>::type
operator%= (NamedType& lhs, const NamedType& rhs)
{
    lhs.val %= rhs.val;
    return lhs;
}

template<class NamedType>
typename std::enable_if<std::is_base_of<BitwiseAndAssignment<NamedType>, NamedType>::value, NamedType&>::type
operator+= (NamedType& lhs, const NamedType& rhs)
{
    lhs.val &= rhs.val;
    return lhs;
}

template<class NamedType>
typename std::enable_if<std::is_base_of<BitwiseOrAssignment<NamedType>, NamedType>::value, NamedType&>::type
operator|= (NamedType& lhs, const NamedType& rhs)
{
    lhs.val |= rhs.val;
    return lhs;
}

template<class NamedType>
typename std::enable_if<std::is_base_of<BitwiseXorAssignment<NamedType>, NamedType>::value, NamedType&>::type
operator^= (NamedType& lhs, const NamedType& rhs)
{
    lhs.val ^= rhs.val;
    return lhs;
}

template<class NamedType>
typename std::enable_if<std::is_base_of<BitwiseLeftShiftAssignment<NamedType>, NamedType>::value, NamedType&>::type
operator<<= (NamedType& lhs, const NamedType& rhs)
{
    lhs.val <<= rhs.val;
    return lhs;
}

template<class NamedType>
typename std::enable_if<std::is_base_of<BitwiseRightShiftAssignment<NamedType>, NamedType>::value, NamedType&>::type
operator>>= (NamedType& lhs, const NamedType& rhs)
{
    lhs.val >>= rhs.val;
    return lhs;
}

// Increment/Decrement operators

template<class NamedType>
typename std::enable_if<std::is_base_of<PreIncrement<NamedType>, NamedType>::value, NamedType&>::type
operator++ (NamedType& rhs)
{
    ++rhs.val;
    return rhs;
}

template<class NamedType>
typename std::enable_if<std::is_base_of<PreDecrement<NamedType>, NamedType>::value, NamedType&>::type
operator-- (NamedType& rhs)
{
    --rhs.val;
    return rhs;
}

template<class NamedType>
typename std::enable_if<std::is_base_of<PostIncrement<NamedType>, NamedType>::value, NamedType>::type
operator++ (NamedType& lhs, int)
{
    NamedType ret = lhs;
    ret.val++;
    return ret;
}

template<class NamedType>
typename std::enable_if<std::is_base_of<PostDecrement<NamedType>, NamedType>::value, NamedType>::type
operator-- (NamedType& lhs, int)
{
    NamedType ret = lhs;
    ret.val--;
    return ret;
}

// Logical operators

template<class NamedType>
typename std::enable_if<std::is_base_of<Negation<NamedType>, NamedType>::value, bool>::type
operator! (const NamedType& a)
{
    return !a.val;
}

template<class NamedType>
typename std::enable_if<std::is_base_of<And<NamedType>, NamedType>::value, bool>::type
operator&& (const NamedType& lhs, const NamedType& rhs)
{
    return (lhs.val && rhs.val);
}

template<class NamedType>
typename std::enable_if<std::is_base_of<InclusiveOr<NamedType>, NamedType>::value, bool>::type
operator|| (const NamedType& lhs, const NamedType& rhs)
{
    return (lhs.val || rhs.val);
}

// Comparison operators

template<class NamedType>
typename std::enable_if<std::is_base_of<EqualTo<NamedType>, NamedType>::value, bool>::type
operator== (const NamedType& lhs, const NamedType& rhs)
{
    return (lhs.val == rhs.val);
}

template<class NamedType>
typename std::enable_if<std::is_base_of<NotEqualTo<NamedType>, NamedType>::value, bool>::type
operator!= (const NamedType& lhs, const NamedType& rhs)
{
    return (lhs.val != rhs.val);
}

template<class NamedType>
typename std::enable_if<std::is_base_of<LessThan<NamedType>, NamedType>::value, bool>::type
operator< (const NamedType& lhs, const NamedType& rhs)
{
    return (lhs.val < rhs.val);
}

template<class NamedType>
typename std::enable_if<std::is_base_of<GreaterThan<NamedType>, NamedType>::value, bool>::type
operator> (const NamedType& lhs, const NamedType& rhs)
{
    return (lhs.val > rhs.val);
}

template<class NamedType>
typename std::enable_if<std::is_base_of<LessThanOrEqualTo<NamedType>, NamedType>::value, bool>::type
operator<= (const NamedType& lhs, const NamedType& rhs)
{
    return (lhs.val == rhs.val);
}

template<class NamedType>
typename std::enable_if<std::is_base_of<GreaterThanOrEqualTo<NamedType>, NamedType>::value, bool>::type
operator>= (const NamedType& lhs, const NamedType& rhs)
{
    return (lhs.val >= rhs.val);
}

#endif // OPERATORS_H
