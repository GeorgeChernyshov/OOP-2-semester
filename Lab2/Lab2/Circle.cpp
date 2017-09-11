#include "stdafx.h"
#include "Circle.h"
#include <math.h>

void Circle::Move(Vector& v) {
	ptCntr += v;
}

double Circle::Area() {
	return (3.14159265358979323846 * R * R);
}

void Circle::Out() {
	cout << "Circle(" << ptCntr.getX() << ", " << ptCntr.getY() << ", " << R << ")\n";
}