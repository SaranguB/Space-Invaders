#pragma once
#include "SFML/Audio.hpp"

namespace Sound
{
	enum class SoundType
	{
		BUTTON_CLICK,
	};
	class SoundService

	{

	private:
		const int backgroundMusicvolume = 30;

		sf::Music backgroundMusic;
		sf::Sound soundEffect;
		sf::SoundBuffer bufferButtonClick;

		void LoadBackgroundMusicFromFile();
		void LoadSoundFromFile();

	public:


		void Initialize();

		void PlayBackgroundMusic();
		void PlaySound(SoundType soundType);
	};
}