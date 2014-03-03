#include "Window.hpp"

Window::Window(int height,int width,std::string window_name) : 
      height(height), width(width), window_name(window_name), 
      renderer(NULL){ }

Window::~Window(){
	glfwDestroyWindow(window_handle);
}

void Window::setRenderer(RenderSystem* renderer){
  this->renderer = renderer;
}

void Window::show(void){

  if(renderer == 0){
    printf("Render system not set, unable to create window");
  }

	window_handle = glfwCreateWindow(height,width,window_name.c_str(),NULL,NULL);

  if(!window_handle){
    printf("Failed to create window!");
  }

}


