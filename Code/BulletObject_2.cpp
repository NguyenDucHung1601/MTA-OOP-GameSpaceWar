#include "BulletObject_2.h"



BulletObject_2::BulletObject_2(const int& level) : BulletObject_Base()
{
	file_name = name_level_2[level];
	rect_.w = WIDTH_BULLET_2[level];
	rect_.h = HEIGHT_BULLET_2[level];
	speed = speed_level_2[level];
	bulle_type_ = BULLET_2;
	damage_ = damage_level_2[level];
}


BulletObject_2::~BulletObject_2()
{
}

void BulletObject_2::HandleMove(const int& x_border, const int&y_border) {
	rect_.x += (int)cos(angle*DEGTORAD)*speed;
	rect_.y += (int)sin(angle*DEGTORAD)*speed;

	if (rect_.x + WIDTH_BULLET_2 < 0 || rect_.x > SCREEN_WIDTH) {
		is_move_ = false;
	}

	if (rect_.y + HEIGHT_BULLET_2 < 0 || rect_.y > SCREEN_HEIGHT) {
		is_move_ = false;
	}
}
