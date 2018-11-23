#include <iostream>

#include "Sound.h"

namespace myEngine
{

	struct SoundClip
	{
		ALuint m_id;

		~SoundClip()
		{
			alDeleteBuffers(1, &m_id);
		}

		void SoundClip::loadOggFile(std::string _path, std::vector<char> &_buffer, ALenum &_format, ALsizei &_frequency)
		{

			int endian = 0;
			int bitStream = 0;
			long bytes = 0;
			char array[2048] = { 0 };
			vorbis_info *pInfo = NULL;
			OggVorbis_File oggFile = { 0 };

			// Use the inbuilt fopen to create a file descriptor
			if (ov_fopen(_path.c_str(), &oggFile) != 0)
			{
				std::cout << "Failed to open file '" << _path << "' for decoding" << std::endl;
				throw std::exception();
			}

			// Extract information from the file header
			pInfo = ov_info(&oggFile, -1);

			// Record the format required by OpenAL
			if (pInfo->channels == 1)
			{
				_format = AL_FORMAT_MONO16;
			}
			else
			{
				_format = AL_FORMAT_STEREO16;
			}

			// Record the sample rate required by OpenAL
			_frequency = pInfo->rate;

			// Keep reading bytes from the file to populate the output buffer
			while (true)
			{
				// Read bytes into temporary array
				bytes = ov_read(&oggFile, array, 2048, endian, 2, 1, &bitStream);

				if (bytes < 0)
				{
					ov_clear(&oggFile);
					std::cout << "Failed to decode file '" << _path << "'." << std::endl;
					throw std::exception();
				}
				else if (bytes == 0)
				{
					break;
				}

				// Copy from temporary array into output buffer
				_buffer.insert(_buffer.end(), array, array + bytes);
			}

			// Clean up and close the file
			ov_clear(&oggFile);

		}

	};

	Sound::Sound()
	{

	}
	Sound::~Sound()
	{

	}

	void Sound::loadSoundClip(std::string _path)
	{

		m_clip = std::make_shared<SoundClip>();

		ALenum format = 0;
		ALsizei frequency = 0;
		std::vector<char> bufferData;

		alGenBuffers(1, &(m_clip->m_id));

		m_clip->loadOggFile(_path, bufferData, format, frequency);

		alBufferData(m_clip->m_id, format, &bufferData[0], static_cast<ALsizei>(bufferData.size()), frequency);

	}

	void Sound::play()
	{
		ALuint sid = 0;
		alGenSources(1, &sid);
		alListener3f(AL_POSITION, 0.0f, 0.0f, 0.0f);
		alSource3f(sid, AL_POSITION, 100.0f, 0.0f, 0.0f);
		alSourcei(sid, AL_BUFFER, m_clip->m_id);
		alSourcePlay(sid);

		//audioSources.push_back(sid);
	}

	SoundObject::SoundObject()
	{
		m_device = alcOpenDevice(NULL);

		if (!m_device)
		{
			throw std::exception();
		}

		m_context = alcCreateContext(m_device, NULL);

		if (!m_context)
		{
			alcCloseDevice(m_device);
			throw std::exception();
		}

		if (!alcMakeContextCurrent(m_context))
		{
			alcDestroyContext(m_context);
			alcCloseDevice(m_device);
			throw std::exception();
		}
	}

	SoundObject::~SoundObject()
	{
		alcMakeContextCurrent(NULL);
		alcDestroyContext(m_context);
		alcCloseDevice(m_device);
	}

}