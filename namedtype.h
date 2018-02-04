#ifndef NAMEDTYPE_H
#define NAMEDTYPE_H

#include "skills.h"
#include "operators.h"
#include "operators_withconvert.h"
#include <type_traits>
#include <ratio>

template<typename T1, typename T2, T2 (*from)(T1), T1 (*to)(T2)>
struct Convert
{
    static T2 convertFrom(T1 t) {return from(t);}
    static T1 convertTo(T2 t) {return to(t);}
};

template<typename T1, typename T2, typename Ratio>
struct ConvertWithRatio
{
    static T1 convertFrom(T2 t) {return static_cast<T1>(t) * Ratio::den / Ratio::num;}
    static T2 convertTo(T1 t) {return static_cast<T2>(t * Ratio::num / Ratio::den);}
};


template<typename T, class Tag, class Converter, template<typename> class... Skills >
struct NamedTypeImpl : public Skills<NamedTypeImpl<T, Tag, Converter, Skills...>>... , Converter
{
  explicit NamedTypeImpl(T val_) : val(val_) {}
  T val;

  template<typename T2, class Converter2>
  operator NamedTypeImpl<T2, Tag, Converter2, Skills...>() const
  {
    return NamedTypeImpl<T2, Tag, Converter2, Skills...>{Converter2::convertFrom(Converter::convertTo(val))};
  }

  struct conversions
  {
    template<typename T2, T2 (*f)(T), T (*g)(T)>
    struct composeFrom
    {
        static T2 func(T t) {return f(g(t));}
    };

    template<typename T2, T (*f)(T), T (*g)(T2)>
    struct composeTo
    {
        static T func(T2 t) {return f(g(t));}
    };

    template<typename T2, class Converter1, class Converter2>
    using ComposeConverter = Convert<T, T2, composeFrom<T2, Converter2::convertFrom, Converter1::convertFrom>::func, composeTo<T2, Converter1::convertTo, Converter2::convertTo>::func>;

    template<typename T2, class Converter2>
    using GetConvertible = NamedTypeImpl<T2, Tag, ComposeConverter<T2, Converter, Converter2>, Skills...>;
  };
};


template<typename T, class Tag, template<typename> class... Skills >
using NamedType = NamedTypeImpl<T, Tag, ConvertWithRatio<T, T, std::ratio<1>>, Skills...>;

template<class NamedType, typename T2, class Ratio>
using MultipleOf2 = typename NamedType::conversions::template GetConvertible<T2, ConvertWithRatio<T2, decltype(NamedType::val), Ratio>>;

//template<class NamedType, class Converter>
//using ConvertibleTo = typename NamedType::conversions::template GetConvertible<decltptype(NamedType::val),Converter>;




#endif // NAMEDTYPE_H
