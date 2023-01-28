#pragma once
#include "SFML/Graphics.hpp"
#include "bat.h"
#include "ball.h"
#include "textobj.h"
#include "brick.h"
#include "brickRow.h"

bool pointInRect(sf::RectangleShape rect, sf::Vector2f point) {
	float rectX = rect.getPosition().x;
	float rectY = rect.getPosition().y;
	return (point.x >= rectX && point.x <= rectX + rect.getSize().x)
		&& (point.y >= rectY && point.y <= rectY + rect.getSize().y);
}

void checkEvents(sf::RenderWindow& window) {
	sf::Event event;
	while (window.pollEvent(event)){
		if (event.type == sf::Event::Closed)
			window.close();
	}
}

void updateGame(Bat& bat, Ball& ball, TextObj& scoreText, int score,
	BrickField& field) {
	batUpdate(bat);
	ballUpdate(ball);
	textUpdate(scoreText, score);
	brickFieldUpdate(field);
}

void checkCollisions(Bat& bat, Ball& ball) {
	//кто в кого попал, пересёкся и что с этим делать
	sf::Vector2f midLeft{
		ball.shape.getPosition().x,
		ball.shape.getPosition().y + BALL_RADIUS
	};
	sf::Vector2f midTop{
		ball.shape.getPosition().x + BALL_RADIUS,
		ball.shape.getPosition().y
	};
	sf::Vector2f midRight{
		ball.shape.getPosition().x + 2 * BALL_RADIUS,
		ball.shape.getPosition().y + BALL_RADIUS
	};
	sf::Vector2f midBottom{
		ball.shape.getPosition().x + BALL_RADIUS,
		ball.shape.getPosition().y + 2 * BALL_RADIUS
	};
	if (pointInRect(bat.shape, midBottom)) {
		ball.speedY = -ball.speedY;
	}
}
void checkCollisionsWithBricks(Ball& ball, BrickField& field) {
	sf::Vector2f midLeft{
		ball.shape.getPosition().x,
		ball.shape.getPosition().y + BALL_RADIUS
	};
	sf::Vector2f midTop{
		ball.shape.getPosition().x + BALL_RADIUS,
		ball.shape.getPosition().y
	};
	sf::Vector2f midRight{
		ball.shape.getPosition().x + 2 * BALL_RADIUS,
		ball.shape.getPosition().y + BALL_RADIUS
	};
	sf::Vector2f midBottom{
		ball.shape.getPosition().x + BALL_RADIUS,
		ball.shape.getPosition().y + 2 * BALL_RADIUS
	};
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			//в нижний край
			if (pointInRect(field.arr[i][j].shape, midTop)) {
				field.arr[i][j].shape.setPosition(0.f, 1000.f);
				ball.speedY = -ball.speedY;
				break;
			}
			//в верхний край
			if (pointInRect(field.arr[i][j].shape, midBottom)) {
				field.arr[i][j].shape.setPosition(0.f, 1000.f);
				ball.speedY = -ball.speedY;
				break;
			}
			//в левый край
			if (pointInRect(field.arr[i][j].shape, midRight)) {
				field.arr[i][j].shape.setPosition(0.f, 1000.f);
				ball.speedX = -ball.speedX;
				break;
			}
			//в правый край
			if (pointInRect(field.arr[i][j].shape, midLeft)) {
				field.arr[i][j].shape.setPosition(0.f, 1000.f);
				ball.speedX = -ball.speedX;
				break;
			}
		}
	}
}

void drawGame(sf::RenderWindow& window, const Bat& bat, 
	const Ball& ball, const TextObj& scoreText, const BrickField& field)
{
	window.clear();
	batDraw(window, bat);
	ballDraw(window, ball);	
	textDraw(window, scoreText);
	brickFieldDraw(window, field);
	window.display();
}



