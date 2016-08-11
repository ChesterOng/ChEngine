#pragma once  
#include <SDL\SDL.h>
#include <GL\glew.h>

#include "Log.hpp"
#include "Window.hpp"
#include "GLSL.hpp"

class Engine
{
private:
   //Variables ------
   Log * _log;
   //Functions ------
   void printSDLVersion();

public:
   //Variables ------
   Window window;
   GLSL   GLSL;
   //Construct ------
   Engine();
   ~Engine();

   //Functions ------
   void initLog(Log * log);
   void initSDL(const Uint32 SDLinitFlags);
};

