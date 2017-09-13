#pragma once

template<class T, int cap>
class MyStack
{
public:
	MyStack() {
		arr = new T[capacity];
		size = 0;
	}

	~MyStack() {
		delete[] arr;
	}

	void Push(const T& obj) {
		if (size < capacity) {
			arr[size++] = obj;
			return;
		}
		throw StackOverflow();
	}

	T Pop() {
		if (size > 0) { return arr[(size--) - 1]; }
		throw StackUnderflow();
	}

	int GetSize() { return size; }

	int Capacity() { return capacity; }

	T& operator[] (int index) {
		if (index > 0 && index < size) return arr[size - 1];
		throw StackOutOfRange();
	}
private:
	const int capacity = cap;
	T* arr;
	int size;
};

struct StackOverflow : public exception {};
struct StackUnderflow : public exception {};
struct StackOutOfRange : public exception {
public:
	void Out() {
		cout << "\nOut of range\n";
		return;
	}
};

