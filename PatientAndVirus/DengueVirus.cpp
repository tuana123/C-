#include "DengueVirus.h"
#include <string>


DengueVirus::DengueVirus()
{
	this->DoBorn();
	this->InitResistance();
}


DengueVirus::~DengueVirus()
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
}

MyVirus* DengueVirus::DoClone()
{
	DengueVirus *p;
	p->m_dna = this->m_dna;
//	p->m_protein = this->m_protein;
	p->m_resistance = this->m_resistance;
	return p;
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
