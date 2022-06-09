#include "Game.h"

void Game::initWindow()
{
	this->videoMode = sf::VideoMode(this->WINDOW_WIDTH, this->WINDOW_HEIGHT);
	this->window = new sf::RenderWindow(this->videoMode, "Plane game!", sf::Style::Default);
	this->window->setFramerateLimit(60);
}

void Game::initPlane()
{
	// Create new plane
	this->plane = new Plane(this->WINDOW_WIDTH / 2.f, this->WINDOW_HEIGHT - 70.f, sf::Vector2f(30.f, 70.f));

	// Init movement
	this->maxVelocity = 25.f;
	this->acceleration = 1.f;
	this->drag = 0.5f;
}

// Constructors / Destructors
Game::Game()
{
	this->initWindow();
	this->initPlane();

	this->multiplier = 60.f;
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

	// Clock
	dt = clock.restart().asSeconds();
}

void Game::updateInput()
{
	// Acceleration
	this->dir = sf::Vector2f(0, 0);
	// Left
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->dir.x = -1.f;
		if (this->currVelocity.x > -this->maxVelocity)
			this->currVelocity.x += this->acceleration * this->dir.x;
	}
	// Right
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->dir.x = 1.f;
		if (this->currVelocity.x < this->maxVelocity)
			this->currVelocity.x += this->acceleration * this->dir.x;
	}

	// Drag
	if (this->currVelocity.x > 0.f)
	{
		this->currVelocity.x -= this->drag;
		if (this->currVelocity.x < 0.f)
			this->currVelocity.x = 0.f;
	}
	else if (this->currVelocity.x < 0.f)
	{
		this->currVelocity.x += this->drag;
		if (this->currVelocity.x > 0.f)
			this->currVelocity.x = 0.f;
	}

	// Move plane
	this->plane->move(this->currVelocity.x, this->dt * this->multiplier);
}

void Game::checkCollision()
{
	// Left collision
	if (this->plane->getShape().left < 0)
	{
		this->plane->setPos(sf::Vector2f(0, this->plane->getShape().top));
		this->currVelocity.x = 0.f;
	}
	// Right collision
	if (this->plane->getShape().left + this->plane->getShape().width > this->WINDOW_WIDTH)
	{
		this->plane->setPos(sf::Vector2f(this->WINDOW_WIDTH - this->plane->getShape().width, this->plane->getShape().top));
		this->currVelocity.x = 0.f;
	}
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
