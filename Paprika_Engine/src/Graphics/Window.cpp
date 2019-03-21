#include "Window.h"
#include <SDL.h>

#include <assert.h>

Window::Window(const char* title, int x, int y, int width, int height, int32_t flags):
	window(NULL)
{
	window = SDL_CreateWindow(title, x, y, width, height, flags);
	assert(window != NULL);
}

Window::~Window()
{
	SDL_DestroyWindow(window);
}

const char * Window::getTitle()
{
	return SDL_GetWindowTitle(window);
}

void Window::setTitle(const char * title)
{
	SDL_SetWindowTitle(window, title);
}

void Window::getWindowSize(int & width, int & height) const
{
	SDL_GetWindowSize(window, &width, &height);
}

void Window::setWindowSize(const int width, const int height)
{
	SDL_SetWindowSize(window, width, height);
}

const unsigned int Window::getWidth()
{
	int w;
	SDL_GetWindowSize(window, &w, NULL);
	return w;
}

void Window::setWidth(const unsigned int width)
{
	SDL_SetWindowSize(window, width, getHeight());
}

const unsigned int Window::getHeight()
{
	int h;
	SDL_GetWindowSize(window, NULL, &h);
	return h;
}

void Window::setHeight(const unsigned int height)
{
	SDL_SetWindowSize(window, getWidth(), height);
}

const int32_t Window::getFlags() const
{
	return SDL_GetWindowFlags(window);
}

void Window::setFullscreen(bool value)
{
	SDL_SetWindowFullscreen(window, value ? SDL_WINDOW_FULLSCREEN : 0);
}
bool Window::isFullscreen()
{
	return getFlags() & FULLSCREEN;
}
void Window::toggleFullscreen()
{
	SDL_SetWindowFullscreen(window, ~(getFlags() & FULLSCREEN));
}
