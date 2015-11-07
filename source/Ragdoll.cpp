//
// Created by gclmini-06 on 07.11.2015.
//

#include "Ragdoll.h"
#include <iostream>

namespace PS
{
	Ragdoll::Ragdoll(){

		float density=1.0f;
		float friction = 0.7f;

		position.x = rand() % World::GetInstance()->GetWindow()->getSize().x;
		position.y = rand() % 100;

		_shape_torso = new sf::RectangleShape();
		_shape_torso->setSize(sf::Vector2f(10.0f, 35.0f));
		_shape_torso->setOrigin(_shape_torso->getSize()/2.0f);
		_shape_torso->setFillColor(sf::Color::Blue);

		_shape_head = new sf::RectangleShape();
		_shape_head->setSize(sf::Vector2f(8.0f, 10.0f));
		_shape_head->setOrigin(_shape_head->getSize()/2.0f);
		_shape_head->setFillColor(sf::Color::Red);

		_shape_arm_left = new sf::RectangleShape();
		_shape_arm_left->setSize(sf::Vector2f(3.0f, 16.0f));
		_shape_arm_left->setOrigin(_shape_arm_left->getSize()/2.0f);
		_shape_arm_left->setFillColor(sf::Color::Yellow);
		_shape_arm_left2 = new sf::RectangleShape();
		_shape_arm_left2->setSize(sf::Vector2f(3.0f, 16.0f));
		_shape_arm_left2->setOrigin(_shape_arm_left2->getSize()/2.0f);
		_shape_arm_left2->setFillColor(sf::Color::Yellow);


		_shape_arm_right = new sf::RectangleShape();
		_shape_arm_right->setSize(sf::Vector2f(3.0f, 16.0f));
		_shape_arm_right->setOrigin(_shape_arm_right->getSize()/2.0f);
		_shape_arm_right->setFillColor(sf::Color::Cyan);
		_shape_arm_right2 = new sf::RectangleShape();
		_shape_arm_right2->setSize(sf::Vector2f(3.0f, 16.0f));
		_shape_arm_right2->setOrigin(_shape_arm_right2->getSize()/2.0f);
		_shape_arm_right2->setFillColor(sf::Color::Cyan);

		_shape_leg_left = new sf::RectangleShape();
		_shape_leg_left->setSize(sf::Vector2f(3.0f, 20.0f));
		_shape_leg_left->setOrigin(_shape_leg_left->getSize()/2.0f);
		_shape_leg_left->setFillColor(sf::Color::Magenta);
		_shape_leg_left2 = new sf::RectangleShape();
		_shape_leg_left2->setSize(sf::Vector2f(3.0f, 20.0f));
		_shape_leg_left2->setOrigin(_shape_leg_left2->getSize()/2.0f);
		_shape_leg_left2->setFillColor(sf::Color::Magenta);

		_shape_leg_right = new sf::RectangleShape();
		_shape_leg_right->setSize(sf::Vector2f(3.0f, 20.0f));
		_shape_leg_right->setOrigin(_shape_leg_right->getSize()/2.0f);
		_shape_leg_right->setFillColor(sf::Color::Green);
		_shape_leg_right2 = new sf::RectangleShape();
		_shape_leg_right2->setSize(sf::Vector2f(3.0f, 20.0f));
		_shape_leg_right2->setOrigin(_shape_leg_right2->getSize()/2.0f);
		_shape_leg_right2->setFillColor(sf::Color::Green);


//b2d torso
		_bodyDef_torso.type = b2_dynamicBody;
		_bodyDef_torso.position.Set(
				position.x*World::WORLD_TO_BOX2D,
				position.y*World::WORLD_TO_BOX2D);
		_body_torso = World::GetInstance()->GetPhysicsWorld()->CreateBody(&_bodyDef_torso);
		b2PolygonShape dynamicBox;
		dynamicBox.SetAsBox((_shape_torso->getSize().x/2.0f)*World::WORLD_TO_BOX2D, (_shape_torso->getSize().y/2.0f)*World::WORLD_TO_BOX2D);
		b2FixtureDef fixtureDef;
		fixtureDef.shape = &dynamicBox;
		fixtureDef.density = density*2.f;
		fixtureDef.friction = friction;
		_body_torso->CreateFixture(&fixtureDef);

	//b2d head
		_bodyDef_head.type = b2_dynamicBody;
		_bodyDef_head.position.Set(
				position.x*World::WORLD_TO_BOX2D,
				(position.y+_shape_head->getSize().y)*World::WORLD_TO_BOX2D);
		_body_head = World::GetInstance()->GetPhysicsWorld()->CreateBody(&_bodyDef_head);
		//b2PolygonShape dynamicBox2;
		dynamicBox.SetAsBox((_shape_head->getSize().x/2.0f)*World::WORLD_TO_BOX2D, (_shape_head->getSize().y/2.0f)*World::WORLD_TO_BOX2D);
		//b2FixtureDef fixtureDefhead;
		fixtureDef.shape = &dynamicBox;
		fixtureDef.density = density;
		fixtureDef.friction = friction;
		_body_head->CreateFixture(&fixtureDef);

		//b2d arm
		_bodyDef_arm_left.type = b2_dynamicBody;
		_bodyDef_arm_left.position.Set(
				(position.x+_shape_torso->getSize().x/2.0f)*World::WORLD_TO_BOX2D,
				position.y*World::WORLD_TO_BOX2D);
		_body_arm_left = World::GetInstance()->GetPhysicsWorld()->CreateBody(&_bodyDef_arm_left);
		//b2PolygonShape dynamicBox2;
		dynamicBox.SetAsBox((_shape_arm_left->getSize().x/2.0f)*World::WORLD_TO_BOX2D, (_shape_arm_left->getSize().y/2.0f)*World::WORLD_TO_BOX2D);
		//b2FixtureDef fixtureDefhead;
		fixtureDef.shape = &dynamicBox;
		fixtureDef.density = density;
		fixtureDef.friction = friction;
		_body_arm_left->CreateFixture(&fixtureDef);
//b2d arm left2
		_bodyDef_arm_left2.type = b2_dynamicBody;
		_bodyDef_arm_left2.position.Set(
				_bodyDef_arm_left.position.x,
				_bodyDef_arm_left.position.y*4
		);
		_body_arm_left2 = World::GetInstance()->GetPhysicsWorld()->CreateBody(&_bodyDef_arm_left2);
		//b2PolygonShape dynamicBox2;
		dynamicBox.SetAsBox((_shape_arm_left2->getSize().x/2.0f)*World::WORLD_TO_BOX2D, (_shape_arm_left2->getSize().y/2.0f)*World::WORLD_TO_BOX2D);
		//b2FixtureDef fixtureDefhead;
		fixtureDef.shape = &dynamicBox;
		fixtureDef.density = density;
		fixtureDef.friction = friction;
		_body_arm_left2->CreateFixture(&fixtureDef);


		//b2d arm right
		_bodyDef_arm_right.type = b2_dynamicBody;
		_bodyDef_arm_right.position.Set(
				(position.x-_shape_torso->getSize().x/2.0f)*World::WORLD_TO_BOX2D,
				position.y*World::WORLD_TO_BOX2D);
		_body_arm_right = World::GetInstance()->GetPhysicsWorld()->CreateBody(&_bodyDef_arm_right);
		//b2PolygonShape dynamicBox2;
		dynamicBox.SetAsBox((_shape_arm_right->getSize().x/2.0f)*World::WORLD_TO_BOX2D, (_shape_arm_right->getSize().y/2.0f)*World::WORLD_TO_BOX2D);
		//b2FixtureDef fixtureDefhead;
		fixtureDef.shape = &dynamicBox;
		fixtureDef.density = density;
		fixtureDef.friction = friction;
		_body_arm_right->CreateFixture(&fixtureDef);



		//b2d arm right2
		_bodyDef_arm_right2.type = b2_dynamicBody;
		_bodyDef_arm_right2.position.Set(
				_bodyDef_arm_right.position.x,
				_bodyDef_arm_right.position.y*4
		);
		_body_arm_right2 = World::GetInstance()->GetPhysicsWorld()->CreateBody(&_bodyDef_arm_right2);
		//b2PolygonShape dynamicBox2;
		dynamicBox.SetAsBox((_shape_arm_right2->getSize().x/2.0f)*World::WORLD_TO_BOX2D, (_shape_arm_right2->getSize().y/2.0f)*World::WORLD_TO_BOX2D);
		//b2FixtureDef fixtureDefhead;
		fixtureDef.shape = &dynamicBox;
		fixtureDef.density = density;
		fixtureDef.friction = friction;
		_body_arm_right2->CreateFixture(&fixtureDef);

		// b2d leg left
		_bodyDef_leg_left.type = b2_dynamicBody;
		_bodyDef_leg_left.position.Set(
				(position.x+_shape_torso->getSize().x/2.0f)*World::WORLD_TO_BOX2D,
				(position.y+_shape_leg_left->getSize().y)*World::WORLD_TO_BOX2D);
		_body_leg_left = World::GetInstance()->GetPhysicsWorld()->CreateBody(&_bodyDef_leg_left);
		//b2PolygonShape dynamicBox2;
		dynamicBox.SetAsBox((_shape_leg_left->getSize().x/2.0f)*World::WORLD_TO_BOX2D, (_shape_leg_left->getSize().y/2.0f)*World::WORLD_TO_BOX2D);
		//b2FixtureDef fixtureDefhead;
		fixtureDef.shape = &dynamicBox;
		fixtureDef.density = density;
		fixtureDef.friction = friction;
		_body_leg_left->CreateFixture(&fixtureDef);


		// b2d leg left2
		_bodyDef_leg_left2.type = b2_dynamicBody;
		_bodyDef_leg_left2.position.Set(
				_bodyDef_leg_left.position.x,
				_bodyDef_leg_left.position.y*4//(_shape_leg_left2->getSize().y*World::WORLD_TO_BOX2D)
		);
		_body_leg_left2 = World::GetInstance()->GetPhysicsWorld()->CreateBody(&_bodyDef_leg_left2);
		//b2PolygonShape dynamicBox2;
		dynamicBox.SetAsBox((_shape_leg_left2->getSize().x/2.0f)*World::WORLD_TO_BOX2D, (_shape_leg_left2->getSize().y/2.0f)*World::WORLD_TO_BOX2D);
		//b2FixtureDef fixtureDefhead;
		fixtureDef.shape = &dynamicBox;
		fixtureDef.density = density;
		fixtureDef.friction = friction;
		_body_leg_left2->CreateFixture(&fixtureDef);


		//b2d leg right
		_bodyDef_leg_right.type = b2_dynamicBody;
		_bodyDef_leg_right.position.Set(
				(position.x-_shape_torso->getSize().x/2.0f)*World::WORLD_TO_BOX2D,
				(position.y+_shape_leg_right->getSize().y)*World::WORLD_TO_BOX2D);
		_body_leg_right = World::GetInstance()->GetPhysicsWorld()->CreateBody(&_bodyDef_leg_right);
		//b2PolygonShape dynamicBox2;
		dynamicBox.SetAsBox((_shape_leg_right->getSize().x/2.0f)*World::WORLD_TO_BOX2D, (_shape_leg_right->getSize().y/2.0f)*World::WORLD_TO_BOX2D);
		//b2FixtureDef fixtureDefhead;
		fixtureDef.shape = &dynamicBox;
		fixtureDef.density = density;
		fixtureDef.friction = friction;
		_body_leg_right->CreateFixture(&fixtureDef);
		//b2d leg right2
		_bodyDef_leg_right2.type = b2_dynamicBody;
		_bodyDef_leg_right2.position.Set(
				_bodyDef_leg_right.position.x,
				_bodyDef_leg_right.position.y*4
		);
		_body_leg_right2 = World::GetInstance()->GetPhysicsWorld()->CreateBody(&_bodyDef_leg_right2);
		//b2PolygonShape dynamicBox2;
		dynamicBox.SetAsBox((_shape_leg_right2->getSize().x/2.0f)*World::WORLD_TO_BOX2D, (_shape_leg_right2->getSize().y/2.0f)*World::WORLD_TO_BOX2D);
		//b2FixtureDef fixtureDefhead;
		fixtureDef.shape = &dynamicBox;
		fixtureDef.density = density;
		fixtureDef.friction = friction;
		_body_leg_right2->CreateFixture(&fixtureDef);



		//joints
		//////////////////////////////
		b2RevoluteJointDef headJointDef = getDefGetJointDef(_body_torso,_body_head,0,-_shape_torso->getSize().y/2,0,_shape_head->getSize().y/2.0f);
		_head_joint = (b2RevoluteJoint*) World::GetInstance()->GetPhysicsWorld()->CreateJoint(&headJointDef);

		b2RevoluteJointDef armLeftJointDef = getDefGetJointDef(_body_torso,_body_arm_left,-_shape_torso->getSize().x/2.0f,-_shape_torso->getSize().y/2,-_shape_arm_left->getSize().x/2.0f,-_shape_arm_left->getSize().y/2.0f);
		_arm_left_joint = (b2RevoluteJoint*) World::GetInstance()->GetPhysicsWorld()->CreateJoint(&armLeftJointDef);

		b2RevoluteJointDef armRightJointDef = getDefGetJointDef(_body_torso,_body_arm_right,_shape_torso->getSize().x/2.0f,-_shape_torso->getSize().y/2,_shape_arm_right->getSize().x/2.0f,-_shape_arm_right->getSize().y/2.0f);
		_arm_right_joint = (b2RevoluteJoint*) World::GetInstance()->GetPhysicsWorld()->CreateJoint(&armRightJointDef);

		b2RevoluteJointDef legLeftJointDef = getDefGetJointDef(_body_torso,_body_leg_left,-_shape_torso->getSize().x/2.0f+_shape_leg_left->getSize().x/2.f,_shape_torso->getSize().y/2,-_shape_leg_left->getSize().x/2.0f,_shape_leg_left->getSize().y/2.0f);
		_leg_left_joint = (b2RevoluteJoint*) World::GetInstance()->GetPhysicsWorld()->CreateJoint(&legLeftJointDef);

		b2RevoluteJointDef legRightJointDef = getDefGetJointDef(_body_torso,_body_leg_right,_shape_torso->getSize().x/2.0f-_shape_leg_left->getSize().x/2.f,_shape_torso->getSize().y/2,_shape_leg_right->getSize().x/2.0f,_shape_leg_right->getSize().y/2.0f);
		_leg_right_joint = (b2RevoluteJoint*) World::GetInstance()->GetPhysicsWorld()->CreateJoint(&legRightJointDef);




		b2RevoluteJointDef armleft2JointDef = getDefGetJointDef(_body_arm_left,_body_arm_left2,-_shape_arm_left->getSize().x/2.0f,_shape_arm_left->getSize().y/2,-_shape_arm_left2->getSize().x/2.0f,-_shape_arm_left2->getSize().y/2.0f);
		_arm_left2_joint = (b2RevoluteJoint*) World::GetInstance()->GetPhysicsWorld()->CreateJoint(&armleft2JointDef);

		b2RevoluteJointDef armright2JointDef = getDefGetJointDef(_body_arm_right,_body_arm_right2,_shape_arm_right->getSize().x/2.0f,_shape_arm_right->getSize().y/2,_shape_arm_right2->getSize().x/2.0f,-_shape_arm_right2->getSize().y/2.0f);
		_arm_right2_joint = (b2RevoluteJoint*) World::GetInstance()->GetPhysicsWorld()->CreateJoint(&armright2JointDef);

		b2RevoluteJointDef legleft2JointDef = getDefGetJointDef(_body_leg_left,_body_leg_left2,-_shape_leg_left->getSize().x/2.0f+_shape_leg_left2->getSize().x/2.f,-_shape_leg_left->getSize().y/2,-_shape_leg_left2->getSize().x/2.0f,_shape_leg_left2->getSize().y/2.0f);
		_leg_left2_joint = (b2RevoluteJoint*) World::GetInstance()->GetPhysicsWorld()->CreateJoint(&legleft2JointDef);

		b2RevoluteJointDef legright2JointDef = getDefGetJointDef(_body_leg_right,_body_leg_right2,_shape_leg_right->getSize().x/2.0f-_shape_leg_left2->getSize().x/2.f,-_shape_leg_right->getSize().y/2,_shape_leg_right2->getSize().x/2.0f,_shape_leg_right2->getSize().y/2.0f);
		_leg_right2_joint = (b2RevoluteJoint*) World::GetInstance()->GetPhysicsWorld()->CreateJoint(&legright2JointDef);


		b2Vec2 forceVec;
		forceVec.Set(-.1f,-.8f);
		_body_torso->ApplyLinearImpulse(forceVec,_body_torso->GetPosition(), true);

	}

	void Ragdoll::GetFixtureDef(b2FixtureDef& fixtureDef,b2PolygonShape& dynamicShape, sf::RectangleShape *shape, float32 density, float32 friction)
	{
		b2PolygonShape dynamicBox;
		dynamicBox.SetAsBox(shape->getSize().x, shape->getSize().y);
		//dynamicBox.SetAsBox(50.0f, 50.0f);


		fixtureDef.shape = &dynamicBox;
		fixtureDef.density = density;
		fixtureDef.friction = friction;
		//return fixtureDef;
	}

	b2RevoluteJointDef Ragdoll::getDefGetJointDef(b2Body *bodyA, b2Body *bodyB, float32 anchorAX, float32 anchorAY, float32 anchorBX, float32 anchorBY) const
	{
		b2RevoluteJointDef revoluteJointDef;
		revoluteJointDef.bodyA = bodyA;
		revoluteJointDef.bodyB = bodyB;
		revoluteJointDef.collideConnected = false;
		revoluteJointDef.localAnchorA.Set(anchorAX*World::WORLD_TO_BOX2D,anchorAY*World::WORLD_TO_BOX2D);//the top right corner of the box
		revoluteJointDef.localAnchorB.Set(anchorBX*World::WORLD_TO_BOX2D,anchorBY*World::WORLD_TO_BOX2D);//center of the circle

		return revoluteJointDef;
	}

	Ragdoll::~Ragdoll()
	{

	}

	void Ragdoll::Update(float timeStep)
	{
		b2Vec2 position = _body_torso->GetPosition();
		float32 angle = _body_torso->GetAngle();
		_shape_torso->setPosition(position.x/World::WORLD_TO_BOX2D, position.y/World::WORLD_TO_BOX2D);
		_shape_torso->setRotation(angle*180/3.14f);

		position = _body_head->GetPosition();
		angle = _body_head->GetAngle();
		_shape_head->setPosition(position.x/World::WORLD_TO_BOX2D, position.y/World::WORLD_TO_BOX2D);
		_shape_head->setRotation(angle*180/3.14f);

		position = _body_arm_left->GetPosition();
		angle = _body_arm_left->GetAngle();
		_shape_arm_left->setPosition(position.x/World::WORLD_TO_BOX2D, position.y/World::WORLD_TO_BOX2D);
		_shape_arm_left->setRotation(angle*180/3.14f);

		position = _body_arm_right->GetPosition();
		angle = _body_arm_right->GetAngle();
		_shape_arm_right->setPosition(position.x/World::WORLD_TO_BOX2D, position.y/World::WORLD_TO_BOX2D);
		_shape_arm_right->setRotation(angle*180/3.14f);

		position = _body_leg_left->GetPosition();
		angle = _body_leg_left->GetAngle();
		_shape_leg_left->setPosition(position.x/World::WORLD_TO_BOX2D, position.y/World::WORLD_TO_BOX2D);
		_shape_leg_left->setRotation(angle*180/3.14f);

		position = _body_leg_right->GetPosition();
		angle = _body_leg_right->GetAngle();
		_shape_leg_right->setPosition(position.x/World::WORLD_TO_BOX2D, position.y/World::WORLD_TO_BOX2D);
		_shape_leg_right->setRotation(angle*180/3.14f);

		position = _body_arm_left2->GetPosition();
		angle = _body_arm_left2->GetAngle();
		_shape_arm_left2->setPosition(position.x/World::WORLD_TO_BOX2D, position.y/World::WORLD_TO_BOX2D);
		_shape_arm_left2->setRotation(angle*180/3.14f);

		position = _body_arm_right2->GetPosition();
		angle = _body_arm_right2->GetAngle();
		_shape_arm_right2->setPosition(position.x/World::WORLD_TO_BOX2D, position.y/World::WORLD_TO_BOX2D);
		_shape_arm_right2->setRotation(angle*180/3.14f);

		position = _body_leg_left2->GetPosition();
		angle = _body_leg_left2->GetAngle();
		_shape_leg_left2->setPosition(position.x/World::WORLD_TO_BOX2D, position.y/World::WORLD_TO_BOX2D);
		_shape_leg_left2->setRotation(angle*180/3.14f);

		position = _body_leg_right2->GetPosition();
		angle = _body_leg_right2->GetAngle();
		_shape_leg_right2->setPosition(position.x/World::WORLD_TO_BOX2D, position.y/World::WORLD_TO_BOX2D);
		_shape_leg_right2->setRotation(angle*180/3.14f);



//		CheckBreakForce(_head_joint,timeStep);
//		CheckBreakForce(_arm_left_joint,timeStep);
//		CheckBreakForce(_arm_right_joint,timeStep);
//		CheckBreakForce(_leg_left_joint,timeStep);
//		CheckBreakForce(_leg_right_joint,timeStep);

	}
	void Ragdoll::CheckBreakForce(b2RevoluteJoint* joint,float timeStep)
	{
		if(joint!=NULL)
		{
//			std::cout << "time: " << timeStep << std::endl;
			reactionForce = joint->GetReactionForce(1 / timeStep);
			float forceModuleSq = reactionForce.LengthSquared();

			if(forceModuleSq > 1)
			{
				World::GetInstance()->GetPhysicsWorld()->DestroyJoint(joint);
			}
		}
	}
	void Ragdoll::Draw(sf::RenderWindow *window)
	{

		window->draw(*_shape_arm_left);
		window->draw(*_shape_arm_left2);
		window->draw(*_shape_leg_left);
		window->draw(*_shape_leg_left2);

		window->draw(*_shape_torso);

		window->draw(*_shape_arm_right);
		window->draw(*_shape_arm_right2);
		window->draw(*_shape_leg_right);
		window->draw(*_shape_leg_right2);

		window->draw(*_shape_head);
	}
}
