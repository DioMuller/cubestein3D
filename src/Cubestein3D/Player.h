#pragma once
#include "Character.h"
#include "AudioPlayer.h"

class Player : Character
{
	////////////////////////////////////////
	// Attributes
	////////////////////////////////////////
	private:
		int health;
		int ammo;
		int kills;
		int points;

	////////////////////////////////////////
	// GUI Textures
	////////////////////////////////////////
	private:
		TextureInfo* guiBorder;
		TextureInfo* guiIconHealth;
		TextureInfo* guiIconAmmo;
		TextureInfo* guiIconKills;
		TextureInfo* guiIconPoints;

	////////////////////////////////////////
	// Sound Effects
	////////////////////////////////////////
	private:
		SFXId sfxShoot;

	////////////////////////////////////////
	// Constructor / Destructor
	////////////////////////////////////////
	public:
		Player(Vector position);
		~Player();

	////////////////////////////////////////
	// Methods
	////////////////////////////////////////
	public:
		void Render(long delta, Renderer* renderer);
		void CollideWith(Entity* other);

		void AddKill();
		bool Shoot();
};

