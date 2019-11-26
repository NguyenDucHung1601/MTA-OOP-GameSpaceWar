#include "BulletObject_4.h"



BulletObject_4::BulletObject_4(const int& level) : BulletObject_Base()
{
	file_name = name_level_4[level];
	rect_.w = WIDTH_BULLET_4[level];
	rect_.h = HEIGHT_BULLET_4[level];
	speed = 0;
	bulle_type_ = BULLET_4;
	damage_ = damage_level_4[level];
	acceleration = ACCELERATION;
}


BulletObject_4::~BulletObject_4()
{
}

void BulletObject_4::HandleMove(const int& x_border, const int&y_border) {
	speed += acceleration;
	rect_.x += (int)cos(angle*DEGTORAD)*speed;
	rect_.y += (int)sin(angle*DEGTORAD)*speed;

	if (rect_.x + WIDTH_BULLET_4 < 0 || rect_.x > SCREEN_WIDTH) {
		is_move_ = false;
	}

	if (rect_.y + HEIGHT_BULLET_4 < 0 || rect_.y > SCREEN_HEIGHT) {
		is_move_ = false;
	}
}