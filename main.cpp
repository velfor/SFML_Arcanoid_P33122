#include "settings.h"
#include <ctime>
#include "functions.h"
#include "bat.h"
#include "textobj.h"
#include "brick.h"

using namespace sf;
int main()
{
	srand(time(0));

	RenderWindow window(
		VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), 
		WINDOW_TITLE
	);

	int score = 0;

	Bat bat;
	batInit(bat);
	Ball ball;
	ballInit(ball);
	TextObj scoreText;
	textInit(scoreText, score);
	Brick brick;
	brickInit(brick, Color::Yellow, Vector2f{ 0.f, 50.f });

	while (window.isOpen()){
		checkEvents(window);
		updateGame(bat, ball, scoreText, score, brick);
		
		if (ball.shape.getPosition().y >=
			WINDOW_HEIGHT - 2 * BALL_RADIUS)
			break;
		checkCollisions(bat, ball);
		drawGame(window, bat, ball, scoreText, brick);
	}
	return 0;
}