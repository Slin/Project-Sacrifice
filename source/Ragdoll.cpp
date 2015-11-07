//
// Created by gclmini-06 on 07.11.2015.
//

#include "Ragdoll.h"
#include <iostream>

namespace PS
{
	Ragdoll::Ragdoll(){

		float density=1.0f;
		float friction = 0.3f;

		position.x = rand() % World::GetInstance()->GetWindow()->getSize().x/2+100;
		position.y = rand() % 100;

		sf::Vector2f tempVec;

		//_shape_torso = new sf::Sprite();
		_shape_torso = new sf::Sprite();
		_shape_torso->setTexture(*TexturePool::GetInstance()->GetTexture("assets/textures/Opfer_puppet_Koerper.png"),true);
		_shape_torso->setScale(World::GetInstance()->GetScaleFactor(),World::GetInstance()->GetScaleFactor());
		tempVec.x=_shape_torso->getGlobalBounds().width;
		tempVec.y=_shape_torso->getGlobalBounds().height;
		_shape_torso->setOrigin(tempVec/2.0f);

		_shape_head = new sf::Sprite();
		_shape_head->setTexture(*TexturePool::GetInstance()->GetTexture("assets/textures/Opfer_puppet_Head_02.png"),true);
		_shape_head->setScale(World::GetInstance()->GetScaleFactor(),World::GetInstance()->GetScaleFactor());
		tempVec.x=_shape_head->getGlobalBounds().width;
		tempVec.y=_shape_head->getGlobalBounds().height;
		_shape_head->setOrigin(tempVec/2.0f);

		_shape_arm_left = new sf::Sprite();
		_shape_arm_left->setTexture(*TexturePool::GetInstance()->GetTexture("assets/textures/Opfer_puppet_Oberarm.png"),true);
		_shape_arm_left->setScale(World::GetInstance()->GetScaleFactor(),World::GetInstance()->GetScaleFactor());
		tempVec.x=_shape_arm_left->getGlobalBounds().width;
		tempVec.y=_shape_arm_left->getGlobalBounds().height;
		_shape_arm_left->setOrigin(tempVec/2.0f);

		_shape_arm_left2 = new sf::Sprite();
		_shape_arm_left2->setTexture(*TexturePool::GetInstance()->GetTexture("assets/textures/Opfer_puppet_Unterarm.png"),true);
		_shape_arm_left2->setScale(World::GetInstance()->GetScaleFactor(),World::GetInstance()->GetScaleFactor());
		tempVec.x=_shape_arm_left2->getGlobalBounds().width;
		tempVec.y=_shape_arm_left2->getGlobalBounds().height;
		_shape_arm_left2->setOrigin(tempVec/2.0f);


		_shape_arm_right = new sf::Sprite();
		_shape_arm_right->setTexture(*TexturePool::GetInstance()->GetTexture("assets/textures/Opfer_puppet_Oberarm.png"),true);
		_shape_arm_right->setScale(World::GetInstance()->GetScaleFactor(),World::GetInstance()->GetScaleFactor());
		tempVec.x=_shape_arm_right->getGlobalBounds().width;
		tempVec.y=_shape_arm_right->getGlobalBounds().height;
		_shape_arm_right->setOrigin(tempVec/2.0f);
		
		_shape_arm_right2 = new sf::Sprite();
		_shape_arm_right2->setTexture(*TexturePool::GetInstance()->GetTexture("assets/textures/Opfer_puppet_Unterarm.png"),true);
		_shape_arm_right2->setScale(World::GetInstance()->GetScaleFactor(),World::GetInstance()->GetScaleFactor());
		tempVec.x=_shape_arm_right2->getGlobalBounds().width;
		tempVec.y=_shape_arm_right2->getGlobalBounds().height;
		_shape_arm_right2->setOrigin(tempVec/2.0f);

		_shape_leg_left = new sf::Sprite();
		_shape_leg_left->setTexture(*TexturePool::GetInstance()->GetTexture("assets/textures/Opfer_puppet_Oberschenkel.png"),true);
		_shape_leg_left->setScale(World::GetInstance()->GetScaleFactor(),World::GetInstance()->GetScaleFactor());
		tempVec.x=_shape_leg_left->getGlobalBounds().width;
		tempVec.y=_shape_leg_left->getGlobalBounds().height;
		_shape_leg_left->setOrigin(tempVec/2.0f);
		
		_shape_leg_left2 = new sf::Sprite();
		_shape_leg_left2->setTexture(*TexturePool::GetInstance()->GetTexture("assets/textures/Opfer_puppet_Unterschenkel.png"),true);
		_shape_leg_left2->setScale(World::GetInstance()->GetScaleFactor(),World::GetInstance()->GetScaleFactor());
		tempVec.x=_shape_leg_left2->getGlobalBounds().width;
		tempVec.y=_shape_leg_left2->getGlobalBounds().height;
		_shape_leg_left2->setOrigin(tempVec/2.0f);

		_shape_leg_right = new sf::Sprite();
		_shape_leg_right->setTexture(*TexturePool::GetInstance()->GetTexture("assets/textures/Opfer_puppet_Oberschenkel.png"),true);
		_shape_leg_right->setScale(World::GetInstance()->GetScaleFactor(),World::GetInstance()->GetScaleFactor());
		tempVec.x=_shape_leg_right->getGlobalBounds().width;
		tempVec.y=_shape_leg_right->getGlobalBounds().height;
		_shape_leg_right->setOrigin(tempVec/2.0f);
		
		_shape_leg_right2 = new sf::Sprite();
		_shape_leg_right2->setTexture(*TexturePool::GetInstance()->GetTexture("assets/textures/Opfer_puppet_Unterschenkel.png"),true);
		_shape_leg_right2->setScale(World::GetInstance()->GetScaleFactor(),World::GetInstance()->GetScaleFactor());
		tempVec.x=_shape_leg_right2->getGlobalBounds().width;
		tempVec.y=_shape_leg_right2->getGlobalBounds().height;
		_shape_leg_right2->setOrigin(tempVec/2.0f);


//b2d torso
		_bodyDef_torso.type = b2_dynamicBody;
		_bodyDef_torso.position.Set(
				position.x*World::WORLD_TO_BOX2D,
				position.y*World::WORLD_TO_BOX2D);
		_body_torso = World::GetInstance()->GetPhysicsWorld()->CreateBody(&_bodyDef_torso);
		b2PolygonShape dynamicBox;
		dynamicBox.SetAsBox((_shape_torso->getGlobalBounds().width/2.0f)*World::WORLD_TO_BOX2D,
							(_shape_torso->getGlobalBounds().height/2.0f)*World::WORLD_TO_BOX2D);
		b2FixtureDef fixtureDef;
		fixtureDef.shape = &dynamicBox;
		fixtureDef.density = density*2.f;
		fixtureDef.friction = friction;
		_body_torso->CreateFixture(&fixtureDef);

	//b2d head
		_bodyDef_head.type = b2_dynamicBody;
		_bodyDef_head.position.Set(
				position.x*World::WORLD_TO_BOX2D,
				(position.y+_shape_head->getGlobalBounds().height)*World::WORLD_TO_BOX2D);
		_body_head = World::GetInstance()->GetPhysicsWorld()->CreateBody(&_bodyDef_head);
		//b2PolygonShape dynamicBox2;
		dynamicBox.SetAsBox((_shape_head->getGlobalBounds().width/2.0f)*World::WORLD_TO_BOX2D,
							(_shape_head->getGlobalBounds().height/2.0f)*World::WORLD_TO_BOX2D);
		//b2FixtureDef fixtureDefhead;
		fixtureDef.shape = &dynamicBox;
		fixtureDef.density = density*.5f;
		fixtureDef.friction = friction;
		_body_head->CreateFixture(&fixtureDef);

		//b2d arm
		_bodyDef_arm_left.type = b2_dynamicBody;
		_bodyDef_arm_left.position.Set(
				(position.x+_shape_torso->getGlobalBounds().width/2.0f)*World::WORLD_TO_BOX2D,
				position.y*World::WORLD_TO_BOX2D);
		_body_arm_left = World::GetInstance()->GetPhysicsWorld()->CreateBody(&_bodyDef_arm_left);
		//b2PolygonShape dynamicBox2;
		dynamicBox.SetAsBox((_shape_arm_left->getGlobalBounds().width/2.0f)*World::WORLD_TO_BOX2D,
							(_shape_arm_left->getGlobalBounds().height/2.0f)*World::WORLD_TO_BOX2D);
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
		dynamicBox.SetAsBox((_shape_arm_left2->getGlobalBounds().width/2.0f)*World::WORLD_TO_BOX2D,
							(_shape_arm_left2->getGlobalBounds().height/2.0f)*World::WORLD_TO_BOX2D);
		b2FixtureDef fixtureDefhead2;
		fixtureDefhead2.shape = &dynamicBox;
		fixtureDefhead2.density = density;
		fixtureDefhead2.friction = friction;
		fixtureDefhead2.filter.maskBits=0;
		_body_arm_left2->CreateFixture(&fixtureDefhead2);


		//b2d arm right
		_bodyDef_arm_right.type = b2_dynamicBody;
		_bodyDef_arm_right.position.Set(
				(position.x-_shape_torso->getGlobalBounds().width/2.0f)*World::WORLD_TO_BOX2D,
				position.y*World::WORLD_TO_BOX2D);
		_body_arm_right = World::GetInstance()->GetPhysicsWorld()->CreateBody(&_bodyDef_arm_right);
		//b2PolygonShape dynamicBox2;
		dynamicBox.SetAsBox((_shape_arm_right->getGlobalBounds().width/2.0f)*World::WORLD_TO_BOX2D,
							(_shape_arm_right->getGlobalBounds().height/2.0f)*World::WORLD_TO_BOX2D);
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
		dynamicBox.SetAsBox((_shape_arm_right2->getGlobalBounds().width/2.0f)*World::WORLD_TO_BOX2D,
							(_shape_arm_right2->getGlobalBounds().height/2.0f)*World::WORLD_TO_BOX2D);
		//b2FixtureDef fixtureDefhead;
		fixtureDefhead2.shape = &dynamicBox;
		fixtureDefhead2.density = density;
		fixtureDefhead2.friction = friction;
		fixtureDefhead2.filter.maskBits=0;
		_body_arm_right2->CreateFixture(&fixtureDefhead2);

		// b2d leg left
		_bodyDef_leg_left.type = b2_dynamicBody;
		_bodyDef_leg_left.position.Set(
				(position.x+_shape_torso->getGlobalBounds().width/2.0f)*World::WORLD_TO_BOX2D,
				(position.y+_shape_leg_left->getGlobalBounds().height/2.f)*World::WORLD_TO_BOX2D);
		_body_leg_left = World::GetInstance()->GetPhysicsWorld()->CreateBody(&_bodyDef_leg_left);
		//b2PolygonShape dynamicBox2;
		dynamicBox.SetAsBox((_shape_leg_left->getGlobalBounds().width/2.0f)*World::WORLD_TO_BOX2D, (_shape_leg_left->getGlobalBounds().height/2.0f)*World::WORLD_TO_BOX2D);
		//b2FixtureDef fixtureDefhead;
		fixtureDef.shape = &dynamicBox;
		fixtureDef.density = density;
		fixtureDef.friction = friction;
		_body_leg_left->CreateFixture(&fixtureDef);


		// b2d leg left2
		_bodyDef_leg_left2.type = b2_dynamicBody;
		_bodyDef_leg_left2.position.Set(
				_bodyDef_leg_left.position.x,
				_bodyDef_leg_left.position.y*4//(_shape_leg_left2->getGlobalBounds().height*World::WORLD_TO_BOX2D)
		);
		_body_leg_left2 = World::GetInstance()->GetPhysicsWorld()->CreateBody(&_bodyDef_leg_left2);
		//b2PolygonShape dynamicBox2;
		dynamicBox.SetAsBox(
				(_shape_leg_left2->getGlobalBounds().width/2.0f)*World::WORLD_TO_BOX2D,
				(_shape_leg_left2->getGlobalBounds().height/2.0f)*World::WORLD_TO_BOX2D);
		//b2FixtureDef fixtureDefhead;
		fixtureDef.shape = &dynamicBox;
		fixtureDef.density = density;
		fixtureDef.friction = friction;
		_body_leg_left2->CreateFixture(&fixtureDef);


		//b2d leg right
		_bodyDef_leg_right.type = b2_dynamicBody;
		_bodyDef_leg_right.position.Set(
				(position.x-_shape_torso->getGlobalBounds().width/2.0f)*World::WORLD_TO_BOX2D,
				(position.y+_shape_leg_right->getGlobalBounds().height/2)*World::WORLD_TO_BOX2D);
		_body_leg_right = World::GetInstance()->GetPhysicsWorld()->CreateBody(&_bodyDef_leg_right);
		//b2PolygonShape dynamicBox2;
		dynamicBox.SetAsBox((_shape_leg_right->getGlobalBounds().width/2.0f)*World::WORLD_TO_BOX2D, (_shape_leg_right->getGlobalBounds().height/2.0f)*World::WORLD_TO_BOX2D);
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
		dynamicBox.SetAsBox((_shape_leg_right2->getGlobalBounds().width/2.0f)*World::WORLD_TO_BOX2D, (_shape_leg_right2->getGlobalBounds().height/2.0f)*World::WORLD_TO_BOX2D);
		//b2FixtureDef fixtureDefhead;
		fixtureDef.shape = &dynamicBox;
		fixtureDef.density = density;
		fixtureDef.friction = friction;
		_body_leg_right2->CreateFixture(&fixtureDef);



		//joints
		//////////////////////////////
		b2RevoluteJointDef headJointDef = getDefGetJointDef(
				_body_torso,_body_head,
				0,
				-_shape_torso->getGlobalBounds().height/3.f,
				_shape_head->getGlobalBounds().width/6.f,
				_shape_head->getGlobalBounds().height/3.f);
		headJointDef.enableLimit = true;
		headJointDef.lowerAngle = -90 * DEGTORAD;
		headJointDef.upperAngle =  90 * DEGTORAD;
		_head_joint = (b2RevoluteJoint*) World::GetInstance()->GetPhysicsWorld()->CreateJoint(&headJointDef);

		b2RevoluteJointDef armLeftJointDef = getDefGetJointDef(
				_body_torso,_body_arm_left,
				_shape_torso->getGlobalBounds().width/4.f,
				-_shape_torso->getGlobalBounds().height/4.f,
				0,
				-_shape_arm_left->getGlobalBounds().height/3.5f);
		_arm_left_joint = (b2RevoluteJoint*) World::GetInstance()->GetPhysicsWorld()->CreateJoint(&armLeftJointDef);

			b2RevoluteJointDef armleft2JointDef = getDefGetJointDef(
				_body_arm_left,_body_arm_left2,
				0,
				_shape_arm_left->getGlobalBounds().height/2.f,
				_shape_arm_left2->getGlobalBounds().width/4.f,
				-_shape_arm_left2->getGlobalBounds().height/2.3f);
		armleft2JointDef.enableLimit = true;
		armleft2JointDef.lowerAngle = 0 * DEGTORAD;
		armleft2JointDef.upperAngle =  160 * DEGTORAD;
		_arm_left2_joint = (b2RevoluteJoint*) World::GetInstance()->GetPhysicsWorld()->CreateJoint(&armleft2JointDef);

		b2RevoluteJointDef armRightJointDef = getDefGetJointDef(
				_body_torso,_body_arm_right,
				_shape_torso->getGlobalBounds().width/4.f,
				-_shape_torso->getGlobalBounds().height/4.f,
				0,
				-_shape_arm_right->getGlobalBounds().height/3.5f);
		_arm_right_joint = (b2RevoluteJoint*) World::GetInstance()->GetPhysicsWorld()->CreateJoint(&armRightJointDef);

		b2RevoluteJointDef armright2JointDef = getDefGetJointDef(
				_body_arm_right,_body_arm_right2,
				0,
				_shape_arm_right->getGlobalBounds().height/2.f,
				_shape_arm_right2->getGlobalBounds().width/4.f,
				-_shape_arm_right2->getGlobalBounds().height/2.3f);
		armright2JointDef.enableLimit = true;
		armright2JointDef.lowerAngle = 0 * DEGTORAD;
		armright2JointDef.upperAngle =  160 * DEGTORAD;
		_arm_right2_joint = (b2RevoluteJoint*) World::GetInstance()->GetPhysicsWorld()->CreateJoint(&armright2JointDef);



		b2RevoluteJointDef legLeftJointDef = getDefGetJointDef(
				_body_torso,_body_leg_left,
				0,
				_shape_torso->getGlobalBounds().height/2.f,
				0,
				-_shape_leg_left->getGlobalBounds().height/3.0f);
		legLeftJointDef.enableLimit = true;
		legLeftJointDef.lowerAngle = -90 * DEGTORAD;
		legLeftJointDef.upperAngle =  160 * DEGTORAD;
		_leg_left_joint = (b2RevoluteJoint*) World::GetInstance()->GetPhysicsWorld()->CreateJoint(&legLeftJointDef);

		b2RevoluteJointDef legleft2JointDef = getDefGetJointDef(
				_body_leg_left,_body_leg_left2,
				-5*World::GetInstance()->GetScaleFactor(),
				_shape_leg_left->getGlobalBounds().height/2.f  -4*World::GetInstance()->GetScaleFactor(),
				0,
				-_shape_leg_left2->getGlobalBounds().height/2.0f+12*World::GetInstance()->GetScaleFactor());
		legleft2JointDef.enableLimit = true;
		legleft2JointDef.lowerAngle = -90 * DEGTORAD;
		legleft2JointDef.upperAngle =  0 * DEGTORAD;
		_leg_left2_joint = (b2RevoluteJoint*) World::GetInstance()->GetPhysicsWorld()->CreateJoint(&legleft2JointDef);



		b2RevoluteJointDef legRightJointDef = getDefGetJointDef(
				_body_torso,_body_leg_right,
				0,
				_shape_torso->getGlobalBounds().height/2.f,
				0,
				-_shape_leg_right->getGlobalBounds().height/3.0f);
		legRightJointDef.enableLimit = true;
		legRightJointDef.lowerAngle = -90 * DEGTORAD;
		legRightJointDef.upperAngle =  160 * DEGTORAD;
		_leg_right_joint = (b2RevoluteJoint*) World::GetInstance()->GetPhysicsWorld()->CreateJoint(&legRightJointDef);

		b2RevoluteJointDef legright2JointDef = getDefGetJointDef(
				_body_leg_right,_body_leg_right2,
				-5*World::GetInstance()->GetScaleFactor(),
				_shape_leg_right->getGlobalBounds().height/2.f  -4*World::GetInstance()->GetScaleFactor(),
				0,
				-_shape_leg_right2->getGlobalBounds().height/2.0f+12*World::GetInstance()->GetScaleFactor());

		legright2JointDef.enableLimit = true;
		legright2JointDef.lowerAngle = -90 * DEGTORAD;
		legright2JointDef.upperAngle =  0 * DEGTORAD;
		_leg_right2_joint = (b2RevoluteJoint*) World::GetInstance()->GetPhysicsWorld()->CreateJoint(&legright2JointDef);


		b2Vec2 forceVec;
		forceVec.Set(-.1f,-.8f);
		_body_torso->ApplyLinearImpulse(forceVec,_body_torso->GetPosition(), true);

	}

	void Ragdoll::GetFixtureDef(b2FixtureDef& fixtureDef,b2PolygonShape& dynamicShape, sf::Sprite *shape, float32 density, float32 friction)
	{
		b2PolygonShape dynamicBox;
		dynamicBox.SetAsBox(shape->getGlobalBounds().width, shape->getGlobalBounds().height);
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
		World::GetInstance()->GetPhysicsWorld()->DestroyJoint(_head_joint );
		World::GetInstance()->GetPhysicsWorld()->DestroyJoint(_arm_left_joint);
		World::GetInstance()->GetPhysicsWorld()->DestroyJoint(_arm_right_joint);
		World::GetInstance()->GetPhysicsWorld()->DestroyJoint(_leg_left_joint);
		World::GetInstance()->GetPhysicsWorld()->DestroyJoint(_leg_right_joint);
		World::GetInstance()->GetPhysicsWorld()->DestroyJoint(_arm_left2_joint);
		World::GetInstance()->GetPhysicsWorld()->DestroyJoint(_arm_right2_joint);
		World::GetInstance()->GetPhysicsWorld()->DestroyJoint(_leg_left2_joint);
		World::GetInstance()->GetPhysicsWorld()->DestroyJoint(_leg_right2_joint);

		World::GetInstance()->GetPhysicsWorld()->DestroyBody( _body_head );
		World::GetInstance()->GetPhysicsWorld()->DestroyBody( _body_torso );
		World::GetInstance()->GetPhysicsWorld()->DestroyBody( _body_arm_left );
		World::GetInstance()->GetPhysicsWorld()->DestroyBody( _body_arm_right );
		World::GetInstance()->GetPhysicsWorld()->DestroyBody( _body_leg_left );
		World::GetInstance()->GetPhysicsWorld()->DestroyBody( _body_leg_right );
		World::GetInstance()->GetPhysicsWorld()->DestroyBody(  _body_arm_left2);
		World::GetInstance()->GetPhysicsWorld()->DestroyBody( _body_arm_right2 );
		World::GetInstance()->GetPhysicsWorld()->DestroyBody( _body_leg_left2 );
		World::GetInstance()->GetPhysicsWorld()->DestroyBody( _body_leg_right2 );

		delete _head_joint;
		delete _arm_left_joint;
		delete _arm_right_joint;
		delete _leg_left_joint;
		delete _leg_right_joint;
		delete _arm_left2_joint;
		delete _arm_right2_joint;
		delete _leg_left2_joint;
		delete _leg_right2_joint;

		delete _shape_torso;
		delete _shape_head;
		delete _shape_arm_left;
		delete _shape_arm_right;
		delete _shape_leg_left;
		delete _shape_leg_right;
		delete _shape_arm_left2;
		delete _shape_arm_right2;
		delete _shape_leg_left2;
		delete _shape_leg_right2;
		
		
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


		window->draw(*_shape_arm_left2);
		window->draw(*_shape_arm_left);
		window->draw(*_shape_leg_left2);
		window->draw(*_shape_leg_left);
		window->draw(*_shape_head);

		window->draw(*_shape_torso);







		window->draw(*_shape_leg_right2);
		window->draw(*_shape_leg_right);

		window->draw(*_shape_arm_right2);
		window->draw(*_shape_arm_right);

	}
}