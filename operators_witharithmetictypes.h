#ifndef OPERATORS_WITHARITHMETICTYPES_H
#define OPERATORS_WITHARITHMETICTYPES_H

#include "skills.h"
#include "conjunction.h"
#include <type_traits>
#include <iostream>

// Arithmetic operators

template<class NamedType, typename T>
typename std::enable_if<conjunction<std::is_base_of<AdditionWithArith, NamedType>,
                                    std::is_arithmetic<T>>::value,NamedType>::type
operator+ (const NamedType& lhs, const T& rhs)
{
  return NamedType{lhs.val + rhs};
}

template<class NamedType, typename T>
typename std::enable_if<conjunction<std::is_base_of<SubtractionWithArith, NamedType>, std::is_arithmetic<T>>::value, NamedType>::type
operator- (const NamedType& lhs, const T& rhs)
{
  return NamedType{lhs.val - rhs};
}

template<class NamedType, typename T>
typename std::enable_if<conjunction<std::is_base_of<MultiplicationWithArith, NamedType>, std::is_arithmetic<T>>::value, NamedType>::type
operator* (const NamedType& lhs, const T& rhs)
{
  return NamedType{static_cast<decltype(lhs.val)>(lhs.val * rhs)};
}

template<class NamedType, typename T>
typename std::enable_if<conjunction<std::is_base_of<DivisionWithArith, NamedType>, std::is_arithmetic<T>>::value, NamedType>::type
operator/ (const NamedType& lhs, const T& rhs)
{
  return NamedType{lhs.val / rhs};
}

template<class NamedType, typename T>
typename std::enable_if<conjunction<std::is_base_of<ModuloWithArith, NamedType>, std::is_arithmetic<T>>::value, NamedType>::type
operator% (const NamedType& lhs, const T& rhs)
{
  return NamedType{lhs.val % rhs};
}

template<class NamedType, typename T>
typename std::enable_if<conjunction<std::is_base_of<BitwiseAndWithArith, NamedType>, std::is_arithmetic<T>>::value, NamedType>::type
operator& (const NamedType& lhs, const T& rhs)
{
  return NamedType{lhs.val & rhs};
}

template<class NamedType, typename T>
typename std::enable_if<conjunction<std::is_base_of<BitwiseOrWithArith, NamedType>, std::is_arithmetic<T>>::value, NamedType>::type
operator| (const NamedType& lhs, const T& rhs)
{
  return NamedType{lhs.val | rhs};
}

template<class NamedType, typename T>
typename std::enable_if<conjunction<std::is_base_of<BitwiseXorWithArith, NamedType>, std::is_arithmetic<T>>::value, NamedType>::type
operator^ (const NamedType& lhs, const T& rhs)
{
  return NamedType{lhs.val ^ rhs};
}

template<class NamedType, typename T>
typename std::enable_if<conjunction<std::is_base_of<BitwiseLeftShift, NamedType>, std::is_arithmetic<T>>::value, NamedType>::type
operator<< (const NamedType& lhs, const T& rhs)
{
  return NamedType{lhs.val << rhs};
}

template<class NamedType, typename T>
typename std::enable_if<conjunction<std::is_base_of<BitwiseRightShiftWithArith, NamedType>, std::is_arithmetic<T>>::value, NamedType>::type
operator>> (const NamedType& lhs, const T& rhs)
{
    return NamedType{lhs.val >> rhs};
}

// Assignment operators

template<class NamedType, typename T>
typename std::enable_if<conjunction<std::is_base_of<AdditionAssignmentWithArith, NamedType>, std::is_arithmetic<T>>::value, NamedType&>::type
operator+= (NamedType& lhs, const T& rhs)
{
    lhs.val += rhs;
    return lhs;
}

template<class NamedType, typename T>
typename std::enable_if<conjunction<std::is_base_of<SubtractionAssignmentWithArith, NamedType>, std::is_arithmetic<T>>::value, NamedType&>::type
operator-= (NamedType& lhs, const T& rhs)
{
    lhs.val -= rhs;
    return lhs;
}

template<class NamedType, typename T>
typename std::enable_if<conjunction<std::is_base_of<MultiplicationAssignmentWithArith, NamedType>, std::is_arithmetic<T>>::value, NamedType&>::type
operator*= (NamedType& lhs, const T& rhs)
{
    lhs.val *= rhs;
    return lhs;
}

template<class NamedType, typename T>
typename std::enable_if<conjunction<std::is_base_of<DivisionAssignmentWithArith, NamedType>, std::is_arithmetic<T>>::value, NamedType&>::type
operator/= (NamedType& lhs, const T& rhs)
{
    lhs.val /= rhs;
    return lhs;
}

template<class NamedType, typename T>
typename std::enable_if<conjunction<std::is_base_of<ModuloAssignmentWithArith, NamedType>, std::is_arithmetic<T>>::value, NamedType&>::type
operator%= (NamedType& lhs, const T& rhs)
{
    lhs.val %= rhs;
    return lhs;
}

template<class NamedType, typename T>
typename std::enable_if<conjunction<std::is_base_of<BitwiseAndAssignmentWithArith, NamedType>, std::is_arithmetic<T>>::value, NamedType&>::type
operator+= (NamedType& lhs, const T& rhs)
{
    lhs.val &= rhs;
    return lhs;
}

template<class NamedType, typename T>
typename std::enable_if<conjunction<std::is_base_of<BitwiseOrAssignmentWithArith, NamedType>, std::is_arithmetic<T>>::value, NamedType&>::type
operator|= (NamedType& lhs, const T& rhs)
{
    lhs.val |= rhs;
    return lhs;
}

template<class NamedType, typename T>
typename std::enable_if<conjunction<std::is_base_of<BitwiseXorAssignmentWithArith, NamedType>, std::is_arithmetic<T>>::value, NamedType&>::type
operator^= (NamedType& lhs, const T& rhs)
{
    lhs.val ^= rhs;
    return lhs;
}

template<class NamedType, typename T>
typename std::enable_if<conjunction<std::is_base_of<BitwiseLeftShiftAssignmentWithArith, NamedType>, std::is_arithmetic<T>>::value, NamedType&>::type
operator<<= (NamedType& lhs, const T& rhs)
{
    lhs.val <<= rhs;
    return lhs;
}

template<class NamedType, typename T>
typename std::enable_if<conjunction<std::is_base_of<BitwiseRightShiftAssignmentWithArith, NamedType>, std::is_arithmetic<T>>::value, NamedType&>::type
operator>>= (NamedType& lhs, const T& rhs)
{
    lhs.val >>= rhs;
    return lhs;
}

// Logical operators

template<class NamedType, typename T>
typename std::enable_if<conjunction<std::is_base_of<AndWithArith, NamedType>, std::is_arithmetic<T>>::value, bool>::type
operator&& (const NamedType& lhs, const T& rhs)
{
    return (lhs.val && rhs);
}

template<class NamedType, typename T>
typename std::enable_if<conjunction<std::is_base_of<InclusiveOrWithArith, NamedType>, std::is_arithmetic<T>>::value, bool>::type
operator|| (const NamedType& lhs, const T& rhs)
{
    return (lhs.val || rhs);
}

// Comparison operators

template<class NamedType, typename T>
typename std::enable_if<conjunction<std::is_base_of<EqualToWithArith, NamedType>, std::is_arithmetic<T>>::value, bool>::type
operator== (const NamedType& lhs, const T& rhs)
{
    return (lhs.val == rhs);
}

template<class NamedType, typename T>
typename std::enable_if<conjunction<std::is_base_of<NotEqualToWithArith, NamedType>, std::is_arithmetic<T>>::value, bool>::type
operator!= (const NamedType& lhs, const T& rhs)
{
    return (lhs.val != rhs);
}

template<class NamedType, typename T>
typename std::enable_if<conjunction<std::is_base_of<LessThanWithArith, NamedType>, std::is_arithmetic<T>>::value, bool>::type
operator< (const NamedType& lhs, const T& rhs)
{
    return (lhs.val < rhs);
}

template<class NamedType, typename T>
typename std::enable_if<conjunction<std::is_base_of<GreaterThanWithArith, NamedType>, std::is_arithmetic<T>>::value, bool>::type
operator> (const NamedType& lhs, const T& rhs)
{
    return (lhs.val > rhs);
}

template<class NamedType, typename T>
typename std::enable_if<conjunction<std::is_base_of<LessThanOrEqualToWithArith, NamedType>, std::is_arithmetic<T>>::value, bool>::type
operator<= (const NamedType& lhs, const T& rhs)
{
    return (lhs.val <= rhs);
}

template<class NamedType, typename T>
typename std::enable_if<conjunction<std::is_base_of<GreaterThanOrEqualToWithArith, NamedType>, std::is_arithmetic<T>>::value, bool>::type
operator>= (const NamedType& lhs, const T& rhs)
{
    return (lhs.val >= rhs);
}

#endif // OPERATORS_WITHARITHMETICTYPES_H
