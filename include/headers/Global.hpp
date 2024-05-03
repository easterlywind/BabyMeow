#pragma once

#include "Lib.hpp"
#include "LTexture.hpp"
#include "Enemy.hpp"
#include "Food.hpp"

using namespace std;

//The renderer we'll be using
extern SDL_Renderer* gRenderer;

// The window we'll be rendering to
extern SDL_Window* gWindow;

//Globally used font
extern TTF_Font* gFont;

extern SDL_Surface* icon;

extern SDL_Cursor* cursor;

extern SDL_Event e;

extern LTexture cat;
extern LTexture game_over_image;
extern LTexture background;
extern LTexture Font;
extern Enermy dog;
extern Enermy dog2;
extern Food pate;
extern LTexture restart;

extern bool GAME_OVER;

extern int Score;
extern int bullet_count;
extern int treasure_armor;

extern string cout_score;
extern Uint32 startTime;
extern float angle_arrow;
extern LTexture Arrow;
extern LTexture gun_fire_effect;
extern LTexture bullet_image;
extern Enermy treasure;

extern Mix_Music* Music_sound;
extern Mix_Chunk* Fire_sound;
extern Mix_Chunk* Lose_sound;
extern Mix_Chunk* cat_eat_sound;
extern Mix_Chunk* Dog_sound;
extern Mix_Chunk* Ting_sound;
extern Mix_Chunk* cant_shot_sound;

extern int x_mouse;
extern int y_mouse;

extern bool press_mouse;

extern LTexture music_menu;
extern LTexture how_to_play_title[2];
extern LTexture return_button;
extern LTexture score_image;

extern bool	music_flag;

extern Uint32 tmp_time;
extern int highest_score;

