#include "PauseMenu.h"

PauseMenu::PauseMenu(float width1, float height1)
{
	if (!font.loadFromFile("Dream.ttf"))
	{
		// handle error
	}
	pausemenu[0].setFont(font);
	pausemenu[0].setFillColor(sf::Color::White);
	pausemenu[0].setString("Play Again");
	pausemenu[0].setCharacterSize(50);
	pausemenu[0].setOutlineThickness(5);
	pausemenu[0].setPosition(sf::Vector2f(width1 / 2.3, height1 / (3 + 1) * .9));

	pausemenu[1].setFont(font);
	pausemenu[1].setFillColor(sf::Color::Red);
	pausemenu[1].setString("Score");
	pausemenu[1].setCharacterSize(50);
	pausemenu[1].setOutlineThickness(5);
	pausemenu[1].setPosition(sf::Vector2f(width1 / 2.3, height1 / (3 + 1) * 1.4));

	pausemenu[2].setFont(font);
	pausemenu[2].setFillColor(sf::Color::Red);
	pausemenu[2].setString("Exit");
	pausemenu[2].setCharacterSize(50);
	pausemenu[2].setOutlineThickness(5);
	pausemenu[2].setPosition(sf::Vector2f(width1 / 2.3, height1 / (3 + 1) * 1.9));


	selectedIndex = 0;
}
PauseMenu::~PauseMenu()
{
}

void PauseMenu::draw1(sf::RenderWindow& window)
{
	for (int i = 0; i < 3; i++)
	{
		window.draw(pausemenu[i]);
	}
}

void PauseMenu::MoveUp1()
{
	if (selectedIndex - 1 >= 0)
	{
		pausemenu[selectedIndex].setFillColor(sf::Color::Red);
		selectedIndex--;
		pausemenu[selectedIndex].setFillColor(sf::Color::White);
	}
}

void PauseMenu::MoveDown1()
{
	if (selectedIndex + 1 < 3)
	{
		pausemenu[selectedIndex].setFillColor(sf::Color::Red);
		selectedIndex++;
		pausemenu[selectedIndex].setFillColor(sf::Color::White);
	}
}
