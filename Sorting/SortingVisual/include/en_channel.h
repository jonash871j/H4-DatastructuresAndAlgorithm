#pragma once
#include "en_def.h"

namespace GLEngine
{
	class Channel
	{
	private:
		Mixer* _mixer;
		int _channelKey;
		int _sdlChannelRangeStart;
		int _sdlChannelRangeEnd;
		int _sdlChannelIndex;
		int _pSoundAmount;
		int _pSoundIndex;
		int* _playingSounds;

	public:
		Channel(int channelKey, int sdlChannelRangeStart, int sdlChannelRangeEnd);

	public:
		export void PlaySound(Sound& sound);
		export void StopSound(Sound& sound);
		export void StopAllSounds();
		export Mixer& GetMixer();

	private:
		void UpdateIndexes(Sound& sound);
	};
}
