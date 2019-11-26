#include "Menu.h"
#include "Text.h"

int Menu::MenuStart(SDL_Surface * des, TTF_Font * font, Mix_Chunk* g_sound_selection)
{
	g_image_menu = SDLCommonFunction::Load_Image(g_picture_menuStart);
	if (g_image_menu == NULL)
	{
		return 4;
	}

	const int kMenuItem = 5;
	SDL_Rect pos[kMenuItem];

	pos[0].x = 630;
	pos[0].y = 378;

	pos[1].x = 633;
	pos[1].y = 475;

	pos[2].x = 640;
	pos[2].y = 575;

	pos[3].x = 625;
	pos[3].y = 680;

	pos[4].x = 630;
	pos[4].y = 785;

	Text text_menu[kMenuItem];

	text_menu[0].SetText("Play Game");
	text_menu[0].SetColor(Text::RED_TEXT);
	text_menu[0].setRect(pos[0].x, pos[0].y);

	text_menu[1].SetText("Instructions");
	text_menu[1].SetColor(Text::RED_TEXT);
	text_menu[1].setRect(pos[1].x, pos[1].y);

	text_menu[2].SetText("High Score");
	text_menu[2].SetColor(Text::RED_TEXT);
	text_menu[2].setRect(pos[2].x, pos[2].y);

	text_menu[3].SetText("Information");
	text_menu[3].SetColor(Text::RED_TEXT);
	text_menu[3].setRect(pos[3].x, pos[3].y);

	text_menu[4].SetText("Quit Game");
	text_menu[4].SetColor(Text::RED_TEXT);
	text_menu[4].setRect(pos[4].x, pos[4].y);

	bool selected[kMenuItem] = { 0,0,0,0,0 };
	int xm = 0;
	int ym = 0;

	SDL_Event m_event;
	while (true)
	{
		SDLCommonFunction::ApplySurface(g_image_menu, des, 0, 0);
		for (int i = 0; i < kMenuItem; ++i)
		{
			text_menu[i].CreatText(font, des);
		}

		while (SDL_PollEvent(&m_event))
		{
			switch (m_event.type)
			{
			case SDL_QUIT:
				return 4;
			case SDL_MOUSEMOTION:
			{
				xm = m_event.motion.x;
				ym = m_event.motion.y;

				for (int i = 0; i < kMenuItem; i++)
				{
					if (CheckFocusWithRect(xm, ym, text_menu[i].getRect()))
					{
						if (selected[i] == false)
						{
							selected[i] = 1;
							text_menu[i].SetColor(Text::BLUE_TEXT);
						}
					}
					else
					{
						if (selected[i] == true)
						{
							selected[i] = 0;
							text_menu[i].SetColor(Text::RED_TEXT);
						}
					}
				}
			}
			break;
			case SDL_MOUSEBUTTONDOWN:
			{
				xm = m_event.button.x;
				ym = m_event.button.y;
				for (int i = 0; i < kMenuItem; i++)
				{
					if (CheckFocusWithRect(xm, ym, text_menu[i].getRect()))
					{
						Mix_PlayChannel(-1, g_sound_selection, 0);
						return i;
					}
				}
			}
			break;
			case SDL_KEYDOWN:
				if (m_event.key.keysym.sym == SDLK_ESCAPE)
				{
					return 4;
				}
			default:
				break;
			}
		}

		SDL_Flip(des);
	}
	return 4;
}

int Menu::MenuOther(int submenu, SDL_Surface * des, TTF_Font * font, Mix_Chunk* g_sound_selection)
{
	if (submenu == 1) g_image_menu = SDLCommonFunction::Load_Image(g_picture_menuInstructions);
	else if (submenu == 2) g_image_menu = SDLCommonFunction::Load_Image(g_picture_menuHightSocre);
	else if (submenu == 3) g_image_menu = SDLCommonFunction::Load_Image(g_picture_menuInformation);

	if (g_image_menu == NULL)
	{
		return 0;
	}

	Text text_menu;
	text_menu.SetText("Return");
	text_menu.SetColor(Text::RED_TEXT);
	text_menu.setRect(1248, 816);

	bool selected = 0;
	int xm = 0;
	int ym = 0;

	SDL_Event m_event;
	while (true)
	{
		SDLCommonFunction::ApplySurface(g_image_menu, des, 0, 0);
		text_menu.CreatText(font, des);

		while (SDL_PollEvent(&m_event))
		{
			switch (m_event.type)
			{
			case SDL_QUIT:
				return 0;
			case SDL_MOUSEMOTION:
			{
				xm = m_event.motion.x;
				ym = m_event.motion.y;

				if (CheckFocusWithRect(xm, ym, text_menu.getRect()))
				{
					if (selected == false)
					{
						selected = 1;
						text_menu.SetColor(Text::BLUE_TEXT);
					}
				}
				else
				{
					if (selected == true)
					{
						selected = 0;
						text_menu.SetColor(Text::RED_TEXT);
					}
				}
			}
			break;
			case SDL_MOUSEBUTTONDOWN:
			{
				xm = m_event.button.x;
				ym = m_event.button.y;
				if (CheckFocusWithRect(xm, ym, text_menu.getRect()))
				{
					Mix_PlayChannel(-1, g_sound_selection, 0);
					return 1;
				}
			}
			break;
			}
		}

		SDL_Flip(des);
	}
	return 0;
}

int Menu::MenuGameOver(SDL_Surface * des, TTF_Font * font, TTF_Font* fontforScore, const int& score, Mix_Chunk* g_sound_selection)
{
	g_image_menu = SDLCommonFunction::Load_Image(g_picture_menuGameOver);
	if (g_image_menu == NULL)
	{
		return 2;
	}

	const int kMenuItem = 2;
	SDL_Rect pos[kMenuItem];

	pos[0].x = 630;
	pos[0].y = 670;

	pos[1].x = 633;
	pos[1].y = 765;

	Text text_menu[kMenuItem];

	text_menu[0].SetText("Play again");
	text_menu[0].SetColor(Text::RED_TEXT);
	text_menu[0].setRect(pos[0].x, pos[0].y);

	text_menu[1].SetText("Main menu");
	text_menu[1].SetColor(Text::RED_TEXT);
	text_menu[1].setRect(pos[1].x, pos[1].y);

	bool selected[kMenuItem] = { 0,0 };
	int xm = 0;
	int ym = 0;

	SDL_Event m_event;
	while (true)
	{
		SDLCommonFunction::ApplySurface(g_image_menu, des, 0, 0);
		for (int i = 0; i < kMenuItem; ++i)
		{
			text_menu[i].CreatText(font, des);
		}

		std::string strScore = std::to_string(score);
		Text playerScore;
		playerScore.SetText(strScore);
		playerScore.SetColor(Text::RED_TEXT);
		playerScore.setRect(650, 480);
		playerScore.CreatText(fontforScore, des);

		while (SDL_PollEvent(&m_event))
		{
			switch (m_event.type)
			{
			case SDL_QUIT:
				return 2;
			case SDL_MOUSEMOTION:
			{
				xm = m_event.motion.x;
				ym = m_event.motion.y;

				for (int i = 0; i < kMenuItem; i++)
				{
					if (CheckFocusWithRect(xm, ym, text_menu[i].getRect()))
					{
						if (selected[i] == false)
						{
							selected[i] = 1;
							text_menu[i].SetColor(Text::BLUE_TEXT);
						}
					}
					else
					{
						if (selected[i] == true)
						{
							selected[i] = 0;
							text_menu[i].SetColor(Text::RED_TEXT);
						}
					}
				}
			}
			break;
			case SDL_MOUSEBUTTONDOWN:
			{
				xm = m_event.button.x;
				ym = m_event.button.y;
				for (int i = 0; i < kMenuItem; i++)
				{
					if (CheckFocusWithRect(xm, ym, text_menu[i].getRect()))
					{
						Mix_PlayChannel(-1, g_sound_selection, 0);
						return i;
					}
				}
			}
			break;
			}
		}

		SDL_Flip(des);
	}
	return 2;
}

bool Menu::CheckFocusWithRect(const int & x, const int & y, const SDL_Rect & rect)
{
	if (x >= rect.x && x <= rect.x + rect.w && y >= rect.y && y <= rect.y + rect.h)
	{
		return true;
	}
	return false;
}


