#pragma once
#include "Shape.h"
#include "Vector.h"

class Circle : public Shape
{
public:
	Circle(double r = 0.) : ptCntr(Vector(0.0, 0.0)), R(r) {
		shapes[this->GetCount()] = this; 
		Count++; 
	}
	Circle(Vector& v, double r = 0.) : ptCntr(v), R(r) { 
		shapes[this->GetCount()] = this; Count++; 
	}
	Circle(double x, double y, double r = 0.) : ptCntr(Vector(x, y)), R(r) { 
		shapes[this->GetCount()] = this; Count++; 
	}
	~Circle() { Count--; };
	
	void Move(Vector& v);
	void Out();
	double Area();
private:
	Vector ptCntr;
	double R;
};

