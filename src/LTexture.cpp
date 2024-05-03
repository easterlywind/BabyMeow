#include "LTexture.hpp"
#include "Global.hpp"
#include "Constant.hpp"

LTexture::LTexture()
{
	//Initialize
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
	mPosX = 0;
	mPosY = 0;
	mVelX = 0;
	mVelY = 0;
}

LTexture::~LTexture()
{
	//Deallocate
	free();
}

bool LTexture::loadFromFile(std::string path)
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

bool LTexture::loadFromRenderedText(std::string textureText, Uint8 r, Uint8 g, Uint8 b)
{
	//Get rid of preexisting texture
	free();

	SDL_Color textColor = { r, g, b };

	//Render text surface
	SDL_Surface* textSurface = TTF_RenderText_Solid(gFont, textureText.c_str(), textColor);
	if (textSurface == NULL)
	{
		printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
	}
	else
	{
		//Create texture from surface pixels
		mTexture = SDL_CreateTextureFromSurface(gRenderer, textSurface);
		if (mTexture == NULL)
		{
			printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
		}
		else
		{
			//Get image dimensions
			mWidth = textSurface->w;
			mHeight = textSurface->h;
		}

		//Get rid of old surface
		SDL_FreeSurface(textSurface);
	}

	//Return success
	return mTexture != NULL;
}

void LTexture::free()
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

void LTexture::render(int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip)
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

int LTexture::getWidth()
{
	return mWidth;
}

int LTexture::getHeight()
{
	return mHeight;
}
void LTexture::setVelocity(int vx, int vy) {
	mVelX = vx;
	mVelY = vy;
}

int LTexture::getX() {
	return mPosX;
}

int LTexture::getY() {
	return mPosY;
}

void LTexture::move() {

	mPosX += mVelX;
	mPosY += mVelY;

	if (mPosX <= 2) {
		mVelX = -mVelX;
	}
	else if (mPosX >= SCREEN_WIDTH - mWidth - 2) {
		mVelX = -mVelX;
	}
	else if (mPosY <= 2) {
		mVelY = -mVelY;
	}
	else if (mPosY >= SCREEN_HEIGHT - mHeight - 2) {
		mVelY = -mVelY;
	}
}

void LTexture::setPos(int x, int y) {
	mPosX = x;
	mPosY = y;
}

int LTexture::getXVelocity()
{
	return mVelX;
}

int LTexture::getYVelocity()
{
	return mVelY;
}

void LTexture::checkvelocity()
{
	if (mVelX > 10) mVelX = 10;
	if (mVelX < -10) mVelX = -10;
	if (mVelY > 10) mVelY = 10;
	if (mVelY < -10) mVelY = -10;
	if (int(SDL_GetTicks() - tmp_time)/ 1400 == 1)
	{
		tmp_time = SDL_GetTicks();
		if ((mVelX == 1 || mVelX == -1) && (mVelY == 1 || mVelY == -1))
		{
			mVelX = 0;
			mVelY = 0;
		}
		if (mVelX > 1) mVelX--;
		if (mVelY > 1) mVelY--;
		if (mVelX < -1) mVelX++;
		if (mVelY < -1) mVelY++;
	}
}

