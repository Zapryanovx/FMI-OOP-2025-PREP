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
	return Point{x, y};
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

struct Triangle
{
	Point A;
	Point B;
	Point C;
};

Triangle readTriangle()
{
	Point A = readPoint();
	Point B = readPoint();
	Point C = readPoint();

	return Triangle{ A, B, C };
}

void printTriangle(const Triangle& triangle)
{
	printPoint(triangle.A);
	printPoint(triangle.B);
	printPoint(triangle.C);
}

double trianglePer(double a, double b, double c)
{
	return a + b + c;
}

double triangleArea(const Triangle& triangle)
{
	double a = distance(triangle.B, triangle.C);
	double b = distance(triangle.C, triangle.A);
	double c = distance(triangle.A, triangle.B);

	double halfPer = trianglePer(a, b, c) / 2;
	
	return sqrt(halfPer * (halfPer - a) * (halfPer - b) * (halfPer - c));
}

void getTypeOfTriangle(const Triangle& triangle)
{
	double a = distance(triangle.B, triangle.C);
	double b = distance(triangle.C, triangle.A);
	double c = distance(triangle.A, triangle.B);

	if (a == b && b == c)
	{
		std::cout << "equilateral" << std::endl;
	}

	else if (a != b && b != c)
	{
		std::cout << "sided" << std::endl;
	}

	else
	{
		std::cout << "isosceles" << std::endl;
	}
}

void sortTriangles(Triangle* triangles, int n)
{
	double* areas = new double[n];
	for (int i = 0; i < n; i++)
	{
		areas[i] = triangleArea(triangles[i]);
	}

	for (int i = 0; i < n - 1; i++)
	{
		int minArea = i;

		for (int j = i + 1; j < n; j++)
		{
			if (areas[j] < areas[minArea])
			{
				minArea = j;
			}
		}

		if (minArea != i)
		{
			std::swap(triangles[i], triangles[minArea]);
			std::swap(areas[i], areas[minArea]);
		}
	}

	delete[] areas;
}


int main()
{
	int n;
	std::cin >> n;

	Triangle* triangles = new Triangle[n];

	for (int i = 0; i < n; i++)
	{
		triangles[i] = readTriangle();
	}

	sortTriangles(triangles, n);

	for (int i = 0; i < n; i++)
	{
		printTriangle(triangles[i]);
	}

	return 0;
}