#ifndef NAMEDTYPE_H
#define NAMEDTYPE_H

#include "skills.h"
#include <type_traits>
#include <ratio>


template<typename T, T (*from)(T), T (*to)(T)>
struct Convert
{
  static T convertFrom(T t) {return from(t);}
  static T convertTo(T t) {return to(t);}
};


template<typename T, typename Ratio>
struct ConvertWithRatio
{
  static T convertFrom(T t) {return t * Ratio::den / Ratio::num;}
  static T convertTo(T t) {return t * Ratio::num / Ratio::den;}
};


template<typename T, class Tag, class Converter, template<typename> class... Skills >
struct NamedTypeImpl : public Skills<NamedTypeImpl<T, Tag, Converter, Skills...>>...
{
  explicit NamedTypeImpl(T val_) : val(val_) {}
  T val;

  template<class Converter2>
  operator NamedTypeImpl<T, Tag, Converter2, Skills...>() const
  {
    return NamedTypeImpl<T, Tag, Converter2, Skills...>{Converter2::convertFrom(Converter::convertTo(val))};
  }

  struct conversions
  {
    template<T(*f)(T), T(*g)(T)>
    struct compose
    {
        static T func(T t) {return f(g(t));}
    };
    template<class Converter1, class Converter2>
    using ComposeConverter = Convert<T, compose<Converter1::convertFrom, Converter2::convertFrom>::func, compose<Converter1::convertTo, Converter2::convertTo>::func>;
    template<typename Converter2>
    using GetConvertible = NamedTypeImpl<T, Tag, ComposeConverter<Converter, Converter2>, Skills...>;
  };
};


template<typename T, class Tag, template<typename> class... Skills >
using NamedType = NamedTypeImpl<T, Tag, ConvertWithRatio<T, std::ratio<1>>, Skills...>;

template<class NamedType, class Ratio>
using MultipleOf = typename NamedType::conversions::template GetConvertible<ConvertWithRatio<decltype(NamedType::val), Ratio>>;

template<class NamedType, typename T, class Ratio>
using MultipleOf2 = typename NamedType::conversions::template GetConvertible<ConvertWithRatio<T, Ratio>>;

template<class NamedType, class Converter>
using ConvertibleTo = typename NamedType::conversions::template GetConvertible<Converter>;










#endif // NAMEDTYPE_H
