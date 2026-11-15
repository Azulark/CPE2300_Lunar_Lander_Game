//CPE2300 - Project
//Project Name: Lunar Lander
//Team Name: Argonauts
//Team Members: Thomas Nguyen, William Reddekopp, Aiden Spady

#include "raylib.h"
#include "rotation.h"

// screen size
#define SCREEN_WIDTH 1000       
#define SCREEN_HEIGHT 600

float rocket_x = 300;
float rocket_y = 200;
float rocket_angle = 0.0f;
float rotation_speed = 90.0f;

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
    Vector2 center = {rocket_x, rocket_y};

    Vector2 left_leg_start = RotatePoint(
        (Vector2){-15, 15}, center, rocket_angle
    );

    Vector2 left_leg_end = RotatePoint(
        (Vector2){-30, 35}, center, rocket_angle
    );

    Vector2 right_leg_start = RotatePoint(
    (Vector2){15, 15}, center, rocket_angle
    );

    Vector2 right_leg_end = RotatePoint(
        (Vector2){30, 35}, center, rocket_angle
    );

    Vector2 left_foot_start = RotatePoint(
        (Vector2){-35, 35}, center, rocket_angle
    );
    Vector2 left_foot_end = RotatePoint(
        (Vector2){-25, 35}, center, rocket_angle
    );

    Vector2 right_foot_start = RotatePoint(
        (Vector2){25, 35}, center, rocket_angle
    );
    Vector2 right_foot_end = RotatePoint(
        (Vector2){35, 35}, center, rocket_angle
    );

    // Main rocket body
    DrawRectanglePro(
    (Rectangle){rocket_x, rocket_y, 30, 50},
    (Vector2){15, 30},
    rocket_angle,
    WHITE
    );

    // Left landing leg
    DrawLineV(left_leg_start, left_leg_end, WHITE);

    // Right landing leg
    DrawLineV(right_leg_start, right_leg_end, WHITE);

    // Landing feet
    DrawLineV(left_foot_start, left_foot_end, WHITE);

    DrawLineV(right_foot_start, right_foot_end, WHITE);
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
        rocket_angle = UpdateRotation(rocket_angle, rotation_speed, GetFrameTime());
        BeginDrawing();
        DrawBackground();
        DrawTerrain();
        DrawRocket();
        DrawLandingPad();
        DrawText(TextFormat("Angle: %.1f", rocket_angle), 20, 20, 20, YELLOW);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}