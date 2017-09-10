#pragma once
#include "Shape.h"

class Vector : public Shape
{
private:
	double x, y;	// Координаты вектора на плоскости
public:
	//========== Три конструктора
	Vector(double c1, double c2);
	Vector();							// Default
	Vector(const Vector& v);
	~Vector();
	void Move(Vector& v);
	double Area();
										//====== Переопределение операций =====//
	Vector& operator= (const Vector& v);	// Присвоение
	const Vector operator+ (const Vector& v);
	Vector& operator+= (const Vector& v);
	double operator!();
	bool operator> (const Vector& v);
	bool operator== (const Vector& v);
	double getX();
	double getY();
	friend const Vector operator* (const Vector& v, const double d);
	friend const Vector operator* (const double d, const Vector& v);
	friend const double operator* (const Vector& left, const Vector& right);
	void Out();
};

