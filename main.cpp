#include <string>
#include "Ellipse.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Shape.h"
#include "Coord.h"
#include "Shape.h"
#include "LinkedListT.h"
#include <iostream>

int main() {
    std::cout << ".......................running testLinkedListDbl...." <<std::endl << std::endl;
    
    DblLinkedList<int> primes;
    primes.push_back( 2 );
    primes.push_back( 3 );
    primes.push_back( 5 );
    primes.push_back( 7 );
    primes.push_back( 11 );
    primes.push_back( 13 );
    primes.push_back( 17);
    primes.push_back( 19);
    
    DblLinkedList<std::string> caesarQuotes;
    caesarQuotes.push_back("men" );
    caesarQuotes.push_back("in" );
    caesarQuotes.push_back("general" );
    caesarQuotes.push_back("are" );
    caesarQuotes.push_back("quick" );
    caesarQuotes.push_back("to" );
    caesarQuotes.push_back("believe" );
    caesarQuotes.push_back("that" );
    caesarQuotes.push_back("which" );
    caesarQuotes.push_back("they" );
    caesarQuotes.push_back("wish" );
    caesarQuotes.push_back("to" );
    caesarQuotes.push_back("be" );
    caesarQuotes.push_back("true" );
    
    DblLinkedList<Shape const&> shapes;
    shapes.push_back(Circle( 3) );
    shapes.push_back(Rectangle( Coord (-1, 2), 3, 5));
    shapes.push_back(Triangle (3, 4, 5));
    shapes.push_back(Ellipse (10, 20));
    shapes.push_back(Parallelogram(Coord(-4, -2), 10, 20, 30));
    
    std::cout <<"prime numbers: " <<primes << std::endl << std::endl;
    std::cout << "julias caesar quotes: " << caesarQuotes << std::endl << std::endl;
    std::cout << "shapes: " <<shapes << std::endl << std::endl;
    while(!shapes.empty()) {
        Shape const& shape = shapes.pop_front();
        std::cout << shape.name() <<" has area: " <<shape.area() << " and perimeter: " << shape.perimeter() << std::endl;
    }
    std::cout << std::endl << ".............done" << std::endl;
    return 0;
}

