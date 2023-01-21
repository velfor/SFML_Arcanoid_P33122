#pragma once
#include "settings.h"
#include "SFML/Graphics.hpp"
#include "brick.h"

struct BrickRow {
	Brick arr[10];
	int size;
};

void brickInit(BrickRow& brickRow, int size, sf::Vector2f position,
	float stepX)
{
	brickRow.size = size;
	for (int i = 0; i < brickRow.size; i++) {
		sf::Color color{ (sf::Uint8)(25 * i), 100, 100 };
		sf::Vector2f brickPos{position.x + i*stepX, position.y};
		brickInit(brickRow.arr[i], color, brickPos);
	}
}