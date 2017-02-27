#ifndef GMFIGURES_H
#define GMFIGURES_H

#include "abstractfigures.h"
#include <iostream>
using std::ostream;

class Circle : public ScalableFigure
{
    friend ostream& operator<<(ostream &output, const Circle &obj);

public:
    Circle(double value);
    void transform(double value);
    /*virtual*/ void scalable(double zoom);
    /*virtual*/ void print();
    /*virtual*/ ~Circle(){}

private:
    double cradius;

    /*virtual*/ void calculateValues();
};


class Square : public ScalableFigure
{
    friend ostream& operator<<(ostream &output, const Square &obj);

public:
    Square(double value);
    void transform(double value);
    /*virtual*/ void scalable(double zoom);
    /*virtual*/ void print();
    /*virtual*/ ~Square(){}

private:
    double sideLength;

    /*virtual*/ void calculateValues();
};


class Triangle : public StretchableFigure
{
    friend ostream& operator<<(ostream &output, const Triangle &obj);

public:
    Triangle(double value1, double value2, double value3);
    void transform(double value1, double value2, double value3);
    /*virtual*/ void scalable(double zoom);
    /*virtual*/ void stretchable();
    /*virtual*/ void print();
    /*virtual*/ ~Triangle(){}

private:
    double valueA;
    double valueB;
    double valueC;

    /*virtual*/ void calculateValues();
};



class Rectangle : public StretchableFigure
{
    friend ostream& operator<<(ostream &output, const Rectangle &obj);

public:
    Rectangle(double value1, double value2);
    void transform(double value1, double value2);
    /*virtual*/ void scalable(double zoom);
    /*virtual*/ void stretchable();
    /*virtual*/ void print();
    /*virtual*/ ~Rectangle(){}

private:
    double valueA;
    double valueB;

    /*virtual*/ void calculateValues();
};

#endif // GMFIGURES_H
