#include "RenderSystem.hpp"

RenderSystem::RenderSystem(){
}

RenderSystem::~RenderSystem(){

}

void RenderSystem::draw(void){
  simple_draw();
}


void RenderSystem::simple_draw(void){
  
}

void RenderSystem::init(void){
  drawables.push_back(Drawable());
}
