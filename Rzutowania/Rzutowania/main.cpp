#include <iostream>
#include <cmath>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int NWD(int a, int b)
{
	int pom;

	while (b != 0)
	{
		pom = b;
		b = a % b;
		a = pom;
	}
	return a;
}

class Ulamek
{
	int licznik, mianownik;
public:
	void skrocUlamek()
	{
		int n = NWD(this->getL(), this->getM());
		this->licznik = this->licznik / n;
		this->mianownik = this->mianownik / n;
	}
	Ulamek() {}
	Ulamek(int l, int m)
	{
		this->licznik = l;
		this->mianownik = m;
	}
	void setDane(int l, int m)
	{
		this->licznik = l;
		this->mianownik = m;
	}
	int getL()
	{
		return this->licznik;
	}
	int getM()
	{
		return this->mianownik;
	}
	Ulamek(int l)
	{
		this->licznik = l;
		this->mianownik = 1;
	}
	operator double() {return static_cast<double>(licznik)/static_cast<double>(mianownik);}
};

ostream& operator<<(ostream& str, Ulamek u)
{
	if (u.getM() == 1)
		str << u.getL() << " " << "(" << u.getL() << "/" << u.getM()<< ")";
	else
		str << u.getL() << "/" << u.getM();
	return str;
}

Ulamek dodaj(Ulamek u1, Ulamek u2)
{
	Ulamek wynik;
	if (u1.getM() == u2.getL())
	{
		wynik.setDane((u1.getL() + u2.getL()), u1.getM());
	}
	else
	{ 
		int l = (u1.getL() * u2.getM())+ (u2.getL() * u1.getM());
		int m = (u1.getM() * u2.getM());
		wynik.setDane(l, m);
	}
	wynik.skrocUlamek();
	return wynik;
}



double kwadratLiczby(double l)
{
	return l * l;
}

int main()
{
	Ulamek tab[3];
	tab[0].setDane(1, 2); tab[1].setDane(5, 8), tab[2].setDane(7, 9);
	cout << "Ul1: " << tab[0] << " Ul2: " << tab[1] << " Ul3: " << tab[2] << '\n';
	cout << "Dodane: " << dodaj(tab[0], tab[1]) << '\n';
	cout << "Dodane calkowite: " << dodaj(tab[0], 7) << '\n';
	cout << "Double: " << double(tab[2]) << '\n';
	cout << "Kwadrat: " << kwadratLiczby(tab[2]) << '\n';
	Ulamek ula(88, 22);
	ula.skrocUlamek();
	cout << "Skrocony: " << ula;
	return 0;
}