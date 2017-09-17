#pragma once
#include "Shape.h"
#include "Vector.h"

class Rect : public Shape
{
public:
	Rect(Vector& v1 = Vector(0.0, 0.0), Vector& v2 = Vector(0.0, 0.0)) : ptLT(v1), ptRB(v2) {}
	Rect(double left, double top, double right, double bottom) : ptLT(Vector(left, top)), ptRB(Vector(right, bottom)) {}

	void Inflate(double x = 1);
	void Inflate(double a, double b);
	void Inflate(double left, double top, double right, double bottom);
	void Move(Vector& v);
	ostream& Out(ostream& os = cout) const;
	double Area();

	Rect& operator=(const Rect& r);
	friend const bool operator<(const Rect& left, const Rect& right);
	friend ostream& operator<<(ostream& os, const Rect& v);
private:
	Vector ptLT;
	Vector ptRB;
};

