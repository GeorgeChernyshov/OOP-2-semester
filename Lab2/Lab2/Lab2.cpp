#include "stdafx.h"
#include "MyString.h"
#include "Rect.h"
#include "Circle.h"

void main()
{
	// Рассмотрите реализацию операции присвоения (operator=) для класса Vector.
	// Объясните назначение условия if (this == &v).
	Vector a(2, 1), b;
	cout << "\tTest Vector operator=\n";
	a.Out();		b.Out();
	a = b;
	cout << "\tTest operator=\n";
	a.Out();          b.Out();
	a = a;
	stop

		// Почему работает следующий код, хотя операция присвоения не вызывается?
		// Убедитесь с помощью отладчика (точки останова).
		Vector c = a;

	c.Out();

	MyString s("Dynamic strings always change their size");
	MyString str;

	str = s;

	cout << "\n\n\tTest MyString operator=\n\n" << str.GetString() << endl;
	stop
	// Вызывается ли эта операция в в этом фрагменте? Почему?
	MyString ss = s;

	MyString h("hello");
	s = h;
	cout << "\tTest operator=\n" << s.GetString() << " " << ss.GetString() << endl;

		cout << "\n\n\tTest Vector operator+\n";

	Vector d;
	Vector a1(3, 2), b1(4, 6);
	d = a1 + b1;

	d.Out();

	stop

	Vector e = a1 + b1;

	cout << "\n\n\tTest Vector copy constructor\n";
	e.Out();

	cout << "\n\n\tTest unary operator!() - \'vector length\'\n";
	cout << "\n |a1| = " << !a1 << endl;

	stop
	
	if (e > a)
	cout << "\n\nVector e is greater than vector a\n";
	if (e == e)
	cout << "\n Vector e is equal to vector e\n";
	else
	cout << "\n\nCould not compare vectors\n";

	cout << "\n\n\tTest operator*()\n";
	Vector v(1,2), w;
	w = 5. * v;
	w.Out();

	w = v * 5.;
	w.Out();

	w = 5 * v * atan(1.);
	w.Out();

	double zero = Vector(1, 0) * Vector(0, 1);
	double four = Vector(2, 0) * Vector(2, 0);
	cout << "Check scalar multiplication: " << zero << " = 0, " << four << " = 4\n";

	// Обоснуйте ваш выбор способа реализации.

	Vector v1 (1,1), v2 (101,101);

	Rect r (v1, v2);

	cout << "\n\n\tTest Rect\n";
	r.Out();

	r = Rect (10, 10, 50, 30);

	r.Out();

	r.Inflate();

	cout << "\n\n\tTest Inflate\n";
	r.Out();

	r.Inflate(2.5);
	r.Out();

	r.Inflate(-2.5, -2.5);
	r.Out();

	r.Inflate(1, 2, -3, 4);
	r.Out();
	
	cout << "\n\n\tTest static members\n";

	Rect::PrintCount();	

	Rect *pv = new Rect;

	pv->PrintCount();		

	delete pv;
	Vector::PrintCount();	

	Vector ar[4];
	ar->PrintCount();		

	Vector *par[4];
	Vector::PrintCount();

	par[0] = new Vector(1,1);
	Vector::PrintCount();
	par[0]->Out();

	delete par[0];
	Shape::PrintCount();

	// Лучше создать не массив, а динамический список указателей.
	// Те, кто чувствует себя вполне уверенно, могут реализовать
	// не массив, а динамический список адресов, но это сложнее.

	// Заодно static-член класса Shape должен запоминать адреса созданных объектов
	// в массиве указателей (если счетчик не превышает 999).
	
	cout << "\n\n\tTest abstract Shapes;\n";
	{
	Rect* pr = new Rect(0, 0, 5, 5);	// In the heap
	Rect r (10, 10, 100, 100);			// On stack frame

	Circle* pc = new Circle (10, 10, 5);// In the heap
	Circle c (20, 20, 3);				// On stack frame
	Vector v (5.,5.);					// Смещение
	Shape::PrintCount();

	for (int i = 0; i<Shape::GetCount(); i++)
	{
	Shape* p = Shape::shapes[i];
	p->Move(v);
	p->Out();
	cout << "Area = " <<	p->Area() << endl;
	}
	Shape::PrintCount();
	delete pr;
	Shape::PrintCount();
	delete pc;
	Shape::PrintCount();
	}
	Shape::PrintCount();
	
	cout << "Print anything to exit\n";
	string str1;
	cin >> str1;
}

