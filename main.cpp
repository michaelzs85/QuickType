#include "namedtype.h"
#include <iostream>
#include <ratio>

using Meters = NamedType<double,struct MetersTag, Addition, Subtraction>;
//using Kilometers = MultipleOf2<Meters, double, std::kilo>;
using Kilometers = MultipleOf<Meters, std::kilo>;

using Feet = NamedType<double, struct FeetTag, Addition, Subtraction>;

void printKm(Kilometers l)
{
    std::cout << l.val << "km\n";
}



int main()
{
    //Meters l1{8};
    //Meters l2{154};
    Kilometers l4(1.5);
    Meters l3(2305);

    Feet f(14);

    printKm(l4);
    printKm(l3);
    return 0;
}



