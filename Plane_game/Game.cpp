#include "Game.h"

void Game::initWindow()
{
	this->videoMode = sf::VideoMode(this->WINDOW_WIDTH, this->WINDOW_HEIGHT);
	this->window = new sf::RenderWindow(this->videoMode, "Plane game!", sf::Style::Default);
	this->window->setFramerateLimit(120);
}

void Game::initPlane()
{
	this->plane = new Plane(this->WINDOW_WIDTH / 2.f, this->WINDOW_HEIGHT - 50.f, sf::Vector2f(20.f, 50.f));
}

// Constructors / Destructors
Game::Game()
{
	this->initWindow();
	this->initPlane();
}

Game::~Game()
{
	delete this->window;
	delete this->plane;
}

void Game::updateEvents()
{
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		default:
			break;
		}
	}
}

// Functions
void Game::update()
{
	this->updateEvents();
}

void Game::render()
{
	this->window->clear();

	// Render stuff
	this->plane->render(this->window);

	this->window->display();
}

void Game::run()
{
	// Game loop
	while (this->window->isOpen())
	{
		this->update();
		this->render();
	}
}
