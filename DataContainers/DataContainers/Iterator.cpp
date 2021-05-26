#include"Iterator.h"

template <typename T>
Iterator<T>::Iterator(Element<T>* Temp) :Temp(Temp)
{
	//cout << "IConst:\t" << this << endl;
}

template <typename T>
Iterator<T>::~Iterator()
{
	//cout << "IDectruc:\t" << this << endl;
}

template <typename T>
Iterator<T>& Iterator<T>::operator++()
{
	Temp = Temp->pNext;
	return *this;
}

template <typename T>
Iterator<T> Iterator<T>::operator++(int)
{
	Iterator old = *this;
	Temp = Temp->pNext;
	return old;
}

template<typename T>
bool Iterator<T>::operator==(const Iterator<T>& other)const
{
	return this->Temp == other.Temp;
}

template<typename T>
bool Iterator<T>::operator!=(const Iterator<T>& other)const
{
	return this->Temp != other.Temp;
}

template<typename T>
const Element<T>* Iterator<T>::operator->()const
{
	return Temp;
}

template<typename T>
Element<T>* Iterator<T>::operator->()
{
	return Temp;
}

template<typename T>
const T& Iterator<T>::operator*() const
{
	return Temp->Data;
}

template<typename T>
T& Iterator<T>:: operator*()
{
	return Temp->Data;
}