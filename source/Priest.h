//
// Created by Nils Daumann on 07.11.15.
//

#ifndef PROJECT_SACRIFICE_PRIEST_H
#define PROJECT_SACRIFICE_PRIEST_H

#include "Entity.h"

namespace PS
{
	class Priest : Entity
	{
	public:
		Priest();
		~Priest();

		void Update(float timeStep);
		void Draw(sf::RenderWindow *window);

		void Animate();
		float GetAnimationTimer()
		{
			return _animationTimer;
		}

	private:
		sf::Sprite *_object;
		bool _animate;
		float _animationTimer;
	};
}


#endif //PROJECT_SACRIFICE_PRIEST_H
