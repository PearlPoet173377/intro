#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

class Shape
{
	string color;
public:
	
	Shape(const string color)
	{
		this->color = color;
	}
	
	virtual double area()const = 0;
	virtual double perimeter()const = 0;
	virtual void draw()const = 0;
};

class Square :public Shape
{
	double side;
public:
	double get_side()const
	{
		return side;
	}

	void set_side(double side)
	{
		if (side > 0)this->side = side;
		else this->side = 1;
	}

	explicit Square(double side, const string& color="white"):Shape(color)
	{
		set_side(side);
	}

	~Square()
	{

	}

	double area() const
	{
		return side * side;
	}

	double perimeter()const
	{
		return side * 4;
	}

	void draw()const
	{
		for (int i = 0; i < side; i++)
		{
			for (int j = 0; j < side; j++)
			{
				cout << "* ";
			}
			cout << endl;
		}
	}
};

class Rectanangle :public Shape
{
	double a;
	double b;
public:

	double get_a()const
	{
		return a;
	}

	double get_b()const
	{
		return b;
	}

	void set_a(double a)
	{
		if (a > 0)this->a = a;
		else this->a = 1;
	}

	void set_b(double b)
	{
		if (b > 0)this->b = b;
		else this->b = 1;
	}

	explicit Rectanangle(double a,double b, const string& color = "white") :Shape(color)
	{
		set_a(a);
		set_b(b);
	}

	~Rectanangle()
	{

	}

	double area() const
	{
		return a * b;
	}

	double perimeter()const
	{
		return 2 * a + 2 * b;
	}

	void draw()const
	{
		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < b; j++)
			{
				cout << "* ";
			}
			cout << endl;
		}
	}

};


void main()
{
	Rectanangle square(5,7);
	cout << "Area:\t" << square.area() << endl;
	cout << "Perim:\t" << square.perimeter() << endl;
	square.draw();
}