#pragma once
#include<iostream>
#include"poklon.h"
#include<fstream>
using namespace std;
class Cokolada : public Poklon
{
	int prcnt_kakaa;

public:
	Cokolada() : Poklon()
	{
		prcnt_kakaa = 0;
	}
	Cokolada(int cen, int bm, int pk) : Poklon(cen, bm)
	{
		prcnt_kakaa = pk;
	}
	~Cokolada() {}

	void print() override
	{
		cout << "cena: " << cena << "broj masnica: " << broj_masnica << "procenat kakaa: " << prcnt_kakaa << endl;
	}
	int vecibrm() override
	{
		return broj_masnica * 2;
	}
	
	void upisi(ofstream& o) override {
		o << "cena: " << cena << "broj masnica: " << broj_masnica << "procenat kakaa: " << prcnt_kakaa << endl;
	}
};

