#ifndef __PARAMETERS_H__
#define __PARAMETERS_H__

#include "Definitions.h"
#include "Vector.h"

//////////////////////////////////////////
// Drawing
//////////////////////////////////////////

// Screen Width
#define SCREEN_WIDTH 800

// Screen Height
#define SCREEN_HEIGHT 600

// Screen Bytes Per Pixel
#define SCREEN_BPP 32

//////////////////////////////////////////
// Log and Debug
//////////////////////////////////////////

// Log Verbose Level
#define VERBOSE_LEVEL LOG_HIGH

// Show Debug Info
#define SHOWDEBUG true

// Debug info Line offset
#define DEBUG_LINE_OFFSET 40

// Debug Info start point
#define DEBUGPOSITION_X 10
#define DEBUGPOSITION_Y SCREEN_HEIGHT - 15

//////////////////////////////////////////
// Game Parameters
//////////////////////////////////////////

// Main Character Speed
#define CHARACTER_SPEED 0.01f

// Enemy Speed
#define ENEMY_SPEED 0.005f

// Shot Speed
#define SHOT_SPEED 0.03f

// Shot Lifetime
#define SHOT_LIFETIME 800

// Shot Size
#define SHOT_SIZE 0.9f

// Shot is destroyed if it hits wall?
#define SHOT_DESTROYONWALL false

// Enemy attack distance
#define ATTACK_DISTANCE 100.0f

//Enemy damage when hiting the player
#define ENEMY_DAMAGE 1

// How much health a medikit restores.
#define MEDIKIT_RESTORE 30

// How much ammo the 
#define AMMO_RESTORE 20

// Treasure Value
#define TREASURE_VALUE 1000

//////////////////////////////////////////
// Level Parameters
//////////////////////////////////////////

// Level Scale
#define SCALE 4

// Collision error vector
#define COLLISION_ERROR Vector(1.0f, 0, 1.0f)

// Wall Repetitions
#define TEXTURE_WALL_REPETITIONS Vector(2, 1, 0)

// Paiting Repetitions
#define TEXTURE_PAINTING_REPETITIONS Vector(1, 1, 0)

// Character size.
#define CHARACTER_SIZE Vector(0.5f, 1.0f, 0.5f)

// Character Y
#define CHARACTER_Y -0.4f

// Pickup size
#define PICKUP_SIZE Vector(1.0f, 0.5f, 1.0f)

// Pickup position
#define PICKUP_Y -0.8f

// Pickup rotation
#define PICKUP_ROTATION 0.05f

// Player damage SFX Wait Time.
#define DAMAGE_SFX_WAITTIME 1000

// Level finish offset
#define FINISH_OFFSET Vector( -0.5, 1, -0.5 );

//////////////////////////////////////////
// Audio
//////////////////////////////////////////
#define AUDIO_RATE 44100
#define AUDIO_CHANNELS 2
#define AUDIO_BUFFERS 4096

//////////////////////////////////////////
// GUI
//////////////////////////////////////////

// Border Position
#define BORDER_HEIGHT 50

// Icons default Y value.
#define ICON_Y 10

// Text default Y value.
#define TEXT_Y 17

// Default Icon size
#define ICON_SIZE 32

//Health Icon Position
#define ICON_HEALTH_START Vector(15, ICON_Y + ICON_SIZE, 1)
#define ICON_HEALTH_END Vector(15 + ICON_SIZE, ICON_Y, 1)

// Ammo Icon Position
#define ICON_AMMO_START Vector(105, ICON_Y + ICON_SIZE, 1)
#define ICON_AMMO_END Vector(105 + ICON_SIZE, ICON_Y, 1)

// Kills Icon Position
#define ICON_KILLS_START Vector(205, ICON_Y + ICON_SIZE, 1)
#define ICON_KILLS_END Vector(205 + ICON_SIZE, ICON_Y, 1)

// Points Icon Position
#define ICON_POINTS_START Vector(305, ICON_Y + ICON_SIZE, 1)
#define ICON_POINTS_END Vector(305 + ICON_SIZE, ICON_Y, 1)

// Health Text Position
#define HEALTH_OFFSET Vector(50, TEXT_Y, 1)

// Ammo Text Position
#define AMMO_OFFSET Vector(150, TEXT_Y, 1)

// Kills Text Position
#define KILLS_OFFSET Vector(250, TEXT_Y, 1)

// Points Text Position
#define POINTS_OFFSET Vector(350, TEXT_Y, 1)

// Weapon
#define CROSSHAIR_SIZE 5
#define CROSSHAIR_SPACE 3

// Level Name
#define FONT_SIZE 16
#define LEVELNAME_OFFSET Vector(15.0f, TEXT_Y, 1.0f)

// Screen Size
#define SCREEN_START Vector(0,0,0)
#define SCREEN_END Vector(SCREEN_WIDTH, SCREEN_HEIGHT, 0)

#endif