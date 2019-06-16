#include "Patient.h"
#include "FluVirus.h"
#include "DengueVirus.h"

Patient::Patient()
{
	this->InitResistance();
	this->DoStart();
}

Patient::~Patient()
{
}

void Patient::InitResistance()
{
	this->m_resistance = rand() % (9000 - 1000 + 1) + 1000;
}

void Patient::DoStart()
{
	this->m_state = 1;
	int num_virus = (rand() % (20 - 10 + 1) + 10);
	for (int i = 0; i < num_virus; i++)
	{
		int n = rand() % (2 - 1 + 1) + 1;
		switch (n)
		{
		case 1:
		{
//			FluVirus flu = ;
			m_listVirus.push_back(new FluVirus());
			break;
		}		
		case 2:
		{
//			DengueVirus *dengue = new DengueVirus();
			m_listVirus.push_back(new DengueVirus());
			break;
		}			
		default:
		{
			break;
		}			
		}
	}
}

void Patient::TakeMedicine(int medicine_resistance)
{
	std::list<MyVirus*>::iterator position;
	// Reduce resistance of virus
	for (position = this->m_listVirus.begin(); position != this->m_listVirus.end();/*empty*/)
	{
		MyVirus *p = *position;
		p->Reduce_Resistance(medicine_resistance);
		if (p->Getm_resitance() <= 0)
		{
			//p->DoDie();
			position = m_listVirus.erase(position);
		}
		else
		{
			std::list<MyVirus*> list = p->DoClone();
			m_listVirus.insert(position, list.begin(), list.end());
			++position;
		}	
	}
	std::cout << "List Virus!" << std::endl;
	// Print list virus
	for (position = this->m_listVirus.begin(); position != this->m_listVirus.end(); position++)
	{
		MyVirus *p = *position;		
		p->GetNameVirus();
		std::cout << std::endl;
	}
	// Check Patient Die
	std::cout << "\nNumber Virus: " << m_listVirus.size() << std::endl;
	if (this->m_resistance < this->m_listVirus.size())
	{
		this->DoDie();
	}
	if (this->m_listVirus.empty())
	{
		std::cout << "Clear Virus In Patient." << std::endl;
		this->m_state = 0;
	}
}

void Patient::DoDie()
{
	this->m_state = 0;
	this->m_resistance = 0;
	this->m_listVirus.clear();
	std::cout << "Patient Was Die." << std::endl;
}

int Patient::GetState()
{
	return this->m_state;
}
