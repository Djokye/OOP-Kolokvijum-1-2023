#pragma once
#include<iostream>
using namespace std;
class Poklon
{
protected:
	int cena, broj_masnica;

public:
	Poklon()
	{
		cena = 0;
		broj_masnica = 0;
	}
	Poklon(int cen, int bm)
	{
		cena = cen;
		broj_masnica = bm;
	}
	~Poklon() {}

	virtual void print() = 0; 
	virtual int vecibrm() = 0;
};

