#include "stdafx.h"
#include "Rect.h"

Rect& Rect::operator=(const Rect& r) {
	ptLT = r.ptLT;
	ptRB = r.ptRB;
	return *this;
}

void Rect::Inflate(double x) {
	Vector v1(x, x);
	ptRB = ptRB + v1;
	ptLT = ptLT + (-1)*v1;
}

void Rect::Inflate(double a, double b) {
	Vector v1(a, b);
	ptRB = ptRB + v1;
	ptLT = ptLT + (-1)*v1;
}

void Rect::Inflate(double left, double top, double right, double bottom) {
	Vector v1(-left, -top);
	Vector v2(right, bottom);
	ptLT += v1;
	ptRB += v2;
}

void Rect::Move(Vector& v) {
	ptLT += v;
	ptRB += v;
}

double Rect::Area() { return ((ptRB.getX() - ptLT.getX()) * (ptRB.getY() - ptLT.getY())); }

ostream& Rect::Out(ostream& os) const {
	os << "Rect(" << ptLT.getX() << ", " << ptLT.getY() << ", " << ptRB.getX() << ", " << ptRB.getY() << ")\n";
	return os;
}

const bool operator<(const Rect& left, const Rect& right) {
	return (left.ptLT + left.ptRB) < (right.ptLT + right.ptRB);
}

ostream& operator<<(ostream& os, const Rect& r) {
	r.Out(os);
	return os;
}