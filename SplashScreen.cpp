#include "stdafx.h"
#include "SplashScreen.h"

void SplashScreen::Show(sf::RenderWindow &renderWindow) {
	sf::Image image;
	if (image.loadFromFile("C:\\Users\\Jacqueline\\Documents\\Visual Studio 2015\\Projects\\Pang_\\Pang_\\Pang_\\SplashScreen.png") != true) {
		return;
	}
	//I don't know if I need this line after ^ that if statement condition, but just in case:
	image.loadFromFile("C:\\Users\\Jacqueline\\Documents\\Visual Studio 2015\\Projects\\Pang_\\Pang_\\Pang_\\SplashScreen.png"); 
	sf::Texture text;
	text.loadFromImage(image);
	sf::Sprite sprite;
	sprite.setTexture(text);
	renderWindow.draw(sprite);
	renderWindow.display();

	sf::Event event;
	while (true) {
		while (renderWindow.pollEvent(event)) {
			if(event.type == sf::Event::EventType::KeyPressed
				|| event.type == sf::Event::EventType::MouseButtonPressed
				|| event.type == sf::Event::EventType::Closed)
			{
				return;
			}
		}
	}

}