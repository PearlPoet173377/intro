#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n-----------------\n"

class Element
{
	int Data; //значение элемента
	Element* pNext;
	static int count;//укаазтель на след элемент
public:

	const Element* getpNext()const;
	
	int getData()const;
	
	Element(int Data, Element* pNext = nullptr);
	~Element();
	
	friend class Iterator;
	friend class ForwardList;
	friend ForwardList operator+(const ForwardList& left, const ForwardList& right);
};
int Element::count = 0;

const Element* Element::getpNext()const
{
	return pNext;
}

int Element::getData()const
{
	return Data;
}

Element::Element(int Data, Element* pNext = nullptr) :Data(Data), pNext(pNext)
{
	count++;
	//cout << "EConst:\t" << this << endl;
}
Element::~Element()
{
	count--;
	//cout << "EDestruc:\t" << this << endl;
}


class Iterator
{
	Element* Temp;
public:
	Iterator(Element* Temp = nullptr);
	~Iterator();

	Iterator& operator++();
	Iterator operator++(int);

	bool operator==(const Iterator& other)const;
	bool operator!=(const Iterator& other)const;

	const Element* operator->()const;
	Element* operator->();

	const int& operator*() const;
	int& operator*();
};

Iterator::Iterator(Element* Temp = nullptr) :Temp(Temp)
{
	//cout << "IConst:\t" << this << endl;
}

Iterator::~Iterator()
{
	//cout << "IDectruc:\t" << this << endl;
}

Iterator& Iterator::operator++()
{
	Temp = Temp->pNext;
	return *this;
}

Iterator Iterator::operator++(int)
{
	Iterator old = *this;
	Temp = Temp->pNext;
	return old;
}

bool Iterator::operator==(const Iterator& other)const
{
	return this->Temp == other.Temp;
}

bool Iterator::operator!=(const Iterator& other)const
{
	return this->Temp != other.Temp;
}

const Element* Iterator::operator->()const
{
	return Temp;
}

Element* Iterator::operator->()
{
	return Temp;
}

const int& Iterator::operator*() const
{
	return Temp->Data;
}

int& Iterator::operator*()
{
	return Temp->Data;
}


class ForwardList
{
	unsigned int size;
	Element* Head; //указатель на началтный элемент списка
public:
	unsigned int get_size() const
	{
		return size;
	}
	const Element* getHead()const
	{
		return Head;
	}

	Iterator begin()
	{
		return Head;
	}

	Iterator end()
	{
		return nullptr;
	}
	
	ForwardList()
	{
		this->size = 0;
		this->Head = nullptr;

		cout << "LConst:\t" << this << endl;
	}

	ForwardList(std::initializer_list<int> il)
	{
		cout << typeid(il.begin()).name() << endl;
		for (const int* it = il.begin(); it != il.end(); it++)
		{
			push_back(*it);
		}
		cout << "ILConst:\t" << this << endl;
	}
	
	ForwardList(const ForwardList& other)
	{
		for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)
			push_back(Temp->Data);
		cout << "LCopyConstructor:\t" << this << endl;
	}

	ForwardList(ForwardList&& other)
	{
		this->size = other.size;
		this->Head = other.Head;
		other.Head = nullptr;
		cout << "LMoveConst: " << this << endl;
	}

	~ForwardList()
	{
		
		while (Head)pop_front();
		cout << "LDestruc:\t" << this << endl;
	}


	//operators

	ForwardList& operator=(const ForwardList& other)
	{
		if (this == &other)return *this;
		while (Head)pop_front();
		for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)
			push_back(Temp->Data);
		cout << "LCopyAssign:\t" << this << endl;
		return *this;
	}

	ForwardList& operator=(ForwardList&& other)
	{
		while (Head)pop_front();
		this->size = other.size;
		this->Head = other.Head;
		other.Head = nullptr;
		cout << "LMoveAssign: " << this << endl;
		return *this;
	}

	//Adding Elements

	int& operator[](int index)
	{
		if (index >= size)throw std::exception("Out of range");
		Element* Temp = Head;
		for (int i = 0; i < index; i++)
		{
			Temp = Temp->pNext;
		}
		return Temp->Data;
	}
	
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
		
		//for(Element* Temp=Head;Temp;/*Temp=Temp->pNext*/Temp++)
			//cout << Temp << "\t" << Temp->Data << "\t" << Temp->pNext << endl;
		for (Iterator Temp = Head; Temp != nullptr; Temp++)
			cout << *Temp << "\t";
			//cout/*<<Temp<<"\t"*/ << Temp->Data << "\t" << Temp->pNext << endl;

		cout << "In list " << size << " elements\n";
		cout << "Total count of elements: " << Element::count << endl;
	}

};

ForwardList operator+(const ForwardList& left, const ForwardList& right)
{
	ForwardList cat = left;
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

	cout << sizeof(Element) << endl;
	ForwardList list = { 3,5,8,13,21 };
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



}