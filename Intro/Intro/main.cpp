#include<iostream>
using namespace std; /// в виде функции не получается

#define tab "\t"
class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
	
	//Constructor
	/*Point()
	{
		x = y = 0;
		cout << "DefConstructors:\t" << this << endl;
	}

	Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "Single Argument Constructor:" << this << endl;
	}*/

	Point(double x=0, double y=0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructors:\t" << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t" << this << endl;
	}
	

	//Operators:
	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssigned:\t" << this << endl;
		return *this;
	}

	Point& operator+=(const Point& other)
	{
		this->x += other.x;
		this->y += other.y;
		cout << "Operator+=" << this << endl;
		return *this;
	}
	//increment/decrement
	Point& operator++()
	{
		this->x++;
		this->y++;
		return *this;
	}
	Point& operator++(int)
	{
		Point old = *this;
		this->x++;
		this->y++;
		return old;
	}

	//Methods
	void print()const
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}
	Point distance()
	{
		if (x < y)
		{
			double buf = x;
			x = y;
			y = buf;
		}
		cout << "Distance: " << x - y << endl;
		return x - y;
	}
};

Point operator+(const Point& left, const Point& right)
{
	Point result;
	result.set_x(left.get_x() + right.get_x());
	result.set_y(left.get_y() + right.get_y());
	cout<<"Global Plus: "<<endl;
	return result;
}

Point operator-(const Point& left, const Point& right)
{
	Point result(left.get_x() - right.get_x(), left.get_y() - right.get_y());
	cout << "Global minus: " << endl;
	return result;
}

Point operator*(const Point& left, const Point& right)
{
	cout << "Global multiply: " << endl;
	return Point
	(
		left.get_x() * right.get_x(),
		left.get_y() * right.get_y()
	);
}

Point operator/(const Point& left, const Point& right)
{
	cout << "Global devide: " << endl;
	return Point
	(
		left.get_x() / right.get_x(),
		left.get_y() / right.get_y()
	);
}

//#define INTRO
//#define CONSTRUCTORS_CHECK
//#define ARIFMETICAL_OPERATORS

void main()
{
#ifdef INTRO
	int a;// объявляем переменную типа int
	A.x = 2;
	A.y = 3;
	cout << A.x << tab << A.y << endl;

	Point* pA = &A;
	cout << pA->x << tab << pA->y << endl;
	cout << sizeof(A) << endl;
	cout << sizeof(pA) << endl;
#endif
#ifdef CONSTRUCTORS_CHECK
	Point A;
	A.print();
	Point B(2, 3);
	B.print();

	Point C = 5;//Single Argument Constructor
	Point D(8);//Single argument constructor второй метод вызова
	int b(3);//якобы для типа int вызывается конст с 1 параметром
	cout << int() << endl;//якобы вызывается конс с 1 парам для типа int
	                      //и возращ значение по умолч для типа int
	                      //так можно получить знач по умолч для любого типа
	Point E{ 13 };//Songle Arg Const третий метод вызова

	Point F = B;
	F.print();
	Point G;
	G = F;
#endif
	/*int a, b, c;
	a = b = c = 0;

	Point A, B, C;
	A = B = C = Point();*/

#ifdef ARIFMETICAL_OPERATORS
	Point A(2, 3);
	Point B(3, 4);
	Point C = A + B;
	C.print();
	(A - B).print();
	(A * B).print();
	(A / B).print();
#endif ARIFMETICAL_OPERATORS

	Point A(2, 3);
	Point B();
	A.distance();
}