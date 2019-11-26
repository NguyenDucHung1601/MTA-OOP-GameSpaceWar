#include "ThreatObject_Base.h"



ThreatObject_Base::ThreatObject_Base()
{
	file_name = "";
	rect_.x = 0;
	rect_.y = 0;
	rect_.w = WIDTH_THREAT;
	rect_.h = HEIGHT_THREAT;
	p_object_ = NULL;
	angle = 90;
	blood = 0;
	speed = 0;
	bulle_type_ = BULLET_1;
	level = 0;
}


ThreatObject_Base::~ThreatObject_Base()
{
}

void ThreatObject_Base::Reset() {
	rect_.y =  - HEIGHT_THREAT;
	int rand_x = rand() % SCREEN_WIDTH;
	if (rand_x > SCREEN_WIDTH - WIDTH_THREAT) {
		rand_x = SCREEN_WIDTH * 0.5;
	}
	rect_.x = rand_x;
}

void ThreatObject_Base::Remove_Bullet(const int &ia) {
	int size_threat = p_bullet_list.size();
	if (size_threat > 0 && ia < size_threat) {
		BulletObject_Base* p_bullet = p_bullet_list.at(ia);
		p_bullet_list.erase(p_bullet_list.begin() + ia);
		if (p_bullet != NULL) {
			delete p_bullet;
			p_bullet = NULL;
		}
	}
}