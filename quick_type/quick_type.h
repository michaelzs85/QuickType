#include "namedtype.h"
#include <assert.h>
#include <limits>

using Meters = NamedType<int, struct MetersTag, Addition, Subtraction, Printable, UnaryMinus, MultiplicationWithArith, DivisionAssignmentWithArith>;
using Kilometers = MultipleOf2<Meters, double, std::kilo>;

using Feet        = MultipleOf2<Meters, int, std::ratio<1000000000000, 3280833333334>>;
using Flightlevel = MultipleOf2<Feet, double, std::ratio<100>>;

Meters operator"" _m(unsigned long long int x)
{
    assert(std::numeric_limits<int>::max() >= x && x >= 0);
    return Meters{static_cast<int>(x)};
}
