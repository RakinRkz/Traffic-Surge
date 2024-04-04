#include "Menu.h"


Menu::Menu(float width, float height)
{

	if (!font.loadFromFile("Dream.ttf"))
	{
		// handle error
	}
	/*menu[0].getLocalBounds().x;
	menu[0].getLocalBounds().y;*/
	/*sf::RectangleShape rectangle(sf::Vector2f(200,400));
	rectangle.setPosition(100, 120);
	rectangle.setFillColor(sf::Color::White);
	window.draw(rectangle);*/
	//rectangle.setSize(sf::Vector2f(80, 40));
	/*menu[0].setOutlineColor(sf::Color::Green);
	menu[0].setOutlineThickness(20);*/
	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::White);
	menu[0].setString("Start");
	menu[0].setCharacterSize(50);
	menu[0].setOutlineThickness(5);
	menu[0].setPosition(sf::Vector2f(width / 2.3, height / (MAX_NUMBER_OF_ITEMS + 1) * .9));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::Red);
	menu[1].setString("Leaderboard");
	menu[1].setCharacterSize(50);
	menu[1].setOutlineThickness(5);
	menu[1].setPosition(sf::Vector2f(width / 2.3, height / (MAX_NUMBER_OF_ITEMS + 1) * 1.4));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::Red);
	menu[2].setString("Exit");
	menu[2].setCharacterSize(50);
	menu[2].setOutlineThickness(5);
	menu[2].setPosition(sf::Vector2f(width / 2.3, height / (MAX_NUMBER_OF_ITEMS + 1) * 1.9));


	selectedItemIndex = 0;
}


Menu::~Menu()
{
}
//void Menu::title(sf::RenderWindow& window)
//{
//	sf::Text text;
//	sf::Font font;
//	if (!font.loadFromFile("Cyberpunk-Regular.ttf"))
//	{
//		// handle error
//	}
//	text.setFont(font);
//	text.setString("Traffic Surge");
//	text.setFillColor(sf::Color::Yellow);
//	text.setCharacterSize(50);
//}

void Menu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::White);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::White);
	}
}