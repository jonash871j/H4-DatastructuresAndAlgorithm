#pragma once
#include "en_def.h"
#include "en_channel.h"

namespace GLEngine
{
	class SoundSystem
	{
	private:
		Window& _window;
		map<int, Channel*> _channels;

	public:
		SoundSystem(Window& window);

	public:
		template<typename Enum>
		void AddChannel(Enum channelKey)
		{
			AddChannel((int)channelKey);
		}
		export void AddChannel(int channelKey);

		//template<typename Enum> 
		/*void PlaySound(Enum soundKey)
		{
			PlaySound(ResourceManager::GetSound((int)soundKey));
		}*/
		export void PlaySound(Sound& sound);

		//template<typename Enum>
		/*void StopSound(Enum soundKey)
		{
			StopSound(ResourceManager::GetSound((int)soundKey));
		}*/
		export void StopSound(Sound& sound);

		template<typename Enum>
		Channel& GetChannel(Enum channelKey)
		{
			return GetChannel((int)channelKey);
		}
		export Channel& GetChannel(int channelKey);
	};
}