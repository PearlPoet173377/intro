#pragma once

template<typename T>class Iterator;
template<typename T>class ForwardList;

template<typename T>
class Element
{
	T Data; //значение элемента
	Element* pNext;
	static int count;//укаазтель на след элемент
public:

	const Element* getpNext();

	T getData()const;

	Element(T Data, Element* pNext = nullptr);
	~Element();

	friend class Iterator<T>;
	friend class ForwardList<T>;
	friend ForwardList<T> operator+(const ForwardList<T>& left, const ForwardList<T>& right);
};