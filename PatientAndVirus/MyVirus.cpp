#include "MyVirus.h"
#include <fstream>
#include <iostream>
#include <string>
MyVirus::MyVirus()
{
}

MyVirus::~MyVirus()
{
}

MyVirus::MyVirus(const MyVirus *p)
{
	this->m_dna = p->m_dna;
	this->m_resistance = p->m_resistance;
}

void MyVirus::Setm_resitance(int _m_resistance)
{
	this->m_resistance = _m_resistance;
}

int MyVirus::Getm_resitance()
{
	return this->m_resistance;
}

void MyVirus::Setm_dna(char *_m_dna)
{
	this->m_dna = _m_dna;
}

void MyVirus::LoadADNIformation()
{
	std::string str;
	std::ifstream infile;
	infile.open("ATGX.bin");
	if (infile.is_open())
	{
		infile >> str;
		char *c = new char[str.size() + 1];
		for (int i = 0; i < str.size(); i++)
		{
			c[i] = str[i];
		}
		c[str.size()] = '\0';
		this->m_dna = c;
		infile.close();
	}
	else
	{
		std::cout << "Erros";
	}
}

void MyVirus::Reduce_Resistance(int medicine_resistance)
{
	this->m_resistance = this->m_resistance - medicine_resistance;
}
