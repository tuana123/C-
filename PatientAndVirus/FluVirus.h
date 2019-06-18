#pragma once
#include "MyVirus.h"
class FluVirus: public MyVirus
{
private:
	int m_color;
public:
	FluVirus();
	~FluVirus();
	FluVirus(FluVirus *);
	void DoBorn() override;
	void DoDie() override;
	std::list<MyVirus*> DoClone() override;
	void InitResistance() override;
	void GetNameVirus() override;
};

