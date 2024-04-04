#pragma once
#include<SFML/Graphics.hpp>
class PauseMenu
{
public:
	PauseMenu(float width1, float height1);
	~PauseMenu();

	void draw1(sf::RenderWindow& window1);
	void MoveUp1();
	void MoveDown1();
	int GetPressedItem1() { 
		return selectedIndex; 
	}

private:
	int selectedIndex;
	sf::Font font;
	sf::Text pausemenu[3];
};

