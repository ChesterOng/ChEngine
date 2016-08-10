#include "GLSL.hpp"

GLSL::GLSL()
{
}


GLSL::~GLSL()
{
   if (_progID != 0)
   {

   }
}

void GLSL::initLog(Log * log)
{
   _log = log;
}

void GLSL::init()
{
   if (_progID == 0)
   {  //Check if program exist
      glCreateProgram();
   }
   else
   {
      glDeleteProgram(_progID);
      _progID = glCreateProgram();
   }
}
