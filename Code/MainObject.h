#pragma once

#ifndef MAIN_OBJECT_H_
#define MAIN_OBJECT_H_

#include "BulletObject_Base.h"
#include"BulletObject_0.h"
#include"BulletObject_1.h"
#include"BulletObject_2.h"
#include"BulletObject_3.h"
#include"BulletObject_4.h"

const int WIDTH_MAIN_OBJECT = 80;
const int HEIGHT_MAIN_OBJECT = 58;


class MainObject : public BaseObject
{
private:
	int blood;
	std::vector<BulletObject_Base*> p_bullet_list;
	Bullet_Type bullet_type;
	int level;
	short Continuous_Shooting;
public:
	MainObject();
	virtual ~MainObject();
	int getBlood() const { return blood; }
	void setbBlood(const int &blood) { this->blood = blood; }
	std::vector<BulletObject_Base*> getBulletList() const {return this->p_bullet_list; }
	Bullet_Type getBullet_type() const { return bullet_type; }
	void setBullet_type(const Bullet_Type &bullet_type) { this->bullet_type = bullet_type; }
	int getLevel() const { return level; }
	void setLeveL(const int &level) { this->level = level; }
	void HanleInputAction(SDL_Event events, Mix_Chunk* g_sound_bullet[6]);
	virtual void HandleMove(const int& x, const int& y);
	void Add_Shooting(); // giữ chuột để bắn liên tục
	void Show_Bullet_Move(SDL_Surface* s_screen);
	void Remove_Bullet(const int&); // xóa đạn tại vị trí
	BulletObject_Base* add_newBullet(const Bullet_Type &, const int &level);
};

#endif // !MAIN_OBJECT_H_