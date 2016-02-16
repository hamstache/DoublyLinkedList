#include "Parallelogram.h"
#include "Shape.h"
#include "Coord.h"
#include <cmath>

const double PI = 3.1415926589;

Parallelogram :: Parallelogram()
: _sideA (0), _sideB(0), _theta(0) {       }

Parallelogram :: Parallelogram(double sideA, double sideB, double theta)
: Parallelogram(Coord(0,0), sideB, sideA, theta) {    }

Parallelogram::Parallelogram(Coord center, double sideA, double sideB, double theta)
: Shape(center), _sideA(sideA), _sideB(sideB), _theta(theta) {   }

double Parallelogram::sideA() const {return _sideA;}
double Parallelogram::sideB() const {return _sideB;}
double Parallelogram::theta() const {return _theta;}


void Parallelogram::sideA(double sideA) {_sideA = sideA;}
void Parallelogram::sideB(double sideB) {_sideB = sideB;}
void Parallelogram::theta(double theta) {_theta = theta;}

double Parallelogram::area() const { return _sideA * _sideB;    }
double Parallelogram::perimeter() const { return (2* _sideA) + (2*_sideB);    }
double Parallelogram::length() const{ return cos(theta() * PI/ 180.00) *sideB() +sideA();   }
double Parallelogram::width() const { return sin((theta()/360)*2*PI) * sideB();    }

bool Parallelogram::operator!=(const Parallelogram& pOther) const{ return !(*this == pOther);}
bool Parallelogram::operator==(const Parallelogram& pOther) const {
    return dynamic_cast<const Shape&>( *this) == dynamic_cast<const Shape&>(pOther) &&
    _sideB==pOther._sideB &&
    _sideA == pOther._sideA &&
    _theta == pOther._theta;
}
ostream& operator<<(ostream& os, const Parallelogram& p) {
    return os<<"Parallelogram[sideB=" << p._sideB <<", sideA=" <<p._sideA << ", angle=" << p._theta << ", " << dynamic_cast<const Shape&> (p) <<"]";
}

string Parallelogram:: name() const { return "I am a Parallelogram.\n" ;}
