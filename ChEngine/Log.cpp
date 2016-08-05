#include "Log.hpp"

void Log::checkLength(std::string & str, int len)
{
   if (str.length() > len) str = str.substr(0, len);
}

void Log::toUpperCase(std::string & str)
{
   for (char & c : str)
      c = toupper(c);
}

std::string Log::getSeperator(std::string & type)
{
   return std::string(LOG_TYPE_LENGTH_MAX - type.length(), ' ');
}

std::string Log::getSeperator()
{
   return std::string("\t");
}

Log::Log(const std::string & logFilePath, bool isAppend)
{
   init(logFilePath, isAppend);
}

bool Log::init(const std::string &logFilePath, bool isAppend = false)
{
   std::ofstream os{ logFilePath,std::ios::out | isAppend ? 0 : std::ios::trunc };

   if (os.is_open())
   {//File Could be opened
      _logFilePath = logFilePath;
      os.close();
   }
   else
   {
      std::cout << "[ERR] LogFilePath could not be assessed : " << logFilePath << '\n';
      return false;
   }
   return true;
}

void Log::print(std::string printStr, std::string type, bool isTab = false)
{
   toUpperCase(printStr);
   toUpperCase(type);

   checkLength(type);

   std::string seperator = isTab ? getSeperator(), getSeperator(type);
   std::cout << "[" << type << "] " << getSeperator(type) 
}
