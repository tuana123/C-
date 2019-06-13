#include "FluVirus.h"
#include <iostream>


FluVirus::FluVirus()
{
	this->InitResistance();
}

FluVirus::~FluVirus()
{
	DoDie();
}

void FluVirus::DoBorn()
{
	this->LoadADNIformation();
	int color = rand() % (2);
	if (color == 1)
	{
		this->m_color = 0x0000ff;
		std::cout << "Virus Blue was Born";
	}
	std::cout << "Virus Blue was Red";
	this->m_color = 0xff0000;
}

void FluVirus::DoDie()
{
	delete[] this->m_dna;
	this->m_resistance = 0;
}

void FluVirus::DoClone()
{
}

void FluVirus::InitResistance()
{
	this->m_resistance = rand() % (30 - 10 + 1) + 10;
}
