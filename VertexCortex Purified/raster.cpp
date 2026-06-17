#include "raster.h"

// Brensenham's Line drawing algorithm
void drawLine(int x0, int y0, int x1, int y1, uint32_t colour, frameBuffer* fb)
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
            if (y >= 0 && y < fb->height && x >= 0 && x < fb->width) {

                fb->colourBuffer[y * fb->width + x] = colour;

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

            if (y >= 0 && y < fb->height && x >= 0 && x < fb->width) {

                fb->colourBuffer[y * fb->width + x] = colour;

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

void drawRect(int x, int y, int width, int height, uint32_t colour, frameBuffer* fb) {

    for (int i = y; i < height + y; i++) {
        for (int j = x; j < width + x; j++) {

            if (i >= 0 && i < fb->height && j >= 0 && j < fb->width) {

                fb->colourBuffer[i * fb->width + j] = colour;
            }

        }
    }

}

void render(frameBuffer& frameBuffer) {
    return;
};