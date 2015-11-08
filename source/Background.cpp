//
// Created by Nils Daumann on 07.11.15.
//

#include "Background.h"
#include <iostream>

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

		_blood1 = new sf::Sprite();
		_blood1->setTexture(*TexturePool::GetInstance()->GetTexture("assets/textures/blood_stains_01.png"));
		_blood1->setOrigin(_blood1->getLocalBounds().width/2.0f, _blood1->getLocalBounds().height/2.0f);
		_blood1->setScale(_mainBackground->getScale());
		_blood1->setPosition(window->getSize().x*0.5f, window->getSize().y*0.5f);
		_blood1->setColor(sf::Color(255, 255, 255, 0));

		_blood2 = new sf::Sprite();
		_blood2->setTexture(*TexturePool::GetInstance()->GetTexture("assets/textures/blood_stains_02.png"));
		_blood2->setOrigin(_blood2->getLocalBounds().width/2.0f, _blood2->getLocalBounds().height/2.0f);
		_blood2->setScale(_mainBackground->getScale());
		_blood2->setPosition(window->getSize().x*0.5f, window->getSize().y*0.5f);
		_blood2->setColor(sf::Color(255, 255, 255, 0));

		_blood3 = new sf::Sprite();
		_blood3->setTexture(*TexturePool::GetInstance()->GetTexture("assets/textures/blood_stains_03.png"));
		_blood3->setOrigin(_blood3->getLocalBounds().width/2.0f, _blood3->getLocalBounds().height/2.0f);
		_blood3->setScale(_mainBackground->getScale());
		_blood3->setPosition(window->getSize().x*0.5f, window->getSize().y*0.5f);
		_blood3->setColor(sf::Color(255, 255, 255, 0));

		_feuer1 = new sf::Sprite();
		_feuer1->setTexture(*TexturePool::GetInstance()->GetTexture("assets/textures/firebig.png"));
		_feuer1->setTextureRect(sf::IntRect(0.0f, 0.0f, 372, 905));
		_feuer1->setScale(_mainBackground->getScale());
		_feuer1->setOrigin(_feuer1->getLocalBounds().width/2.0f, _feuer1->getLocalBounds().height/2.0f);
		_feuer1->setPosition(window->getSize().x*0.5f + 640.0f*world->GetScaleFactor(), 650.0f*world->GetScaleFactor());

		_feuer2 = new sf::Sprite();
		_feuer2->setTexture(*TexturePool::GetInstance()->GetTexture("assets/textures/firebig.png"));
		_feuer2->setTextureRect(sf::IntRect(0.0f, 0.0f, 372, 905));
		_feuer2->setScale(_mainBackground->getScale());
		_feuer2->setOrigin(_feuer2->getLocalBounds().width/2.0f, _feuer2->getLocalBounds().height/2.0f);
		_feuer2->setPosition(window->getSize().x*0.5f - 640.0f*world->GetScaleFactor(), 650.0f*world->GetScaleFactor());

		_feuer3 = new sf::Sprite();
		_feuer3->setTexture(*TexturePool::GetInstance()->GetTexture("assets/textures/firesmall.png"));
		_feuer3->setTextureRect(sf::IntRect(0.0f, 0.0f, 91, 185));
		_feuer3->setScale(_mainBackground->getScale());
		_feuer3->setOrigin(_feuer3->getLocalBounds().width/2.0f, _feuer3->getLocalBounds().height/2.0f);
		_feuer3->setPosition(window->getSize().x*0.5f + 230.0f*world->GetScaleFactor(), 170.0f*world->GetScaleFactor());

		_feuer4 = new sf::Sprite();
		_feuer4->setTexture(*TexturePool::GetInstance()->GetTexture("assets/textures/firesmall.png"));
		_feuer4->setTextureRect(sf::IntRect(0.0f, 0.0f, 91, 185));
		_feuer4->setScale(_mainBackground->getScale());
		_feuer4->setOrigin(_feuer4->getLocalBounds().width/2.0f, _feuer4->getLocalBounds().height/2.0f);
		_feuer4->setPosition(window->getSize().x*0.5f - 218.0f*world->GetScaleFactor(), 170.0f*world->GetScaleFactor());


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

		_abdunkel = new sf::Sprite();
		_abdunkel->setTexture(*TexturePool::GetInstance()->GetTexture("assets/textures/abdunkel.png"));
		_abdunkel->setOrigin(_abdunkel->getLocalBounds().width/2.0f, _abdunkel->getLocalBounds().height/2.0f);
		_abdunkel->setScale(_mainBackground->getScale());
		_abdunkel->setPosition(window->getSize().x*0.5f, window->getSize().y*0.5f);

	}

	Background::~Background()
	{
		delete _mainBackground;
		delete _altar;
		delete _blood1;
		delete _blood2;
		delete _blood3;
		delete _feuer1;
		delete _feuer2;
		delete _feuer3;
		delete _feuer4;
		delete _life1;
		delete _life2;
		delete _life3;
		delete _life4;
		delete _abdunkel;
	}

	void Background::Update(float timeStep)
	{
		_animationTimer += timeStep;
		int image = _animationTimer/0.1f;

		_feuer1->setTextureRect(sf::IntRect((image%7)*372, 0.0f, 372, 905));
		_feuer2->setTextureRect(sf::IntRect(((image+3)%7)*372, 0.0f, 372, 905));

		_feuer3->setTextureRect(sf::IntRect((image%7)*91, 0.0f, 91, 185));
		_feuer4->setTextureRect(sf::IntRect(((image+3)%7)*91, 0.0f, 91, 185));

		if(_animationTimer > 10.0f && _animationTimer < 20.0f)
		{
			_blood1->setColor(sf::Color(255, 255, 255, (_animationTimer-10.0f)*255.0f/10.0f));
		}
		if(_animationTimer >= 20.0f && _animationTimer < 30.0f)
		{
			_blood1->setColor(sf::Color(255, 255, 255, 255));
			_blood2->setColor(sf::Color(255, 255, 255, (_animationTimer-20.0f)*255.0f/10.0f));
		}
		if(_animationTimer >= 30.0f && _animationTimer < 40.0f)
		{
			_blood2->setColor(sf::Color(255, 255, 255, 255));
			_blood3->setColor(sf::Color(255, 255, 255, (_animationTimer-30.0f)*255.0f/10.0f));
		}
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

		window->draw(*_feuer3);
		window->draw(*_feuer4);
	}

	void Background::DrawLate(sf::RenderWindow *window)
	{
		window->draw(*_altar);
		window->draw(*_blood1);
		window->draw(*_blood2);
		window->draw(*_blood3);
		window->draw(*_abdunkel);
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
	void Background::AddLife()
	{
		std::cout<<"Background::AddLife() implement me :D"<<std::endl;
	}
}