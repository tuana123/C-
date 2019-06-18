#include "DengueVirus.h"
#include <string>
#include <iostream>
#include <iomanip>

DengueVirus::DengueVirus()
{
	this->DoBorn();
	this->InitResistance();
}

DengueVirus::~DengueVirus()
{
	this->DoDie();
}

DengueVirus::DengueVirus(DengueVirus *dengue)
{
	
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
	//delete[]this->m_protein;
	this->m_resistance = 0;
}

std::list<MyVirus*> DengueVirus::DoClone()
{
	std::list<MyVirus*> listVirus;
	DengueVirus *p1 = new DengueVirus();
	DengueVirus *p2 = new DengueVirus();
	std::string str = this->m_dna;
	for (int i = 0; i < str.size(); i++)
	{
		p1->m_dna[i] = str[i];
		p2->m_dna[i] = str[i];
	}
	for (int i = 0; i < sizeof(this->m_protein); i++)
	{
		p1->m_protein[i] = this->m_protein[i];
		p2->m_protein[i] = this->m_protein[i];
	}
	p1->m_resistance = this->m_resistance;
	p2->m_resistance = this->m_resistance;
	listVirus.push_back(p1);
	listVirus.push_back(p2);
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
	std::cout << this->m_protein << std::setw(20) << std::right << this->m_resistance << std::endl;
}
