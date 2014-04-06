#ifndef __PARAMETERS_H__
#define __PARAMETERS_H__

#include "Definitions.h"
#include "Vector.h"

// Log Verbose Level
#define VERBOSE_LEVEL LOG_ALL

// Main Character Speed
#define CHARACTER_SPEED 0.01f

// Enemy Speed
#define ENEMY_SPEED 0.005f

// Level Scale
#define SCALE 4

// Collision error vector
#define COLLISION_ERROR Vector(0.9f, 0, 0.9f)

// Screen Width
#define SCREEN_WIDTH 800

// Screen Height
#define SCREEN_HEIGHT 600

// Screen Bytes Per Pixel
#define SCREEN_BPP 32

#endif