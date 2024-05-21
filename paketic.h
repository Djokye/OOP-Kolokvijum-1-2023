#pragma once
#include<iostream>
#include"poklon.h"
#include"cokolada.h"
#include"igracka.h"
#include<fstream>
using namespace std;
class Paketic
{
	Poklon** pokloni;
	int brmax,tren;

public:
	Paketic()
	{
		tren = 0;
		brmax = 0;
		pokloni = new Poklon * [1];
	}
	Paketic(int brp)
	{
		brmax = brp;
		pokloni = new Poklon * [brmax];
		tren = 0;
	}
	virtual ~Paketic()
	{
		if (pokloni != nullptr)
		{
			for (int i = 0; i < tren; i++)
			{
				delete pokloni[i];
			}
			delete[] pokloni;
		}
		pokloni = nullptr;
	}

	int BrojPoklona()
	{
		return brmax;
	}
	
	void Add(Poklon* p)
	{
		if (tren<brmax)
		{
			pokloni[tren] = p;
			tren++;
		}
	}
	void print()
	{
		for (int i = 0; i < tren; i++)
		{
			pokloni[i]->print();
		}
	}

	Poklon *Max()
	{
		if (tren > 0)
		{
			int najveci = 0;
			int j = 0;
			for (int i = 0; i < tren; i++)
			{
				if (pokloni[i]->vecibrm() > najveci)
				{
					najveci = pokloni[i]->vecibrm();
					j = i;
				}
			}
			return pokloni[j];
		}
		else throw "nema pokloncica";
	}

	void RemoveMinimum()
	{
		if (tren > 0)
		{
			int najmanji = pokloni[0]->vecibrm();
			int j = 0;
			for (int i = 0; i < tren; i++)
			{
				if (pokloni[i]->vecibrm() < najmanji)
				{
					najmanji = pokloni[i]->vecibrm();
					j = i;
				}
			}
			for (int i = j; i < tren-1; i++)
			{
				pokloni[i] = pokloni[i + 1];
			}
			tren--;
		}
		else throw "nema pokloncica";
	}

	void Save(const char* putanja)
	{
		ofstream izlaz(putanja);
		if (izlaz.is_open())
		{
			for (int i = 0; i < tren; i++)
			{
					pokloni[i]->upisi(izlaz);
			}
		}
		else throw "nisi ga otvorio";
	}

	friend Paketic operator+(Paketic& p1, Paketic& p2)
	{
		Paketic p(p1.tren + p2.tren);
		for (int i = 0; i < p1.tren; i++)
		{
			p.Add(p1.pokloni[i]);
		}
		for (int i = 0; i < p2.tren; i++)
		{
			p.Add(p2.pokloni[i]);
		}
		return p;
	}
};

