#include "Common_Function.h"
#include "MainObject.h"
#include "ThreatObject_0.h"
#include "ExplosionObject.h"
#include "Text.h"
#include "Menu.h"

using namespace std;

#undef main


bool Init() { // -------------------- Khoi tao cac thuoc tinh ban dau
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		return false;
	}

	// -------- Video Init
	g_screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);

	if (g_screen == NULL)	return false;

	// ------- Audio Init
	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)	return false;

	// Read file wav audio
	g_sound_music[0] = Mix_LoadWAV(g_audio_music_1);
	g_sound_music[1] = Mix_LoadWAV(g_audio_music_2);
	g_sound_selection = Mix_LoadWAV(g_audio_selection);
	g_sound_gameover = Mix_LoadWAV(g_audio_gameover);

	g_sound_bullet[0] = Mix_LoadWAV(g_audio_bulletMain_1);
	g_sound_bullet[1] = Mix_LoadWAV(g_audio_bulletMain_2);
	g_sound_bullet[2] = Mix_LoadWAV(g_audio_bulletMain_3);
	g_sound_bullet[3] = Mix_LoadWAV(g_audio_bulletMain_4);
	g_sound_bullet[4] = Mix_LoadWAV(g_audio_bulletMain_5);
	g_sound_bullet[5] = Mix_LoadWAV(g_audio_bulletThreat);

	g_sound_item[0] = Mix_LoadWAV(g_audio_powerup);
	g_sound_item[1] = Mix_LoadWAV(g_audio_health);
	g_sound_item[2] = Mix_LoadWAV(g_audio_life);
	g_sound_item[3] = Mix_LoadWAV(g_audio_shield);

	g_sound_explosion[0] = Mix_LoadWAV(g_audio_explosion_1);
	g_sound_explosion[1] = Mix_LoadWAV(g_audio_explosion_2);

	if (g_sound_music[0] == NULL || g_sound_music[1] == NULL|| g_sound_selection == NULL || g_sound_gameover == NULL|| g_sound_bullet[0] == NULL || g_sound_bullet[1] == NULL
		|| g_sound_bullet[2] == NULL || g_sound_bullet[3] == NULL || g_sound_bullet[4] == NULL || g_sound_bullet[5] == NULL
		|| g_sound_explosion[0] == NULL || g_sound_explosion[1] == NULL || g_sound_item[0] == NULL || g_sound_item[1] == NULL 
		|| g_sound_item [2] == NULL || g_sound_item[3] == NULL)
	{
		return false;
	}

	// --------- FontText Init
	if (TTF_Init() == -1)
		return false;

	g_font_text = TTF_OpenFont(g_fontText, 25);
	g_font_menu = TTF_OpenFont(g_fontText, 50);
	g_font_score = TTF_OpenFont(g_fontText, 80);

	if (g_font_text == NULL || g_font_menu == NULL)
		return false;


	return true;
}


int main(int arc, char* atgv[]) {

	float y_background_begin = START_Y_POS_BACKGROUND;
	bool isQuit = false;

	/*-----------------  KIEM TRA KHOI TAO BAN DAU -----------------*/
	if (Init() == false) { // Ktra khoi tao ban dau
		return 0;
	}
	g_background = SDLCommonFunction::Load_Image(g_picture_background);
	if (g_background == NULL)
		return 0;

	/*-------------------- TAO TEXT ------------------*/
	Text lifeMainObj;
	Text bloodMainObj;
	Text scoreGame;
	Text timeGame;

	/*----------------- TAO NHAN VAT CHINH -----------------*/
	MainObject shipObj;
	shipObj.setRect(START_X_POS_MAIN_OBJECT, START_Y_POS_MAIN_OBJECT);
	bool ret = shipObj.LoadImg(); // ktra anh nhan vat chinh
	if (!ret)	return 0;

	/*---------------- TAO DOI DUONG VU NO -------------------*/
	vector<ExplosionObject*> explosion_list;


	/*----------------- CHAY CHUONG TRINH CHO DEN KHI QUIT ------------*/
	Mix_PlayChannel(-1, g_sound_music[0], -1);
	
	/*------------------------ CHON MENU -------------------------*/
	//Mix_PlayChannel(-1, g_sound_music[0], -1);
	Menu menu;
	Label_MenuStart:
	Label_ChoseAgain:
	switch (menu.MenuStart(g_screen, g_font_menu, g_sound_selection))
	{
	case 0: // Play Game
		break;
	case 1: // Instructions
		if (menu.MenuOther(1, g_screen, g_font_menu, g_sound_selection) == 1)  goto Label_ChoseAgain;
		isQuit = true;
		break;
	case 2: // High Score
		if (menu.MenuOther(2, g_screen, g_font_menu, g_sound_selection) == 1) goto Label_ChoseAgain;
		isQuit = true;
		break;
	case 3: // Information
		if (menu.MenuOther(3, g_screen, g_font_menu, g_sound_selection) == 1) goto Label_ChoseAgain;
		isQuit = true;
		break;
	case 4: // Quit Game
		isQuit = true;
		break;
	}

	Label_StartGame:
	/*----------------- TAO QUAN DICH ----------------------*/
	vector<ThreatObject_Base*> p_threats_list;
	srand(time(NULL));
	for (int t = 0; t < NUMBER_THREAT; t++) {
		ThreatObject_Base* p_threat = new ThreatObject_0();
		if (p_threat != NULL) {
			ret = p_threat->LoadImg(); // ktra anh threat
			if (!ret)	return 0;
			int rand_x = rand() % SCREEN_WIDTH - WIDTH_THREAT;
			p_threat->setRect(rand_x, -HEIGHT_THREAT - t * 200);
			p_threat->Init_Bullet();
			p_threats_list.push_back(p_threat);
		}
	}

	/*----------- DAT THONG SO BAN DAU CHO NGUOI CHOI ---------*/
	unsigned int num_life = NUM_LIFE_BEGIN; // so mang choi ban dau
	unsigned int blood_mainObj = 500; // mau cua nhan vat chinh
	unsigned int die_number = 0; // so lan chet cua mainObject
	unsigned int score = 0; // diem so cua nguoi choi
	SDL_WarpMouse(START_X_POS_MAIN_OBJECT, START_Y_POS_MAIN_OBJECT); // Dat vtri con tro chuot

	/*--------- CHAY CHUONG TRINH DEN KHI QUIT ---------------*/
	SDL_ShowCursor(SDL_DISABLE); // Khong hien thi con tro chuot
	while (!isQuit) {
		while (SDL_PollEvent(&g_event)) {
			if (g_event.type == SDL_QUIT) {
				isQuit = true;
				break;
			}
			shipObj.HanleInputAction(g_event, g_sound_bullet); // bat su kien cho mainObject
		}

		/* ---------- Run background ----------*/
		y_background_begin += SPEED_BACKGROUND;
		SDLCommonFunction::ApplySurface(g_background, g_screen, 0, y_background_begin);
		SDLCommonFunction::ApplySurface(g_background, g_screen, 0, y_background_begin - SCREEN_HEIGHT * 5);
		if (y_background_begin >= SCREEN_HEIGHT * 4) {
			y_background_begin = START_Y_POS_BACKGROUND;
		}
		/*--------- Show PlayerLife------------*/
		lifeMainObj.ShowLife(num_life, g_font_text, g_screen);
		bloodMainObj.ShowBlood(blood_mainObj, g_font_text, g_screen);

		/* ---------- Run mainObject ----------*/
		shipObj.HandleMove(0, 0);
		shipObj.Add_Shooting();
		shipObj.Show(g_screen);
		shipObj.Show_Bullet_Move(g_screen); // mainObject shooter

		/* ----------- Run Threat ------------*/
		for (int thr = 0; thr < NUMBER_THREAT; thr++) {
			ThreatObject_Base* p_threat = p_threats_list.at(thr);
			/*ThreatObject_Base* p_threat = new ThreatObject_0();*/
			//p_threat = p_threats_list.at(thr);
			if (p_threat != NULL) {
				p_threat->HandleMove(SCREEN_WIDTH, SCREEN_HEIGHT);
				p_threat->Show(g_screen);
				p_threat->Make_Bullet(g_screen, SCREEN_WIDTH, SCREEN_WIDTH); // Threat Shooter
			}
			// Ktra va cham giua mainObjectBullet va Threats
			vector<BulletObject_Base*> bulletList = shipObj.getBulletList();
			for (int bl = 0; bl < bulletList.size(); bl++) { // khi làm dự án tránh đặt trùng biến đếm của các vòng for
				BulletObject_Base* p_bullet = bulletList.at(bl);	// điều này rất dễ gây ra lỗi
				if (p_bullet != NULL) {
					bool ret_col = SDLCommonFunction::CheckCollision(p_bullet->getRect(), p_threat->getRect());
					if (ret_col) {
						p_threat->setBlood(p_threat->getBlood() - p_bullet->getDamge());
						shipObj.Remove_Bullet(bl);
						if (p_threat->getBlood() <= 0) {
							//apply exposion
							ExplosionObject* ex = new ExplosionObject(explosion_0);
							int x_pos = p_threat->getRect().x + WIDTH_THREAT * 0.5 - EXP_WIDTH[explosion_0] * 0.5;
							int y_pos = p_threat->getRect().y + HEIGHT_THREAT * 0.5 - EXP_HEIGHT[explosion_0] * 0.5;
							ex->setRect(x_pos, y_pos);
							// todo:: set name()phan biet loại vụ nổ
							ex->LoadImg();
							ex->set_clip();
							explosion_list.push_back(ex);
							//change threat's coordita
							p_threat->Reset();
							p_threat->setBlood(200);
							/*shipObj.Remove_Bullet(bl);*/
							Mix_PlayChannel(-1, g_sound_explosion[1], 0);
							score++;
						}
					}
				}
			}
			// Ktra va cham giua mainObject va Threats
			bool is_col1 = SDLCommonFunction::CheckCollision(shipObj.getRect(), p_threat->getRect());
			if (is_col1) {
				shipObj.setbBlood(0);
				if (shipObj.getBlood() <= 0) {
					//apply exposion
					ExplosionObject* ex = new ExplosionObject(explosion_0);
					int x_pos = shipObj.getRect().x + WIDTH_THREAT * 0.5 - EXP_WIDTH[explosion_0] * 0.5;
					int y_pos = shipObj.getRect().y + HEIGHT_THREAT * 0.5 - EXP_HEIGHT[explosion_0] * 0.5;
					ex->setRect(x_pos, y_pos);
					// todo:: set name()phan biet loại vụ nổ
					ex->LoadImg();
					ex->set_clip();
					explosion_list.push_back(ex);
					//change threat's coordita
					p_threat->Reset();
					p_threat->setBlood(200);
					shipObj.setbBlood(500);
					Mix_PlayChannel(-1, g_sound_explosion[0], 0);
					die_number++;
					if (die_number < NUM_LIFE_BEGIN)
					{
						SDL_WarpMouse(START_X_POS_MAIN_OBJECT, START_Y_POS_MAIN_OBJECT);
						num_life--;
						lifeMainObj.ShowLife(num_life, g_font_text, g_screen);

						if (SDL_Flip(g_screen) == -1)
							return 0;

					}
					else // GAME OVER
					{
						SDL_Delay(1000);
						SDL_ShowCursor(SDL_ENABLE); // Hien thi con tro chuot
						Mix_PlayChannel(-1, g_sound_gameover, 0);
						switch (menu.MenuGameOver(g_screen, g_font_menu, g_font_score, score, g_sound_selection))
						{
						case 0:
							goto Label_StartGame;
						case 1:
							goto Label_MenuStart;
						case 2:
							isQuit = true;
						}
					}
				}
			}
			// Ktra va cham giua threatBullet va mainObject
			bool is_col2 = false;
			p_threat->getBulletList();
			for (int ib = 0; ib < p_threat->getBulletList().size(); ib++)
			{
				BulletObject_Base* p_bullet = p_threat->getBulletList().at(ib);
				if (p_bullet != NULL)
				{
					is_col2 = SDLCommonFunction::CheckCollision(p_bullet->getRect(), shipObj.getRect());
					if (is_col2) {
						shipObj.setbBlood(shipObj.getBlood() - p_bullet->getDamge());
						blood_mainObj = shipObj.getBlood();
						//p_threat->Remove_Bullet(ib);
					}					
					if (shipObj.getBlood()<=0) {
						shipObj.setbBlood(500);
						//apply exposion
						ExplosionObject* ex = new ExplosionObject(explosion_0);
						int x_pos = shipObj.getRect().x + WIDTH_THREAT * 0.5 - EXP_WIDTH[explosion_0] * 0.5;
						int y_pos = shipObj.getRect().y + HEIGHT_THREAT * 0.5 - EXP_HEIGHT[explosion_0] * 0.5;
						ex->setRect(x_pos, y_pos);
						// todo:: set name()phan biet loại vụ nổ
						ex->LoadImg();
						ex->set_clip();
						explosion_list.push_back(ex);
						//change threat's coordita
						//shipObj.setbBlood(500);
						num_life--;
						Mix_PlayChannel(-1, g_sound_explosion[0], 0);
						die_number++;
						
						if (die_number < NUM_LIFE_BEGIN)
						{
							
							SDL_WarpMouse(START_X_POS_MAIN_OBJECT, START_Y_POS_MAIN_OBJECT);
							//num_life--;
							lifeMainObj.ShowLife(num_life, g_font_text, g_screen);

							if (SDL_Flip(g_screen) == -1)
								return 0;
						}
						else // GAME OVER
						{
							SDL_Delay(1000);
							SDL_ShowCursor(SDL_ENABLE); // Hien thi con tro chuot
							Mix_PlayChannel(-1, g_sound_gameover, 0);
							switch (menu.MenuGameOver(g_screen, g_font_menu, g_font_score, score, g_sound_selection))
							{
							case 0:
								goto Label_StartGame;
							case 1:
								goto Label_MenuStart;
							case 2:
								isQuit = true;
							}
						}
					}
				}
			}

			for (int exp = 0; exp < explosion_list.size(); exp++) {
				ExplosionObject* p_exp = explosion_list.at(exp);
				p_exp->Show(g_screen);
				if (p_exp->getFrame_count_() > p_exp->getFrame_number_()) {
					explosion_list.erase(explosion_list.begin() + exp);
					if (p_exp != NULL) {
						delete p_exp;
						p_exp = NULL;
					}
				}
			}
		}
				
		// ----------- Show time for game
		timeGame.ShowTime(g_font_text, g_screen);

		// ----------- Show score to screen
		scoreGame.ShowScore(score, g_font_text, g_screen);

		// ----------- Update screen
		if (SDL_Flip(g_screen) == -1)
			return 0;
	}


	/*delete vector<ThreatObject_Base*> p_threats_list;*/

	SDLCommonFunction::CleanUp();
	SDL_Quit();

	return 0;
}