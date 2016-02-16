#include <cmath>
#include "Triangle.h"
#include <iostream>
using namespace std;

Triangle::Triangle()
: Triangle( 0, 0, 0) {}

Triangle::Triangle (double sideA, double sideB, double sideC)
: _sideA(sideA), _sideB (sideB), _sideC(sideC) {
    //    valid();
    //    if (!valid()) { throw invalid_argument ("invalid triangle sides"); }
}
Triangle::Triangle(Coord center, double sideA, double sideB, double sideC)
: Shape(center), _sideA(sideA), _sideB(sideB), _sideC(sideC) {   }

void Triangle::sideA(double sideA) { _sideA = sideA; checkValid(); }
void Triangle::sideB(double sideB) { _sideB = sideB; checkValid();}
void Triangle::sideC(double sideC) { _sideC = sideC; checkValid(); }


string Triangle::name() const{ return "I am a Triangle";}

//bool  Triangle::isValid() const  {  return  valid();  }



bool Triangle::valid() const {
    return _sideA + _sideB > _sideC &&
    _sideB + _sideC > _sideA &&
    _sideC + _sideA > _sideB;
}




double Triangle::max (double m, double n) const{ return m > n ? m : n;}




double Triangle::length() const { return max( _sideC, max(_sideA, _sideB ));}
double Triangle::width() const {return area()/2 ;}
double Triangle::perimeter() const { return _sideA+_sideB+_sideC ; }
double Triangle::area() const { return heron(); }

double Triangle::heron() const {
    double area, s;
    s = perimeter()/2;
    area = sqrt(s*(s-_sideA)*(s-_sideB)*(s-_sideC));
    
    return area;
}
void Triangle::checkValid() const {
    if (!valid())  {  cout << " is invalid." << endl;
        display();
    }
}

void Triangle::display() const {
    cout <<"Triangle[" <<_sideA<<", "<<_sideB<<", "<<_sideC<<"]";
}

bool Triangle::isValid() const {return valid();}

bool Triangle::operator!=(const Triangle& trOther) const{ return !(*this == trOther);}
bool Triangle::operator==(const Triangle& trOther) const {
    return dynamic_cast<const Shape&>( *this) == dynamic_cast<const Shape&>(trOther) &&
    _sideB==trOther._sideB &&
    _sideA == trOther._sideA &&
    _sideC == trOther._sideC;
}

