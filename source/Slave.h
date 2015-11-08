//
// Created by Nils Daumann on 08.11.15.
//

#ifndef PROJECT_SACRIFICE_SLAVE_H
#define PROJECT_SACRIFICE_SLAVE_H

#include "Entity.h"

namespace PS
{
	class Slave : public Entity
	{
	public:
		Slave();
		~Slave();

		void Draw(sf::RenderWindow *window);
		void Update(float timeStep);

	private:
		sf::Sprite *_object;
		sf::Sprite *_object2;
		float _animationTimer;
	};
}


#endif //PROJECT_SACRIFICE_SLAVE_H
