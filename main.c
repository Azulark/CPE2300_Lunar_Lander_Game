// CPE2300 - Lunar Lander
// Main game file

#include "raylib.h"
#include "graphics/LL_graphics.h"
#include "rotations/rotation.h"


// Rocket position and orientation
float rocket_x = 300;
float rocket_y = 200;
float rocket_angle = 0.0f;

// Rotation speed
float rotation_speed = 90.0f;


int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Lunar Lander");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        // Update rocket rotation
        rocket_angle = UpdateRotation(
            rocket_angle,
            rotation_speed,
            GetFrameTime()
        );

        BeginDrawing();

        DrawBackground();
        DrawTerrain();
        DrawRocket();
        DrawLandingPad();

        DrawText(
            TextFormat("Angle: %.1f", rocket_angle),
            20, 20, 20, YELLOW
        );

        EndDrawing();
    }

    CloseWindow();

    return 0;
}