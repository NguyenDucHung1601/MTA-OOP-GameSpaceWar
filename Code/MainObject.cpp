#include "MainObject.h"



MainObject::MainObject()
{
	file_name = g_picture_mainObj;
	rect_.x = 0;
	rect_.y = 0;
	p_object_ = NULL;
	rect_.w = WIDTH_MAIN_OBJECT;
	rect_.h = HEIGHT_MAIN_OBJECT;
	blood = 500;
	bullet_type = BULLET_0;
	angle = 270;
	Continuous_Shooting = 0;
	level = 2;
	
}


MainObject::~MainObject()
{
}

void MainObject::HanleInputAction(SDL_Event events, Mix_Chunk* g_sound_bullet[6]) {
	if (events.type == SDL_KEYDOWN) {
		switch (events.key.keysym.sym) {
		/*case SDLK_a: SDL_ShowCursor(SDL_ENABLE); break;
		case SDLK_s: SDL_ShowCursor(SDL_DISABLE); break;*/
		}
	}
	else if (events.type == SDL_KEYUP) {
		// to do
	}
	else if (events.type == SDL_MOUSEBUTTONDOWN) {
		if (events.type == SDL_MOUSEBUTTONDOWN) {

			if (events.button.button == SDL_BUTTON_LEFT) {
				BulletObject_Base* bullet = add_newBullet(bullet_type, level);
				p_bullet_list.push_back(bullet);
				
				Continuous_Shooting = 1;
				Mix_PlayChannel(-1, g_sound_bullet[0], 0);
				
			}
			else if (events.button.button == SDL_BUTTON_RIGHT) {
				// to do
			}
		}
	}
	else if (events.type == SDL_MOUSEMOTION) {
		rect_.x = events.motion.x;
		rect_.y = events.motion.y;
	}

	else if (events.type == SDL_MOUSEBUTTONUP) {
		Continuous_Shooting = 0;
	}
	else {
		//todo
	}
}

void MainObject::HandleMove(const int& x, const int& y) {
	if (rect_.x > SCREEN_WIDTH - WIDTH_MAIN_OBJECT) {
		rect_.x = SCREEN_WIDTH - WIDTH_MAIN_OBJECT;
	}
	if (rect_.x < 0) {
		rect_.x = 0;
	}

	if (rect_.y > SCREEN_HEIGHT - HEIGHT_MAIN_OBJECT) {
		rect_.y = SCREEN_HEIGHT - HEIGHT_MAIN_OBJECT;
	}
	if (rect_.y < 0) {
		rect_.y = 0;
	}
}


void MainObject::Add_Shooting() {
	if (Continuous_Shooting >= 1) { //click truột trái thì Continuous_Shooting =1
		Continuous_Shooting++;
	}

	if (Continuous_Shooting >= 10) { //qua 20 lần không nhả chuột sẽ bắn liên tục
		if (Continuous_Shooting % 3 == 0) {
			BulletObject_Base* bullet = add_newBullet(getBullet_type(), getLevel());
			p_bullet_list.push_back(bullet);
		}
	}
}

void MainObject::Show_Bullet_Move(SDL_Surface* g_screen) {
	int size_bullet = p_bullet_list.size();
	int i = 0;
	while (i < size_bullet) {
		BulletObject_Base* p_bullet = p_bullet_list.at(i);
		if (p_bullet != NULL) {
			if (p_bullet->getIs_move()) {
				p_bullet->Show(g_screen);
				p_bullet->HandleMove(SCREEN_WIDTH, SCREEN_HEIGHT);
			}
			else {
				if (p_bullet != NULL) {
					p_bullet_list.erase(p_bullet_list.begin() + i);
					i--;
					delete p_bullet;
					p_bullet = NULL;
				}
			}
		}
		i++;
		size_bullet = p_bullet_list.size();
	}
}

void MainObject::Remove_Bullet(const int& idx) {
	int size_bullet = p_bullet_list.size();
	if (size_bullet > 0 && idx < size_bullet) {
		BulletObject_Base* p_bullet = p_bullet_list.at(idx);
		p_bullet_list.erase(p_bullet_list.begin() + idx);
		if (p_bullet != NULL) {
			delete p_bullet;
			p_bullet = NULL;
		}
	}
}

BulletObject_Base* MainObject::add_newBullet(const Bullet_Type &bulle_type, const int &level) {
	BulletObject_Base* bullet=NULL;
	if (bulle_type == BULLET_0) {
		bullet = new BulletObject_0(level);		
		bullet->setRect(rect_.x + WIDTH_MAIN_OBJECT / 2 - WIDTH_BULLET_0[level] / 2, rect_.y - HEIGHT_BULLET_0[level] * 0.5);
	}
	else if (bulle_type == BULLET_1) {
		bullet  = new BulletObject_1(level);
		bullet->setRect(rect_.x + WIDTH_MAIN_OBJECT / 2 - WIDTH_BULLET_1[level] / 2, rect_.y - HEIGHT_BULLET_1[level] * 0.5);
	}
	else if (bulle_type == BULLET_2) {
		bullet = new BulletObject_2(level);
		bullet->setRect(rect_.x + WIDTH_MAIN_OBJECT / 2 - WIDTH_BULLET_2[level] / 2, rect_.y - HEIGHT_BULLET_2[level] * 0.5);
	}
	else if (bulle_type == BULLET_3) {
		bullet = new BulletObject_3(level);
		bullet->setRect(rect_.x + WIDTH_MAIN_OBJECT / 2 - WIDTH_BULLET_3[level] / 2, rect_.y - HEIGHT_BULLET_3[level] * 0.5);
	}
	else if (bulle_type == BULLET_4) {
		bullet = new BulletObject_4(level);
		bullet->setRect(rect_.x + WIDTH_MAIN_OBJECT / 2 - WIDTH_BULLET_4[level] / 2, rect_.y - HEIGHT_BULLET_4[level] * 0.5);
	}
	bullet->LoadImg();
	bullet->setIs_move(true);
	bullet->setAngle(angle);
	return bullet;
}