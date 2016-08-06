#pragma once
#include <iostream>
#include <fstream>
#include <string>

#define LOG_TYPE_LENGTH_MAX 7

//All Arguments are not mutable
//Class to display Text to screen and file
class Log
{
private:
	//File Variables
	std::string _logFilePath = "";
   
   //Trims Length to len
   void checkLength(std::string &str, int len = LOG_TYPE_LENGTH_MAX);

   //String toUpper
   void toUpperCase(std::string &str);

   //Returns Seperator //Call Check Length before doing this
   std::string getSeperator(std::string &type);
   std::string getSeperator();

public:
   // Const | Destruct
   Log() {}
   Log(const std::string &logFilePath, bool isAppend = false);

   ~Log() {}

	//initalises filePath
	bool init(const std::string &logFilePath, bool isAppend = false);

   //Printing Functions
   //Prints to Console
   void print(std::string printStr, std::string type = "ERR", bool isTab = false);

   //Writes to LogFile
   void write(std::string printStr, std::string type = "ERR", bool isTab = false);

   //Prints and Write
   void pwrite(std::string printStr, std::string type = "ERR", bool isTab = false);

   inline std::string getFilePath() { return _logFilePath; }
};