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
	const char* get_str()const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}
	int get_size()const
	{
		return size;
	}

	
	String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "DefConst:\t" << this << endl;
	}

	String(const char* str)
	{
		this->size = strlen(str) + 1;
		this->str = new char[size] {};
		strcpy(this->str, str);
		cout << "Constructor:\t\t" << this << endl;
	}

	String(const String& other)
	{
		this->size = other.size;
		this->str = new char[size] {};
		strcpy(this->str, other.str);
		cout << "CopyConstructor:\t" << this << endl;
	}

	String(String&& other)
	{
		this->size = other.size;
		this->str = other.str;
		other.str = nullptr;
		cout << "MoveConst:\t" << this << endl;
	}
	
	~String()
	{
		delete[] this->str;
		cout << "Destructor:\t" << this << endl;
	}


	String& operator=(const String& other)
	{
		if (this == &other)return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size] {};
		strcpy(this->str, other.str);
		cout << "CopyAssigmentConstructor:\t" << this << endl;
		return *this;
	}

	/*String(String&& other)
	{
		delete[] this->str;
		this->size = other.size;
		this->str = other.str;
		other.str = nullptr;
		cout << "MoveAssigment:\t" << this << endl;
		return *this;
	}*/

	String& operator+=(const String& other)
	{
		return *this = *this + other;
	}

	char& operator[](int index)const
	{
		return this->str[index];
	}
	
	void print()const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
	}
};


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
//#define ASSIGMENT_CHECK
//#define OPERATOR_PLUS_CHECK

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

#ifdef OPERATOR_PLUS_CHECK

#endif;

	String str1; //defconst
	String str2();//щбъявляется функ str2 которая ничего не принимает и возращ значение типа String
	String str3{}; //defconst
	String str4(5);
	String str5{ 8 };
}