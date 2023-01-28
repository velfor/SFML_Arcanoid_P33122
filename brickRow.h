#pragma once
#include "settings.h"
#include "SFML/Graphics.hpp"
#include "brick.h"

struct BrickField {
	Brick arr[8][20];
};

void brickFieldInit(BrickField& field)
{
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			sf::Color color;
			if (i == 0 || i == 1) color = sf::Color::Red;
			if (i == 2 || i == 3) color = sf::Color{255, 105, 0};
			if (i == 4 || i == 5) color = sf::Color::Green;
			if (i == 6 || i == 7) color = sf::Color::Yellow;
			sf::Vector2f brickPos{ 
				j * BRICK_WIDTH, 60.f + i*BRICK_HEIGHT };
			brickInit(field.arr[i][j], color, brickPos);
		}
	}
}

void brickFieldUpdate(BrickField& field) {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			brickUpdate(field.arr[i][j]);
		}
	}
}

void brickFieldDraw(sf::RenderWindow& window, const BrickField& field) {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			window.draw(field.arr[i][j].shape);
		}
	}
}


