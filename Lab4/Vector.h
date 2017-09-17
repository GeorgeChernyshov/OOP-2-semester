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
	double getX() const;
	double getY() const;
	void setX(double nx);
	void setY(double ny);
	ostream& Out(ostream& os = cout) const;

	Vector& operator= (const Vector& v);
	
	Vector& operator+= (const Vector& v);
	double operator!();
	bool operator> (const Vector& v);
	friend const Vector operator+ (const Vector& left, const Vector& right);
	friend bool operator== (const Vector& left, const Vector& right);
	friend ostream& operator<<(ostream& os, const Vector& v);
	friend const Vector operator* (const Vector& v, const double d);
	friend const Vector operator* (const double d, const Vector& v);
	friend const double operator* (const Vector& left, const Vector& right);
	friend const bool operator< (const Vector& left, const Vector& right);
};

