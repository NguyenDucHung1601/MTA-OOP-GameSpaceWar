#include "Text.h"

Text::Text()
{
	rect_.x = 0;
	rect_.y = 0;
	text_color_.r = 255;
	text_color_.g = 255;
	text_color_.b = 255;
}

Text::~Text()
{

}


void Text::SetText(const std::string & text)
{
	str_text_ = text;
}

void Text::SetColor(const int & type)
{
	if (type == RED_TEXT)
	{
		SDL_Color color = { 255,0,0 };
		text_color_ = color;
	}
	else if (type == WHITE_TEXT)
	{
		SDL_Color color = { 255,255,255 };
		text_color_ = color;
	}
	else if (type == BLUE_TEXT)
	{
		SDL_Color color = { 0,255,255 };
		text_color_ = color;
	}
	else
	{
		SDL_Color color = { 0,0,0 };
		text_color_ = color;
	}
}

void Text::CreatText(TTF_Font* font, SDL_Surface * des)
{
	// tao doi tuong surface tu 1 text cho vao
	p_object_ = TTF_RenderText_Solid(font, str_text_.c_str(), text_color_);
	Show(des);
}

void Text::ShowTime(TTF_Font * font, SDL_Surface * des)
{
	std::string strTime = "Time: ";
	Uint32 timeVal = SDL_GetTicks() / 1000;
	std::string strVal = std::to_string(timeVal);
	strTime += strVal;

	SetColor(Text::WHITE_TEXT);
	SetText(strTime);
	setRect(SCREEN_WIDTH - 150, 10);
	CreatText(font, des);
}

void Text::ShowScore(const int & score, TTF_Font * font, SDL_Surface * des)
{
	std::string scoreVal = std::to_string(score);
	std::string strScore = "Score: ";
	strScore += scoreVal;

	SetColor(Text::WHITE_TEXT);
	SetText(strScore);
	setRect(650, 10);
	CreatText(font, des);
}

void Text::ShowLife(const int & numlife, TTF_Font * font, SDL_Surface * des)
{
	setRect(50, 7);
	setFile_name(g_picture_life);
	LoadImg();
	Show(des);
	std::string num = std::to_string(numlife);
	std::string numOfLife = " x ";
	numOfLife += num;

	SetColor(Text::WHITE_TEXT);
	SetText(numOfLife);
	setRect(80, 10);
	CreatText(font, des);
}

void Text::ShowBlood(const int & blood, TTF_Font * font, SDL_Surface * des)
{
	setRect(50, 40);
	setFile_name(g_picture_health);
	LoadImg();
	Show(des);
	std::string num = std::to_string(blood);
	std::string numOfLife = " x ";
	numOfLife += num;

	SetColor(Text::WHITE_TEXT);
	SetText(numOfLife);
	setRect(80, 43);
	CreatText(font, des);
}
