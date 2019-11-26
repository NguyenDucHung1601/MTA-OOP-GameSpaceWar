#pragma once

#ifndef THREAT_OBJECT_BASE_H_
#define THREAT_OBJECT_BASE_H_

#include"BaseObject.h"
#include"BulletObject_Base.h"
#include"BulletObject_0.h"
#include"BulletObject_1.h"
#include"BulletObject_2.h"
#include"BulletObject_3.h"
#include"BulletObject_4.h"

const int WIDTH_THREAT = 56;
const int HEIGHT_THREAT = 50;

class ThreatObject_Base : public BaseObject
{
protected:
	int blood;
	std::vector<BulletObject_Base*> p_bullet_list;
	Bullet_Type bulle_type_;
	int level;
public:
	ThreatObject_Base();
	virtual ~ThreatObject_Base();
	std::vector<BulletObject_Base*> getBulletList() const { return this->p_bullet_list; }
	int getBlood()const { return blood; }
	void setBlood(const int blood){ this->blood= blood; }
	int getLevel()const { return level; }
	void setLevel(const int level) { this->level = level; }
	virtual void Init_Bullet() = 0;
	virtual void Make_Bullet(SDL_Surface* des  , const int& x_limit, const int& y_limit) =0;
	void Reset();
	void Remove_Bullet(const int &ia);
};

#endif // !THREAT_OBJECT_BASE_H_