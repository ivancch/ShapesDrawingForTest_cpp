

#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include <iostream>
#include "Shape.h"
#include "../Point2D.h"
#include "../myDrawingLib.h"

/**
 * The whole class is written in a header file because the example
 * will not be used in real projects and was created
 * for demonstration purposes only.
 */
class RectangleDemo : public Shape
{
private:
	float m_a;
	float m_b;
public:
	/**
	 * @param[in] a First side of the rectangle.
	 * @param[in] b Second side of the rectangle.
	 * @param[in] point Coordinates to start drawing the rectangle.
	 */
	RectangleDemo(const float a, const float b, Point2D *point) :
		Shape(point), m_a(a), m_b(b)
	{
	}
	
	float getA() const { return m_a; }
	void setA(float a) { m_a = a; }

	float getB() const { return m_b; }
	void setB(float b) { m_b = b; }

	/**
	 * Draw a rectangle from a given coordinate point. First to the right,
	 * then up, then to the left, then to the original coordinates.
	 *
	 * The sides and coordinates of the rectangle are set in
	 * the constructor when the object is created.
	 */
	void draw() const override
	{
		//Create context and pen.
		myDrawingLib::Context context;
		// Get starting coordinates.
		int initX = this->getCoordinates()->getX();
		int initY = this->getCoordinates()->getY();
		// Move start point to draw start coordinates.
		MoveToEx(context.getHDC(), initX, initY, NULL);
		//Drawing a rectangle along lines
		//Inverted "y" coordinate for familiar perception.
		LineTo(context.getHDC(), initX+m_a, initY);
		LineTo(context.getHDC(), initX+m_a, initY-m_b);
		LineTo(context.getHDC(), initX, initY-m_b);
		LineTo(context.getHDC(), initX, initY);
	}

	virtual ~RectangleDemo() override
	{
	}
	
	/**
	 * Operator overload function "<<"
	 * to send Rectangle to the output stream.
	 */
	friend std::ostream& operator<<(std::ostream &out, const RectangleDemo &rectangle)
	{
		return out << "Rectangle( a=" << rectangle.m_a
				   << " b=" << rectangle.m_b
				   << " ) Coordinates" << rectangle.getCoordinates();
	}


};




#endif /* RECTANGLE_H_ */
