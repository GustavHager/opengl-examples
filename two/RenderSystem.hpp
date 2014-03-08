#ifndef RENDER_SYSTEM_HPP
#define RENDER_SYSTEM_HPP

#include "glm/glm.hpp"
#include "glm/gtc/quaternion.hpp"

struct drawable{
  glm::vec3 pos;
  glm::quat orientation; 
  glm::vec3 scale;
};

/*
* This is the render manger class, it handles the drawing 
*/
class RenderSystem{
public:
  RenderSystem();
  ~RenderSystem();
  void draw();
  
private:
  void simple_draw(void);

};

#endif
