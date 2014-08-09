#ifndef SHADER_HPP
#define SHADER_HPP

#include <GLFW/glfw3.h>

#include <string>
#include <fstream>

class Shader{
        public:
                Shader(std::string vertexShader, std::string fragmentShader);
                GLuint getShaderID(void) const;

        private:
                GLuint shaderID;
                const std::string vertexShaderFilename, fragmentShaderFilename;

                std::string loadText(std::string filename);
                void buildShaderObject(std::string vertex, std::string fragment);
                GLuint compileShader(std::string text, GLenum);
                
                
};

#endif
