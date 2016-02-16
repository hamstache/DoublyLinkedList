#ifndef _Shapes_Triangle_
#define _Shapes_Triangle_

#include <iostream>
#include <string>
using namespace std;
#include "Shape.h"
#include "Coord.h"

class Triangle : public Shape {
    
public:
    Triangle(); //default constructor, but...it makes invalid triangles
    Triangle( double sideA, double sideB, double sideC);
    Triangle(Coord center, double sideA, double sideB, double sideC);
    
    
    double sideA() const;  //standard accessors "getters"
    double sideB() const;  //e.g., void setSideB(double sideB);
    double sideC() const;
    
    
    void sideA (double sideA);  //standard mutators "setters"
    void sideB (double sideB);  // e.g., void setSideB (double sideB);
    void sideC (double sideC);
    
    virtual double perimeter() const; //virtual functions inherited from class Shape
    virtual double area() const;
    virtual double length() const;
    virtual double width() const;
    virtual string name () const;
    virtual bool   isValid() const;
    void display() const;
    
    virtual bool operator!=(const Triangle& trOther) const;
    virtual bool operator==(const Triangle& trother) const;
    friend ostream& operator<<(ostream& os, const Triangle& tr);
    
private:
    double max (double m, double n) const;
    double heron() const;
    void checkValid() const;
    bool valid() const;
    
private:
    double _sideA;
    double _sideB;
    double _sideC;
    
    
    
};

#endif /* defined (_Shapes_Triangle_) */