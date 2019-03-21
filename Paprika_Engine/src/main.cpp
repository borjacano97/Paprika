#define SDL_MAIN_HANDLED

#include <stdio.h>
#include <SDL.h>
#include <Box2D/Box2D.h>

int main(int argc, char** argv) 
{

	////////////////////////////
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window* win = SDL_CreateWindow("Paprika engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
	SDL_Surface* surface = SDL_GetWindowSurface(win);
	int color = ~0u;
	bool close = false;
	while (!close)
	{
		SDL_FillRect(surface, NULL, --color);
		SDL_UpdateWindowSurface(win);
		static SDL_Event e;
		while (SDL_PollEvent(&e) && !(close = e.type == SDL_QUIT));
	}


	SDL_Quit();
	return 0;
}