#pragma once
#include "Shape.h"
#include "Vector.h"

class Rect : public Shape
{
public:
	Rect(Vector& v1 = Vector(0.0, 0.0), Vector& v2 = Vector(0.0, 0.0)) : ptLT(v1), ptRB(v2) {
		shapes[this->GetCount()] = this; 
		Count++;  
	}

	Rect(double left, double top, double right, double bottom) : ptLT(Vector(left, top)), ptRB(Vector(right, bottom)) { 
		shapes[this->GetCount()] = this; 
		Count++;  
	}

	void Inflate(double x = 1);
	void Inflate(double a, double b);
	void Inflate(double left, double top, double right, double bottom);
	void Move(Vector& v);
	void Out();
	double Area();

	Rect& operator=(const Rect& r);
private:
	Vector ptLT;
	Vector ptRB;
};

