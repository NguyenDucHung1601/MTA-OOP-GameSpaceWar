#ifndef TEXT_H_
#define TEXT_H_
#include "BaseObject.h"
#include <string>

class Text : public BaseObject
{
private:
	std::string str_text_; // noi dung text
	SDL_Color text_color_; // color cua text
public:
	enum TextColor
	{
		RED_TEXT = 0,
		WHITE_TEXT = 1,
		BLUE_TEXT = 2,

	};

	Text();
	~Text();
	void SetText(const std::string& text);
	void SetColor(const int& type);
	void CreatText(TTF_Font* font, SDL_Surface*des);
	virtual void HandleMove(const int& x, const int& y) {
		;
	}

	void ShowTime(TTF_Font* font, SDL_Surface* des);
	void ShowScore(const int& score, TTF_Font* font, SDL_Surface *des);
	void ShowLife(const int& numlife, TTF_Font* font, SDL_Surface* des);
	void ShowBlood(const int& blood, TTF_Font* font, SDL_Surface* des);
};

#endif 
