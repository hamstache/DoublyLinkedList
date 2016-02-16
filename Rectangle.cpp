#include "Rectangle.h"

Rectangle :: Rectangle ()
: _length(0), _width(0) {        }

Rectangle :: Rectangle (double length, double width )
: Rectangle(Coord(0,0), length, width)  {     }

Rectangle::Rectangle(Coord center, double length, double width)
: Parallelogram(center, length, width, 90) {    }

void Rectangle::width (double width) { width = sideB();     }
void Rectangle::length (double length) { length = sideA();    }

double Rectangle::area() const { return _length * _width;    }
double Rectangle::perimeter() const { return (2 * _length) + (2* _width);    }
double Rectangle::length() const { return sideA();     }
double Rectangle::width() const {  return sideB();    }
string Rectangle::name() const { return "I am a rectangle";     }

ostream& operator<<(ostream& os, const Rectangle& r) {
    return os<<"Rectangle[" <<dynamic_cast<const Parallelogram&>(r) <<"]";
}