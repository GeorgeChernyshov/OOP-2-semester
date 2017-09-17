// Контейнеры STL: 
//deque, stack, queue, priority_queue
//set, multiset, map, multimap
//Итераторы. Стандартные алгоритмы. Предикаты.
#include "stdafx.h"
#include "Vector.h"
#include "MyString.h"
#include "Rect.h"

template<typename T>
void printall(T t) {
	while (t.size() > 0) {
		cout << t.top() << " ";
		t.pop();
	}
	cout << endl;
	return;
}
template<typename F>
void printall(queue<F> t) {
	while (t.size() > 0) {
		cout << t.front() << " ";
		t.pop();
	}
	cout << endl;
	return;
}

bool in_range(const Vector& v) {
	return (v.getX() > -10 && v.getY() > -10 && v.getX() < 10 && v.getY() < 10);
}

char low(char& s) {
	if (s >= 'A' && s <= 'Z') s += 32;
	return s;
}

int main()
{
	setlocale(LC_CTYPE, ".1251");
	setlocale(LC_MONETARY, ".1251");

	//Очередь с двумя концами - контейнер deque
	deque<Vector> dv;
	dv.assign(3, Vector(1, 1));

	for_each(dv.begin(), dv.end(), [](Vector& v) { v.Out(); });

	deque<MyString> dms;
	dms.push_back("Aaa");
	dms.push_front("Baa");
	dms.push_front("f");
	dms.insert(dms.begin() + 1, 3, "abac");

	cout << "\nBefore erase\n";

	for_each(dms.begin(), dms.end(), [](MyString& m) { cout << m.GetString() << endl; });

	for (unsigned int i = 0; i < dms.size(); i++) {
		char a = dms[i].GetString()[0];
		if (a == 'A' || a == 'a') dms.erase(dms.begin() + i--);
	}

	cout << "\nAfter erase\n";

	for_each(dms.begin(), dms.end(), [](MyString& m) { cout << m.GetString() << endl; });


	//Напишите шаблон функции для вывода значений stack, queue, priority_queue
	//Подумайте, как "получать" данное "с верхушки"?
	//Что происходит с контейнерами после вывода значений?

	stack<int> s;
	s.push(6);
	s.push(7);
	queue<int> q;
	q.push(8);
	q.push(9);
	priority_queue<int> priority_q;
	priority_q.push(10);
	priority_q.push(11);

	printall(s);
	printall(q);
	printall(priority_q);

	vector<int> v = {1, 2, 3, 4, 5, 6};
	stack<int, vector<int>> s1(vector<int>(v.rbegin(), v.rend()));

	//д) проверьте, какой из стеков больше (подумайте, какой смысл вкладывается в такое сравнение)
	{
		stack<int> s2;
		s2.push(9);
		s2.push(10);
		stack<int> s3 = s2;
		if (s3 == s2) cout << "Stacks are equal\n";
		s3.push(1);
		s2.push(2);
		if (s3 < s2) cout << "s2 is bigger\n";
		stop

	}

	//Подумайте, что требуется сделать при уничтожении такой очереди?
	{

		queue<Vector*> q1;
		for (int i = 0; i < 3; i++) q1.push(new Vector(1, 2));
		delete q1.front();
		q1.front() = new Vector(-1, -1);
		delete q1.back();
		q1.back() = new Vector(-5, -7);
		cout << q1.size() << endl;


	}

	//в) проверьте "упорядоченность" значений (с помощью pop() ) - если они оказываются не упорядоченными, подумайте:
	//		что сравнивается при вставке?

	{
		const char* cc1 = "Abacabad";
		const char* cc2 = "AbAcabad";
		const char* cc3 = "Abac";
		const char* cc4 = "Bbac";
		const char* arrcc[] = { cc1, cc2, cc3, cc4 };
		priority_queue<const char*> pqcc(arrcc, arrcc + 4);
		printall(pqcc);
		stop
	}

	set<Vector> sV;
	sV.insert(Vector(1, 1));
	sV.insert(Vector(2, -0.02));
	sV.insert(Vector(0, 1));
	sV.insert(Vector(1.3, 0));
	for (set<Vector>::iterator it = sV.begin(); it != sV.end(); it++) {
		it->Out();
	}

	set<int> si1 = { 1, 2, 3, 4 };
	set<int> si2 = { 4, 5, 6, -4 };
	si2.insert(si1.begin(), si1.end());
	for (set<int>::iterator it = si2.begin(); it != si2.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	multiset<Vector> msV;
	msV.insert(Vector(1, 1));
	msV.insert(Vector(12, -0.02));
	msV.insert(Vector(1, 1));
	msV.insert(Vector(1, 1));
	for (multiset<Vector>::iterator it = msV.begin(); it != msV.end(); it++) {
		it->Out();
	}

	multiset<int> msi1 = { 1, 2, 3, 4 };
	multiset<int> msi2 = { 4, 5, 6, -4 };
	msi2.insert(msi1.begin(), msi1.end());
	for (multiset<int>::iterator it = msi2.begin(); it != msi2.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	map<const char*, int> mci;
	mci.insert(pair<const char*, int>("Ivanova", 10));
	mci.insert(pair<const char*, int>("Novoselova", 102));
	mci["Krasikov"] = 25;
	for (map<const char*, int>::iterator it = mci.begin(); it != mci.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}
	map<const char*, int>::iterator itf = mci.find("Ivanova");
	mci.erase(itf);
	mci.insert(pair<const char*, int>("Petrova", 10));
	cout << endl;
	for (map<const char*, int>::iterator it = mci.begin(); it != mci.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}
	stop

		multimap<string, string> mm;
		mm.insert(pair<string, string>("sweet", "сладкий"));
		mm.insert(pair<string, string>("sweet", "дорогой(о человеке)"));
		mm.insert(pair<string, string>("strange", "чужой"));
		mm.insert(pair<string, string>("strange", "странный"));
		mm.insert(pair<string, string>("hello", "привет"));
		cout << endl;
		for (multimap<string, string>::iterator it = mm.begin(); it != mm.end(); it++) {
			cout << it->first << " " << it->second << endl;
		}
		multimap<string, string>::iterator mmit1 = mm.lower_bound("sweet");
		multimap<string, string>::iterator mmit2 = mm.upper_bound("sweet");
		cout << endl;
		for (multimap<string, string>::iterator it = mmit1; it != mmit2; it++) {
			cout << it->first << " " << it->second << endl;
		}

		vector<Vector> vEctor;
		for (set<Vector>::reverse_iterator it = sV.rbegin(); it != sV.rend(); it++) {
			vEctor.push_back(*it);
		}

		for (unsigned int i = 0; i < vEctor.size(); i++) {
			vEctor[i].Out();
		}

		cout << endl;
		ostream_iterator<Vector> out_it_V(cout);
		std::copy(vEctor.begin(), vEctor.end(), out_it_V);
		cout << endl;
		ostream_iterator<Vector> out_it_S(cout);
		std::copy(sV.begin(), sV.end(), out_it_S);

		back_inserter(vEctor) = Vector(500, 500);
		front_inserter(dv) = Vector(500, 500);
		inserter(sV, sV.end()) = Vector(500, 500);

		for_each(vEctor.begin(), vEctor.end(), [](Vector & v) {cout << v; });

		stop

		for_each(vEctor.begin(), vEctor.end(), [](Vector & v) {v.setX(102.5); });
		cout << endl;
		for_each(vEctor.begin(), vEctor.end(), [](Vector & v) {cout << v; });

		cout << endl;
		for (multiset<Vector>::iterator it = msV.begin(); it != msV.end(); it = find(it, msV.end(), Vector(1, 1))) {
			it++->Out();
		}

		sort(vEctor.begin(), vEctor.end());
		cout << endl;
		for_each(vEctor.begin(), vEctor.end(), [](Vector & v) {cout << v; });

		cout << endl;
		multiset<Vector>::iterator found = find_if(msV.begin(), msV.end(), in_range);
		found->Out();

		vector<Rect> vr;
		vr.push_back(Rect(0, 0, 6, 8));
		vr.push_back(Rect(3, 3, 5, 5));
		vr.push_back(Rect(-6, -6, -4, -4));
		vr.push_back(Rect(1, 1, 2, 3));
		sort(vr.begin(), vr.end());
		cout << endl;
		for (unsigned int i = 0; i < vr.size(); i++) {
			cout << vr[i];
		}




	{
		list<string> ls;
		ls.push_back("HELLO");
		ls.push_back(", my");
		ls.push_back("nAmE Is");
		ls.push_back("George");

		set<string> ss;


		for (list<string>::iterator it = ls.begin(); it != ls.end(); it++) {
			string s;
			transform(it->begin(), it->end(), back_inserter(s), low);
			ss.insert(s);
		}

		cout << endl;
		for (set<string>::iterator it = ss.begin(); it != ss.end(); it++) {

			cout << *it << " ";
		}
		cout << endl;

		stop
	}
	{

		vector<string> last = {"Abac", "Abad", "Abac", "Abab"};
		map<string, int> mmm;
		for (unsigned int i = 0; i < last.size(); i++) {
			mmm[last[i]]++;
		}

		for (map<string, int>::iterator it = mmm.begin(); it != mmm.end(); it++) {
			cout << it->first << " " << it->second << endl;
		}

	}



	cout << "Print anything to exit\n";
	string str;
	cin >> str;
	return 0;
}

