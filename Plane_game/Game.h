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

	// Framerate
	sf::Clock clock;
	float dt;
	float multiplier;

	// Plane
	Plane* plane;

	// Plane movement
	sf::Vector2f currVelocity;
	sf::Vector2f dir;
	float maxVelocity;
	float acceleration;
	float drag;

	// Functions
	void initWindow();
	void initPlane();

public:
	// Constructors / Destructors
	Game();
	~Game();

	// Functions
	void updateEvents();
	void updateInput();
	void checkCollision();
	void update();
	void render();

	void run();
};
