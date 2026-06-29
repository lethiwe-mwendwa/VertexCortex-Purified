#include "raster.h"
#include "math.h"

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



    //OUTER LOOP!! LOOP THROUGH PIXEL CANDIDATES
    for (int i = minY; i <= maxY; i++) {
        for (int j = minX; j <= maxX; j++) {

            if (edgeFunction(A.pos, B.pos, Vec2(j, i)) >= 0 && edgeFunction(B.pos, C.pos, Vec2(j, i)) >= 0 &&edgeFunction(C.pos, A.pos, Vec2(j, i)) >= 0){
                
                //now I need to figure out the specific colour.

                fb.colourBuffer[i * fb.width + j] = A.colour;


            }

        }
    }

}


int edgeFunction(Vec2 A, Vec2 B, Vec2 P) {

    return crossProduct(Vec2(B.x - A.x, B.y - A.y), Vec2(P.x - A.x, P.y - A.y));

}


//bool edgeFunction(Vertex2 A, Vertex2 B, Vertex2 C, int x, int y){
//    if (// compare for AB AP
//        crossProduct(Vec2(B.pos.x - A.pos.x, B.pos.y - A.pos.y), Vec2(x - A.pos.x, y - A.pos.y)) > 0 || 
//        // compare for BC BP
//        crossProduct(Vec2(C.pos.x - B.pos.x, C.pos.y - B.pos.y), Vec2(x - B.pos.x, y - B.pos.y)) > 0 ||
//        crossProduct(Vec2(A.pos.x - C.pos.x, A.pos.y - C.pos.y), Vec2(x - C.pos.x, y - C.pos.y)) > 0
//        ){
//        return true;
//    }
//    return false;
//}