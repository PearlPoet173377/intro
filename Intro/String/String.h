#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n-------------------------\n"

class String;
String operator+(const String& left, const String& right);
ostream& operator<<(ostream& os, const String& obj);

class String
{
	char* str;
	int size;
public:
	const char* get_str()const;
	char* get_str();
	int get_size()const;

	explicit String(int size = 80);

	String(const char* str);

	String(const String& other);

	String(String&& other);

	~String();


	String& operator=(const String& other);

	String& operator+=(const String& other);

	char& operator[](int index)const;

	void print()const;
};

