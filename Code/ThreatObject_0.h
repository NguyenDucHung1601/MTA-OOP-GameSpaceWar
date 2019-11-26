#pragma once
#ifndef THREAT_OBJECT_BASE_0_H_
#define THREAT_OBJECT_BASE_0_H_

#include"ThreatObject_Base.h"

const int BOOLD_THREAT_0 = 100;


class ThreatObject_0 : public ThreatObject_Base
{
public:
	ThreatObject_0();
	virtual ~ThreatObject_0();
	virtual void Init_Bullet();
	virtual void HandleMove(const int& x_limit, const int& y_limit) ;
	virtual void Make_Bullet(SDL_Surface* des, const int& x_limit, const int& y_limit);
};

#endif // !THREAT_OBJECT_BASE_0_H_