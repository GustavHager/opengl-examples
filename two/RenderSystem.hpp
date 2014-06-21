#ifndef RENDER_SYSTEM_HPP
#define RENDER_SYSTEM_HPP

#include <GLFW/glfw3.h>
#include "glm/glm.hpp"
#include "glm/gtc/quaternion.hpp"
#include <vector>

struct PhysicalState{
  glm::vec3 pos;
  glm::quat orientation; 
  glm::vec3 scale;
};

class Drawable{
public:
    Drawable(){
      //set the physical state variables
      state.pos = glm::vec3(0.0f,0.0f,0.0f);
      state.orientation = glm::quat(0.0f,0.0f,0.0f,0.0f);
      state.scale = glm::vec3(1.0f,1.0f,1.0f);

      //generate some vertices
      vertices.push_back(glm::vec3(0.0f,0.0f,0.0f));
      vertices.push_back(glm::vec3(1.0f,0.0f,0.0f));
      vertices.push_back(glm::vec3(0.0f,1.0f,0.0f));


      //vertex array stuff
      glGenVertexArrays(1,&vertexArrayID);
      glBindVertexArray(vertexArrayID);

      //vertex buffer stuff
      glGenBuffers(1,&vertexBufferID); 
      glBindBuffer(GL_ARRAY_BUFFER,vertexBufferID);
      glBufferData(GL_ARRAY_BUFFER,3*vertices.size(),&vertices,GL_STATIC_DRAW);

      glEnableVertexAttribArray(0);
    }

  PhysicalState state;
  GLuint vertexArrayID;
  GLuint vertexBufferID;
  std::vector<glm::vec3> vertices;
};


/*
* This is the render manger class, it handles the drawing 
*/
class RenderSystem{
public:
  RenderSystem();
  ~RenderSystem();
   
  void draw(void);
  void init(void);
  
private:
  void simple_draw(void);
  void draw_object(Drawable& d);
  std::vector<Drawable> drawables;

};

#endif
