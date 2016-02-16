#ifndef _Shapes_Circle_
#define _Shapes_Circle_

#include <iostream>
using namespace std;

#include "Ellipse.h"

class Circle: public Ellipse {
public:
    Circle ();
    Circle (double radius);
    Circle(Coord center, double radius);
    
    void radius (double value);
    double radius() const;
    double diameter() const;
    double circumference ()const;
    
    friend ostream& operator<<(ostream& os, const Circle& cr);
    
    string name () const;
private:
};

#endif //defined (_Shapes_Circle_)