//
// Created by Nils Daumann on 08.11.15.
//

#ifndef PROJECT_SACRIFICE_ENDFELSEN_H
#define PROJECT_SACRIFICE_ENDFELSEN_H

#include "Entity.h"

namespace PS
{
	class EndFelsen : public Entity
	{
	public:
		EndFelsen();
		~EndFelsen();

		void Update(float timeStep);
		void Draw(sf::RenderWindow *window);

	private:
		float _fallSpeed;

		sf::Sprite *_felsen;
	};
}

#endif //PROJECT_SACRIFICE_ENDFELSEN_H
