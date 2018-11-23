#ifndef SOUND_H
#define SOUND_H

#include <memory>
#include <string>

#include <AL/al.h>
#include <AL/alc.h>
#include <vorbis/vorbisfile.h>

#include <vector>

namespace myEngine
{

	struct SoundClip;

	class Sound
	{
	private:

		std::shared_ptr<SoundClip> m_clip;

	public:
		Sound();
		~Sound();

		void loadSoundClip(std::string _path);

		void play();


	};

	class SoundObject
	{

	private:

		ALCdevice* m_device;
		ALCcontext* m_context;

	public:
		SoundObject();
		~SoundObject();

	};

}

#endif // !SOUND_H
