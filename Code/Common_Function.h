#ifndef COMMON_FUNCTION_H_
#define COMMON_FUNCTION_H_


#include<Windows.h>
#include <string>
#include <stdlib.h>
#include <time.h>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>


// Background
const int SCREEN_WIDTH = 1500;
const int SCREEN_HEIGHT = 900;
const int SCREEN_BPP = 32;
const float SPEED_BACKGROUND = 0.75;
const int START_Y_POS_BACKGROUND = -3600;

// Main Object
const int START_X_POS_MAIN_OBJECT = 720;
const int START_Y_POS_MAIN_OBJECT = 800;
const int NUM_LIFE_BEGIN = 3;


// Threats
const int NUMBER_THREAT = 9;
const int SPEED_THREAT = 10;
const int SPEED_BULLET_THREAT = 15;


// Global
static SDL_Surface* g_screen = NULL;
static SDL_Surface* g_background = NULL;
static SDL_Surface* g_object = NULL; //////////// Cai nay dung de lam gi???
static SDL_Surface* g_image_menu = NULL;
static SDL_Event g_event;

static Mix_Chunk* g_sound_music[2];
static Mix_Chunk* g_sound_selection;
static Mix_Chunk* g_sound_bullet[6];
static Mix_Chunk* g_sound_item[4];
static Mix_Chunk* g_sound_explosion[2];
static Mix_Chunk* g_sound_gameover;

static TTF_Font* g_font_text = NULL;
static TTF_Font* g_font_menu = NULL;
static TTF_Font* g_font_score = NULL;

// Picture
static std::string g_picture_menuStart = "menuStart.png";
static std::string g_picture_menuInstructions = "menuInstructions.png";
static std::string g_picture_menuHightSocre = "menuHighScore.png";
static std::string g_picture_menuInformation = "menuInformation.png";
static std::string g_picture_menuGameOver = "menuGameOver.png";
static std::string g_picture_background = "background.png";
static std::string g_picture_mainObj = "ship001.png";
static std::string g_picture_threat = "threat001.png";
//static std::string g_picture_explosion = "e2.png";


static std::string g_picture_bulletThreat = "bulletthreat.png";

static std::string g_picture_rocket_1 = "rocket001.png";
static std::string g_picture_rocket_2 = "rocket002.png";
static std::string g_picture_rocket_3 = "rocket003.png";

static std::string g_picture_life = "heart.png";
static std::string g_picture_health = "health.png";
static std::string g_picture_shield = "shield.png";

static std::string g_picture_powerup = "powerup.png";
static std::string g_picture_powerup_1 = "powerup001.png";
static std::string g_picture_powerup_2 = "powerup002.png";
static std::string g_picture_powerup_3 = "powerup003.png";
static std::string g_picture_powerup_4 = "powerup004.png";
static std::string g_picture_powerup_5 = "powerup005.png";

// Audio
static char g_audio_bulletMain_1[] = { "bullet001_Laser.wav" };
static char g_audio_bulletMain_2[] = { "bullet002_Fire.wav" };
static char g_audio_bulletMain_3[] = { "bullet003_Ball.wav" };
static char g_audio_bulletMain_4[] = { "bullet004_Electronic.wav" };
static char g_audio_bulletMain_5[] = { "bullet005_Nuclear.wav" };
static char g_audio_bulletThreat[] = { "bullet_Threat.wav" };

static char g_audio_music_1[] = { "music_background.wav" };
static char g_audio_music_2[] = { "music.wav" };
static char g_audio_selection[] = { "selection.wav" };
static char g_audio_gameover[] = { "game_over.ogg" };

static char g_audio_explosion_1[] = { "Explosion1.wav" };
static char g_audio_explosion_2[] = { "Explosion2.wav" };

static char g_audio_health[] = { "health.ogg" };
static char g_audio_shield[] = { "shield.ogg" };
static char g_audio_powerup[] = { "powerup.ogg" };
static char g_audio_life[] = { "life.ogg" };


// FontText
static char g_fontText[] = { "VNBAHAB.ttf" };
static char g_fontMenu[] = { "First Job (Demo).ttf " };





namespace SDLCommonFunction { // Dua vao namespace ---> Tranh bi trung lap

	SDL_Surface* Load_Image(std::string imageName); // --------------- Tai hinh anh len
	SDL_Rect ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y); // ---------- Load image vao man hinh screen
	void ApplySurfaceClip(SDL_Surface* src, SDL_Surface *des, SDL_Rect* clip, int x, int y); //---------- Load image vu no
	void CleanUp(); // ----------- Giai phong cac doi tuong bien global
	bool CheckCollision(const SDL_Rect& object1, const SDL_Rect& object2); // --------- Ktra va cham
}


#endif