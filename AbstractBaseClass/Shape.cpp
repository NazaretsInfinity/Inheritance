#include"Shape.h"
		Geometry::Shape::Shape(SHAPE_TAKE_PARAMETERS) : color(color)
		{
			set_start_x(start_x);
			set_start_y(start_y);
			set_line_width(linewidth);
			count++;
		}
		Geometry::Shape::~Shape() { count--; }
		//INCAPSULATION
		int Geometry::Shape::getCOUNT()
		{
			return count;
		}
		Geometry::Color Geometry::Shape::getCOLOR()const
		{
			return color;
		}
		unsigned int Geometry::Shape::getX()const
		{
			return start_x;
		}
		unsigned int Geometry::Shape::getY()const
		{
			return start_y;
		}
		unsigned int Geometry::Shape::get_linewidth()const
		{
			return linewidth;
		}
		void Geometry::Shape::set_start_x(unsigned int start_x)
		{
			if (start_x < MINX)start_x = MINX;
			if (start_x > MAXX) start_x = MAXX;
			this->start_x = start_x;
		}
		void Geometry::Shape::set_start_y(unsigned int start_y)
		{
			if (start_y < MINY)start_y = MINY;
			if (start_y > MAXY)start_y = MAXY;
			this->start_y = start_y;
		}
		void Geometry::Shape::set_line_width(unsigned int line_width)
		{
			if (line_width < MINLINE)line_width = MINLINE;
			if (line_width > MAXLINE)line_width = MAXLINE;
			this->linewidth = line_width;
		}
		double Geometry::Shape::filtersize(double size)
		{
			if (size < MINSIZE)size = MINSIZE;
			if (size > MAXSIZE)size = MAXSIZE;
			return size;
		}
		void Geometry::Shape::setCOLOR(Color color)
		{
			this->color = color;
		}
		COLORREF Geometry::Shape::setRGB(Color color)const
		{
			switch (color)
			{
			case CONSOLE_BLUE: return 0xFF0000; break;
			case CONSOLE_RED: return 0x0000FF; break;
			case CONSOLE_GREEN: return 0x00FF00; break;
			case CONSOLE_YELLOW: return 0x0000FFFF; break;
			}
		}
		void Geometry::Shape::info()const
		{

			cout << "Area of figure: " << area() << endl;
			cout << "Perimeter of figure: " << perimeter() << "\n\n";
			draw();
		}
		int Geometry::Shape::count = 0;

