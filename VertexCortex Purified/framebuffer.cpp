#include "framebuffer.h"


frameBuffer::frameBuffer(size_t width, size_t height)
{
    colourBuffer = new uint32_t[height * width];

    this->width = width;
    this->height = height;

    // For Win32
    bitmapInfo = {};
    bitmapInfo.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    bitmapInfo.bmiHeader.biWidth = width;
    bitmapInfo.bmiHeader.biHeight = -(LONG)height;
    bitmapInfo.bmiHeader.biPlanes = 1;
    bitmapInfo.bmiHeader.biBitCount = 32;
    bitmapInfo.bmiHeader.biCompression = BI_RGB;
}

frameBuffer::~frameBuffer()
{
    delete[] colourBuffer;
}

void frameBuffer::clear(uint32_t colour)
{
    for (int i = 0; i < height * width; i++) {
        colourBuffer[i] = colour;
    }
}

void frameBuffer::setPixel(size_t x, size_t y, uint32_t colour)
{
    if ((y >= height) || (x >= width) || (y < 0) || (x < 0)) {
        return;
    }
    colourBuffer[y * width + x] = colour;

}

// Brensenham's Line drawing algorithm
void frameBuffer::drawLine(int x0, int y0, int x1, int y1, uint32_t colour)
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
            if (y >= 0 && y < height && x >= 0 && x < width) {

                colourBuffer[y * width + x] = colour;

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

            if (y >= 0 && y < height && x >= 0 && x < width) {

                colourBuffer[y * width + x] = colour;

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

void frameBuffer::drawRect(int x, int y, int width, int height, uint32_t colour) {

    for (int i = y; i < height + y; i++) {
        for (int j = x; j < width + x; j++) {

            if (i >= 0 && i < this->height && j >= 0 && j < this->width) {

                colourBuffer[i * this->width + j] = colour;
            }

        }
    }

}

const uint32_t* frameBuffer::getColourData()
{
    return colourBuffer;
}

void frameBuffer::present(HDC deviceContext)
{
    // win32 stuff
    StretchDIBits(
        deviceContext,  // destination
        0,              // dest x
        0,              // dest y
        width,              // dest width
        height,              // dest height
        0,              // source x
        0,              // source y
        width,              // source width
        height,              // source height
        colourBuffer,              // your pixel data
        &bitmapInfo,              // your bitmapInfo
        DIB_RGB_COLORS,              // color format flag
        SRCCOPY               // raster operation
    );

}

uint32_t packColorBGR(uint8_t r, uint8_t g, uint8_t b)
{
    return (b) | (g << 8) | (r << 16);
}

Clock::Clock()
{
    // updates counterFrequency
    QueryPerformanceFrequency(&counterFrequency);
    QueryPerformanceCounter(&lastTime);
}

void Clock::tick()
{
    LARGE_INTEGER currentTime;

    QueryPerformanceCounter(&currentTime);

    dt = (float)(currentTime.QuadPart - lastTime.QuadPart) / (float)counterFrequency.QuadPart;

    lastTime = currentTime;
}

void render(frameBuffer& frameBuffer) {
    return;
};

