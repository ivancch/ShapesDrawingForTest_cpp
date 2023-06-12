
#ifndef POINT2D_H_
#define POINT2D_H_

#include <iostream>

/**
 * This class is the simplest representation of a point in 2D graphics.
 */
class Point2D
{
private:
	float m_x = 0;
	float m_y = 0;
public:
	/**
	 * Constructor for creating a 2D point.
	 * @param[in] x
	 * @param[in] y
	 */
	Point2D(const float x, const float y) :
		m_x(x), m_y(y)
	{

	}

	float getX() { return m_x; }
	void setX(float x) { m_x = x; }

	float getY() { return m_y; }
	void setY(float x) { m_y = x; }

	/**
	 * Operator overload function "<<"
	 * to send Point2D to the output stream.
	 */
	friend std::ostream& operator<<(std::ostream &out, const Point2D &point)
	{
		return out << "(" << point.m_x << ", "
							   << point.m_y << ")";
	}
};



#endif /* POINT2D_H_ */
