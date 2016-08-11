#include <SDL\SDL.h>

#include <ChEngine\Log.hpp>
#include <ChEngine\GLSL.hpp>

int main(int argc, char* argv[])
{
   Log myLog;
   myLog.init("C:/Users/Chester/Desktop/log.txt");

   GLSL myGLSL;
   myGLSL.initLog(&myLog);

   return 0;
}