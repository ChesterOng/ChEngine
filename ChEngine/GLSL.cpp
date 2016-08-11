#include "GLSL.hpp"

//Privates
void GLSL::rmShaders()
{
   //Get number of attached shaders
   GLsizei maxShaders; glGetProgramiv(_progID, GL_ATTACHED_SHADERS, &maxShaders);

   GLuint *shaders = new GLuint(maxShaders);

   {
      glGetAttachedShaders(_progID, maxShaders, nullptr, shaders);

      for (int i = 0; i < maxShaders; ++i)
      {
         glDetachShader(_progID, shaders[i]);
         _log->pwrite("Detached Shader Index = " + std::to_string(shaders[i]), "Detach", "Shaders");
         glDeleteShader(shaders[i]);
         _log->pwrite("Deleted Shader Index =  " + std::to_string(shaders[i]), "Delete", "Shaders");
      }
   }
   delete[] shaders;
}

std::string GLSL::readFile(const std::string &filePath)
{
   std::ifstream file{ filePath,std::ios::ate | std::ios::in | std::ios::binary };
   std::string contentString;

   if (file.is_open())
   {
      _log->pwrite("File Open for Reading = " + filePath, "Read", "Shader");

      //File Processing
      std::streamsize contentSize = file.tellg();
      file.seekg(std::ios::beg);
      contentSize -= file.tellg();

      char * contents = new char[contentSize + 1];
      contents[contentSize] = '\0';
      file.read(contents, contentSize);

      contentString = std::string(contents);

      delete[] contents;
      file.close();
   }
   else
   {
      _log->pwrite("File Failed to Open = " + filePath, "Error", "Shader");
      return "";
   }

   return contentString;
}

//Publics
GLSL::GLSL()
{
}

GLSL::~GLSL()
{
   _log->pwrite("Destructor Called", "Destr", "GLSL");

   //Delete Attached Shaders
   rmShaders();

   //Delete Program
   if (_progID != 0)
   {
      glDeleteProgram(_progID);
      _log->pwrite("Deleted", "Destr", "GLSL");
   }
}

void GLSL::initLog(Log * log)
{
   _log = log;
}

void GLSL::init()
{
   if (_progID != 0)
   {
      glDeleteProgram(_progID);  _progID = 0;
   }

   _progID = glCreateProgram();

   if (_progID == 0) //Check if program was created Successfully
      _log->pwrite("Program Creation Failed", "Error", "GLSL");
   else
      _log->pwrite("Program Created Successfully", "Init", "GLSL");

}

GLuint GLSL::createShad(GLenum shaderType)
{
   GLuint shadID = glCreateShader(shaderType);
   if (shadID == 0)
   {
      _log->pwrite("Creation of Shader Failed = " + std::to_string(shaderType), "Error", "Shader");
      return 0;
   }
   else
   {
      _log->pwrite("Creation of Shader Passed = " + std::to_string(shaderType), "Create", "Shader");
   }
   return shadID;
}

GLboolean GLSL::bindShad(GLuint shaderID, const std::string &shadSourceFP)
{
   std::string shadSource = readFile(shadSourceFP);

   if (shadSource == "")   //Reading Shader File Failed
      return GL_FALSE;

   const GLchar * shadSource_c_str = shadSource.c_str();

   //Bind Source Here
   glShaderSource(shaderID, 1, &shadSource_c_str, nullptr);

   _log->pwrite("Source Binded to Shader Index = " + std::to_string(shaderID), "Bind", "Shader");
   _log->pwrite("Source FilePath : " + shadSourceFP, "Bind", "Shader");
   _log->pwrite("Source : \n\t" + shadSource, "Bind", "Shader");
   return GL_TRUE;
}

GLboolean GLSL::compShad(GLuint shaderID)
{
   glCompileShader(shaderID);

   {//Error handling
      GLint status = 0;
      glGetShaderiv(shaderID, GL_COMPILE_STATUS, &status);

      if (status == GL_FALSE)
      {
         _log->pwrite("Compilation Shader Error", "Error", "Shader");

         GLint infoLogSize = 0;
         glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &infoLogSize);

         GLchar * infoLog = new GLchar[infoLogSize];
         glGetShaderInfoLog(shaderID, infoLogSize, nullptr, infoLog);

         _log->pwrite("Error Msg : \n\t" + *infoLog, "Error", "Shader");

         delete[] infoLog;

         
         return GL_FALSE;
      }
      else
      {
         _log->pwrite("Compilations Successful", "Compile", "Shader");
      }
   }

   return GL_TRUE;
}

GLboolean GLSL::attchShad(GLuint shaderID)
{
   glAttachShader(_progID, shaderID);
   _log->pwrite("Shader " + std::to_string(shaderID) + " has been Attached", "Attach", "Shader");

   return GL_TRUE;
}

GLboolean GLSL::detchShad(GLuint shaderID)
{
   glDetachShader(_progID, shaderID);
   _log->pwrite("Shader " + std::to_string(shaderID) + " has been Detached", "Detach", "Shader");

   return GL_TRUE;
}

GLboolean GLSL::deletShad(GLuint shaderID)
{
   if (glIsShader(shaderID) == GL_TRUE)
   {
      glDeleteShader(shaderID);

      if (glIsShader(shaderID) == GL_TRUE)
      {  //Check if shader is Still attached to a Program && Thus unable to be deleted
         _log->pwrite("Shader ID = " + std::to_string(shaderID) + " is Marked for deletion", "Delete", "Shader");
         return GL_FALSE;
      }
      else
      {  //Shader has been Deleted
         _log->pwrite("Shader ID = " + std::to_string(shaderID) + " is deleted", "Delete", "Shader");
         return GL_TRUE;
      }
   }
   else
   {
      _log->pwrite("Shader ID = " + std::to_string(shaderID) + " is Not a Shader", "Error", "Shader");
      return GL_FALSE;
   }
   return GL_FALSE;
}

GLboolean GLSL::linkProgram()
{
   glLinkProgram(_progID);

   GLint linkStatus = 0;

   glGetProgramiv(_progID, GL_LINK_STATUS, &linkStatus);

   if (linkStatus == GL_FALSE)
   {
      _log->pwrite("GL Program Link Unsuccessful", "Error", "GLSL");
      
      GLint infoLogLength = 0;
      glGetProgramiv(_progID, GL_INFO_LOG_LENGTH, &infoLogLength);

      GLchar * infoLog = new GLchar[infoLogLength];
      glGetProgramInfoLog(_progID, infoLogLength, nullptr, infoLog);

      _log->pwrite("Error Msg : \n\t" + *infoLog, "Error", "GLSL");
      return GL_FALSE;
   }
   else
   {
      _log->pwrite("GL Program Link Successfully", "Link", "GLSL");
   }

   return GL_TRUE;
}
