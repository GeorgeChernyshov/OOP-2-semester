#include "stdafx.h"
#include "MyStack.h"
template<class T>
void MyStack::Push(T& obj) {

}

template<class T>
T MyStack::Pop() {
	try {
		if (*this.size > 0) return *this[(size--) - 1];
		throw 1;
	}
	catch{
		cout << "Unable to pop from empty stack\n";
	}
}

template<class T>
T& MyStack::operator[] (int index) {

}
