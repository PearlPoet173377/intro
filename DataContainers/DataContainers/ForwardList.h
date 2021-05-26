#pragma once
#include"Iterator.h"


template<typename T>
class ForwardList
{
	unsigned int size;
	Element<T>* Head; //указатель на началтный элемент списка
public:
	unsigned int get_size() const;
	const Element<T>* getHead()const;
	Iterator<T> begin();

	Iterator<T> end();
	ForwardList();

	ForwardList(std::initializer_list<T> il);

	ForwardList(const ForwardList<T>& other);
	ForwardList(ForwardList<T>&& other);
	~ForwardList();


	//operators

	ForwardList<T>& operator=(const ForwardList<T>& other);

	ForwardList<T>& operator=(ForwardList<T>&& other);

	//Adding Elements

	T& operator[](int index);

	void push_front(T Data);
	void push_back(T Data);

	void insert(int index, T data);

	void pop_front();

	void pop_back();
	void print()const;

};