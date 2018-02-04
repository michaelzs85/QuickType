#ifndef OPERATORS_WITHCONVERT_H
#define OPERATORS_WITHCONVERT_H

#include "skills.h"
#include <iostream>

template<class...> struct conjunction : std::true_type { };
template<class B1> struct conjunction<B1> : B1 { };
template<class B1, class... Bn>
struct conjunction<B1, Bn...> : std::conditional<bool(B1::value), conjunction<Bn...>, B1>::type {};

// Arithmetic operators

template<class NamedType, class NamedType2>
typename std::enable_if<conjunction<std::is_base_of<Addition<NamedType>, NamedType>,
                                    std::is_convertible<NamedType2, NamedType>>::value,NamedType>::type
operator+ (const NamedType& lhs, const NamedType2& rhs)
{
  return NamedType{lhs.val + NamedType(rhs).val};
}

template<class NamedType, class NamedType2>
typename std::enable_if<conjunction<std::is_base_of<Subtraction<NamedType>, NamedType>, std::is_convertible<NamedType2, NamedType>>::value, NamedType>::type
operator- (const NamedType& lhs, const NamedType2& rhs)
{
  return NamedType{lhs.val - NamedType(rhs).val};
}

template<class NamedType, class NamedType2>
typename std::enable_if<conjunction<std::is_base_of<Multiplication<NamedType>, NamedType>, std::is_convertible<NamedType2, NamedType>>::value, NamedType>::type
operator* (const NamedType& lhs, const NamedType2& rhs)
{
  return NamedType{lhs.val * NamedType(rhs).val};
}

template<class NamedType, class NamedType2>
typename std::enable_if<conjunction<std::is_base_of<Division<NamedType>, NamedType>, std::is_convertible<NamedType2, NamedType>>::value, NamedType>::type
operator/ (const NamedType& lhs, const NamedType2& rhs)
{
  return NamedType{lhs.val / NamedType(rhs).val};
}

template<class NamedType, class NamedType2>
typename std::enable_if<conjunction<std::is_base_of<Modulo<NamedType>, NamedType>, std::is_convertible<NamedType2, NamedType>>::value, NamedType>::type
operator% (const NamedType& lhs, const NamedType2& rhs)
{
  return NamedType{lhs.val % NamedType(rhs).val};
}

template<class NamedType, class NamedType2>
typename std::enable_if<conjunction<std::is_base_of<BitwiseAnd<NamedType>, NamedType>, std::is_convertible<NamedType2, NamedType>>::value, NamedType>::type
operator& (const NamedType& lhs, const NamedType2& rhs)
{
  return NamedType{lhs.val & NamedType(rhs).val};
}

template<class NamedType, class NamedType2>
typename std::enable_if<conjunction<std::is_base_of<BitwiseOr<NamedType>, NamedType>, std::is_convertible<NamedType2, NamedType>>::value, NamedType>::type
operator| (const NamedType& lhs, const NamedType2& rhs)
{
  return NamedType{lhs.val | NamedType(rhs).val};
}

template<class NamedType, class NamedType2>
typename std::enable_if<conjunction<std::is_base_of<BitwiseXor<NamedType>, NamedType>, std::is_convertible<NamedType2, NamedType>>::value, NamedType>::type
operator^ (const NamedType& lhs, const NamedType2& rhs)
{
  return NamedType{lhs.val ^ NamedType(rhs).val};
}

template<class NamedType, class NamedType2>
typename std::enable_if<conjunction<std::is_base_of<BitwiseLeftShift<NamedType>, NamedType>, std::is_convertible<NamedType2, NamedType>>::value, NamedType>::type
operator<< (const NamedType& lhs, const NamedType2& rhs)
{
  return NamedType{lhs.val << NamedType(rhs).val};
}

template<class NamedType, class NamedType2>
typename std::enable_if<conjunction<std::is_base_of<BitwiseRightShift<NamedType>, NamedType>, std::is_convertible<NamedType2, NamedType>>::value, NamedType>::type
operator>> (const NamedType& lhs, const NamedType2& rhs)
{
    return NamedType{lhs.val >> NamedType(rhs).val};
}

// Assignment operators

template<class NamedType, class NamedType2>
typename std::enable_if<conjunction<std::is_base_of<AdditionAssignment<NamedType>, NamedType>, std::is_convertible<NamedType2, NamedType>>::value, NamedType&>::type
operator+= (NamedType& lhs, const NamedType2& rhs)
{
    lhs.val += NamedType(rhs).val;
    return lhs;
}

template<class NamedType, class NamedType2>
typename std::enable_if<conjunction<std::is_base_of<SubtractionAssignment<NamedType>, NamedType>, std::is_convertible<NamedType2, NamedType>>::value, NamedType&>::type
operator-= (NamedType& lhs, const NamedType2& rhs)
{
    lhs.val -= NamedType(rhs).val;
    return lhs;
}

template<class NamedType, class NamedType2>
typename std::enable_if<conjunction<std::is_base_of<MultiplicationAssignment<NamedType>, NamedType>, std::is_convertible<NamedType2, NamedType>>::value, NamedType&>::type
operator*= (NamedType& lhs, const NamedType2& rhs)
{
    lhs.val *= NamedType(rhs).val;
    return lhs;
}

template<class NamedType, class NamedType2>
typename std::enable_if<conjunction<std::is_base_of<DivisionAssignment<NamedType>, NamedType>, std::is_convertible<NamedType2, NamedType>>::value, NamedType&>::type
operator/= (NamedType& lhs, const NamedType2& rhs)
{
    lhs.val /= NamedType(rhs).val;
    return lhs;
}

template<class NamedType, class NamedType2>
typename std::enable_if<conjunction<std::is_base_of<ModuloAssignment<NamedType>, NamedType>, std::is_convertible<NamedType2, NamedType>>::value, NamedType&>::type
operator%= (NamedType& lhs, const NamedType2& rhs)
{
    lhs.val %= NamedType(rhs).val;
    return lhs;
}

template<class NamedType, class NamedType2>
typename std::enable_if<conjunction<std::is_base_of<BitwiseAndAssignment<NamedType>, NamedType>, std::is_convertible<NamedType2, NamedType>>::value, NamedType&>::type
operator+= (NamedType& lhs, const NamedType2& rhs)
{
    lhs.val &= NamedType(rhs).val;
    return lhs;
}

template<class NamedType, class NamedType2>
typename std::enable_if<conjunction<std::is_base_of<BitwiseOrAssignment<NamedType>, NamedType>, std::is_convertible<NamedType2, NamedType>>::value, NamedType&>::type
operator|= (NamedType& lhs, const NamedType2& rhs)
{
    lhs.val |= NamedType(rhs).val;
    return lhs;
}

template<class NamedType, class NamedType2>
typename std::enable_if<conjunction<std::is_base_of<BitwiseXorAssignment<NamedType>, NamedType>, std::is_convertible<NamedType2, NamedType>>::value, NamedType&>::type
operator^= (NamedType& lhs, const NamedType2& rhs)
{
    lhs.val ^= NamedType(rhs).val;
    return lhs;
}

template<class NamedType, class NamedType2>
typename std::enable_if<conjunction<std::is_base_of<BitwiseLeftShiftAssignment<NamedType>, NamedType>, std::is_convertible<NamedType2, NamedType>>::value, NamedType&>::type
operator<<= (NamedType& lhs, const NamedType2& rhs)
{
    lhs.val <<= NamedType(rhs).val;
    return lhs;
}

template<class NamedType, class NamedType2>
typename std::enable_if<conjunction<std::is_base_of<BitwiseRightShiftAssignment<NamedType>, NamedType>, std::is_convertible<NamedType2, NamedType>>::value, NamedType&>::type
operator>>= (NamedType& lhs, const NamedType2& rhs)
{
    lhs.val >>= NamedType(rhs).val;
    return lhs;
}

// Logical operators

template<class NamedType, class NamedType2>
typename std::enable_if<conjunction<std::is_base_of<And<NamedType>, NamedType>, std::is_convertible<NamedType2, NamedType>>::value, bool>::type
operator&& (const NamedType& lhs, const NamedType2& rhs)
{
    return (lhs.val && NamedType(rhs).val);
}

template<class NamedType, class NamedType2>
typename std::enable_if<conjunction<std::is_base_of<InclusiveOr<NamedType>, NamedType>, std::is_convertible<NamedType2, NamedType>>::value, bool>::type
operator|| (const NamedType& lhs, const NamedType2& rhs)
{
    return (lhs.val || NamedType(rhs).val);
}

// Comparison operators

template<class NamedType, class NamedType2>
typename std::enable_if<conjunction<std::is_base_of<EqualTo<NamedType>, NamedType>, std::is_convertible<NamedType2, NamedType>>::value, bool>::type
operator== (const NamedType& lhs, const NamedType2& rhs)
{
    return (lhs.val == NamedType(rhs).val);
}

template<class NamedType, class NamedType2>
typename std::enable_if<conjunction<std::is_base_of<NotEqualTo<NamedType>, NamedType>, std::is_convertible<NamedType2, NamedType>>::value, bool>::type
operator!= (const NamedType& lhs, const NamedType2& rhs)
{
    return (lhs.val != NamedType(rhs).val);
}

template<class NamedType, class NamedType2>
typename std::enable_if<conjunction<std::is_base_of<LessThan<NamedType>, NamedType>, std::is_convertible<NamedType2, NamedType>>::value, bool>::type
operator< (const NamedType& lhs, const NamedType2& rhs)
{
    return (lhs.val < NamedType(rhs).val);
}

template<class NamedType, class NamedType2>
typename std::enable_if<conjunction<std::is_base_of<GreaterThan<NamedType>, NamedType>, std::is_convertible<NamedType2, NamedType>>::value, bool>::type
operator> (const NamedType& lhs, const NamedType2& rhs)
{
    return (lhs.val > NamedType(rhs).val);
}

template<class NamedType, class NamedType2>
typename std::enable_if<conjunction<std::is_base_of<LessThanOrEqualTo<NamedType>, NamedType>, std::is_convertible<NamedType2, NamedType>>::value, bool>::type
operator<= (const NamedType& lhs, const NamedType2& rhs)
{
    return (lhs.val == NamedType(rhs).val);
}

template<class NamedType, class NamedType2>
typename std::enable_if<conjunction<std::is_base_of<GreaterThanOrEqualTo<NamedType>, NamedType>, std::is_convertible<NamedType2, NamedType>>::value, bool>::type
operator>= (const NamedType& lhs, const NamedType2& rhs)
{
    return (lhs.val >= NamedType(rhs).val);
}



#endif // OPERATORS_WITHCONVERT_H
