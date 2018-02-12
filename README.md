#QuickType
[![Build Status](https://travis-ci.org/michaelzs85/QuickType.svg?branch=master)](https://travis-ci.org/michaelzs85/QuickType)

A C++ Library to support strong type safety. 

The idea is to quickly and easily create your own types. 

```
#include "strong_type.h"
#include <iostream>

using MyType = NamedType<int, struct UniqueTagToDistinguishTypes, Addition, Subtraction, Printable>;

void do_something(MyType x)
{
    MyType y{250};
    std::cout << x + y << "\n"; // works because addition is allowed
    std::cout << x * y << "\n"; // compile error multiplication not allowed
}


int main()
{
    MyType k{99};
    do_something(k);
    return 0;
}
```

The goal is to have type checking at compile time to minimize errors and keeping compiled programs efficent.
