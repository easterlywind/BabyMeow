#pragma once

#include "Lib.hpp"
#include "Constant.hpp"

class Food
{
public:
	//Initializes variables
	Food();

	//Deallocates memory
	~Food();

	//Loads image at specified path
	bool loadFromFile(std::string path);

	//Deallocates texture
	void free();

	//Renders texture at given point
	void render(int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

	//Gets image dimensions
	int getWidth();
	int getHeight();

	// Get position
	int getX();
	int getY();

	void setPos(int x, int y);

	void renew();

private:
	//The actual hardware texture
	SDL_Texture* mTexture;

	//Image dimensions
	int mWidth;
	int mHeight;

	int mPosX, mPosY;
	bool flag_eated;
};
