//
// Created by gclmini-06 on 07.11.2015.
//

#ifndef PROJECT_SACRIFICE_SOUNDPOOL_H
#define PROJECT_SACRIFICE_SOUNDPOOL_H
#include "World.h"
#include <map>

namespace PS
{
	class SoundPool
	{
		map<std::string,sf::SoundBuffer*> soundMap;

	public:
		SoundPool();
		~SoundPool();

		void LoadSound(std::string sound);
		sf::SoundBuffer *GetSound(std::string sound);

		static SoundPool *_instance;

		static SoundPool *GetInstance();

		sf::SoundBuffer *PlaySplat();
		sf::SoundBuffer *PlayStab();
		void PlayStabFail();
	};
}

#endif //PROJECT_SACRIFICE_SOUNDPOOL_H
