#define _USE_MATH_DEFINES
#include<iostream>
#include"Rectangle.h"
#include "Triangle.h"
#include "Circle.h"
using namespace std;
#define Figure_check
void main()
{
#ifdef Figure_check
	Geometry::Square square(50, 400, 50, 5, Geometry::Color::CONSOLE_RED);
    square.info();
    Geometry::Rectangle rect{ 150, 80, 400,150, 5, Geometry::Color::CONSOLE_YELLOW};
    rect.info();
	Geometry::EquilateralTriangle tri(80, 600, 200, 5, Geometry::Color::CONSOLE_GREEN);
	tri.info();
	Geometry::IsoscelesTriangle tri2(80, 100, 700, 200, 5, Geometry::Color::CONSOLE_RED);
	tri2.info();
	Geometry::RectangularTriangle tri3(70, 80, 800, 200, 5, Geometry::Color::CONSOLE_YELLOW);
	tri3.info();
	Geometry::Circle circ(40, 400,260,5, Geometry::Color::CONSOLE_BLUE);
	circ.info();

	cout << "Number of shapes: " << Geometry::Shape::getCOUNT() << endl;
#endif
}