#include "settings.h"
#include <ctime>
#include "functions.h"
#include "bat.h"
#include "textobj.h"
#include "brick.h"
#include "brickRow.h"

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
	BrickRow brickRow;
	brickRowInit(brickRow, 20, Vector2f{0.f, 60.f}, BRICK_WIDTH);

	while (window.isOpen()){
		checkEvents(window);
		updateGame(bat, ball, scoreText, score, brickRow);
		
		if (ball.shape.getPosition().y >=
			WINDOW_HEIGHT - 2 * BALL_RADIUS)
			break;
		checkCollisions(bat, ball);
		drawGame(window, bat, ball, scoreText, brickRow);
	}
	return 0;
}