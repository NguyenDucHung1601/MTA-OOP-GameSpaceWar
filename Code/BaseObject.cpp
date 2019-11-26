#include"BaseObject.h"
#include"Common_Function.h"

BaseObject::BaseObject() {
	file_name = "";
	rect_.x = 0;
	rect_.y = 0;
	p_object_ = NULL;
	angle = 270;   //270 độ
	speed = 0;
}

BaseObject::~BaseObject() {
}

bool BaseObject::LoadImg() {
	p_object_ = SDLCommonFunction::Load_Image(file_name);
	if (p_object_ == NULL) {
		return false;
	}
	return true;
}

void BaseObject::Show(SDL_Surface* des) {
	short y = rect_.y;
	if (p_object_ != NULL) {
		rect_ = SDLCommonFunction::ApplySurface(p_object_, des, rect_.x, rect_.y);
	}
	rect_.y = y;
}