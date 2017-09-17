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

double Vector::getX() const { return x; }

double Vector::getY() const { return y; }

void Vector::setX(double nx) {
	x = nx;
	return;
}

void Vector::setY(double ny) {
	y = ny;
	return;
}

void Vector::Move(Vector& v) { *this += v; }

double Vector::Area() { return 0; }

ostream& Vector::Out(ostream& os) const {
	os << "Vector:  x = " << x << ",  y = " << y << endl; 
	return os;
}

Vector& Vector::operator= (const Vector& v)	
{
	if (this == &v)
		return *this;
	x = v.x;
	y = v.y;
	return *this;
}

const Vector operator+ (const Vector& left, const Vector& right) { return Vector(left.getX() + right.getX(), left.getY() + right.getY()); }

double Vector::operator!() {
	double length = sqrt(x*x + y*y);
	return length;
}

bool Vector::operator> (const Vector& v) {
	return (sqrt(x*x + y*y) > sqrt(v.x*v.x + v.y*v.y));
}

const bool operator< (const Vector& left, const Vector& right) {
	return (sqrt(left.x*left.x + left.y*left.y) < sqrt(right.x*right.x + right.y*right.y));
}

bool operator== (const Vector& left, const Vector& right) {
	return (abs(left.x - right.x) < DBL_EPSILON && abs(left.y - right.y) < DBL_EPSILON) ? 1 : 0;
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

ostream& operator<<(ostream& os, const Vector& v) {
	v.Out(os);
	return os;
}