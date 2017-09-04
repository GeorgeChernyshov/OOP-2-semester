#include "stdafx.h"

int n;

namespace space { int n = 1; }

int main() {
	setlocale(LC_CTYPE, ".1251");
	setlocale(LC_MONETARY, ".1251");
	cout << "global variables example " << ::n << " " << space::n << endl;
	char c = 'A';
	c = 0x42;
	cout << "66th letter " << c << endl;
	c = -1;
	cout << "-1 equals " << c << endl;
	c = CHAR_BIT;
	cout << "CHAR_BIT size = " << (int)c << endl;
	stop;

	wchar_t cw = L'Ф';
	size_t ns = sizeof(cw);
	cout << "cw equals " << cw << " size of wchar is " << ns << endl;
	//Думал, будет 2 байта. Оказалось, 4.

	unsigned char uc = 0x41;
	cout << "unsigned char: " << uc << " ";
	uc = 'B';
	cout << uc << endl;

	int i = 1;
	cout << "int: " << i << " ";
	i = -1;
	cout << i << endl;
	stop;

	unsigned int ui = 1;
	cout << "unsigned int: " << ui << " ";
	ui = static_cast<unsigned int>(-1);
	cout << ui << endl;

	short s = 0xffff;
	cout << "short: " << s << " ";
	s = short(0xffff);
	cout << s << " ";
	s = 1;
	cout << s << endl;
	//Здесь обещали warning. Не нашел.

	unsigned short us = 0xffff;
	cout << "unsigned short: " << us << " ";
	us = 5;
	cout << us << endl;

	long l = 0xffffffff;
	cout << "long: " << l << " ";
	l = -128;
	cout << l << endl;

	l = FLT_MAX_EXP;
	cout << "FLT_MAX_EXP = " << l << endl;
	//максимальное значение float - 2^128

	l = DBL_MAX_EXP;
	cout << "DBL_MAX_EXP = " << l << endl;
	//максимальное значение double - 2^1024

	l = FLT_DIG;
	cout << "FLT_DIG = " << l << endl;
	//количество значимых десятичных знаков float. Это значит, что седьмой знак после запятой отображать нет смысла ввиду ограничений точности float

	l = DBL_DIG;
	cout << "DBL_DIG = " << l << endl;
	//количество значимых десятичных знаков double

	l = FLT_MANT_DIG;
	cout << "FLT_DIG = " << l << endl;
	//максимальная точность float. На единицу больше количества битов в мантиссе. То есть, 1.0f + (1.0f * 2^{-24}) = 1.0f

	l = DBL_MANT_DIG;
	cout << "DBL_DIG = " << l << endl;
	//максимальная точность double

	float f = -12.56f;
	cout << "float: " << f << " ";
	f = -1.e-27f;
	cout << f << endl;

	f = FLT_MAX;
	cout << "FLT_MAX = " << f << endl;
	f = FLT_MIN;
	cout << "FLT_MIN = " << f << endl;

	double d = 0.1234567890123456789123456789;
	cout << "double: " << d << " ";
	d = -0.12345678912345e+306;
	cout << d << endl;

	d = DBL_MAX;
	cout << "DBL_MAX = " << d << endl;
	d = DBL_MIN;
	cout << "DBL_MIN = " << d << endl;
	d = DBL_EPSILON;
	cout << "DBL_EPSILON = " << d << endl;

	uc = static_cast<unsigned char>(~0);
	cout << "unsigned char uc = " << uc << endl;
	i = ~0;
	cout << "int i = " << i << endl;
	stop;

	d = f = i = s = c = 1 / 3;
	c = s = i = f = d = 100 / 3;
	c = s = i = f = d = 10 / 3;
	c = s = i = f = d = 1 / 3.;

	i = 256;
	c = i;
	cout << "c = " << (int)c << endl;

	uc = 255;
	unsigned char u = 2, sum = uc + u;
	cout << "sum = " << (int)sum << endl;

	i = 100;
	f = d = i / 3;
	cout << f << " " << d << endl;
	f = d = (double)i / 3;
	cout << f << " " << d << endl;
	f = d = double(i) / 3;
	cout << f << " " << d << endl;
	f = d = static_cast<double>(i) / 3;
	cout << f << " " << d << endl;
	stop;

	n = 100;
	//присвоили глобальной переменной. Если бы существовала локальная переменная, то присвоилось бы ей
	space::n = 200;
	//присвоили переменной из space
	n++;
	//увеличили глобальную
	int n;
	//ввели локальную переменную, живущую в main
	n = 10;
	//Новая переменная заняла обозначение глобальной и поэтому мы присвоили значение именно ей
	::n++;
	//увеличили глобальную

	{
		int n;
		//ввели новую переменную, локальную для этого блока
		n = -1;
		//теперь это обозначение используется для переменной из блока. К n из main обратиться мы не можем.
		n++;
		::n++;
		space::n++;
		//ко всем остальным переменным мы можем обратиться
	}
	n--;
	//теперь это обозначение вернулось к переменной из main
	::n--;
	space::n--;

	{
	Again:
		int outer;
		for (int i = 0; i < 5; i++) {
			static int nStat;
			{
				int nLoc = 0;
				nLoc++; nStat++;
			}
			outer = nStat;
		}
		if (outer < 10)
			goto Again;
	}
	//Заметим, что несмотря на многократное объявление, nStat сохраняет свое значение. Это происходит, посколько статические переменные сохраняются до конца программы.

	cout << "Input anything to exit" << endl;
	string str;
	cin >> str;

	return 0;
}