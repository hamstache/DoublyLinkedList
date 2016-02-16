#include "Circle.h"

#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.141592653;

Circle::Circle()
: Circle (0) {}

Circle::Circle (double radius)
: Ellipse (radius, radius) {}

Circle::Circle (Coord center, double radius)
: Ellipse(center, radius, radius) {   }


double Circle::radius() const {  return radius();    }




/*If circle changes its radius, it MUST set the semimajor and semiminor axis to be equal*/


void Circle::radius ( double radius ) {
    semimajor (radius) ;
    semiminor (radius);
}


double Circle::diameter() const { return 2* radius();   }
double Circle::circumference() const { return 2 * PI * radius();  }
string Circle::name() const { return "I am a circle."; }

ostream& operator<<(ostream& os, const Circle& cr){
    return os<<"Circle[" << dynamic_cast<const Ellipse&> (cr) <<"]";
}


