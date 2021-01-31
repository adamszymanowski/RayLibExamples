#include "raylib.h"
#include <stdbool.h>
#include <stdio.h>

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "raylib [core] example - mouse input");
    SetTargetFPS(60);

    Vector2 ballPosition = { -100.0f, -100.0f };
    unsigned int ballRadius = 40;
    const int minRadius = 20;
    const int maxRadius = 60;

    Color colors[] = {GOLD, ORANGE, RED, MAROON, PINK, PURPLE, VIOLET, DARKPURPLE, DARKBLUE, BLUE, SKYBLUE, LIME, GREEN};
    const int numberOfColors = sizeof(colors) / sizeof(Color);
    Color ballColor = colors[0];
    unsigned int colorCycleCounter = 0;
    bool minFlag = false;
    bool maxFlag = false;

    while (!WindowShouldClose())
    {
        ballPosition = GetMousePosition();
        if (ballPosition.x < ballRadius)                    ballPosition.x = ballRadius;
        if (ballPosition.x > (screenWidth - ballRadius))    ballPosition.x = (screenWidth - ballRadius);
        if (ballPosition.y < ballRadius)                    ballPosition.y = ballRadius;
        if (ballPosition.y > (screenHeight - ballRadius))   ballPosition.y = (screenHeight - ballRadius);


        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            ballColor = colors[++colorCycleCounter % numberOfColors];
            if (ballRadius < maxRadius) ballRadius += 2;
        }

        if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON))
        {
            ballColor = colors[--colorCycleCounter % numberOfColors];
            if (ballRadius > minRadius) ballRadius -= 2;
        }

        if (IsMouseButtonDown(MOUSE_RIGHT_BUTTON) && ballRadius == minRadius)
            minFlag = true;
        else minFlag = false;


        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON) && ballRadius == maxRadius) 
             maxFlag = true;
        else maxFlag = false;

        // Drawing logic in separate block for good measure.
        BeginDrawing();
        {
            ClearBackground(RAYWHITE);
            if (minFlag) DrawText("can't shrink more!", 10, 30, 20, MAROON);
            if (maxFlag) DrawText("can't grow more!", 10, 30, 20, MAROON);

            DrawCircleV(ballPosition, ballRadius, ballColor);


            DrawText("move ball with mouse and click mouse buttons to toggle through colors", 10, 10, 20, DARKGRAY);
        }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}