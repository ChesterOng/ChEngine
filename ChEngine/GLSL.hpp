#pragma once
#include <SDL\SDL.h>
#include <GL\glew.h>
#include <fstream>

#include "Log.hpp"

class GLSL
{
private:
   Log * _log = nullptr;
   GLuint _progID = 0;

public:
   GLSL();
   ~GLSL();

   void initLog(Log * log);
   void init();

   GLuint createShad    (GLenum shaderType);
   void   bindShad      (GLuint shaderID,std::string shadSource);
   void   attchShad     (GLuint shaderID);
   void   detchShad     (GLuint shaderID);

};

