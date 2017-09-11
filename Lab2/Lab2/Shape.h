#pragma once

class Vector;

class Shape
{
public:
	Shape();
	~Shape() { Count--; }
	static void PrintCount();
	static int GetCount();
	virtual void Move(Vector& v) { return; }
	virtual void Out() { return; }
	virtual double Area() { return 0.0; }
	static Shape* shapes[1000];
protected:
	static int Count;
};

