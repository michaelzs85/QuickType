#include "namedtype.h"

using Meters = NamedType<int,struct MetersTag, Addition, Subtraction, Printable, MultiplicationWithArith, DivisionAssignmentWithArith>;
using Kilometers = MultipleOf2<Meters, double, std::kilo>;

using Feet = MultipleOf2<Meters, int, std::ratio<1000000000000, 3280833333334>>;
using Flightlevel = MultipleOf2<Feet, double, std::ratio<100>>;
