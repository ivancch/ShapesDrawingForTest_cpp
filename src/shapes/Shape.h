

#ifndef SHAPE_H_
#define SHAPE_H_

#include <iostream>
#include "../Point2D.h"

/**
 * Interface class "Shape" for drawing geometric shapes.
 */


class Shape
{
private:
	Point2D *m_coordinates;
protected:
	/**
	 * Abstract shape constructor with initial coordinates
	 * @param[in] point Initial coordinates of geometric shape.
	 */
	Shape(Point2D *point) :
		m_coordinates(point)
	{
	}

public:
	Point2D* getCoordinates() const { return m_coordinates; }
	void setCoordinates(Point2D *coordinates) { m_coordinates = coordinates; }

	/**
	 * An abstract method for drawing geometric objects on the screen.
	 * For each shape is defined differently.
	 */
	virtual void draw() const = 0;

	virtual ~Shape()
	{
		if (m_coordinates)
			delete m_coordinates;
	}

	/**
	 * Operator overload function "<<"
	 * to send Point2D to the output stream.
	 */
	friend std::ostream& operator<<(std::ostream &out, Shape &shape)
	{
		return shape.outputStream(out);
	}
private:
	virtual std::ostream& outputStream(std::ostream &out)
	{
		return out  << "coordinates " << *this->m_coordinates;;
	}

};


#endif /* SHAPE_H_ */
















