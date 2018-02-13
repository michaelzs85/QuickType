#ifndef OPERATORS_WITHCONVERT_H
#define OPERATORS_WITHCONVERT_H

#include "conjunction.hpp"
#include "skills.hpp"
#include <type_traits>

// Arithmetic operators

template <class NamedType, class NamedType2>
typename std::enable_if<conjunction<std::is_base_of<Addition, NamedType>, std::is_convertible<NamedType2, NamedType>>::value, NamedType>::type
operator+(const NamedType& lhs, const NamedType2& rhs)
{
    return NamedType{lhs.val + NamedType(rhs).val};
}

template <class NamedType, class NamedType2>
typename std::enable_if<conjunction<std::is_base_of<Subtraction, NamedType>, std::is_convertible<NamedType2, NamedType>>::value, NamedType>::type
operator-(const NamedType& lhs, const NamedType2& rhs)
{
    return NamedType{lhs.val - NamedType(rhs).val};
}

template <class NamedType, class NamedType2>
typename std::enable_if<conjunction<std::is_base_of<Multiplication, NamedType>, std::is_convertible<NamedType2, NamedType>>::value, NamedType>::type
operator*(const NamedType& lhs, const NamedType2& rhs)
{
    return NamedType{lhs.val * NamedType(rhs).val};
}

template <class NamedType, class NamedType2>
typename std::enable_if<conjunction<std::is_base_of<Division, NamedType>, std::is_convertible<NamedType2, NamedType>>::value, NamedType>::type
operator/(const NamedType& lhs, const NamedType2& rhs)
{
    return NamedType{lhs.val / NamedType(rhs).val};
}

template <class NamedType, class NamedType2>
typename std::enable_if<conjunction<std::is_base_of<Modulo, NamedType>, std::is_convertible<NamedType2, NamedType>>::value, NamedType>::type
operator%(const NamedType& lhs, const NamedType2& rhs)
{
    return NamedType{lhs.val % NamedType(rhs).val};
}

template <class NamedType, class NamedType2>
typename std::enable_if<conjunction<std::is_base_of<BitwiseAnd, NamedType>, std::is_convertible<NamedType2, NamedType>>::value, NamedType>::type
operator&(const NamedType& lhs, const NamedType2& rhs)
{
    return NamedType{lhs.val & NamedType(rhs).val};
}

template <class NamedType, class NamedType2>
typename std::enable_if<conjunction<std::is_base_of<BitwiseOr, NamedType>, std::is_convertible<NamedType2, NamedType>>::value, NamedType>::type
operator|(const NamedType& lhs, const NamedType2& rhs)
{
    return NamedType{lhs.val | NamedType(rhs).val};
}

template <class NamedType, class NamedType2>
typename std::enable_if<conjunction<std::is_base_of<BitwiseXor, NamedType>, std::is_convertible<NamedType2, NamedType>>::value, NamedType>::type
operator^(const NamedType& lhs, const NamedType2& rhs)
{
    return NamedType{lhs.val ^ NamedType(rhs).val};
}

template <class NamedType, class NamedType2>
typename std::enable_if<conjunction<std::is_base_of<BitwiseLeftShift, NamedType>, std::is_convertible<NamedType2, NamedType>>::value, NamedType>::type
operator<<(const NamedType& lhs, const NamedType2& rhs)
{
    return NamedType{lhs.val << NamedType(rhs).val};
}

template <class NamedType, class NamedType2>
typename std::enable_if<conjunction<std::is_base_of<BitwiseRightShift, NamedType>, std::is_convertible<NamedType2, NamedType>>::value,
                        NamedType>::type
operator>>(const NamedType& lhs, const NamedType2& rhs)
{
    return NamedType{lhs.val >> NamedType(rhs).val};
}

// Assignment operators

template <class NamedType, class NamedType2>
typename std::enable_if<conjunction<std::is_base_of<AdditionAssignment, NamedType>, std::is_convertible<NamedType2, NamedType>>::value,
                        NamedType&>::type
operator+=(NamedType& lhs, const NamedType2& rhs)
{
    lhs.val += NamedType(rhs).val;
    return lhs;
}

template <class NamedType, class NamedType2>
typename std::enable_if<conjunction<std::is_base_of<SubtractionAssignment, NamedType>, std::is_convertible<NamedType2, NamedType>>::value,
                        NamedType&>::type
operator-=(NamedType& lhs, const NamedType2& rhs)
{
    lhs.val -= NamedType(rhs).val;
    return lhs;
}

template <class NamedType, class NamedType2>
typename std::enable_if<conjunction<std::is_base_of<MultiplicationAssignment, NamedType>, std::is_convertible<NamedType2, NamedType>>::value,
                        NamedType&>::type
operator*=(NamedType& lhs, const NamedType2& rhs)
{
    lhs.val *= NamedType(rhs).val;
    return lhs;
}

template <class NamedType, class NamedType2>
typename std::enable_if<conjunction<std::is_base_of<DivisionAssignment, NamedType>, std::is_convertible<NamedType2, NamedType>>::value,
                        NamedType&>::type
operator/=(NamedType& lhs, const NamedType2& rhs)
{
    lhs.val /= NamedType(rhs).val;
    return lhs;
}

template <class NamedType, class NamedType2>
typename std::enable_if<conjunction<std::is_base_of<ModuloAssignment, NamedType>, std::is_convertible<NamedType2, NamedType>>::value,
                        NamedType&>::type
operator%=(NamedType& lhs, const NamedType2& rhs)
{
    lhs.val %= NamedType(rhs).val;
    return lhs;
}

template <class NamedType, class NamedType2>
typename std::enable_if<conjunction<std::is_base_of<BitwiseAndAssignment, NamedType>, std::is_convertible<NamedType2, NamedType>>::value,
                        NamedType&>::type
operator&=(NamedType& lhs, const NamedType2& rhs)
{
    lhs.val &= NamedType(rhs).val;
    return lhs;
}

template <class NamedType, class NamedType2>
typename std::enable_if<conjunction<std::is_base_of<BitwiseOrAssignment, NamedType>, std::is_convertible<NamedType2, NamedType>>::value,
                        NamedType&>::type
operator|=(NamedType& lhs, const NamedType2& rhs)
{
    lhs.val |= NamedType(rhs).val;
    return lhs;
}

template <class NamedType, class NamedType2>
typename std::enable_if<conjunction<std::is_base_of<BitwiseXorAssignment, NamedType>, std::is_convertible<NamedType2, NamedType>>::value,
                        NamedType&>::type
operator^=(NamedType& lhs, const NamedType2& rhs)
{
    lhs.val ^= NamedType(rhs).val;
    return lhs;
}

template <class NamedType, class NamedType2>
typename std::enable_if<conjunction<std::is_base_of<BitwiseLeftShiftAssignment, NamedType>, std::is_convertible<NamedType2, NamedType>>::value,
                        NamedType&>::type
operator<<=(NamedType& lhs, const NamedType2& rhs)
{
    lhs.val <<= NamedType(rhs).val;
    return lhs;
}

template <class NamedType, class NamedType2>
typename std::enable_if<conjunction<std::is_base_of<BitwiseRightShiftAssignment, NamedType>, std::is_convertible<NamedType2, NamedType>>::value,
                        NamedType&>::type
operator>>=(NamedType& lhs, const NamedType2& rhs)
{
    lhs.val >>= NamedType(rhs).val;
    return lhs;
}

// Logical operators

template <class NamedType, class NamedType2>
typename std::enable_if<conjunction<std::is_base_of<And, NamedType>, std::is_convertible<NamedType2, NamedType>>::value, bool>::type
operator&&(const NamedType& lhs, const NamedType2& rhs)
{
    return (lhs.val && NamedType(rhs).val);
}

template <class NamedType, class NamedType2>
typename std::enable_if<conjunction<std::is_base_of<InclusiveOr, NamedType>, std::is_convertible<NamedType2, NamedType>>::value, bool>::type
operator||(const NamedType& lhs, const NamedType2& rhs)
{
    return (lhs.val || NamedType(rhs).val);
}

// Comparison operators

template <class NamedType, class NamedType2>
typename std::enable_if<conjunction<std::is_base_of<EqualTo, NamedType>, std::is_convertible<NamedType2, NamedType>>::value, bool>::type
operator==(const NamedType& lhs, const NamedType2& rhs)
{
    return (lhs.val == NamedType(rhs).val);
}

template <class NamedType, class NamedType2>
typename std::enable_if<conjunction<std::is_base_of<NotEqualTo, NamedType>, std::is_convertible<NamedType2, NamedType>>::value, bool>::type
operator!=(const NamedType& lhs, const NamedType2& rhs)
{
    return (lhs.val != NamedType(rhs).val);
}

template <class NamedType, class NamedType2>
typename std::enable_if<conjunction<std::is_base_of<LessThan, NamedType>, std::is_convertible<NamedType2, NamedType>>::value, bool>::type
operator<(const NamedType& lhs, const NamedType2& rhs)
{
    return (lhs.val < NamedType(rhs).val);
}

template <class NamedType, class NamedType2>
typename std::enable_if<conjunction<std::is_base_of<GreaterThan, NamedType>, std::is_convertible<NamedType2, NamedType>>::value, bool>::type
operator>(const NamedType& lhs, const NamedType2& rhs)
{
    return (lhs.val > NamedType(rhs).val);
}

template <class NamedType, class NamedType2>
typename std::enable_if<conjunction<std::is_base_of<LessThanOrEqualTo, NamedType>, std::is_convertible<NamedType2, NamedType>>::value, bool>::type
operator<=(const NamedType& lhs, const NamedType2& rhs)
{
    return (lhs.val <= NamedType(rhs).val);
}

template <class NamedType, class NamedType2>
typename std::enable_if<conjunction<std::is_base_of<GreaterThanOrEqualTo, NamedType>, std::is_convertible<NamedType2, NamedType>>::value, bool>::type
operator>=(const NamedType& lhs, const NamedType2& rhs)
{
    return (lhs.val >= NamedType(rhs).val);
}

#endif // OPERATORS_WITHCONVERT_H
