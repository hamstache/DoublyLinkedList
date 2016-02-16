#ifndef _Shapes_Rectangle_
#define _Shapes_Rectangle_

#include <iostream>
using namespace std;
#include "Shape.h"
#include "Parallelogram.h"

class Rectangle : public Parallelogram {
public:
    Rectangle();
    Rectangle (double length, double width);
    Rectangle(Coord center, double length, double width);
    
    void width (double width);
    void length (double length);
    double area() const;
    double perimeter() const;
    double width() const;
    double length() const;
    string name() const;
    
    friend ostream& operator<<(ostream& os, const Rectangle& r);
    
private:
    double _width, _length;
    
};

#endif /*defined ( _Shapes_Rectangle */
