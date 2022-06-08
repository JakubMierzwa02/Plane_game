#pragma once

#include "Plane.h"

class Game
{
private:
	// Window
	const int WINDOW_WIDTH = 1280;
	const int WINDOW_HEIGHT = 720;
	sf::VideoMode videoMode;
	sf::RenderWindow* window;
	sf::Event ev;

	// Plane
	Plane* plane;

	// Functions
	void initWindow();
	void initPlane();

public:
	// Constructors / Destructors
	Game();
	~Game();

	// Functions
	void updateEvents();
	void update();
	void render();

	void run();
};
