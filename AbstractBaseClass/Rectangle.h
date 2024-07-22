#pragma once
#include"Shape.h"
namespace Geometry
{
	class Rectangle :public Geometry::Shape
	{
		double width, height;
	public:
		Rectangle(double width, double height, SHAPE_TAKE_PARAMETERS);
		~Rectangle();
		void setWIDTH(double width);
		void setHEIGHT(double height);
		double area()const override;
		double perimeter()const override;
		void draw()const override;

		void info()const override;
	};
	class Square :public Rectangle
	{
	public:
		Square(double side, SHAPE_TAKE_PARAMETERS);
		~Square();
	};
}

