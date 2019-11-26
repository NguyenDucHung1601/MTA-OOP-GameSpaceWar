#pragma once
#ifndef BULLE_OBJECT_1_H_
#define BULLE_OBJECT_1_H_

#include"BulletObject_Base.h"

const int WIDTH_BULLET_1[MAX_LEVEL] = {7, 16, 23};
const int HEIGHT_BULLET_1[MAX_LEVEL] = {19, 19, 28};

const std::string name_level_1[MAX_LEVEL] = { "bullet002_1.png", "bullet002_2.png" ,"bullet002_3.png" };
const int damage_level_1[MAX_LEVEL] = { 10, 30, 60 };
const float speed_level_1[MAX_LEVEL] = { 10, 20, 35 };

class BulletObject_1 : public BulletObject_Base
{
public:
	BulletObject_1(const int&);
	virtual ~BulletObject_1();
	virtual void HandleMove(const int&, const int&);
};

#endif // !BULLE_OBJECT_1_H_