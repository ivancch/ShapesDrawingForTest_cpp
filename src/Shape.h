

#ifndef SHAPE_H_
#define SHAPE_H_

#include "Point2D.h"

/**
 * Interface class "Shape" for drawing geometric shapes.
 */
class Shape
{
private:
	Point2D m_coordinates;

protected:
	/**
	 * Abstract shape constructor with initial coordinates
	 * @param[in] point Initial coordinates of geometric shape.
	 */
	Shape(Point2D point) :
		m_coordinates(point)
	{

	}

	Point2D getCoordinates() { return m_coordinates; }
	void setCoordinates(const Point2D coordinates) { m_coordinates = coordinates; }

	/**
	 * An abstract method for drawing geometric objects on the screen.
	 * For each shape is defined differently.
	 */
	virtual void drow() const = 0;

public:
	virtual ~Shape()
	{

	}
};



#endif /* SHAPE_H_ */
