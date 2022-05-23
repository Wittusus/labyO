#include <iostream>
using namespace std;

class Wielomian
{
	int stopien_wielomianu;
	double* tab_wspol;
public:
	Wielomian()
	{

	}
	Wielomian(int s, double* wsp)
	{
		this->stopien_wielomianu = s;
		this->tab_wspol = wsp;
	}
	int getS()
	{
		return stopien_wielomianu;
	}
	void setData(int s, double* wsp)
	{
		this->stopien_wielomianu = s;
		this->tab_wspol = wsp;
	}
	friend ostream& operator<<(ostream& str, Wielomian w);
	friend Wielomian operator +(Wielomian const& wie, Wielomian const& wiel);
	//friend Wielomian operator *(Wielomian const& wi, double d);
};
ostream& operator<<(ostream& str, Wielomian w)
{
	for (int i = w.getS(); i >= 0; i--)
	{
		if (i > 1)
		{
			if (i != w.getS() && w.tab_wspol[i] > 0)
			{
				str << " + ";
			}
			if (w.tab_wspol[i] == 1)
			{
				str << "x^" << i << " ";
			}
			else if (w.tab_wspol[i] != 0)
			{
				str << w.tab_wspol[i] << "x^" << i << " ";
			}
		}
		else if (i == 1)
		{
			if (i != w.getS() && w.tab_wspol[i] > 0)
			{
				str << " + ";
			}
			if (w.tab_wspol[i] == 1)
			{
				str << "x" << " ";
			}
			else if (w.tab_wspol[i] != 0)
			{
				str << w.tab_wspol[i] << "x^" << i << " ";
			}
		}
		else
		{
			if (w.tab_wspol[i] > 0)
			{
				str << " + ";
			}
			if (w.tab_wspol[i] != 0)
			{
				str << w.tab_wspol[i];
			}
		}
	}
	str << '\n';
	return str;
}
Wielomian operator +(Wielomian const& wie, Wielomian const &wiel)
{
	int hi;
	Wielomian wyn;
	if (wie.stopien_wielomianu > wiel.stopien_wielomianu)
	{
		hi = wie.stopien_wielomianu;
		wyn.setData(wie.stopien_wielomianu, wie.tab_wspol);
		for (int i = wiel.stopien_wielomianu; i >= 0; i--)
		{
			if (wiel.tab_wspol[i] != NULL)
			{
				wyn.tab_wspol[i] = wyn.tab_wspol[i] + wiel.tab_wspol[i];
			}
		}
	}
	else
	{
		hi = wiel.stopien_wielomianu;
		wyn.setData(wiel.stopien_wielomianu, wiel.tab_wspol);
		for (int i = wie.stopien_wielomianu; i >= 0; i--)
		{
			if (wie.tab_wspol[i] != NULL)
			{
				wyn.tab_wspol[i] = wyn.tab_wspol[i] + wie.tab_wspol[i];
			}
		}
	}
	return wyn;
}
//Wielomian operator *(Wielomian const& wi, double d)
//{
	/*
	Wielomian wyn(wi.stopien_wielomianu, wi.tab_wspol);
	for (int i = (wi.stopien_wielomianu) + 1; i >= 0; i--)
	{
		wi.tab_wspol[i] = wi.tab_wspol[i] * d;
	}
	return wyn;
	*/
//}
int main()
{
	double* i1{ new double[2]{ -5, 1 } };
	Wielomian w1(1, i1);
	double* i2{ new double[4]{ 1, 0, -7, -3.4 } };
	Wielomian w2(3, i2);
	double* i3{ new double[6]{ 0, 0, 0, -7, 0, 7.8 } };
	Wielomian w3(5, i3);
	cout << "W1: " << w1 << '\n'; cout << "W2: " << w2 << '\n'; cout << "W3: " << w3 << '\n';
	cout << "suma: " << (w1 + w2) + w3 << '\n';
	//cout << "mnozony: " << w2 * 3 << '\n';
	delete[] i1; delete[] i2; delete[] i3;
	return 0;
}