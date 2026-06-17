#include "time.h"

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

