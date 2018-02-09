#ifndef NAMEDTYPE_H
#define NAMEDTYPE_H

#include "operators.h"
#include "operators_witharithmetictypes.h"
#include "operators_withconvert.h"
#include "skills.h"
#include <ratio>
#include <type_traits>

template <typename T1, typename T2, T2 (*from)(T1), T1 (*to)(T2)> struct Convert
{
    static T2 convertFrom(T1 t)
    {
        return from(t);
    }
    static T1 convertTo(T2 t)
    {
        return to(t);
    }
};

template <typename T1, typename T2, T2 (*f)(T1), T1 (*g)(T1)> struct composeFrom
{
    static T2 func(T1 t)
    {
        return f(g(t));
    }
};

template <typename T1, typename T2, T1 (*f)(T1), T1 (*g)(T2)> struct composeTo
{
    static T1 func(T2 t)
    {
        return f(g(t));
    }
};

template <typename T1, typename T2, typename Ratio> struct ConvertWithRatio
{
    static T1 convertFrom(T2 t)
    {
        return static_cast<T1>(t) * Ratio::den / Ratio::num;
    }
    static T2 convertTo(T1 t)
    {
        return static_cast<T2>(t * Ratio::num / Ratio::den);
    }
};

template <typename T, class Tag, class Converter, class... Skills> struct NamedTypeImpl : public Skills..., Converter
{
    NamedTypeImpl() : val({})
    {
    }
    explicit NamedTypeImpl(T val_) : val(val_)
    {
    }
    T val;

    template <typename T2, class Converter2> operator NamedTypeImpl<T2, Tag, Converter2, Skills...>() const
    {
        return NamedTypeImpl<T2, Tag, Converter2, Skills...>{Converter2::convertFrom(Converter::convertTo(val))};
    }

    //  operator T() const
    //  {
    //    return val;
    //  }

    struct conversions
    {
        template <typename T2, class Converter1, class Converter2>
        using ComposeConverter = Convert<T, T2, composeFrom<T, T2, Converter2::convertFrom, Converter1::convertFrom>::func,
                                         composeTo<T, T2, Converter1::convertTo, Converter2::convertTo>::func>;

        template <typename T2, class Converter2>
        using GetConvertible = NamedTypeImpl<T2, Tag, ComposeConverter<T2, Converter, Converter2>, Skills...>;
    };
};

namespace std
{

template <typename T, class Tag, class Converter, class... Skills> struct hash<NamedTypeImpl<T, Tag, Converter, Skills...>>
{
    using NamedType  = NamedTypeImpl<T, Tag, ConvertWithRatio<T, T, std::ratio<1>>, Skills...>;
    using IsHashable = typename std::enable_if<std::is_base_of<Hashable, NamedType>::value, std::true_type>::type;

    size_t operator()(NamedType const& t) const noexcept
    {
        return std::hash<decltype(t.val)>()(t.val);
    }
};
}

template <typename T, class Tag, class... Skills> using NamedType = NamedTypeImpl<T, Tag, ConvertWithRatio<T, T, std::ratio<1>>, Skills...>;

template <class NamedType, typename T2, class Ratio>
using MultipleOf2 = typename NamedType::conversions::template GetConvertible<T2, ConvertWithRatio<T2, decltype(NamedType::val), Ratio>>;

#endif // NAMEDTYPE_H
