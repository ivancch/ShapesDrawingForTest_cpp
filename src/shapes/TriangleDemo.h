

#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include <iostream>
#include <cmath>
#include "Shape.h"
#include "../Point2D.h"
#include "../myDrawingLib.h"

/**
 * The whole class is written in a header file because the example
 * will not be used in real projects and was created
 * for demonstration purposes only.
 */
class TriangleDemo : public Shape
{
private:
	float m_a;
	float m_b;
	float m_c;
public:
	/**
	 *
	 * @param[in] a First side of the triangle.
	 * @param[in] b Second side of the triangle.
	 * @param[in] c Third side of the triangle.
	 * @param[in] point Coordinates to start drawing the triangle.
	 */
	TriangleDemo (const float a, const float b, const float c, Point2D *point) :
		Shape(point)
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

	float getA() const { return m_a; }
	void setA(float a) { m_a = a;}

	float getB() const { return m_b; }
	void setB(float b) { m_b = b; }

	float getC() const { return m_c; }
	void setC(float c) { m_c = c; }

	/**
	 * Drawing a triangle from a given coordinate point.
	 * First to the right, then up, then to the initial coordinates.
	 *
	 * The sides and coordinates of the triangle are set
	 * in the constructor when the object is created.
	 */
	void draw() const override
	{
		//Create context and pen.
		myDrawingLib::Context context;
		// Сalculate the cos and sin of the angle to build a triangle.
		float cosA = ((m_a*m_a)+(m_b*m_b)-(m_c*m_c))/(2*m_a*m_b);
		float sinA = sqrt(1-cosA*cosA);
		// Get starting coordinates.
		int initX = this->getCoordinates()->getX();
		int initY = this->getCoordinates()->getY();
		// Move start point to draw start coordinates.
		MoveToEx(context.getHDC(), initX, initY, NULL);
		// Drawing a triangle along lines.
		// Inverted "y" coordinate for familiar perception.
		LineTo(context.getHDC(), initX+m_a, 		 initY);
		LineTo(context.getHDC(), initX-m_b*cosA+m_a, initY-m_b*sinA);
		LineTo(context.getHDC(), initX, 			 initY);
	}

	virtual ~TriangleDemo() override
	{
	}


	/**
	 * Operator overload function "<<"
	 * to send Triangle to the output stream.
	 */
	friend std::ostream& operator<<(std::ostream &out, const TriangleDemo &triangle)
	{
		return out << "Triangle( a=" << triangle.m_a
				   << " b=" << triangle.m_b
				   << " c=" << triangle.m_c
				   << " ) Coordinates" << triangle.getCoordinates();
	}

};


#endif /* TRIANGLE_H_ */


















