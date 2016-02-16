#ifndef _Shapes_Paralellogram_
#define _Shapes_Paralellogram_

#include <iostream>
using namespace std;

#include "Shape.h"
#include "Coord.h"

class Parallelogram : public Shape {
public:
    Parallelogram();
    Parallelogram (double sideA, double sideB, double theta);
    Parallelogram(Coord center, double sideB, double sideA, double theta);
    
    double sideA() const;
    double sideB() const;
    double theta() const;
    
    void sideA(double sideA);
    void sideB(double sideB);
    void theta(double theta);
    
    virtual double area() const;
    virtual double perimeter() const;
    virtual double width() const;
    virtual double length() const;
    virtual string name() const;
    
    virtual bool operator!=(const Parallelogram& pOther) const;
    virtual bool operator==(const Parallelogram& pOther) const;
    friend ostream& operator<<(ostream& os, const Parallelogram& p);
    
    
private:
    double _sideA, _sideB, _theta;
    
    
};


#endif