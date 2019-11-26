#pragma once
#ifndef BULLE_OBJECT_4_H_
#define BULLE_OBJECT_4_H_

#include"BulletObject_Base.h"

const int WIDTH_BULLET_4[MAX_LEVEL] = {30, 18, 32};
const int HEIGHT_BULLET_4[MAX_LEVEL] = {30, 36, 35};

const std::string name_level_4[MAX_LEVEL] = { "bullet005_1.png", "bullet005_2.png" ,"bullet005_3.png" };
const int damage_level_4[MAX_LEVEL] = { 10, 25, 60 };
const float ACCELERATION=0.5; // gia tốc đạn

class BulletObject_4 : public BulletObject_Base
{
private :
	float acceleration;
public:
	BulletObject_4(const int&);
	float getAcceleration() const {
		return acceleration;
	}
	void setAcceleration(const float& acceleration) {
		this->acceleration = acceleration;
	}
	virtual ~BulletObject_4();
	virtual void HandleMove(const int&, const int&);
};

#endif // !BULLE_OBJECT_4_H_

