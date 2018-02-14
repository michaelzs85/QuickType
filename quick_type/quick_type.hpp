#ifndef NAMEDTYPE_H
#define NAMEDTYPE_H

#include "operators.hpp"
#include "operators_witharithmetictypes.hpp"
#include "operators_withconvert.hpp"
#include "skills.hpp"
#include <ratio>
#include <type_traits>

template <typename T1, typename T2, T2 (*from)(T1), T1 (*to)(T2)> struct convert
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

template <typename T1, typename T2, T2 (*f)(T1), T1 (*g)(T1)> struct compose_from
{
    static T2 func(T1 t)
    {
        return f(g(t));
    }
};

template <typename T1, typename T2, T1 (*f)(T1), T1 (*g)(T2)> struct compose_to
{
    static T1 func(T2 t)
    {
        return f(g(t));
    }
};

template <typename T1, typename T2, typename Ratio> struct convert_with_ratio
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

template <typename T, class Tag, class Converter, class... Skills> struct quick_type_impl : public Skills..., Converter
{
    quick_type_impl() : val({})
    {
    }
    explicit quick_type_impl(T val_) : val(val_)
    {
    }
    T val;

    // conversion operator
    template <typename T2, class Converter2> operator quick_type_impl<T2, Tag, Converter2, Skills...>() const
    {
        return quick_type_impl<T2, Tag, Converter2, Skills...>{Converter2::convertFrom(Converter::convertTo(val))};
    }

    struct conversions
    {
        template <typename T2, class Converter1, class Converter2>
        using ComposeConverter = convert<T, T2, compose_from<T, T2, Converter2::convertFrom, Converter1::convertFrom>::func,
                                         compose_to<T, T2, Converter1::convertTo, Converter2::convertTo>::func>;

        template <typename T2, class Converter2>
        using GetConvertible = quick_type_impl<T2, Tag, ComposeConverter<T2, Converter, Converter2>, Skills...>;
    };
};

template <typename T, class Tag, class... Skills> using quick_type = quick_type_impl<T, Tag, convert_with_ratio<T, T, std::ratio<1>>, Skills...>;

template <class quick_type, typename T2, class Ratio>
using multiple_of2 = typename quick_type::conversions::template GetConvertible<T2, convert_with_ratio<T2, decltype(quick_type::val), Ratio>>;

template <class quick_type, class Ratio> using multiple_of = multiple_of2<quick_type, decltype(quick_type::val), Ratio>;

// hashing

namespace std
{

template <typename T, class Tag, class Converter, class... Skills> struct hash<quick_type_impl<T, Tag, Converter, Skills...>>
{
    using quick_type = quick_type_impl<T, Tag, convert_with_ratio<T, T, std::ratio<1>>, Skills...>;
    using IsHashable = typename std::enable_if<std::is_base_of<Hashable, quick_type>::value, std::true_type>::type;

    size_t operator()(quick_type const &t) const noexcept
    {
        return std::hash<decltype(t.val)>()(t.val);
    }
};
}

#endif // NAMEDTYPE_H
