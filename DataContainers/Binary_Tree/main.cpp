#include<iostream>
using namespace std;

#define tab "\t"

class Tree
{
	class Element
	{
		int Data;
		Element* pLeft;
		Element* pRight;
	public:
		

		Element(int Data, Element* pLeft = nullptr, Element* pRight = nullptr)
		{
			this->Data = Data;
			this->pLeft = pLeft;
			this->pRight = pRight;
			cout << "EConst:\t" << this << endl;
		}

		~Element()
		{
			cout << "EDestruc:\t" << this << endl;
		}
		friend class Tree;

	}*Root; //ukazatel na kornevoy elemnt
public:

	Element* getRoot()
	{
		return Root;
	}

	Tree() :Root(nullptr)
	{
		//Root = nullptr;
		cout << "TConst:\t" << this << endl;
	}

	~Tree()
	{
		clear(Root);
		cout << "TDestruc:\t" << this << endl;
	}

	void insert(int Data, Element* Root)//zdec Elemtnt*Root- eukazetel na vetku
	{
		if (this->Root == nullptr)this->Root = new Element(Data);
		if (Root == nullptr)return;
		if (Data < Root->Data)
		{
			if (Root->pLeft == nullptr)
			{
				Root->pLeft = new Element(Data);
			}
			else
			{
				insert(Data, Root->pLeft);
			}
		}

		else
		{
			/*if (Root->pRight == nullptr)
			{
				Root->pRight = new Element(Data);
			}
			else
			{
				insert(Data, Root->pRight);
			}*/

			if (Root->pRight)insert(Data, Root->pRight);
			else Root->pRight = new Element(Data);
		}
	}

	int minValue(Element* Root)
	{
		if (Root->pLeft != nullptr)
			return minValue(Root->pLeft);
		else
			return Root->Data;
	}

	int maxValue(Element* Root)
	{
		if (Root->pRight != nullptr)
			return maxValue(Root->pRight);
		else
			return Root->Data;
	}

	int size(Element* Root)
	{
		if (Root == nullptr)return 0;
		else return size(Root->pLeft) + size(Root->pRight) + 1;
	}

	int sum(Element* Root)
	{
		return Root ? sum(Root->pLeft) + sum(Root->pRight) + Root->Data : 0;
	}

	void print(Element* Root)
	{
		if (Root == nullptr)return;
		print(Root->pLeft);
		cout << Root->Data << tab;
		print(Root->pRight);
	}

	void clear(Element* Root)
	{
		if (Root == nullptr)return;
		clear(Root->pLeft);
		clear(Root->pRight);
		delete Root;
	}
	
};

void main()
{
	int n;
	cout << "Write a nubber of el: "; cin >> n;
	Tree tree;
	for (int i = 0; i < n; i++)
	{
		tree.insert(rand() % 100, tree.getRoot());
	}
	cout << "Size" << tree.size(tree.getRoot());
}