#include "GraphicsSystem.h"

#include <SDL.h>
#include <assert.h>
void GraphicsSystem::init()
{
	assert(SDL_Init(SDL_INIT_EVERYTHING) > 0);
}

void GraphicsSystem::free()
{
	SDL_Quit();
}
