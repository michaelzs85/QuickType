#include "quick_type.hpp"
#include <assert.h>
#include <limits>

using Meters = NamedType<int, struct MetersTag, Addition, Subtraction, Printable, UnaryMinus, MultiplicationWithArith, DivisionAssignmentWithArith>;

Meters operator"" _m(unsigned long long int x)
{
    assert(std::numeric_limits<int>::max() >= x && x >= 0);
    return Meters{static_cast<int>(x)};
}

using Kilometers = MultipleOf2<Meters, double, std::kilo>;

Kilometers operator "" _km(long double x)
{
    assert(std::numeric_limits<double>::max() >= x && x >=  std::numeric_limits<double>::min());
    return Kilometers{static_cast<double>(x)};
}

using Feet        = MultipleOf<Meters, std::ratio<1000000000000, 3280833333334>>;
using Flightlevel = MultipleOf2<Feet, double, std::ratio<100>>;

