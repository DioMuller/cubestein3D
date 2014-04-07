#include "AudioPlayer.h"
#include "Parameters.h"
#include "Log.h"
#include <SDL\SDL_mixer.h>

////////////////////////////////////////
// Constructor / Destructor
////////////////////////////////////////
AudioPlayer::AudioPlayer()
{
	currentSong = nullptr;
	soundBank = std::vector<void*>();
	Initialize();
}

AudioPlayer::~AudioPlayer()
{
	StopSong();
	Mix_CloseAudio();
}

////////////////////////////////////////
// Methods
////////////////////////////////////////
void AudioPlayer::Initialize()
{
	// Initialize Audio
	if (Mix_OpenAudio(AUDIO_RATE, AUDIO_S16SYS, AUDIO_CHANNELS, AUDIO_BUFFERS) != 0)
	{
		Log::Error("Unable to initialize audio");
		Log::Error(Mix_GetError());
	}
}

////////////////////////////////////////
// BGM Methods
////////////////////////////////////////
void AudioPlayer::PlaySong(std::string song)
{
	if (currentSong != nullptr) StopSong();

	currentSong = Mix_LoadMUS(song.c_str());

	if (currentSong == nullptr)
	{
		Log::Error("Unable to load Ogg file.");
		Log::Error(Mix_GetError());
	}

	if (Mix_PlayMusic((Mix_Music*) currentSong, -1) == -1)
	{
		Log::Error("Unable to play Ogg file.");
		Log::Error(Mix_GetError());
	}
}

void AudioPlayer::StopSong()
{
	if (currentSong == nullptr) return;

	Mix_HaltMusic(); 
	Mix_FreeMusic((Mix_Music*)currentSong);
}

////////////////////////////////////////
// SFX Methods
////////////////////////////////////////
SFXId AudioPlayer::LoadSFX(std::string file)
{
	Mix_Chunk* sound = nullptr;

	sound = Mix_LoadWAV(file.c_str());

	if (sound == nullptr)
	{
		Log::Error("Unable to load Wav file.");
		Log::Error(Mix_GetError());

		return -1;
	}
	else
	{
		soundBank.push_back(sound);
		return (soundBank.size() - 1);
	}
}

void AudioPlayer::PlaySFX(SFXId audio)
{
	if (audio == -1) return;

	int channel;

	channel = Mix_PlayChannel(-1, (Mix_Chunk*) soundBank[audio], 0);

	if (channel == -1)
	{
		Log::Error("Unable to play Wav file.");
		Log::Error(Mix_GetError());
	}
}