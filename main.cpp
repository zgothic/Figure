#include "gmfigures.h"

#include <iostream>
using std::cout;
using std::endl;
using std::cerr;

#include <vector>
using std::vector;

#include <algorithm>
#include <iterator>

void printContainer(vector<Figure *> container)
{
    for(vector<Figure *>::iterator i = container.begin(); i < container.end(); i++)
    {
        (*i)->print();
        cout << endl;;
    }
    cout << "*****************" << endl << endl;
}

int main()
{
    Square *ptrSquare = new Square(10.0);
    Rectangle *ptrRectangle = new Rectangle(10.0, 15.0);
    Circle *ptrCircle = new Circle(20.0);
    Triangle *ptrTriangle = new Triangle(15.0, 25.0, 30.0);

    //cout << *ptrSquare << endl << *ptrRectangle << endl << *ptrCircle << endl << *ptrTriangle << endl;

    vector<Figure *> fcontainer;
    fcontainer.push_back( ptrSquare );
    fcontainer.push_back( ptrRectangle );
    fcontainer.push_back( ptrCircle );
    fcontainer.push_back( ptrTriangle );
    printContainer(fcontainer);

    ptrRectangle->transform(15.0, 15.0);
    printContainer(fcontainer);

    try
    {
        ptrTriangle->transform(15.0, 10.0, 30.0);
    }
    catch(std::runtime_error error)
    {
        cerr << "Error transform the triangle: " << error.what() << endl;
    }
    printContainer(fcontainer);

    return 0;
}
