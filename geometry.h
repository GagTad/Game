#pragma once

#include <cmath>
#include <type_traits>
#include <vector>
#include <algorithm> // std::swap, std::sort 

//miajn doub;e tiperi het hamematutyun aneluc
const double ESP = 1e-9;


template<typename T>
struct Vector 
{
	T dx, dy;

	Vector() : dx(0), dy(0) {}
	Vector(T dx_val, T dy_val) : dx(dx_val), dy(dy_val) {}

};



//skalyar artadryal
template <typename T>
T dotProduct(const Vector<T>& v1, const Vector<T>& v2)
{
	return v1.dx * v2.dx + v1.dy * v2.dy;
}

//2d vectorakan artadryal

template <typename T>
T crossProduct(const Vector<T>& v1, const Vector<T>& v2)
{
	return v1.dx * v2.dy - v1.dy * v2.dx;
}

template<typename T>
T magnitudeSq(const Vector<T>& v) 
{
	return v.dx * v.dx + v.dy * v.dy;
}

template<typename T >
T magnitude(const Vector<T>& v)
{
	return std::sqrt(static_cast<double>(magnitudeSq(v)));
}

//vector + vector
template<typename T>
Vector<T> operator+(const Vector<T>& v1, const Vector<T>& v2)
{
	return Vector<T>(v1.dx + v2.dx, v1.dy + v2.dy);
}

//vector - vector
template<typename T>
Vector<T> operator-(const Vector<T>& v1, const Vector<T>& v2)
{
	return Vector<T>(v1.dx - v2.dx, v1.dy - v2.dy);
}

//vector * scalar	
template<typename T>	
Vector<T> operator*(const Vector<T>& v, T scalar)
{
	return Vector<T>(v.dx * scalar, v.dy * scalar);
}

//scalar * vector
template<typename T>
Vector<T> operator*(T scalar, const Vector<T>& v)
{
	return Vector<T>(v.dx * scalar, v.dy * scalar);
}

//vector / scalar
template<typename T>
Vector<T> operator/(const Vector<T>& v, T scalar)
{
	return Vector<T>(v.dx / scalar, v.dy / scalar);
}

template<typename T>
struct Point
{
	T x, y;

	Point() : x(0), y(0) {}
	Point(T x_val, T y_val) : x(x_val), y(y_val) {}
};

//Point - Point = Vector
template<typename T>
Vector<T> operator-(const Point<T>& p1, const Point<T>& p2)
{
	return Vector<T>(p1.x - p2.x, p1.y - p2.y);
}

//Point + Vector = Point
template<typename T>
Point<T> operator+(const Point<T>& p, const Vector<T>& v)
{
	return Point<T>(p.x + v.dx, p.y + v.dy);
}

//Point - Vector = Point
template<typename T>
Point<T> operator-(const Point<T>& p, const Vector<T>& v)
{
	return Point<T>(p.x - v.dx, p.y - v.dy);
}


//Segment
template<typename T>
struct Segment
{
	Point<T> p1, p2;

	Segment() {}
	Segment(const Point<T>& point1, const Point<T>& point2) : p1(point1), p2(point2) {}

	double lenght() const
	{
		return magnitude(p2 - p1);
	}
};




//Line
template<typename T>
struct Line
{
	Point<T> p0; //pouint
	Vector<T> v; //uxxutyun

	Line() {}
	Line(const Point<T>& p0_val, const Vector<T>& v_val) : p0(p0_val), v(v_val) {}
	Line(const Point<T>& p1, const Point<T>& p2) : p0(p1), v(p2 - p1) {}
};


//Ray
template<typename T>
struct Ray
{
	Point<T> p0; //point
	Vector<T> v; //uxxutyun

	Ray() {}
	Ray(const Point<T>& p0_val, const Vector<T>& v_val) : p0(p0_val), v(v_val) {}
	
};

template<typename T>
Point<T> getPointAt(const Line<T>& l, double t)
{
	return l.p0 + (l.v * t);

}

template<typename T>
Point<T> getPointAt(const Ray<T>& r, double t)
{
	return r.p0 + (r.v * t);//t >= 0
}

template<typename T>
Point<T> getPointAt(const Segment<T>& s, double t)
{
	return s.p1 + ((s.p2 - s.p1) * t);//t [0,1]
}


//Line from Segment
template<typename T>
Line<T> lineFromSegment(const Segment<T>& s)
{
	return Line<T>(s.p1, s.p2);
}



//Polygon
template<typename T>
struct Polygon
{
	std::vector<Point<T>> vertices;

	Polygon() {}
	Polygon(const std::vector<Point<T>>& verts) : vertices(verts) {}


	void addvertexs(const Point<T>& p)
	{
		vertices.push_back(p);
	}

	size_t size() const
	{
		return vertices.size();
	}

};

template<typename T>
double perimeter(const Polygon<T>& poly)
{
	double p = 0.0;
	size_t n = poly.size();
	if (n < 2) return p;
	for (size_t i = 0; i < n; ++i)
	{
		const Point<T>& p1 = poly.vertices[i];
		const Point<T>& p2 = poly.vertices[(i + 1) % n];
		p += magnitude(p2 - p1);
	}
	return p;
}

template<typename T>
T signedArea(const Polygon<T>& poly)
{
	T a = 0;
	size_t n = poly.size();
	if (n < 3) return a; 
	for (size_t i = 0; i < n; ++i)
	{
		const Point<T>& p1 = poly.vertices[i];
		const Point<T>& p2 = poly.vertices[(i + 1) % n];
		a += (p1.x * p2.y) - (p2.x * p1.y);
	}
	return a;
}

template<typename T>
int orientation(const Point<T>& p, const Point<T>& q, const Point<T>& r)
{
	Vector <T> v_pq = q - p;
	Vector <T> v_pr = r - p;

	T val = crossProduct(v_pq, v_pr);
	if constexpr (std::is_floating_point<T>::value) {
		if (std::abs(val) < ESP) return 0; // collinear
	}
	else {
		if (val == 0) return 0; // collinear
	}
	return (val > 0) ? 1 : -1; // 1 CWW -1 CW
}



template <typename T>
bool on_segment(const Point<T>& p, const Point<T>& q, const Point<T>& r) {
	return (q.x <= std::max(p.x, r.x) && q.x >= std::min(p.x, r.x) &&
		q.y <= std::max(p.y, r.y) && q.y >= std::min(p.y, r.y));
}

template <typename T>
bool do_intersect(const Segment<T>& s1, const Segment<T>& s2) {
	Point<T> p1 = s1.p1, q1 = s1.p2;
	Point<T> p2 = s2.p1, q2 = s2.p2;


	int o1 = orientation(p1, q1, p2);
	int o2 = orientation(p1, q1, q2);
	int o3 = orientation(p2, q2, p1);
	int o4 = orientation(p2, q2, q1);


	if (o1 != 0 && o2 != 0 && o3 != 0 && o4 != 0) {
		return (o1 != o2) && (o3 != o4);
	}

	
	if (o1 == 0 && on_segment(p1, p2, q1)) return true;
	if (o2 == 0 && on_segment(p1, q2, q1)) return true;
	if (o3 == 0 && on_segment(p2, p1, q2)) return true;
	if (o4 == 0 && on_segment(p2, q1, q2)) return true;


	return false;
}






template <typename T>
Polygon<T> convex_hull(std::vector<Point<T>>& points) {
	if (points.size() < 3) {
		
		return Polygon<T>(points);
	}


	int p0_idx = 0;
	for (size_t i = 1; i < points.size(); ++i) {
		if (points[i].y < points[p0_idx].y ||
			(points[i].y == points[p0_idx].y && points[i].x < points[p0_idx].x)) {
			p0_idx = i;
		}
	}
	
	std::swap(points[0], points[p0_idx]);
	Point<T> p0 = points[0];

	std::sort(points.begin() + 1, points.end(),
		[&p0](const Point<T>& p1, const Point<T>& p2) {
			int o = orientation(p0, p1, p2);
			if (o == 0) {
			
				return magnitude_sq(p1 - p0) < magnitude_sq(p2 - p0);
			}

			return (o > 0);
		}
	);


	std::vector<Point<T>> hull_stack;
	hull_stack.push_back(points[0]);
	hull_stack.push_back(points[1]);
	hull_stack.push_back(points[2]);


	for (size_t i = 3; i < points.size(); ++i) {
	
		while (hull_stack.size() >= 2 &&
			orientation(hull_stack[hull_stack.size() - 2], hull_stack.back(), points[i]) <= 0) {
			hull_stack.pop_back();
		}
		hull_stack.push_back(points[i]);
	}

	return Polygon<T>(hull_stack);
}