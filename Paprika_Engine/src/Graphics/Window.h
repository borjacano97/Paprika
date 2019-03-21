#pragma once
#include <stdint.h>
class SDL_Window;
class Window 
{
public: 
	enum Flags
	{
		//this has been ripped from SDL_Video.h so we keep this simple
		//if we stop using SDL we'll need to handle it
		FULLSCREEN = 0x00000001,         /**< fullscreen window */
		OPENGL = 0x00000002,             /**< window usable with OpenGL context */
		SHOWN = 0x00000004,              /**< window is visible */
		HIDDEN = 0x00000008,             /**< window is not visible */
		BORDERLESS = 0x00000010,         /**< no window decoration */
		RESIZABLE = 0x00000020,          /**< window can be resized */
		MINIMIZED = 0x00000040,          /**< window is minimized */
		MAXIMIZED = 0x00000080,          /**< window is maximized */
		INPUT_GRABBED = 0x00000100,      /**< window has grabbed input focus */
		INPUT_FOCUS = 0x00000200,        /**< window has input focus */
		MOUSE_FOCUS = 0x00000400,        /**< window has mouse focus */
		FULLSCREEN_DESKTOP = (FULLSCREEN | 0x00001000),
		FOREIGN = 0x00000800,            /**< window not created by SDL */
		ALLOW_HIGHDPI = 0x00002000,      /**< window should be created in high-DPI mode if supported.
											 On macOS NSHighResolutionCapable must be set true in the
											 application's Info.plist for this to have any effect. */
		MOUSE_CAPTURE = 0x00004000,      /**< window has mouse captured (unrelated to INPUT_GRABBED) */
		ALWAYS_ON_TOP = 0x00008000,      /**< window should always be above others */
		SKIP_TASKBAR = 0x00010000,      /**< window should not be added to the taskbar */
		UTILITY = 0x00020000,      /**< window should be treated as a utility window */
		TOOLTIP = 0x00040000,      /**< window should be treated as a tooltip */
		POPUP_MENU = 0x00080000,      /**< window should be treated as a popup menu */
		VULKAN = 0x10000000       /**< window usable for Vulkan surface */
	};
public:
	Window(const char* title, int x, int y, int width, int height, int32_t flags);
	~Window();

	const char* getTitle();
	void setTitle(const char* title);

	void getWindowSize(int& width, int& height)const;
	void setWindowSize(const int width, const int height);

	const unsigned int getWidth();
	void setWidth(const unsigned int width);


	const unsigned int getHeight();
	void setHeight(const unsigned int height);

	const int32_t getFlags() const;

	void setFullscreen(bool value);
	bool isFullscreen();
	void toggleFullscreen();

private:
	SDL_Window* window;
};

