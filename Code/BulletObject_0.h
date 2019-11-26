#pragma once
#ifndef BULLE_OBJECT_0_H_
#define BULLE_OBJECT_0_H_

#include"BulletObject_Base.h"

const int WIDTH_BULLET_0[MAX_LEVEL] = {5,14,19};
const int HEIGHT_BULLET_0[MAX_LEVEL] = { 48, 48, 54 };

const std::string name_level_0[MAX_LEVEL] = { "bullet001_1.png", "bullet001_2.png" ,"bullet001_3.png" };
const int damage_level_0[MAX_LEVEL] = { 50, 30, 60 };
const float speed_level_0[MAX_LEVEL] = { 20.5, 55.5, 70 };

class BulletObject_0 : public BulletObject_Base
{
public:
	BulletObject_0(const int&);
	virtual ~BulletObject_0();
	virtual void HandleMove(const int&, const int&);
	
};

#endif // !BULLE_OBJECT_0_H_