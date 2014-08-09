#include "Shader.hpp"

Shader::Shader(std::string vertexShaderFilename, 
               std::string fragmentShaderFilename) : 
               vertexShaderFilename(vertexShaderFilename), 
               fragmentShaderFilename(fragmentShaderFilename)
{

  std::string vertexShader = loadText(vertexShaderFilename);
  std::string fragmentShader = loadText(fragmentShaderFilename);

  buildShaderObject(vertexShader,fragmentShader);

}

GLuint Shader::getShaderID(void) const{
  return shaderID;
}


std::string Shader::loadText(std::string filename){
     
        std::fstream ifs(filename);

        std::string content;

        if(ifs.is_open()){
          content = std::string( (std::istreambuf_iterator<char>(ifs)),
                                 (std::istreambuf_iterator<char>()) );
        }else{
          printf("Error opening shader file, %s \n", filename.c_str());
        }

        return content; 
}

GLuint Shader::compileShader(std::string text,GLenum type){

        GLuint s = glCreateShader(type);

        const GLchar* rawText[1];
        rawText[0] = text.c_str();

        glShaderSource(s, 1, rawText, NULL);

        glCompileShader(s);

        GLint compileStatus;
        glGetShaderiv(s,GL_COMPILE_STATUS,&compileStatus);

        if(compileStatus == GL_FALSE){
          //some error handling
          GLint logLength;
          glGetShaderiv(s,GL_INFO_LOG_LENGTH,&logLength);
          printf("Shader compile error for ");
          if(type == GL_VERTEX_SHADER){
            printf("vertex shader \n");
          }else if(type == GL_FRAGMENT_SHADER){
            printf("fragment shader \n");
          }

          printf("\nWith shader code: %s \n\n",text.c_str());

          GLchar infoLog[logLength];
          glGetShaderInfoLog(s, logLength, NULL, infoLog);

          printf("Compilation error: %s \n",infoLog);
          
         }

        return s;
}

void Shader::buildShaderObject(std::string vertex, std::string fragment){

        GLuint v, f;

        v = compileShader(vertex,GL_VERTEX_SHADER);
        f = compileShader(fragment,GL_FRAGMENT_SHADER);

        GLuint p = glCreateProgram();
        glAttachShader(p,v);
        glAttachShader(p,f);

        glLinkProgram(p);
        glUseProgram(p);

        shaderID = p;
}
