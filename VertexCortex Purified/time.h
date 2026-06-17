#pragma once
#include "Windows.h"
#include <iostream>

class Clock
{

public:
	Clock();

	float dt;

	// Updates dt
	void tick();

private:

	LARGE_INTEGER lastTime;
	LARGE_INTEGER counterFrequency;

};