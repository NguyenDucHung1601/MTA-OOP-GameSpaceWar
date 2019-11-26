#include "BulletObject_1.h"



BulletObject_1::BulletObject_1(const int& level): BulletObject_Base()
{
	file_name = name_level_1[level];
	rect_.w = WIDTH_BULLET_1[level];
	rect_.h = HEIGHT_BULLET_1[level];
	speed = speed_level_1[level];
	bulle_type_= BULLET_0;
	damage_ = damage_level_1[level];
}


BulletObject_1::~BulletObject_1()
{
}

void BulletObject_1::HandleMove(const int& x_border, const int&y_border) {
	rect_.x += (int)cos(angle*DEGTORAD)*speed;
	rect_.y += (int)sin(angle*DEGTORAD)*speed;

	if (rect_.x + WIDTH_BULLET_1 < 0 || rect_.x > SCREEN_WIDTH) {
		is_move_ = false;
	}

	if (rect_.y + HEIGHT_BULLET_1 < 0 || rect_.y > SCREEN_HEIGHT) {
		is_move_ = false;
	}
}
