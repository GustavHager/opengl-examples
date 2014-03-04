#ifndef RENDER_SYSTEM_HPP
#define RENDER_SYSTEM_HPP

#include "glm/glm.hpp"


/*
* This is the render manger class, it handles the 
* separate render passes, and interfaces with the rest
* of the systems 
*/
class RenderSystem{
public:
  RenderSystem();
  ~RenderSystem();
  void draw();
  
private:

};

#endif
