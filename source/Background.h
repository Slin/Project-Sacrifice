//
// Created by Nils Daumann on 07.11.15.
//

#ifndef PROJECT_SACRIFICE_BACKGROUND_H
#define PROJECT_SACRIFICE_BACKGROUND_H

#include "Entity.h"

namespace PS
{
	class Background : public Entity
	{
	public:
		Background();
		~Background();

		void Update(float timeStep);
		void Draw(sf::RenderWindow *window);
		void DrawLate(sf::RenderWindow *window);

		bool RemoveLife();
		int GetNumberOfLifes();

	private:
		sf::Sprite *_mainBackground;
		sf::Sprite *_altar;

		sf::Sprite *_life1;
		sf::Sprite *_life2;
		sf::Sprite *_life3;
		sf::Sprite *_life4;
	};
}

#endif //PROJECT_SACRIFICE_BACKGROUND_H
