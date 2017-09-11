#pragma once
template<class T>
class MyStack
{
public:
	MyStack();
	~MyStack();
	void Push(T& obj);
	T Pop();
	int GetSize() { return size; }
	int Capacity() { return capacity; }
	T& operator[] (int index);
private:
	const int capacity = 1000;
	T arr[capacity];
	int size;
};

