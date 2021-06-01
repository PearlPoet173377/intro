#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

class List
{
	class Element
	{ 
		int Data;
		Element* pPrev;
		Element* pNext;
	public:
		Element(int Data, Element* pNext = nullptr, Element* pPrev = nullptr)
		{
			this->Data = Data;
			this->pNext = pNext;
			this->pPrev = pPrev;
			//cout << "Econst:\t" << this << endl;
		}
		
		~Element()
		{
			//cout << "EDestruc:\t" << this << endl;
		}
		friend class List;
		friend List operator+(const List& left, const List& right);
	};

	Element* Head;
	Element* Tail;
	unsigned int size;
public:
	class Iterator
	{
		Element* Temp;

	public:
		Iterator(Element* Temp=nullptr):Temp(Temp)
		{
			//cout << "ITConst:\t" << this << endl;
		}

		~Iterator()
		{
			//cout << "ITDestruc:\t" << this << endl;
		}
		//operators
		Iterator& operator++()
		{
			Temp = Temp->pNext;
			return *this;
		}

		Iterator operator++(int)
		{
			Iterator old = *this;
			Temp = Temp->pNext;
			return old;
		}

		Iterator& operator--()
		{
			Temp = Temp->pPrev;
			return *this;
		}

		Iterator operator--(int)
		{
			Iterator old = *this;
			Temp = Temp->pPrev;
			return old;
		}

		bool operator==(const Iterator& other)const
		{
			return this->Temp == other.Temp;
		}
		
		bool operator!=(const Iterator& other)const
		{
			return this->Temp != other.Temp;
		}

		const int& operator*()const
		{
			return Temp->Data;
		}
		
		int& operator*()
		{
			return Temp->Data;
		}
	};

	const Iterator begin()const
	{
		return Head;
	}
	
	Iterator begin()
	{
		return Head;
	}

	const Iterator end()const
	{
		return nullptr;
	}
	
	Iterator end()
	{
		return nullptr;
	}

	List()
	{
		Head = Tail = nullptr;
		size = 0;
		//cout << "LConst:\t" << this << endl;
	}

	List(const initializer_list<int>& il) :List()
	{
		for (const int* it = il.begin(); it != il.end(); it++)
		{
			push_back(*it);
		}
	}

	List(const List& other) :List()
	{
		for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)
			push_back(Temp->Data);
		//cout << "CopyConst:" << this << endl;
	}

	List(List&& other)
	{
		this->Head = other.Head;
		this->Tail = other.Tail;
		this->size = other.size;
		other.Head = other.Tail = nullptr;
		//cout << "MoveConst:" <<this<< endl;
	}

	~List()
	{
		while (Head)pop_back();
		//cout << "LDestruc:\t" << this << endl;
	}

	//operators

	List& operator=(const List& other)
	{
		if (this == &other)return *this;
		while (Head)pop_front();
		for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)
			push_back(Temp->Data);
		//cout << "CopyAssighConst:\t" << this << endl;
		return *this;
	}

	List& operator=(List&& other)
	{
		while (Head)pop_front();
		this->Head = other.Head;
		this->Tail = other.Tail;
		this->size = other.size;
		other.Head = other.Tail = nullptr;
		//cout << "MoveAssign:\t" << this << endl;
		return *this;
	}

	//adding elements

	void push_front(int Data)
	{
		if (Head == nullptr && Tail == nullptr)
		{
			Head = Tail = new Element(Data);
			size++;
			return;
		}
		//Head = new Element(Data, Head);
		/*Element* New = new Element(Data);
		New->pNext = Head;
		Head->pPrev = New;
		Head = New;*/
		Head = Head->pPrev = new Element(Data, Head);
		size++;
	}

	void push_back(int Data)
	{
		if (Head == nullptr && Tail == nullptr)
		{
			Head = Tail = new Element(Data);
			size++;
			return;
		}
		//Head = new Element(Data, Head);
		/*Element* New = new Element(Data);
		New->pPrev = Tail;
		Tail->pNext = New;
		Tail = New;*/
		Tail = Tail->pNext = new Element(Data, nullptr, Tail);
		size++;
	}

	void insert(int Index, int Data) 
	{
		if (Index > size)return;
		if (Index == size)
		{
			push_back(Data);
			return;
		}
		if (Index == 0)
		{
			push_front(Data);
			return;
		}
		
		Element* Temp;
		if (Index < size / 2)
		{
			Temp = Head;
			for (int i = 0; i < Index; i++)
				Temp = Temp->pNext;
		}
		else
		{
			Temp = Tail;
			for (int i = 0; i < size - Index - 1; i++)
				Temp = Temp->pPrev;
		}
		Element* New = new Element(Data);
		New->pNext = Temp;
		New->pPrev = Temp->pPrev;
		Temp->pPrev->pNext = New;
		Temp->pPrev = New;
		Temp->pPrev = Temp->pPrev->pNext = new Element(Data, Temp, Temp->pPrev);
		size++;
	}

	//remove

	void pop_front()
	{
		if (Head == Tail)
		{
			delete Head;
			Head = Tail = nullptr;
			return;
		}
		Head = Head->pNext;
		delete Head->pPrev;
		Head->pPrev = nullptr;
		size--;
	}

	void pop_back()
	{
		if (Head == Tail)
		{
			delete Head;
			Head = Tail = nullptr;
			return;
		}
		Tail = Tail->pPrev;
		delete Tail->pNext;
		Tail->pNext = nullptr;
		size--;
	}

	void erase(int Index)
	{
		if (Index == 0)
		{
			pop_front();
			return;
		}
		if (Index == size - 1)
		{
			pop_back();
			return;
		}
		if (Index >= size)return;
		Element* Temp;
		if (Index < size / 2)
		{
			Temp = Head;
			for (int i = 0; i < Index; i++)
			{
				Temp = Temp->pNext;
			}
		}
		else
		{
			Temp = Tail;
			for (int i = 0; i < size - Index - 1; i++)
				Temp = Temp->pPrev;
		}
		Temp->pPrev->pNext = Temp->pNext;
		Temp->pNext->pPrev = Temp->pPrev;
		delete Temp;
		
	}


	void print()
	{
		for (Element* Temp = Head; Temp; Temp = Temp->pNext)
			cout << Temp << endl << Temp->pPrev << "\t" << Temp->Data << "\t" << Temp->pNext << endl;
	}

	void print_reverse()
	{
		for (Element* Temp = Tail; Temp; Temp = Temp->pPrev)
			cout << Temp << endl << Temp->pPrev << "\t" << Temp->Data << "\t" << Temp->pNext << endl;
	}

	friend List operator+(const List& left, const List& right);
};

List operator+(const List& left, const List& right)
{
	List cat = left;
	/*for (List::Element* Temp = right.Head; Temp; Temp = Temp->pNext)
		cat.push_back(Temp->Data);*/
	for (List::Iterator it = right.begin(); it != right.end(); it++)
	{
		cat.push_back(*it);
	}
	return cat;
}

void main()
{
	/*int n;
	cout << "Write size of list: "; cin >> n;
	List list;
	for (int i = 0; i < n; i++)
	{
		list.push_back(rand() % 100);
	}
	list.print();
	list.pop_back();
	list.print();*/

	/*List list;
	list.push_back(3);
	list.push_back(3);
	list.push_back(3);
	list = list;*/



}