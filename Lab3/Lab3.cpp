//=======================================================================
//	Çàíÿòèå ¹6. Øàáëîíû ôóíêöèé. Øàáëîíû êëàññîâ. Ñòàíäàðòíûå øàáëîíû Ñ++.
//				Îáðàáîòêà èñêëþ÷åíèé.
//=======================================================================
#include "stdafx.h"
#include "Vector.h"
#include "MyString.h"
#include "MyStack.h"

//============= Øàáëîí ôóíêöèè äëÿ âûâîäà ñ ïîìîùüþ èòåðàòîðà

template <class T>
void Swap(T& left, T& right) {
	T t = right;
	right = left;
	left = t;
	return;
}

template <class T> void pr(T& v, string s)
{
	cout << "\n\n\t" << s << "  # Sequence:\n";

	// Èòåðàòîð ëþáîãî êîíòåéíåðà
	T::iterator p;
	int i;

	for (p = v.begin(), i = 0; p != v.end(); p++, i++)
		cout << endl << i + 1 << ". " << *p;
	cout << '\n';
}

void main()
{
	{
		int i = 1, j = -1;
		Swap (i, j);

		double a = 0.5, b = -5.5;
		Swap (a, b);

		Vector u(1, 2), w(-3, -4);
		Swap(u, w);

		MyString s1("Your fault"), s2("My forgiveness");
		Swap(s1, s2);
	}
	try
	{
		cout << "\tTest MyStack\n";
		MyStack <int, 3> stack;

		cout << "\nInteger Stack capacity: " << stack.Capacity();

		stack.Push(1);
		stack.Push(2);
		stack.Push(3);

		cout << "\nInteger Stack has: " << stack.GetSize() << " elements";

			//stack.Push(4);	// Çäåñü äîëæíî áûòü "âûáðîøåíî" èñêëþ÷åíèå

		cout << "\nInteger Stack pops: " << stack.Pop();
		cout << "\nInteger Stack pops: " << stack.Pop();

		cout << "\nInteger Stack has: " << stack.GetSize() << " elements";
		stack.Pop();
				//stack.Pop();		// Çäåñü äîëæíî áûòü "âûáðîøåíî" èñêëþ÷åíèå
		stack.Push(2);

		int i = stack[3];	// Çäåñü äîëæíî áûòü "âûáðîøåíî" èñêëþ÷åíèå

		MyStack<Vector, 5> ptStack;

		cout << "\nVector Stack capacity: " << ptStack.Capacity();

		ptStack.Push(Vector(1, 1));
		ptStack.Push(Vector(2, 2));

		cout << "\nVector Stack pops: ";
		ptStack.Pop().Out();

		cout << "\nVector Stack has: " << ptStack.GetSize() << " elements";
	}
	catch (StackOverflow &e)
	{
		cout << "\nStack overflow\n";
	}
	catch (StackUnderflow &u)
	{
		cout << "\nStack underflow\n";
	}
	catch (StackOutOfRange &o)
	{
		o.Out();
	}

	stop;

	//=======================================================================
	// Êîíòåéíåðû ñòàíäàðòíîé áèáëèîòåêè. Ïîñëåäîâàòåëüíîñòè òèïà vector
	//=======================================================================

	// Ñîçäàéòå ïóñòîé âåêòîð öåëûõ ÷èñåë. Óçíàéòå åãî ðàçìåð ñ ïîìîùüþ ìåòîäà size(),
	// Ñ ïîìîùüþ ìåòîäà push_back() çàïîëíèòå âåêòîð êàêèìè-ëèáî çíà÷åíèÿìè.
	// Ïîëó÷èòå íîâûé ðàçìåð âåêòîðà è âûâåäèòå çíà÷åíèÿ åãî ýëåìåíòîâ.
	// Â ïðîöåññå ðàáîòû ñ âåêòîðîì âû ìîæåòå êðîìå êîëè÷åñòâà ðåàëüíî çàïîëíåííûõ
	// ýëåìåíòîâ (size()) óçíàòü ìàêñèìàëüíî âîçìîæíîå êîëè÷åñòâî ýëåìåíòîâ (max_size()),
	// à òàêæå çàðåçåðâèðîâàííóþ ïàìÿòü (capacity()).

	vector<int> v;
	int n = v.size();
	cout << "Size: " << n << endl;
	v.push_back(-1);
	v.push_back(-2);
	n = v.size();
	cout << "Size: " << n << endl;
	n = v.capacity();
	cout << "Capacity: " << n << endl;
	n = v.max_size();
	cout << "Max Size: " << n << endl;

	pr(v, "Vector of ints");

	vector<double> vd(2, 222.);
	pr(vd, "Vector of doubles");
	n = vd.size();
	cout << "Size: " << n << endl;
	n = vd.capacity();
	cout << "Capacity: " << n << endl;
	n = vd.max_size();
	cout << "Max size: " << n << endl;

	vd.resize(10);
	pr(vd, "After resize");
	n = vd.size();
	cout << "Size: " << n << endl;
	n = vd.capacity();
	cout << "Capacity: " << n << endl;
	n = vd.max_size();
	cout << "Max size: " << n << endl;

	vd.at(8) = 4;
	vd[5] = 6;
	pr(vd, "After at");

	vector<double> wd = vd;
	pr(wd, "Copy");

	vector<double> ud(3);
	copy(vd.begin(), vd.begin() + 3, ud.begin());
	pr(ud, "Copy part");

	double ar[] = { 0., 1., 2., 3., 4., 5. };

	vector<double> va(5);
	copy(ar, ar + 5, va.begin());
	pr(va, "Copy part of array");

	char s[] = "Array is a succession of chars";

	vector<char> vc(10);
	copy(s, s + 10, vc.begin());
	pr(vc, "Copy part of c-style string");

	vector<Vector> vv = { Vector(1, 1), Vector(-2, 55) };

	cout << "\n\nvector of Vectors\n";
	for (int i = 0; i < vv.size(); i++)
		vv[i].Out();

	// Ñîçäàéòå âåêòîð óêàçàòåëåé íà Vector è èíèöèàëèçèðóéòå åãî àäðåñàìè
	// îáúåêòîâ êëàññà Vector

	vector<Vector*> vp = { &vv[0], &vv[1] };

	cout << "\n\nvector of pointers to Vector\n";

	for (int i = 0; i < vp.size(); i++)
		vp[i]->Out();

	// Íàó÷èòåñü ïîëüçîâàòüñÿ ìåòîäîì assign è îïåðàöèåé
	// ïðèñâàèâàíèÿ = äëÿ êîíòåéíåðîâ òèïà vector.
	vp.assign(5, &vv[0]);

	cout << "\n\nAfter assign\n";
	for (int i = 0; i < vp.size(); i++)
		vp[i]->Out();

	// Äåêëàðèðóéòå íîâûé âåêòîð óêàçàòåëåé íà Vector è èíèöèàëèçèðóéòå åãî 
	// ñ ïîìîùüþ âòîðîé âåðñèè assign
	vector<Vector*> vpNew;
	vpNew.assign(vp.begin(), vp.end());

	cout << "\n\nNew vector after assign\n";
	for (unsigned i = 0; i < vpNew.size(); i++)
		vpNew[i]->Out();

	// Íà áàçå øàáëîíà vector ñîçäàíèå äâóõìåðíûé ìàññèâ è
	// çàïîëíèòå åãî çíà÷åíèÿìè ðàçíûìè ñïîñîáàìè.
	// Ïåðâûé âàðèàíò - ïðÿìîóãîëüíàÿ ìàòðèöà
	// Âòîðîé âàðèàíò - ñòóïåí÷àòàÿ ìàòðèöà


	//========= Ñòóïåí÷àòàÿ ìàòðèöà
	vector<vector<double>> vdd(10);
	for (int i = 0; i < vdd.size(); i++)
		vdd[i] = vector<double>(i + 1, double(i));

	cout << "\n\n\tTest vector of vector<double>\n";
	for (int i = 0; i < vdd.size(); i++)
	{
		cout << endl;
		for (int j = 0; j < vdd[i].size(); j++)
			cout << vdd[i][j] << "  ";
	}
	cout << endl;

	for (int i = 0; i < vdd.size(); i++)
		vdd[i] = vector<double>(8, double(i));

	cout << "\n\n\tTest vector of vector<double>\n";
	for (int i = 0; i < vdd.size(); i++)
	{
		cout << endl;
		for (int j = 0; j < vdd[i].size(); j++)
			cout << vdd[i][j] << "  ";
	}
	cout << endl;

	stop;

	vector<char> vec(8, 67);

	char arr[8];
	for (int i = 0; i < 8; i++) arr[i] = i + 64;

	cout << vec.front() << " ";

	cout << vec.back() << " ";

	cout << vec.size() << endl;

	vec.assign(arr + 1, arr + 3);

	cout << vec.front() << " ";
	cout << vec.back() << " ";
	cout << vec.size() << endl;

	stop;

	vec.resize(8, 67);

	vector<char> vChar2(8);
	for (int i = 0; i < 8; i++) {
		vChar2[i] = (i & 1) ? ((i & 2) ? 'U' : 'K') : vec.at(i);
	}

	stop;
	char ch = arr[8];

	stop;

	vChar2.push_back('Z');
	vChar2.pop_back();

	stop;

	for (unsigned int i = 0; i < vChar2.size(); i++) cout << vChar2[i] << " ";
	cout << endl;

	for (int i = 0; i < 8; i++) {
		vChar2.insert(vChar2.begin() + 2 * i, 'W');
	}
	for (unsigned int i = 0; i < vChar2.size(); i++) cout << vChar2[i] << " ";
	cout << endl;

	vChar2.insert(vChar2.begin() + 4, 3, 'X');
	for (unsigned int i = 0; i < vChar2.size(); i++) cout << vChar2[i] << " ";
	cout << endl;

	char arr2[9];
	for (int i = 0; i < 9; i++) arr2[i] = 'a' + i / 3;

	vChar2.insert(vChar2.begin() + 1, arr2 + 2, arr2 + 5);
	for (unsigned int i = 0; i < vChar2.size(); i++) cout << vChar2[i] << " ";
	cout << endl;

	vChar2.erase(vChar2.begin(), vChar2.begin() + 9);
	for (unsigned int i = 0; i < vChar2.size(); i++) cout << vChar2[i] << " ";
	cout << endl;
	stop;

	vChar2.clear();
	for (unsigned int i = 0; i < vChar2.size(); i++) cout << vChar2[i] << " ";
	cout << endl;
	stop;

	vector<vector<int>> vvv;

	stop;

	list<Vector> ptList1;
	list<Vector> ptList2;

	ptList1.push_back(Vector(10, 1));
	ptList1.push_back(Vector(-5, 4));
	ptList1.push_front(Vector(-8.65, -0.01));
	ptList1.insert(ptList1.begin(), Vector(1, 1));

	ptList2.push_back(Vector(5, 2));
	ptList2.push_back(Vector(55, -14));
	ptList2.push_front(Vector(8.65, -0.01));
	ptList2.insert(ptList2.begin(), 3, Vector(3, 4));

	ptList1.sort();
	ptList2.sort();

	stop;

	ptList1.merge(ptList2);


	stop;

	ptList1.remove(Vector(3, 4));

	stop;
	
	for_each(ptList1.begin(), ptList1.end(), [](Vector & v) {v.Out(); });

	stop;

	list<Vector>::iterator it = find(ptList1.begin(), ptList1.end(), Vector(1, 1));
	it = find_if(ptList1.begin(), ptList1.end(), [](Vector& v) {return ((v.getX() > 1) && (v.getY() > 1)); });
	cout << endl;
	it->Out();


	stop;

	list<Vector*> pointerlist;
	pointerlist.push_back(&vv[0]);
	pointerlist.push_back(&vv[1]);
	list<Vector*>::iterator iter = find_if(pointerlist.begin(), pointerlist.end(), [](Vector* v) {return v->getX() > -100; });
	(*iter)->Out();

	stop;

	replace(ptList1.begin(), ptList1.end(), Vector(1, 1), Vector(-0.5, 1.5));
	replace_if(ptList1.begin(), ptList1.end(), [](Vector& v) {return v.getX() > 0; }, Vector(5, 5));
	cout << endl;
	for_each(ptList1.begin(), ptList1.end(), [](Vector & v) {v.Out(); });

	stop;


	//5ã. Ñîçäàéòå âåêòîð ñòðîê (string). Ñ ïîìîùüþ àëãîðèòìà count()
	//ñîñ÷èòàéòå êîëè÷åñòâî îäèíàêîâûõ ñòðîê. Ñ ïîìîùüþ àëãîðèòìà
	//count_if() ñîñ÷èòàéòå êîëè÷åñòâî ñòðîê, íà÷èíàþùèõñÿ ñ çàäàííîé
	//áóêâû

	vector<string> vs;
	vs.push_back("Aaa");
	vs.push_back("Aaaa");
	vs.push_back("Aaa");
	vs.push_back("Bbb");
	vs.push_back("aaa");
	vs.push_back("Aaa");

	cout << count(vs.begin(), vs.end(), "Aaa") << " ";
	cout << count_if(vs.begin(), vs.end(), [](string& str) {return str[0] == 'A'; }) << endl;

	cout << count_if(vs.begin(), vs.end(), [](string& str) {return str == "Aaa"; }) << endl;

	stop;

	cout << "Print anything to exit\n";
	string exit;
	cin >> exit;
}
