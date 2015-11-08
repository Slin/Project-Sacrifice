//
// Created by Nils Daumann on 07.11.15.
//

#include "Animal.h"
#include "Ragdoll.h"
namespace PS
{
	Animal::Animal(Type type)
	{
		_leftHalf = nullptr;
		_rightHalf = nullptr;
		_object = nullptr;

		_leftHalfBody = nullptr;

		_isMovingUp = false;

		_type = type;

		_object = new sf::Sprite();
		switch(_type){
			case Type::Baby:
				_object->setTexture(*TexturePool::GetInstance()->GetTexture("assets/textures/baby_alive.png"));
				break;
			case Type::Opfer:
				_object->setTexture(*TexturePool::GetInstance()->GetTexture("assets/textures/Opfer_puppet_Komplett_liegend.png"));
				break;
			case Type::Pig:
				_object->setTexture(*TexturePool::GetInstance()->GetTexture("assets/textures/pig_alive.png"));
				break;
			case Type::Sheep:
				_object->setTexture(*TexturePool::GetInstance()->GetTexture("assets/textures/sheep_alive.png"));
				break;
		}

		_object->setOrigin(_object->getLocalBounds().width*0.5f, _object->getLocalBounds().height*0.5f);
		_object->setScale(World::GetInstance()->GetScaleFactor(), World::GetInstance()->GetScaleFactor());
		_object->setPosition(World::GetInstance()->GetWindow()->getSize().x*0.5f, 592.0f*World::GetInstance()->GetScaleFactor()-_object->getGlobalBounds().height*0.5f);

		_state = State::Waiting;
	}

	Animal::~Animal()
	{

	}

	void Animal::Kill(bool fuckYeah)
	{
		if(fuckYeah && _type == Type::Baby)
		{
			_isMovingUp = true;
			return;
		}

		if(_state == State::Waiting && _type != Type::Opfer)
		{
			_state = State::Dead;

			_leftHalf = new sf::Sprite();
			_leftHalf->setTexture(*TexturePool::GetInstance()->GetTexture((_type==Type::Baby)?"assets/textures/baby_dead_02.png":(_type==Type::Pig)?"assets/textures/pig_dead_01.png":"assets/textures/sheep_dead_01.png"));
			_leftHalf->setOrigin(_leftHalf->getLocalBounds().width*0.5f, _leftHalf->getLocalBounds().height*0.5f);
			_leftHalf->setScale(World::GetInstance()->GetScaleFactor(), World::GetInstance()->GetScaleFactor());
			_leftHalf->setPosition(_object->getPosition().x-_leftHalf->getGlobalBounds().width*0.5f, _object->getPosition().y);

			_rightHalf = new sf::Sprite();
			_rightHalf->setTexture(*TexturePool::GetInstance()->GetTexture((_type==Type::Baby)?"assets/textures/baby_dead_01.png":(_type==Type::Pig)?"assets/textures/pig_dead_02.png":"assets/textures/sheep_dead_02.png"));
			_rightHalf->setOrigin(_rightHalf->getLocalBounds().width*0.5f, _rightHalf->getLocalBounds().height*0.5f);
			_rightHalf->setScale(World::GetInstance()->GetScaleFactor(), World::GetInstance()->GetScaleFactor());
			_rightHalf->setPosition(_object->getPosition().x+_rightHalf->getGlobalBounds().width*0.5f, _object->getPosition().y);

			delete _object;
			_object = nullptr;

			b2BodyDef bodyDef;
			b2PolygonShape dynamicBox;
			b2FixtureDef fixtureDef;

			bodyDef.type = b2_dynamicBody;
			bodyDef.position.Set(_leftHalf->getPosition().x*World::WORLD_TO_BOX2D, _leftHalf->getPosition().y*World::WORLD_TO_BOX2D);
			_leftHalfBody = World::GetInstance()->GetPhysicsWorld()->CreateBody(&bodyDef);
			dynamicBox.SetAsBox(_leftHalf->getOrigin().x*World::WORLD_TO_BOX2D*0.5f, _leftHalf->getOrigin().y*World::WORLD_TO_BOX2D*0.5f);
			fixtureDef.shape = &dynamicBox;
			fixtureDef.density = 1.0f;
			fixtureDef.friction = 0.3f;
			_leftHalfBody->CreateFixture(&fixtureDef);

			bodyDef.position.Set(_rightHalf->getPosition().x*World::WORLD_TO_BOX2D, _rightHalf->getPosition().y*World::WORLD_TO_BOX2D);
			_rightHalfBody = World::GetInstance()->GetPhysicsWorld()->CreateBody(&bodyDef);
			dynamicBox.SetAsBox(_rightHalf->getOrigin().x*World::WORLD_TO_BOX2D*0.5f, _rightHalf->getOrigin().y*World::WORLD_TO_BOX2D*0.5f);
			fixtureDef.shape = &dynamicBox;
			fixtureDef.density = 1.0f;
			fixtureDef.friction = 0.3f;
			_rightHalfBody->CreateFixture(&fixtureDef);

			_leftHalfBody->ApplyLinearImpulse((_type==Type::Baby)?b2Vec2(-0.6f, -1.5f):b2Vec2(-0.9f, -2.0f), _leftHalfBody->GetWorldCenter(), true);
			_rightHalfBody->ApplyLinearImpulse((_type==Type::Baby)?b2Vec2(0.2f, -0.3f):b2Vec2(0.75f, -1.5f), _rightHalfBody->GetWorldCenter(), true);
		}

		if(_state == State::Waiting && _type == Type::Opfer){
			sf::Vector2f vec = _object->getPosition();
			vec.y-=100;
			new Ragdoll(vec);
			EntityManager::GetInstance()->RemoveEntity(this);
		}
	}

	void Animal::Update(float timeStep)
	{
		if(_leftHalfBody && _leftHalf)
		{
			_leftHalf->setPosition(_leftHalfBody->GetPosition().x/World::WORLD_TO_BOX2D, _leftHalfBody->GetPosition().y/World::WORLD_TO_BOX2D);
			_leftHalf->setRotation(_leftHalfBody->GetAngle()*180.0f/3.14f);
		}

		if(_rightHalfBody && _rightHalf)
		{
			_rightHalf->setPosition(_rightHalfBody->GetPosition().x/World::WORLD_TO_BOX2D, _rightHalfBody->GetPosition().y/World::WORLD_TO_BOX2D);
			_rightHalf->setRotation(_rightHalfBody->GetAngle()*180.0f/3.14f);
		}

		if(_isMovingUp)
		{
			_object->move(0.0f, -3.0f);
		}
	}

	void Animal::Draw(sf::RenderWindow *window)
	{
		if(_object)
			window->draw(*_object);

		if(_leftHalf)
			window->draw(*_leftHalf);

		if(_rightHalf)
			window->draw(*_rightHalf);
	}
}
