#include <GLFW/glfw3.h>
#include <unistd.h>
#include "Window.hpp"
#include "RenderSystem.hpp"

bool closeWindow = false;

//GLFW error callback, called on glfw errors
void glfw_error_callback(int error, const char* description){
  printf("%s\n",description);
}

//GLFW key callback, called on key events
static GLFWkeyfun key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){

   if(key == GLFW_KEY_ESCAPE){
      closeWindow = true;
   }

   return 0;
}

int main(int argc, char** argv){

	//init the GLFW library
  if(glfwInit() == GL_FALSE){
    printf("GLFW init failed, exiting \n");
    exit(-1);
  } 

  //tell GLFW where the error callback is
  glfwSetErrorCallback(glfw_error_callback);
  
  Window* w1n = new Window("w1n");
  RenderSystem* renderer = new RenderSystem();
  //renderer->init();
  w1n->setRenderer(renderer);
  w1n->show();
  renderer->init();

  glfwSetKeyCallback(w1n->getWindowHandle(),(GLFWkeyfun)key_callback);

  printf("starting main loop\n");

  while(closeWindow == false){
    glfwWaitEvents();
    w1n->redraw();
  }

  delete w1n;

  //cleanup and shutdown
  glfwTerminate();

  return 0;
}
