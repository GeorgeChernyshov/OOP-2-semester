#pragma once
#include "Shape.h"

class Vector : public Shape
{
private:
	double x, y;
public:
	Vector(double c1, double c2);
	Vector();
	Vector(const Vector& v);
	~Vector();
	void Move(Vector& v);
	double Area();
	double getX();
	double getY();
	void Out();

	Vector& operator= (const Vector& v);
	const Vector operator+ (const Vector& v);
	Vector& operator+= (const Vector& v);
	double operator!();
	bool operator> (const Vector& v);
	bool operator== (const Vector& v);
	friend const Vector operator* (const Vector& v, const double d);
	friend const Vector operator* (const double d, const Vector& v);
	friend const double operator* (const Vector& left, const Vector& right);
};

