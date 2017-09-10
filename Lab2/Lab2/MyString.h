#pragma once

class MyString
{
private:
	char* m_pStr;		// Ёлемент данных класса (адрес строки)
public:
	MyString();
	MyString(char* s);	// ќбъ€вление конструктора
	MyString(const MyString& str);
	~MyString();		// ќбъ€вление деструктора

	void Copy(char* s);
	char* GetString();	// ќбъ€вление метода (accessor)
	int GetLength();	// ќбъ€вление метода (длина строки)
	MyString& operator=(const MyString& str);
};