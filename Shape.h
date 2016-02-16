#ifndef _Shapes_Shape_
#define _Shapes_Shape_

#include <iostream>
#include<string>
#include "Coord.h"
#include "LinkedListT.h"
using namespace std;

class Shape {
public:
    Shape();
    Shape(Coord center);
    
    Coord center() const;
    void center(Coord center);
    
    virtual double area() const = 0; //virtual (will call appropriate subclass at runtime)
    virtual double perimeter() const = 0; //... = 0 (no default code provided-)
    virtual double length () const = 0; // (subclasses MUST define or they
    virtual double width () const = 0; //      will be abstract too)
    virtual string name () const = 0; //Abstract classes CANNOT BE INSTANTIATED (made) IN NEW FUNCTION WITH TRIANGLES THE NAME IS NOT PURE VIRTUAL SO NO =0
    virtual bool isValid() const;
    virtual bool operator!=(const Shape& shOther) const;
    virtual bool operator==(const Shape& shOther) const;
    friend ostream& operator<<(ostream& os, const Shape& sh);
    
private:
    Coord _center;
};

#endif /* defined(_Shapes_Shape_) */