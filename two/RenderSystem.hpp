#ifndef RENDER_SYSTEM_HPP
#define RENDER_SYSTEM_HPP


class Camera{
public:
  Camera(float x = 0.0, float y=0.0, float z=0.0);
};

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
