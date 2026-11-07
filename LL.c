//CPE2300 - Project
//Project Name: Lunar Lander
//Team Name: Argonauts
//Team Members: Thomas Nguyen, William Reddekopp, Aiden Spadey

#include "raylib.h"

// screen size
#define SCREEN_WIDTH 1000       
#define SCREEN_HEIGHT 600

float rocket_x = 300;
float rocket_y = 200;

// background
void DrawBackground(void) {
    ClearBackground(BLACK);
    DrawRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, BLACK);
    DrawText("Lunar Lander", 400, 50, 40, WHITE);
//draw Stars
    DrawCircle (100, 80, 2, WHITE);
    DrawCircle (250, 150, 2, WHITE);
    DrawCircle (450, 60, 2, WHITE);
    DrawCircle (700, 120, 2, WHITE);
    DrawCircle (800, 200, 2, WHITE);
    DrawCircle (550, 300, 2, WHITE);
}

// terrain
void DrawTerrain(void) {
    DrawLineEx((Vector2){0, 480}, (Vector2){200, 450}, 4, LIGHTGRAY);
    DrawLineEx((Vector2){200, 450}, (Vector2){400, 490}, 4, LIGHTGRAY);
    DrawLineEx((Vector2){400, 490}, (Vector2){600, 470}, 4, LIGHTGRAY);
    DrawLineEx((Vector2){600, 470}, (Vector2){800, 470}, 4, LIGHTGRAY);
    DrawLineEx((Vector2){800, 470}, (Vector2){1000, 500}, 4, LIGHTGRAY);
}

// rocket
void DrawRocket(void)
{
    // Main rocket body
    DrawRectangle(rocket_x - 15, rocket_y - 30, 30, 50, WHITE);

    // Left landing leg
    DrawLine(rocket_x - 15, rocket_y + 15, rocket_x - 30, rocket_y + 35, WHITE);

    // Right landing leg
    DrawLine(rocket_x + 15, rocket_y + 15, rocket_x + 30, rocket_y + 35, WHITE);

    // Landing feet
    DrawLine(rocket_x - 35, rocket_y + 35, rocket_x - 25, rocket_y + 35, WHITE);

    DrawLine(rocket_x + 25, rocket_y + 35, rocket_x + 35, rocket_y + 35, WHITE);
}

// landing pad
void DrawLandingPad(void)
{
    // Landing platform
    DrawRectangle(650, 465, 120, 8, GREEN);

    // Support markings
    DrawLine(680, 473, 680, 485, GREEN);
    DrawLine(740, 473, 740, 485, GREEN);
}

// main game loop
int main(void) {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Lunar Lander");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        DrawBackground();
        DrawTerrain();
        DrawRocket();
        DrawLandingPad();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}