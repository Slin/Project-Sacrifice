//
// Created by Nils Daumann on 06.11.15.
//

#ifndef PROJECT_SACRIFICE_ENTITY_H
#define PROJECT_SACRIFICE_ENTITY_H

#include <SFML/Graphics/RectangleShape.hpp>
#include <Box2D/Box2D.h>

namespace PS
{
	class Entity : public sf::RectangleShape
	{
	public:
		Entity();

		void Update();

	private:
		b2BodyDef _bodyDef;
		b2Body *_body;
	};
}


#endif //PROJECT_SACRIFICE_ENTITY_H
