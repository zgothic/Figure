#include "gmfigures.h"
#include "abstractfigures.h"

#include <stdexcept>
#include <typeinfo>
#include <cmath>

/*START Circle*/
Circle::Circle(double value)
{
    transform(value);
}

void Circle::transform(double value)
{
    if(value <= 0)
        throw std::runtime_error("bad_value");
    cradius = value;

    calculateValues();
}

/*virtual*/ void Circle::scalable(double zoom)
{
    if(zoom > 0)
        transform(cradius*zoom);
}

/*virtual*/ void Circle::print()
{
    cout << typeid(this).name()
         << "\nr = " << cradius << endl;
    Figure::print();
}

/*virtual*/ void Circle::calculateValues()
{
    setArea(3.141592 * cradius * cradius);
    setPerimeter(2 * 3.141592 * cradius);
}

ostream& operator<<(ostream &output, const Circle &obj)
{
    output << "Circle:\nr = " << obj.cradius
           << "\nArea: " << obj.area()
           << "\nPerimeter: " << obj.perimeter() << endl;
    return output;
}
/*END Circle*/


/*START Square*/
Square::Square(double value)
{
    transform(value);
}

void Square::transform(double value)
{
    if(value <= 0)
        throw std::runtime_error("bad_value");
    sideLength = value;
    calculateValues();
}

/*virtual*/ void Square::scalable(double zoom)
{
    if(zoom > 0)
        transform(sideLength*zoom);
}

/*virtual*/ void Square::print()
{
    cout << typeid(this).name()
         << "\na = " << sideLength << endl;
    Figure::print();
}

/*virtual*/ void Square::calculateValues()
{
    setArea(sideLength * sideLength);
    setPerimeter(4 * sideLength);
}

ostream& operator<<(ostream &output, const Square &obj)
{
    output << "Square:\na = " << obj.sideLength
           << "\nArea: " << obj.area()
           << "\nPerimeter: " << obj.perimeter() << endl;
    return output;
}
/*END Square*/


/*START Triangle*/
Triangle::Triangle(double value1, double value2, double value3)
{
    transform(value1, value2, value3);
}

void Triangle::transform(double value1, double value2, double value3)
{
    if(value1 <= 0 || value2 <= 0 || value3 <= 0 ||
            value1 >= value2 + value3 || value2 >= value1 + value3 || value3 >= value1 + value2)
        throw std::runtime_error("bad_value");

    for(int i = 0; i < 3; i++)

    valueA = value1;
    valueB = value2;
    valueC = value3;
    calculateValues();
}

/*virtual*/ void Triangle::scalable(double zoom)
{
    if(zoom > 0)
        transform(valueA*zoom, valueB*zoom, valueC*zoom);
}

/*virtual*/ void Triangle::stretchable()
{
    //stretchable
}

/*virtual*/ void Triangle::print()
{
    cout << typeid(this).name()
         << "\na = " << valueA
         << "\nb = " << valueB
         << "\nc = " << valueC << endl;
    Figure::print();
}

/*virtual*/ void Triangle::calculateValues()
{
    setPerimeter( (valueA + valueB + valueC) );
    double halfP = fPerimeter / 2.0;
    setArea( pow( (halfP * (halfP - valueA)
                  * (halfP - valueB)
                  * (halfP - valueC)), 0.5) );
}

ostream& operator<<(ostream &output, const Triangle &obj)
{
    output << "Triangle:\na = " << obj.valueA
           << "\nb = " << obj.valueB
           << "\nc = " << obj.valueC
           << "\nArea: " << obj.area()
           << "\nPerimeter: " << obj.perimeter() << endl;
    return output;
}
/*END Triangle*/



/*START Rectangle*/
Rectangle::Rectangle(double value1, double value2)
{
    transform(value1, value2);
}

void Rectangle::transform(double value1, double value2)
{
    if(value1 <= 0 || value2 <= 0)
        throw std::runtime_error("bad_value");

    valueA = value1;
    valueB = value2;

    calculateValues();
}

/*virtual*/ void Rectangle::scalable(double zoom)
{
    if(zoom > 0)
        transform(valueA*zoom, valueB*zoom);
}

/*virtual*/ void Rectangle::stretchable()
{
    //stretchable
}

/*virtual*/ void Rectangle::print()
{
    cout << typeid(this).name()
         << "\na = " << valueA
         << "\nb = " << valueB << endl;
    Figure::print();
}

/*virtual*/ void Rectangle::calculateValues()
{
    setArea( valueA * valueB );
    setPerimeter( 2 * valueA + 2 * valueB );
}

ostream& operator<<(ostream &output, const Rectangle &obj)
{
    output << "Rectangle:\na = " << obj.valueA
           << "\nb = " << obj.valueB
           << "\nArea: " << obj.area()
           << "\nPerimeter: " << obj.perimeter() << endl;
    return output;
}
/*END Rectangle*/
