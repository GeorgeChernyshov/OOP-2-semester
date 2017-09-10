#include "stdafx.h"
#include "Shape.h"

int Shape::Count = 0;

Shape::Shape()
{
	Count++;
}


Shape::~Shape()
{
	Count--;
}

void Shape::PrintCount() {
	cout << "Now there are " << Count << " objects\n";
}