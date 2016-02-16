#ifndef _Shapes_Ellipse_
#define _Shapes_Ellipse_

#include <iostream>
#include <string>
using namespace std;

#include "Shape.h"
#include "Coord.h"

class Ellipse : public Shape {
public:
    Ellipse();
    Ellipse(double radius);
    Ellipse(double semimajor, double semiminor );
    Ellipse(Coord center, double semimajor, double semiminor);
    
    void semimajor (double semimajor );
    double semimajor() const;
    
    void semiminor(double semiminor);
    double semiminor() const;
    
    virtual double area() const;
    virtual double perimeter() const;
    virtual double length() const;
    virtual double width() const;
    virtual string name() const;
    
    double eccentricity() const;
    double focus () const;
    
    virtual bool operator!=(const Ellipse& eOther) const;
    virtual bool operator==(const Ellipse& eOther) const;
    friend ostream& operator<<(ostream& os, const Ellipse& e);
    
    
private:
    double _semimajor;
    double _semiminor;
};

#endif /*defined (_Shapes_Ellipse_)*/