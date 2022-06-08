#include "Plane.h"

Plane::Plane(float pos_x, float pos_y, sf::Vector2f size)
{
	this->color = sf::Color::White;
	this->movementSpeed = 10.f;

	this->shape.setFillColor(color);
	this->shape.setSize(size);
	this->shape.setPosition(pos_x, pos_y);
}

Plane::~Plane()
{

}

void Plane::move(const float dir_x, const float dir_y)
{
	this->shape.move(this->movementSpeed * dir_x, this->movementSpeed * dir_y);
}

void Plane::update()
{
	
}

void Plane::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
