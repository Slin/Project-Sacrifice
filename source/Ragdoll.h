//
// Created by gclmini-06 on 07.11.2015.
//

#ifndef PROJECT_SACRIFICE_RAGDOLL_H
#define PROJECT_SACRIFICE_RAGDOLL_H
#include "PhysicsEntity.h"

namespace PS
{
	class Ragdoll : public Entity
	{
	public:
		Ragdoll(sf::Vector2f vec);
		~Ragdoll();

		sf::Vector2f position;

		void Update(float timeStep);
		void Draw(sf::RenderWindow *window);

	private:
		float DEGTORAD = 3.14f/180.f;
		b2Vec2 reactionForce;

		b2BodyDef _bodyDef_torso;
		b2BodyDef _bodyDef_head;
		b2BodyDef _bodyDef_arm_left;
		b2BodyDef _bodyDef_arm_right;
		b2BodyDef _bodyDef_leg_left;
		b2BodyDef _bodyDef_leg_right;
		b2BodyDef _bodyDef_arm_left2;
		b2BodyDef _bodyDef_arm_right2;
		b2BodyDef _bodyDef_leg_left2;
		b2BodyDef _bodyDef_leg_right2;

		b2RevoluteJoint *_head_joint;
		b2RevoluteJoint *_arm_left_joint;
		b2RevoluteJoint *_arm_right_joint;
		b2RevoluteJoint *_leg_left_joint;
		b2RevoluteJoint *_leg_right_joint;
		b2RevoluteJoint *_arm_left2_joint;
		b2RevoluteJoint *_arm_right2_joint;
		b2RevoluteJoint *_leg_left2_joint;
		b2RevoluteJoint *_leg_right2_joint;
		bool headJointDetached=false;
		bool armLJointDetached=false;
		bool armRJointDetached=false;
		bool legLJointDetached=false;
		bool legRJointDetached=false;

		b2Body *_body_head;
		b2Body *_body_torso;
		b2Body *_body_arm_left;
		b2Body *_body_arm_right;
		b2Body *_body_leg_left;
		b2Body *_body_leg_right;
		b2Body *_body_arm_left2;
		b2Body *_body_arm_right2;
		b2Body *_body_leg_left2;
		b2Body *_body_leg_right2;

		sf::Sprite *_shape_torso;
		sf::Sprite *_shape_head;
		sf::Sprite *_shape_arm_left;
		sf::Sprite *_shape_arm_right;
		sf::Sprite *_shape_leg_left;
		sf::Sprite *_shape_leg_right;
		sf::Sprite *_shape_arm_left2;
		sf::Sprite *_shape_arm_right2;
		sf::Sprite *_shape_leg_left2;
		sf::Sprite *_shape_leg_right2;

		void GetFixtureDef(b2FixtureDef& fixtureDef,b2PolygonShape& dynamicShape, sf::Sprite *shape, float32 density, float32 friction);
		b2FixtureDef _fixtureDef;
		b2RevoluteJointDef getDefGetJointDef(b2Body *bodyA, b2Body *bodyB, float32 anchorAX, float32 anchorAY, float32 anchorBX, float32 anchorBY) const;

		b2RevoluteJointDef jointDef;
		bool CheckBreakForce(b2RevoluteJoint* joint,float timeStep);
	};
}

#endif //PROJECT_SACRIFICE_RAGDOLL_H
