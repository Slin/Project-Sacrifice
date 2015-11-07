//
// Created by Nils Daumann on 07.11.15.
//

#include "PhysicsEntity.h"

namespace PS
{
	PhysicsEntity::PhysicsEntity()
	{
		_object = new sf::RectangleShape();
		_object->setSize(sf::Vector2f(80.0f, 80.0f));
		_object->setOrigin(40.0f, 40.0f);
		_object->setFillColor(sf::Color::Green);

		_bodyDef.type = b2_dynamicBody;
		_bodyDef.position.Set(380.0f*World::WORLD_TO_BOX2D, 0.0f*World::WORLD_TO_BOX2D);
		_body = World::GetInstance()->GetPhysicsWorld()->CreateBody(&_bodyDef);

		b2PolygonShape dynamicBox;
		dynamicBox.SetAsBox(40.0f*World::WORLD_TO_BOX2D, 40.0f*World::WORLD_TO_BOX2D);

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
		_object->setRotation(angle*180.0f/M_PI);
		_object->setPosition(position.x/World::WORLD_TO_BOX2D, position.y/World::WORLD_TO_BOX2D);
	}

	void PhysicsEntity::Draw(sf::RenderWindow *window)
	{
		window->draw(*_object);
	}
}
