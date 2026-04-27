#include "Fixed.hpp"

class Point
{
private:
	Fixed const _x;
	Fixed const _y;
public:
	Point();
	Point(float const x, float const y);
	Point(const Point& p);
	Point&	operator=(const Point& other);
	~Point();
	Fixed	getX() const;
	Fixed	getY() const;
};


bool bsp( Point const a, Point const b, Point const c, Point const point);