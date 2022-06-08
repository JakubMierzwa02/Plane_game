#include "Game.h"

void Game::initWindow()
{
	this->videoMode = sf::VideoMode(this->WINDOW_WIDTH, this->WINDOW_HEIGHT);
	this->window = new sf::RenderWindow(this->videoMode, "Plane game!", sf::Style::Default);
	this->window->setFramerateLimit(120);
}

// Constructors / Destructors
Game::Game()
{
	this->initWindow();
}

Game::~Game()
{
	delete this->window;
}

// Functions
void Game::update()
{

}

void Game::render(sf::RenderTarget* target)
{

}

void Game::run()
{
	while (this->window->isOpen())
	{
		this->update();
		this->render(this->window);
	}
}
