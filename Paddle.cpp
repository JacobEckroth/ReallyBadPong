#include "Paddle.h"
#include "Window.h"
#include <iostream>

void Paddle::render() {
	SDL_SetRenderDrawColor(Window::renderer, drawColor.r, drawColor.g, drawColor.b, drawColor.a);
	SDL_RenderFillRect(Window::renderer, &drawRect);
}

void Paddle::init(bool isBot) {
	this->isBot = isBot;
	paddleWidth = 40;
	movingUp = movingDown = false;
	paddleHeight = 120;
	drawRect.w = paddleWidth;
	drawRect.h = paddleHeight;
	if (isBot) {
		drawRect.x = x = Window::screenWidth - paddleWidth;
	}
	else {
		drawRect.x = 0;
	}
	drawRect.y = y = Window::screenHeight / 2 - paddleHeight / 2;
	drawColor.r = drawColor.g = drawColor.b = drawColor.a = 255;
	paddleSpeed = 10;
}

void Paddle::update(int ballCenter) {
	int centerOfPaddle = y + paddleHeight / 2;
	if (isBot) {
		if (abs(centerOfPaddle - ballCenter) <= paddleSpeed){
		return;
	}else if (centerOfPaddle > ballCenter) {
			y -= paddleSpeed;
		}
		else if (centerOfPaddle < ballCenter) {
			y += paddleSpeed;
		}
	}
	else {
		if (movingUp) {
			y -= paddleSpeed;
		}
		else if (movingDown) {
			y += paddleSpeed;
		}
	}
	if (y + paddleHeight > Window::screenHeight) {
		y = Window::screenHeight - paddleHeight;
	}
	else if (y < 0) {
		y = 0;
	}
	drawRect.y = y;
}

bool Paddle::intersects(int ballX, int ballY, int ballWidth, int ballHeight) {
	if (ballX+ballWidth > x && ballX+ballWidth <= x + paddleWidth) {
		if (ballY > y && ballY < y + paddleHeight) {
			return true;
		}
		else if (ballY + ballHeight > y && ballY + ballHeight < y + paddleHeight) {
			return true;
		}


	}
	if (ballX > x && ballX <= x + paddleWidth) {
		if (ballY > y && ballY < y + paddleHeight) {
			return true;
		}
		else if (ballY + ballHeight > y && ballY + ballHeight < y + paddleHeight) {
			return true;
		}
	}
	return false;

}

void Paddle::setMovingUp(bool newMove) {
	movingUp = newMove;
	if (movingUp == true) {
		movingDown = false;
	}
}
void Paddle::setMovingDown(bool newMove) {
	movingDown = newMove;
	if (movingDown == true) {
		movingUp = false;
	}
}