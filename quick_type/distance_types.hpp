#ifndef DISTANCE_TYPES_HPP
#define DISTANCE_TYPES_HPP

/*! \file distance_types.hpp
 */

#include "quick_type.hpp"
#include <assert.h>
#include <limits>

using Meters =
    quick_type<int, struct MetersTag, Hashable, Addition, Subtraction, Printable, UnaryMinus, MultiplicationWithArith, DivisionAssignmentWithArith>;

Meters operator"" _m(unsigned long long int x)
{
    assert(std::numeric_limits<int>::max() >= x && x >= 0);
    return Meters{static_cast<int>(x)};
}

using Kilometers = multiple_of2<Meters, double, std::kilo>;

Kilometers operator"" _km(long double x)
{
    assert(static_cast<long double>(std::numeric_limits<double>::max()) >= x && x >= static_cast<long double>(std::numeric_limits<double>::min()));
    return Kilometers{static_cast<double>(x)};
}

using Feet        = multiple_of<Meters, std::ratio<1000000000000ull, 3280833333334ull>>;
using Flightlevel = multiple_of2<Feet, double, std::ratio<100>>;

#endif // DISTANCE_TYPES_HPP
