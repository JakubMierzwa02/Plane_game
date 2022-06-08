#include "Game.h"

void Game::initWindow()
{
	this->videoMode = sf::VideoMode(this->WINDOW_WIDTH, this->WINDOW_HEIGHT);
	this->window = new sf::RenderWindow(this->videoMode, "Plane game!", sf::Style::Default);
	this->window->setFramerateLimit(120);
}

void Game::initPlane()
{
	// Create new plane
	this->plane = new Plane(this->WINDOW_WIDTH / 2.f, this->WINDOW_HEIGHT - 70.f, sf::Vector2f(30.f, 70.f));
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

void Game::updateInput()
{
	// Move left
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		this->plane->move(-1.f, 0);
	// Move right
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->plane->move(1.f, 0);
}

void Game::checkCollision()
{
	// Left collision
	if (this->plane->getShape().left < 0)
		this->plane->move(1.f, 0);
	// Right collision
	if (this->plane->getShape().left + this->plane->getShape().width > this->WINDOW_WIDTH)
		this->plane->move(-1.f, 0);
}

// Functions
void Game::update()
{
	this->updateEvents();
	this->updateInput();
	this->checkCollision();
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
