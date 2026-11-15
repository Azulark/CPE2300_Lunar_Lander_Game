#ifndef ROTATION_H
#define ROTATION_H

#include "raylib.h"

float UpdateRotation(float angle, float speed, float dt);

Vector2 RotatePoint(Vector2 point, Vector2 center, float angle);

#endif