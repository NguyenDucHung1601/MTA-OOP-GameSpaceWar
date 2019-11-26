#include "ExplosionObject.h"



ExplosionObject::ExplosionObject(const Explosion_Type& type )
{
	file_name = g_picture_explosion[type];
	rect_.x = 0;
	rect_.y = 0;
	rect_.w = EXP_WIDTH[type];
	rect_.h = EXP_HEIGHT[type];
	p_object_ = NULL;
	explosion_type = type;
	frame_number_ = FRAME_NUMBER[type];
	frame_count_ = 0;
}

ExplosionObject::~ExplosionObject()
{
}

void ExplosionObject::set_clip() {
	for (int cl = 0; cl < frame_number_; cl++) {
		clip_[cl].x = EXP_WIDTH[explosion_type] * cl;
		clip_[cl].y = 0;
		clip_[cl].w = EXP_WIDTH[explosion_type];
		clip_[cl].h = EXP_HEIGHT[explosion_type];
	}
}

void ExplosionObject::Show(SDL_Surface* des) {
	if (frame_count_ > frame_number_) {
		return;
	}
	SDLCommonFunction::ApplySurfaceClip(this->p_object_, des, &clip_[(int)frame_count_], rect_.x, rect_.y);
 frame_count_ += 0.1;


}