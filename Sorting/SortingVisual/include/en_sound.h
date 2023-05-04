#pragma once
#include "en_def.h"

namespace GLEngine
{
	class Sound
	{
	private:
		int _channelKey = -1;
		int _soundKey = -1;
		void* _soundData = nullptr;
		const char* _path = nullptr;

	public:
		export Sound();
		export Sound(const char* path, int soundKey, int channelKey);

	public:
		export void Load(const char* path, int soundKey, int channel);
		export int GetChannelKey();
		export int GetSoundKey();

	public:
		void* GetSoundData();
	};
}