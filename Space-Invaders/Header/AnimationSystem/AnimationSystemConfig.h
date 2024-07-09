#pragma once
#include <SFML/Graphics.hpp>


namespace Animation
{
	struct AnimationSystemConfig
	{
		sf::String AnimationTexturePath;

		float spriteSheetWidth;
		float spriteSheetHeight;

		float tileWidth;
		float tileHeight;

		int numberOfAnimationFrame;
		float frameDuration;

		AnimationSystemConfig() = default;
		AnimationSystemConfig(sf::String texturePath, float spriteWidth, float spriteHeight,
			float tWidth, float tHeight, int frames, float Duration) :
			AnimationTexturePath(texturePath),
			spriteSheetWidth(spriteWidth),
			spriteSheetHeight(spriteHeight),
			tileWidth(tWidth),
			tileHeight(tHeight),
			numberOfAnimationFrame(frames),
			frameDuration(Duration){}
	};
}
