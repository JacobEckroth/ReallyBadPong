#pragma once
#include "SDL.h"

class Ball
{

public:
	void render();
	void update();
	void init();
	int getCenterY() {
		return y + ballHeight/2;
	}
	int getY() {
		return y;
	}
	int getX() {
		return x;
	}
	int getWidth() {
		return ballWidth;
	}
	int getHeight() {
		return ballHeight;
	}
	void updateX(int newX) {
		x = newX;
	}

	void calculateStartingVelocities();
	void flipXVelocity();
	void respawn();
private:
	int x;
	int y;
	float xvel;
	float yvel;
	int maxTotalVel = 15;
	int ballWidth;
	int ballHeight;
	SDL_Rect drawRect;
	SDL_Color drawColor;
};

