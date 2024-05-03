#ifndef MYFUNCTION__H_
#define MYFUNCTION__H_

#include "Global.hpp"
#include "Constant.hpp"


bool checkCollision(LTexture& a, Enermy& b);
bool checkCollision(LTexture& a, Food& b);
void Bullet_calculator();
void initialize();
double getAngle(double x, double y, double x0, double y0);
void gamecalculator();
void gamerender();
bool checkCollision(int& mousex, int& mousey, LTexture& tmp);
void how_to_play_mode();
void menu_mode();
void music_config();

#endif // !MYFUNCTION__H_
