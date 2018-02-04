#include "namedtype.h"
#include <iostream>
#include <ratio>

using Meters = NamedType<int,struct MetersTag, Addition, Subtraction, Printable>;
using Kilometers = MultipleOf2<Meters, double, std::kilo>;

using Feet = MultipleOf2<Meters, int, std::ratio<1000000000000, 3280833333334>>;




void printKm(Kilometers l)
{
    std::cout << l.val << "km\n";
}



int main()
{
    Feet f1(1289);
    Meters l1(134);
    std::cout << "l1: " << l1 << "m\n";
    Kilometers l2(l1);
    std::cout << "l2: " << l2 << "m\n";
    std::cout << "l2+f1: " << l2+f1 << "Km\n";
    std::cout << "l2-f1: " << l2-f1 << "Km\n";
    //printKm(l4);
    //printKm(l3);
    return 0;
}



