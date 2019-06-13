#pragma once
#include <list>
class MyVirus
{
protected:
	char *m_dna;
	int m_resistance;
public:
	MyVirus();
	~MyVirus();
	MyVirus(const MyVirus *p);
	void Setm_dna(char*);
	void Setm_resitance(int);
	int Getm_resitance();
	void LoadADNIformation();
	int Reduce_Resistance(int);
	virtual void DoBorn();
	virtual void DoDie();
	virtual std::list<MyVirus*> DoClone();
	virtual void InitResistance();
};

