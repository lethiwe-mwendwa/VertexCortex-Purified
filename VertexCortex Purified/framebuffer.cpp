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

// Red, green, blue to bgr binary storage
uint32_t packColourBGR(uint8_t r, uint8_t g, uint8_t b)
{
    return (b) | (g << 8) | (r << 16);
}

// Takes BGR colour value and returns it's Red value
uint32_t getColourRed(uint8_t colour)
{
    // REMEMBER!! unint32_t colours are packed as BGR

    return (colour >> 16) & 255;
}

// Takes BGR colour value and returns it's Red value
uint32_t getColourGreen(uint8_t colour)
{
    // REMEMBER!! unint32_t colours are packed as BGR

    return (colour >> 8 ) & 255;
}

// Takes BGR colour value and returns it's Blue value
uint32_t getColourBlue(uint8_t colour)
{
    // REMEMBER!! unint32_t colours are packed as BGR

    return colour & 255;
}