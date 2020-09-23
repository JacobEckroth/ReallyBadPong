#pragma once
#include "Paddle.h"
#include "Ball.h"

class Board
{

public:
	void render();
	void update();
	void init();
	void playerUp(bool);
	void playerDown(bool);
	void testPaddles();
	~Board();
private:
	Paddle* playerPaddle;
	Paddle* computerPaddle;
	Ball* ball;


};

