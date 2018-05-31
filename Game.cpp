#include "stdafx.h"
#include "Game.h"
#include "SplashScreen.h"
#include "MainMenu.h"


void Game::Start(void) {
	if (_gameState != Uninitialized)
		return;

	_mainWindow.create(sf::VideoMode(1024, 768, 32), "Pang!");

	PlayerPaddle *player1 = new PlayerPaddle();
	player1->Load("C:\\Users\\Jacqueline\\Documents\\Visual Studio 2015\\Projects\\Pang_\\Pang_\\Pang_\\paddle.png");
	player1->SetPosition((1024 / 2) - 45, 700);

	_gameObjectManager.Add("Paddle1", player1);
	_gameState = Game::ShowingSplash;

	while (!IsExiting()) {
		GameLoop();
	}
	_mainWindow.close();
}

bool Game::IsExiting()
{
	if (_gameState == Game::Exiting)
		return true;
	else
		return false;
}

void Game::GameLoop()
{
	sf::Event currentEvent;
	// getEvent changed to pollEvent
	_mainWindow.pollEvent(currentEvent);
	

		switch (_gameState)
		{
		case Game::ShowingMenu: {
			ShowMenu();
			break;
		}
		case Game::ShowingSplash: {
			ShowSplashScreen();
			break;
		}
		case Game::Playing:
		{
			while (_mainWindow.pollEvent(currentEvent)) {
				_mainWindow.clear(sf::Color(255, 0, 0));
				_gameObjectManager.DrawAll(_mainWindow);
				_mainWindow.display();

				if (currentEvent.type == sf::Event::Closed)
				{
					_gameState = Game::Exiting;
				}
				if (currentEvent.type == sf::Event::KeyPressed) {
					if (currentEvent.KeyPressed == sf::Keyboard::Escape) ShowMenu();
				}
			}
			break;
		}
		}
	
}

void Game::ShowSplashScreen() {
	SplashScreen splashScreen;
	splashScreen.Show(_mainWindow);
	_gameState = Game::ShowingMenu;
}

void Game::ShowMenu() {
	MainMenu mainMenu;
	MainMenu::MenuResult result = mainMenu.Show(_mainWindow);

	switch (result) {
		case MainMenu::Exit:
			_gameState = Game::Exiting;
			break;
		case MainMenu::Play:
			_gameState = Game::Playing;
			break;
	}
}


// C++ thing, static member variables need to instantiated outside of the class
Game::GameState Game::_gameState = Uninitialized;
sf::RenderWindow Game::_mainWindow;
GameObjectManager Game::_gameObjectManager;