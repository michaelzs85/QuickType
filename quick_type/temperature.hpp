#ifndef TEMPERATURE_HPP
#define TEMPERATURE_HPP

/*! \file temperature.hpp
 */

#include "quick_type.hpp"
#include <assert.h>
#include <limits>

using Celsius = quick_type<double, struct CelsiusTag, Hashable, Addition, Subtraction, UnaryMinus, Printable>;

using Fahrenheit = multiple_with_offset2<Celsius, double, std::ratio<5, 9>, std::ratio<32>>;

using Kelvin = multiple_with_offset2<Celsius, double, std::ratio<1>, std::ratio<5463, 20>>;

#endif // TEMPERATURE_HPP
