#include "raylib.h"
#include<random>
#include<iostream>

const int screenWidth = 500;
const int screenHeight = 500;
const int cellSize = 10;

bool lifeInfo[50][50];
bool N[8];

bool setLife(int ix, int iy) {
    // No precomputed gradients mean this works for any number of grid coordinates
    const unsigned w = 8 * sizeof(unsigned);
    const unsigned s = w / 2;
    unsigned a = ix, b = iy;
    a *= 3284157443;

    b ^= a << s | a >> w - s;
    b *= 1911520717;

    a ^= b << s | b >> w - s;
    a *= 2048419325;
    int random = a * (3.14159265 / ~(~0u >> 1)); // in [0, 2*Pi]

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
