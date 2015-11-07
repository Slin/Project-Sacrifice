//
// Created by Nils Daumann on 07.11.15.
//

#include "PhysicsEntity.h"

namespace PS
{
	PhysicsEntity::PhysicsEntity()
	{
		_object = new sf::RectangleShape();
		_object->setSize(sf::Vector2f(50.0f, 50.0f));
		_object->setFillColor(sf::Color::Red);

		_bodyDef.type = b2_dynamicBody;
		_bodyDef.position.Set(0.0f, 4.0f);
		_body = World::GetInstance()->GetPhysicsWorld()->CreateBody(&_bodyDef);

		b2PolygonShape dynamicBox;
		dynamicBox.SetAsBox(50.0f, 50.0f);

		b2FixtureDef fixtureDef;
		fixtureDef.shape = &dynamicBox;
		fixtureDef.density = 1.0f;
		fixtureDef.friction = 0.3f;

		_body->CreateFixture(&fixtureDef);
	}

	PhysicsEntity::~PhysicsEntity()
	{
		World::GetInstance()->GetPhysicsWorld()->DestroyBody(_body);
		delete _object;
	}

	void PhysicsEntity::Update()
	{
		b2Vec2 position = _body->GetPosition();
		float32 angle = _body->GetAngle();
		_object->setPosition(position.x, position.y);
	}

	void PhysicsEntity::Draw(sf::RenderWindow *window)
	{
		window->draw(*_object);
	}
}
