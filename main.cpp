#include "raylib.h"
#include<random>
#include<iostream>

const int screenWidth = 500;
const int screenHeight = 500;
const int cellSize = 5;

bool lifeInfo[screenWidth/cellSize][screenWidth / cellSize];
bool nextGenlifeInfo[screenWidth / cellSize][screenWidth / cellSize];
bool N[8];//n stamds for neighbors

bool setLife(int ix, int iy) {
    //int random = rand();
    // Create the vector from the angle
    return GetRandomValue(1,0);
}

void getNeighbour(int x, int y)
{
    int count = screenHeight / cellSize;
    N[0] = lifeInfo[(x - 1+count)%count]   [(y - 1+count) % count];
    N[1] = lifeInfo[(x - 1+ count) % count][(y+ count) % count];
    N[2] = lifeInfo[(x - 1+ count) % count][(y + 1+ count) % count];
    N[3] = lifeInfo[(x+ count) % count]    [(y - 1+ count) % count];
    N[4] = lifeInfo[(x+ count) % count]    [(y + 1+ count) % count];
    N[5] = lifeInfo[(x + 1+ count) % count][(y - 1+ count) % count];
    N[6] = lifeInfo[(x + 1+ count) % count][(y+ count) % count];
    N[7] = lifeInfo[(x + 1+ count) % count][(y + 1+ count) % count];
}

void checkRules(int x,int y)
{
    x /= cellSize; y /= cellSize;
    
    int liveNeighbor=0;
    getNeighbour(x,y);

    for (int i = 0; i < 8; i++){ liveNeighbor += N[i];}


    if (lifeInfo[x][y]) 
    {
        if (liveNeighbor > 3 || liveNeighbor < 2) 
        {
            nextGenlifeInfo[x][y] = 0;

        }
        else{ nextGenlifeInfo[x][y] = 1; }
    }

    else 
    {
        if(liveNeighbor==3){ nextGenlifeInfo[x][y] = 1; }
        else{ nextGenlifeInfo[x][y] = 0; }

    }





}


int main(void)
{


    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    SetTargetFPS(30);            // Set our game to run at 60 frames-per-second



    for (int i = 0; i < screenWidth; i += cellSize)
    {
        for (int j = 0; j < screenWidth; j += cellSize)
        {
            lifeInfo[i/cellSize][j/cellSize] = setLife(i, j);
        }
    }





     while (!WindowShouldClose())    // Detect window close button or ESC key
    {
 
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(BLACK);

        for (int i = 0; i < screenWidth; i+=cellSize) 
        {
            for (int j = 0; j < screenWidth; j+=cellSize)
            {   
                
                if (lifeInfo[i/cellSize][j/cellSize])
                {
                    DrawRectangle(i, j, cellSize-1, cellSize-1, GREEN);
                }
                else{ DrawRectangle(i, j, cellSize-1, cellSize-1, DARKGRAY); }
                
                
                checkRules(i,j);
            }


        }

        // Copy contents of nextGenlifeInfo to lifeInfo
        for (int i = 0; i < screenWidth / cellSize; ++i) {
            for (int j = 0; j < screenWidth / cellSize; ++j) {
                lifeInfo[i][j] = nextGenlifeInfo[i][j];
                nextGenlifeInfo[i][j] = 0;
            }
        }
        //DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
     }














    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
