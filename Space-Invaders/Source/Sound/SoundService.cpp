#include "../../Header/Sound/SoundService.h"
#include "../../Header/Global/Config.h"

namespace Sound
{
	using namespace Global;
	void SoundService::Initialize()
	{
		LoadBackgroundMusicFromFile();
		LoadSoundFromFile();
	}

	void SoundService::LoadBackgroundMusicFromFile()
	{
		if (!backgroundMusic.openFromFile(Config::background_music_path))
		{
			printf("Error Loading Background Music");
		}
	}

	void SoundService::LoadSoundFromFile()
	{
		if (!bufferButtonClick.loadFromFile(Config::button_click_sound_path))
		{
			printf("Error Loading Sound Effect");

		}
	}

	void SoundService::PlayBackgroundMusic()
	{
		backgroundMusic.setLoop(true);
		backgroundMusic.setVolume(backgroundMusicvolume);
		backgroundMusic.play();
	}

	void SoundService::PlaySound(SoundType soundType)
	{
		switch (soundType)
		{
		case SoundType::BUTTON_CLICK:
			soundEffect.setBuffer(bufferButtonClick);
			break;
		default:
			printf("Invalid Sound");

		}
		soundEffect.play();
	}




}