#include "Engine.hpp"

void Engine::printSDLVersion()
{
   SDL_version ver;
   SDL_GetVersion(&ver);
   _log->pwrite("SDL Version : " + ver.major + '.' + ver.minor + '.' + ver.patch, "Init", "SDL");
}

Engine::Engine()
{
}


Engine::~Engine()
{
}

void Engine::initLog(Log * log)
{
   _log = log;
}

void Engine::initSDL(const Uint32 SDLinitFlags)
{
   SDL_Init(SDLinitFlags);

   //Print Version
   printSDLVersion();
}
