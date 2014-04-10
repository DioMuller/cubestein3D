#ifndef __DEFINITIONS_H__
#define __DEFINITIONS_H__

////////////////////////////////////////
// MATH DEFINITIONS
////////////////////////////////////////
#define MIN(a,b) a < b ? a : b
#define MAX(a,b) a > b ? a : b

////////////////////////////////////////
// LOG DEFINITIONS
////////////////////////////////////////
#define LOG_ALL 4
#define LOG_HIGH 3
#define LOG_NORMAL 2
#define LOG_LOW 1
#define LOG_NONE 0

////////////////////////////////////////
// INPUT DEFINITIONS
////////////////////////////////////////
#define Button int

#define BUTTON_NONE -1
#define BUTTON_LEFT 0
#define BUTTON_UP 1
#define BUTTON_RIGHT 2
#define BUTTON_DOWN 3
#define BUTTON_QUIT 4
#define BUTTON_SHOT 5
#define BUTTON_ACTION 6

#define INPUTCOUNT 7

////////////////////////////////////////
// SKYBOX DEFINITIONS
////////////////////////////////////////
#define SKY_BACK 0
#define SKY_FRONT 1
#define SKY_LEFT 2
#define SKY_RIGHT 3
#define SKY_TOP 4
#define SKY_BOTTOM 5

#define GameState int

#define STATE_TITLE 0
#define STATE_HOWTOPLAY 1
#define STATE_PLAYING 2
#define STATE_GAMEOVER 3
#define STATE_FINISHED 4

#endif