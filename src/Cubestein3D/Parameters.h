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
#define SHOT_SPEED 0.1f

// Shot Lifetime
#define SHOT_LIFETIME 1000

// Shot Size
#define SHOT_SIZE 0.5f

// Shot is destroyed if it hits wall?
#define SHOT_DESTROYONWALL false


//////////////////////////////////////////
// Level Parameters
//////////////////////////////////////////

// Level Scale
#define SCALE 4

// Collision error vector
#define COLLISION_ERROR Vector(0.9f, 0, 0.9f)


//////////////////////////////////////////
// GUI
//////////////////////////////////////////

// Border Position
#define BORDER_HEIGHT 50

// Icons default Y value.
#define ICON_Y 8

// Text default Y value.
#define TEXT_Y 15

// Default Icon size
#define ICON_SIZE 32

//Health Icon Position
#define ICON_HEALTH_START Vector(10, ICON_Y + ICON_SIZE, 1)
#define ICON_HEALTH_END Vector(10 + ICON_SIZE, ICON_Y, 1)

// Ammo Icon Position
#define ICON_AMMO_START Vector(100, ICON_Y + ICON_SIZE, 1)
#define ICON_AMMO_END Vector(100 + ICON_SIZE, ICON_Y, 1)

// Kills Icon Position
#define ICON_KILLS_START Vector(200, ICON_Y + ICON_SIZE, 1)
#define ICON_KILLS_END Vector(200 + ICON_SIZE, ICON_Y, 1)

// Points Icon Position
#define ICON_POINTS_START Vector(300, ICON_Y + ICON_SIZE, 1)
#define ICON_POINTS_END Vector(300 + ICON_SIZE, ICON_Y, 1)

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

#endif