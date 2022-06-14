#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Network.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

class Plane
{
private:
	sf::Texture shapeTex;
	sf::Sprite shape;

public:
	// Constructors / Destructors
	Plane(float pos_x, float pos_y);
	~Plane();

	// Accessors
	const sf::FloatRect getShape() const;

	// Modifiers
	void setPos(sf::Vector2f pos);

	// Functions
	void move(float velocity, float dt);

	void render(sf::RenderTarget* target);
};
