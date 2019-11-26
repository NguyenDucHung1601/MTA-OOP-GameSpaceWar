#ifndef  MENU_H_
#define MENU_H_

#include "Common_Function.h"
#include "BaseObject.h"

class Menu : public BaseObject
{
public:
	int MenuStart(SDL_Surface* des, TTF_Font* font, Mix_Chunk* g_sound_selection); // menu mo dau
	int MenuOther(int submenu, SDL_Surface* des, TTF_Font* font, Mix_Chunk* g_sound_selection); // 1.menu instructions   2.menu highscore   3.menu information
	int MenuGameOver(SDL_Surface* des, TTF_Font* font, TTF_Font* fontforScore, const int& score, Mix_Chunk* g_sound_selection); // menu gameover

	bool CheckFocusWithRect(const int& x, const int& y, const SDL_Rect& rect); // ktra chon menu

	virtual void HandleMove(const int& x, const int& y) {
		;
	}
};

#endif
