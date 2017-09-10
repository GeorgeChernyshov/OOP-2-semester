#pragma once

class MyString
{
private:
	char* m_pStr;		// ������� ������ ������ (����� ������)
public:
	MyString();
	MyString(char* s);	// ���������� ������������
	MyString(const MyString& str);
	~MyString();		// ���������� �����������

	void Copy(char* s);
	char* GetString();	// ���������� ������ (accessor)
	int GetLength();	// ���������� ������ (����� ������)
	MyString& operator=(const MyString& str);
};