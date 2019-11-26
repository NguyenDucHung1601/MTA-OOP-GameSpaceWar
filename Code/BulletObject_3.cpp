#include "BulletObject_3.h"



BulletObject_3::BulletObject_3(const int& level) : BulletObject_Base()
{
	file_name = name_level_3[level];
	rect_.w = WIDTH_BULLET_3[level];
	rect_.h = HEIGHT_BULLET_3[level];
	speed = speed_level_3[level];
	bulle_type_ = BULLET_3;
	damage_ = damage_level_3[level];
}


BulletObject_3::~BulletObject_3()
{
}

void BulletObject_3::HandleMove(const int& x_border, const int&y_border) {
	rect_.x += (int)cos(angle*DEGTORAD)*speed;
	rect_.y += (int)sin(angle*DEGTORAD)*speed;

	if (rect_.x + WIDTH_BULLET_3 < 0 || rect_.x > SCREEN_WIDTH) {
		is_move_ = false;
	}

	if (rect_.y + HEIGHT_BULLET_3 < 0 || rect_.y > SCREEN_HEIGHT) {
		is_move_ = false;
	}
}
