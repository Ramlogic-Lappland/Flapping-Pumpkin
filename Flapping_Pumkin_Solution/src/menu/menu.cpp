#include "menu.h"

#include "raylib.h"

#include "globals/globals.h"
#include "globals/button.h"
#include "globals/collisionsManager.h"

#include "gameManager.h"
#include "menu/credits.h"
#include "game/game.h"


namespace Menu
{

	const float ver = 0.3f;

	button::createButton playBttn;
	button::createButton creditsBttn;
	Vector2 pointerPosition = { 0.0f, 0.0f };
	Rectangle pointer;

	bool creditsInitOk;

	void initMenu()
	{
		initButtons();

		pointer = { pointerPosition.x, pointerPosition.y, 20, 20 };
		creditsInitOk = false;
	}

	void updateMenu()
	{
		pointerPosition = GetMousePosition();
		pointer.x = pointerPosition.x;
		pointer.y = pointerPosition.y;


		if (collisions::rectangleRectangle(playBttn.position.x, playBttn.position.y, static_cast<float>(playBttn.buttonText[0].width), static_cast<float>(playBttn.buttonText[0].height), pointerPosition.x, pointerPosition.y, pointer.width, pointer.height))
		{
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				Game::initGame();
				gameManager::currentscreen = gameManager::game;
			}
		}

		if (collisions::rectangleRectangle(creditsBttn.position.x, creditsBttn.position.y, static_cast<float>(creditsBttn.buttonText[0].width), static_cast<float>(creditsBttn.buttonText[0].height), pointerPosition.x, pointerPosition.y, pointer.width, pointer.height))
		{
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{			
				if (creditsInitOk == false)
				{
					Credits::initCredits();
					creditsInitOk = true;
				}
				gameManager::currentscreen = gameManager::credits;
			}
		}

	}

	void drawMenu()
	{
		DrawTexture(playBttn.buttonText[playBttn.buttonFrame], static_cast<int>(playBttn.position.x), static_cast<int>(playBttn.position.y), WHITE);
		DrawTexture(creditsBttn.buttonText[creditsBttn.buttonFrame], static_cast<int>(creditsBttn.position.x), static_cast<int>(creditsBttn.position.y), WHITE);

		DrawText(TextFormat("Version: %.1f", ver), 0, 0, 20, RED);
#ifdef _DEBUG
		DrawRectangle(static_cast<int>(pointer.x), static_cast<int>(pointer.y), static_cast<int>(pointer.width), static_cast<int>(pointer.height), RED);
#endif
	}

	void unloadMenu()
	{
		for (int i = 0; i < playBttn.amountOfFrames; i++)
		{
			UnloadTexture(playBttn.buttonText[i]);
		}
		for (int i = 0; i < creditsBttn.amountOfFrames; i++)
		{
			UnloadTexture(creditsBttn.buttonText[i]);
		}
	}

	void initButtons()
	{
		playBttn.amountOfFrames = 1;
		playBttn.buttonText[playBttn.amountOfFrames];
		playBttn.buttonFrame = 0;
		playBttn.buttonText = new Texture2D[playBttn.amountOfFrames];
		playBttn.buttonText[0] = LoadTexture("res/menu/play_button.png");
		playBttn.position = { (Globals::Screen.size.x / 2 - (playBttn.buttonText[0].width / 2)), 200 };

		creditsBttn.amountOfFrames = 1;
		creditsBttn.buttonText[creditsBttn.amountOfFrames];
		creditsBttn.buttonFrame = 0;
		creditsBttn.buttonText = new Texture2D[creditsBttn.amountOfFrames];
		creditsBttn.buttonText[0] = LoadTexture("res/menu/credits_button.png");
		creditsBttn.position = { (Globals::Screen.size.x / 2 - (creditsBttn.buttonText[0].width / 2)), 400 };
	}
}