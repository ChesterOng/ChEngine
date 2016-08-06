#include "Engine.hpp"

void Engine::printSDLVersion()
{
   SDL_version ver;
   SDL_GetVersion(&ver);
   _log.pwrite("SDL Version : " + ver.major + '.' + ver.minor + '.' + ver.patch, "SDL");
}

Engine::Engine()
{
}


Engine::~Engine()
{
}

void Engine::initLog(const std::string & logFilePath, bool isAppend)
{
   _log.init(logFilePath, isAppend);
}

void Engine::initSDL(const Uint32 SDLinitFlags)
{
   SDL_Init(SDLinitFlags);

   //Print Version
   printSDLVersion();
}
