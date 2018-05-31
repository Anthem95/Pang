#include "stdafx.h"
#include "MainMenu.h"

MainMenu::MenuResult MainMenu::Show(sf::RenderWindow& window) {
	
	//Load menu image from file
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

	std::list<MenuItem>::iterator it; // dafuq does this do?
	// I think this just iterates through the list of menu items.
	// idk why you'd use this though instead of just a standard counter,
	// since there aren't that many options to choose from. 

	for (it = _menuItems.begin(); it != _menuItems.end(); it++) {
		sf::Rect<int> menuItemRect = (*it).rect; //yeah, I need to look up this syntax.
		if (menuItemRect.height > y && menuItemRect.top < y && menuItemRect.left < x && menuItemRect.width > x) {
			return (*it).action; //maybe this is like a location pointer? So wherever it is on the screen,
			// if it's located within those bounds, find the action it's connected to and call it.
		}
	}

	return Nothing; // return handle Nothing if the click wasn't within range of a button on the gui
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