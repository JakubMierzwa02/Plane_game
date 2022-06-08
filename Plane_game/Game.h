#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Network.hpp"

class Game
{
private:
	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 600;
	sf::VideoMode videoMode;
	sf::RenderWindow* window;

	// Functions
	void initWindow();

public:
	// Constructors / Destructors
	Game();
	~Game();

	// Functions
	void update();
	void render(sf::RenderTarget* target);

	void run();
};
