#include "Ellipse.h"
#include"Shape.h"
#include <cmath>

const double PI = 3.1415926589;

Ellipse::Ellipse() : Ellipse (0, 0) {   }
Ellipse::Ellipse (double radius) : Ellipse (radius, radius) {}
Ellipse::Ellipse(double semimajor, double semiminor)
: _semimajor(semimajor), _semiminor (semiminor) {}

Ellipse::Ellipse(Coord center, double semimajor, double semiminor)
: Shape(center), _semimajor(semimajor), _semiminor(semiminor) {   }

double Ellipse::semimajor() const {return _semimajor; }
void Ellipse::semimajor (double semimajor) { _semimajor = semimajor; }

double Ellipse::semiminor() const {return _semiminor; }
void Ellipse::semiminor (double semiminor) { _semiminor = semiminor; }

double Ellipse::area () const { return PI * _semimajor * _semiminor; }
double Ellipse::perimeter () const { //approximation by Indian mathematician Ramanujan
    double a = _semimajor;
    double b = _semiminor;
    return PI*(3* (a+b) - sqrt((3*a +b) * (a + 3*b)));
}
double Ellipse::length () const { return 2 * _semimajor; }
double Ellipse::width () const { return 2* _semiminor; }
string Ellipse::name () const {return "Ellipse"; }

double Ellipse::eccentricity() const { return focus() / _semimajor; }
double Ellipse::focus() const {
    return sqrt ( pow(_semimajor, 2) - pow( _semiminor, 2));
}


bool Ellipse::operator!=(const Ellipse& pOther) const{ return !(*this == pOther);}
bool Ellipse::operator==(const Ellipse& pOther) const {
    return dynamic_cast<const Shape&>( *this) == dynamic_cast<const Shape&>(pOther) &&
    _semimajor == pOther._semimajor &&
    _semiminor == pOther._semiminor;
}

ostream& operator<<(ostream& os, const Ellipse& e) {
    return os<<"Ellipse[semimajor==" << e._semimajor <<", semiminor=" <<e._semiminor << ", " << dynamic_cast<const Shape&> (e) <<"]";
}