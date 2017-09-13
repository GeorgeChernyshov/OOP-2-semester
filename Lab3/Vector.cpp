#include "stdafx.h"
#include "Vector.h"

Vector::Vector(double c1, double c2)
{
	x = c1;   y = c2;
	shapes[this->GetCount()] = this;
	Count++;
}

Vector::Vector()
{
	x = y = 0.;
	shapes[this->GetCount()] = this;
	Count++;
}

Vector::Vector(const Vector& v) {
	*this = v;
	shapes[this->GetCount()] = this;
	Count++;
}

Vector::~Vector() { Count--; }

double Vector::getX() { return x; }

double Vector::getY() { return y; }

void Vector::Move(Vector& v) { *this += v; }

double Vector::Area() { return 0; }

void Vector::Out() { cout << "Vector:  x = " << x << ",  y = " << y << endl; }

Vector& Vector::operator= (const Vector& v)	
{
	if (this == &v)
		return *this;
	x = v.x;
	y = v.y;
	return *this;
}

const Vector Vector::operator+ (const Vector& v) { return Vector(x + v.x, y + v.y); }

double Vector::operator!() {
	double length = sqrt(x*x + y*y);
	return length;
}

bool Vector::operator> (const Vector& v) {
	return (sqrt(x*x + y*y) > sqrt(v.x*v.x + v.y*v.y)) ? 1 : 0;
}

bool Vector::operator< (const Vector& v) {
	return (sqrt(x*x + y*y) < sqrt(v.x*v.x + v.y*v.y)) ? 1 : 0;
}

bool Vector::operator== (const Vector& v) {
	return (abs(x - v.x) < DBL_EPSILON && abs(y - v.y) < DBL_EPSILON) ? 1 : 0;
}

const Vector operator* (const Vector& v, const double d) {
	return Vector(v.x*d, v.y*d);
}

const Vector operator*(const double d, const Vector& v) { return Vector(v.x*d, v.y*d); }

const double operator* (const Vector& left, const Vector& right) {
	return ((left.x * right.x) + (left.y * right.y));
}

Vector& Vector::operator+= (const Vector& v) {
	*this = *this + v;
	return *this;
}