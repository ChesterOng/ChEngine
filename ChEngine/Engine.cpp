#include "Engine.hpp"

void ChEngine::printSDLVersion()
{
   SDL_version ver;
   SDL_GetVersion(&ver);

   _log->pwrite("SDL Version : " + std::to_string(ver.major) + '.' + std::to_string(ver.minor) + '.' + std::to_string(ver.patch), "Init", "SDL");
}

void ChEngine::initSDLSubSystems(Uint32 SDLinitFlags)
{
   Uint32 initSubSystems = SDL_WasInit(0);

   Uint32 toInitSubSystems = SDLinitFlags & (~initSubSystems);

   //Special Cases

   if ((toInitSubSystems & SDL_INIT_VIDEO) != 0 && (toInitSubSystems & SDL_INIT_EVENTS) != 0)
      toInitSubSystems ^= SDL_INIT_EVENTS;

   if ((toInitSubSystems & SDL_INIT_GAMECONTROLLER) != 0 && (toInitSubSystems & SDL_INIT_JOYSTICK) != 0)
      toInitSubSystems ^= SDL_INIT_JOYSTICK;

   if (toInitSubSystems & SDL_INIT_TIMER)
   {
      if (SDL_InitSubSystem(SDL_INIT_TIMER) == 0)
      {
         _log->pwrite("Timer SubSystem initalised", "init", "SDL");
      }
      else
      {
         _log->pwrite("Timer SubSystem Initalisation Failed", "Error", "SDL");
         _log->pwrite("SDL Error Log :\n\t" + std::string(SDL_GetError()), "Error", "SDL");
      }
   }
   if (toInitSubSystems & SDL_INIT_AUDIO)
   {
      if (SDL_InitSubSystem(SDL_INIT_AUDIO) == 0)
      {
         _log->pwrite("Audio SubSystem initalised", "init", "SDL");
      }
      else
      {
         _log->pwrite("Audio SubSystem Initalisation Failed", "Error", "SDL");
         _log->pwrite("SDL Error Log :\n\t" + std::string(SDL_GetError()), "Error", "SDL");
      }
   }
   if (toInitSubSystems & SDL_INIT_VIDEO) //init Events too
   {
      if (SDL_InitSubSystem(SDL_INIT_VIDEO) == 0)
      {
         _log->pwrite("Video SubSystem initalised", "init", "SDL");
         _log->pwrite("Events SubSystem initalised", "init", "SDL");
      }
      else
      {
         _log->pwrite("Video SubSystem Initalisation Failed", "Error", "SDL");
         _log->pwrite("SDL Error Log :\n\t" + std::string(SDL_GetError()), "Error", "SDL");
      }
   }
   if (toInitSubSystems & SDL_INIT_JOYSTICK)
   {
      if (SDL_InitSubSystem(SDL_INIT_JOYSTICK) == 0)
      {
         _log->pwrite("JoyStick SubSystem initalised", "init", "SDL");
      }
      else
      {
         _log->pwrite("JoyStick SubSystem Initalisation Failed", "Error", "SDL");
         _log->pwrite("SDL Error Log :\n\t" + std::string(SDL_GetError()), "Error", "SDL");
      }
   }
   if (toInitSubSystems & SDL_INIT_HAPTIC)
   {
      if (SDL_InitSubSystem(SDL_INIT_HAPTIC) == 0)
      {
         _log->pwrite("Haptic SubSystem initalised", "init", "SDL");
      }
      else
      {
         _log->pwrite("Haptic SubSystem Initalisation Failed", "Error", "SDL");
         _log->pwrite("SDL Error Log :\n\t" + std::string(SDL_GetError()), "Error", "SDL");
      }
   }
   if (toInitSubSystems & SDL_INIT_GAMECONTROLLER)  //init JoyStick
   {
      if (SDL_InitSubSystem(SDL_INIT_GAMECONTROLLER) == 0)
      {
         _log->pwrite("Game Controller SubSystem initalised", "init", "SDL");
         _log->pwrite("JoyStick SubSystem initalised", "init", "SDL");
      }
      else
      {
         _log->pwrite("Game Controller SubSystem Initalisation Failed", "Error", "SDL");
         _log->pwrite("SDL Error Log :\n\t" + std::string(SDL_GetError()), "Error", "SDL");
      }
   }
   if (toInitSubSystems & SDL_INIT_EVENTS)
   {
      if (SDL_InitSubSystem(SDL_INIT_EVENTS) == 0)
      {
         _log->pwrite("Events SubSystem initalised", "init", "SDL");
      }
      else
      {
         _log->pwrite("Events SubSystem Initalisation Failed", "Error", "SDL");
         _log->pwrite("SDL Error Log :\n\t" + std::string(SDL_GetError()), "Error", "SDL");
      }
   }
}

ChEngine::ChEngine()
{
}

ChEngine::~ChEngine()
{
   SDL_Quit();
}

void ChEngine::initLog(Log * log)
{
   _log = log;
}

void ChEngine::initSDL(const Uint32 SDLinitFlags)
{

   SDL_Init(0);
   initSDLSubSystems(SDLinitFlags);
   //Print Version
   printSDLVersion();
}
