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
		_mainBackground->setTexture(*TexturePool::GetInstance()->GetTexture("assets/textures/background.png"));
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

		groundBodyDef.position.Set(window->getSize().x*0.5f*World::WORLD_TO_BOX2D, (window->getSize().y-(15.0f+34.0f+65.0f+65.0f+75.0f+70.0f+65.0f+60.0f)*world->GetScaleFactor())*World::WORLD_TO_BOX2D);
		groundBody = world->GetPhysicsWorld()->CreateBody(&groundBodyDef);
		groundBox.SetAsBox((133.0f*world->GetScaleFactor())*World::WORLD_TO_BOX2D, 60.0f*world->GetScaleFactor()*World::WORLD_TO_BOX2D);
		groundBody->CreateFixture(&groundBox, 0.0f);


		//Walls
		groundBodyDef.position.Set(-200.0f*world->GetScaleFactor()*World::WORLD_TO_BOX2D, window->getSize().y*0.5f*World::WORLD_TO_BOX2D);
		groundBody = world->GetPhysicsWorld()->CreateBody(&groundBodyDef);
		groundBox.SetAsBox(10.0f*world->GetScaleFactor()*World::WORLD_TO_BOX2D, window->getSize().y*0.5f*World::WORLD_TO_BOX2D);
		groundBody->CreateFixture(&groundBox, 0.0f);

		groundBodyDef.position.Set((window->getSize().x+200.0f*world->GetScaleFactor())*World::WORLD_TO_BOX2D, window->getSize().y*0.5f*World::WORLD_TO_BOX2D);
		groundBody = world->GetPhysicsWorld()->CreateBody(&groundBodyDef);
		groundBox.SetAsBox(10.0f*world->GetScaleFactor()*World::WORLD_TO_BOX2D, window->getSize().y*0.5f*World::WORLD_TO_BOX2D);
		groundBody->CreateFixture(&groundBox, 0.0f);


		_altar = new sf::Sprite();
		_altar->setTexture(*TexturePool::GetInstance()->GetTexture("assets/textures/altar.png"));
		_altar->setScale(_mainBackground->getScale());
		_altar->setOrigin(_altar->getLocalBounds().width/2.0f, _altar->getLocalBounds().height/2.0f);
		_altar->setPosition(window->getSize().x*0.5f + 3.0f*world->GetScaleFactor(), 623.0f*world->GetScaleFactor());


		_feuer1 = new sf::Sprite();
		_feuer1->setTexture(*TexturePool::GetInstance()->GetTexture("assets/textures/feuer.png"));
		_feuer1->setTextureRect(sf::IntRect(0.0f, 0.0f, 349, 692));
		_feuer1->setScale(_mainBackground->getScale());
		_feuer1->setOrigin(_feuer1->getLocalBounds().width/2.0f, _feuer1->getLocalBounds().height/2.0f);
		_feuer1->setPosition(window->getSize().x*0.5f + 640.0f*world->GetScaleFactor(), 670.0f*world->GetScaleFactor());

		_feuer2 = new sf::Sprite();
		_feuer2->setTexture(*TexturePool::GetInstance()->GetTexture("assets/textures/feuer.png"));
		_feuer2->setTextureRect(sf::IntRect(0.0f, 0.0f, 349, 692));
		_feuer2->setScale(_mainBackground->getScale());
		_feuer2->setOrigin(_feuer2->getLocalBounds().width/2.0f, _feuer2->getLocalBounds().height/2.0f);
		_feuer2->setPosition(window->getSize().x*0.5f - 640.0f*world->GetScaleFactor(), 670.0f*world->GetScaleFactor());


		_life1 = new sf::Sprite();
		_life1->setTexture(*TexturePool::GetInstance()->GetTexture("assets/textures/orbohr.png"));
		_life1->setScale(_mainBackground->getScale());
		_life1->setOrigin(_life1->getLocalBounds().width/2.0f, _life1->getLocalBounds().height/2.0f);
		_life1->setPosition(window->getSize().x*0.5f-148.0f*world->GetScaleFactor(), 202.0f*world->GetScaleFactor());

		_life2 = new sf::Sprite();
		_life2->setTexture(*TexturePool::GetInstance()->GetTexture("assets/textures/orbohr.png"));
		_life2->setScale(_mainBackground->getScale());
		_life2->setOrigin(_life2->getLocalBounds().width/2.0f, _life2->getLocalBounds().height/2.0f);
		_life2->setPosition(window->getSize().x*0.5f+148.0f*world->GetScaleFactor(), 202.0f*world->GetScaleFactor());

		_life3 = new sf::Sprite();
		_life3->setTexture(*TexturePool::GetInstance()->GetTexture("assets/textures/orb_eyes.png"));
		_life3->setScale(_mainBackground->getScale());
		_life3->setOrigin(_life3->getLocalBounds().width/2.0f, _life3->getLocalBounds().height/2.0f);
		_life3->setPosition(window->getSize().x*0.5f-63.0f*world->GetScaleFactor(), 138.0f*world->GetScaleFactor());

		_life4 = new sf::Sprite();
		_life4->setTexture(*TexturePool::GetInstance()->GetTexture("assets/textures/orb_eyes.png"));
		_life4->setScale(_mainBackground->getScale());
		_life4->setOrigin(_life4->getLocalBounds().width/2.0f, _life4->getLocalBounds().height/2.0f);
		_life4->setPosition(window->getSize().x*0.5f+63.0f*world->GetScaleFactor(), 138.0f*world->GetScaleFactor());

	}

	Background::~Background()
	{
		delete _mainBackground;
	}

	void Background::Update(float timeStep)
	{
		_animationTimer += timeStep;
		int image = _animationTimer/0.05f;

		_feuer1->setTextureRect(sf::IntRect((image%5)*349, 0.0f, 349, 692));
		_feuer2->setTextureRect(sf::IntRect(((image+2)%5)*349, 0.0f, 349, 692));
	}

	void Background::Draw(sf::RenderWindow *window)
	{
		window->draw(*_mainBackground);

		if(_life1)
			window->draw(*_life1);
		if(_life2)
			window->draw(*_life2);
		if(_life3)
			window->draw(*_life3);
		if(_life4)
			window->draw(*_life4);
	}

	void Background::DrawLate(sf::RenderWindow *window)
	{
		window->draw(*_altar);
		window->draw(*_feuer1);
		window->draw(*_feuer2);
	}

	bool Background::RemoveLife()
	{
		if(_life1)
		{
			delete _life1;
			_life1 = nullptr;
			return false;
		}
		if(_life2)
		{
			delete _life2;
			_life2 = nullptr;
			return false;
		}
		if(_life3)
		{
			delete _life3;
			_life3 = nullptr;
			return false;
		}
		if(_life4)
		{
			delete _life4;
			_life4 = nullptr;
			return false;
		}

		return true;
	}

	int Background::GetNumberOfLifes()
	{

		return (_life1 != nullptr) + (_life2 != nullptr) + (_life3 != nullptr) + (_life4 != nullptr);
	}
}