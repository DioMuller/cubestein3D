#pragma once
#include <string>
#include <vector>

#define SFXId int

class AudioPlayer
{
	////////////////////////////////////////
	// Static Methods
	////////////////////////////////////////
	private:
		void* currentSong;
		std::vector<void*> soundBank;
		std::vector<std::string> loadedSounds;

	////////////////////////////////////////
	// Constructor / Destructor
	////////////////////////////////////////
	public:
		AudioPlayer();
		~AudioPlayer();

	////////////////////////////////////////
	// Static Methods
	////////////////////////////////////////
	public:
		// Initialization
		void Initialize();

		// Music methods
		void PlaySong(std::string song);
		void StopSong();

		// SFX methods
		SFXId LoadSFX(std::string file);
		void PlaySFX(SFXId audio);
};

