#include <SFML/Graphics.hpp>
#include <locale>
#include<iostream>
#include<string>
using namespace std;

int main()
{
    sf::RenderWindow window({ 1920 ,1080 }, "test");

    std::string input_text;
    sf::Font font;
    font.loadFromFile("LATINWD.ttf");
    sf::Text text("", font);
    text.setFillColor(sf::Color::Red);
    text.setPosition(850, 300);

    sf::RectangleShape box(sf::Vector2f(300, 80));
    box.setFillColor(sf::Color::White);
    box.setPosition(775, 280);
    
    //string str;

    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::TextEntered) {
                if (std::isprint(event.text.unicode))
                    input_text += event.text.unicode;
            }
            else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::BackSpace) {
                    if (!input_text.empty())
                        input_text.pop_back();
                }
                if (event.key.code == sf::Keyboard::Return) {
                    cout << input_text;
                }
            }
        }


        static sf::Time text_effect_time;
        static bool show_cursor;

        text_effect_time += clock.restart();

        if (text_effect_time >= sf::seconds(0.5f))
        {
            show_cursor = !show_cursor;
            text_effect_time = sf::Time::Zero;
        }

        text.setString(input_text + (show_cursor ? '_' : ' '));

        window.clear();
        window.draw(box);
        window.draw(text);
        window.display();
    }
}