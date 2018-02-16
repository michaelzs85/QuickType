#ifndef CONVERT_HPP
#define CONVERT_HPP

/*! \file convert.hpp
 */

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

#endif // CONVERT_HPP
