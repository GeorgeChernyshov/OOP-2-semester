#pragma once
#include <vector>
#include "Vector.h"

class Shape
{
public:
	Shape();
	~Shape();
	static void PrintCount();
	virtual void Move(Vector& v);
	virtual void Out();
	virtual double Area();
protected:
	static int Count;
private:
	static vector<Shape*> shapes;
};

