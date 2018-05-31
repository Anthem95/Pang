#include "stdafx.h"
#include "MainMenu.h"

MainMenu::MenuResult MainMenu::Show(sf::RenderWindow& window) {
	
	//Load menu image from static filename
	sf::Image image;
	image.loadFromFile("C:\\Users\\Jacqueline\\Documents\\Visual Studio 2015\\Projects\\Pang_\\Pang_\\Pang_\\mainmenu.png");
	sf::Sprite sprite; 
	sf::Texture text;
	text.loadFromImage(image);
	sprite.setTexture(text);

	//Setup clickable regions

	//Play menu item coords
	MenuItem playButton;
	playButton.rect.top = 145;
	playButton.rect.height = 380;
	playButton.rect.left = 0;
	playButton.rect.width = 1023;
	playButton.action = Play;

	//Exit menu item coords
	MenuItem exitButton;
	exitButton.rect.left = 0;
	exitButton.rect.width = 1023;
	exitButton.rect.top = 383;
	exitButton.rect.height = 560;
	exitButton.action = Exit;

	_menuItems.push_back(playButton);
	_menuItems.push_back(exitButton);

	window.draw(sprite);
	window.display();

	return GetMenuResponse(window);

}


MainMenu::MenuResult MainMenu::HandleClick(int x, int y) {

	std::list<MenuItem>::iterator it; // iterates through the list of menu items.

	for (it = _menuItems.begin(); it != _menuItems.end(); it++) {
		sf::Rect<int> menuItemRect = (*it).rect; 
		if (menuItemRect.height > y && menuItemRect.top < y && menuItemRect.left < x && menuItemRect.width > x) {
			return (*it).action; //Location of click pointer
			// if it's located within bounds, find the action that corresponds with the text and call it.
		}
	}

	return Nothing; // return handle Nothing if the click wasn't within range of a button on the ui window
}

MainMenu::MenuResult MainMenu::GetMenuResponse(sf::RenderWindow& window) {

	sf::Event menuEvent;
	

	while (true) {
		while (window.pollEvent(menuEvent)) {
			if (menuEvent.type == sf::Event::MouseButtonPressed) {
				return HandleClick(menuEvent.mouseButton.x, menuEvent.mouseButton.y);
			}
			if (menuEvent.type == sf::Event::Closed) {
				return Exit;
			}
		}
	}

}
