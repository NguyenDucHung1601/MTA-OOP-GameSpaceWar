#pragma once

#ifndef BULLET_OBJECT_BASE_H
#define BULLET_OBJECT_BASE_H

#include"BaseObject.h"
//#include"BulletObject_1.h"
const int amount_type = 5;
enum Bullet_Type { BULLET_0 = 0, BULLET_1 = 1, BULLET_2 = 2, BULLET_3 = 3, BULLET_4 = 4 };
const int MAX_LEVEL = 3;

class BulletObject_Base : public BaseObject
{
protected:
	bool is_move_;
	Bullet_Type bulle_type_;
	int damage_;
	
public:
	BulletObject_Base();
	virtual ~BulletObject_Base();

	int getBullet_type() const { return bulle_type_; }
	void setBullet_type(const Bullet_Type& type) { bulle_type_ = type; }
	bool getIs_move() const { return is_move_; }
	void setIs_move(bool is_move_) { this->is_move_ = is_move_; }
	int getDamge() const { return damage_; }
	void setDamage(const int& damage) { damage_ = damage; }
	void SetWidthHeight(const int& width, const int& height) {
		rect_.w = width;
		rect_.h = height;
	}	
	
};

#endif // !1