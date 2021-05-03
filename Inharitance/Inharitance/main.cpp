#include<iostream>
#include<string>
using namespace std;

class Box
{
	double width;
	double height;
	double lenght;
	string material;
public:
	double get_width()const
	{
		return width;
	}
	
	double get_height()const
	{
		return height;
	}

	double get_lenght()const
	{
		return lenght;
	}

	const string& get_material()const
	{
		return this->material;
	}


	//Const

	Box(double width, double height, double lenght, const string& material):
		width(width), height(height), lenght(lenght), material(material)
	{
		cout << "BoxConst:\t" << this << endl;
	}

	~Box()
	{
		cout << "BoxDectruc:\t" << this << endl;
	}


	//methods
	void info()const
	{
		cout << "Dimesions:\t" << width << "x" << height << "x" << lenght << endl;;
		cout << "Material;\t" << material << endl;
	}
};

class GiftBox :public Box
{
	string cover;
public:
	const string& get_cover()const
	{
		return cover;
		
	}
	GiftBox(double width, double height, double lenght, const string& material,const string&cover) :
		Box(width, height, lenght, material)
	{
		this->cover = cover;
		cout << "GiftBoxConst:\t" << this << endl;
	}

	~GiftBox()
	{
		cout << "GiftBoxDestruc:\t" << this << endl;
	}

	void info()const
	{
		Box::info();
		cout << "Cover:\t" << cover << endl;
	}

};

void main()
{
	/*Box box(2, 5, 8, "paper");
	box.info();*/

	GiftBox giftbox(2,5,8,"paper","cats");
	giftbox.info();

}