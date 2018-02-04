#ifndef OPERATORS_WITHARITHMETICTYPES_H
#define OPERATORS_WITHARITHMETICTYPES_H

#include "skills.h"
#include "conjunction.h"
#include <type_traits>
#include <iostream>

// Arithmetic operators

template<class NamedType, typename T>
typename std::enable_if<conjunction<std::is_base_of<AdditionWithArith<NamedType>, NamedType>,
                                    std::is_arithmetic<T>>::value,NamedType>::type
operator+ (const NamedType& lhs, const T& rhs)
{
  return NamedType{lhs.val + rhs};
}

template<class NamedType, typename T>
typename std::enable_if<conjunction<std::is_base_of<SubtractionWithArith<NamedType>, NamedType>, std::is_arithmetic<T>>::value, NamedType>::type
operator- (const NamedType& lhs, const T& rhs)
{
  return NamedType{lhs.val - rhs};
}

template<class NamedType, typename T>
typename std::enable_if<conjunction<std::is_base_of<MultiplicationWithArith<NamedType>, NamedType>, std::is_arithmetic<T>>::value, NamedType>::type
operator* (const NamedType& lhs, const T& rhs)
{
  return NamedType{static_cast<decltype(lhs.val)>(lhs.val * rhs)};
}

template<class NamedType, typename T>
typename std::enable_if<conjunction<std::is_base_of<DivisionWithArith<NamedType>, NamedType>, std::is_arithmetic<T>>::value, NamedType>::type
operator/ (const NamedType& lhs, const T& rhs)
{
  return NamedType{lhs.val / rhs};
}

template<class NamedType, typename T>
typename std::enable_if<conjunction<std::is_base_of<ModuloWithArith<NamedType>, NamedType>, std::is_arithmetic<T>>::value, NamedType>::type
operator% (const NamedType& lhs, const T& rhs)
{
  return NamedType{lhs.val % rhs};
}

template<class NamedType, typename T>
typename std::enable_if<conjunction<std::is_base_of<BitwiseAndWithArith<NamedType>, NamedType>, std::is_arithmetic<T>>::value, NamedType>::type
operator& (const NamedType& lhs, const T& rhs)
{
  return NamedType{lhs.val & rhs};
}

template<class NamedType, typename T>
typename std::enable_if<conjunction<std::is_base_of<BitwiseOrWithArith<NamedType>, NamedType>, std::is_arithmetic<T>>::value, NamedType>::type
operator| (const NamedType& lhs, const T& rhs)
{
  return NamedType{lhs.val | rhs};
}

template<class NamedType, typename T>
typename std::enable_if<conjunction<std::is_base_of<BitwiseXorWithArith<NamedType>, NamedType>, std::is_arithmetic<T>>::value, NamedType>::type
operator^ (const NamedType& lhs, const T& rhs)
{
  return NamedType{lhs.val ^ rhs};
}

template<class NamedType, typename T>
typename std::enable_if<conjunction<std::is_base_of<BitwiseLeftShift<NamedType>, NamedType>, std::is_arithmetic<T>>::value, NamedType>::type
operator<< (const NamedType& lhs, const T& rhs)
{
  return NamedType{lhs.val << rhs};
}

template<class NamedType, typename T>
typename std::enable_if<conjunction<std::is_base_of<BitwiseRightShiftWithArith<NamedType>, NamedType>, std::is_arithmetic<T>>::value, NamedType>::type
operator>> (const NamedType& lhs, const T& rhs)
{
    return NamedType{lhs.val >> rhs};
}

// Assignment operators

template<class NamedType, typename T>
typename std::enable_if<conjunction<std::is_base_of<AdditionAssignmentWithArith<NamedType>, NamedType>, std::is_arithmetic<T>>::value, NamedType&>::type
operator+= (NamedType& lhs, const T& rhs)
{
    lhs.val += rhs;
    return lhs;
}

template<class NamedType, typename T>
typename std::enable_if<conjunction<std::is_base_of<SubtractionAssignmentWithArith<NamedType>, NamedType>, std::is_arithmetic<T>>::value, NamedType&>::type
operator-= (NamedType& lhs, const T& rhs)
{
    lhs.val -= rhs;
    return lhs;
}

template<class NamedType, typename T>
typename std::enable_if<conjunction<std::is_base_of<MultiplicationAssignmentWithArith<NamedType>, NamedType>, std::is_arithmetic<T>>::value, NamedType&>::type
operator*= (NamedType& lhs, const T& rhs)
{
    lhs.val *= rhs;
    return lhs;
}

template<class NamedType, typename T>
typename std::enable_if<conjunction<std::is_base_of<DivisionAssignmentWithArith<NamedType>, NamedType>, std::is_arithmetic<T>>::value, NamedType&>::type
operator/= (NamedType& lhs, const T& rhs)
{
    lhs.val /= rhs;
    return lhs;
}

template<class NamedType, typename T>
typename std::enable_if<conjunction<std::is_base_of<ModuloAssignmentWithArith<NamedType>, NamedType>, std::is_arithmetic<T>>::value, NamedType&>::type
operator%= (NamedType& lhs, const T& rhs)
{
    lhs.val %= rhs;
    return lhs;
}

template<class NamedType, typename T>
typename std::enable_if<conjunction<std::is_base_of<BitwiseAndAssignmentWithArith<NamedType>, NamedType>, std::is_arithmetic<T>>::value, NamedType&>::type
operator+= (NamedType& lhs, const T& rhs)
{
    lhs.val &= rhs;
    return lhs;
}

template<class NamedType, typename T>
typename std::enable_if<conjunction<std::is_base_of<BitwiseOrAssignmentWithArith<NamedType>, NamedType>, std::is_arithmetic<T>>::value, NamedType&>::type
operator|= (NamedType& lhs, const T& rhs)
{
    lhs.val |= rhs;
    return lhs;
}

template<class NamedType, typename T>
typename std::enable_if<conjunction<std::is_base_of<BitwiseXorAssignmentWithArith<NamedType>, NamedType>, std::is_arithmetic<T>>::value, NamedType&>::type
operator^= (NamedType& lhs, const T& rhs)
{
    lhs.val ^= rhs;
    return lhs;
}

template<class NamedType, typename T>
typename std::enable_if<conjunction<std::is_base_of<BitwiseLeftShiftAssignmentWithArith<NamedType>, NamedType>, std::is_arithmetic<T>>::value, NamedType&>::type
operator<<= (NamedType& lhs, const T& rhs)
{
    lhs.val <<= rhs;
    return lhs;
}

template<class NamedType, typename T>
typename std::enable_if<conjunction<std::is_base_of<BitwiseRightShiftAssignmentWithArith<NamedType>, NamedType>, std::is_arithmetic<T>>::value, NamedType&>::type
operator>>= (NamedType& lhs, const T& rhs)
{
    lhs.val >>= rhs;
    return lhs;
}

// Logical operators

template<class NamedType, typename T>
typename std::enable_if<conjunction<std::is_base_of<AndWithArith<NamedType>, NamedType>, std::is_arithmetic<T>>::value, bool>::type
operator&& (const NamedType& lhs, const T& rhs)
{
    return (lhs.val && rhs);
}

template<class NamedType, typename T>
typename std::enable_if<conjunction<std::is_base_of<InclusiveOrWithArith<NamedType>, NamedType>, std::is_arithmetic<T>>::value, bool>::type
operator|| (const NamedType& lhs, const T& rhs)
{
    return (lhs.val || rhs);
}

// Comparison operators

template<class NamedType, typename T>
typename std::enable_if<conjunction<std::is_base_of<EqualToWithArith<NamedType>, NamedType>, std::is_arithmetic<T>>::value, bool>::type
operator== (const NamedType& lhs, const T& rhs)
{
    return (lhs.val == rhs);
}

template<class NamedType, typename T>
typename std::enable_if<conjunction<std::is_base_of<NotEqualToWithArith<NamedType>, NamedType>, std::is_arithmetic<T>>::value, bool>::type
operator!= (const NamedType& lhs, const T& rhs)
{
    return (lhs.val != rhs);
}

template<class NamedType, typename T>
typename std::enable_if<conjunction<std::is_base_of<LessThanWithArith<NamedType>, NamedType>, std::is_arithmetic<T>>::value, bool>::type
operator< (const NamedType& lhs, const T& rhs)
{
    return (lhs.val < rhs);
}

template<class NamedType, typename T>
typename std::enable_if<conjunction<std::is_base_of<GreaterThanWithArith<NamedType>, NamedType>, std::is_arithmetic<T>>::value, bool>::type
operator> (const NamedType& lhs, const T& rhs)
{
    return (lhs.val > rhs);
}

template<class NamedType, typename T>
typename std::enable_if<conjunction<std::is_base_of<LessThanOrEqualToWithArith<NamedType>, NamedType>, std::is_arithmetic<T>>::value, bool>::type
operator<= (const NamedType& lhs, const T& rhs)
{
    return (lhs.val == rhs);
}

template<class NamedType, typename T>
typename std::enable_if<conjunction<std::is_base_of<GreaterThanOrEqualToWithArith<NamedType>, NamedType>, std::is_arithmetic<T>>::value, bool>::type
operator>= (const NamedType& lhs, const T& rhs)
{
    return (lhs.val >= rhs);
}

#endif // OPERATORS_WITHARITHMETICTYPES_H
