#include "stdafx.h"
#include "MyString.h"

MyString::MyString() {
	m_pStr = new char[1];
}

MyString::MyString(const MyString& str) {
	this->Copy(str.m_pStr);
}

void MyString::Copy(char* s)
{
	delete[] m_pStr;
	// ����������� �������� ��������� ���������� ������.
	int len = strlen(s) + 1;
	m_pStr = new char[len];
	// + 1, ��� ��� ������� ���� ���� ����� �����������
	// ���� ������ ��������, �������� ������-�������� � ������-���� ������
	if (m_pStr)
		strcpy_s(m_pStr, len, s);
}

// ����������� ������������.
MyString::MyString(char* s)
{
	m_pStr = 0;
	Copy(s);
}

// ����������� �����������.
MyString::~MyString()
{
	// ������������ ������, ������� � ������������ ��� ������-����� ������
	delete[] m_pStr;
}

// ����� ������
char* MyString::GetString()
{
	return m_pStr;
}

int MyString::GetLength()
{
	return strlen(m_pStr) + 1;
}

MyString& MyString::operator=(const MyString& str) {
	m_pStr = str.m_pStr;
	return *this;
}