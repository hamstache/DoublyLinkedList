#ifndef _Coord
#define _Coord
#include "LinkedListT.h"

#include <iostream>
using namespace std;

class Coord{
public:
    Coord();
    Coord(double x, double y);
    
    double& x(); //read-write reference to _x
    double x() const; //read-only copy of _x
    
    double& y(); //read-write reference to _y
    double y() const; //read-only copy of _y
    
    friend ostream& operator<<(ostream& os, const Coord& coord);
    
    bool operator!=(const Coord& cOther) const;
    bool operator==(const Coord& cOther) const;
    
private:
    double _x;
    double _y;
    
};

#endif