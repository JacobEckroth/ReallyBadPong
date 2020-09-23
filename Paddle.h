#pragma once
#include "SDL.h"
class Paddle
{

public:
	void render();
	void init(bool);
	void update(int);
	bool intersects(int, int,int,int);
	int getWidth() {
		return paddleWidth;
	}
	void setMovingUp(bool);
	void setMovingDown(bool);
private:
	bool isBot;
	int x;
	int y;
	
	bool movingUp;
	bool movingDown;
	int paddleWidth;
	int paddleHeight;
	int paddleSpeed;
	SDL_Rect drawRect;
	SDL_Color drawColor;
};

