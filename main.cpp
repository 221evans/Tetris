#include <iostream>
#include "raylib.h"
int main() {


    InitWindow(300,600, "Raylib tetris");
    int setTargetFPS(60);

    while(!WindowShouldClose())
    {
        BeginDrawing();
        
        EndDrawing();
    }

    CloseWindow();


    return 0;
}
