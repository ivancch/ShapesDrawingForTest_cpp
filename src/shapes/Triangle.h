

#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include <iostream>
#include <cmath>
#include "Shape.h"
#include "../Point2D.h"
#include "../myDrawingLib.h"

class Triangle : public Shape
{
private:
	float m_a;
	float m_b;
	float m_c;
public:
	Triangle (const float a, const float b, const float c, Point2D *point1) :
		Shape(point1)
	{
		if ((a > b+c) || (b > a+c) || (c > a+b) || (a==0) || (b==0) || (c==0))
		{
			std::cout << "\nTriangle cannot be created"
					  << "Triangle created a=100, b=100, c=100"
					  << std::endl;
			m_a = 100;
			m_b = 100;
			m_c = 100;
		} else
		{
			m_a = a;
			m_b = b;
			m_c = c;
		}
	}

	void drow() const override
	{
		//Create context and pen.
		myDrawingLib::Context context;
		// Сalculate the cos and sin of the angle to build a triangle.
		float cosA = ((m_a*m_a)+(m_b*m_b)-(m_c*m_c))/(2*m_a*m_b);
		float sinA = sqrt(1-cosA*cosA);
		// Get starting coordinates.
		Point2D* startСoord = this->getCoordinates();
		// Move start point to draw start coordinates.
		MoveToEx(context.getHDC(), startСoord->getX(), startСoord->getY(), NULL);
		// Drawing a triangle along lines.
		// Inverted "y" coordinate for familiar perception.
		LineTo(context.getHDC(), startСoord->getX() + m_a, startСoord->getY());
		LineTo(context.getHDC(),
			   startСoord->getX() - m_b * cosA + m_a,
			   startСoord->getY() - m_b * sinA);
		LineTo(context.getHDC(), startСoord->getX(), startСoord->getY());
	}

	virtual ~Triangle() override
	{
	}


	friend std::ostream& operator<<(std::ostream &out, const Triangle &triangle)
	{
		return out << "Triangle( a=" << triangle.m_a
				   << "b=" << triangle.m_b
				   << "c=" << triangle.m_c
				   << "coordinates" << triangle.getCoordinates();
	}

};


#endif /* TRIANGLE_H_ */


















