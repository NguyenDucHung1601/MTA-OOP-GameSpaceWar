#include "Common_Function.h"
//#include "Text.h"

SDL_Surface* SDLCommonFunction::Load_Image(std::string imageName) { // ------------------- Tai cac hinh anh len
	SDL_Surface* load_image = NULL;
	SDL_Surface* optimize_image = NULL;
	load_image = IMG_Load(imageName.c_str());
	if (load_image != NULL) {
		optimize_image = SDL_DisplayFormat(load_image);
		SDL_FreeSurface(load_image);

		// --- Xu li ColorKey --- // ---------> Xoa background cua g_object
		if (optimize_image != NULL)
		{
			UINT32 color_key = SDL_MapRGB(optimize_image->format, 0xFF, 0xFF, 0xFF);
			SDL_SetColorKey(optimize_image, SDL_SRCCOLORKEY, color_key);
			//SDL_SetColorKey(optimize_image, SDL_SRCCOLORKEY, color_key1);

			//SDL_SetColorKey(optimize_image, SDL_SRCCOLORKEY, SDL_MapRGB(optimize_image->format, 0x00, 0xFF, 0xFF));

		} //
	}
	return optimize_image;
}

SDL_Rect SDLCommonFunction::ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y) { // ------------ Load image vao man hinh screen
	SDL_Rect offset;
	offset.x = x;
	offset.y = y;
	SDL_BlitSurface(src, NULL, des, &offset);
	return offset;
}

void SDLCommonFunction::ApplySurfaceClip(SDL_Surface * src, SDL_Surface * des, SDL_Rect * clip, int x, int y)
{
	SDL_Rect offset;
	offset.x = x;
	offset.y = y;
	SDL_BlitSurface(src, clip, des, &offset);
}

void SDLCommonFunction::CleanUp() { // ------------- Giai phong cai doi tuong bien global
	SDL_FreeSurface(g_screen);
	SDL_FreeSurface(g_background);
}

bool SDLCommonFunction::CheckCollision(const SDL_Rect & object1, const SDL_Rect & object2)
{
	int deficit = 12; // vùng va chạm nhỏ hơn size object
	int left_obj_1 = object1.x + object1.w / deficit;
	int right_obj_1 = object1.x + object1.w - object1.w / deficit;
	int top_obj_1 = object1.y + object1.h / deficit;
	int bottom_obj_1 = object1.y + object1.h - object1.h / deficit;

	int left_obj_2 = object2.x + object2.w / deficit;
	int right_obj_2 = object2.x + object2.w - object2.w / deficit;
	int top_obj_2 = object2.y + object2.h / deficit;
	int bottom_obj_2 = object2.y + object2.h - object2.h / deficit;

	int y1[2] = { top_obj_1 , bottom_obj_1 };
	int x2[2] = { left_obj_2 , right_obj_2 };
	int x1[2] = { left_obj_1 , right_obj_1 };
	int y2[2] = { top_obj_2, bottom_obj_2 };

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			if (x2[j] >= left_obj_1 && x2[j] <= right_obj_1 && y1[i] >= top_obj_2 && y1[i] <= bottom_obj_2) {
				return true;
			}
		}
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			if (x1[j] >= left_obj_2 && x1[j] <= right_obj_2 && y2[i] >= top_obj_1 && y2[i] <= bottom_obj_1) {
				return true;
			}
		}
	}
	return false;
}