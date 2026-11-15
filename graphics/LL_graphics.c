//CPE2300 - Project
//Project Name: Lunar Lander
//Team Name: Argonauts
//Team Members: Thomas Nguyen, William Reddekopp, Aiden Spadey

#include "raylib.h"
#include "LL_graphics.h"
#include "../rotations/rotation.h"


// Background
void DrawBackground(void)
{
    ClearBackground(BLACK);

    DrawRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, BLACK);
    DrawText("Lunar Lander", 400, 50, 40, WHITE);

    // Draw stars
    DrawCircle(100, 80, 2, WHITE);
    DrawCircle(250, 150, 2, WHITE);
    DrawCircle(450, 200, 2, WHITE);
    DrawCircle(700, 120, 2, WHITE);
    DrawCircle(800, 200, 2, WHITE);
    DrawCircle(550, 300, 2, WHITE);
}


// Terrain
void DrawTerrain(void)
{
    DrawLineEx((Vector2){0, 480}, (Vector2){200, 450}, 4, LIGHTGRAY);
    DrawLineEx((Vector2){200, 450}, (Vector2){400, 490}, 4, LIGHTGRAY);
    DrawLineEx((Vector2){400, 490}, (Vector2){600, 470}, 4, LIGHTGRAY);
    DrawLineEx((Vector2){600, 470}, (Vector2){800, 470}, 4, LIGHTGRAY);
    DrawLineEx((Vector2){800, 470}, (Vector2){1000, 500}, 4, LIGHTGRAY);
}


void DrawRocket(void)
{
    // Actual center of the original rocket body
    Vector2 center = {rocket_x, rocket_y - 5};

    // Left landing leg
    Vector2 leftLegStart =
        RotatePoint((Vector2){-15, 20}, center, rocket_angle);

    Vector2 leftLegEnd =
        RotatePoint((Vector2){-30, 40}, center, rocket_angle);

    // Right landing leg
    Vector2 rightLegStart =
        RotatePoint((Vector2){15, 20}, center, rocket_angle);

    Vector2 rightLegEnd =
        RotatePoint((Vector2){30, 40}, center, rocket_angle);

    // Left landing foot
    Vector2 leftFootStart =
        RotatePoint((Vector2){-35, 40}, center, rocket_angle);

    Vector2 leftFootEnd =
        RotatePoint((Vector2){-25, 40}, center, rocket_angle);

    // Right landing foot
    Vector2 rightFootStart =
        RotatePoint((Vector2){25, 40}, center, rocket_angle);

    Vector2 rightFootEnd =
        RotatePoint((Vector2){35, 40}, center, rocket_angle);

    // Draw landing gear first
    DrawLineV(leftLegStart, leftLegEnd, WHITE);
    DrawLineV(rightLegStart, rightLegEnd, WHITE);

    DrawLineV(leftFootStart, leftFootEnd, WHITE);
    DrawLineV(rightFootStart, rightFootEnd, WHITE);

    // Draw the solid, rotating rocket body
   // Draw the rocket body
DrawRectanglePro(
    (Rectangle){center.x, center.y, 30, 50},
    (Vector2){15, 25},
    rocket_angle,
    WHITE
);
}


// Landing pad
void DrawLandingPad(void)
{
    DrawRectangle(650, 465, 120, 8, GREEN);

    DrawLine(680, 473, 680, 485, GREEN);
    DrawLine(740, 473, 740, 485, GREEN);
}