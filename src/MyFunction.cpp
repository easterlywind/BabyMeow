#include "MyFunction.hpp"

bool checkCollision(LTexture& a, Enermy& b)
{
	int leftA = a.getX();
	int rightA = a.getX() + a.getWidth();
	int topA = a.getY();
	int bottomA = a.getY() + a.getHeight();

	int leftB = b.getX();
	int rightB = b.getX() + b.getWidth();
	int topB = b.getY();
	int bottomB = b.getY() + b.getHeight();

	if (bottomA <= topB || topA >= bottomB || rightA <= leftB || leftA >= rightB)
	{
		return false;
	}
	return true;
}

bool checkCollision(LTexture& a, Food& b)
{
	int leftA = a.getX();
	int rightA = a.getX() + a.getWidth();
	int topA = a.getY();
	int bottomA = a.getY() + a.getHeight();

	int leftB = b.getX();
	int rightB = b.getX() + b.getWidth();
	int topB = b.getY();
	int bottomB = b.getY() + b.getHeight();

	if (bottomA <= topB || topA >= bottomB || rightA <= leftB || leftA >= rightB)
	{
		return false;
	}
	return true;
}
Uint32 time_reload;
void Bullet_calculator()
{
	if ((SDL_GetTicks() - time_reload) / 1650 >= 1)
	{
		bullet_count++;
		time_reload = SDL_GetTicks();
	}
}

double getAngle(double x, double y, double x0, double y0) {
	x -= x0;
	y -= y0;
	return atan2(y, x) * 180 / M_PI;
}

bool checkCollision(int& mousex, int& mousey, LTexture& tmpp)
{
	int LeftX = tmpp.getX();
	int RightX = tmpp.getX() + tmpp.getWidth();
	int TopY = tmpp.getY();
	int BottomY = tmpp.getY() + tmpp.getHeight();
	if ((mousex >= LeftX && mousex <= RightX) && (mousey >= TopY && mousey <= BottomY))
	{
		return true;
	}
	return false;
}

void initialize()
{
	srand(time(0));

	//if (Mix_PausedMusic()) Mix_ResumeMusic();
	Mix_FreeMusic(Music_sound);
	Music_sound = NULL;
	Music_sound = Mix_LoadMUS("assets/music/music.mp3");
	if (music_flag == true && GAME_OVER == false) Mix_PlayMusic(Music_sound, -1);

	SDL_Surface* icon = IMG_Load("assets/image/popcat2_mini.png");
	SDL_Cursor* cursor = SDL_CreateColorCursor(icon, 0, 0);
	SDL_SetCursor(cursor);

	Score = 0;
	startTime = SDL_GetTicks();
	treasure_armor = 3;
	pate.renew();

	cat.setPos((SCREEN_WIDTH - cat.getWidth()) / 2, (SCREEN_HEIGHT - cat.getHeight()) / 2);
	cat.setVelocity(0, 1);
	cat.loadFromFile("assets/image/cat.png");

	bullet_count = 3;

	dog.setVelocity(0, 1);
	dog2.setVelocity(0, 1);
	dog.setPos(rand() % (SCREEN_WIDTH - dog.getWidth()), -dog.getHeight());
	dog2.setPos(rand() % (SCREEN_WIDTH - dog2.getWidth()), -dog2.getHeight());
	Arrow.setPos((SCREEN_WIDTH - Arrow.getWidth()) / 2, (SCREEN_HEIGHT - Arrow.getHeight()) / 2);
	bullet_image.setPos((SCREEN_WIDTH - bullet_image.getWidth()) / 2 - 15, score_image.getHeight() + 20);
	//Treasure
	treasure.setVelocity(0, 1);
	treasure.setPos(rand() % (SCREEN_WIDTH - treasure.getWidth()), -treasure.getHeight() - 20);
}

void gamecalculator()
{
	Bullet_calculator();
	SDL_GetMouseState(&x_mouse, &y_mouse);

	cat.checkvelocity();
	dog2.setVelocity(0, (SDL_GetTicks() - startTime) / 6000 + 1);

	if (checkCollision(cat, treasure))
	{
		if (treasure_armor == 0)
		{
			Mix_PlayChannel(-1, cat_eat_sound, 0);
			Mix_PlayChannel(-1, Ting_sound, 0);
			Score += 5;
			bullet_count += 5;
			treasure.setPos(rand() % (SCREEN_WIDTH - treasure.getWidth()), -200);
			treasure_armor = 3;
		}
		else
		{
			Mix_PlayChannel(-1, Ting_sound, 0);
			int tmpvelX = 0, tmpvelY = 0;
			if (-cat.getXVelocity() < 0) tmpvelX = -1;
			if (-cat.getXVelocity() > 0) tmpvelX = 1;
			if (-cat.getYVelocity() < 0) tmpvelY = -1;
			if (-cat.getYVelocity() > 0) tmpvelY = 1;
			cat.setVelocity(-cat.getXVelocity() + tmpvelX, -cat.getYVelocity() + tmpvelY);
			treasure_armor--;
		}
	}

	cat.move();
	dog.move();
	dog2.move();
	treasure.move();

	Arrow.setPos(cat.getX() - (Arrow.getWidth() - cat.getWidth()) / 2, cat.getY() - (Arrow.getHeight() - cat.getHeight()) / 2);
	angle_arrow = getAngle(x_mouse, y_mouse, Arrow.getX() + Arrow.getWidth() / 2, Arrow.getY() + Arrow.getHeight() / 2);

	if (checkCollision(cat, dog) || checkCollision(cat, dog2))
	{
		GAME_OVER = true;
	}
	if (checkCollision(cat, pate))
	{
		Mix_PlayChannel(-1, cat_eat_sound, 0);
		Score++;
		bullet_count += 2;
		pate.renew();
	}

	if (music_flag == false && Mix_PausedMusic() == 0) Mix_PauseMusic();
	if (music_flag == true && Mix_PausedMusic() == 1) Mix_ResumeMusic();
	if (music_flag == true && Mix_PlayingMusic() == 0) Mix_PlayMusic(Music_sound, -1);
	if (GAME_OVER == true) {
		if (cat.loadFromFile("assets/image/cat_cry.png") == false)
			cout << "Failed to load cat_cry image" << endl;
		Mix_PauseMusic();
		Mix_PlayChannel(-1, Lose_sound, 0);
		Music_sound = Mix_LoadMUS("assets/music/music-menu.mp3");
	}
}

void gamerender()
{
	background.render(0, 0, NULL, 0, NULL, SDL_FLIP_NONE);

	pate.render(pate.getX(), pate.getY(), NULL, 0, NULL, SDL_FLIP_NONE);
	dog.render(dog.getX(), dog.getY(), NULL, 0, NULL, SDL_FLIP_NONE);
	dog2.render(dog2.getX(), dog2.getY(), NULL, 0, NULL, SDL_FLIP_NONE);
	Arrow.render(Arrow.getX(), Arrow.getY(), NULL, angle_arrow, NULL, SDL_FLIP_NONE);
	if (press_mouse)
	{
		gun_fire_effect.setPos(Arrow.getX() + Arrow.getWidth() / 2 - gun_fire_effect.getWidth()/2, Arrow.getY() + Arrow.getHeight() / 2 - gun_fire_effect.getHeight() / 2);
		gun_fire_effect.render(gun_fire_effect.getX(), gun_fire_effect.getY(), NULL, angle_arrow, NULL, SDL_FLIP_NONE);
		press_mouse = false;
	}

	treasure.render(treasure.getX(), treasure.getY());
	cat.render(cat.getX(), cat.getY(), NULL, 0, NULL, SDL_FLIP_NONE);
	if (GAME_OVER) {
		highest_score = max(highest_score, Score);
		game_over_image.render((SCREEN_WIDTH - game_over_image.getWidth()) / 2, (SCREEN_HEIGHT - game_over_image.getHeight()) / 2, NULL, 0, NULL, SDL_FLIP_NONE);
	}

	bullet_image.render(bullet_image.getX(), bullet_image.getY());

	cout_score = ": ";
	cout_score += to_string(bullet_count);
	Font.loadFromRenderedText(cout_score, 0, 0, 0);
	Font.render(bullet_image.getX() + bullet_image.getWidth() + 10, bullet_image.getY() + (bullet_image.getHeight() - Font.getHeight()) / 2);

	cout_score = ": ";
	cout_score += to_string(Score);
	Font.loadFromRenderedText(cout_score, 0, 0, 0);
	Font.render((SCREEN_WIDTH - score_image.getWidth() - Font.getWidth()) / 2 + score_image.getWidth() + 5, 20 + (score_image.getHeight() - Font.getHeight()) / 2);
	score_image.render((SCREEN_WIDTH - score_image.getWidth() - Font.getWidth()) / 2, 20);

	string tmp_string = "" + to_string(treasure_armor);
	if (treasure_armor == 0)
	{
		Font.loadFromRenderedText(tmp_string, 255, 0, 0);
	}
	else
	{
		Font.loadFromRenderedText(tmp_string, 0, 0, 0);
	}
	Font.render(treasure.getX() + treasure.getWidth(), treasure.getY());

	music_menu.render(music_menu.getX(), music_menu.getY());

	return_button.render(return_button.getX(), return_button.getY());
}


void menu_mode()
{
	if (music_flag == false)
	{
		Mix_PauseMusic();
	}
	if (music_flag == true && Mix_PausedMusic())
	{
		Mix_ResumeMusic();
	}
	restart.render(restart.getX(), restart.getY(), NULL, 0, NULL, SDL_FLIP_NONE);


	how_to_play_title[0].setPos(619, 378);
	how_to_play_title[0].render(how_to_play_title[0].getX(), how_to_play_title[0].getY());

	how_to_play_title[1].setPos(619, 474);
	how_to_play_title[1].render(how_to_play_title[1].getX(), how_to_play_title[1].getY());

	string tmp_string = to_string(highest_score);
	Font.loadFromRenderedText(tmp_string, 0, 0, 0);
	Font.render( 800, 344);


	music_menu.render(music_menu.getX(), music_menu.getY());
}

void music_config()
{
	if (music_flag == true) music_flag = false;
		else music_flag = true;
	if (music_flag == true)
		if (music_menu.loadFromFile("assets/image/music_on_1.png") == false) {
			cout << "Failed to load music-on!" << endl;
		}
	if (music_flag == false)
		if (music_menu.loadFromFile("assets/image/music_off_1.png") == false) {
			cout << "Failed to load music-off!" << endl;
		}
}
