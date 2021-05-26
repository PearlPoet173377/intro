#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n-----------------\n"

template<typename T>class Iterator;
template<typename T>class ForwardList;

#include"Element.h"
#include"Element.cpp"

#include"Iterator.h"
#include"Iterator.cpp"



#include"ForwardList.h"
#include"ForwardLIst.cpp"








template<typename T>
ForwardList<T> operator+(const ForwardList<T>& left, const ForwardList<T>& right)
{
	ForwardList<T> cat = left;
	for (const Element* Temp = right.getHead(); Temp; Temp = Temp->getpNext())
		cat.push_back(Temp->getData());
	return cat;
}

#define HARDCORE
//#define BASE_CHECK
#ifdef BASE_CHECK
//#define ADDING_ELEMENTS
#endif

void main()
{
 /*
	int n;
	cout << "Write size of list: "; cin >> n;
	ForwardList list;
	for (int i = 0; i < n; i++)
	{
		list.push_front(rand() % 100);
		//list.push_back(rand() % 100);
	}
	cout << "List ready" << endl;
	int value;
	int index;
	cout << "Write a index: "; cin >> index;
	cout << "Write a number: "; cin >> value;
	//list.push_back(value);
	list.insert(index, value);
	list.print();

	ForwardList list2;
	cout << "Write size of list: "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		list2.push_back(rand() % 100);
	}
	list2.print();*/

	/*int arr[] = { 3,5,8,13,21 };
	for (int i:arr)
	{
		cout << arr[i] << "\t";
	}*/

	cout << sizeof(Element<int>) << endl;
	ForwardList<int> list = { 3,5,8,13,21 };
	for(int i:list)
	{
		cout<<i<<"\t";
	}
	cout << endl;

	//list.print();
	/*try
	{

		for (int i = 0; i < list.get_size(); i++)
		{
			list[i] = rand() % 100;
		}
		for (int i = 0; i < list.get_size(); i++)
		{
			cout << list[i] << "\t";
		}
	}

	catch (std::exception& e)
	{
		std::cerr << e.what() << endl;//метод what()возращ сообщение об ошибке
	}*/

	/*int n;
	cout << "Write a size of list: "; cin >> n ;
	ForwardList list;

	for (int i = 0; i < n; i++)
	{
		list.push_back(rand() % 100);
	}
	list = list;
	list.print();

	cout << delimiter;

	//ForwardList list2 = list;
	ForwardList list2;*/

	/*ForwardList list1;
	list1.push_back(3); 
	list1.push_back(5);
	list1.push_back(8);
	list1.push_back(13);
	list1.push_back(15);
	
	ForwardList list2;
	list2.push_back(34);
	list2.push_back(55);
	list2.push_back(89);
	list2.push_back(144);
	cout << delimiter << endl;

	ForwardList list3;
	list3 = list1 + list2;
	list3.print();
	cout << delimiter << endl;*/

	ForwardList<double> dfl = { 2.5, 2.87, 3.14, 5.9, 8.2 };
	for (double i : dfl)cout << i << "\t"; cout << endl;


	ForwardList<std::string> stih = { "Horosho","zhivet","na","svete","Vinni-Puh" };
	for (std::string i : stih)cout << i << "\t"; cout << endl;


}