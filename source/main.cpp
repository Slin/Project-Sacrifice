#include <iostream>
#include <SFML/Main.hpp>
#include <SFML/Graphics.hpp>
using namespace std;

int main(int argc, char* argv[])
{
    sf::RenderWindow App(sf::VideoMode(800, 600), "Project Sacrifice");

    sf::RectangleShape shape;
    shape.setOrigin(0.0f, 0.0f);
    shape.setSize(sf::Vector2<float>(20.0f, 20.0f));

    while(App.isOpen())
    {
        sf::Event Event;
        while(App.pollEvent(Event))
        {
            if (Event.type == sf::Event::Closed)
                App.close();
        }

        App.clear(sf::Color::Black);

        App.draw(shape);

        App.display();
    }
}
