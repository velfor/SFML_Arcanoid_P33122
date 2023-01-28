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
	brick.shape.setOutlineThickness(1.f);
	brick.shape.setOutlineColor(sf::Color::Black);
}

void brickUpdate(Brick& brick) {}

void brickDraw(sf::RenderWindow& window, const Brick& brick) {
	window.draw(brick.shape);
}
