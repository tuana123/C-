#pragma once
#include "MyVirus.h"
class FluVirus: public MyVirus
{
private:
	int m_color;
public:
	FluVirus();
	~FluVirus();
	void DoBorn() override;
	virtual void DoDie();
	virtual std::list<MyVirus*> DoClone();
	virtual void InitResistance();
};

