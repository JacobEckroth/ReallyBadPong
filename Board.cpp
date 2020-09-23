#include "Board.h"
#include "Window.h"

void Board::render() {
	ball->render();
	playerPaddle->render();
	computerPaddle->render();
}

void Board::update() {
	ball->update();
	int ballY = ball->getCenterY();


	playerPaddle->update(ballY);
	computerPaddle->update(ballY);
	testPaddles();
}


void Board::testPaddles() {
	if (playerPaddle->intersects(ball->getX(), ball->getY(), ball->getWidth(), ball->getHeight())) {
		ball->flipXVelocity();
		ball->updateX(playerPaddle->getWidth());
	}
	else if (computerPaddle->intersects(ball->getX(), ball->getY(), ball->getWidth(), ball->getHeight())) {
		ball->flipXVelocity();
		ball->updateX(Window::screenWidth - computerPaddle->getWidth() - ball->getWidth());
	}

}

void Board::init() {
	ball = new Ball();
	ball->init();
	playerPaddle = new Paddle();
	computerPaddle = new Paddle();
	playerPaddle->init(false);
	computerPaddle->init(true);



}

Board::~Board() {
	delete ball;
	delete playerPaddle;
	delete computerPaddle;
}

void Board::playerUp(bool active) {
	playerPaddle->setMovingUp(active);

}
void Board::playerDown(bool active) {
	playerPaddle->setMovingDown(active);
}