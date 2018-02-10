#ifndef CONJUNCTION_H
#define CONJUNCTION_H

#include <type_traits>

// conjunction function taken from http://en.cppreference.com/w/cpp/types/conjunction
// replace with std::conjunction once C++17 is available
template <class...> struct conjunction : std::true_type
{
};
template <class B1> struct conjunction<B1> : B1
{
};
template <class B1, class... Bn> struct conjunction<B1, Bn...> : std::conditional<bool(B1::value), conjunction<Bn...>, B1>::type
{
};

#endif // CONJUNCTION_H
