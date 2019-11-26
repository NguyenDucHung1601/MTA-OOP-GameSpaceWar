#pragma once
#ifndef BASE_OBJECT_H_
#define BASE_OBJECT_H_

#include<string.h>
#include<vector>
#include<math.h>
#include"Common_Function.h"

const float DEGTORAD = 0.017453f;

class BaseObject
{
protected:
	std::string file_name;
	SDL_Rect rect_;
	SDL_Surface* p_object_;
	float angle;// hướng di chuyển của đối tượng a= vevto(x,y);
	float speed;
public:
	BaseObject();
	virtual ~BaseObject();

	virtual void HandleMove(const int&, const int&) = 0;

	virtual void Show(SDL_Surface*);
	bool LoadImg();

	void setFile_name(std::string name) {
		file_name = name;
	}

	std::string getFile_name() {
		return file_name;
	}

	void setSpeed(const float &speed) {
		this->speed = speed;
	}
	float getSpeed() const {
		return speed;
	}

	void setRect(const int &x, const int &y) {
		rect_.x = x;
		rect_.y = y;
	}
	SDL_Rect getRect() const {
		return rect_;
	}
	SDL_Surface* getP_object() {
		return p_object_;
	}
	void setAngle(const float &x) { // x có đơn vị là độ
		angle = x;
	}
	float getAngle() const { return angle; }
};

#endif // !BASE_OBJECT_H_