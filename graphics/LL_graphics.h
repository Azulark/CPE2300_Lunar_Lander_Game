#ifndef LL_GRAPHICS_H
#define LL_GRAPHICS_H

#include "raylib.h"

// Screen dimensions
#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 600

extern float rocket_x;
extern float rocket_y;
extern float rocket_angle;

// Graphics function declarations
void DrawBackground(void);
void DrawTerrain(void);
void DrawRocket(void);
void DrawLandingPad(void);

#endif