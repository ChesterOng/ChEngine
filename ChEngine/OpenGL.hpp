#pragma once
#include <SDL\SDL.h>
#include <GL\glew.h>

#include "Log.hpp"

#pragma region Buffers
struct GLColor
{
   GLfloat r = 1.0f;
   GLfloat g = 1.0f;
   GLfloat b = 1.0f;
   GLfloat a = 1.0f;

   GLColor(GLfloat rNew, GLfloat gNew, GLfloat bNew, GLfloat aNew)
      {r = rNew; g = gNew; b = bNew; a = aNew;}
};

struct GLDepth 
{
   GLenum   func     = GL_LESS;  //gldepthfunc
   GLclampd clearVal = 1.0;

   GLDepth(GLenum funcNew, GLclampd clearValNew)
      {func = funcNew; clearVal = clearValNew;}
};
struct GLAccum
{
   GLenum   op    = GL_ACCUM;
   GLfloat  value = 1.0f;

   GLAccum(GLenum opNew, GLfloat valueNew)
      {op = opNew; value = valueNew;}
};
struct GLStencil
{
   GLenum func = GL_ALWAYS;   //GLStencilFunc argumentsx
   GLint  ref  = 0;
   GLuint mask = 0x01;
   GLint  s    = 0;      
   //Index Set when glClearStencil is called
   GLStencil(GLenum funcNew,GLint refNew, GLuint maskNew, GLint sNew)
      {func = funcNew; ref = refNew; mask = maskNew; s = sNew;}
};
#pragma endregion

class OpenGL
{
private:
   //Variables --------
   Log * _log = nullptr;

public:
   //Constuctor--------
   OpenGL();
   ~OpenGL();
   //Functions --------
   void initLog(Log * log);

   //Variables --------
   struct Buffers
   {
      GLbitfield  fields   = GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT;
      GLColor     Color    = { 1.0f, 1.0f, 1.0f, 1.0f };
      GLDepth     Depth    = { GL_LESS, 1.0 };
      GLStencil   Stencil  = { GL_ALWAYS, 0, 0x01, 0 };

      //Set GL Clear Values
      virtual void initClear();
      //Call GL Clear
      virtual void clear();
   } buffer;

};

