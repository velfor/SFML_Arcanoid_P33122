#include "settings.h"
#include <ctime>
#include "functions.h"
#include "bat.h"
#include "textobj.h"
#include "brick.h"
#include "brickRow.h"
using namespace sf;

enum GameState { PLAY, GAME_OVER };

int main()
{
	srand(time(0));

	RenderWindow window(
		VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), 
		WINDOW_TITLE
	);

	int score = 0;

	GameState gameState = PLAY;

	Bat bat;
	batInit(bat);
	Ball ball;
	ballInit(ball);
	TextObj scoreText;
	
	textInit(scoreText, std::to_string(score));

	TextObj gameOverText;
	textInit(gameOverText, "GAME OVER");
	gameOverText.text.setPosition(400.f,300.f);

	BrickField field;
	brickFieldInit(field);

	while (window.isOpen()){
		checkEvents(window);
		switch (gameState) {
		case PLAY:
			updateGame(bat, ball, scoreText, score, field);
			if (ball.shape.getPosition().y >=
				WINDOW_HEIGHT - 2 * BALL_RADIUS)
				gameState = GAME_OVER;
			checkCollisions(bat, ball);
			checkCollisionsWithBricks(ball, field);
			drawGame(window, bat, ball, scoreText, field);
			break;
		case GAME_OVER:
			window.clear();
			textDraw(window, gameOverText);
			window.display();
			break;
		}
	}
	return 0;
}