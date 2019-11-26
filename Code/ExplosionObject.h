#pragma once
#ifndef EXPLOSION_OBJECT_H
#define EXPLOSION_OBJECT_H

#include "BaseObject.h"

const int amount_explosion_type = 2;
const int EXP_WIDTH[amount_explosion_type] = { 150, 192 };
const int EXP_HEIGHT[amount_explosion_type] = { 150, 192 };
const int FRAME_NUMBER[amount_explosion_type] = { 4, 64 };
enum Explosion_Type {explosion_0= 0, explosion_1=1};

static std::string g_picture_explosion[amount_explosion_type] = { "exp.png","type_B" };

class ExplosionObject : public BaseObject
{
private:
	Explosion_Type explosion_type;
	float frame_count_;
	int frame_number_;
	SDL_Rect clip_[64]; 
public:
	ExplosionObject(const Explosion_Type& type);
	virtual ~ExplosionObject();
	void setFrame_count_(const int& frc) { frame_count_ = frc; }
	short getFrame_count_() const {	return frame_count_;}

	void setFrame_number_(const int& frn) { frame_number_ = frn; }
	short getFrame_number_() const { return frame_number_; }

	void set_clip();
	virtual void Show(SDL_Surface*);
	virtual void HandleMove(const int& x, const int& y) {
		;
	}
};

#endif // !EXPLOSION_OBJECT_H
