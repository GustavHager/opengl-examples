#ifndef RENDER_SYSTEM_HPP
#define RENDER_SYSTEM_HPP

#include <list>

class RenderPass{
  RenderPass();
  virtual void render() = 0;
  virtual bool skipPass() = 0;
};


/*
* This is the render manger class, it handles the 
* separate render passes, and makes sure they are
* done in the correct order, or skipped if not needed 
*/
class RenderSystem{
public:
  RenderSystem();
  ~RenderSystem();
  
private:
  std::list<RenderPass> renderPasses;

};

#endif
