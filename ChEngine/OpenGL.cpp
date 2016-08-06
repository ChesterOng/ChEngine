#include "OpenGL.hpp"



OpenGL::OpenGL()
{
}


OpenGL::~OpenGL()
{
}

void OpenGL::Buffers::initClear()
{
   glClearColor   (Color.r, Color.g, Color.b, Color.a);
   glClearDepth   (Depth.clearVal);
   glClearStencil (Stencil.s);
}

void OpenGL::Buffers::clear()
{
   glClear(fields);
}
