//
// Created by Nils Daumann on 06.11.15.
//

#include "Entity.h"
#include "World.h"
namespace PS
{
	Entity::Entity()
	{
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

	void Entity::Update()
	{
		b2Vec2 position = _body->GetPosition();
		float32 angle = _body->GetAngle();
		setPosition(position.x, position.y);
	}
}
