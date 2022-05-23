#include <iostream>
#include <cmath>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

class punkt
{
	int x, y;
public:
	void setX(int i)
	{
		this->x = i;
	}
	int getX()
	{
		return this->x;
	}
	void setY(int i)
	{
		this->y = i;
	}
	int getY()
	{
		return this->y;
	}
};
class odcinek
{
	punkt start, end;
public:
	int length()
	{
		return sqrt(pow(this->end.getX() - this->start.getX(), 2) + pow(this->end.getY() - this->start.getY(), 2));
	}
	friend class punkt;
	void setDane(int x1, int y1, int x2, int y2)
	{
		this->start.setX(x1); this->start.setY(y1); this->end.setX(x2); this->end.setY(y2);
	}
	void print()
	{
		cout << this->start.getX() << " " << this->start.getY() << " " << this->end.getX() << " " << this->end.getY() << '\n';
	}
};
class okrag
{ 
	punkt middle;
	int radius;
public:
	friend class punkt;
	int stycznosc(okrag o1)
	{
		int length= sqrt(pow(this->middle.getX() - o1.getX(), 2) + pow(this->middle.getY() - o1.getY(), 2));
		int radiuses = this->getR() + o1.getR();
		if (radiuses > length)
			return 2;
		else if (radiuses = length)
			return 1;
		else
			return 0;
		
	}
	okrag()
	{

	}
	okrag(int x, int y, int r)
	{
		this->middle.setX(x);
		this->middle.setY(y);
		this->radius = r;
	}
	void setDane(int x, int y, int r)
	{
		this->middle.setX(x);
		this->middle.setY(y);
		this->radius = r;
	}
	int getX()
	{
		return this->middle.getX();
	}
	int getY()
	{
		return this->middle.getY();
	}
	int getR()
	{
		return this->radius;
	}
	void print()
	{
		cout << " " << this->getX() << " " << this->getY() << " " << this->getR() << '\n';
	}
};
void wypisz(odcinek o)
{

}
int main()
{
	srand(time(NULL));
	odcinek arr[3];
	arr[0].setDane(-4, 1, 6, 1); arr[1].setDane(0, 6, 1, 1); arr[2].setDane(3, 8, -3, 2);
	for (int i = 0; i < 3; i++)
	{
		cout << "dl" << i << ": " << arr[i].length() << '\n';
	}
	okrag okr(0, 0, 6);
	okrag tab[10000];
	for (int i = 0; i < 10000; i++)
	{
		int x = (rand() % 41) - 20;
		int y = (rand() % 41) - 20;
		int r = (rand() % 20) + 1;
		tab[i].setDane(x, y, r);
	}
	int stykiZ = 0;
	int stykiW = 0;
	for (int i = 0; i < 10000; i++)
	{
		if (okr.stycznosc(tab[i]) == 1)
			stykiZ++;
		else if (okr.stycznosc(tab[i]) == 2)
			stykiW++;
	}
	cout << "Ilosc okregow z jaka styka sie okr zewnetrznie to " << stykiZ << ", a wewnetrznie to " << stykiW << '\n';
	return 0;
}