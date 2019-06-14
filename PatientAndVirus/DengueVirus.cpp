#include "DengueVirus.h"
#include <string>


DengueVirus::DengueVirus()
{
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
