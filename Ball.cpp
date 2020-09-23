#include "Ball.h"
#include "Window.h"
#include <iostream>
void Ball::init() {
	ballWidth = ballHeight = 30;
	calculateStartingVelocities();
	drawRect.w = ballWidth;
	drawRect.h = ballHeight;
	drawRect.x = x = Window::screenWidth / 2 + ballWidth / 2;
	drawRect.y = y =Window::screenHeight / 2 + ballHeight / 2;

	drawColor.r = drawColor.g = drawColor.b = drawColor.a = 255;

}



void Ball::render() {
	SDL_SetRenderDrawColor (Window::renderer, drawColor.r, drawColor.g, drawColor.b, drawColor.a);
	SDL_RenderFillRect(Window::renderer, &drawRect);
}

void Ball::calculateStartingVelocities() {
	xvel = rand() % (maxTotalVel-2) + 2;
	yvel = pow(pow(maxTotalVel, 2) - pow(xvel, 2), .5);
	/*std::cout << "New X:" << xvel << std::endl;
	std::cout << "New Y:" << yvel << std::endl;*/
	int choice = rand() % 2;
	if (choice == 1) {
		xvel = -xvel;
	}
	choice = rand() % 2;
	if (choice == 1) {
		yvel = -yvel;
	}
}

void Ball::update() {
	x += xvel;
	y += yvel;

	if (y < 0) {
		y = 0;
		yvel = -yvel;
	}
	else if (y + ballHeight > Window::screenHeight) {
		y = Window::screenHeight - ballHeight;
		yvel = -yvel;
	}

	drawRect.x = x;
	drawRect.y = y;

	if (x < 0 - ballWidth) {
		respawn();
	}
	else if (x > Window::screenWidth) {
		respawn();
	}

	
	
}

void Ball::respawn() {
	
	calculateStartingVelocities();
	drawRect.x = x = Window::screenWidth / 2 + ballWidth / 2;
	drawRect.y = y = Window::screenHeight / 2 + ballHeight / 2;
	
}

void Ball::flipXVelocity() {
	xvel = -xvel;
}

