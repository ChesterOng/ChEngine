#pragma once  
#include <SDL\SDL.h>
#include <GL\glew.h>

#include "Log.hpp"
#include "Window.hpp"

class Engine
{
private:
   //Variables ------
   Log _log;
   //Functions ------
   void printSDLVersion();

public:
   //Variables ------
   Window window;
   //Construct ------
   Engine();
   ~Engine();

   //Functions ------
   void initLog(const std::string &logFilePath, bool isAppend = false);
   void initSDL(const Uint32 SDLinitFlags);
};

