#include "Obstacle.h"

Obstacle::Obstacle(sf::Vector2f sizeL, float gap, sf::Vector2f sizeR)
	: gap(gap)
{
	this->shapeL.setSize(sizeL);
	this->shapeR.setSize(sizeR);

	this->shapeL.setFillColor(sf::Color(77, 53, 13));
	this->shapeR.setFillColor(sf::Color(77, 53, 13));

	this->shapeL.setPosition(0.f, -this->shapeL.getSize().y);
	this->shapeR.setPosition(this->gap + this->shapeL.getSize().x, -this->shapeR.getSize().y);
}

Obstacle::~Obstacle()
{

}

const sf::FloatRect Obstacle::getBoundsL() const
{
	return this->shapeL.getGlobalBounds();
}

const sf::FloatRect Obstacle::getBoundsR() const
{
	return this->shapeR.getGlobalBounds();
}

void Obstacle::move(float velocity, float dt)
{
	this->shapeL.move(0.f, velocity * dt);
	this->shapeR.move(0.f, velocity * dt);
}

void Obstacle::render(sf::RenderTarget* target)
{
	target->draw(shapeL);
	target->draw(shapeR);
}
