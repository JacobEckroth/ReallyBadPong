#include "Window.h"

#include <iostream>

int Window::screenHeight = 0;
int Window::screenWidth = 0;
SDL_Renderer* Window::renderer = nullptr;
Window::Window() {

}

Window::~Window() {

}

void Window::update() {
	board->update();

}

void Window::handleEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	case SDL_KEYDOWN:
		handleKeyDown(event.key);
		break;
	case SDL_KEYUP:
		handleKeyUp(event.key);
		break;
		/*case SDL_MOUSEBUTTONDOWN:
			board->handleMouseDown(event.button);
			break;
		case SDL_MOUSEBUTTONUP:
			board->handleMouseUp(event.button);
			break;*/
	}
}

void Window::handleKeyDown(SDL_KeyboardEvent& key) {
	
	switch (key.keysym.scancode) {
	case 82:
		board->playerUp(true);
		break;
	case 81:
		board->playerDown(true);
		break;
	default:
		std::cout << "Scancode is:" << key.keysym.scancode << std::endl;
		break;
	}
}
void Window::handleKeyUp(SDL_KeyboardEvent& key) {

	switch (key.keysym.scancode) {
	case 82:
		board->playerUp(false);
		break;
	case 81:
		board->playerDown(false);
		break;
	default:
		std::cout << "Scancode is:" << key.keysym.scancode << std::endl;
		break;
	}
}


void Window::clean() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);	//error here
	delete board;
	SDL_Quit();


	std::cout << "Succesfully cleaned!\n";
}

bool Window::running() {
	return isRunning;
}


void Window::render() {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	board->render();

	SDL_RenderPresent(Window::renderer);

}
void Window::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
	int flags = 0;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Subsystems Initialized!\n";
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window) {
			std::cout << "Window Created!\n";
		}
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 121, 121, 121, 255);
			std::cout << "Renderer created!\n";
			SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
		}
		screenHeight = height;
		isRunning = true;
	}

	else {
		isRunning = false;
	}
	screenWidth = width;
	screenHeight = height;
	board = new Board();
	board->init();




}

