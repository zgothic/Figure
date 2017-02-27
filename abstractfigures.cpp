#include "abstractfigures.h"

#include <iostream>
using std::endl;
using std::cout;

/*START Figure*/
double Figure::area() const
{
    return fArea;
}

double Figure::perimeter() const
{
    return fPerimeter;
}

void Figure::setArea(double value) const
{
    fArea = value;
}

void Figure::setPerimeter(double value) const
{
    fPerimeter = value;
}

/*virtual*/ void Figure::print()
{
    cout << "Area: " << area()
         << "\nPerimeter: " << perimeter() << endl;
}
/*END Figure*/
