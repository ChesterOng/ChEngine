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
   return std::string(LOG_TYPE_LENGTH_MAX - type.length() + 1, ' ');
}

std::string Log::getSeperator()
{
   return std::string("\t");
}

Log::Log(const std::string & logFilePath, bool isAppend)
{
   init(logFilePath, isAppend);
}

bool Log::init(const std::string &logFilePath, bool isAppend)
{
   std::ios::openmode mode = isAppend ? std::ios::out : std::ios::out | std::ios::trunc;

   std::ofstream os{ logFilePath,mode };

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

void Log::print(std::string printStr, std::string type, bool isTab)
{
   toUpperCase(printStr);
   toUpperCase(type);

   checkLength(type);

   std::string seperator = isTab ? getSeperator() : getSeperator(type);
   std::cout << "[" << type << "] " << seperator << printStr << '\n';
}

void Log::write(std::string printStr, std::string type, bool isTab)
{
   toUpperCase(printStr);
   toUpperCase(type);

   checkLength(type);

   std::string seperator = isTab ? getSeperator() : getSeperator(type);
   std::ofstream os{ _logFilePath,std::ios::app | std::ios::out };
   if (os.is_open())
   {
      os << "[" << type << "] " << seperator << printStr << std::endl;
      os.close();
   }
   else
   {
      std::cout << "[ERR] LogFilePath could not be assessed : " << _logFilePath << '\n';
   }
}

void Log::pwrite(std::string printStr, std::string type, bool isTab)
{
   print(printStr, type, isTab);
   write(printStr, type, isTab);
}
