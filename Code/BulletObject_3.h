#pragma once
#ifndef BULLE_OBJECT_3_H_
#define BULLE_OBJECT_3_H_

#include"BulletObject_Base.h"

const int WIDTH_BULLET_3[MAX_LEVEL] = {10,14,24};
const int HEIGHT_BULLET_3[MAX_LEVEL] = {16,16,22};

const std::string name_level_3[MAX_LEVEL] = { "bullet004_1.png", "bullet004_2.png" ,"bullet004_3.png" };
const int damage_level_3[MAX_LEVEL] = { 10, 25, 60 };
const float speed_level_3[MAX_LEVEL] = { 0.25, 1, 1.5 };

class BulletObject_3 : public BulletObject_Base
{
public:
	BulletObject_3(const int&);
	virtual ~BulletObject_3();
	virtual void HandleMove(const int&, const int&);
};

#endif // !BULLE_OBJECT_3_H_

