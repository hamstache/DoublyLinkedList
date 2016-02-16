#include "Shape.h"

bool Shape::isValid() const { return true; }
string Shape::name() const {  return "Shape";  }

Shape::Shape()
:Shape(Coord(0, 0)) {  }

Coord Shape::center() const {return _center; }

Shape::Shape(Coord center)
: _center(center) {    }

void Shape::center(Coord center) {_center = center ;}

ostream& operator<<(ostream& os, const Shape& sh){
    return os<<"Shape[center="<<sh._center<<"]";
}

bool Shape::operator==(const Shape& shOther) const{
    return _center == shOther._center;
}

bool Shape::operator!=(const Shape& shOther) const{
    return !(*this == shOther);
}