#include "Point.hpp"
 

// ( (p_x - v2_x) * (v1_y - v2_y) ) - (v1_x - v2_x) * (p_y - v2_y))

static Fixed sign(Point const& p, Point const& v1, Point const& v2) 
{
	return (((p.getX() - v2.getX()) * (v1.getY() - v2.getY())) - ((v1.getX() - v2.getX()) * (p.getY() - v2.getY())));
}


bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	i, j, k;
	i = sign(point, a, b);
	j = sign(point, b, c);
	k = sign(point, c, a);

	if (i == 0 || j == 0 || k == 0)
		return false;
	if (i > 0 && j > 0 && k > 0)
		return true;
	if (i < 0 && j < 0 && k < 0)
		return true;
	return false;
}
