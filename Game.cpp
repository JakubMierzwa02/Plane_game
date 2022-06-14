#include "Game.h"

void Game::initWindow()
{
	this->videoMode = sf::VideoMode(this->WINDOW_WIDTH, this->WINDOW_HEIGHT);
	this->window = new sf::RenderWindow(this->videoMode, "Plane game!", sf::Style::Default);
	this->window->setFramerateLimit(60);
}

void Game::initLogic()
{
	this->endGame = false;
	this->points = 0;
}

void Game::initGui()
{
	if (!this->font.loadFromFile("Fonts/font.ttf"))
		std::cout << "Error";

	this->text.setFont(this->font);
	this->text.setCharacterSize(32);
	this->text.setFillColor(sf::Color::White);
	this->text.setPosition(sf::Vector2f(10.f, 10.f));
	this->text.setString("NONE");
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

void Game::initObstacle()
{
	this->gap_size = 150.f;
	this->spawnTimerMax = 80;
	this->spawnTimer = this->spawnTimerMax;
}

// Constructors / Destructors
Game::Game()
{
	this->multiplier = 60.f;

	this->initWindow();
	this->initLogic();
	this->initGui();
	this->initPlane();
	this->initObstacle();
}

Game::~Game()
{
	delete this->window;
	delete this->plane;
}

// Functions
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

void Game::checkWindowCollision()
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

void Game::updateObstacles()
{
	// Spawn obstacle
	if (this->spawnTimer < this->spawnTimerMax)
		this->spawnTimer++;
	else
	{
		this->rand_size_x = rand() % int(this->WINDOW_WIDTH - this->gap_size);
		this->obstacles.push_back(new Obstacle(sf::Vector2f(this->rand_size_x, 30.f), this->gap_size, sf::Vector2f(this->WINDOW_WIDTH - this->gap_size, 30.f)));
		this->spawnTimer = 0;
	}

	for (size_t i = 0; i < this->obstacles.size(); i++)
	{
		// Move obstacles
		this->obstacles[i]->move(5.f, this->dt * this->multiplier);

		// Get point
		if (this->plane->getShape().top < this->obstacles[i]->getBoundsL().top && this->obstacles[i]->getBoundsL().top < this->plane->getShape().top + 5.f)
			this->points++;

		// Check if out of bounds
		if (this->obstacles[i]->getBoundsL().top > this->WINDOW_HEIGHT)
		{
			delete this->obstacles[i];
			this->obstacles.erase(this->obstacles.begin() + i);
		}
	}
}

void Game::checkObstacleCollision()
{
	for (size_t i = 0; i < this->obstacles.size(); i++)
	{
		if (this->plane->getShape().intersects(this->obstacles[i]->getBoundsL()) || this->plane->getShape().intersects(this->obstacles[i]->getBoundsR()))
			this->endGame = true;
	}
}

void Game::updateGui()
{
	std::stringstream ss;
	ss << "Points: " << this->points;
	this->text.setString(ss.str());
}

void Game::update()
{
	this->updateEvents();
	this->updateInput();
	this->checkWindowCollision();
	this->checkObstacleCollision();
	this->updateObstacles();
	this->updateGui();
}

void Game::render()
{
	this->window->clear();

	// Render stuff
	// Render obstacles
	for (size_t i = 0; i < this->obstacles.size(); i++)
	{
		this->obstacles[i]->render(this->window);
	}

	// Render plane
	this->plane->render(this->window);

	// Render GUI
	this->window->draw(this->text);

	this->window->display();
}

void Game::run()
{
	// Game loop
	while (this->window->isOpen())
	{
		if (!endGame)
			this->update();
		this->render();
	}
}
