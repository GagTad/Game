
#include <iostream>
#include <raylib.h>
#include "Game.h"
#include "Colors.h"

double lastUpdateTime = 0;
bool EventTriggered(double interval) {

	double currentTime = GetTime();
	if (currentTime - lastUpdateTime >= interval) 
	{
		lastUpdateTime = currentTime;
		return true;
	}
	return false;
}

int main()
{
	
	InitWindow(500, 620, "Tetris++");
	SetTargetFPS(60);

	Font font = LoadFontEx("Font/monogram.ttf", 64, 0, 0);
	Game game;

	//Game loop
	while (WindowShouldClose() == false)
	{
		game.HandleInput();
		float fallInterval = 0.5f - (game.GetLevel() - 1) * 0.05f;
		if (fallInterval < 0.1f) fallInterval = 0.1f;

		if (EventTriggered(fallInterval))
		{
			game.MoveBlockDown();
		}



		BeginDrawing();
		ClearBackground(BackColor);
		DrawTextEx(font, "Score", { 365 ,15 }, 38, 2, WHITE);
		DrawTextEx(font, "Next", { 375 ,175 }, 38, 2, WHITE);
		char levelText[20];
		sprintf_s(levelText, "LEVEL %02d", game.GetLevel());
		DrawTextEx(font, levelText, { 330 ,570 }, 38, 1, WHITE);

		char hsText[20];
		sprintf_s(hsText, "BEST: %d", game.highScore);
		DrawTextEx(font, hsText, { 330, 520 }, 30, 2, WHITE);

		if (game.gameOver)
		{
			DrawTextEx(font, "Game Over", { 320 ,450 }, 38, 2, WHITE);
		}
		DrawRectangleRounded({ 320 , 55 , 170 ,60 }, 0.3, 6, lightBlue);

		char scoreText[10];
		sprintf_s(scoreText, "%d", game.score);


		Vector2 textSize = MeasureTextEx(font , scoreText , 38 , 2);

		DrawTextEx(font, scoreText, { 320 +(170 - textSize.x)/2 ,65}, 38, 2, WHITE);
		DrawRectangleRounded({ 320 , 215 , 170 ,180 }, 0.3, 6, lightBlue);
		game.Draw();
		EndDrawing();

	}

	CloseWindow();
}

