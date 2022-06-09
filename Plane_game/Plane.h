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

	// Accessors
	const sf::FloatRect getShape() const;

	// Modifiers
	void setPos(sf::Vector2f pos);

	// Functions
	void move(float velocity, float dt);

	void render(sf::RenderTarget* target);
};
