#include <iostream>

struct Point
{
	double x;
	double y;
};

Point readPoint()
{
	double x, y;
	std::cin >> x >> y;
	return Point{ x, y };
}

void printPoint(const Point& p)
{
	std::cout << p.x << " " << p.y << std::endl;
}

double distance(const Point& lhs, const Point& rhs)
{
	return sqrt((lhs.x - rhs.x) * (lhs.x - rhs.x)
		+ (lhs.y - rhs.y) * (lhs.y - rhs.y));
}

double distanceToCenter(const Point& p)
{
	Point center{ 0, 0 };
	return distance(p, center);
}

int main()
{

	return 0;
}