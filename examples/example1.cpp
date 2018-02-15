#include "quick_type.hpp"
#include <assert.h>
#include <iostream>

/*! \file example1.cpp
 *  \brief A basic example using a quick_type as an interface type.
 *
 * In this example two types ('Row' and 'Column') are defined and used in the interface of get_element. The goal is to make it clear what each
 * parameter does at the call site and let the compiler check that the correct parameters are provided.
 */

constexpr int rows    = 3;
constexpr int columns = 4;
//!< Create an array with some data. There is no deeper meaning to this stuff, it's simply a data structure to read some data from.
static int ARR[rows][columns] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

/*! Definition of a new type called 'Row'. The first template parameter defines the unterlying type; the second parameter is an in place declared
 * struct to differentiate between quick_types; the third possible following parameters describe the functionalities of the declared type.*/
using Row = quick_type<int, struct RowTag, Comparable, Printable>;
/*! Another new type is declared, differentiated from 'Row' by the 'ColumnTag'. */
using Column = quick_type<int, struct ColumnTag, Comparable, Printable>;

int main();
int get_element(Row r, Column c);

int main()
{
    // int res = get_element(1,3); //!< compile error! which of these values is the row? which is the column?
    // int res = get_element(Column(2), Row(1)) //!< compile error! Types do not match, wrong usage of the function
    Row    y(1);
    Column x(2);
    //!< The types of x and y make it impossible to call get_element incorrect.
    std::cout << "The result of get_element(" << y << ", " << x << ") = " << get_element(y, x) << "\n";
    int res = get_element(Row(1), Column(2)); // works! Its clear at the call site what each argument is doing.
    return res;
}

/*! The get_element function uses the explicit types Row and Column for its interface. Imagine get_element had this signature: int get_element(int
 * row, int column). At the call site it would look like this: var = get_element(3,5); The meaning of the parameters is unclear and mistakes can
 * easily happen. */
int get_element(Row r, Column c)
{
    if (0 <= r.val && r.val < rows && 0 <= c.val && c.val < columns)
    {
        return (ARR[r.val][c.val]);
    }
    return -1;
}
