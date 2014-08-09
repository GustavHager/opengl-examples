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

  //load the shader
  Shader s("shader.vert","shader.frag"); 

  printf("Render system initialized \n");
}

void RenderSystem::printError(void){
  GLenum errorCode = glGetError();
  if(errorCode == GL_NO_ERROR){
    std::cerr << "No gl error" << std::endl;
  }else if(errorCode == GL_INVALID_ENUM){
    std::cerr << "GL invalid enum" << std::endl;
  }else if(errorCode == GL_INVALID_VALUE){
    std::cerr << "GL invalid value" << std::endl; 
  }else if(errorCode == GL_INVALID_OPERATION){
    std::cerr << "GL invalid operation" << std::endl;
  }else{
    std::cerr << "GL unknown error (msg missing)" << std::endl;
  }

}
