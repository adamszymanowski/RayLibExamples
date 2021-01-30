#include "raylib.h"
#include <stdbool.h>
#include <stdio.h>

int main(void)
{
    // Screen Setup
    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "raylib [core] example - keyboard input");
    SetTargetFPS(60);

    // Game setup
    Vector2 ballPosition = { (float)screenWidth / 2, (float)screenHeight / 2 };
    float ballRadius = 20;

    #define debugBufferSize 10
    char debugBuffer[debugBufferSize] = { 0 };

    while (!WindowShouldClose())
    {

        if (IsKeyDown(KEY_LEFT))
        {
            float boundaryLeft = ballRadius;
            if (ballPosition.x <= boundaryLeft)
            {
                ballPosition.x = boundaryLeft;
            }
            else
            {
                ballPosition.x -= 2.0f;
            }
        }

        if (IsKeyDown(KEY_RIGHT))
        {
            float boundaryDown = (screenWidth - ballRadius);
            if (ballPosition.x >= boundaryDown)
            {
                ballPosition.x = boundaryDown;
            }
            else
            {
                ballPosition.x += 2.0f;
            }
        }

        if (IsKeyDown(KEY_UP))
        {
            float boundaryUp = ballRadius;
            if (ballPosition.y <= boundaryUp) 
            {
                ballPosition.y = boundaryUp;
            }
            else
            {
                ballPosition.y -= 2.0f;
            }
        }

        if (IsKeyDown(KEY_DOWN))
        {
            float boundaryDown = (screenHeight - ballRadius);
            if (ballPosition.y >= boundaryDown)
            {
                ballPosition.y = boundaryDown;
            }
            else
            {
                ballPosition.y += 2.0f;
            }
        }

        // Drawing logic in separate block for good measure.
        BeginDrawing();
        {
            ClearBackground(RAYWHITE);
            DrawText("move the ball with arrow keys", 10, 10, 20, DARKGRAY);
            DrawCircleV(ballPosition, ballRadius, MAROON);

            // Debug drawing
            snprintf(debugBuffer, debugBufferSize, "X: %f", ballPosition.x);
            DrawText(debugBuffer, screenWidth - 100, 10, 20, DARKBLUE);
            snprintf(debugBuffer, debugBufferSize, "Y: %f", ballPosition.y);
            DrawText(debugBuffer, screenWidth-100, 30, 20, DARKBLUE);

        }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}