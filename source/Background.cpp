//
// Created by Nils Daumann on 07.11.15.
//

#include "Background.h"

namespace PS
{
	Background::Background()
	{
		World *world = World::GetInstance();
		_mainBackground = new sf::Sprite();
		_mainBackground->setTexture(*TexturePool::GetInstance()->GetTexture("assets/textures/azteken_background.png"));
		_mainBackground->setScale(world->GetScaleFactor(), world->GetScaleFactor());

		sf::RenderWindow *window = world->GetWindow();
		float offset = 1920.0f*world->GetScaleFactor() - window->getSize().x;
		_mainBackground->setPosition(-offset*0.5f, 0.0f);

		//Temple
		b2BodyDef groundBodyDef;
		groundBodyDef.position.Set(window->getSize().x*0.5f*World::WORLD_TO_BOX2D, (window->getSize().y + 50.0f)*World::WORLD_TO_BOX2D);
		b2Body *groundBody = world->GetPhysicsWorld()->CreateBody(&groundBodyDef);
		b2PolygonShape groundBox;
		groundBox.SetAsBox((window->getSize().x*0.5f + 1000.0f)*World::WORLD_TO_BOX2D, 50.0f*World::WORLD_TO_BOX2D);
		groundBody->CreateFixture(&groundBox, 0.0f);

		groundBodyDef.position.Set(window->getSize().x*0.5f*World::WORLD_TO_BOX2D, (window->getSize().y-15.0f*world->GetScaleFactor())*World::WORLD_TO_BOX2D);
		groundBody = world->GetPhysicsWorld()->CreateBody(&groundBodyDef);
		groundBox.SetAsBox((743.0f*world->GetScaleFactor())*World::WORLD_TO_BOX2D, 15.0f*world->GetScaleFactor()*World::WORLD_TO_BOX2D);
		groundBody->CreateFixture(&groundBox, 0.0f);

		groundBodyDef.position.Set(window->getSize().x*0.5f*World::WORLD_TO_BOX2D, (window->getSize().y-(15.0f+34.0f)*world->GetScaleFactor())*World::WORLD_TO_BOX2D);
		groundBody = world->GetPhysicsWorld()->CreateBody(&groundBodyDef);
		groundBox.SetAsBox((718.0f*world->GetScaleFactor())*World::WORLD_TO_BOX2D, 34.0f*world->GetScaleFactor()*World::WORLD_TO_BOX2D);
		groundBody->CreateFixture(&groundBox, 0.0f);

		groundBodyDef.position.Set(window->getSize().x*0.5f*World::WORLD_TO_BOX2D, (window->getSize().y-(15.0f+34.0f+65.0f)*world->GetScaleFactor())*World::WORLD_TO_BOX2D);
		groundBody = world->GetPhysicsWorld()->CreateBody(&groundBodyDef);
		groundBox.SetAsBox((670.0f*world->GetScaleFactor())*World::WORLD_TO_BOX2D, 65.0f*world->GetScaleFactor()*World::WORLD_TO_BOX2D);
		groundBody->CreateFixture(&groundBox, 0.0f);

		groundBodyDef.position.Set(window->getSize().x*0.5f*World::WORLD_TO_BOX2D, (window->getSize().y-(15.0f+34.0f+65.0f+65.0f)*world->GetScaleFactor())*World::WORLD_TO_BOX2D);
		groundBody = world->GetPhysicsWorld()->CreateBody(&groundBodyDef);
		groundBox.SetAsBox((594.0f*world->GetScaleFactor())*World::WORLD_TO_BOX2D, 65.0f*world->GetScaleFactor()*World::WORLD_TO_BOX2D);
		groundBody->CreateFixture(&groundBox, 0.0f);

		groundBodyDef.position.Set(window->getSize().x*0.5f*World::WORLD_TO_BOX2D, (window->getSize().y-(15.0f+34.0f+65.0f+65.0f+75.0f)*world->GetScaleFactor())*World::WORLD_TO_BOX2D);
		groundBody = world->GetPhysicsWorld()->CreateBody(&groundBodyDef);
		groundBox.SetAsBox((490.0f*world->GetScaleFactor())*World::WORLD_TO_BOX2D, 75.0f*world->GetScaleFactor()*World::WORLD_TO_BOX2D);
		groundBody->CreateFixture(&groundBox, 0.0f);

		groundBodyDef.position.Set(window->getSize().x*0.5f*World::WORLD_TO_BOX2D, (window->getSize().y-(15.0f+34.0f+65.0f+65.0f+75.0f+70.0f)*world->GetScaleFactor())*World::WORLD_TO_BOX2D);
		groundBody = world->GetPhysicsWorld()->CreateBody(&groundBodyDef);
		groundBox.SetAsBox((437.0f*world->GetScaleFactor())*World::WORLD_TO_BOX2D, 70.0f*world->GetScaleFactor()*World::WORLD_TO_BOX2D);
		groundBody->CreateFixture(&groundBox, 0.0f);

		groundBodyDef.position.Set(window->getSize().x*0.5f*World::WORLD_TO_BOX2D, (window->getSize().y-(15.0f+34.0f+65.0f+65.0f+75.0f+70.0f+65.0f)*world->GetScaleFactor())*World::WORLD_TO_BOX2D);
		groundBody = world->GetPhysicsWorld()->CreateBody(&groundBodyDef);
		groundBox.SetAsBox((373.0f*world->GetScaleFactor())*World::WORLD_TO_BOX2D, 65.0f*world->GetScaleFactor()*World::WORLD_TO_BOX2D);
		groundBody->CreateFixture(&groundBox, 0.0f);

		groundBodyDef.position.Set(window->getSize().x*0.5f*World::WORLD_TO_BOX2D, (window->getSize().y-(15.0f+34.0f+65.0f+65.0f+75.0f+70.0f+65.0f+80.0f)*world->GetScaleFactor())*World::WORLD_TO_BOX2D);
		groundBody = world->GetPhysicsWorld()->CreateBody(&groundBodyDef);
		groundBox.SetAsBox((133.0f*world->GetScaleFactor())*World::WORLD_TO_BOX2D, 80.0f*world->GetScaleFactor()*World::WORLD_TO_BOX2D);
		groundBody->CreateFixture(&groundBox, 0.0f);


		//Walls
		groundBodyDef.position.Set(-200.0f*world->GetScaleFactor()*World::WORLD_TO_BOX2D, window->getSize().y*0.5f*World::WORLD_TO_BOX2D);
		groundBody = world->GetPhysicsWorld()->CreateBody(&groundBodyDef);
		groundBox.SetAsBox(10.0f*world->GetScaleFactor()*World::WORLD_TO_BOX2D, window->getSize().y*0.5f*World::WORLD_TO_BOX2D);
		groundBody->CreateFixture(&groundBox, 0.0f);

		groundBodyDef.position.Set(window->getSize().x+200.0f*world->GetScaleFactor()*World::WORLD_TO_BOX2D, window->getSize().y*0.5f*World::WORLD_TO_BOX2D);
		groundBody = world->GetPhysicsWorld()->CreateBody(&groundBodyDef);
		groundBox.SetAsBox(10.0f*world->GetScaleFactor()*World::WORLD_TO_BOX2D, window->getSize().y*0.5f*World::WORLD_TO_BOX2D);
		groundBody->CreateFixture(&groundBox, 0.0f);
	}

	Background::~Background()
	{
		delete _mainBackground;
	}

	void Background::Update(float timeStep)
	{

	}

	void Background::Draw(sf::RenderWindow *window)
	{
		window->draw(*_mainBackground);
	}
}