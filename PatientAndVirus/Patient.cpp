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
	std::list<MyVirus> m_virusList(rand() % (20 - 10 + 1) + 10);
	for (int i = 0; i < m_listVirus.size(); i++)
	{
		int n = rand() % (2 - 1 + 1) + 1;
		switch (n)
		{
		case 1:
			FluVirus *flu = new FluVirus();
			m_listVirus.push_front(flu);
			break;
		case 2:
			DengueVirus *dengue = new DengueVirus();
			m_listVirus.push_front(dengue);
			break;
		default:
			break;
		}
	}
}