#include"ForwardList.h"

template<typename T>
unsigned int ForwardList<T>::get_size() const
{
	return size;
}

template<typename T>
const Element<T>* ForwardList<T>::getHead()const
{
	return Head;
}


template<typename T>
Iterator<T> ForwardList<T>::begin()
{
	return Head;
}

template<typename T>
Iterator<T> ForwardList<T>::end()
{
	return nullptr;
}

template<typename T>
ForwardList<T>::ForwardList()
{
	this->size = 0;
	this->Head = nullptr;

	cout << "LConst:\t" << this << endl;
}

template<typename T>
ForwardList<T>::ForwardList(std::initializer_list<T> il)
{
	cout << typeid(il.begin()).name() << endl;
	for (T i : il)
	{
		push_back(i);
	}
	cout << "ILConst:\t" << this << endl;
}

template<typename T>
ForwardList<T>::ForwardList(const ForwardList<T>& other)
{
	for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)
		push_back(Temp->Data);
	cout << "LCopyConstructor:\t" << this << endl;
}

template<typename T>
ForwardList<T>::ForwardList(ForwardList<T>&& other)
{
	this->size = other.size;
	this->Head = other.Head;
	other.Head = nullptr;
	cout << "LMoveConst: " << this << endl;
}

template<typename T>
ForwardList<T>::~ForwardList()
{

	while (Head)pop_front();
	cout << "LDestruc:\t" << this << endl;
}


//operators

template<typename T>
ForwardList<T>& ForwardList<T>::operator=(const ForwardList<T>& other)
{
	if (this == &other)return *this;
	while (Head)pop_front();
	for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)
		push_back(Temp->Data);
	cout << "LCopyAssign:\t" << this << endl;
	return *this;
}

template<typename T>
ForwardList<T>& ForwardList<T>::operator=(ForwardList<T>&& other)
{
	while (Head)pop_front();
	this->size = other.size;
	this->Head = other.Head;
	other.Head = nullptr;
	cout << "LMoveAssign: " << this << endl;
	return *this;
}

//Adding Elements

template<typename T>
T& ForwardList<T>::operator[](int index)
{
	if (index >= size)throw std::exception("Out of range");
	Element* Temp = Head;
	for (int i = 0; i < index; i++)
	{
		Temp = Temp->pNext;
	}
	return Temp->Data;
}

template<typename T>
void ForwardList<T>::push_front(T Data)
{
	/*Element* New = new Element(Data);
	New->pNext = Head;
	Head = New;*/
	Head = new Element<T>(Data, Head);
	size++;
}
template<typename T>
void ForwardList<T>::push_back(T Data)
{
	if (Head == nullptr)
	{
		push_front(Data);
		return;
	}
	Element<T>* New = new Element<T>(Data);
	Element<T>* Temp = Head;
	while (Temp->pNext != nullptr)
	{
		Temp = Temp->pNext;
	}
	Temp->pNext = New;
	size++;
}

template<typename T>
void ForwardList<T>::insert(int index, T data)
{
	if (index > Element::count)return;
	if (index == 0)
	{
		push_front(data);
		return;
	}
	Element<T>* New = new Element<T>(data);
	Element<T>* Temp = Head;
	for (int i = 0; i < index - 1; i++)
	{
		Temp = Temp->pNext;
	}
	New->pNext = Temp->pNext;
	Temp->pNext = New;
	size++;
}

template<typename T>
void ForwardList<T>::pop_front()
{
	if (Head == nullptr)return;
	Element<T>* erase_element = Head;	//1) Запоминаем адрес удаляемого элемента:
	Head = Head->pNext;		//2) Исключаем элемент из списка:
	delete erase_element;//3) Удаляем элемент из памяти
	size--;
}

template<typename T>
void ForwardList<T>::pop_back()
{
	if (Head == nullptr)return;
	if (Head->pNext == nullptr)
	{
		pop_front();
		return;
	}
	Element<T>* Temp = Head;
	while (Temp->pNext->pNext != nullptr)
		Temp = Temp->pNext;
	delete Temp->pNext;
	Temp->pNext = nullptr;
	size--;
}

template<typename T>
void ForwardList<T>::print()const
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
	cout << "Total count of elements: " << Element<T>::count << endl;
}

