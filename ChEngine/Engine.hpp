#pragma once  
#include <SDL\SDL.h>
#include <GL\glew.h>

#include "Log.hpp"
#include "Window.hpp"
#include "GLSL.hpp"

static class ChEngine
{
private:
   //Variables ------
   Log * _log;
   //Functions ------
   void printSDLVersion();
   void initSDLSubSystems(Uint32 SDLinitFlags);

public:
   //Construct ------
   ChEngine();
   ~ChEngine();

   //Functions ------
   void initLog(Log * log);
   void initSDL(Uint32 SDLinitFlags);
} Engine;

