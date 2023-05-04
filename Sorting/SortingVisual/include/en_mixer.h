#pragma once
#include "en_def.h"

namespace GLEngine
{
	struct MixerValues
	{
		float pan;
		float volume;
	};

	class Mixer
	{
	private:
		map<int, MixerValues*> _mixerValues;
		Channel& _channel;
		Sound* soundTarget = nullptr;

	public:
		Mixer(Channel& channel);

	public:
		export void TargetSound(Sound& sound);
		export void TargetAllSounds(Sound& sound);
		export void SetDefault();
		export void SetVolmue(float volmue);
		export void SetPan(float pan);
	};
}

