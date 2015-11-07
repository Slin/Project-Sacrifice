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
		Ragdoll();
		~Ragdoll();

		sf::Vector2f position;

		void Update();
		void Draw(sf::RenderWindow *window);

	private:
		b2BodyDef _bodyDef_torso;
		b2BodyDef _bodyDef_head;
		b2BodyDef _bodyDef_arm_left;
		b2BodyDef _bodyDef_arm_right;
		b2BodyDef _bodyDef_leg_left;
		b2BodyDef _bodyDef_leg_right;

		b2RevoluteJoint *_head_joint;
		b2RevoluteJoint *_arm_left_joint;
		b2RevoluteJoint *_arm_right_joint;
		b2RevoluteJoint *_leg_left_joint;
		b2RevoluteJoint *_leg_right_joint;

		b2Body *_body_head;
		b2Body *_body_torso;
		b2Body *_body_arm_left;
		b2Body *_body_arm_right;
		b2Body *_body_leg_left;
		b2Body *_body_leg_right;

		sf::RectangleShape *_shape_torso;
		sf::RectangleShape *_shape_head;
		sf::RectangleShape *_shape_arm_left;
		sf::RectangleShape *_shape_arm_right;
		sf::RectangleShape *_shape_leg_left;
		sf::RectangleShape *_shape_leg_right;
		void GetFixtureDef(b2FixtureDef& fixtureDef,b2PolygonShape& dynamicShape, sf::RectangleShape *shape, float32 density, float32 friction);
		b2FixtureDef _fixtureDef;
		b2RevoluteJointDef getDefGetJointDef(b2Body *bodyA, b2Body *bodyB, float32 anchorAX, float32 anchorAY, float32 anchorBX, float32 anchorBY) const;

		b2RevoluteJointDef jointDef;
	};
}

#endif //PROJECT_SACRIFICE_RAGDOLL_H
