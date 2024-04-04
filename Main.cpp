//#include "SFML/Graphics.hpp"
//#include "Menu.h"
//
//int main()
//{
//	sf::RenderWindow window(sf::VideoMode(600, 600), "SFML WORK!");
//
//	Button btn1("Play", { window.getSize().x,window.getSize().y }, 20, sf::Color::Green, sf::Color::Red);
//	btn1.setPosition({ window.getSize().x,window.getSize().y });
//
//	while (window.isOpen())
//	{
//		sf::Event event;
//
//		while (window.pollEvent(event))
//		{
//			switch (event.type)
//			{
//			case sf::Event::Closed:
//				window.close();
//
//				break;
//			case sf::Event::MouseMoved:
//				if (btn1.isMouseOver(window)) {
//					btn1.setBackColor(sf::Color::Red);
//				}
//				else {
//					btn1.setBackColor(sf::Color::Green);
//				}
//			}
//		}
//
//		window.clear();
//		btn1.draw(window);
//		window.display();
//	}
//}
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Menu.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Traffic Surge", sf::Style::Fullscreen | sf::Style::Close);

	Menu menu(window.getSize().x, window.getSize().y);

	sf::Texture texture;
	sf::Sprite bg;
	if (!texture.loadFromFile("menu1.png"))
	{
		//handle error
	}
	bg.setTexture(texture);

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					menu.MoveUp();
					break;

				case sf::Keyboard::Down:
					menu.MoveDown();
					break;

				case sf::Keyboard::Return:
					switch (menu.GetPressedItem())
					{
					case 0:
						std::cout << "Play button has been pressed" << std::endl;
						break;
					case 1:
						std::cout << "Option button has been pressed" << std::endl;
						break;
					case 2:
						window.close();
						break;
					}

					break;
				}

				break;
			case sf::Event::Closed:
				window.close();

				break;

			}
		}

		window.clear();

		window.draw(bg);
		menu.draw(window);

		window.display();
	}
}