#include "raylib.h"
#include "rotation.h"
#include <math.h>


float UpdateRotation(float angle, float speed, float dt)
{
    if (IsKeyDown(KEY_A)) {
        angle -= speed * dt;
    }

    if (IsKeyDown(KEY_D)) {
        angle += speed * dt;
    }
    
    // limits the rotations to +- 90 degrees, remove the two if statements
    // if that is undesired.
    if (angle > 90.0f) {
    angle = 90.0f;
    }

    if (angle < -90.0f) {
        angle = -90.0f;
    }

    return angle;
}

Vector2 RotatePoint(Vector2 point, Vector2 center, float angle)
{
    float radians = angle * DEG2RAD;
    float cosine = cosf(radians);
    float sine = sinf(radians);

    Vector2 result;

    result.x = point.x * cosine - point.y * sine;
    result.y = point.x * sine + point.y * cosine;

    result.x += center.x;
    result.y += center.y;

    return result;
}