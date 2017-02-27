#ifndef ABSTRACTFIGURES_H
#define ABSTRACTFIGURES_H

#include <iostream>
using std::endl;
using std::cout;

/*START Figure*/
class Figure
{
public:
    mutable double fArea;
    mutable double fPerimeter;

    double area() const;
    double perimeter() const;
    void setArea(double value) const;
    void setPerimeter(double value) const;
    virtual void print();
    virtual void calculateValues() = 0;
    virtual ~Figure(){}
};
/*END Figure*/


/*START ScalableFigure*/
class ScalableFigure : public Figure
{
public:
    virtual void scalable(double zoom) = 0;
};
/*END ScalableFigure*/


/*START StretchableFigure*/
class StretchableFigure : public ScalableFigure
{
public:
    virtual void stretchable() = 0;
};
/*END StretchableFigure*/


#endif // ABSTRACTFIGURES_H
