#include "LoadFile.hpp"

bool init()
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
	{
		cout << "SDL couldn't ! SDL error: " << SDL_GetError() << endl;
		return false;
	}

	if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
		cout << "Warning: Linear texture filtering not enabled!" << endl;
	}

	gWindow = SDL_CreateWindow("BabyMeow", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (gWindow == NULL)
	{
		cout << "Window coundn't not be created! SDL error: " << SDL_GetError() << endl;
		return false;
	}

	gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (gRenderer == NULL) {
		cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << endl;
		return false;
	}

	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags)) {
		cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << endl;
		return false;
	}

	//Initialize SDL_mixer
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		cout << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << endl;
		return false;
	}

	if (TTF_Init() == -1) {
		cout << "SDL_ttf could not initialize! SDL_ttf Error: " << TTF_GetError() << endl;
		return false;
	}

	return true;
}

bool loadMedia() {
	bool success = true;

	// Tải hình ảnh background
	if (background.loadFromFile("assets/image/background2.png") == false) {
		cout << "Failed to load background image" << endl;
		success = false;
	}

	//Load cat
	if (cat.loadFromFile("assets/image/cat_cry.png") == false) {
		cout << "Failed to load cat image!" << endl;
		success = false;
	}

	//Load dog1
	if (dog.loadFromFile("assets/image/doggo.png") == false) {
		cout << "Failed to load doggo image!" << endl;
		success = false;
	}

	//Load dog2
	if (dog2.loadFromFile("assets/image/doggo2.png") == false) {
		cout << "Failed to load doggo2 image!" << endl;
		success = false;
	}

	//Load game_over_image
	if (game_over_image.loadFromFile("assets/image/game_over_image.png") == false) {
		cout << "Failed to load game_over_image!" << endl;
		success = false;
	}

	//Load food image
	if (pate.loadFromFile("assets/image/pate.png") == false) {
		cout << "Failed to load food!" << endl;
		success = false;
	}

	//Load Arror image
	if (Arrow.loadFromFile("assets/image/Gun.png") == false)
	{
		cout << "Failed to load Arrow image" << endl;
		success = false;
	}

	if (gun_fire_effect.loadFromFile("assets/image/gun_fire_effect.png") == false)
	{
		cout << "Failed to load gun fire effect" << endl;
		success = false;
	}

	if (bullet_image.loadFromFile("assets/image/bullet.png") == false)
	{
		cout << "Failed to load bullet image" << endl;
		success = false;
	}

	if (treasure.loadFromFile("assets/image/treasure.png") == false)
	{
		cout << "Failed to load treasure image" << endl;
		success = false;
	}

	if (restart.loadFromFile("assets/image/wonderful.png") == false)
	{
		cout << "Failed to load restart image" << endl;
		success = false;
	}

	if (music_menu.loadFromFile("assets/image/music_on_1.png") == false)
	{
		cout << "Failed to load music-menu image" << endl;
		success = false;
	}


	if (how_to_play_title[0].loadFromFile("assets/image/play_1.png") == false)
	{
		cout << "Failed to load how-to-play-menu image" << endl;
		success = false;
	}

	if (how_to_play_title[1].loadFromFile("assets/image/exit_1.png") == false)
	{
		cout << "Failed to load how-to-play-menu image" << endl;
		success = false;
	}

	if (return_button.loadFromFile("assets/image/return_button.png") == false)
	{
		cout << "Failed to load return button image" << endl;
		success = false;
	}

	if (score_image.loadFromFile("assets/image/score.png") == false)
	{
		cout << "Failed to load score image" << endl;
		success = false;
	}

	music_menu.setPos(1185, 27);
	return_button.setPos(20, 20);
	//Open the font
	gFont = TTF_OpenFont("assets/fonts/Minecraft.ttf", 24);
	if (gFont == NULL)
	{
		printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
		success = false;
	}

	//Load music
	Music_sound = Mix_LoadMUS("assets/music/music.mp3");
	if (Music_sound == NULL) {
		cout << "Failed to load Music sound" << endl;
		success = false;
	}

	//Load Fire sound effect
	Fire_sound = Mix_LoadWAV("assets/music/gun_fire_effect.wav");
	if (Fire_sound == NULL) {
		cout << "Failed to load Fire effect" << endl;
		success = false;
	}

	//Load Ting sound effect
	Ting_sound = Mix_LoadWAV("assets/music/ting_sound.wav");
	if (Ting_sound == NULL) {
		cout << "Failed to load ting effect" << endl;
		success = false;
	}

	//Load lose sound effect
	Lose_sound = Mix_LoadWAV("assets/music/lose_music.wav");
	if (Lose_sound == NULL) {
		cout << "Failed to load lose effect" << endl;
		success = false;
	}

	//Load dog sound effect
	Dog_sound = Mix_LoadWAV("assets/music/dog_sound.wav");
	if (Dog_sound == NULL) {
		cout << "Failed to load dog effect" << endl;
		success = false;
	}

	//Load cat_eat sound effect
	cat_eat_sound = Mix_LoadWAV("assets/music/cat_eat_sound.wav");
	if (cat_eat_sound == NULL) {
		cout << "Failed to load cat_eat effect" << endl;
		success = false;
	}

	//Load can't shoot effect
	cant_shot_sound = Mix_LoadWAV("assets/music/cant_shot.wav");
	if (cant_shot_sound == NULL) {
		cout << "Failed to load can't shoot effect" << endl;
		success = false;
	}
	SDL_Surface* logo = IMG_Load("assets/image/pate.png");
    SDL_SetWindowIcon(gWindow,logo);

	return success;
}

void close() {

	cat.free();
	dog.free();
	dog2.free();
	game_over_image.free();
	background.free();
	pate.free();
	Font.free();
	Arrow.free();
	restart.free();
	bullet_image.free();
	treasure.free();
	music_menu.free();
	how_to_play_title[0].free();
	how_to_play_title[1].free();
	return_button.free();
	score_image.free();

	Mix_FreeMusic(Music_sound);
	Music_sound = NULL;
	Mix_FreeChunk(Fire_sound);
	Fire_sound = NULL;
	Mix_FreeChunk(Lose_sound);
	Lose_sound = NULL;
	Mix_FreeChunk(cat_eat_sound);
	cat_eat_sound = NULL;
	Mix_FreeChunk(Dog_sound);
	Dog_sound = NULL;
	Mix_FreeChunk(Ting_sound);
	Ting_sound = NULL;
	Mix_FreeChunk(cant_shot_sound);
	cant_shot_sound = NULL;

	TTF_CloseFont(gFont);
	gFont = NULL;
	SDL_DestroyRenderer(gRenderer);
	gRenderer = nullptr;
	SDL_DestroyWindow(gWindow);
	gWindow = nullptr;

	Mix_CloseAudio();
	SDL_FreeSurface(icon);
	SDL_FreeCursor(cursor);
	IMG_Quit();
	SDL_Quit();
	TTF_Quit();
}
