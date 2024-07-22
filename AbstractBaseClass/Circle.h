#pragma once
#include"Shape.h"
namespace Geometry
{
	class Circle :public Shape
	{
		double radius;
	public:
		Circle(double radius, SHAPE_TAKE_PARAMETERS);
		~Circle();
		double getRADIUS()const;
		void setRADIUS(double radius);
		double perimeter()const override;
		double area()const override;
		void info()const override;
		void draw()const override;
	};
}
