#include "Window.hpp"

void Window::initGLContext()
{
   if (_window == nullptr)
   {  //is Window Created
      _log->pwrite("GL context cannot be initalised unless SDL Window is created!", "SDL|GL");
      return;
   }

   if (_context == nullptr)
   {  //Check if Context was created before
      _context = SDL_GL_CreateContext(_window);
   }
   else
   {  //Cannot Create as context is still active
      _log->pwrite("GL context has already been initalised", "SDL|GL");
   }
}

Window::Window()
{
}


Window::~Window()
{
   if (_context != nullptr)
   {
      SDL_GL_DeleteContext(_context);
      _context = nullptr;
   }

   if (_window != nullptr)
   {
      SDL_DestroyWindow(_window);
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
   _window = SDL_CreateWindow(title, x, y, w, h, flags);

   if (_window == nullptr)
   {  //Window did not initalise as expected
      _log->pwrite("SDL Window Cannot Be Created!"             , "WINDOW");
      _log->pwrite("SDL Error : " + std::string(SDL_GetError()), "WINDOW");
   }
}

void Window::draw()
{
   SDL_GL_SwapWindow(_window);
}

void Window::clear()
{
   GL.buffer.clear();
}
