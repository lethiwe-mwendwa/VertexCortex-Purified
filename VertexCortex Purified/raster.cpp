#include "raster.h"
#include "vertex.h"
#include "math.h"

// for debugging
#include <iostream>
#include <Windows.h>
#include <string>


void render(frameBuffer& frameBuffer) {
    return;
}

// Brensenham's Line drawing algorithm
void drawLine(int x0, int y0, int x1, int y1, uint32_t colour, frameBuffer& fb)
{
    // TODO! add a x count and y count so that it doesn't run and calculate the points that are out of bounds.

    int x = x0;
    int y = y0;

    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);

    int Pk;

    // direction
    int sx = 0;
    int sy = 0;

    if (x0 < x1) {
        sx = 1;
    }
    else {
        sx = -1;
    }

    if (y0 < y1) {
        sy = 1;
    }
    else {
        sy = -1;
    }

    // Case 1 y increments
    if (dy > dx) {
        Pk = 2 * (dx)-dy;

        for (int i = 0; i <= dy; i++) {

            // if the points are within then draw
            if (y >= 0 && y < fb.height && x >= 0 && x < fb.width) {

                fb.colourBuffer[y * fb.width + x] = colour;

            }

            y += sy;

            // maybe x increments
            if (Pk < 0) {

                Pk += 2 * (dx);
            }
            else {

                Pk += 2 * (dx)-2 * (dy);
                x += sx;
            }

        }
    }
    else if (dx >= dy) {
        Pk = 2 * (dy)-dx;

        for (int i = 0; i <= dx; i++) {

            if (y >= 0 && y < fb.height && x >= 0 && x < fb.width) {

                fb.colourBuffer[y * fb.width + x] = colour;

            }

            x += sx;

            // maybe y increments
            if (Pk < 0) {

                Pk += 2 * (dy);
            }
            else {

                Pk += 2 * (dy)-2 * (dx);
                y += sy;
            }
        }
    }
}

void drawRect(int x, int y, int width, int height, uint32_t colour, frameBuffer& fb) {

    for (int i = y; i < height + y; i++) {
        for (int j = x; j < width + x; j++) {

            if (i >= 0 && i < fb.height && j >= 0 && j < fb.width) {

                fb.colourBuffer[i * fb.width + j] = colour;
            }

        }
    }

}


void drawTriangleWireframe(Vec2 A, Vec2 B, Vec2 C, uint32_t colour, frameBuffer& fb)
{
    drawLine(A.x, A.y, B.x, B.y, colour, fb);
    drawLine(B.x, B.y, C.x, C.y, colour, fb);
    drawLine(C.x, C.y, A.x, A.y, colour, fb);

}


void drawTriangle(Vertex2 A, Vertex2 B, Vertex2 C, frameBuffer& fb) {
    
    //uint32_t colour;

    // Calculate bounding box here
    int minX = A.pos.x;
    if (B.pos.x < minX){ minX = B.pos.x; }
    if (C.pos.x < minX){ minX = C.pos.x; }

    int minY = A.pos.y;
    if (B.pos.y < minY) { minY = B.pos.y; }
    if (C.pos.y < minY) { minY = C.pos.y; }

    int maxX = A.pos.x;
    if (B.pos.x > maxX) { maxX = B.pos.x; }
    if (C.pos.x > maxX) { maxX = C.pos.x; }

    int maxY = A.pos.y;
    if (B.pos.y > maxY) { maxY = B.pos.y; }
    if (C.pos.y > maxY) { maxY = C.pos.y; }


    // This stuff is for the colour weighing!!
    //Double the signed area of the triangle ABC
    float ABC = edgeFunction(A.pos, B.pos, C.pos);

    //OUTER LOOP!! LOOP THROUGH PIXEL CANDIDATES
    for (int i = minY; i <= maxY; i++) {
        for (int j = minX; j <= maxX; j++) {

            if (edgeFunction(A.pos, B.pos, Vec2(j, i)) >= 0 && edgeFunction(B.pos, C.pos, Vec2(j, i)) >= 0 &&edgeFunction(C.pos, A.pos, Vec2(j, i)) >= 0){

                Vec2 P = Vec2(j, i);

                float BCP = edgeFunction(B.pos, C.pos, P);
                float CAP = edgeFunction(C.pos, A.pos, P);
                float ABP = edgeFunction(A.pos, B.pos, P);

                // Weights of the point P towards each of the vertices (Barycentric coordinates)
                float weightA = BCP / ABC;
                float weightB = CAP / ABC;
                float weightC = ABP / ABC;

                float r = A.colour.r * weightA + B.colour.r * weightB + C.colour.r * weightC;
                float g = A.colour.g * weightA + B.colour.g * weightB + C.colour.g * weightC;
                float b = A.colour.b * weightA + B.colour.b * weightB + C.colour.b * weightC;

                fb.colourBuffer[i * fb.width + j] = packColourBGR(r,g,b);

            }

        }
    }

}


float edgeFunction(Vec2 A, Vec2 B, Vec2 P) {

    return crossProduct(Vec2(B.x - A.x, B.y - A.y), Vec2(P.x - A.x, P.y - A.y));

}