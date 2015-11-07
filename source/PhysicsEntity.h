//
// Created by Nils Daumann on 07.11.15.
//

#ifndef PROJECT_SACRIFICE_PHYSICSENTITY_H
#define PROJECT_SACRIFICE_PHYSICSENTITY_H

#include "Entity.h"

namespace PS
{
	class PhysicsEntity : public Entity
	{
	public:
		PhysicsEntity();
		~PhysicsEntity();

		void Update(float timeStep);
		void Draw(sf::RenderWindow *window);

	private:
		b2BodyDef _bodyDef;
		b2Body *_body;
		sf::RectangleShape *_object;
	};
}


#endif //PROJECT_SACRIFICE_PHYSICSENTITY_H
