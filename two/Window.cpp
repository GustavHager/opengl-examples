#include "Window.hpp"

Window::Window(std::string window_name,int height,int width) : 
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
    printf("Render system not set, unable to create window\n");
  }
  
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	
  window_handle = glfwCreateWindow(height,width,window_name.c_str(),NULL,NULL);

  if(!window_handle){
    printf("Failed to create window!\n");
  }
  
  glfwMakeContextCurrent(window_handle);
}

void Window::setInputManager(void (*f)(GLFWwindow*, int, int, int, int)){
  printf("input manager set!\n");
  glfwSetKeyCallback(window_handle,f);
}

GLFWwindow* Window::getWindowHandle(void){
  return window_handle;
}

bool Window::windowShouldClose(void){
  return glfwWindowShouldClose(window_handle);
}

void Window::redraw(void){
  renderer->draw();
}
