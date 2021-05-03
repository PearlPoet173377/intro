#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

class Element
{
	int Data; //значение элемента
	Element* pNext;
	static int count;//укаазтель на след элемент
public:
	Element(int Data, Element* pNext = nullptr) :Data(Data), pNext(pNext)
	{
		count++;
		//cout << "EConst:\t" << this << endl;
	}
	~Element()
	{
		count--;
		//cout << "EDestruc:\t" << this << endl;
	}

	friend class ForwardList;
};
int Element::count = 0;

class ForwardList
{
	unsigned int size;
	Element* Head; //указатель на началтный элемент списка
public:
	ForwardList()
	{
		this->size = 0;
		this->Head = nullptr;

		cout << "LConst:\t" << this << endl;
	}

	~ForwardList()
	{
		
		while (Head)pop_front();
		cout << "LDestruc:\t" << this << endl;
	}

	//Adding Elements

	void push_front(int Data)
	{
		/*Element* New = new Element(Data);
		New->pNext = Head;
		Head = New;*/
		Head = new Element(Data, Head);
		size++;
	}

	void push_back(int Data)
	{
		if (Head == nullptr)
		{
			push_front(Data);
			return;
		}
		Element* New = new Element(Data);
		Element* Temp=Head;
		while (Temp->pNext != nullptr)
		{
			Temp = Temp->pNext;
		}
		Temp->pNext = New;
		size++;
	}

	void insert(int index, int data)
	{
		if (index > Element::count)return;
		if (index == 0)
		{
			push_front(data);
			return;
		}
		Element* New = new Element(data);
		Element* Temp = Head;
		for (int i = 0; i < index-1; i++)
		{
			Temp = Temp->pNext;
		}
		New->pNext = Temp->pNext;
		Temp->pNext = New;
		size++;
	}

	void pop_front()
	{
		if (Head == nullptr)return;
		Element* erase_element = Head;
		Head = Head->pNext;
		delete erase_element;
		size--;
	}
	
	void pop_back() 
	{
		if (Head == nullptr)return;
		if (Head->pNext == nullptr)
		{
			pop_front();
			return;
		}
		Element* Temp = Head;
		while (Temp->pNext->pNext != nullptr)
			Temp = Temp->pNext;
		delete Temp->pNext;
		Temp->pNext = nullptr;
		size--;
	}

	void print()const
	{
		/*Element* Temp = Head;
		while (Temp != nullptr)
		{
			cout << Temp << "\t" << Temp->Data << "\t" << Temp->pNext << endl;
			Temp = Temp->pNext;
		}*/
		
		for(Element* Temp=Head;Temp;Temp=Temp->pNext)
			cout << Temp << "\t" << Temp->Data << "\t" << Temp->pNext << endl;
		cout << "In list " << size << " elements\n";
		cout << "Total count of elements: " << Element::count << endl;
	}

};


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
	for (int i = 0; i < sizeof(arr)/sizeof(int); i++)
	{
		cout << arr[i] << "\t";
	}*/

	ForwardList list = { 3,5,8,13,21 };
	list.print();
}