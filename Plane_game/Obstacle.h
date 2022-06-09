#pragma once

#include "SFML/Graphics.hpp"

class Obstacle
{
private:
	sf::RectangleShape shapeL;
	float gap;
	sf::RectangleShape shapeR;

public:
	// Constructor / Destructror
	Obstacle(sf::Vector2f sizeL, float gap, sf::Vector2f sizeR);
	~Obstacle();

	// Accessors
	const sf::FloatRect getPos() const;

	// Functions
	void move(float, float);
	void render(sf::RenderTarget*);
};