#pragma once

#include <SDL\SDL.h>
#include <GL\glew.h>
#include <fstream>
#include <vector>

#include "Log.hpp"
#include "OpenGL.hpp"

class GLSL
{
private:
   //Variables
   Log * _log = nullptr;
   GLuint _progID = 0;

   std::vector<GLuint> _enabledAttribs;

   //Functions
   void rmShaders();
   std::string readFile(const std::string &filePath);

public:
   //Variables
   OpenGL _OpenGL;      //Need to initalise this

   GLSL() {}
   GLSL(Log * log) : _log(log) {};

   ~GLSL();

   void initLog(Log * log);
   void init();

   #pragma region Shaders

      GLuint      createShad     (GLenum shaderType);
      GLboolean   bindShad       (GLuint shaderID, const std::string &shadSourceFP);
      GLboolean   compShad       (GLuint shaderID);
      void        attchShad      (GLuint shaderID);
      void        detchShad      (GLuint shaderID);
      GLboolean   deletShad      (GLuint shaderID);

   #pragma endregion

   GLboolean   linkProgram();
   void        useProgram();
   void        unuseProgram();

   #pragma region GLSLAttrib

      //Get Variable Location
      GLint getAttribLocation(const GLchar *name);
      GLint getUniformLocation(const GLchar *name);

      //Set Variable Location
      //You have to bind the Location Before Linking
      void bindAttribLocation(GLuint locationIndex, const GLchar *name);

      void addEnabledAttrib(GLuint index);
      void removeEnabledAttrib(GLuint index);

      void useAttribs();
      void unuseAttribs();
   #pragma endregion

   #pragma region Buffers
      void genVertexArray        (GLsizei n, GLuint *arrays);
      void setActiveVertexArray  (GLuint index);
      //TODO : glVertexAttribPointer()!!!

      void genBuffer (GLsizei n, GLuint *arrays);
      void setActiveBuffer (GLuint index);
      void setBufferDataDim(GLenum type, GLsizeiptr size, const GLvoid * data, GLenum usage);
      void setBufferData   (GLenum type, GLintptr offset, GLsizeiptr size, const GLvoid * data);

   #pragma endregion
};

