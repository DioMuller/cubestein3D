#include "MusicPlayer.h"
#include "Parameters.h"
#include "Log.h"
#include <SDL\SDL_mixer.h>

void* MusicPlayer::currentSong = nullptr;

void MusicPlayer::Initialize()
{
	// Initialize Audio
	if (Mix_OpenAudio(AUDIO_RATE, AUDIO_S16SYS, AUDIO_CHANNELS, AUDIO_BUFFERS) != 0)
	{
		Log::Error("Unable to initialize audio");
		Log::Error(Mix_GetError());
	}
}

void MusicPlayer::PlaySong(std::string song)
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

void MusicPlayer::StopSong()
{

}