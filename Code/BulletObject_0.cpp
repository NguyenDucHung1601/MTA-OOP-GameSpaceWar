#include "BulletObject_0.h"



BulletObject_0::BulletObject_0(const int& level) : BulletObject_Base()
{
	file_name = name_level_0[level];
	rect_.w = WIDTH_BULLET_0[level];
	rect_.h = HEIGHT_BULLET_0[level];
	speed = speed_level_0[level];
	bulle_type_ = BULLET_0;
	damage_ = damage_level_0[level];
}


BulletObject_0::~BulletObject_0()
{
}

void BulletObject_0::HandleMove(const int& x_border, const int&y_border) {
	rect_.y -= speed;
	if (rect_.y < 0) {
		is_move_ = false;
	}
}