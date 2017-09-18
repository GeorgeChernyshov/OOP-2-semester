#include "stdafx.h"
#include "MyString.h"

MyString::MyString() { m_pStr = new char[1]; }

MyString::MyString(const MyString& str) { this->Copy(str.m_pStr); }

MyString::MyString(char* s)
{
	m_pStr = 0;
	Copy(s);
}

void MyString::Copy(char* s)
{
	delete[] m_pStr;
	int len = strlen(s) + 1;
	m_pStr = new char[len];
	if (m_pStr) strcpy_s(m_pStr, len, s);
}

MyString::~MyString() { delete[] m_pStr; }

char* MyString::GetString() { return m_pStr; }

int MyString::GetLength() { return strlen(m_pStr) + 1; }

MyString& MyString::operator=(const MyString& str) {
	if (this == &str) return *this;
	this->Copy(str.m_pStr);
	return *this;
}