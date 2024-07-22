#pragma once
#include"Shape.h"
namespace Geometry
{
	class EquilateralTriangle : public Geometry::Triangle
	{
		double side;
	public:
		EquilateralTriangle(double side, SHAPE_TAKE_PARAMETERS);
		~EquilateralTriangle();
		double getSIDE()const;
		void setSIDE(double side);
		double getHEIGHT()const override;
		double area()const override;
		double perimeter()const override;
		void draw()const override;
		void info()const override;
	};
	class IsoscelesTriangle : public Geometry::Triangle
	{
		double side, latside;
	public:
		IsoscelesTriangle(double side, double latside, SHAPE_TAKE_PARAMETERS);
		~IsoscelesTriangle();
		void setSIDE(double side);
		void setLATSIDE(double latside);
		double getHEIGHT()const override;
		double perimeter()const override;
		double area()const override;
		void draw()const override;
		void info()const override;
	};
	class RectangularTriangle :public Geometry::Triangle
	{
		double fside, sside;
	public:
		RectangularTriangle(double fside, double sside, SHAPE_TAKE_PARAMETERS);
		~RectangularTriangle();
		void setFSIDE(double fside);
		void setSSIDE(double sside);
		double  getHYPOTENUS()const;
		double getHEIGHT()const override;
		double perimeter()const override;
		double area()const override;
		void draw()const override;
		void info()const override;
	};
}