#pragma once
#include<iostream>
#include"poklon.h"
#include"cokolada.h"
#include"igracka.h"
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
	~Paketic()
	{
		for (int i = 0; i < tren; i++)
		{
			delete pokloni[i];
		}
		delete[] pokloni;
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
};

