#pragma once
#include<iostream>
#include"poklon.h"
#include <ctype.h>
#include<fstream>
using namespace std;
class Igracka : public Poklon
{
	char* materijal;

public:
	Igracka() : Poklon()
	{
		materijal = nullptr;
	}
	Igracka(int cen, int bm, const char* mat) : Poklon(cen, bm)
	{
		materijal = new char[strlen(mat) + 1];
		strncpy(materijal, mat, strlen(mat) + 1);
	}
	~Igracka()
	{
		if (materijal != nullptr)
		{
			delete materijal;
			materijal = nullptr;
		}
	}

	void print() override
	{
		cout << "cena: " << cena << "broj masnica: " << broj_masnica << "materijal: " << materijal << endl;
	}

	int vecibrm() override
	{
		return broj_masnica + 2;
	}

	void upisi(ofstream& o) override {
		o << "cena: " << cena << "broj masnica: " << broj_masnica << "procenat kakaa: " << materijal << endl;
	}
};

