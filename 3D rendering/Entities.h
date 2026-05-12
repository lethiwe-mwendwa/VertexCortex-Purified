#pragma once
#include "SDL.h"
#include <vector>
#include "Shape.h"

extern std::vector<Shape*> Entities;

void renderEntities(SDL_Renderer* renderer);

//void transformEntities(SDL_Renderer* renderer, char axis, int value);