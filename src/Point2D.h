
#ifndef POINT2D_H_
#define POINT2D_H_

#include <iostream>

/**
 * This class is the simplest representation of a point in 2D graphics.
 */


class Point2D
{
private:
	int m_x = 0;
	int m_y = 0;
public:
	/**
	 * Constructor for creating a 2D point.
	 * @param[in] x
	 * @param[in] y
	 */
	Point2D(const int x, const int y) :
		m_x(x), m_y(y)
	{

	}


	/**
	 * Operator overload function "<<"
	 * to send Point2D to the output stream.
	 */
	friend std::ostream& operator<<(std::ostream &out, const Point2D &point)
	{
		return out << "Point(" << point.m_x << ", "
							   << point.m_y << ")";
	}
};



#endif /* POINT2D_H_ */
