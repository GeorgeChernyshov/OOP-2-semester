#include "stdafx.h"
#include "Shape.h"

int Shape::Count = 0;
Shape* Shape::shapes[1000];

Shape::Shape()
{
	shapes[this->GetCount()] = this;
	Count++;
}

void Shape::PrintCount() { cout << "Now there are " << Count << " objects\n"; }

int Shape::GetCount() { return Count; }