#include <SDL\SDL.h>

#include <ChEngine\Log.hpp>

int main(int argc, char* argv[])
{
   Log m_Log;
   m_Log.init("Error.txt", false);
   m_Log.write("asdasd");
   m_Log.print("Hello");
   return 0;
}