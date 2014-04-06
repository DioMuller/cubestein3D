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

//Health Icon Position
#define ICON_HEALTH_START Vector(10, 42, 1)
#define ICON_HEALTH_END Vector(42, 10, 1)

// Health Text Position
#define HEALTH_OFFSET Vector(50, 15, 1)

#endif