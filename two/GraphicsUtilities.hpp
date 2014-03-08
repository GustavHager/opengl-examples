#ifndef GRAPHICS_UTILITIES_HPP
#define GRAPHICS_UTILITIES_HPP

#define GLFW_INCLUDE_GLCOREARB
#include <GLFW/glfw3.h>

#include "glm/glm.hpp"


#include <string>
#include <fstream>

//some constants used to access resource files
const std::string shaderPath = "shaders/";


/*
* General wrappers of the openl api
* mostly to keep foot-shooting at a 
* minimum
*/

class OpenGLVertexArray{
public:
  OpenGLVertexArray(){
    glGenVertexArrays(1,&id);
  };

  void bind(void){
    glBindVertexArray(id);
  } 
private:
  GLuint id;
};

class OpenGLBuffer{
public:
  OpenGLBuffer(const GLuint id){
    this->id = id;
  }
  OpenGLBuffer(){
    glGenBuffers(1,&id);
  };
  void bind(void){
    glBindBuffer(GL_ARRAY_BUFFER,id);
  };
  
private:
  GLuint id;
};

class OpenGLShader{
public:
  OpenGLShader(const std::string name) : name(name){

  };  
  void bind(void){
    glUseProgram(id);
  } 
  const std::string name;
private:
  GLuint id;

  void loadshader(std::string name){
    //read the shader source
    std::string vertexText = readFile(shaderPath+name+".vert"); 
    std::string fragmentText = readFile(shaderPath+name+".frag");
    //create the shader objects and assign the code
    GLuint vid = glCreateShader(GL_VERTEX_SHADER);
    GLuint fid = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(vid,1,(const GLchar**)vertexText.c_str(),0); 
    glShaderSource(fid,1,(const GLchar**)fragmentText.c_str(),0);
    
    //compile and link the shaders
    compileShader(vid);
    compileShader(fid);
    
    //create the program object and link the shaders
    id = glCreateProgram();
    glAttachShader(id,vid);
    glAttachShader(id,fid);
    //TODO
    //here we should really bind some shader
    //variable names, but for now we
    //skip it and do it later
    //glBindAttribLocation();
    glLinkProgram(id);
    
    //make sure the linking went ok 
    GLint link_status;
    glGetProgramiv(id,GL_LINK_STATUS,(int*)&link_status);
    if(link_status == GL_FALSE){
      GLint maxLength = 0;
    	glGetProgramiv(id, GL_INFO_LOG_LENGTH, &maxLength);
 
     	GLchar* infoLog = new GLchar[maxLength];
    	glGetProgramInfoLog(id, maxLength, &maxLength, &infoLog[0]);
 
    	//We don't need the program anymore.
    	glDeleteProgram(id);
    }

    glDetachShader(id,vid);
    glDetachShader(id,fid);
    glDeleteShader(vid);
    glDeleteShader(fid); 
  }

  void compileShader(GLuint s){
    glCompileShader(s);    
    GLint status;
    glGetShaderiv(s,GL_COMPILE_STATUS,&status);
    if(status == GL_FALSE){
      GLint logSize;
      glGetShaderiv(s,GL_INFO_LOG_LENGTH,&logSize);
      char* shaderLog = new char[logSize];
      glGetShaderInfoLog(s,logSize,NULL,shaderLog);
      printf("Failed to compile shader, with error \n %s",shaderLog);
      delete shaderLog;
      glDeleteShader(s);
    }
  }

  std::string readFile(std::string filename){
    std::ifstream in(filename, std::ios::in | std::ios::binary);

    if (in){
      std::string contents;
      in.seekg(0, std::ios::end);
      contents.resize(in.tellg());
      in.seekg(0, std::ios::beg);
      in.read(&contents[0], contents.size());
      in.close();
      return(contents);
  }
  throw(errno);
  }
};
#endif
