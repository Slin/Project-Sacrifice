#include <iostream>
#include <SFML/Main.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <Box2D/Box2D.h>

using namespace std;

int main(int argc, char* argv[])
{
    sf::RenderWindow App(sf::VideoMode(800, 600), "Project Sacrifice");
    sf::Time time = sf::Time::Zero;

    sf::RectangleShape shape;
    shape.setPosition(sf::Vector2<float>(50.0f, 50.0f));
    shape.setSize(sf::Vector2<float>(50.0f, 50.0f));


    b2Vec2 gravity(0.0f, 9.81f);
    b2World world(gravity);

    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0.0f, 500.0f);
    b2Body* groundBody = world.CreateBody(&groundBodyDef);
    b2PolygonShape groundBox;
    groundBox.SetAsBox(1000.0f, 10.0f);
    groundBody->CreateFixture(&groundBox, 0.0f);

    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(0.0f, 4.0f);
    b2Body* body = world.CreateBody(&bodyDef);

    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(50.0f, 50.0f);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;

    body->CreateFixture(&fixtureDef);

    sf::Clock clock;

    while(App.isOpen())
    {
        sf::Event Event;
        while(App.pollEvent(Event))
        {
            if (Event.type == sf::Event::Closed)
                App.close();
        }

        time += clock.getElapsedTime();
        clock.restart();
        while(time.asSeconds() > 1.0f/60.0f)
        {
            world.Step(1.0f/60.0f, 6, 2);
            b2Vec2 position = body->GetPosition();
            float32 angle = body->GetAngle();
            shape.setPosition(position.x, position.y);

            time -= sf::seconds(1.0f/60.0f);
        }

        App.clear(sf::Color::Black);
        App.draw(shape);

        App.display();
    }
}
