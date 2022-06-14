#include "Plane.h"

Plane::Plane(float pos_x, float pos_y)
{
	this->shapeTex.loadFromFile("Resources/plane.png");
	this->shape.setTexture(this->shapeTex);
	this->shape.setScale(0.22f, 0.22f);

	this->shape.setPosition(pos_x, pos_y);
}

Plane::~Plane()
{

}

const sf::FloatRect Plane::getShape() const
{
	return this->shape.getGlobalBounds();
}

void Plane::setPos(sf::Vector2f pos)
{
	this->shape.setPosition(pos);
}

void Plane::move(float velocity, float dt)
{
	this->shape.move(velocity * dt, 0);
}

void Plane::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
