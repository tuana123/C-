#pragma once
#include <list>
class MyVirus
{
protected:
	char *m_dna;
	int m_resistance;
public:
	MyVirus();
	virtual ~MyVirus();
	MyVirus(const MyVirus *p);
	void Setm_dna(char*);
	void Setm_resitance(int);
	int Getm_resitance();
	void LoadADNIformation();
	void Reduce_Resistance(int);
	virtual void DoBorn() = 0;
	virtual void DoDie() = 0;
	virtual std::list<MyVirus*> DoClone() = 0;
	virtual void InitResistance() = 0;
	virtual void GetNameVirus() = 0;
};

