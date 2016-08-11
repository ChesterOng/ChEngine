#pragma once

#include <SDL\SDL.h>
#include <GL\glew.h>
#include <fstream>

#include "Log.hpp"

class GLSL
{
private:
   //Variables
   Log * _log = nullptr;
   GLuint _progID = 0;

   //Functions
   void rmShaders();
   std::string readFile(const std::string &filePath);

public:
   GLSL();
   ~GLSL();

   void initLog(Log * log);
   void init();

   GLuint      createShad     (GLenum shaderType);
   GLboolean   bindShad       (GLuint shaderID, const std::string &shadSourceFP);
   GLboolean   compShad       (GLuint shaderID);
   GLboolean   attchShad      (GLuint shaderID);
   GLboolean   detchShad      (GLuint shaderID);
   GLboolean   deletShad      (GLuint shaderID);

   GLboolean   linkProgram();
};

