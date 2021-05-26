#include "Element.h"

template<typename T>
int Element<T>::count = 0;

template <typename T>
const Element<T>* Element<T>::getpNext()
{
	return pNext;
}

template<typename T>
T Element<T>::getData()const
{
	return Data;
}

template <typename T>
Element<T>::Element(T Data, Element* pNext) :Data(Data), pNext(pNext)
{
	count++;
	//cout << "EConst:\t" << this << endl;
}
template<typename T>
Element<T>::~Element()
{
	count--;
	//cout << "EDestruc:\t" << this << endl;
}
