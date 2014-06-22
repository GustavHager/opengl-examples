#include "RenderSystem.hpp"

RenderSystem::RenderSystem(){
}

RenderSystem::~RenderSystem(){

}

void RenderSystem::draw(void){
  simple_draw();
}


void RenderSystem::simple_draw(){
  for(Drawable item : drawables){
    draw_object(item);
  }
}

void RenderSystem::draw_object(Drawable& d){
  glEnableVertexAttribArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, d.vertexBufferID);
  glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,(void*)0);
  glDrawArrays(GL_TRIANGLES,0,3);  
  glDisableVertexAttribArray(0);
}

void RenderSystem::init(void){
  drawables.push_back(Drawable());
  printf("drawing stuff\n");
}
