#pragma once
#include "SFML/Graphics.hpp"
#include "bat.h"
#include "ball.h"
#include "textobj.h"
#include "brick.h"

bool pointInRect(sf::RectangleShape bat, sf::Vector2f point) {
	float batX = bat.getPosition().x;
	float batY = bat.getPosition().y;
	return (point.x >= batX && point.x <= batX + BAT_WIDTH)
		&& (point.y >= batY && point.y <= batY + BAT_HEIGHT);
}

void checkEvents(sf::RenderWindow& window) {
	sf::Event event;
	while (window.pollEvent(event)){
		if (event.type == sf::Event::Closed)
			window.close();
	}
}

void updateGame(Bat& bat, Ball& ball, TextObj& scoreText, int score,
	Brick& brick) {
	batUpdate(bat);
	ballUpdate(ball);
	textUpdate(scoreText, score);
	brickUpdate(brick);
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

void drawGame(sf::RenderWindow& window, const Bat& bat, 
	const Ball& ball, const TextObj& scoreText, const Brick& brick) {
	window.clear();
	batDraw(window, bat);
	ballDraw(window, ball);	
	textDraw(window, scoreText);
	brickDraw(window, brick);
	window.display();
}



