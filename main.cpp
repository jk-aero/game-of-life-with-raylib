#include "raylib.h"
#include<random>
#include<iostream>

const int screenWidth = 500;
const int screenHeight = 500;
const int cellSize = 10;

bool lifeInfo[50][50];
bool N[8];

bool setLife(int ix, int iy) {
    int random = rand();
    // Create the vector from the angle
    return random % 2;
}

void getNeighbour(int x, int y)
{
   
    N[0] = lifeInfo[x - 1][y - 1];
    N[1] = lifeInfo[x - 1][y];
    N[2] = lifeInfo[x - 1][y + 1];

    N[3] = lifeInfo[x][y - 1];
    N[4] = lifeInfo[x][y + 1];

    N[5] = lifeInfo[x + 1][y - 1];
    N[6] = lifeInfo[x + 1][y];
    N[7] = lifeInfo[x + 1][y + 1];
}

void checkRules(int x,int y)
{
    x /= 10; y /= 10;
    
    int val=0;
    getNeighbour(x,y);

    for (int i = 0; i < 8; i++){val += N[i];}

    if (val < 2) {lifeInfo[x][y] = 0;return;}
    if (val >3) {lifeInfo[x][y] = 0;return;}
    if (val ==2 or val==3) { lifeInfo[x][y] = 1; return; }
    if (val== 3 and !lifeInfo[x][y] ) { lifeInfo[x][y] = 1; return;}
   
}


int main(void)
{


    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    SetTargetFPS(20);            // Set our game to run at 60 frames-per-second



    for (int i = 0; i < screenWidth; i += cellSize)
    {
        for (int j = 0; j < screenWidth; j += cellSize)
        {
            lifeInfo[i/10][j/10] = setLife(i, j);
        }
    }





     while (!WindowShouldClose())    // Detect window close button or ESC key
    {
 
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        for (int i = 0; i < screenWidth; i+=cellSize) 
        {
            for (int j = 0; j < screenWidth; j+=cellSize)
            {   
                
                if (lifeInfo[i/10][j/10])
                {
                    DrawRectangle(i, j, 10, 10, WHITE);
                }
                else{ DrawRectangle(i, j, 10, 10, BLACK); }

                checkRules(i,j);
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
