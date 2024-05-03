#include "Enemy.hpp"
#include "Global.hpp"
#include "Constant.hpp"

Enermy::Enermy()
{
	//Initialize
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
	mPosX = 0;
	mPosY = 0;
	mVelX = 0;
	mVelY = 0;
	renew_flag = false;
}

Enermy::~Enermy()
{
	//Deallocate
	free();
}

bool Enermy::loadFromFile(std::string path)
{
	//Get rid of preexisting texture
	free();

	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{

		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}
		else
		{
			//Get image dimensions
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	//Return success
	mTexture = newTexture;
	return mTexture != NULL;
}

void Enermy::free()
{
	//Free texture if it exists
	if (mTexture != NULL)
	{
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

void Enermy::render(int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip)
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };

	//Set clip rendering dimensions
	if (clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	SDL_RenderCopyEx(gRenderer, mTexture, clip, &renderQuad, angle, center, flip);
}

int Enermy::getWidth()
{
	return mWidth;
}

int Enermy::getHeight()
{
	return mHeight;
}

void Enermy::setVelocity(int vx, int vy) {
	mVelX = vx;
	mVelY = vy;
}

int Enermy::getX() {
	return mPosX;
}

int Enermy::getY() {
	return mPosY;
}

void Enermy::move() {
	mPosX += mVelX;
	mPosY += mVelY;
	if (mPosY > SCREEN_HEIGHT)
	{
		renew_flag = true;
	}

	if (renew_flag)
	{
		renew_flag = false;
		mPosX = rand() % (SCREEN_WIDTH - mWidth);
		mPosY = - 2* mHeight;
	}
}

void Enermy::setPos(int x, int y) {
	mPosX = x;
	mPosY = y;
}

int Enermy::getXVelocity()
{
	return mVelX;
}

int Enermy::getYVelocity()
{
	return mVelY;
}