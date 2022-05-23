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
	friend void wypisz(punkt p);
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
	punkt(int x, int y)
	{
		this->setX(x);
		this->setY(y);
	}
	punkt()
	{

	}
};
class kwadrat
{
	punkt pp, kp;
public:
	friend void wypisz(kwadrat k);
	friend class punkt;
	void setDane(int x1, int y1, int x2, int y2)
	{
		this->pp.setX(x1); this->pp.setY(y1); this->kp.setX(x2); this->kp.setY(y2);
	}
	void print()
	{
		cout << this->pp.getX() << " " << this->pp.getY() << " " << this->kp.getX() << " " << this->kp.getY() << '\n';
	}
	int pole()
	{
		return (pow(pp.getX() - kp.getX(),2));
	}

};
class okrag
{
	punkt middle;
	int radius;
public:
	friend void wypisz(okrag o);
	friend class punkt;
	int rozlacznosc(okrag o1)
	{
		double distance = sqrt(pow(this->middle.getX() - o1.getX(), 2) + pow(this->middle.getY() - o1.getY(), 2));
		int radiusesM = sqrt(pow(this->getR() - o1.getR(), 2));
		int radiusesP = this->getR() + o1.getR();
		if (radiusesP < distance)
			return 2;
		else if (radiusesM > distance)
			return 1;

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
void wypisz(punkt p)
{
	cout << "Dane punktu:" << '\n' << "x: " << p.getX() << " y: " << p.getY() << '\n';
}
void wypisz(kwadrat k)
{
	cout << "Dane kwadratu:" << '\n' << "x poczatku: " << k.pp.getX() << " y: " << k.pp.getY() << '\n' << "x konca: " << k.kp.getX() << " y: " << k.kp.getY() << '\n';
}
void wypisz(okrag o)
{
	cout << "Dane okregu: " << '\n' << "x srodka: " << o.getX() << " y: " << o.getY() << " promien: " << o.getR() << '\n';
}
int main()
{
	srand(time(NULL));
	kwadrat tab[2];	tab[0].setDane(0, 0, 3, 3); tab[1].setDane(-8, 8, -1, 1);
	cout << "p1: " << tab[0].pole() << " p2: " << tab[1].pole() << '\n';
	okrag okr(10, 10, 5);
	okrag tabO[500];
	for (int i = 0; i < 500; i++)
	{
		int x = (rand() % 31) - 10;
		int y = (rand() % 21);
		int r = (rand() % 5) +1;
		tabO[i].setDane(x, y, r);
	}
	int rozZ = 0; int rozW = 0;
	for (int i = 0; i < 500; i++)
	{
		if (okr.rozlacznosc(tabO[i]) == 2)
			rozZ++;
		else if (okr.rozlacznosc(tabO[i]) == 1)
			rozW++;
	}
	cout << "Ilosc okregow z jaka okr jest rozlaczny zewnetrznie to " << rozZ << ", a wewnetrznie to " << rozW << '\n';
	punkt p(1, 1);
	wypisz(tab[0]); wypisz(p); wypisz(okr);
	return 0;
}