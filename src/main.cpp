#include "Global.hpp"
#include "Constant.hpp"
#include "MyFunction.hpp"
#include "LTexture.hpp"
#include "Enemy.hpp"
#include "Food.hpp"
#include "LoadFile.hpp"

using namespace std;


int main(int argc, char* args[])
{
	if (!init())
	{
		cout << "Failed to initialize!" << endl;
	}
	else
	{
		if (!loadMedia())
		{
			cout << "Failed to load media!" << endl;
		}
		else
		{
			highest_score = 0;
			bool quit = false;
			initialize();
			while (quit == false)
			{
				//MENU_MODE
				Music_sound = Mix_LoadMUS("assets/music/music-menu.mp3");
				Mix_PlayMusic(Music_sound, -1);
				while (GAME_OVER == true && quit == false)
				{
					while (SDL_PollEvent(&e) != 0)
					{
						if (e.type == SDL_QUIT)
						{
							quit = true;
							GAME_OVER = true;
						}
						if (e.type == SDL_MOUSEBUTTONDOWN)
						{
							SDL_GetMouseState(&x_mouse, &y_mouse);
							if (checkCollision(x_mouse, y_mouse, music_menu))
							{
								music_config();
							}
							if (checkCollision(x_mouse, y_mouse, how_to_play_title[0]))
							{
								GAME_OVER = false;
							}
							if (checkCollision(x_mouse, y_mouse, how_to_play_title[1]))
							{
								quit = true;
								GAME_OVER = true;
							}
						}
					}

					SDL_RenderClear(gRenderer);
					menu_mode();
					SDL_RenderPresent(gRenderer);
				}

				//PLAY MODE
				initialize();
				while (GAME_OVER == false && quit == false)
				{
					while (SDL_PollEvent(&e) != 0)
					{
						if (e.type == SDL_QUIT)
						{
							quit = true;
							GAME_OVER = true;
						}
						if (e.type == SDL_MOUSEBUTTONDOWN)
						{
							SDL_GetMouseState(&x_mouse, &y_mouse);
							if (checkCollision(x_mouse, y_mouse, music_menu))
							{
								music_config();
							} else if (checkCollision(x_mouse, y_mouse, return_button))
								{
									GAME_OVER = true;
								}
							else if (bullet_count > 0)
								{
									Mix_PlayChannel(-1, Fire_sound, 0);
									tmp_time = SDL_GetTicks();
									int push_x = -(x_mouse - cat.getX()) / 45 + cat.getXVelocity();
									int push_y = -(y_mouse - cat.getY()) / 45 + cat.getYVelocity();
									cat.setVelocity(push_x, push_y);
									bullet_count--;
									press_mouse = true;
								}
							else Mix_PlayChannel(-1, cant_shot_sound, 0);
						}
					}
					SDL_RenderClear(gRenderer);
					gamecalculator();
					gamerender();
					SDL_RenderPresent(gRenderer);
				}
				SDL_Delay(1000);
			}
		}
	}

	close();
	return 0;
}
