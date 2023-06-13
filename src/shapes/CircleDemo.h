
#ifndef CIRCLE_H_
#define CIRCLE_H_

#define _USE_MATH_DEFINES
#include <math.h>

#include <iostream>
#include "Shape.h"
#include "../Point2D.h"
#include "../myDrawingLib.h"

/**
 * The whole class is written in a header file because the example
 * will not be used in real projects and was created
 * for demonstration purposes only.
 */
class CircleDemo : public Shape
{
private:
	float m_radius;
	int m_polygons = 10;
public:
	/**
	 * The number of polygons is set to default = 10
	 * @param[in] radius Сircle radius.
	 * @param[in] point Coordinates to start drawing the сircle.
	 */
	CircleDemo(const float radius, Point2D *point) :
		Shape(point), m_radius(radius)
	{
	}

	/**
	 * Creates a circle with the given radius and the given number of polygons.
	 * @param[in] radius Сircle radius.
	 * @param[in] The number of polygons with which the circle will be drawn.
	 * 			  min = 5
	 * @param[in] point Coordinates to start drawing the сircle.
	 */
	CircleDemo(const float radius, int polygons, Point2D *point) :
		Shape(point), m_radius(radius)
	{
		if (polygons < 5)
		{
			std::cout << "Drawing a circle with fewer polygons"
					" than five is impossible. Set five polygons.\n";
			m_polygons = 5;
		}
		else
			m_polygons = polygons;

	}

	float getRadius() const { return m_radius; }
	void setRadius(float radius) { m_radius = radius;}

	int getPolygons() const { return m_polygons; }
	void setPolygons(int polygons) { m_polygons = polygons; }

	/**
	 * Draws a circle from the given coordinate point as the center.
	 * Drawing is carried out using polygons, the number
	 * of which is specified when creating an object.
	 *
	 * The sides and coordinates of the circle are
	 * set in the constructor when the object is created.
	 */
	void draw() const override
	{
		//Create context and pen.
		myDrawingLib::Context context;
		// Get starting coordinates.
		int initX = this->getCoordinates()->getX();
		int initY = this->getCoordinates()->getY();
		// Сreate the variable angle to drawing a circle.
		double angle = 0;
		// Move start point to draw start coordinates.
		MoveToEx(context.getHDC(), initX+m_radius, initY, NULL);
		//Drawing a circle with polygons.
		//Inverted "y" coordinate for familiar perception.
		for(int i = 0; i < m_polygons+1; i++)
		{
			LineTo(context.getHDC(),
				initX + m_radius * cos(angle * M_PI / 180),
				initY + m_radius * sin(angle * M_PI / 180));
			angle = angle + 360.0/m_polygons;
		}
	}

	/**
	 * Operator overload function "<<"
	 * to send Circle to the output stream.
	 */
	friend std::ostream& operator<<(std::ostream &out, const CircleDemo &circle)
	{
		return out << "Rectangle( radius=" << circle.m_radius
				   << " ) Coordinates" << circle.getCoordinates();
	}

};

#endif /* CIRCLE_H_ */
