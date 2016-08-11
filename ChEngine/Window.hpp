#pragma once
#include <GL\glew.h>
#include <SDL\SDL.h>

#include "Log.hpp"

class Window
{
private:
   Log        *   _log     = nullptr;
   SDL_Window *   _window  = nullptr;
   SDL_GLContext  _context = nullptr;
   
   void initGLContext();

public:
   Window();
   Window(Log* log) : _log(log) {}
   ~Window();

   void initLog(Log* log);
   void initWindow(const char * title, int x, int y, int w, int h, Uint32 flags);

   virtual void swapWindow();
};

