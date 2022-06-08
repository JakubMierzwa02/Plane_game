#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Network.hpp"

class Plane
{
private:
	sf::RectangleShape shape;

	sf::Color color;
	float movementSpeed;

public:
	// Constructors / Destructors
	Plane(float pos_x, float pos_y, sf::Vector2f size);
	~Plane();

	// Functions
	void move(const float dir_x, const float dir_y);
	void update();
	void render(sf::RenderTarget* target);
};
