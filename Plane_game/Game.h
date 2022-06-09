#pragma once

#include <iostream>
#include <vector>

#include "Plane.h"
#include "Obstacle.h"

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

	// Game logic
	bool endGame;
	int points;

	// GUI
	sf::Font font;
	sf::Text text;

	// Plane
	Plane* plane;

	// Plane movement
	sf::Vector2f currVelocity;
	sf::Vector2f dir;
	float maxVelocity;
	float acceleration;
	float drag;

	// Obstacle
	float gap_size;
	float rand_size_x;
	int spawnTimerMax;
	int spawnTimer;
	Obstacle* obstacle;
	std::vector<Obstacle*> obstacles;

	// Functions
	void initWindow();
	void initLogic();
	void initGui();
	void initPlane();
	void initObstacle();

public:
	// Constructors / Destructors
	Game();
	~Game();

	// Functions
	void updateEvents();
	void updateInput();
	void checkWindowCollision();
	void checkObstacleCollision();
	void updateObstacles();
	void update();
	void render();

	void run();
};
