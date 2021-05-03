#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

class Animal
{
public:
	virtual ~Animal() {};
	
	virtual void sound()const = 0; //чисто вируальный метод, благодаря которому класс явл абстрактныйм
	
};

class Cat :public Animal
{
	/*void sound()const
	{
		cout << "Meow" << endl;
	}*/
};

class Tiger :public Cat
{
	~Tiger()
	{

	}

	void sound()const
	{
		cout << "Roar" << endl;
	}
};

class HomeCat :public Cat
{
	~HomeCat()
	{

	}


	void sound()const
	{
		cout << "Meow" << endl;
	}
};

class Dog :public Animal
{
	~Dog()
	{

	}

	void sound()const
	{
		cout << "Wof" << endl;
	}
};


void main()
{
	/*Cat tom;
	Dog rax;*/

	Animal* zoo[] =
	{
		new HomeCat,
		new Dog,
		new Tiger,
		new Dog,
		new HomeCat
	};

	for (int i = 0; i < sizeof(zoo) / sizeof(Animal*); i++)
	{
		zoo[i]->sound();
	}

}