#include "Window.hpp"

void Window::initGLContext()
{
   if (_window == nullptr)
   {  //is Window Created
      _log->pwrite("GL context cannot be initalised unless SDL Window is created!", "Error", "GL Context");
      return;
   }

   if (_context == nullptr)
   {  //Check if Context was created before
      _context = SDL_GL_CreateContext(_window);
      if (_context == NULL)
      {
         _log->pwrite("Creation failed", "Error", "GL Context");
         _log->pwrite("SDL Error Log :\n\t" + std::string(SDL_GetError()), "Error", "GL Context");
      }
      else
      {
         _log->pwrite("Creation success", "Init", "GL Context");
      }
   }
   else
   {  //Cannot Create as context is still active
      _log->pwrite("Context still active", "Error", "GL Context");
   }
}

Window::Window()
{
}

Window::~Window()
{
   _log->pwrite("Destructor Called","Destr", "Window");
   if (_context != nullptr)
   {
      SDL_GL_DeleteContext(_context);
      _log->pwrite("Deleted", "Destr" , "GL Context");
      _context = nullptr;
   }

   if (_window != nullptr)
   {
      SDL_DestroyWindow(_window);
      _log->pwrite("Deleted", "Destr", "Window");
      _window = nullptr;
   }

   _log = nullptr;
}

void Window::initLog(Log * log)
{
   _log = log;
}

void Window::initWindow(const char * title, int x, int y, int w, int h, Uint32 flags)
{
   if (_window == nullptr)
   {  //Check that Window isn't created yet
      _window = SDL_CreateWindow(title, x, y, w, h, flags);

      if (_window == nullptr)
      {  //Window did not initalise as expected
         _log->pwrite("Creation Failed", "Error", "Window");
         _log->pwrite(std::string(SDL_GetError())  , "Init", "Window");
      }
      else
      {
         _log->pwrite("Creation Success", "Init", "Window");
      }
   }
   else
   {
      _log->pwrite("Already active", "Error", "Window");
   }
}

void Window::swapWindow()
{
   SDL_GL_SwapWindow(_window);
}