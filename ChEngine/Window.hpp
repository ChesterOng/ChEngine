#pragma once
#include <GL\glew.h>
#include <SDL\SDL.h>

#include "Log.hpp"
#include "OpenGL.hpp"
#include "GLSL.hpp"
class Window
{
private:
   Log        *   _log     = nullptr;
   SDL_Window *   _window  = nullptr;
   GLSL       *   _GLSL    = nullptr;
   SDL_GLContext  _context = nullptr;
   
   void initGLContext();

public:
   OpenGL GL;



   Window();
   ~Window();

   void initLog(Log* log);
   void initGLSL(GLSL* glsl);
   void initWindow(const char * title, int x, int y, int w, int h, Uint32 flags);

   virtual void draw();
   virtual void clear();
   virtual void render();
   virtual void renderEnd();
};

