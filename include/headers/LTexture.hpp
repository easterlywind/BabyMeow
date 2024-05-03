#ifndef LTEXTURE__H_
#define LTEXTURE__H_

#include "Lib.hpp"
#include "Constant.hpp"

using namespace std;

class LTexture
{
public:
	//Initializes variables
	LTexture();

	//Deallocates memory
	~LTexture();

	//Loads image at specified path
	bool loadFromFile(std::string path);


	#if defined(SDL_TTF_MAJOR_VERSION)
	//Creates image from font string
	bool loadFromRenderedText(string textureText, Uint8 r, Uint8 g, Uint8 b);
	#endif

	//Deallocates texture
	void free();

	//Renders texture at given point
	void render(int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

	//Gets image dimensions
	int getWidth();
	int getHeight();

	// Set velocity
	void setVelocity(int vx, int vy);

	// Get velocity in x and y direction
	int getXVelocity();
	int getYVelocity();
	void checkvelocity();

	// Get position
	int getX();
	int getY();

	void move();

	void setPos(int x, int y);

private:
	//The actual hardware texture
	SDL_Texture* mTexture;

	//Image dimensions
	int mWidth;
	int mHeight;

	int mPosX, mPosY;
	int mVelX, mVelY;
};
#endif // !LTEXTURE__H_
