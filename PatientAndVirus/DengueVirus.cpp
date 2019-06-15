#include "DengueVirus.h"
#include <string>
#include <iostream>


DengueVirus::DengueVirus()
{
	this->DoBorn();
	this->InitResistance();
}

DengueVirus::~DengueVirus()
{
	this->DoDie();
}

void DengueVirus::DoBorn()
{
	this->LoadADNIformation();
	int j = rand() % (3 - 1 + 1) + 1;
	switch (j)
	{
	case 1:
	{
		std::string str = "NS3";
		for (int i = 0; i < str.size(); i++)
		{
			this->m_protein[i] = str[i];
		}
		this->m_protein[str.size()] = '\0';
		break;
	}
		
	case 2:
	{
		std::string str = "NS5";
		for (int i = 0; i < str.size(); i++)
		{
			this->m_protein[i] = str[i];
		}
		this->m_protein[str.size()] = '\0';
	}
	
	case 3:
	{
		std::string str = "E";
		for (int i = 0; i < str.size(); i++)
		{
			this->m_protein[i] = str[i];
		}
		this->m_protein[str.size()] = '\0';
	}
	}
	
}

void DengueVirus::DoDie()
{
	delete[] this->m_dna;
	delete[]this->m_protein;
	this->m_resistance = 0;
}

std::list<MyVirus*> DengueVirus::DoClone()
{
	std::list<MyVirus*> listVirus;
	DengueVirus *p;
	p = this;
	/*p->m_dna = this->m_dna;
	for (int i = 0; i < sizeof(this->m_protein); i++)
	{
		p->m_protein[i] = this->m_protein[i];
	}
	p->m_resistance = this->m_resistance;*/
	listVirus.push_back(p);
	listVirus.push_back(p);
	return listVirus;
}

void DengueVirus::InitResistance()
{
	std::string str = this->m_protein;
	if (str == "NS3")
	{
		this->m_resistance = rand() % (10 - 1 + 1) + 1;
	}
	else if(str == "NS5")
	{
		this->m_resistance = rand() % (20 - 11 + 1) + 11;
	}
	else
	{
		this->m_resistance = rand() % (30 - 21 + 1) + 21;
	}
}

void DengueVirus::GetNameVirus()
{
	std::cout << "\nDengue Virus " << this->m_protein;
	std::cout << "\nResistance " << this->m_resistance;
}
