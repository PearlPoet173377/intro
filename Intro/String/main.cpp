#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n-------------------------\n"

class String;
String operator+(const String& left, const String& right);

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


const char* String::get_str()const
{
	return str;
}
char* String::get_str()
{
	return str;
}
int String::get_size()const
{
	return size;
}


String::String(int size) :size(size), str(new char[size] {})
{
	/*this->size = size;
	this->str = new char[size] {};*/
	cout << (size == 80? "Def": "Size")<<"Const:\t" << this << endl;
}

String::String(const char* str)
{
	this->size = strlen(str) + 1;
	this->str = new char[size] {};
	strcpy(this->str, str);
	cout << "Constructor:\t\t" << this << endl;
}

String::String(const String& other)
{
	this->size = other.size;
	this->str = new char[size] {};
	strcpy(this->str, other.str);
	cout << "CopyConstructor:\t" << this << endl;
}

String::String(String&& other)
{
	this->size = other.size;
	this->str = other.str;
	other.str = nullptr;
	cout << "MoveConst:\t" << this << endl;
}

String::~String()
{
	delete[] this->str;
	cout << "Destructor:\t" << this << endl;
}


String& String::operator=(const String& other)
{
	if (this == &other)return *this;
	delete[] this->str;
	this->size = other.size;
	this->str = new char[size] {};
	strcpy(this->str, other.str);
	cout << "CopyAssigmentConstructor:\t" << this << endl;
	return *this;
}

String& String::operator+=(const String& other)
{
	return *this = *this + other;
}

char& String::operator[](int index)const
{
	return this->str[index];
}

void String::print()const
{
	cout << "Size:\t" << size << endl;
	cout << "Str:\t" << str << endl;
}


String operator+(const String& left, const String& right)
{
	String result = left.get_size() + right.get_size() - 1;
	for (int i = 0; i < left.get_size(); i++)
		//result.get_str()[i] = left.get_str()[i];
		result[i] = left[i];
	for (int i = 0; i < right.get_size(); i++)
		//result.get_str()[i + left.get_size() - 1] = right.get_str()[i];
		result[i + left.get_size() - 1] = right[i];
	return result;
}

ostream& operator<<(ostream& os, const String& obj)
{
	return os << obj.get_str();
}


//#define CONSTRUCTORS_CHECK
#define ASSIGMENT_CHECK

void main()
{
	//setlocale(LC_ALL, "");
	system("CHCP 1251");
#ifdef CONSTRUCTORS_CHECK

	String str;
	str.print();

	String str2 = "Hello";
	str2.print();
	cout << str2 << endl;

	String str3 = str2;
	cout << "Str3:\t" << str3 << endl;

	String str4;
	str4 = str3;
	cout << "Str4:\t" << str4 << endl;

#endif

#ifdef ASSIGMENT_CHECK
	String str1 = "Hello";
	String str2="World";
	String str3 = str1 + str2;
	cout << str3 << endl;

	/*str1 += str2;
	cout << str1 << endl;*/
#endif
}