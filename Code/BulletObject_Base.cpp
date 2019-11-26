#include "BulletObject_Base.h"



BulletObject_Base::BulletObject_Base()
{
	file_name = "";
	rect_.x = 0;
	rect_.y = 0;
	p_object_ = NULL;
	angle = 270;
	speed = 0;
	is_move_ = false;
	bulle_type_ = BULLET_0;
	damage_ = 0;
}


BulletObject_Base::~BulletObject_Base()
{
}



