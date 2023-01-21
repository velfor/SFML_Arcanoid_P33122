#pragma once
#include "settings.h"
#include "SFML/Graphics.hpp"

struct Brick {
	sf::RectangleShape shape;
	sf::Color color;
	sf::Vector2f position;
};

void brickInit(Brick& brick, sf::Color color, sf::Vector2f position) {
	brick.color = color;
	brick.position = position;
	brick.shape.setPosition(brick.position);
	brick.shape.setFillColor(brick.color);
	brick.shape.setSize(sf::Vector2f{ BRICK_WIDTH, BRICK_HEIGHT });
}

void brickUpdate(Brick& brick) {}


