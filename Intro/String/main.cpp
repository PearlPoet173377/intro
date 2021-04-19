#include"String.h"

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