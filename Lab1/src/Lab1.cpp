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

	enum RANK {
		eSoldier,
		eSergeant,
		eCorporal,
		eLieutenant,
		eCaptain = 6,
		eMajor,
		eColonel = eMajor + 3,
		eGeneral = 20
	};
	//Заметим, что несмотря на многократное объявление, nStat сохраняет свое значение. Это происходит, посколько статические переменные сохраняются до конца программы.

	typedef RANK RANG;

	RANG r = eSoldier;
	if (r == eSoldier) r = eSergeant;

	if (r == eSergeant) {
		i = r;
		r = RANK(i++);
		cout << ((r == eSergeant) ? "Still sergeant\n" : "Corporal now/n");
		i = r;
		r = RANK(++i);
		cout << ((r == eSergeant) ? "Still sergeant\n" : "Corporal now/n");
		i = r;
	}
	RANK rr = eColonel;
	stop;

	{
		n = 127;
		bool b = n != 0;
		b = n == 0;
		b = n > 0;
		b = n <= 0;
		b = n > 1;

		int num = static_cast<int>(b);
		if (b) cout << "\n\t My flag is: true" << "   or: " << b << "\n\t Conversion to int: " << num;
		b = n == num;
		cout << "\n\t Now the flag is false" << "   or: " << b << endl;
	}

	const double pi = acos(-1.);
	double space_permiability = 4.e-7 * pi;
	const int dozen = 12;
	cout << "pi = " << pi << ", space_permiability = " << space_permiability << ", and dozen is " << dozen << endl;
	int var = dozen;
	//dozen = 1;
	var = 1;

#define _MSVER400
	//#define _MSVER311
	char *version;
#if defined _MSVER400
	version = "version 4.00";
#elif defined _MSVER311
	version = "version 3.11";
#else
	version = "version Unknown";
#endif
	cout << version << endl;
	stop;

#if defined _DEBUG
	cout << "Debug mode: on" << endl;
#elif defined NDEBUG
	cout << "Debug mode: off" << endl;
#endif

	{
		cout << "\n\nGradually eat out all the units:\n\n";
		us = 0xff;
		while (us) {
			cout << hex << us << endl;
			us &= us - 1;
		}
		cout << hex << us << "\nDone\n";

		cout << "\n\nShow even-odd:\n\n";
		for (int i = 0; i < 10; i++) {
			if (i & 1)
				cout << i << " - odd\n";
			else
				cout << i << " - even\n";
		}

		char c = ' ';
		do {
			if (c == 'a')
				cout << "\nAction is a delegate type in C#";
			else if (c == 'b')
				cout << "\nbreak is one of the 'leave' statements in all C-like languages";
			else if (c == 'c')
				cout << "\ncontinue is a 'go on' statement in all C-like languages";
			else if (c == 'd')
				cout << "\ndo-while is a rarely used loop statement in all C-like languages";
			else
				cout << "\nPlease read the rules of this loop";
			cout << "\n\nEnter chars: a, b, c, d (q to quit):\n\n";
			cin >> c;
			if (c == 'q')
				cout << "\nI am going to leave the loop\n";
		} while (c != 'q');
		stop;
	}

	for (double x = 0.0; x < 4; x += 0.1) {
		cout << x << " ";
		if (x < 2.1 || x > 3)
			cout << 0 << endl;
		else if (x < 2.5)
			cout << (x - 2) * 4 << endl;
		else
			cout << (3 - x) * 4 << endl;
	}

	for (double x = 0.0; x < 4; x += 0.1) {
		cout << x << " " << (x < 2.5 ? (x < 2.1 ? 0 : (x - 2) * 4) : (x > 3 ? 0 : (3 - x) * 4)) << endl;
	}

	for (int i = 0; i >= 0; i++) {
		char ch;
		cin >> ch;
		switch (ch) {
		case 'a': 
			cout << "\"Ok\"" << endl;
			break;
		case 'b':
			cout << "Bell" << endl;
			break;
		case 'c':
			cout << i << endl;
			break;
		case 'Esc':
			cout << "\"to quit use \'q\'\"" << endl;
			break;
		case 'q':
			cout << "\"Bye\"" << endl;
			i = -2;
			break;
		}
	}

	unsigned short flags = 0xaabb;
	unsigned short ans = 0;
	for (int i = 0; i < 16; i++) {
		if ((flags & (1 << i)) == (1 << i)) ans |= (1 << (15 - i));
	}
	cout << hex << ans << endl;

	cout << "Input anything to exit" << endl;
	string str;
	cin >> str;

	return 0;
}