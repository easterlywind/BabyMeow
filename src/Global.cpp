#include "Global.hpp"

using namespace std;

//The renderer we'll be using
SDL_Renderer* gRenderer = NULL;

// The window we'll be rendering to
SDL_Window* gWindow = NULL;

//Globally used font
TTF_Font* gFont = NULL;

SDL_Surface* icon = NULL;

SDL_Cursor* cursor = NULL;

SDL_Event e;

LTexture cat;
LTexture game_over_image;
LTexture background;
LTexture Font;
Enermy dog;
Enermy dog2;
Food pate;
LTexture restart;

bool GAME_OVER = true;
float angle_arrow = 0;
int Score = 0;
int bullet_count = 0;
int treasure_armor = 0;

Uint32 startTime = SDL_GetTicks();
string cout_score;

LTexture Arrow;
LTexture gun_fire_effect;
LTexture bullet_image;
Enermy treasure;

Mix_Music* Music_sound = NULL;
Mix_Chunk* Fire_sound = NULL;
Mix_Chunk* Lose_sound = NULL;
Mix_Chunk* cat_eat_sound = NULL;
Mix_Chunk* Dog_sound = NULL;
Mix_Chunk* Ting_sound = NULL;
Mix_Chunk* cant_shot_sound = NULL;

int x_mouse = 0;
int y_mouse = 0;

bool press_mouse = false;
int highest_score = 0;
Uint32 tmp_time = 0;


LTexture music_menu;
LTexture how_to_play_title[2];
LTexture return_button;
LTexture score_image;

bool music_flag = true;


