#pragma once
#ifndef BULLE_OBJECT_2_H_
#define BULLE_OBJECT_2_H_

#include"BulletObject_Base.h"

const int WIDTH_BULLET_2[MAX_LEVEL] = { 13,13,13 };
const int HEIGHT_BULLET_2[MAX_LEVEL] = { 13, 24,33 };

const std::string name_level_2[MAX_LEVEL] = { "bullet003_1.png", "bullet003_2.png" ,"bullet003_3.png" };
const int damage_level_2[MAX_LEVEL] = { 5, 20, 35 };
const float speed_level_2[MAX_LEVEL] = { 1, 1.5, 2 };

class BulletObject_2 : public BulletObject_Base
{
public:
	BulletObject_2(const int&);
	virtual ~BulletObject_2();
	virtual void HandleMove(const int&, const int&);
};

#endif // !BULLE_OBJECT_2_H_

