#include "ThreatObject_0.h"



ThreatObject_0::ThreatObject_0() : ThreatObject_Base()
{
	file_name = g_picture_threat;
	speed = 3;
	blood = BOOLD_THREAT_0;
	bulle_type_ = BULLET_1;
}


ThreatObject_0::~ThreatObject_0()
{
	
}

void ThreatObject_0::Init_Bullet() {
	BulletObject_Base* p_bullet = new BulletObject_1(getLevel());
	if (p_bullet) {
		bool ret = p_bullet->LoadImg();
		if (ret) {
			p_bullet->setIs_move(true);
			p_bullet->setBullet_type(BULLET_1);
			p_bullet->setAngle(angle);
			p_bullet->setRect(rect_.x, rect_.y + rect_.h*0.5);
			p_bullet_list.push_back(p_bullet);
		}
	}
}

void ThreatObject_0::HandleMove(const int& x_limit, const int& y_limit) {
	rect_.x += (int)cos(angle*DEGTORAD)*speed;
	rect_.y += (int)sin(angle*DEGTORAD)*speed;
	if (rect_.y > SCREEN_HEIGHT) {
		rect_.y = -WIDTH_THREAT;
		int rand_x = rand() % SCREEN_WIDTH;
		if (rand_x > SCREEN_WIDTH - WIDTH_THREAT) {
			rand_x = SCREEN_WIDTH * 0.5;
		}
		rect_.x = rand_x;
	}
}
void ThreatObject_0::Make_Bullet(SDL_Surface* des, const int& x_limit, const int& y_limit) {
	for (int i = 0; i < p_bullet_list.size(); i++) {
		BulletObject_Base* p_bullet = p_bullet_list.at(i);
		if (p_bullet) {
			if (p_bullet->getIs_move()) {
				p_bullet->Show(des);
				p_bullet->HandleMove(x_limit, y_limit);
			}
			else {
				p_bullet->setIs_move(true);
				p_bullet->setRect(rect_.x + WIDTH_THREAT / 2 - WIDTH_BULLET_1[0] / 2, rect_.y + HEIGHT_THREAT);
			}
		}
	}
}